#include "Application/ControlInput/ControlInput.hpp"


void ControlInput::init(void){

}

void ControlInput::run(void)
{
	while(1)
	{
		attitude.Pitch = 100;
		attitude.publish();

		vTaskDelay(300);
	}
}

/****************************************************************
 * 						PRIVATE FUNCTIONS						*
 ****************************************************************/
void ControlInput::handle_internal_message(void)
{

}

void ControlInput::update_status(void)
{

}

void ControlInput::handle_switch(float state)
{

}

void ControlInput::handle_clicker(float state)
{

}

void ControlInput::check_arm(void)
{

}

void ControlInput::switch_arm_state(void)
{

}

void ControlInput::request_control(uint8_t Request)
{

}

void ControlInput::calibrate_start(void)
{

}

void ControlInput::calibrate_stop(void)
{

}

void ControlInput::report_status(void)
{

}