/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 7/11/2023				    */
/****************************************/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

/*---------------------------------- Definitions ----------------------------------*/

#define SPI_8_BIT_DATA_FORMAT			(0u)
#define SPI_16_BIT_DATA_FORMAT			(1u)

#define SPI_MSB_BIT_FIRST				(0u)
#define SPI_LSB_BIT_FIRST				(1u)

#define SPI_CLK_DIV_2					(0b000)
#define SPI_CLK_DIV_4					(0b001)
#define SPI_CLK_DIV_8					(0b010)
#define SPI_CLK_DIV_16					(0b011)
#define SPI_CLK_DIV_32					(0b100)
#define SPI_CLK_DIV_64					(0b101)
#define SPI_CLK_DIV_128					(0b110)
#define SPI_CLK_DIV_256					(0b111)

#define SPI_SLAVE_MODE					(0u)
#define SPI_MASTER_MODE					(1u)

#define SPI_ZERO_IDLE					(0u)
#define SPI_ONE_IDLE					(1u)

#define SPI_READ_ON_FIRST_EDGE			(0u)
#define SPI_WRITE_ON_FIRST_EDGE			(1u)

#define SPI_INTERRUPT_DISABLE			(0u)
#define SPI_INTERRUPT_ENABLE			(1u)


/*----------------------------- type definitions ------------------------------*/
typedef struct
{
	u8 DataFormat;
	u8 FirstBit;
	u8 BaudRate;
	u8 Master_Slave;
	u8 ClockPolarity;
	u8 ClockPhase;
	u8 TX_Interrupt;
	u8 RX_Interrupt;
	void (*TX_INT_FUNC)(u16);
	void (*RX_INT_FUNC)(void);
	
}SPI_Cfg;

/*---------------------------- Function Declarations -------------------------*/

void SPI_voidInit(u8 copy_u8InstanceID, SPI_Cfg *cfgPtr);

/* if Data format is 8 bit write 8bit data instead of 16 bit */
u16 SPI_u16SendReceiveSync(u8 copy_u8InstanceID, u16 copy_u16DataToTransmit);

void SPI_voidSendReceiveAsync(u8 copy_u8InstanceID, u16 copy_u16DataToTransmit);


#endif  /* SPI_INTERFACE_H */