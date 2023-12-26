/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 4/11/2023				    */
/****************************************/

#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

/*---------------------------------- Definitions ----------------------------------*/

#define DMA_CHANNEL_1					(0u)
#define DMA_CHANNEL_2                   (1u)
#define DMA_CHANNEL_3                   (2u)
#define DMA_CHANNEL_4                   (3u)
#define DMA_CHANNEL_5                   (4u)
#define DMA_CHANNEL_6                   (5u)
#define DMA_CHANNEL_7                   (6u)



/* Modes */
#define DMA_MEM_TO_MEM_MODE				(0u)
#define DMA_MEM_TO_PER_MODE             (1u)
#define DMA_PER_TO_MEM_MODE             (2u)

/* Priority */
#define DMA_VERY_HIGH_PRIORITY			(0b11)
#define DMA_HIGH_PRIORITY				(0b10)
#define DMA_MEDIUM_PRIORITY				(0b01)
#define DMA_LOW_PRIORITY				(0b00)

/* size */
#define DMA_8_BIT_SIZE					(0b00)
#define DMA_16_BIT_SIZE					(0b01)
#define DMA_32_BIT_SIZE					(0b10)

/* Incremention */
#define DMA_MEMORY_INC_ENABLE           (1u)
#define DMA_MEMORY_INC_DISABLE          (0u)

#define DMA_PERIPHERAL_INC_ENABLE       (1u)
#define DMA_PERIPHERAL_INC_DISABLE      (0u)

/* circular_mode */
#define DMA_CIRCULAR_MODE_ENABLE        (1u)
#define DMA_CIRCULAR_MODE_DISABLE       (0u)

/* interrupts */
#define DMA_INTERRUPT_ENABLE            (1u)
#define DMA_INTERRUPT_DISABLE           (0u)







/*----------------------------- type definitions ------------------------------*/
/* To do later: add then DMA_PBcfg.c and define there modes for all channels */
typedef struct
{
	u8 mode;
	u8 priority;
	u8 memory_size;
	u8 peripheral_size;
	u8 memory_inc;
	u8 per_inc;
	u8 circular_mode;
	u8 transfer_error_interrupt;
	u8 half_transfer_interrupt;
	u8 transfer_complete_interrupt;
	void (*ptr_func)(void);
	
}DMA_Channel_Cfg;

/*---------------------------- Function Declarations -------------------------*/

void DMA_voidChannelInit(u8 copy_u8ChannelID, DMA_Channel_Cfg *copy_ChannelCfgPtr);

/* in case of MEMORY TO MEMORY the peripheral address is used as a Destination */
void DMA_voidChannelStart(u8 copy_u8ChannelID, u32 *copy_Pu32MemoryAddress, u32 *copy_Pu32PeripheralAddress, u16 copy_u16BlockLength);

void DMA_voidChannelStop(u8 copy_u8ChannelID);


#endif  /* DMA_INTERFACE_H */