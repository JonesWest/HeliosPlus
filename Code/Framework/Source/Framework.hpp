#pragma once

typedef enum{
	STATUS_NOTOK = 0,
	STATUS_OK,
	STATUS_CALIBRATING
}STATUS;

//Includes:
#include "RTOS.hpp"
#include "EEPROM.hpp"
#include "MessageTypes.hpp"
#include "Message.hpp"
#include "MessageDistribution.hpp"
#include "Messenger.hpp"
#include "ApplicationModule.hpp"
#include "APP_Interface.hpp"
#include "Global.hpp"
#include "HAL_Interface.hpp"
#include "Timing.hpp"
#include "Globals.hpp"

//Interfaces:
#include "APP_Attitude_I.hpp"
#include "APP_Quaternion_I.hpp"
#include "APP_Control_I.hpp"
#include "APP_Navigation_I.hpp"
#include "APP_SystemStatus_I.hpp"
#include "APP_SystemMode_I.hpp"

#include "HAL_Accelerometer_I.hpp"
#include "HAL_ControlReceiver_I.hpp"
#include "HAL_Motor_I.hpp"
#include "HAL_HeliosLED_I.hpp"
#include "HAL_Communication_I.hpp"
#include "HAL_Multiplexer_I.hpp"
#include "HAL_Altitude_I.hpp"
#include "HAL_Gyroscope_I.hpp"
#include "HAL_Eeprom_I.hpp"
#include "HAL_Magnetometer_I.hpp"

//Drivers:
#include "GenericPulseMeasurement.hpp"
#include "PPMReceiver.hpp"

