#pragma once
/*! \file */

#include "Framework.hpp"
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_i2c.h"


typedef enum{
	GENERIC_I2C_TYPE_I2C1_PB6_PB7 = 0, 	//!< SCL PB6, SDA PB7
	GENERIC_I2C_TYPE_I2C1_PB8_PB9,		//!< SCL PB8, SDA PB9
	GENERIC_I2C_TYPE_I2C2_PF1_PF0,		//!< SCL PF1, SDA PF0
	GENERIC_I2C_TYPE_I2C2_PH4_PH5,		//!< SCL PH4, SDA PH5
	GENERIC_I2C_TYPE_I2C3_PH7_PH8,		//!< SCL PH7, SDA PH8
	GENERIC_I2C_TYPE_I2C3_PA8_PC9		//!< SCL PA8, SDA PC9
}GENERIC_I2C_TYPE;

class GenericI2C {
	public:
		GenericI2C(GENERIC_I2C_TYPE I2C, uint32_t ClockSpeed);

		bool read_register8(uint8_t address, uint8_t registerAddress, uint8_t n, uint8_t* data);
		bool read_register16(uint8_t address, uint16_t registerAddress, uint8_t n, uint8_t* data);
		bool write_register8(uint8_t address, uint8_t registerAddress, uint8_t n, uint8_t* data);
		bool write_register16(uint8_t address, uint16_t registerAddress, uint8_t n, uint8_t* data);

		void restart(void);
		void set_clock_speed(uint32_t ClockSpeed);

	private:
		void setup(void);
		bool start(uint8_t address, uint8_t direction);
		bool write(uint8_t data);
		bool readAck(uint8_t* data);
		bool readNack(uint8_t* data);

		I2C_TypeDef* m_I2C;
		GENERIC_I2C_TYPE m_Type;
		uint32_t m_ClockSpeed;

		uint8_t dummy;
};
