/********************************************************************
 * Module       : i2c                                               *
 * File Name    : i2c_private.h                                     *
 * Description  : contains private definitions & types              *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/

#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H


#define I2C_1_BASE_ADDRESS			0x40005400
#define I2C_2_BASE_ADDRESS			0x40005800


typedef struct
{
	u32 CR1;
	u32 CR2;
	u32 OAR1;
	u32 OAR2;
    u32 DR;
    u32 SR1;
    u32 SR2;
    u32 CCR;
    u32 TRISE;
	
}I2C_RegMap;



volatile I2C_RegMap *I2C[] = {(I2C_RegMap *)I2C_1_BASE_ADDRESS, (I2C_RegMap *)I2C_2_BASE_ADDRESS};

#endif  /* I2C_PRIVATE_H */
