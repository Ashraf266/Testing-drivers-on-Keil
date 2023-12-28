/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 7/11/2023				    */
/****************************************/

/* not a full driver but it works for the synchronous configuration */

/*---------------------------------- Includes ----------------------------------*/
#include "std_types.h"
#include "bit_math.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"


/*---------------------------------- Global Variables ----------------------------------*/

static volatile void (*TX_CallBack[2])(u16) = {NULL_PTR};
static volatile void (*RX_CallBack[2])(void) = {NULL_PTR};


/*---------------------------------- ISR ----------------------------------*/
void SPI1_IRQHandler(void)
{
	if(TX_CallBack[0] != NULL_PTR)
	{
		TX_CallBack[0](SPI[0]->DR);
	}
	/* IDK when to use it cuz it sends IRQs when the the buffer is busy */
	if(RX_CallBack[0] != NULL_PTR)
	{
		RX_CallBack[0]();
	}
	
}

void SPI2_IRQHandler(void)
{
	if(TX_CallBack[1] != NULL_PTR)
	{
		TX_CallBack[1](SPI[1]->DR);
	}
	
	if(RX_CallBack[1] != NULL_PTR)
	{
		RX_CallBack[1]();
	}
	
}


/*---------------------------- Function Definitions -------------------------*/

void SPI_voidInit(u8 copy_u8InstanceID, SPI_Cfg *cfgPtr)
{
	
	SPI[copy_u8InstanceID]->CR1 = 0x00000300;
	SPI[copy_u8InstanceID]->CR1 |= (cfgPtr->DataFormat << 11);
	SPI[copy_u8InstanceID]->CR1 |= (cfgPtr->FirstBit << 7);
	SPI[copy_u8InstanceID]->CR1 |= (cfgPtr->BaudRate << 3);
	SPI[copy_u8InstanceID]->CR1 |= (cfgPtr->Master_Slave << 2);
	SPI[copy_u8InstanceID]->CR1 |= (cfgPtr->ClockPolarity << 1);
	SPI[copy_u8InstanceID]->CR1 |= (cfgPtr->ClockPhase << 0);
	
	SPI[copy_u8InstanceID]->CR2 = 0x00000000;
	SPI[copy_u8InstanceID]->CR2 |= (cfgPtr->TX_Interrupt << 7);
	SPI[copy_u8InstanceID]->CR2 |= (cfgPtr->RX_Interrupt << 6);
	
	TX_CallBack[copy_u8InstanceID] = cfgPtr->TX_INT_FUNC;
	RX_CallBack[copy_u8InstanceID] = cfgPtr->RX_INT_FUNC;
	
	/* Enable SPI */
	SPI[copy_u8InstanceID]->CR1 |= (1 << 6);
}



u16 SPI_u16SendReceiveSync(u8 copy_u8InstanceID, u16 copy_u16DataToTransmit)
{
	
	SPI[copy_u8InstanceID]->DR = copy_u16DataToTransmit;
	while( GET_BIT( SPI[copy_u8InstanceID]->SR , 7) == 1 );
	
	return SPI[copy_u8InstanceID]->DR;
	
}


void SPI_voidSendReceiveAsync(u8 copy_u8InstanceID, u16 copy_u16DataToTransmit)
{
	SPI[copy_u8InstanceID]->DR = copy_u16DataToTransmit;
}