/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 30/7/2023					*/
/****************************************/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_


#define		RCC_AHB		0
#define		RCC_APB1	1
#define		RCC_APB2	2

#define		DMA1EN		0
#define		DMA2EN		1
#define		SRAMEN		2
#define		FLITFEN		4
#define		CRCEN		6
#define		FSMCEN		8
#define		SDIOEN		10

#define 	IOPA		2
#define 	IOPB		3
#define 	IOPC		4



void RCC_voidInitSysClock(void);
void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);

#endif /* RCC_INTERFACE_H_ */
