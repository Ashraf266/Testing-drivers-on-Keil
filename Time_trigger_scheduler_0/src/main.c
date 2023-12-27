#include "std_types.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "AFIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "SYSTICK_interface.h"
#include "OS_interface.h"

void Task1(void)
{
	GPIO_voidSetPinValue(GPIO_PORTA_NUM, GPIO_PIN5, GPIO_HIGH);
}
void Task2(void)
{

}

void Task3(void)
{
		GPIO_voidSetPinValue(GPIO_PORTA_NUM, GPIO_PIN5, GPIO_LOW);
}

int main(void)
{

	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2, 2);
	GPIO_voidSetPinDirection(GPIO_PORTA_NUM, GPIO_PIN5, GPIO_OUTPUT_PUSH_PULL_10MHZ);
	
	OS_init();
	
	OS_voidCreateTask(0, 1, Task1);
	OS_voidCreateTask(1, 2, Task2);
	OS_voidCreateTask(2, 3, Task3);
	
  OS_voidStart();
	
	while(1)
	{


	}

}
