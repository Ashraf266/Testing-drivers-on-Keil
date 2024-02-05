/********************************************************************
 * Module       : pwm                                               *
 * File Name    : pwm_private.h                                     *
 * Description  : contains private definitions & types              *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/

#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

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
    u32 RCR;  /* Only Available in TIM1 Reserved in Other Timers */
    u32 CCR1;
    u32 CCR2;
    u32 CCR3;
    u32 CCR4;
    u32 BDTR; /* Only Available in TIM1 Reserved in Other Timers */
    u32 DCR;
    u32 DMAR;
	
}PWM_RegMap;


volatile PWM_RegMap *const PWM[] = {
    (PWM_RegMap *)PWM_TIM1_BASE_ADDRESS, 
    (PWM_RegMap *)PWM_TIM2_BASE_ADDRESS, 
    (PWM_RegMap *)PWM_TIM3_BASE_ADDRESS,
    (PWM_RegMap *)PWM_TIM4_BASE_ADDRESS};


#endif /* PWM_PRIVATE_H */
