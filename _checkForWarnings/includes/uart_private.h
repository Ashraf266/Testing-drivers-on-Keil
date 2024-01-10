/********************************************************************
 * Module       : uart                                              *
 * File Name    : uart_private.h                                    *
 * Description  : contains private definitions & types              *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/

#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#define UART_1_BASE_ADDRESS			0x40013800
#define UART_2_BASE_ADDRESS			0x40004400
#define UART_3_BASE_ADDRESS			0x40004800


typedef struct
{
	u32 SR;
	u32 DR;
	u32 BRR;
	u32 CR1;
	u32 CR2;
	
}UART_RegMap;



volatile UART_RegMap *UART[] = { (UART_RegMap *)UART_1_BASE_ADDRESS, (UART_RegMap *)UART_2_BASE_ADDRESS, (UART_RegMap *)UART_3_BASE_ADDRESS};

#endif  /* UART_PRIVATE_H */
