/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 28/10/2023				*/
/****************************************/

#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H



/*---------------------------------- Definitions ----------------------------------*/

#define AFIO_BASE_ADDRESS				0x40010000
#define AFIO							((AFIO_RegMap *) AFIO_BASE_ADDRESS)
#define AFIO_EXTICR1					(*(u32 * const)(AFIO_BASE_ADDRESS+0x08))


/*-------------------------- Types Declarations -------------------------*/
 
/* structure contain the register map of the AFIO */
typedef struct
{
	volatile u32	EVCR;
	volatile u32	MAPR;
	volatile u32	EXTICR[4];
	volatile u32	MAPR2;
	
}AFIO_RegMap;

#endif  /* AFIO_PRIVATE_H */