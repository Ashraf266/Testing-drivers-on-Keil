#include "std_types.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "AFIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "SYSTICK_interface.h"
#include "OS_interface.h"
#include "DMA_interface.h"



u32 dma_time = 0;
u32 cpu_time = 0;


void test(void)
{
	static u8 var_test;
	//DMA_voidChannelStop(DMA_CHANNEL_1);
	var_test++;
	dma_time = SYSTICK_u32GetElapsedTime();
}



int main(void)
{
	u32 array1[100] = {8,9,10,10,11,56};
	u32 array2[100] = {1,2,3,4,5,6};
	
	u32 array3[100] = {8,9,10,10,11,56};
	u32 array4[100] = {1,2,3,4,5,6};
	u8 i;
	
	SYSTICK_voidInit();
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2, 2);
	RCC_voidEnableClock(RCC_AHB, 0);
	
	NVIC_voidEnableInterrupt(11);
	
	DMA_Channel_Cfg channel1 = {DMA_MEM_TO_MEM_MODE,
															DMA_VERY_HIGH_PRIORITY,
															DMA_32_BIT_SIZE,
															DMA_32_BIT_SIZE,
															DMA_MEMORY_INC_ENABLE,
															DMA_PERIPHERAL_INC_ENABLE,
															DMA_CIRCULAR_MODE_DISABLE,
															DMA_INTERRUPT_DISABLE,
															DMA_INTERRUPT_DISABLE,
															DMA_INTERRUPT_ENABLE,
															test
	};
	
	DMA_voidChannelInit(DMA_CHANNEL_1, &channel1);
	
	SYSTICK_voidSetIntervalSingle(15000000, NULL_PTR);
	DMA_voidChannelStart(DMA_CHANNEL_1, array1, array2, 100);
	
	//SYSTICK_voidSetBusyWait(3000000);
	
	//DMA_voidChannelStart(DMA_CHANNEL_1, array1, array2, 100);
	for(i=0; i<100; i++)
	{
		array4[i] = array3[i];
	}
	cpu_time = SYSTICK_u32GetElapsedTime();
	SYSTICK_voidStopTimer();
	
	while(1)
	{


	}

}
