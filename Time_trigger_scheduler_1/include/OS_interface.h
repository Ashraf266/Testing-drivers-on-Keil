/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 2/11/2023				    */
/****************************************/

#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H

/*---------------------------------- Definitions ----------------------------------*/


/*---------------------------- Function Declarations -------------------------*/

void OS_init(void);

void OS_voidCreateTask(u8 copy_u8ID, u16 copy_u16Periodicity, void (*ptr)(void), u8 copy_u8FirstDelay);

void OS_voidStart(void);





#endif  /* OS_INTERFACE_H */