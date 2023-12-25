/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 28/10/2023				*/
/****************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H



/*---------------------------------- Definitions ----------------------------------*/

#define EXTI_BASE_ADDRESS				0x40010400
#define EXTI							((EXTI_RegMap *) EXTI_BASE_ADDRESS)


/*-------------------------- Types Declarations -------------------------*/
 
/* structure contain the register map of the EXTI */
typedef struct
{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
	
}EXTI_RegMap;



#endif  /* EXTI_PRIVATE_H */