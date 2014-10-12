#include "FlightDynamics.hpp"


FlightDynamics::FlightDynamics(const char* name, uint32_t stackSize, uint8_t priority, uint32_t eeprom_size)
: ApplicationModule(name, stackSize, priority, eeprom_size),
  attitude_quaternion(EulerAngle(0,0,0))
{
	// Initializer code goes here
	//Subscribe to the calibrate gyroscope message type:
	messenger.subscribe(CALIBRATE_GYROSCOPE);
	messenger.subscribe(CALIBRATE_ACCELEROMETER);
	messenger.subscribe(REQUEST_SENSORS_REPORT);

	pitch_filter.set_coeffs({0.0018, 0.0071, 0.0107, 0.0071, 0.0018,
		 	 	 	 	 	 -2.7737, 3.019, -1.5048, 0.2879});
	roll_filter.set_coeffs({0.0018, 0.0071, 0.0107, 0.0071, 0.0018,
		 	 	 	 	 	 -2.7737, 3.019, -1.5048, 0.2879});
	yaw_filter.set_coeffs({0.0018, 0.0071, 0.0107, 0.0071, 0.0018,
		 	 	 	 	 	 -2.7737, 3.019, -1.5048, 0.2879});

	eeprom.load(&eeprom_structure, sizeof(EEPROM_Structure));

	attitude_socket.reset();

	set_frequency(200);
}

void FlightDynamics::task(void){

	//Download Sensor data from sensors:
	update_sensor_data();

	//Run extended kalman filter:
	if(raw_acc[0] != 0 && raw_acc[1] != 0 && raw_acc[2] != 0){
		EKF.innovate_priori(attitude_quaternion, raw_gyro[0], raw_gyro[1], raw_gyro[2]);
		//EKF.innovate_priori(attitude_quaternion, 0, 0, 0);
		EKF.innovate_stage1(attitude_quaternion, raw_acc[0],  raw_acc[1],  raw_acc[2]);
		attitude_quaternion.normalize();
	}

	attitude_euler = attitude_quaternion.to_euler();
	attitude_euler.to_degrees();

	//Update the attitude (euler) interface/socket:
	attitude_socket.pitch 			= attitude_euler.x;
	attitude_socket.roll 			= attitude_euler.y;
	attitude_socket.yaw 			= attitude_euler.z;

	attitude_socket.pitch_velocity 	= pitch_filter.process(raw_gyro[0]);
	attitude_socket.roll_velocity  	= roll_filter.process(raw_gyro[1]);
	attitude_socket.yaw_velocity 	= yaw_filter.process(raw_gyro[2]);

	//Update the quarternion interface/socket:
	attitude_quarternion_socket = attitude_quaternion;

	//Publish the data to other stake-holders:
	attitude_socket.publish();
	attitude_quarternion_socket.publish();


	update_status();
	debug_led();

	if(debugging_stream) handle_debug_stream();
}

void FlightDynamics::handle_message(Message& msg){
	switch(msg.type){
		case REQUEST_SENSORS_REPORT:
			report_status();
			break;

		case CALIBRATE_GYROSCOPE:
			/*Interface_Receive(this, APP_SYSTEMMODE_I, &LocalSystemMode);
			if(!(LocalSystemMode.Mode & MAV_MODE_FLAG_SAFETY_ARMED) )
			{
				FlightDynamics_CalibrateGyroscope(CALIBRATE_START);
			}*/
			break;

		case CALIBRATE_ACCELEROMETER:
			/*Interface_Receive(this, APP_SYSTEMMODE_I, &LocalSystemMode);
			if(!(LocalSystemMode.Mode & MAV_MODE_FLAG_SAFETY_ARMED) )
			{
				FlightDynamics_CalibrateAccelerometer(CALIBRATE_START);
			}*/
			break;

		case START_DEBUG_STREAM:
			debugging_stream = true;
			break;

		case STOP_DEBUG_STREAM:
			debugging_stream = false;
			break;

		default:
			break;
	}

	//Respond to the sender:
	return;
}

