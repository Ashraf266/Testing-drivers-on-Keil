/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 28/10/2023				*/
/****************************************/

#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H


/*---------------------------------- Definitions ----------------------------------*/

#define AFIO_EXTI_LINE_PA				(0b0000)
#define AFIO_EXTI_LINE_PB				(0b0001)
#define AFIO_EXTI_LINE_PC				(0b0010)

/*---------------------------- Function Declarations -------------------------*/

void AFIO_voidSetEXTIConfig(u8 copy_u8Line, u8 copy_u8PortMap);


#endif  /* AFIO_INTERFACE_H */