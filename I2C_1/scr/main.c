#include "port.h"
#include "rcc.h"
#include "i2c.h"
#include "std_types.h"








int main(void)
{

	RCC_init();
	RCC_EnableClock(RCC_APB2, 2);
	RCC_EnableClock(RCC_APB2, 3);
	RCC_EnableClock(RCC_APB2, 4);
	RCC_EnableClock(RCC_APB1, RCC_APB1_I2C1);
	
	PORT_init(&configurations);
	
	I2C_init(0, &I2C_1_Cfg);
	
	u8 data, test = 0;

	while(1)
	{
		/*
		I2C_start(0);
		I2C_sendAddress(0, 0x68,0);
		I2C_writeByte(0, 0x1A);
		I2C_writeByte(0, 0x05);
		I2C_stop(0);
		
		
		I2C_start(0);
		I2C_sendAddress(0, 0x68,0);
		I2C_writeByte(0, 0x1B);
		I2C_writeByte(0, 0x00);
		I2C_stop(0);
		
		I2C_start(0);
		I2C_sendAddress(0, 0x68,0);
		I2C_writeByte(0, 0x43);
		//I2C_stop(0);

		I2C_start(0);
		I2C_sendAddress(0, 0x68,1);
		data = I2C_readWithNack(0);
		I2C_stop(0);
		*/
		
		
		/* Sending is working */
		

		//I2C_start(0);
		//I2C_sendAddress(0, 0x04,0);
		//I2C_writeByte(0, 'a');
		//I2C_writeByte(0, 'b');
		//I2C_stop(0);
		
		
		
		I2C_start(0);
		I2C_sendAddress(0, 0x04,1);
		test = I2C_readWithAck(0);
		data = I2C_readWithNack(0);
		I2C_stop(0);
		test = data;

	}

}

