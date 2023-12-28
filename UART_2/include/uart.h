/********************************************************************
 * Module       : uart                                              *
 * File Name    : uart.h                                            *
 * Description  : contains definitions & interfaces for uart driver *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/

#ifndef UART_H
#define UART_H

#include "uart_cfg.h"
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/******* UART IDs *******/
#define UART_1_ID							(0u)
#define UART_2_ID							(1u)
#define UART_3_ID							(2u)

/******* Data length *******/
#define UART_8_DATA_BITS					(0u)
#define UART_9_DATA_BITS					(1u)

/******* Parity options *******/
#define UART_PARITY_BIT_DISABLE				(0u)
#define UART_PARITY_BIT_ENABLE				(1u)

/******* Parity Types *******/
#define UART_EVEN_PARITY					(0u)
#define UART_ODD_PARITY						(1u)

/******* Stop Bits *******/
#define UART_1_STOP_BIT						(0b00)
#define UART_2_STOP_BIT						(0b10)

/******* UART interrupts *******/
#define UART_INTERRUPT_DISABLE				(0u)
#define UART_INTERRUPT_ENABLE				(1u)


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

/* Structure contains a configuration of the UART */

/* For baud rate div value Check stm32f103c8t6 page 798
 * baudRate = FCLK / (16 * baud_rate_div) 
 * baud Rate divided into 4bit fraction & 12bit mantissa
 * fraction value = 16 * the fraction from the equation
 * mantissa value = the decimal value from the equation */

typedef struct
{
	u16 baud_rate_div;
	u8 word_length;
	u8 parity_bit;
	u8 parity_mode;
	u8 stop_bits;
	u8 TX_interrupt;
	u8 RX_interrupt;
	void (*TX_func)(void);
	void (*RX_func)(u8);
	
}UART_ConfigType;


/*******************************************************************************
 *                               External Variables                            *
 *******************************************************************************/

extern UART_ConfigType UART_1_Cfg;
extern UART_ConfigType UART_2_Cfg;
extern UART_ConfigType UART_3_Cfg;

/*******************************************************************************
 *                             Functions Prototypes                            *
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
void UART_init(u8 instanceID, UART_ConfigType *cfgPtr);


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
void UART_transmitSync(u8 instanceID, u8 data);


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
void UART_transmitAsync(u8 instanceID, u8 data);


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
void UART_transmitStringSync(u8 instanceID, u8 *str);


/******************************************************************
[Function Name] : UART_receiveSync                                *
[Description]   : Sync function to receive the data		          *
[Args]:         : u8 instanceID			        				  *
[in]	        : the ID of the UART peripheral                   *
[out]	        : The received data                               *
[in/out]        : NOTHING                                         *
[Returns]       : u8                                              *
*******************************************************************/
u8 UART_receiveSync(u8 instanceID);


#endif /* UART_H */
