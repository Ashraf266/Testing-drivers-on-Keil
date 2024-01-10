/********************************************************************
 * Module       : dio                                               *
 * File Name    : dio_private.h                                     *
 * Description  : contains private definitions & types              *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/

#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

#define DIO_PORT_A_BASE_ADDRESS	                    0x40010800
#define DIO_PORT_B_BASE_ADDRESS	                    0x40010C00
#define DIO_PORT_C_BASE_ADDRESS	                    0x40011000

/* Register Map Structure for the GPIO */
typedef struct
{
	u32 CRL;
    u32 CRH;
    u32 IDR;
    u32 ODR;
    u32 BSRR;
    u32 BRR;
    u32 LCKR;
	
}DIO_RegMap;

volatile DIO_RegMap *const DIO[] = {(DIO_RegMap *)DIO_PORT_A_BASE_ADDRESS, (DIO_RegMap *)DIO_PORT_B_BASE_ADDRESS, (DIO_RegMap *)DIO_PORT_C_BASE_ADDRESS};



#endif /* DIO_PRIVATE_H */
