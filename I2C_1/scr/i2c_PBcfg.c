/********************************************************************
 * Module       : i2c                                               *
 * File Name    : i2c_PBcfg.c                                       *
 * Description  : Post build configuration for i2c driver           *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/

#include "i2c.h"



I2C_ConfigType I2C_1_Cfg = {
    I2C_STANDARD_SPEED,
    0x05,
    0x24,
    0xf,
    150
};

I2C_ConfigType I2C_2_Cfg = {
    I2C_STANDARD_SPEED,
    0x05,
    0x24,
    36,
    180
};

