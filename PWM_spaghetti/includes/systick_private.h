/********************************************************************
 * Module       : systick                                           *
 * File Name    : systick_private.h                                 *
 * Description  : contains private definitions & types              *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/

#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H


#define SYSTICK_BASE_ADDRESS				0xE000E010
#define SYSTICK								((volatile SYSTICK_RegMap *) SYSTICK_BASE_ADDRESS)

#define SYSTICK_CLK_AHB_8					(0u)
#define SYSTICK_CLK_AHB						(1u)

typedef struct
{
	u32 ENABLE		:  1;
	u32 TICK_INT	:  1;
	u32 CLKSOURCE	:  1;
	u32 			: 13;
	u32 COUNTFLAG	:  1;
	u32 			:  0;
	u32 LOAD;
	u32 VAL;
	
}SYSTICK_RegMap;


#endif  /* SYSTICK_PRIVATE_H */
