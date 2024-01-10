/********************************************************************
 * Module       : spi                                               *
 * File Name    : spi.h                                             *
 * Description  : contains definitions & interfaces for spi driver  *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/

#ifndef SPI_H
#define SPI_H

#include "spi_cfg.h"
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/******* SPI IDs *******/
#define SPI_1_ID                        (0u)
#define SPI_2_ID                        (1u)

/******* Data Format *******/
#define SPI_8_BIT_DATA_FORMAT			(0u)
#define SPI_16_BIT_DATA_FORMAT			(1u)


/******* First Bit *******/
#define SPI_MSB_BIT_FIRST				(0u)
#define SPI_LSB_BIT_FIRST				(1u)


/******* Clock Prescaler *******/
#define SPI_CLK_DIV_2					(0b000)
#define SPI_CLK_DIV_4					(0b001)
#define SPI_CLK_DIV_8					(0b010)
#define SPI_CLK_DIV_16					(0b011)
#define SPI_CLK_DIV_32					(0b100)
#define SPI_CLK_DIV_64					(0b101)
#define SPI_CLK_DIV_128					(0b110)
#define SPI_CLK_DIV_256					(0b111)


/******* Mode *******/
#define SPI_SLAVE_MODE					(0u)
#define SPI_MASTER_MODE					(1u)


/******* Clock Polarity *******/
#define SPI_IDLE_LOW					(0u)
#define SPI_IDLE_HIGH                   (1u)

/******* Clock Phase *******/
/* NOTE Clock Phase is what to do on the first Edge */
#define SPI_READ_ON_FIRST_EDGE			(0u)
#define SPI_WRITE_ON_FIRST_EDGE			(1u)


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

/* Structure contains a configuration of the SPI */
typedef struct
{
	u8 DataFormat;
	u8 FirstBit;
	u8 BaudRate;
	u8 Master_Slave;
	u8 ClockPolarity;
	u8 ClockPhase;
	void (*INT_FUNC)(u16);
	
}SPI_ConfigType;


/*******************************************************************************
 *                               External Variables                            *
 *******************************************************************************/

extern SPI_ConfigType SPI_1_Cfg;
extern SPI_ConfigType SPI_2_Cfg;

/*******************************************************************************
 *                             Functions Prototypes                            *
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
void SPI_init(u8 instanceID, SPI_ConfigType *cfgPtr);


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
u16 SPI_sendReceiveSync(u8 instanceID, u16 dataToTransmit);


/******************************************************************
[Function Name] : SPI_sendReceiveAsync                            *
[Description]   : Async function to Transmit data                 *
[Args]:         : u8 instanceID, u16 dataToTransmit               *
[in]	        : the ID of the SPI peripheral                    *
|                 data to be transmitted                          *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
[NOTES]         : if Data format is 8 bit write 8bit data         *
|                 instead of 16 bit rest forced to be zero by HW  *
*******************************************************************/
void SPI_sendReceiveAsync(u8 instanceID, u16 dataToTransmit);


#endif /* SPI_H */