void FlightDynamics::update_sensor_data(){
	portENTER_CRITICAL();
	if(!gyroscope->get_gyro_data(raw_gyro[0], raw_gyro[1], raw_gyro[2]) ||
	   !accelerometer->get_acc_data(raw_acc[0], raw_acc[1], raw_acc[2]) ||
	   !magnetometer->get_mag_data(raw_mag[0], raw_mag[1], raw_mag[2])){

			no_sensor_errors++;
			gyroscope->restart();
			sensor_error = true;
	}else{
		sensor_error = false;
	}

	portEXIT_CRITICAL();
}


void FlightDynamics::debug_led(void){
	static uint32_t LED_timestamp = 0;
	static uint8_t LED_current_state = 0;
	static float old_gyro = 0;

	//Blink the LED:
	if(Time.get_time_since_ms(LED_timestamp) > 500){
		if(LED_current_state){
			//GPIO_WriteBit(GPIOC, GPIO_Pin_5, 0);
			leds->set_LED(DEBUG_BLUE2, LED_OFF);
			LED_current_state = 0;
		}else{
			//GPIO_WriteBit(GPIOC, GPIO_Pin_5, 1);
			leds->set_LED(DEBUG_BLUE2, LED_ON);
			LED_current_state = 1;
			}
		LED_timestamp = Time.get_timestamp();
	}

	if(old_gyro == raw_gyro[0]){
		leds->set_LED(DEBUG_BLUE1, LED_ON);
	}else{
		leds->set_LED(DEBUG_BLUE1, LED_OFF);
	}

	old_gyro = raw_gyro[0];
}

void FlightDynamics::update_status(void){
	static STATUS last_state = STATUS_OK;

	if(acc_calibrating || gyro_calibrating || mag_calibrating){
		sensor_status = STATUS_CALIBRATING;

	}else if(sensor_error == true){
		sensor_status = STATUS_NOTOK;

	}else{
		sensor_status = STATUS_OK;
	}

	//Notify others about any changes:
	if(last_state != sensor_status){
		report_status();
	}

	last_state = sensor_status;
}

void FlightDynamics::report_status(void){
	Message message;

	message.sender = &messenger;
	message.type = SENSOR_REPORT_STATUS;

	message.set_integer32( MAV_SYS_STATUS_SENSOR_3D_GYRO  |
						   MAV_SYS_STATUS_SENSOR_3D_ACCEL |
						   MAV_SYS_STATUS_SENSOR_3D_MAG);

	message.set_enum(sensor_status);
	messenger.broadcast(&message);
}

void FlightDynamics::handle_debug_stream(){
	static uint32_t timestamp = 0;

	if(Time.get_time_since_ms(timestamp)>50){
		Debug.send_number(attitude_socket.pitch);
		Debug.send(',');
		Debug.send_number(attitude_socket.roll);
		Debug.send(',');
		Debug.send_number(attitude_socket.yaw);

		Debug.send('\n');
		Debug.send('\r');
		Debug.transmit();
		timestamp = Time.get_timestamp();
	}
}

/*
 * 		//--------------------- YAW CALCULATION----------------------------
		// Vi skal beregne vinklen mellem x og y aksen fra magnotomeret for at
		// f� en fast vinkel (yaw). F�rst skal x og y aksen dog tilt kompenseres,
		// for at den n�jagtige vinkel kan beregnes.
		// TODO

		// Step 1: Tilt Compensate
		Vector3_t earthFrameMag;
		Vector3_t eulerAngles = { ExtendedKalmanAngles[PITCH], ExtendedKalmanAngles[ROLL], 0};

		//This should align the magnetometer and and gyro/accelerometer axises:
		//maybe should the extended kalman values always be swapped?
		//float temp = RawMag[X];
		RawMag[X] = RawMag[Y];
		RawMag[Y] = temp;
		RawMag[Z] *= -1;/

		frameConvert_bodyToEarthZYX(RawMag, eulerAngles, earthFrameMag);

		// Step 2: Find magnetometer yaw/heading
		float magYaw  	 = atan2(earthFrameMag[X], earthFrameMag[Y])*RAD_TO_DEGREE;		//
		float gyroYaw 	 = ComplementaryYaw + RawGyro[YAW]*0.005;						// 0.005 is the sampling frequency of 200Hz. (maybe add a minus instead of plus)

		// Step 3: Filter gyro and mag
		ComplementaryYaw = complementaryFilter_update(0.99, gyroYaw, magYaw);


		LocalAttitude.Yaw = ComplementaryYaw;
 * */
