/********************************************************************
 * Module       : rcc                                               *
 * File Name    : rcc_cfg.h                                         *
 * Description  : rcc driver static configurations                  *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/

#ifndef RCC_CFG_H
#define RCC_CFG_H

/******************************************************************
[Required] : Select System Clock                                  *
[Options]  : 1- RCC_HSE_CRYSTAL                                   *
             2- RCC_HSE_RC                                        *
             3- RCC_HSI                                           *
             4- RCC_PLL                                           *
*******************************************************************/
#define	RCC_CLOCK_TYPE		RCC_HSE_CRYSTAL



/* PLL Configurations */
#if RCC_CLOCK_TYPE == RCC_PLL
/* NOTE: Select value only if you have PLL as input clock source */

/******************************************************************
[Required] : Select PLL Input Clock                               *
[Options]  : 1- RCC_PLL_IN_HSI_DIV_2                              *
             2- RCC_PLL_IN_HSE_DIV_2                              *
             3- RCC_PLL_IN_HSE                                    *
*******************************************************************/
#define RCC_PLL_INPUT		RCC_PLL_IN_HSE

/******************************************************************
[Required] : PLL Clock Multiplication Factor                      *
[Options]  : 2 to 16                                              *
*******************************************************************/
#define RCC_PLL_MUL_VAL		9

/******************************************************************
[Required] : APB1 Bus Clock prescaler                             *
[Options]  : 0, 2, 4, 8, or 16                                    *
*******************************************************************/
#define	RCC_PLL_APB1_PRESCALER	2

/******************************************************************
[Required] : APB2 Bus Clock prescaler                             *
[Options]  : 0, 2, 4, 8, or 16                                    *
*******************************************************************/
#define	RCC_PLL_APB2_PRESCALER	0

/* Options: 0, 2, 4, 8, 16, 64, 128, 256, 512 */
/******************************************************************
[Required] : AHB Bus Clock prescaler                              *
[Options]  : 0, 2, 4, 8, 16, 64, 128, 256, 512                    *
*******************************************************************/
#define	RCC_PLL_AHB_PRESCALER	0

#endif


#endif /* RCC_CFG_H */
