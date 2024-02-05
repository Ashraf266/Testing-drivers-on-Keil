#include "std_types.h"
#include "bit_math.h"

#include "RCC_interface.h"

#define PORTA_CRL	*((u32 *) 0x40010800)
#define PORTA_ODR	*((u32 *) 0x4001080C)


int main(void)
{
	volatile long long int i;
	RCC_voidInitSysClock();

	RCC_voidEnableClock(RCC_APB2, 2);

	PORTA_CRL= 0x00000002;



	for(i=0; i<=8000000; i++);

	/* output HIGH */
	PORTA_ODR= 0x00000001;

	while(1)
	{




	}
}
