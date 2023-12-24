/********************************************************************
 * Module       : port                                              *
 * File Name    : port.h                                            *
 * Description  : contains definitions & interfaces for port driver *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/

#ifndef PORT_H
#define PORT_H

#include "port_cfg.h"
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/******* port cfg *******/

/* General purpose output */
#define PORT_GP_PUSH_PULL_CFG                      (0b00)
#define PORT_GP_OPEN_DRAIN_CFG                     (0b01)

/* as   Alternate Function output*/
#define PORT_AF_PUSH_PULL_CFG                      (0b10)
#define PORT_AF_OPEN_DRAIN_CFG                     (0b11)

/* as Input */
#define PORT_ANALOG_CFG                            (0b00)
#define PORT_INPUT_FLOATING_CFG                    (0b01)
#define PORT_INPUT_INTERNAL_RES_CFG                (0b10)


/******* port modes *******/

#define PORT_INPUT_MODE                            (0b00)
#define PORT_OUTPUT_SPEED_10_MHZ_MODE              (0b01)
#define PORT_OUTPUT_SPEED_2_MHZ_MODE               (0b10)
#define PORT_OUTPUT_SPEED_50_MHZ_MODE              (0b11)

/******* port pin Direction *******/

#define PORT_PIN_INPUT                             (0u)
#define PORT_PIN_OUTPUT                            (1u)

/******* port internal resistor *******/
#define PORT_PIN_FLOATING                          (0u)
#define PORT_PULL_DOWN_RES                         (0u)
#define PORT_PULL_UP_RES                           (1u)

/******* pin level *******/
#define PORT_PIN_LOW                               (0u)
#define PORT_PIN_HIGH                              (1u)

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

/* Structure contains a configuration of a single pin */
typedef struct
{
	u8	  pinID;
	u8	  pinDirection;
	u8	  pinInternalResistor;
    u8 	  pinMode;
	u8	  pinCfg;
	u8	  pinLevel;
}PORT_ConfigPin;

/* Type definition for Port_ConfigType used by the PORT APIs */
typedef struct
{
	PORT_ConfigPin	pins[PORT_NUM_OF_PINS];
}PORT_ConfigType;


/*******************************************************************************
 *                               External Variables                            *
 *******************************************************************************/
extern PORT_ConfigType configurations;


/*******************************************************************************
 *                             Functions Prototypes                            *
 *******************************************************************************/

/******************************************************************
[Function Name] : PORT_init                                       *
[Description]   : Initializes All MC Pins                         *
[Args]:         : PORT_ConfigType *Config                         *
[in]	        : pointer to the configuration structure          *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void PORT_init(PORT_ConfigType *Config);


#endif /* PORT_H */
