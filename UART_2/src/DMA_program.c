/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 4/11/2023				    */
/****************************************/

/*---------------------------------- Includes ----------------------------------*/
#include "std_types.h"
#include "bit_math.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"


/*---------------------------------- Global Variables ----------------------------------*/
static volatile void (* Callback[7])(void) = {NULL_PTR};

/*---------------------------------- ISR ----------------------------------*/

void DMA1_Channel1_IRQHandler(void)
{
	if( Callback[0] != NULL_PTR )
	{
		(* Callback[0])();
	}
	DMA->IFCR = (1 <<(0*4));
	
}

void DMA1_Channel2_IRQHandler(void)
{
	if( Callback[1] != NULL_PTR )
	{
		(* Callback[1])();
	}
	DMA->IFCR = (1 <<(1*4));
	
}

void DMA1_Channel3_IRQHandler(void)
{
	if( Callback[2] != NULL_PTR )
	{
		(* Callback[2])();
	}
	DMA->IFCR = (1 <<(2*4));
	
}

void DMA1_Channel4_IRQHandler(void)
{
	if( Callback[3] != NULL_PTR )
	{
		(* Callback[3])();
	}
	DMA->IFCR = (1 <<(3*4));
	
}

void DMA1_Channel5_IRQHandler(void)
{
	if( Callback[4] != NULL_PTR )
	{
		(* Callback[4])();
	}
	DMA->IFCR = (1 <<(4*4));
	
}

void DMA1_Channel6_IRQHandler(void)
{
	if( Callback[5] != NULL_PTR )
	{
		(* Callback[5])();
	}
	DMA->IFCR = (1 <<(5*4));
	
}

void DMA1_Channel7_IRQHandler(void)
{
	if( Callback[6] != NULL_PTR )
	{
		(* Callback[6])();
	}
	DMA->IFCR = (1 <<(6*4));
	
}



/*---------------------------- Function Definitions -------------------------*/

void DMA_voidChannelInit(u8 copy_u8ChannelID, DMA_Channel_Cfg *copy_ChannelCfgPtr)
{
	/* clear the configuration reg */
	DMA->Channel[copy_u8ChannelID].CCR &= 0x00000000;
	
	/* set mode */
	switch(copy_ChannelCfgPtr->mode)
	{
		case DMA_MEM_TO_MEM_MODE:
		
					SET_BIT(DMA->Channel[copy_u8ChannelID].CCR, 14);
					SET_BIT(DMA->Channel[copy_u8ChannelID].CCR, 4);
					break;
		
		case DMA_MEM_TO_PER_MODE:
		
					SET_BIT(DMA->Channel[copy_u8ChannelID].CCR, 4);
					break;
		
		case DMA_PER_TO_MEM_MODE:
		
					CLR_BIT(DMA->Channel[copy_u8ChannelID].CCR, 4);
					break;
					
		default:
					break;
	}
	
	/* set priority */
	DMA->Channel[copy_u8ChannelID].CCR |= (copy_ChannelCfgPtr->priority << 12);
	
	/* set memory size */
	DMA->Channel[copy_u8ChannelID].CCR |= (copy_ChannelCfgPtr->memory_size << 10);
	
	/* set peripheral size */
	DMA->Channel[copy_u8ChannelID].CCR |= (copy_ChannelCfgPtr->peripheral_size << 8);
	
	/* MINC */
	DMA->Channel[copy_u8ChannelID].CCR |= (copy_ChannelCfgPtr->memory_inc << 7);
	
	/* PINC */
	DMA->Channel[copy_u8ChannelID].CCR |= (copy_ChannelCfgPtr->per_inc << 6);
	
	/* circular mode */
	DMA->Channel[copy_u8ChannelID].CCR |= (copy_ChannelCfgPtr->circular_mode << 5);
	
	/* transfer error interrupt */
	DMA->Channel[copy_u8ChannelID].CCR |= (copy_ChannelCfgPtr->transfer_error_interrupt << 3);
	
	/* half transfer interrupt */
	DMA->Channel[copy_u8ChannelID].CCR |= (copy_ChannelCfgPtr->half_transfer_interrupt << 2);
	
	/* transfer complete interrutp */
	DMA->Channel[copy_u8ChannelID].CCR |= (copy_ChannelCfgPtr->transfer_complete_interrupt << 1);
	
	/* call_back */
	Callback[copy_u8ChannelID] = copy_ChannelCfgPtr->ptr_func;
	
}

void DMA_voidChannelStart(u8 copy_u8ChannelID, u32 *copy_Pu32MemoryAddress, u32 *copy_Pu32PeripheralAddress, u16 copy_u16BlockLength)
{
	/* make sure channel is disabled */
	CLR_BIT(DMA->Channel[copy_u8ChannelID].CCR, 0);
	
	/* set block length */
	DMA->Channel[copy_u8ChannelID].CNDTR = copy_u16BlockLength;
	
	/* set peripheral address */
	DMA->Channel[copy_u8ChannelID].CPAR  = copy_Pu32PeripheralAddress;
	
	/* set memory address */
	DMA->Channel[copy_u8ChannelID].CMAR  = copy_Pu32MemoryAddress;
	
	/* Enable Channel */
	SET_BIT(DMA->Channel[copy_u8ChannelID].CCR, 0);
}

void DMA_voidChannelStop(u8 copy_u8ChannelID)
{
	CLR_BIT(DMA->Channel[copy_u8ChannelID].CCR, 0);
}