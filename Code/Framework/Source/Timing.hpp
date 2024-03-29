#pragma once
/**************************************************************************//**
 * @file     Timing.hpp
 * @brief
 * @version  V1.0
 * @date     13. October 2014
 *
 * @note
 * This file is a part of the framework develop for Helios Flightcontroller
 *
 ******************************************************************************/

#include "stm32f4xx_tim.h"
#include "stm32f4xx_rcc.h"

class Timing{
public:
	Timing();
	unsigned int get_timestamp(void);
	unsigned int get_time_since_us(unsigned int timestamp);
	float get_time_since_ms(unsigned int timestamp);
	float get_time_since_sec(unsigned int timestamp);
	void delay_ms(uint32_t ms);
	void delay_us(uint32_t us);
};

extern Timing Time;
