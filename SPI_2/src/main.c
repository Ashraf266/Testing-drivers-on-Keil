#include "std_types.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "AFIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "SYSTICK_interface.h"
#include "OS_interface.h"
#include "DMA_interface.h"
#include "spi.h"

u8 num = 0xFF;
void func1(u16 data)
{
	num = data;
}

int main(void)
{
	volatile u8 data = 0xFF;
	SYSTICK_voidInit();
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2, 2);
	RCC_voidEnableClock(RCC_APB2, 12);
	
	NVIC_voidEnableInterrupt(35);
	
	GPIO_voidSetPinDirection(GPIO_PORTA_NUM, GPIO_PIN5, GPIO_ALTER_FUNC_OUTPUT_PUSH_PULL_10MHZ);
	GPIO_voidSetPinDirection(GPIO_PORTA_NUM, GPIO_PIN6, GPIO_INPUT_FLOATING);
	GPIO_voidSetPinDirection(GPIO_PORTA_NUM, GPIO_PIN7, GPIO_ALTER_FUNC_OUTPUT_PUSH_PULL_10MHZ);
	
	SPI_init(0, &SPI_1_Cfg);

	
	while(1)
	{
			SPI_sendReceiveAsync(0, 0x00);
		  //SPI_sendReceiveSync(0, 0x01);

	}

}
