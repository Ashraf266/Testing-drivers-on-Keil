/********************************************************************
 * Module       : nvic                                              *
 * File Name    : nvic.c                                            *
 * Description  : nvic Implementation                               *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/

#include "bit_math.h"
#include "nvic.h"
#include "nvic_private.h"


/*******************************************************************************
 *                             Functions Definition                            *
 *******************************************************************************/


/******************************************************************
[Function Name] : NVIC_globalInterruptEnable                      *
[Description]   : Sets Global interrupt bit                       *
[Args]:         : void                                            *
[in]	        : NOTHING                                         *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void NVIC_globalInterruptEnable(void)
{
	GlobalInterruptEnableMacro();
}


/******************************************************************
[Function Name] : NVIC_globalInterruptDisable                     *
[Description]   : Disables All interrupts                         *
[Args]:         : void                                            *
[in]	        : NOTHING                                         *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void NVIC_globalInterruptDisable(void)
{
	GlobalInterruptDisableMacro();
}


/******************************************************************
[Function Name] : NVIC_hardFaultEnable                            *
[Description]   : Enables Hard Faults                             *
[Args]:         : void                                            *
[in]	        : NOTHING                                         *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void NVIC_hardFaultEnable(void)
{
	FaultsEnableMacro();
}


/******************************************************************
[Function Name] : NVIC_hardFaultDisable                           *
[Description]   : Disables Hard Faults                            *
[Args]:         : void                                            *
[in]	        : NOTHING                                         *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void NVIC_hardFaultDisable(void)
{
	FaultsDisableMacro();
}


/******************************************************************
[Function Name] : NVIC_enableInterrupt                            *
[Description]   : Enables a peripheral's interrupt                *
[Args]:         : u8 interruptID                                  *
[in]	        : interrupt ID from the interrupt table           *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void NVIC_enableInterrupt(u8 interruptID)
{
	if(interruptID <= 31)
	{
		/* SET_BIT(NVIC_ISER0, interruptID); */
		/* This is faster as writing zero has no effect */
		NVIC_ISER0 = (1<< interruptID);
	}
	else if(interruptID <= 59)
	{
		NVIC_ISER1 = (1<< (interruptID-32));
	}
	else
	{
		/* Do nothing */
	}
	
}


/******************************************************************
[Function Name] : NVIC_disableInterrupt                           *
[Description]   : Disables a peripheral's interrupt               *
[Args]:         : u8 interruptID                                  *
[in]	        : interrupt ID from the interrupt table           *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void NVIC_disableInterrupt(u8 interruptID)
{
	if(interruptID <= 31)
	{
		NVIC_ICER0 = (1<< interruptID);
	}
	else if(interruptID <= 59)
	{
		NVIC_ICER1 = (1<< (interruptID-32));
	}
	else
	{
		/* Do nothing */
	}
	
}


/******************************************************************
[Function Name] : NVIC_setPendingFlag                             *
[Description]   : Triggers a peripheral interrupt                 *
[Args]:         : u8 interruptID                                  *
[in]	        : interrupt ID from the interrupt table           *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void NVIC_setPendingFlag(u8 interruptID)
{
	if(interruptID <= 31)
	{
		NVIC_ISPR0 = (1<< interruptID);
	}
	else if(interruptID <= 59)
	{
		NVIC_ISPR1 = (1<< (interruptID-32));
	}
	else
	{
		/* Do nothing */
	}
	
}


/******************************************************************
[Function Name] : NVIC_clearPendingFlag                           *
[Description]   : Clears the interrupt flag                       *
[Args]:         : u8 interruptID                                  *
[in]	        : interrupt ID from the interrupt table           *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void NVIC_clearPendingFlag(u8 interruptID)
{
	if(interruptID <= 31)
	{
		NVIC_ICPR0 = (1<< interruptID);
	}
	else if(interruptID <= 59)
	{
		NVIC_ICPR1 = (1<< (interruptID-32));
	}
	else
	{
		/* Do nothing */
	}
	
}


/******************************************************************
[Function Name] : NVIC_getActiveFlag                           *
[Description]   : returns the interrupt flag status               *
[Args]:         : u8 interruptID                                  *
[in]	        : interrupt ID from the interrupt table           *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : u8                                              *
*******************************************************************/
u8	 NVIC_getActiveFlag(u8 interruptID)
{
	u8 active_flag = 0;
	if(interruptID <= 31)
	{
		active_flag = GET_BIT(NVIC_IABR0, interruptID);
	}
	else if(interruptID <= 59)
	{
		active_flag = GET_BIT(NVIC_IABR1, (interruptID-32));
	}
	else
	{
		/* Do nothing */
	}
	
	return active_flag;
}


/******************************************************************
[Function Name] : NVIC_setPrioriy                                 *
[Description]   : returns the interrupt flag status               *
[Args]:         : u8 interruptID, u8 groupPriority, u8 subPrioriy *
[in]	        : interrupt ID from the interrupt table           *
|                 interrupt group priority                        *
|                 interrupt subGroup priority                     *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : u8                                              *
*******************************************************************/
void NVIC_setPrioriy(u8 interruptID, u8 groupPriority, u8 subPrioriy)
{
	u8 priority = 0x00;
#if(PRIORITY_GROUPING_CONFIG == NVIC_4G0S)
	
    /* temporarly we will use a register from SCB */
    SCB_AIRCR = 0x05FA0300;
    priority = groupPriority;

#elif(PRIORITY_GROUPING_CONFIG == NVIC_3G1S)
	
    SCB_AIRCR = 0x05FA0400;
    priority = (groupPriority<<1) | (subPrioriy);

#elif(PRIORITY_GROUPING_CONFIG == NVIC_2G2S)
	
    SCB_AIRCR = 0x05FA0500;
    priority = (groupPriority<<2) | (subPrioriy);

#elif(PRIORITY_GROUPING_CONFIG == NVIC_1G3S)
	
    SCB_AIRCR = 0x05FA0600;
    priority = (groupPriority<<3) | (subPrioriy);
	
#elif(PRIORITY_GROUPING_CONFIG == NVIC_0G4S)

    SCB_AIRCR = 0x05FA0700;
    priority = subPrioriy;

#else

    #error "WRONG OPTION !!!!"

#endif

    NVIC_IPR[ interruptID ] = (priority << 4);

}
