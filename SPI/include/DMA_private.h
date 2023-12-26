/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 4/11/2023				    */
/****************************************/

#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H


#define DMA_BASE_ADDRESS			0x40020000
#define DMA							((volatile DMA_RegMap *) DMA_BASE_ADDRESS)



typedef struct
{
	u32 CCR;
	u32 CNDTR;
	u32 CPAR;
	u32 CMAR;
	const u32 dummy_reserved;
	
}DMA_Channel;

typedef struct
{
	u32	ISR;
	u32 IFCR;
	DMA_Channel Channel[7];
	
}DMA_RegMap;


#endif  /* DMA_PRIVATE_H */