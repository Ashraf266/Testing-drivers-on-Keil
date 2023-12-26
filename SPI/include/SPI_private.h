/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 7/11/2023				    */
/****************************************/

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H


#define SPI_1_BASE_ADDRESS			0x40013000
#define SPI_2_BASE_ADDRESS			0x40003800


typedef struct
{
	u32 CR1;
	u32 CR2;
	u32 SR;
	u32 DR;
	
}SPI_RegMap;



volatile SPI_RegMap *SPI[] = { SPI_1_BASE_ADDRESS, SPI_2_BASE_ADDRESS};

#endif  /* SPI_PRIVATE_H */