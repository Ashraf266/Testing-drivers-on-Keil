/********************************************************************
 * Module       : uart                                               *
 * File Name    : uart.c                                             *
 * Description  : uart Implementation                                *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/


#include "bit_math.h"
#include "uart.h"
#include "uart_private.h"



/*******************************************************************************
 *                               Global Variables                              *
 *******************************************************************************/

static volatile void (*TX_CallBack[3])(void) = {NULL_PTR};
static volatile void (*RX_CallBack[3])(u8) = {NULL_PTR};


/*******************************************************************************
 *                                      ISR                                    *
 *******************************************************************************/

void USART1_IRQHandler(void)
{
	if( (TX_CallBack[0] != NULL_PTR) && (GET_BIT(UART[0]->SR, 6) == 1) )
	{
		TX_CallBack[0]();
		CLR_BIT(UART[0]->SR, 6);
	}

	if( (RX_CallBack[0] != NULL_PTR) && (GET_BIT(UART[0]->SR, 5) == 1) )
	{
		RX_CallBack[0](UART[0]->DR);
	}
	
}

void USART2_IRQHandler(void)
{
	if( (TX_CallBack[1] != NULL_PTR) && (GET_BIT(UART[1]->SR, 6) == 1) )
	{
		TX_CallBack[1]();
		CLR_BIT(UART[1]->SR, 6);
	}

	if( (RX_CallBack[1] != NULL_PTR) && (GET_BIT(UART[1]->SR, 5) == 1) )
	{
		RX_CallBack[1](UART[1]->DR);
	}
	
}

void USART3_IRQHandler(void)
{
	if( (TX_CallBack[2] != NULL_PTR) && (GET_BIT(UART[2]->SR, 6) == 1) )
	{
		TX_CallBack[2]();
		CLR_BIT(UART[2]->SR, 6);
	}

	if( (RX_CallBack[2] != NULL_PTR) && (GET_BIT(UART[2]->SR, 5) == 1) )
	{
		RX_CallBack[2](UART[2]->DR);
	}
	
}

/*******************************************************************************
 *                             Functions Definition                            *
 *******************************************************************************/


/******************************************************************
[Function Name] : UART_init                                       *
[Description]   : Initializes UART peripheral                     *
[Args]:         : u8 instanceID, UART_ConfigType *cfgPtr          *
[in]	        : the ID of the UART peripheral                   *
|                 pointer to the configuration structure          *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void UART_init(u8 instanceID, UART_ConfigType *cfgPtr)
{
	UART[instanceID]->BRR = 0x00000000;
	UART[instanceID]->BRR = cfgPtr->baud_rate_div;
	
	UART[instanceID]->CR1 = 0x00000000;
	UART[instanceID]->CR1 |=	(cfgPtr->word_length << 12);
	UART[instanceID]->CR1 |=	(cfgPtr->parity_bit << 10);
	UART[instanceID]->CR1 |=	(cfgPtr->parity_mode << 9);
	UART[instanceID]->CR1 |=	(cfgPtr->TX_interrupt << 6);
	UART[instanceID]->CR1 |=	(cfgPtr->RX_interrupt << 5);
	
	UART[instanceID]->CR2 = 0x00000000;
	UART[instanceID]->CR2 |= (cfgPtr->stop_bits << 12);
	
	TX_CallBack[instanceID] = (volatile void (*)(void))cfgPtr->TX_func;
	RX_CallBack[instanceID] = (volatile void (*)(u8))cfgPtr->RX_func;
	
	/* Enable TX */
	UART[instanceID]->CR1 |= (1<<3);
	/* Enable RX */
	UART[instanceID]->CR1 |= (1<<2);	
	/* Enable UART */
	UART[instanceID]->CR1 |= (1<<13);
	
	UART[instanceID]->SR = 0x00000000;
}


/******************************************************************
[Function Name] : UART_transmitSync                               *
[Description]   : Sync function to transmit a data byte           *
[Args]:         : u8 instanceID, u8 data        				  *
[in]	        : the ID of the UART peripheral                   *
|                 data byte value						          *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void UART_transmitSync(u8 instanceID, u8 data)
{
	UART[instanceID]->DR = data;
	while( GET_BIT(UART[instanceID]->SR, 6) == 0 );
	CLR_BIT(UART[1]->SR, 6);
	
}


/******************************************************************
[Function Name] : UART_transmitSync                               *
[Description]   : Async function to transmit a data byte          *
[Args]:         : u8 instanceID, u8 data        				  *
[in]	        : the ID of the UART peripheral                   *
|                 data byte value						          *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void UART_transmitAsync(u8 instanceID, u8 data)
{
	UART[instanceID]->DR = data;
}


/******************************************************************
[Function Name] : UART_transmitStringSync                         *
[Description]   : Transmits a string 				              *
[Args]:         : u8 instanceID, u8 *str        				  *
[in]	        : the ID of the UART peripheral                   *
|                 pinter to the string					          *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void UART_transmitStringSync(u8 instanceID, u8 *str)
{
	while( *str != '\0' )
	{
		UART[instanceID]->DR = *str;
		while( GET_BIT(UART[instanceID]->SR, 6) == 0 );
		CLR_BIT(UART[1]->SR, 6);
		str++;
	}
}


/******************************************************************
[Function Name] : UART_receiveSync                                *
[Description]   : Sync function to receive the data		          *
[Args]:         : u8 instanceID			        				  *
[in]	        : the ID of the UART peripheral                   *
[out]	        : The received data                               *
[in/out]        : NOTHING                                         *
[Returns]       : u8                                              *
*******************************************************************/
u8 UART_receiveSync(u8 instanceID)
{
	while( GET_BIT(UART[instanceID]->SR, 5) == 0 );
	return (u8)UART[instanceID]->DR;
}
