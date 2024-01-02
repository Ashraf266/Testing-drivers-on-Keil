/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 2/11/2023				    */
/****************************************/

#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

#define OS_TASK_READY_STATE					1
#define OS_TASK_RUNNING_STATE				2




typedef struct
{
	u16 periodicity;
	void (* Fptr)(void);
	u8 firstDelay;
	u8 state;
	
}Task;


/*---------------------------- Static Functions Declarations -------------------------*/

static void Scheduler(void);


#endif  /* OS_PRIVATE_H */