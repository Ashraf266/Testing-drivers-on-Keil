#include "std_types.h"
#include "rcc.h"
#include "port.h"




int main(void)
{

	RCC_init();
	RCC_EnableClock(RCC_APB2, 2);
	RCC_EnableClock(RCC_APB2, 3);
	RCC_EnableClock(RCC_APB2, 4);
	
	PORT_init(&configurations);
	

	while(1)
	{


	}

}
