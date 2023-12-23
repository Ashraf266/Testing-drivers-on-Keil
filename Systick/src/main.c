#include "std_types.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "AFIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "SYSTICK_interface.h"

void func1(void)
{
	GPIO_voidSetPinValue(GPIO_PORTA_NUM, GPIO_PIN5, GPIO_HIGH);
}
void func2(void)
{
	GPIO_voidSetPinValue(GPIO_PORTA_NUM, GPIO_PIN5, GPIO_LOW);
}

int main(void)
{

	volatile u32 elapsed;
	volatile u32 remaining;
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2, 2);
	RCC_voidEnableClock(RCC_APB2, 3);
	RCC_voidEnableClock(RCC_APB2, 4);
	
	SYSTICK_voidInit();

	GPIO_voidSetPinDirection(GPIO_PORTA_NUM, GPIO_PIN5, GPIO_OUTPUT_PUSH_PULL_10MHZ);
	
	GPIO_voidSetPinValue(GPIO_PORTA_NUM, GPIO_PIN5, GPIO_HIGH);
	SYSTICK_voidSetBusyWait(3000000);
	GPIO_voidSetPinValue(GPIO_PORTA_NUM, GPIO_PIN5, GPIO_LOW);
	
	SYSTICK_voidSetIntervalSingle(3000000, func1);
	
	SYSTICK_voidSetIntervalPeriodic(3000000, func2);

	while(1)
	{
		elapsed = SYSTICK_u32GetElapsedTime();
		remaining = SYSTICK_u32GetRemainingTime();

	}

}
