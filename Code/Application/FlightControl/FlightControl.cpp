#include "FlightControl.hpp"

FlightControl::FlightControl(const char* name, uint32_t stackSize, uint8_t priority, uint32_t eeprom_size)
: ApplicationModule(name, stackSize, priority, eeprom_size)
{

	messenger.subscribe(REQUEST_MOTORS_REPORT);

	distribution_controller = &quadcopter;
	attitude_controller.reinitialize_constants();

	set_frequency(200);
}

void FlightControl::task(void){
	//Receive control input and attitude estimate:
	system_status_socket.receive();
	control_socket.receive();
	attitude_socket.receive();
	navigation_socket.receive();

	//Update local data about armed-state and control mode:
	check_armed();
	check_control_mode();

	//Update attitude controller, and get motor commands for attitude:
	attitude_controller.update(attitude_socket, control_socket);
	attitude_controller.get_commands(pitch_command, roll_command, yaw_command);

	//Update throttle control:
	throttle_controller.update(navigation_socket, attitude_socket, control_socket);
	throttle_controller.get_throttle_cmd(throttle);

	//Update distribution controller:
	distribution_controller->update(pitch_command, roll_command, yaw_command, throttle);

	//If we are armed:
	if(system_status_socket.armed && throttle > 10){

			motors->set_motor_speed(MOTOR_1, distribution_controller->get_motor_output(0));
			motors->set_motor_speed(MOTOR_2, distribution_controller->get_motor_output(1));
			motors->set_motor_speed(MOTOR_3, distribution_controller->get_motor_output(2));
			motors->set_motor_speed(MOTOR_4, distribution_controller->get_motor_output(3));
			motors->set_motor_speed(MOTOR_5, distribution_controller->get_motor_output(4));
			motors->set_motor_speed(MOTOR_6, distribution_controller->get_motor_output(5));
			motors->set_motor_speed(MOTOR_7, distribution_controller->get_motor_output(6));
			motors->set_motor_speed(MOTOR_8, distribution_controller->get_motor_output(7));
	}else{
		//Throttle is around 0, so we'll turn off all motors.
		motors->set_motor_speed(MOTOR_ALL, 0);
		attitude_controller.reset();
	}

	if(debugging_stream) handle_debug_stream();
}

void FlightControl::handle_message(Message& msg){
	Message response;

	switch(msg.type){
		case REQUEST_MOTORS_REPORT:
			response.type = MOTOR_REPORT_STATUS;
			response.set_pointer(&control_socket);
			response.set_enum(STATUS_OK);
			messenger.send_to(msg.sender, &response);
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

}

void FlightControl::check_armed(){
	static bool last_armed = false;

	//Check if we are armed:
	if(system_status_socket.armed){
		//Check if this has just happened!
		if(!last_armed){
			//Update PID constants in controllers:
			attitude_controller.reinitialize_constants();
			throttle_controller.reset_constants();
		}
	}

	last_armed = system_status_socket.armed;
}

void FlightControl::handle_debug_stream(){
	static uint32_t timestamp = 0;

	if(Time.get_time_since_ms(timestamp)>50){
	/*	Debug.send_and_transmit_uint32({
			distribution_controller->get_motor_output(0),
			distribution_controller->get_motor_output(1),
			distribution_controller->get_motor_output(2),
			distribution_controller->get_motor_output(3),
		});*/

		Debug.send_and_transmit_floats({
			pitch_command,
			roll_command,
			yaw_command
		});

		timestamp = Time.get_timestamp();
	}
}
