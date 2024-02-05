/********************************************************************
 * Module       : pwm                                               *
 * File Name    : pwm.c                                             *
 * Description  : pwm Implementation                                *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/

#include "pwm.h"
#include "pwm_private.h"


/*******************************************************************************
 *                             Functions Definition                            *
 *******************************************************************************/


/******************************************************************
[Function Name] : PWM_init                                        *
[Description]   : Initializes PWM peripheral                      *
[Args]:         : u8 instanceID, PWM_ConfigType *cfgPtr           *
[in]	        : the ID of the PWM peripheral                    *
|                 pointer to the configuration structure          *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void PWM_init(u8 instanceID, PWM_ConfigType *cfgPtr)
{
    PWM[instanceID] ->CR1 = (1<< 7) | (1<< 0);
	PWM[instanceID] ->CR2 = 0;
	PWM[instanceID] ->SMCR = 0;
	PWM[instanceID] ->DIER = 0;
	PWM[instanceID] ->EGR = 0;
	PWM[instanceID] ->CCER = (1<<0);
	PWM[instanceID] ->PSC = cfgPtr->Prescaler;
	PWM[instanceID] ->ARR = cfgPtr->AutoReload;
	PWM[instanceID] ->DCR = 0;
	PWM[instanceID] ->CCR1 = 0;
    PWM[instanceID] ->CCR2 = 0;
    PWM[instanceID] ->CCR3 = 0;
    PWM[instanceID] ->CCR4 = 0;

    if(instanceID == 0)
    {
        PWM[instanceID] ->BDTR = (1<<15);
    }

    if(cfgPtr->Channel_1_Enable == PWM_CHANNEL_ENABLE)
    {
	    PWM[instanceID] ->CCMR1 = ((PWM[instanceID] ->CCMR1) & 0xFF00) | ((0b110 << 4) | (1 << 3));
    }

    if(cfgPtr->Channel_2_Enable == PWM_CHANNEL_ENABLE)
    {
	    PWM[instanceID] ->CCMR1 = ((PWM[instanceID] ->CCMR1) & 0x00FF) | ((0b110 << 12) | (1 << 11));
    }

    if(cfgPtr->Channel_3_Enable == PWM_CHANNEL_ENABLE)
    {
	    PWM[instanceID] ->CCMR2 = ((PWM[instanceID] ->CCMR2) & 0xFF00) | ((0b110 << 4) | (1 << 3));
    }

    if(cfgPtr->Channel_4_Enable == PWM_CHANNEL_ENABLE)
    {
	    PWM[instanceID] ->CCMR1 = ((PWM[instanceID] ->CCMR1) & 0x00FF) | ((0b110 << 12) | (1 << 11));
    }

}


/******************************************************************
[Function Name] : PWM_setSignalByValue                            *
[Description]   : Sets the PWM Signal Value                       *
[Args]:         : u8 instanceID, u8 channelID, u16 value          *
[in]	        : the ID of the PWM peripheral                    *
                  the ID of the PWM Channel                       *
                  the value of the High Time                      *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void PWM_setSignalByValue(u8 instanceID, u8 channelID, u16 value)
{
    switch(channelID)
    {
        case PWM_CHANNEL_1:
                            PWM[instanceID] ->CCR1 = value;
                            break;
        
        case PWM_CHANNEL_2:
                            PWM[instanceID] ->CCR2 = value;
                            break;

        case PWM_CHANNEL_3:
                            PWM[instanceID] ->CCR3 = value;
                            break;

        case PWM_CHANNEL_4:
                            PWM[instanceID] ->CCR4 = value;
                            break;

        default:
                break;
    }
}


/******************************************************************
[Function Name] : PWM_setSignalByPercent                          *
[Description]   : Sets the PWM Signal Value                       *
[Args]:         : u8 instanceID, u8 channelID, u8 percent         *
[in]	        : the ID of the PWM peripheral                    *
                  the ID of the PWM Channel                       *
                  the Percent of the High Time                    *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void PWM_setSignalByPercent(u8 instanceID, u8 channelID, u8 percent)
{
    u16 value = percent * PWM[instanceID] ->ARR / 100;
    switch(channelID)
    {
        case PWM_CHANNEL_1:
                            PWM[instanceID] ->CCR1 = value;
                            break;
        
        case PWM_CHANNEL_2:
                            PWM[instanceID] ->CCR2 = value;
                            break;

        case PWM_CHANNEL_3:
                            PWM[instanceID] ->CCR3 = value;
                            break;

        case PWM_CHANNEL_4:
                            PWM[instanceID] ->CCR4 = value;
                            break;

        default:
                break;
    }

}


