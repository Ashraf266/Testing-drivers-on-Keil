#include "std_types.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "AFIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"


void EXTI0_IRQHandler(void)
{
	
	GPIO_voidSetPinValue(GPIO_PORTA_NUM, GPIO_PIN5, GPIO_HIGH);
	while(1)
	{
		
	}
	/* clear pending flag by writing one in the pending flag register */
	
}




int main(void)
{

	volatile u64 i;
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2, 2);
	RCC_voidEnableClock(RCC_APB2, 3);
	RCC_voidEnableClock(RCC_APB2, 4);
	RCC_voidEnableClock(RCC_APB2, 0);
	
	AFIO_voidSetEXTIConfig(0, AFIO_EXTI_LINE_PB);
	
	NVIC_voidEnableInterrupt(6);
	NVIC_voidSetPrioriy(6, 3, 3);

	GPIO_voidSetPinDirection(GPIO_PORTA_NUM, GPIO_PIN5, GPIO_OUTPUT_PUSH_PULL_10MHZ);
	GPIO_voidSetPinDirection(GPIO_PORTB_NUM, GPIO_PIN0, GPIO_INPUT_INTERNAL_PULL_UP);
	
	EXTI_voidInit(0, EXTI_FALLING_EDGE);
	EXTI_voidEnableEXTI(0);
	
	GPIO_voidSetPinValue(GPIO_PORTA_NUM, GPIO_PIN5, GPIO_LOW);


	while(1)
	{
		//NVIC_voidSetPendingFlag(9);
		//GPIO_voidSetPinValue(GPIO_PORTA_NUM, GPIO_PIN5, GPIO_HIGH);
		//for(i=0; i< 700000; i++);
		//GPIO_voidSetPinValue(GPIO_PORTA_NUM, GPIO_PIN5, GPIO_LOW);
		//for(i=0; i< 70000; i++);
		i = GPIO_u8GetPinValue(GPIO_PORTB_NUM, GPIO_PIN0);


	}

}
