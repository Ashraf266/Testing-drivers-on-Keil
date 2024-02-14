/********************************************************************
 * Module       : i2c                                               *
 * File Name    : i2c.h                                             *
 * Description  : contains definitions & interfaces for i2c driver  *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/

#ifndef I2C_H
#define I2C_H

#include "i2c_cfg.h"
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/******* I2C IDs *******/
#define I2C_1_ID                        (0u)
#define I2C_2_ID                        (1u)

/******* I2C Speed *******/
#define I2C_STANDARD_SPEED              (0u)
#define I2C_FAST_SPEED                  (1u)



/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

/* Structure contains a configuration of the I2C */
typedef struct
{
    u8 speed;
    u8 address;
    u8 clock;
    u8 riseTime;
    u16 clock_control; /* calculated from the datasheet page 782 depends on the speed mode */

}I2C_ConfigType;


/*******************************************************************************
 *                               External Variables                            *
 *******************************************************************************/

extern I2C_ConfigType I2C_1_Cfg;
extern I2C_ConfigType I2C_2_Cfg;

/*******************************************************************************
 *                             Functions Prototypes                            *
 *******************************************************************************/

/******************************************************************
[Function Name] : I2C_init                                        *
[Description]   : Initializes I2C peripheral                      *
[Args]:         : u8 instanceID, I2C_ConfigType *cfgPtr           *
[in]	        : the ID of the I2C peripheral                    *
|                 pointer to the configuration structure          *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void I2C_init(u8 instanceID, I2C_ConfigType *cfgPtr);

void I2C_start(u8 instanceID);

void I2C_stop(u8 instanceID);

void I2C_sendAddress(u8 instanceID, u8 addr, u8 op);

void I2C_writeByte(u8 instanceID, u8 data);

u8 I2C_readWithAck(u8 instanceID);

u8 I2C_readWithNack(u8 instanceID);

#endif /* I2C_H */
