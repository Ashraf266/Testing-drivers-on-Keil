#include "std_types.h"
#include "rcc.h"
#include "port.h"
#include "systick.h"

#define PWM_TIM1_BASE_ADDRESS	                    0x40012C00
#define PWM_TIM2_BASE_ADDRESS	                    0x40000000
#define PWM_TIM3_BASE_ADDRESS	                    0x40000400
#define PWM_TIM4_BASE_ADDRESS	                    0x40000800

/* Register Map Structure for the GP TIM */
typedef struct
{
    u32 CR1;
    u32 CR2;
    u32 SMCR;
    u32 DIER;
    u32 SR;
    u32 EGR;
    u32 CCMR1;
    u32 CCMR2;
    u32 CCER;
    u32 CNT;
    u32 PSC;
    u32 ARR;
    u32 reserved_1; /* Not reserved in TIM1 but we won't use it in this Driver */
    u32 CCR1;
    u32 CCR2;
    u32 CCR3;
    u32 CCR4;
    u32 reserved_2; /* Not reserved in TIM1 but we won't use it in this Driver */
    u32 DCR;
    u32 DMAR;
	
}PWM_RegMap;


volatile PWM_RegMap *const PWM[] = {
    (PWM_RegMap *)PWM_TIM1_BASE_ADDRESS, 
    (PWM_RegMap *)PWM_TIM2_BASE_ADDRESS, 
    (PWM_RegMap *)PWM_TIM3_BASE_ADDRESS,
    (PWM_RegMap *)PWM_TIM4_BASE_ADDRESS};


int main(void)
{

	RCC_init();
	RCC_EnableClock(RCC_APB2, 2);
	RCC_EnableClock(RCC_APB2, 3);
	RCC_EnableClock(RCC_APB2, 4);
	RCC_EnableClock(RCC_APB2, RCC_APB2_TIM1);
	RCC_EnableClock(RCC_APB1, RCC_APB1_TIM4);
	
	PORT_init(&configurations);
	
/* PWM init */
	PWM[0] ->CR1 = (1<< 7) | (1<< 0);
	PWM[0] ->CR2 = 0;
	PWM[0] ->SMCR = 0;
	PWM[0] ->DIER = 0;
	PWM[0] ->EGR = 0;
	PWM[0] ->CCMR1 = (0b110 << 4) | (1 << 3);
	PWM[0] ->CCMR2 = 0;
	PWM[0] ->CCER = (1<<0);
	PWM[0] ->PSC = 71;
	PWM[0] ->ARR = 5000;
	PWM[0] ->DCR = 0;
	PWM[0] ->CCR1 = 0;
	
	PWM[0] ->reserved_2 = 1<<15; // Only needed in TIM1 reserved_2 refers to BDTR register
	

	while(1)
	{
		
		SYSTICK_setBusyWait(15000000);
		PWM[0] ->CCR1 = 0;
		SYSTICK_setBusyWait(15000000);
		PWM[0] ->CCR1 = 1000;
		SYSTICK_setBusyWait(15000000);
		PWM[0] ->CCR1 = 2000;
		SYSTICK_setBusyWait(15000000);
		PWM[0] ->CCR1 = 3000;
		SYSTICK_setBusyWait(15000000);
		PWM[0] ->CCR1 = 4000;
		SYSTICK_setBusyWait(15000000);
		PWM[0] ->CCR1 = 5000;

	}

}
