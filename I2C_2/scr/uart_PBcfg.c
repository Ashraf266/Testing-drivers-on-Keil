/********************************************************************
 * Module       : uart                                              *
 * File Name    : uart_PBcfg.c                                      *
 * Description  : Post build configuration for uart driver          *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/

#include "uart.h"
/* NOTE: if you decided to use call back function make sure to do some prototyping with extern to those functions */

UART_ConfigType UART_1_Cfg = {  
                                0x341,
								UART_8_DATA_BITS,
								UART_PARITY_BIT_DISABLE,
								UART_EVEN_PARITY,
								UART_1_STOP_BIT,
								UART_INTERRUPT_DISABLE,
								UART_INTERRUPT_DISABLE,
								NULL_PTR,
								NULL_PTR  
};

UART_ConfigType UART_2_Cfg = {  
                                0x341,
								UART_8_DATA_BITS,
								UART_PARITY_BIT_DISABLE,
								UART_EVEN_PARITY,
								UART_1_STOP_BIT,
								UART_INTERRUPT_DISABLE,
								UART_INTERRUPT_DISABLE,
								NULL_PTR,
								NULL_PTR  
};

UART_ConfigType UART_3_Cfg = {  
                                0x341,
								UART_8_DATA_BITS,
								UART_PARITY_BIT_DISABLE,
								UART_EVEN_PARITY,
								UART_1_STOP_BIT,
								UART_INTERRUPT_DISABLE,
								UART_INTERRUPT_DISABLE,
								NULL_PTR,
								NULL_PTR  
};
