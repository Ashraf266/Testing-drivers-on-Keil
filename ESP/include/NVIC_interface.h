/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 27/10/2023				*/
/****************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


/*---------------------------------- Definitions ----------------------------------*/


/*---------------------------- Function Declarations -------------------------*/

void NVIC_voidEnableInterrupt	(u8 copy_u8IntNumber);
void NVIC_voidDisableInterrupt	(u8 copy_u8IntNumber);
void NVIC_voidSetPendingFlag	(u8 copy_u8IntNumber);
void NVIC_voidClearPendingFlag	(u8 copy_u8IntNumber);
u8	 NVIC_u8GetActiveFlag		(u8 copy_u8IntNumber);
void NVIC_voidSetPrioriy		(u8 copy_u8IntNumber, u8 copy_u8GroupPriority, u8 copy_u8SubPrioriy);


#endif /* NVIC_INTERFACE_H */