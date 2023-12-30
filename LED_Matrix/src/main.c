#include "std_types.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "AFIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "SYSTICK_interface.h"
#include "LEDMRX_interface.h"

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

	u8 x[4] = {0b0011, 0b1100, 0b0001, 0b1111};
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2, 2);
	RCC_voidEnableClock(RCC_APB2, 3);
	RCC_voidEnableClock(RCC_APB2, 4);
	
	SYSTICK_voidInit();
	LEDMRX_voidInit();

	while(1)
	{
		LEDMRX_voidDisplay(x);
	}

}
