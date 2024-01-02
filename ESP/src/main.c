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
#include "UART_interface.h"


int main(void)
{
	u8 str[2000] = {0};
	u8 i = 0;
	SYSTICK_voidInit();
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2, 2);
	RCC_voidEnableClock(RCC_APB2, 14);
	
	GPIO_voidSetPinDirection(GPIO_PORTA_NUM, GPIO_PIN9, GPIO_ALTER_FUNC_OUTPUT_PUSH_PULL_50MHZ);
	GPIO_voidSetPinDirection(GPIO_PORTA_NUM, GPIO_PIN10, GPIO_INPUT_FLOATING);
	
	UART_Cfg uart_config = {  0x45,
														UART_8_DATA_BITS,
														UART_PARITY_BIT_DISABLE,
														UART_EVEN_PARITY,
														UART_1_STOP_BIT,
														UART_INTERRUPT_DISABLE,
														UART_INTERRUPT_DISABLE,
														NULL_PTR,
														NULL_PTR  };
	
UART_voidInit(UART_1_ID, &uart_config);
UART_voidTransmitStringSync(UART_1_ID, (u8*)"AT+GMR\r\n");

	while(1)
	{
		str[i] = UART_u8ReceiveSync(UART_1_ID);
		i++;
	}

}
