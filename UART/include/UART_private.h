/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 8/11/2023				    */
/****************************************/

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



volatile UART_RegMap *UART[] = { UART_1_BASE_ADDRESS, UART_2_BASE_ADDRESS, UART_3_BASE_ADDRESS};

#endif  /* UART_PRIVATE_H */