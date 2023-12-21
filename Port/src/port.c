/********************************************************************
 * Module       : port                                              *
 * File Name    : port.c                                            *
 * Description  : port Implementation                               *
 * Author       : Mohamed Ashraf                                    *
 *******************************************************************/

#include "std_types.h"
#include "bit_math.h"
#include "port.h"
#include "port_private.h"





/******************************************************************
[Function Name] : PORT_init                                       *
[Description]   : Initializes All MC Pins                         *
[Args]:         : PORT_ConfigType *Config                         *
[in]	        : pointer to the configuration structure          *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void PORT_init(PORT_ConfigType *Config)
{
    u8 pinID;
    u8 pinNumber;
    u8 portNumber;

    /* Initialize each Pin */
    for(pinID = 0; pinID < PORT_NUM_OF_PINS; pinID++)
    {
        /* Skip those pins it's for dubugging */
        if((pinID == 13) || (pinID == 14) || (pinID == 18) || (pinID > 31))
        {
            continue;
        }
        
        /* get port & pin numbers*/
        portNumber = pinID/16;
        pinNumber  = pinID - portNumber*16;

        /* set cfg & mode */
        if (pinNumber < 8 )
        {
            /* Clear OLD Configurations */
            PORT[portNumber]->CRL &= ~((u32)0xF<<(pinNumber*4));

            /* Set NEW Configurations */
            PORT[portNumber]->CRL |= ((u32)((Config->pins[pinID].pinCfg << 2) | Config->pins[pinID].pinMode )<<(pinNumber*4));
        }
        else
        {
            /* Clear OLD Configurations */
            PORT[portNumber]->CRH &= ~((u32)0xF<<(pinNumber*4));

            /* Set NEW Configurations */
            PORT[portNumber]->CRH |= ((u32)((Config->pins[pinID].pinCfg << 2) | Config->pins[pinID].pinMode )<<(pinNumber*4));
        }

        /* Check pin direction to set additional configuration like internal res & Initial pin level*/
        if(Config->pins[pinID].pinDirection == PORT_PIN_OUTPUT)
        {
            /* initialize pin level */
            CLR_BIT(PORT[portNumber]->ODR, pinNumber);
            PORT[portNumber]->ODR |= (Config->pins[pinID].pinDirection << pinNumber);
        }
        else
        {
            /* configure the internal resistor */
            PORT[portNumber]->ODR |= (Config->pins[pinID].pinInternalResistor << pinNumber);
        }


    }
}


