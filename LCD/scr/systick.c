/********************************************************************
 * Module       : systick                                           *
 * File Name    : systick.c                                         *
 * Description  : systick Implementation                            *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/


#include "bit_math.h"
#include "systick.h"
#include "systick_private.h"



/*******************************************************************************
 *                                Global Variables                             *
 *******************************************************************************/

static volatile void (* CallBackFunc)(void) = NULL_PTR;
static u8   singleIntervalFlag 	= 0;


/*******************************************************************************
 *                                      ISR                                    *
 *******************************************************************************/

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


/*******************************************************************************
 *                             Functions Definition                            *
 *******************************************************************************/


/******************************************************************
[Function Name] : SYSTICK_init                                    *
[Description]   : Initializes the systick                         *
[Args]:         : void                                            *
[in]	        : NOTHING                                         *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void SYSTICK_init(void)
{
	SYSTICK->ENABLE 	= 0;				/* Disable Systick */
	SYSTICK->TICK_INT 	= 0;				/* Disable Interrupts */
	SYSTICK->CLKSOURCE 	= SYSTICK_CLK;		/* Select Clock source based on pre-compile configuration */
	SYSTICK->VAL 		= 0;				/* Clear timer current value */
	
}


/******************************************************************
[Function Name] : SYSTICK_setBusyWait                             *
[Description]   : Sync function for delays                        *
[Args]:         : u32 ticks                                       *
[in]	        : Number of ticks to wait                         *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void SYSTICK_setBusyWait(u32 ticks)
{
	SYSTICK->ENABLE 	= 0;				/* Disable Systick */
	SYSTICK->VAL 		= 0;				/* clear timer counts */
	SYSTICK->LOAD		= ticks;	        /* set Reload value */
	SYSTICK->TICK_INT 	= 0;				/* Disable Interrupts */
	SYSTICK->ENABLE		= 1;				/* Enable Systick */
	while( SYSTICK->COUNTFLAG == 0 );		/* Busy wait */
	SYSTICK->ENABLE		= 0;				/* Disable Systick */
	
}


/******************************************************************
[Function Name] : SYSTICK_setIntervalSingle                       *
[Description]   : This ia an Async function that takes a number   *
|                 of ticks then it Generate an interrupt only once*
|                 calling the function passed as a parameter      *
[Args]:         : u32 ticks, void (* ptr2func)(void)              *
[in]	        : Number of ticks                                 *
|                 a pointer function for callBack                 *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void SYSTICK_setIntervalSingle(u32 ticks, void (* ptr2func)(void))
{
	SYSTICK->ENABLE 	= 0;				            /* Disable Systick */
	SYSTICK->VAL 		= 0;				            /* clear timer counts */
	SYSTICK->LOAD		= ticks;                        /* set Reload value */
	SYSTICK->TICK_INT 	= 1;                            /* Enable Interrupts */
	CallBackFunc = (volatile void (*)(void))ptr2func;	/* Set callBack function */
	singleIntervalFlag  = 1;				            /* Set single interval flag to interrupt only one time and stop */
	SYSTICK->ENABLE		= 1;				            /* Enable Systick */
	
}


/******************************************************************
[Function Name] : SYSTICK_setIntervalPeriodic                     *
[Description]   : This ia an Async function that takes a number   *
|                 of ticks then it Generate an interrupt          *
|                 periodically calling the function               *
|                 passed as a parameter                           *
[Args]:         : u32 ticks, void (* ptr2func)(void)              *
[in]	        : Number of ticks                                 *
|                 a pointer function for callBack                 *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void SYSTICK_setIntervalPeriodic(u32 ticks, void (* ptr2func)(void))
{
	SYSTICK->ENABLE 	= 0;				            /* Disable Systick */
	SYSTICK->VAL 		= 0;				            /* clear timer counts */
	SYSTICK->LOAD		= ticks;                        /* set Reload value */
	SYSTICK->TICK_INT 	= 1;                            /* Enable Interrupts */
	CallBackFunc = (volatile void (*)(void))ptr2func;   /* Set callBack function */
	singleIntervalFlag  = 0;				            /* Clear single interval flag */
	SYSTICK->ENABLE		= 1;				            /* Enable Systick */
	
}


/******************************************************************
[Function Name] : SYSTICK_stopTimer                               *
[Description]   : Stops the Systick timer usually used to stop    *
|                 the periodic interrupts functions               *
[Args]:         : void                                            *
[in]	        : NOTHING                                         *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void SYSTICK_stopTimer(void)
{
	SYSTICK->ENABLE		= 0;				/* Disable Systick */
}


/******************************************************************
[Function Name] : SYSTICK_getElapsedTime                          *
[Description]   : Gets the Elapsed Time "Reload - Val"            *
[Args]:         : void                                            *
[in]	        : NOTHING                                         *
[out]	        : The Elapsed Time since timer starts             *
[in/out]        : NOTHING                                         *
[Returns]       : u32                                             *
*******************************************************************/
u32  SYSTICK_getElapsedTime(void)
{
	u32 elapsed_time = SYSTICK->LOAD - SYSTICK->VAL;
	return elapsed_time;
}


/******************************************************************
[Function Name] : SYSTICK_getRemainingTime                        *
[Description]   : Gets the Remaining Time "Val"                   *
[Args]:         : void                                            *
[in]	        : NOTHING                                         *
[out]	        : The Remaining Time to finish conunting          *
[in/out]        : NOTHING                                         *
[Returns]       : u32                                             *
*******************************************************************/
u32	 SYSTICK_getRemainingTime(void)
{
	return SYSTICK->VAL;
}
