/********************************************************************
 * Module       : systick                                              *
 * File Name    : systick.h                                            *
 * Description  : contains definitions & interfaces for systick driver *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/

#ifndef SYSTICK_H
#define SYSTICK_H

#include "systick_cfg.h"
#include "std_types.h"


/*******************************************************************************
 *                             Functions Prototypes                            *
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
void SYSTICK_init(void);


/******************************************************************
[Function Name] : SYSTICK_setBusyWait                             *
[Description]   : Sync function for delays                        *
[Args]:         : u32 ticks                                       *
[in]	        : Number of ticks to wait                         *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void SYSTICK_setBusyWait(u32 ticks);


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
void SYSTICK_setIntervalSingle(u32 ticks, void (* ptr2func)(void));


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
void SYSTICK_setIntervalPeriodic(u32 ticks, void (* ptr2func)(void));


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
void SYSTICK_stopTimer(void);


/******************************************************************
[Function Name] : SYSTICK_getElapsedTime                          *
[Description]   : Gets the Elapsed Time "Reload - Val"            *
[Args]:         : void                                            *
[in]	        : NOTHING                                         *
[out]	        : The Elapsed Time since timer starts             *
[in/out]        : NOTHING                                         *
[Returns]       : u32                                             *
*******************************************************************/
u32  SYSTICK_getElapsedTime(void);


/******************************************************************
[Function Name] : SYSTICK_getRemainingTime                        *
[Description]   : Gets the Remaining Time "Val"                   *
[Args]:         : void                                            *
[in]	        : NOTHING                                         *
[out]	        : The Remaining Time to finish conunting          *
[in/out]        : NOTHING                                         *
[Returns]       : u32                                             *
*******************************************************************/
u32	 SYSTICK_getRemainingTime(void);



#endif /* SYSTICK_H */
