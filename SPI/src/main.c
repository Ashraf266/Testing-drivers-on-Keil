#include "std_types.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "AFIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "SYSTICK_interface.h"
#include "OS_interface.h"
#include "DMA_interface.h"
#include "SPI_interface.h"

u8 num = 0xFF;

int main(void)
{
	volatile u8 data = 0xFF;
	SYSTICK_voidInit();
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2, 2);
	RCC_voidEnableClock(RCC_APB2, 12);
	
	GPIO_voidSetPinDirection(GPIO_PORTA_NUM, GPIO_PIN5, GPIO_ALTER_FUNC_OUTPUT_PUSH_PULL_10MHZ);
	GPIO_voidSetPinDirection(GPIO_PORTA_NUM, GPIO_PIN6, GPIO_INPUT_FLOATING);
	GPIO_voidSetPinDirection(GPIO_PORTA_NUM, GPIO_PIN7, GPIO_ALTER_FUNC_OUTPUT_PUSH_PULL_10MHZ);
	
	SPI_Cfg spi_cfg = {	SPI_8_BIT_DATA_FORMAT,
											SPI_MSB_BIT_FIRST,
											SPI_CLK_DIV_64,
											SPI_MASTER_MODE,
											SPI_ONE_IDLE,
											SPI_WRITE_ON_FIRST_EDGE,
											SPI_INTERRUPT_DISABLE,
											SPI_INTERRUPT_DISABLE,
											NULL_PTR,
											NULL_PTR};
	
	SPI_voidInit(0, &spi_cfg);

	
	while(1)
	{
			data = (u8)SPI_u16SendReceiveSync(0, 0x00);
			num = data;

	}

}
