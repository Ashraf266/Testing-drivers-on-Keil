/********************************************************************
 * Module       : rcc                                               *
 * File Name    : rcc.c                                             *
 * Description  : rcc Driver Implementation                         *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/

#include "bit_math.h"
#include "rcc.h"
#include "rcc_private.h"


/*******************************************************************************
 *                             Functions Definition                            *
 *******************************************************************************/


/******************************************************************
[Function Name] : RCC_init                                        *
[Description]   : Initializes the Clock based on static cfg       *
[Args]:         : void                                            *
[in]	        : NOTHING                                         *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void RCC_init(void)
{

#if		RCC_CLOCK_TYPE	==	RCC_HSE_CRYSTAL

	RCC->CR = 0x00010000;	/* Enable HSE without Bypass */
	RCC->CFGR = 0x00000001;	/* select HSE as a system clock */
    while( GET_BIT(RCC->CR, 17) != 1 ); /* wait until the HSE is ready */

#elif	RCC_CLOCK_TYPE	==	RCC_HSE_RC

	RCC->CR = 0x00050000;	/* Enable HSE with Bypass */
	RCC->CFGR = 0x00000001;	/* select HSE as a system clock */
    while( GET_BIT(RCC->CR, 17) != 1 ); /* wait until the HSE is ready */

#elif	RCC_CLOCK_TYPE	==	RCC_HSI

	RCC->CR = 0x00000081;	/* Enable HSI + Trimming = 0*/
	RCC->CFGR = 0x00000000;	/* select HSI as a system clock */
    while( GET_BIT(RCC->CR, 1) != 1 ); /* wait until the HSI is ready */

#elif	RCC_CLOCK_TYPE	==	RCC_PLL

	RCC->CFGR = 0x00000003;	/* select PLL as a system clock */
	
	#if	  RCC_PLL_INPUT == 	RCC_PLL_IN_HSI_DIV_2
	
	CLR_BIT(RCC->CFGR, 16);	/* select HSI/2 as input to PLL */
	
	#elif RCC_PLL_INPUT == 	RCC_PLL_IN_HSE_DIV_2
	
	SET_BIT(RCC->CFGR, 17);	/* HSE clock divided by 2 */
	SET_BIT(RCC->CFGR, 16);	/* select HSE as PLL input */
	
	#elif RCC_PLL_INPUT ==	RCC_PLL_IN_HSE
	
	SET_BIT(RCC->CFGR, 16);	/* select HSE as PLL input */
	
	#else
		#error	("WRONG PLL INPUT") 
	#endif
	
	/* set PLL MUL */	
	RCC->CFGR |= (RCC_PLL_MUL_VAL - 2) << 18;

	
	/* set APB1 Prescaler */	
	switch(RCC_PLL_APB1_PRESCALER)
	{
		case 0:
			RCC->CFGR |= (0b000 << 8);
		break;
		
		case 2:
			RCC->CFGR |= (0b100 << 8);
		break;
		
		case 4:
			RCC->CFGR |= (0b101 << 8);
		break;
		
		case 8:
			RCC->CFGR |= (0b110 << 8);
		break;
		
		case 16:
			RCC->CFGR |= (0b111 << 8);
		break;
		
		default:
			/* do nothing */
			break;
	}
	
	/* set APB2 Prescaler */
	switch(RCC_PLL_APB2_PRESCALER)
	{
		case 0:
			RCC->CFGR |= (0b000 << 11);
		break;
		
		case 2:
			RCC->CFGR |= (0b100 << 11);
		break;
		
		case 4:
			RCC->CFGR |= (0b101 << 11);
		break;
		
		case 8:
			RCC->CFGR |= (0b110 << 11);
		break;
		
		case 16:
			RCC->CFGR |= (0b111 << 11);
		break;
		
		default:
			/* do nothing */
			break;
	}
	
	/* set AHB Prescaler */
	switch(RCC_PLL_APB2_PRESCALER)
	{
		case 0:
			RCC->CFGR |= (0b0000 << 4);
		break;
		
		case 2:
			RCC->CFGR |= (0b1000 << 4);
		break;
		
		case 4:
			RCC->CFGR |= (0b1001 << 4);
		break;
		
		case 8:
			RCC->CFGR |= (0b1010 << 4);
		break;
		
		case 16:
			RCC->CFGR |= (0b1011 << 4);
		break;
		
		case 64:
			RCC->CFGR |= (0b1100 << 4);
		    break;

		case 128:
			RCC->CFGR |= (0b1101 << 4);
		    break;
		
		case 256:
			RCC->CFGR |= (0b1110 << 4);
		    break;
		
		case 512:
			RCC->CFGR |= (0b1111 << 4);
		    break;
		
		default:
			break;
	}
	
	RCC->CR = 0x01000000;	/* Enable PLL */
	
	while( GET_BIT(RCC->CR, 25) != 1 ); /* wait until the PLL is Locked & ready */
#else
	#error("WRONG CLOCK TYPE")
#endif

}


/******************************************************************
[Function Name] : RCC_init                                        *
[Description]   : Enables Clock for specific Peripheral           *
[Args]:         : u8 BusID  &  u8 PerID                           *
[in]	        : NOTHING                                         *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void RCC_EnableClock(u8 BusID, u8 PerID)
{
    switch (BusID)
    {
    case RCC_AHB:
        SET_BIT(RCC->AHBENR, PerID);
        break;

    case RCC_APB1:
        SET_BIT(RCC->APB1ENR, PerID);
        break;

    case RCC_APB2:
        SET_BIT(RCC->APB2ENR, PerID);
        break;
    
    default:
        break;
    }
}


/******************************************************************
[Function Name] : RCC_init                                        *
[Description]   : Disable Clock for specific Peripheral           *
[Args]:         : u8 BusID  &  u8 PerID                           *
[in]	        : NOTHING                                         *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void RCC_DisableClock(u8 BusID, u8 PerID)
{
    switch (BusID)
    {
    case RCC_AHB:
        CLR_BIT(RCC->AHBENR, PerID);
        break;

    case RCC_APB1:
        CLR_BIT(RCC->APB1ENR, PerID);
        break;

    case RCC_APB2:
        CLR_BIT(RCC->APB2ENR, PerID);
        break;
    
    default:
        break;
    }
}
