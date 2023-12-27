/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 28/10/2023				*/
/****************************************/

/*---------------------------------- Includes ----------------------------------*/
#include "std_types.h"
#include "bit_math.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


/*---------------------------- Function Definitions -------------------------*/

void EXTI_voidInit(u8 copy_u8Line, u8 copy_u8Mode)
{
	
	switch(copy_u8Mode)
	{
		case EXTI_RISING_EDGE:
							
							SET_BIT(EXTI->RTSR, copy_u8Line);
							break;
		
		case EXTI_FALLING_EDGE:
							
							SET_BIT(EXTI->FTSR, copy_u8Line);
							break;
							
		case EXTI_ON_LOGIC_CHANGE:
							
							SET_BIT(EXTI->RTSR, copy_u8Line);
							SET_BIT(EXTI->FTSR, copy_u8Line);
							break;
		default:
				/* do nothing */
							break;
	}
	
	/* Disable Interrrupt */
	CLR_BIT(EXTI->IMR, copy_u8Line);
	
}


void EXTI_voidEnableEXTI(u8 copy_u8Line)
{
	
	SET_BIT(EXTI->IMR, copy_u8Line);
	
}


void EXTI_voidDisableEXTI(u8 copy_u8Line)
{
	
	CLR_BIT(EXTI->IMR, copy_u8Line);
	
}


void EXTI_voidSwTrigger(u8 copy_u8Line)
{
	
	SET_BIT(EXTI->SWIER, copy_u8Line);
	
}