/********************************************************************
 * Module       : port                                              *
 * File Name    : port_private.h                                    *
 * Description  : contains private definitions & types              *
 * Author       : Mohamed Ashraf                                    *
 *******************************************************************/

#ifndef PORT_PRIVATE_H
#define PORT_PRIVATE_H

#define PORT_PORT_A_BASE_ADDRESS	                    0x40010800
#define PORT_PORT_B_BASE_ADDRESS	                    0x40010C00
#define PORT_PORT_C_BASE_ADDRESS	                    0x40011000

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
	
}PORT_RegMap;

PORT_RegMap *PORT[] = {PORT_PORT_A_BASE_ADDRESS, PORT_PORT_B_BASE_ADDRESS, PORT_PORT_C_BASE_ADDRESS};



#endif /* PORT_PRIVATE_H */