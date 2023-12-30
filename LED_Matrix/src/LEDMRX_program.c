/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 31/10/2023				*/
/****************************************/

/*---------------------------------- Includes ----------------------------------*/
#include "std_types.h"
#include "bit_math.h"

#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"






/*---------------------------- Function Definitions -------------------------*/

void LEDMRX_voidInit(void)
{
	u8 num_rows = 0;
	u8 num_cols = 0;
	
	for(num_rows = 0; num_rows < LEDMRX_ROW_SIZE; num_rows++)
	{
		
		GPIO_voidSetPinDirection(LEDMRX_ROW_PORT_ID, LEDMRX_ROW_FIRST_PIN+ num_rows, GPIO_OUTPUT_PUSH_PULL_10MHZ);
		
	}
	
	for(num_cols = 0; num_cols < LEDMRX_COL_SIZE; num_cols++)
	{
		
		GPIO_voidSetPinDirection(LEDMRX_COL_PORT_ID, LEDMRX_COL_FIRST_PIN+ num_cols, GPIO_OUTPUT_PUSH_PULL_10MHZ);
		
	}
	
	
}



void LEDMRX_voidDisplay(u8 *copy_u8Data)
{
	
	u8 num_rows = 0;
	u8 num_cols = 0;
	u8 bit_value = 0;
	
	/* Disable All Cols */
	for(num_cols = 0; num_cols < LEDMRX_COL_SIZE; num_cols++)
	{
		
		GPIO_voidSetPinValue(LEDMRX_COL_PORT_ID, LEDMRX_COL_FIRST_PIN+ num_cols, LEDMRX_COL_NOT_ACTIVE);
		
	}
	
	/* Enable each column and set rows */
	for(num_cols = 0; num_cols < LEDMRX_COL_SIZE; num_cols++)
	{
		/* Enable COL */
		GPIO_voidSetPinValue(LEDMRX_COL_PORT_ID, LEDMRX_COL_FIRST_PIN+ num_cols, LEDMRX_COL_ACTIVE);
		
			/* set ROW value */
			for(num_rows = 0; num_rows < LEDMRX_ROW_SIZE; num_rows++)
			{
				if( GET_BIT(copy_u8Data[num_cols], num_rows) == 1 )
				{
					bit_value = LEDMRX_ROW_ACTIVE;
				}
				else
				{
					bit_value = LEDMRX_ROW_NOT_ACTIVE;
				}
				GPIO_voidSetPinValue(LEDMRX_ROW_PORT_ID, LEDMRX_ROW_FIRST_PIN+ num_rows, bit_value);
		
			}
		/* delay */
		SYSTICK_voidSetBusyWait(LEDMRX_DELAY_VALUE);
		/* Disable COL */
		GPIO_voidSetPinValue(LEDMRX_COL_PORT_ID, LEDMRX_COL_FIRST_PIN+ num_cols, LEDMRX_COL_NOT_ACTIVE);
		
	}
	
	
	
	
}