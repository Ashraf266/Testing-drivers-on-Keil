/********************************************************************
 * Module       : rcc                                              *
 * File Name    : rcc_private.h                                    *
 * Description  : contains private definitions & types              *
 * Author       : Mohamed Ashraf                                    *
 *******************************************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

#define RCC_BASE_ADDRESS	                    0x40021000

/* Register Map Structure for the RCC */
typedef struct
{
    u32 CR;
    u32 CFGR;
    u32 CIR;
    u32 APB2RSTR;
    u32 APB1RSTR;
    u32 AHBENR;
    u32 APB2ENR;
    u32 APB1ENR;
    u32 BDCR;
    u32 CSR;

}RCC_RegMap;

#define RCC                                     ((volatile RCC_RegMap *)(RCC_BASE_ADDRESS))

/* Clock Types */
#define	RCC_HSE_CRYSTAL				(0u)
#define	RCC_HSE_RC					(1u)
#define	RCC_HSI						(2u)
#define	RCC_PLL						(3u)

/* PLL Options */
#define	RCC_PLL_IN_HSI_DIV_2		(0u)
#define	RCC_PLL_IN_HSE_DIV_2		(1u)
#define	RCC_PLL_IN_HSE				(2u)


#endif /* RCC_PRIVATE_H */
