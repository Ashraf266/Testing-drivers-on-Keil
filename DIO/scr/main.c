#include "std_types.h"
#include "rcc.h"
#include "port.h"
#include "dio.h"




int main(void)
{
	volatile u16 i;
	RCC_init();
	RCC_EnableClock(RCC_APB2, 2);
	RCC_EnableClock(RCC_APB2, 3);
	RCC_EnableClock(RCC_APB2, 4);
	
	PORT_init(&configurations);
	
	DIO_writePin(DIO_PORT_A_ID, DIO_PIN_2_ID, DIO_PIN_LOW);
	
	DIO_pinGroupType pinGroup1 = { 0x1F, 5, DIO_PORT_B_ID };
	
	DIO_writePinGroup(&pinGroup1, 0x13);
	
	i = DIO_readPin(1, 5);
	i = DIO_readPinGroup(&pinGroup1);
	

	while(1)
	{


	}

}
