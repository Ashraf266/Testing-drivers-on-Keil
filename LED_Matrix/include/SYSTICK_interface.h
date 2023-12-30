/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 29/10/2023				*/
/****************************************/

#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

/*---------------------------------- Definitions ----------------------------------*/


/*---------------------------- Function Declarations -------------------------*/

void SYSTICK_voidInit					(void);

void SYSTICK_voidSetBusyWait			(u32 copy_u32Ticks); 									/* sync func */

void SYSTICK_voidSetIntervalSingle		(u32 copy_u32Ticks, void (* copy_ptr2func)(void)); 	/* async func */

void SYSTICK_voidSetIntervalPeriodic	(u32 copy_u32Ticks, void (* copy_ptr2func)(void));	/* async func */

void SYSTICK_voidStopTimer				(void);

u32  SYSTICK_u32GetElapsedTime			(void);   /* Reload - Val */

u32	 SYSTICK_u32GetRemainingTime		(void); /* val */



#endif  /* SYSTICK_INTERFACE_H */