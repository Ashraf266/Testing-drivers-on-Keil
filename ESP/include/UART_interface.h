/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 8/11/2023				    */
/****************************************/

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

/*---------------------------------- Definitions ----------------------------------*/

/* Instance ID */
#define UART_1_ID							(0u)
#define UART_2_ID							(1u)
#define UART_3_ID							(2u)

/* Configurations */
#define UART_8_DATA_BITS					(0u)
#define UART_9_DATA_BITS					(1u)

#define UART_PARITY_BIT_DISABLE				(0u)
#define UART_PARITY_BIT_ENABLE				(1u)

#define UART_EVEN_PARITY					(0u)
#define UART_ODD_PARITY						(1u)

#define UART_1_STOP_BIT						(0b00)
#define UART_2_STOP_BIT						(0b10)

#define UART_INTERRUPT_DISABLE				(0u)
#define UART_INTERRUPT_ENABLE				(1u)



/*----------------------------- type definitions ------------------------------*/
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
	
}UART_Cfg;

/*---------------------------- Function Declarations -------------------------*/

void UART_voidInit(u8 copy_u8InstanceID, UART_Cfg *cfgPtr);

void UART_voidTransmitSync(u8 copy_u8InstanceID, u8 copy_u8Data);

void UART_voidTransmitAsync(u8 copy_u8InstanceID, u8 copy_u8Data);

void UART_voidTransmitStringSync(u8 copy_u8InstanceID, u8 *copy_u8Data);

u8   UART_u8ReceiveSync(u8 copy_u8InstanceID);


#endif  /* UART_INTERFACE_H */