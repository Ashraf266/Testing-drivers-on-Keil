#include "std_types.h"
#include "RCC_interface.h"
#include "port.h"




int main(void)
{

	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2, 2);
	RCC_voidEnableClock(RCC_APB2, 3);
	RCC_voidEnableClock(RCC_APB2, 4);
	
	PORT_init(&configurations);
	

	while(1)
	{


	}

}
