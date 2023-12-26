/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 30/7/2023					*/
/****************************************/

#include "std_types.h"
#include "bit_math.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"



void RCC_voidInitSysClock(void)
{
	
	#if		RCC_CLOCK_TYPE	==	RCC_HSE_CRYSTAL
	
		RCC_CR = 0x00010000;	/* Enable HSE without Bypass */
		RCC_CFGR = 0x00000001;	/* select HSE as a system clock */
	
	#elif	RCC_CLOCK_TYPE	==	RCC_HSE_RC
	
		RCC_CR = 0x00050000;	/* Enable HSE with Bypass */
		RCC_CFGR = 0x00000001;	/* select HSE as a system clock */
	
	#elif	RCC_CLOCK_TYPE	==	RCC_HSI
	
		RCC_CR = 0x00000081;	/* Enable HSI + Trimming = 0*/
		RCC_CFGR = 0x00000000;	/* select HSI as a system clock */
	
	#elif	RCC_CLOCK_TYPE	==	RCC_PLL
	
		RCC_CFGR = 0x00000003;	/* select PLL as a system clock */
		
		#if	  RCC_PLL_INPUT == 	RCC_PLL_IN_HSI_DIV_2
		
		CLR_BIT(RCC_CFGR, 16);	/* select HSI/2 as input to PLL */
		
		#elif RCC_PLL_INPUT == 	RCC_PLL_IN_HSE_DIV_2
		
		SET_BIT(RCC_CFGR, 17);	/* HSE clock divided by 2 */
		SET_BIT(RCC_CFGR, 16);	/* select HSE as PLL input */
		
		#elif RCC_PLL_INPUT ==	RCC_PLL_IN_HSE
		
		SET_BIT(RCC_CFGR, 16);	/* select HSE as PLL input */
		
		#else
			#error	("WRONG PLL INPUT") 
		#endif
		
		/* set PLL MUL */
		#if ( (RCC_PLL_MUL_VAL >= 2)  ||  (RCC_PLL_MUL_VAL <= 16))
			
		RCC_CFGR |= (RCC_PLL_MUL_VAL - 2) << 18;
		
		#else
			#error	("RCC_PLL_MUL_VAL out of range")
		#endif
		
		/* set APB1 Prescaler */
		
		#if ( (RCC_PLL_APB1_PRESCALER == 0)  ||  (RCC_PLL_APB1_PRESCALER == 2)  ||  (RCC_PLL_APB1_PRESCALER == 4)\
			   ||  (RCC_PLL_APB1_PRESCALER == 8)  ||  (RCC_PLL_APB1_PRESCALER == 16))
			
		switch(RCC_PLL_APB1_PRESCALER)
		{
			case 0:
				RCC_CFGR |= (0b000 << 8);
			break;
			
			case 2:
				RCC_CFGR |= (0b100 << 8);
			break;
			
			case 4:
				RCC_CFGR |= (0b101 << 8);
			break;
			
			case 8:
				RCC_CFGR |= (0b110 << 8);
			break;
			
			case 16:
				RCC_CFGR |= (0b111 << 8);
			break;
			
			default:
				/* do nothing */
				break;
		}
		
		#else
			#error	("RCC_PLL_APB1_PRESCALER out of range")
		#endif
		
		/* set APB2 Prescaler */
		
		#if ( (RCC_PLL_APB2_PRESCALER == 0)  ||  (RCC_PLL_APB2_PRESCALER == 2)  ||  (RCC_PLL_APB2_PRESCALER == 4)\
			   ||  (RCC_PLL_APB2_PRESCALER == 8)  ||  (RCC_PLL_APB2_PRESCALER == 16))
			
		switch(RCC_PLL_APB2_PRESCALER)
		{
			case 0:
				RCC_CFGR |= (0b000 << 11);
			break;
			
			case 2:
				RCC_CFGR |= (0b100 << 11);
			break;
			
			case 4:
				RCC_CFGR |= (0b101 << 11);
			break;
			
			case 8:
				RCC_CFGR |= (0b110 << 11);
			break;
			
			case 16:
				RCC_CFGR |= (0b111 << 11);
			break;
			
			default:
				/* do nothing */
				break;
		}
		
		#else
			#error	("RCC_PLL_APB2_PRESCALER out of range")
		#endif
		
		/* set AHB Prescaler */
		switch(RCC_PLL_APB2_PRESCALER)
		{
			case 0:
				RCC_CFGR |= (0b0000 << 4);
			break;
			
			case 2:
				RCC_CFGR |= (0b1000 << 4);
			break;
			
			case 4:
				RCC_CFGR |= (0b1001 << 4);
			break;
			
			case 8:
				RCC_CFGR |= (0b1010 << 4);
			break;
			
			case 16:
				RCC_CFGR |= (0b1011 << 4);
			break;
			
			case 64:
				RCC_CFGR |= (0b1100 << 4);
			break;

			case 128:
				RCC_CFGR |= (0b1101 << 4);
			break;
			
			case 256:
				RCC_CFGR |= (0b1110 << 4);
			break;
			
			case 512:
				RCC_CFGR |= (0b1111 << 4);
			break;
			
			default:
				/* return Error */
				break;
		}
		
		RCC_CR = 0x01000000;	/* Enable PLL */
		
		while( GET_BIT(RCC_CR, 25) != 1 ); /* wait until the PLL is Locked & ready */

	#else
		#error("WRONG CLOCK TYPE")
	#endif
	
}

void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if( Copy_u8PerId  <= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB  :	SET_BIT(RCC_AHBENR  ,Copy_u8PerId);		break;
			case RCC_APB1 :	SET_BIT(RCC_APB1ENR ,Copy_u8PerId);		break;
			case RCC_APB2 :	SET_BIT(RCC_APB2ENR ,Copy_u8PerId);		break;
			/*default		  : Return Error						break;*/
		}
	}
	else
	{
		/* Return Error */
	}
	
}



void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if( Copy_u8PerId  <= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB  :	CLR_BIT(RCC_AHBENR  ,Copy_u8PerId);		break;
			case RCC_APB1 :	CLR_BIT(RCC_APB1ENR ,Copy_u8PerId);		break;
			case RCC_APB2 :	CLR_BIT(RCC_APB2ENR ,Copy_u8PerId);		break;
			/*default		  : Return Error						break;*/
		}
	}
	else
	{
		/* Return Error */
	}
	
}
