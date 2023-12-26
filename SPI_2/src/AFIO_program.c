/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 28/10/2023				*/
/****************************************/

/*---------------------------------- Includes ----------------------------------*/
#include "std_types.h"
#include "bit_math.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"


/*---------------------------- Function Definitions -------------------------*/

void AFIO_voidSetEXTIConfig(u8 copy_u8Line, u8 copy_u8PortMap)
{
	
	AFIO->EXTICR[ copy_u8Line/4 ] &= ~(0xF << ((copy_u8Line%4)*4));
	AFIO->EXTICR[ copy_u8Line/4 ] |= (copy_u8PortMap << ((copy_u8Line%4)*4));
	
}
