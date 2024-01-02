/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 8/11/2023				    */
/****************************************/

/*---------------------------------- Includes ----------------------------------*/
#include "std_types.h"
#include "bit_math.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

/*---------------------------------- Global Variables ----------------------------------*/

static volatile void (*TX_CallBack[3])(void) = {NULL_PTR};
static volatile void (*RX_CallBack[3])(u8) = {NULL_PTR};

/*---------------------------------- ISR ----------------------------------*/
void USART1_IRQHandler(void)
{
	if(TX_CallBack[0] != NULL_PTR)
	{
		TX_CallBack[0]();
		CLR_BIT(UART[0]->SR, 6);
	}

	if(RX_CallBack[0] != NULL_PTR)
	{
		RX_CallBack[0](UART[0]->DR);
	}
	
}

void USART2_IRQHandler(void)
{
	if(TX_CallBack[1] != NULL_PTR)
	{
		TX_CallBack[1]();
		CLR_BIT(UART[1]->SR, 6);
	}

	if(RX_CallBack[1] != NULL_PTR)
	{
		RX_CallBack[1](UART[1]->DR);
	}
	
}

void USART3_IRQHandler(void)
{
	if(TX_CallBack[2] != NULL_PTR)
	{
		TX_CallBack[2]();
		CLR_BIT(UART[2]->SR, 6);
	}

	if(RX_CallBack[2] != NULL_PTR)
	{
		RX_CallBack[2](UART[2]->DR);
	}
	
}

/*---------------------------- Function Definitions -------------------------*/

void UART_voidInit(u8 copy_u8InstanceID, UART_Cfg *cfgPtr)
{
	
	UART[copy_u8InstanceID]->BRR = 0x00000000;
	UART[copy_u8InstanceID]->BRR = cfgPtr->baud_rate_div;
	
	UART[copy_u8InstanceID]->CR1 = 0x00000000;
	UART[copy_u8InstanceID]->CR1 |=	(cfgPtr->word_length << 12);
	UART[copy_u8InstanceID]->CR1 |=	(cfgPtr->parity_bit << 10);
	UART[copy_u8InstanceID]->CR1 |=	(cfgPtr->parity_mode << 9);
	UART[copy_u8InstanceID]->CR1 |=	(cfgPtr->TX_interrupt << 6);
	UART[copy_u8InstanceID]->CR1 |=	(cfgPtr->RX_interrupt << 5);
	
	UART[copy_u8InstanceID]->CR2 = 0x00000000;
	UART[copy_u8InstanceID]->CR2 |= (cfgPtr->stop_bits << 12);
	
	TX_CallBack[copy_u8InstanceID] = cfgPtr->TX_func;
	RX_CallBack[copy_u8InstanceID] = cfgPtr->RX_func;
	
	/* Enable UART */
	UART[copy_u8InstanceID]->CR1 |= (1<<13);
	/* Enable TX */
	UART[copy_u8InstanceID]->CR1 |= (1<<3);
	/* Enable RX */
	UART[copy_u8InstanceID]->CR1 |= (1<<2);
	
	UART[copy_u8InstanceID]->SR = 0x00000000;
}



void UART_voidTransmitSync(u8 copy_u8InstanceID, u8 copy_u8Data)
{
	UART[copy_u8InstanceID]->DR = copy_u8Data;
	while( GET_BIT(UART[copy_u8InstanceID]->SR, 6) == 0 );
	CLR_BIT(UART[1]->SR, 6);
	
}

void UART_voidTransmitAsync(u8 copy_u8InstanceID, u8 copy_u8Data)
{
	UART[copy_u8InstanceID]->DR = copy_u8Data;
}

void UART_voidTransmitStringSync(u8 copy_u8InstanceID, u8 *copy_u8Data)
{
	while( *copy_u8Data != '\0' )
	{
		UART[copy_u8InstanceID]->DR = *copy_u8Data;
		while( GET_BIT(UART[copy_u8InstanceID]->SR, 6) == 0 );
		CLR_BIT(UART[1]->SR, 6);
		copy_u8Data++;
	}
}

u8   UART_u8ReceiveSync(u8 copy_u8InstanceID)
{
	while( GET_BIT(UART[copy_u8InstanceID]->SR, 5) == 0 );
	return (u8)UART[copy_u8InstanceID]->DR;
}