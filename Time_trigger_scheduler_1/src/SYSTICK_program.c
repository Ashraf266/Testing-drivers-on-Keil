/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 29/10/2023				*/
/****************************************/

/*---------------------------------- Includes ----------------------------------*/
#include "std_types.h"
#include "bit_math.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"


/*---------------------------------- Global Variables ----------------------------------*/

void (* CallBackFunc)(void) = NULL_PTR;
u8   singleIntervalFlag 	= 0;


/*---------------------------------- ISR ----------------------------------*/
void SysTick_Handler(void)
{
	
	if( CallBackFunc != NULL_PTR )
	{
		(* CallBackFunc)();
	}
	
	if( singleIntervalFlag == 1 )
	{
		singleIntervalFlag  = 0;
		SYSTICK->ENABLE		= 0;
	}
	
}

/*---------------------------- Function Definitions -------------------------*/

void SYSTICK_voidInit(void)
{
	SYSTICK->ENABLE 	= 0;				/* Disable Systick */
	SYSTICK->TICK_INT 	= 0;				/* Disable Interrupts */
	SYSTICK->CLKSOURCE 	= SYSTICK_CLK;		/* Select Clock source based on pre-compile configuration */
	SYSTICK->VAL 		= 0;				/* Clear timer current value */
	
}



void SYSTICK_voidSetBusyWait(u32 copy_u32Ticks)
{
	SYSTICK->ENABLE 	= 0;				/* Disable Systick */
	SYSTICK->VAL 		= 0;				/* clear timer counts */
	SYSTICK->LOAD		= copy_u32Ticks;	/* set Reload value */
	SYSTICK->TICK_INT 	= 0;				/* Disable Interrupts */
	SYSTICK->ENABLE		= 1;				/* Enable Systick */
	while( SYSTICK->COUNTFLAG == 0 );		/* Busy wait */
	SYSTICK->ENABLE		= 0;				/* Disable Systick */
	
}


void SYSTICK_voidSetIntervalSingle(u32 copy_u32Ticks, void (* copy_ptr2func)(void))
{
	SYSTICK->ENABLE 	= 0;				/* Disable Systick */
	SYSTICK->VAL 		= 0;				/* clear timer counts */
	SYSTICK->LOAD		= copy_u32Ticks;    /* set Reload value */
	SYSTICK->TICK_INT 	= 1;                /* Enable Interrupts */
	CallBackFunc = copy_ptr2func;			/* Set callBack function */
	singleIntervalFlag  = 1;				/* Set single interval flag to interrupt only one time and stop */
	SYSTICK->ENABLE		= 1;				/* Enable Systick */
	
}



void SYSTICK_voidSetIntervalPeriodic(u32 copy_u32Ticks, void (* copy_ptr2func)(void))
{
	SYSTICK->ENABLE 	= 0;				/* Disable Systick */
	SYSTICK->VAL 		= 0;				/* clear timer counts */
	SYSTICK->LOAD		= copy_u32Ticks;    /* set Reload value */
	SYSTICK->TICK_INT 	= 1;                /* Enable Interrupts */
	CallBackFunc = copy_ptr2func;           /* Set callBack function */
	singleIntervalFlag  = 0;				/* Clear single interval flag */
	SYSTICK->ENABLE		= 1;				/* Enable Systick */
	
}

void SYSTICK_voidStopTimer(void)
{
	SYSTICK->ENABLE		= 0;				/* Disable Systick */
}



u32  SYSTICK_u32GetElapsedTime(void)
{
	u32 elapsed_time = SYSTICK->LOAD - SYSTICK->VAL;
	return elapsed_time;
}



u32	 SYSTICK_u32GetRemainingTime(void)
{
	return SYSTICK->VAL;
}