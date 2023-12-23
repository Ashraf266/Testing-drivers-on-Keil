/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 24/10/2023				*/
/****************************************/

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


/*---------------------------------- Definitions ----------------------------------*/

/* GPIO PORTS BASE ADDRESSES */
#define GPIO_PORT_A_BASE_ADDRESS	0x40010800
#define GPIO_PORT_B_BASE_ADDRESS	0x40010C00
#define GPIO_PORT_C_BASE_ADDRESS	0x40011000

/* GPIO PORT REGISTERS */
#define GPIO_PORTA		((GPIO_RegMap *)GPIO_PORT_A_BASE_ADDRESS)
#define GPIO_PORTB		((GPIO_RegMap *)GPIO_PORT_B_BASE_ADDRESS)
#define GPIO_PORTC		((GPIO_RegMap *)GPIO_PORT_C_BASE_ADDRESS)


/*-------------------------- Types Declarations -------------------------*/
 
/* structure contain the register map of a GPIO PORT */
typedef struct
{
	volatile u32 CRL;
	volatile u32 CRH;
	volatile u32 IDR: 16;
	volatile u32 : 0;
	volatile u32 ODR: 16;
	volatile u32 : 0;
	volatile u32 BSRR;
	volatile u32 BRR: 16;
	volatile u32 : 0;
	volatile u32 LCKR: 16;
	volatile u32 : 0;
}GPIO_RegMap;


#endif /* GPIO_PRIVATE_H */
