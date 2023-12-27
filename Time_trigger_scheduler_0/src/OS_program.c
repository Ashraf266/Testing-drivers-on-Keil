/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 2/11/2023				    */
/****************************************/



/*---------------------------------- Includes ----------------------------------*/
#include "std_types.h"
#include "bit_math.h"

#include "SYSTICK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"




/*----------------------------- Global variables ---------------------------*/

static Task OS_Tasks[OS_NUMBER_OF_TASKS] = { 0 };

volatile u16 TickCounts = 0;



/*---------------------------- Function Definitions -------------------------*/

void OS_init(void)
{
	SYSTICK_voidInit();
}

void OS_voidCreateTask(u8 copy_u8ID, u16 copy_u16Periodicity, void (*ptr)(void))
{
	OS_Tasks[copy_u8ID].periodicity = copy_u16Periodicity;
	OS_Tasks[copy_u8ID].Fptr = ptr;
}

void OS_voidStart(void)
{
	SYSTICK_voidSetIntervalPeriodic(OS_TICK_VALUE, Scheduler);
}

static void Scheduler(void)
{
	u8 i = 0;
	
	for(i = 0; i< OS_NUMBER_OF_TASKS; i++)
	{
		if(TickCounts % OS_Tasks[i].periodicity  == 0)
		{
			OS_Tasks[i].Fptr();
		}
		
	}
	
	TickCounts++;
}