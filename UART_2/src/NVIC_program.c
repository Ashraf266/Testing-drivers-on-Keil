/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 27/10/2023				*/
/****************************************/

/* NOTE: NOT UNIVERSAL NVIC DRIVER !!!!!!!!!!!!!!!!!!!!!! */

/*---------------------------------- Includes ----------------------------------*/
#include "std_types.h"
#include "bit_math.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

/*---------------------------- Function Definitions -------------------------*/

void NVIC_voidEnableInterrupt(u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber <= 31)
	{
		/* (NVIC_ISER0, copy_u8IntNumber); */
		/* faster as writing zero has no effect */
		NVIC_ISER0 = (1<< copy_u8IntNumber);
	}
	else if(copy_u8IntNumber <= 59)
	{
		NVIC_ISER1 = (1<< (copy_u8IntNumber-32));
	}
	else
	{
		/* Do nothing */
	}
	
}


void NVIC_voidDisableInterrupt(u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber <= 31)
	{
		NVIC_ICER0 = (1<< copy_u8IntNumber);
	}
	else if(copy_u8IntNumber <= 59)
	{
		NVIC_ICER1 = (1<< (copy_u8IntNumber-32));
	}
	else
	{
		/* Do nothing */
	}
	
}


void NVIC_voidSetPendingFlag(u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber <= 31)
	{
		NVIC_ISPR0 = (1<< copy_u8IntNumber);
	}
	else if(copy_u8IntNumber <= 59)
	{
		NVIC_ISPR1 = (1<< (copy_u8IntNumber-32));
	}
	else
	{
		/* Do nothing */
	}
	
}


void NVIC_voidClearPendingFlag(u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber <= 31)
	{
		NVIC_ICPR0 = (1<< copy_u8IntNumber);
	}
	else if(copy_u8IntNumber <= 59)
	{
		NVIC_ICPR1 = (1<< (copy_u8IntNumber-32));
	}
	else
	{
		/* Do nothing */
	}
	
}


u8 NVIC_u8GetActiveFlag(u8 copy_u8IntNumber)
{
	u8 active_flag = 0;
	if(copy_u8IntNumber <= 31)
	{
		active_flag = GET_BIT(NVIC_IABR0, copy_u8IntNumber);
	}
	else if(copy_u8IntNumber <= 59)
	{
		active_flag = GET_BIT(NVIC_IABR1, (copy_u8IntNumber-32));
	}
	else
	{
		/* Do nothing */
	}
	
	return active_flag;
}


void NVIC_voidSetPrioriy(u8 copy_u8IntNumber, u8 copy_u8GroupPriority, u8 copy_u8SubPrioriy)
{
	u8 priority = 0x00;
#if(PRIORITY_GROUPING_CONFIG == NVIC_4G0S)
	
SCB_AIRCR = 0x05FA0300;
priority = copy_u8GroupPriority;

#elif(PRIORITY_GROUPING_CONFIG == NVIC_3G1S)
	
SCB_AIRCR = 0x05FA0400;
priority = (copy_u8GroupPriority<<1) | (copy_u8SubPrioriy);

#elif(PRIORITY_GROUPING_CONFIG == NVIC_2G2S)
	
SCB_AIRCR = 0x05FA0500;
priority = (copy_u8GroupPriority<<2) | (copy_u8SubPrioriy);

#elif(PRIORITY_GROUPING_CONFIG == NVIC_1G3S)
	
SCB_AIRCR = 0x05FA0600;
priority = (copy_u8GroupPriority<<3) | (copy_u8SubPrioriy);
	
#elif(PRIORITY_GROUPING_CONFIG == NVIC_0G4S)

SCB_AIRCR = 0x05FA0700;
priority = copy_u8SubPrioriy;

#else
		#error "WRONG OPTION !!!!"
#endif

NVIC_IPR[ copy_u8IntNumber ] = (priority << 4);

}	
