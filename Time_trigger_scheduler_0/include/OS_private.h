/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 2/11/2023				    */
/****************************************/

#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

typedef struct
{
	u16 periodicity;
	void (* Fptr)(void);
	
}Task;


/*---------------------------- Static Functions Declarations -------------------------*/

static void Scheduler(void);


#endif  /* OS_PRIVATE_H */