#include "std_types.h"
#include "rcc.h"
#include "port.h"
#include "systick.h"
#include "pwm.h"



extern PWM_ConfigType PWM_TIM1_Cfg;





int main(void)
{

	//u16 i;
		RCC_init();
	RCC_EnableClock(RCC_APB2, 2);
	RCC_EnableClock(RCC_APB2, 3);
	RCC_EnableClock(RCC_APB2, 4);
	RCC_EnableClock(RCC_APB2, RCC_APB2_TIM1);
	RCC_EnableClock(RCC_APB1, RCC_APB1_TIM4);
	
	PORT_init(&configurations);
	
/* PWM init */
	PWM_init(0, &PWM_TIM1_Cfg);

	

	while(1)
	{

		/* LED */
		SYSTICK_setBusyWait(15000000);
		PWM_setSignalByValue(0,0,722);//0.722ms
		SYSTICK_setBusyWait(15000000);
		PWM_setSignalByValue(0,0,1250);
		SYSTICK_setBusyWait(15000000);
		PWM_setSignalByValue(0,0,1500);
		SYSTICK_setBusyWait(15000000);
		PWM_setSignalByValue(0,0,1750);
		SYSTICK_setBusyWait(15000000);
		PWM_setSignalByValue(0,0,2500);//2.5ms
		//SYSTICK_setBusyWait(15000000);
		//PWM_setSignalByValue(0,0,5000);


	}

}
