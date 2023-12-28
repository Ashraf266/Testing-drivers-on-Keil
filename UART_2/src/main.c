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
#include "uart.h"


int main(void)
{
	u8 str[50] = {0};
	u8 i = 0;
	SYSTICK_voidInit();
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2, 2);
	RCC_voidEnableClock(RCC_APB2, 14);
	
	GPIO_voidSetPinDirection(GPIO_PORTA_NUM, GPIO_PIN9, GPIO_ALTER_FUNC_OUTPUT_PUSH_PULL_50MHZ);
	GPIO_voidSetPinDirection(GPIO_PORTA_NUM, GPIO_PIN10, GPIO_INPUT_FLOATING);
	
	
	UART_init(UART_1_ID, &UART_1_Cfg);

	UART_transmitStringSync(UART_1_ID, (u8 *)"Hi, My name is Ashraf: UART TEST...");
	UART_transmitSync(UART_1_ID, '\n');
	UART_transmitSync(UART_1_ID, '\r');

	while(1)
	{
		while(1)
		{
			str[i] = UART_receiveSync(UART_1_ID);
			if( str[i] == '\r' )
			{
				break;
			}
			i++;
		}
		str[i] = '\0';
		i= 0;
		UART_transmitStringSync(UART_1_ID, str);
		UART_transmitSync(UART_1_ID, '\n');
		UART_transmitSync(UART_1_ID, '\r');
	}

}
