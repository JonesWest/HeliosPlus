#pragma once
#include "Framework.hpp"

typedef struct{
	float x = 0;
	float y = 0;
	float z = 0;
}coordinate_t;

struct APP_Navigation_I : APP_Interface<APP_Navigation_I>{
	using APP_Interface::APP_Interface;

	coordinate_t position;
	coordinate_t velocity;
	coordinate_t acceleration;
	float longitude = 0;
	float latitude = 0;
	float altitude = 0;
	float heading = 0;
	float speed = 0;
	float course = 0;

};
