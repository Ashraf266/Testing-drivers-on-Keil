/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 30/7/2023					*/
/****************************************/

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_


/* Select System Clock Type */
/* Options:		RCC_HSE_CRYSTAL
				RCC_HSE_RC
				RCC_HSI
				RCC_PLL				*/
#define	RCC_CLOCK_TYPE		RCC_PLL



/* PLL Configurations */
#if RCC_CLOCK_TYPE == RCC_PLL
/* NOTE: Select value only if you have PLL as input clock source */

/* Options:		RCC_PLL_IN_HSI_DIV_2
				RCC_PLL_IN_HSE_DIV_2
				RCC_PLL_IN_HSE		*/
#define RCC_PLL_INPUT		RCC_PLL_IN_HSE

/* Options: 2 to 16 */
#define RCC_PLL_MUL_VAL		9

/* Options: 0, 2, 4, 8, or 16 */
#define	RCC_PLL_APB1_PRESCALER	2

/* Options: 0, 2, 4, 8, or 16 */
#define	RCC_PLL_APB2_PRESCALER	0

/* Options: 0, 2, 4, 8, 16, 64, 128, 256, 512 */
#define	RCC_PLL_AHB_PRESCALER	0

#endif

	




#endif /* RCC_CONFIG_H_ */
