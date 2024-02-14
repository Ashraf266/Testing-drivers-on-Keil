/********************************************************************
 * Module       : spi                                               *
 * File Name    : spi.c                                             *
 * Description  : spi Implementation                                *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/


#include "bit_math.h"
#include "spi.h"
#include "spi_private.h"



/*******************************************************************************
 *                               Global Variables                              *
 *******************************************************************************/

/* a Call Back function that receives the data */
static volatile void (*CallBackFunc[2])(u16) = {NULL_PTR, NULL_PTR};

/*******************************************************************************
 *                                      ISR                                    *
 *******************************************************************************/

void SPI1_IRQHandler(void)
{
	if(CallBackFunc[0] != NULL_PTR)
	{
		CallBackFunc[0](SPI[0]->DR);
	}
	/* Stop the interrupts after finishing */
	CLR_BIT(SPI[0]->CR2, 7);
	
}

void SPI2_IRQHandler(void)
{
	if(CallBackFunc[1] != NULL_PTR)
	{
		CallBackFunc[1](SPI[1]->DR);
	}
	/* Stop the interrupts after finishing */
	CLR_BIT(SPI[1]->CR2, 7);
	
}


/*******************************************************************************
 *                             Functions Definition                            *
 *******************************************************************************/


/******************************************************************
[Function Name] : SPI_init                                        *
[Description]   : Initializes SPI peripheral                      *
[Args]:         : u8 instanceID, SPI_ConfigType *cfgPtr           *
[in]	        : the ID of the SPI peripheral                    *
|                 pointer to the configuration structure          *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void SPI_init(u8 instanceID, SPI_ConfigType *cfgPtr)
{
	
	/* Set the SPI Configurations */
	SPI[instanceID]->CR1 = 0x00000300;
	SPI[instanceID]->CR1 |= (cfgPtr->DataFormat << 11);
	SPI[instanceID]->CR1 |= (cfgPtr->FirstBit << 7);
	SPI[instanceID]->CR1 |= (cfgPtr->BaudRate << 3);
	SPI[instanceID]->CR1 |= (cfgPtr->Master_Slave << 2);
	SPI[instanceID]->CR1 |= (cfgPtr->ClockPolarity << 1);
	SPI[instanceID]->CR1 |= (cfgPtr->ClockPhase << 0);
	
	/* Clear all interrupts */
	SPI[instanceID]->CR2 = 0x00000000;

	/* Set the call back function */
	CallBackFunc[instanceID] = (volatile void (*)(u16))cfgPtr->INT_FUNC;

	/* Enable SPI */
	SPI[instanceID]->CR1 |= (1 << 6);
}


/******************************************************************
[Function Name] : SPI_sendReceiveSync                             *
[Description]   : Sync function to Transmit data                  *
[Args]:         : u8 instanceID, u16 dataToTransmit               *
[in]	        : the ID of the SPI peripheral                    *
|                 data to be transmitted                          *
[out]	        : The received data                               *
[in/out]        : NOTHING                                         *
[Returns]       : u16                                             *
[NOTES]         : if Data format is 8 bit write 8bit data         *
|                 instead of 16 bit                               *
*******************************************************************/
u16 SPI_sendReceiveSync(u8 instanceID, u16 dataToTransmit)
{
	/* Start sending the data */
	SPI[instanceID]->DR = dataToTransmit;
	/* Wait until data is send */
	while( GET_BIT( SPI[instanceID]->SR , 7) == 1 );
	/* Return the received data */
	return SPI[instanceID]->DR;
	
}


/******************************************************************
[Function Name] : SPI_sendReceiveAsync                            *
[Description]   : Sync function to Transmit data                  *
[Args]:         : u8 instanceID, u16 dataToTransmit               *
[in]	        : the ID of the SPI peripheral                    *
|                 data to be transmitted                          *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
[NOTES]         : if Data format is 8 bit write 8bit data         *
|                 instead of 16 bit                               *
*******************************************************************/
void SPI_sendReceiveAsync(u8 instanceID, u16 dataToTransmit)
{
	/* Start sending the data */
	SPI[instanceID]->DR = dataToTransmit;
	/* Enable the interrupt */
    SET_BIT(SPI[instanceID]->CR2, 7);
}

