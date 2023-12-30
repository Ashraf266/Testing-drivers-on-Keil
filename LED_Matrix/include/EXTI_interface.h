/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 28/10/2023				*/
/****************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


/*---------------------------------- Definitions ----------------------------------*/

/* Line Trigger Mode */
#define EXTI_RISING_EDGE					(0u)
#define EXTI_FALLING_EDGE					(1u)
#define EXTI_ON_LOGIC_CHANGE				(2u)


/*---------------------------- Function Declarations -------------------------*/

void EXTI_voidInit(u8 copy_u8Line, u8 copy_u8Mode);

void EXTI_voidEnableEXTI(u8 copy_u8Line);

void EXTI_voidDisableEXTI(u8 copy_u8Line);

void EXTI_voidSwTrigger(u8 copy_u8Line);



#endif  /* EXTI_INTERFACE_H */