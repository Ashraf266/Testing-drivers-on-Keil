/********************************************************************
 * Module       : pwm                                               *
 * File Name    : pwm.h                                             *
 * Description  : contains definitions & interfaces for pwm driver  *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/

#ifndef PWM_H
#define PWM_H

#include "pwm_cfg.h"
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/******* PWM IDs *******/
#define PWM_TIM1_ID             (0u)
#define PWM_TIM2_ID             (1u)
#define PWM_TIM3_ID             (2u)
#define PWM_TIM4_ID             (3u)


/******* PWM Channels *******/
#define PWM_CHANNEL_1           (0u)
#define PWM_CHANNEL_2           (1u)
#define PWM_CHANNEL_3           (2u)
#define PWM_CHANNEL_4           (3u)


/******* Channel Status *******/
#define PWM_CHANNEL_DISABLE     (0u)
#define PWM_CHANNEL_ENABLE      (1u)





/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

/* Type definition for PWM_ConfigType used by the PWM APIs */
typedef struct
{
    u16 Prescaler;
    u16 AutoReload;
	u8  Channel_1_Enable;
    u8  Channel_2_Enable;
    u8  Channel_3_Enable;
    u8  Channel_4_Enable;
}PWM_ConfigType;



/*******************************************************************************
 *                             Functions Prototypes                            *
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
void PWM_init(u8 instanceID, PWM_ConfigType *cfgPtr);


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
void PWM_setSignalByValue(u8 instanceID, u8 channelID, u16 value);


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
void PWM_setSignalByPercent(u8 instanceID, u8 channelID, u8 percent);



#endif /* PWM_H */
