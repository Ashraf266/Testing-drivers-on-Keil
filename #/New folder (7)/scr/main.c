#include "std_types.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"





int main(void)
{
	volatile long long i;
	u32 delay = 700000;
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2, IOPA);
	RCC_voidEnableClock(RCC_APB2, IOPB);
	RCC_voidEnableClock(RCC_APB2, IOPC);

	GPIO_voidSetPinDirection(GPIO_PORTA_NUM, GPIO_PIN5, GPIO_OUTPUT_PUSH_PULL_2MHZ);
	GPIO_voidSetPinDirection(GPIO_PORTB_NUM, GPIO_PIN12, GPIO_INPUT_INTERNAL_PULL_UP);


	while(1)
	{
		if(GPIO_u8GetPinValue(GPIO_PORTB_NUM, GPIO_PIN12) == GPIO_HIGH)
		{
			GPIO_voidSetPinValue(GPIO_PORTA_NUM, GPIO_PIN5, GPIO_HIGH);
			for(i=0; i<delay; i++);
			GPIO_voidSetPinValue(GPIO_PORTA_NUM, GPIO_PIN5, GPIO_LOW);
			for(i=0; i<delay; i++);
		}
		else
		{
			GPIO_voidSetPinValue(GPIO_PORTA_NUM, GPIO_PIN5, GPIO_LOW);
		}
	}
}
