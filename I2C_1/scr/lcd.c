/********************************************************************
 * Module       : lcd                                               *
 * File Name    : lcd.c                                             *
 * Description  : lcd Implementation                                *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/


#include "bit_math.h"
#include "lcd.h"
#include "lcd_private.h"
#include "dio.h"


/*******************************************************************************
 *                               Global Variables                              *
 *******************************************************************************/

DIO_pinGroupType dataPins = {
    0xF,
    LCD_DATA_OFFSET,
    LCD_DATA_PORT_ID
    };


/*******************************************************************************
 *                             Functions Definition                            *
 *******************************************************************************/

/* function to make delays in ms not accurate but it does the work */
static void delay(u32 ms)
{
    volatile u32 i;
    for (i = 0; i < (ms*1000*LCD_CPU_CLK); i++)
    {
        __asm("NOP");
    }
}

/******************************************************************
[Function Name] : LCD_init                                        *
[Description]   : Initializes The LCD                             *
[Args]:         : void                                            *
[in]	        : NOTHING                                         *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void LCD_init(void)
{

    delay(20);		/* LCD Power ON delay always > 15ms */

    /* Initialization sequence for 4-bit mode */
    LCD_sendCommand(0x02); /* 4-bit mode initialization */
    LCD_sendCommand(0x28); /* Function Set: 2 lines, 5x8 matrix */
    LCD_sendCommand(0x0C); /* Display On, Cursor Off, Blink Off */
    LCD_sendCommand(0x06); /* Entry Mode Set: Increment cursor, No display shift */
    LCD_sendCommand(0x01); /* Clear display */

    delay(2); /* Additional delay after clearing the display */
}



/******************************************************************
[Function Name] : LCD_sendCommand                                 *
[Description]   : Sends command to The LCD                        *
[Args]:         : u8 command                                      *
[in]	        : command to be send to the LCD                   *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void LCD_sendCommand(u8 command)
{
    /* send Higher nibble */
    DIO_writePinGroup(&dataPins, (command>>4));
    DIO_writePin(LCD_RS_PORT_ID, LCD_RS_PIN_ID, DIO_PIN_LOW);
    DIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, DIO_PIN_HIGH);
    delay(1);
    DIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, DIO_PIN_LOW);
    delay(1);

    /* send Lower nibble */
    DIO_writePinGroup(&dataPins, (command&0xF));
    DIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, DIO_PIN_HIGH);
    delay(1);
    DIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, DIO_PIN_LOW);

    delay(2);
}



/******************************************************************
[Function Name] : LCD_displayCharacter                            *
[Description]   : Displays a character on the screen              *
[Args]:         : u8 data                                         *
[in]	        : Character to be displayed on the LCD            *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void LCD_displayCharacter(u8 data)
{
        /* send Higher nibble */
    DIO_writePinGroup(&dataPins, (data>>4));
    DIO_writePin(LCD_RS_PORT_ID, LCD_RS_PIN_ID, DIO_PIN_HIGH);
    DIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, DIO_PIN_HIGH);
    delay(1);
    DIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, DIO_PIN_LOW);
    delay(1);

    /* send Lower nibble */
    DIO_writePinGroup(&dataPins, (data&0xF));
    DIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, DIO_PIN_HIGH);
    delay(1);
    DIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, DIO_PIN_LOW);

    delay(2);
}



/******************************************************************
[Function Name] : LCD_displayString                               *
[Description]   : Displays a string on the screen                 *
[Args]:         : u8 data                                         *
[in]	        : pointer to the first character in the string    *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void LCD_displayString(const u8 *str)
{
	u8 i = 0;
	while(str[i] != '\0')
	{
		LCD_displayCharacter(str[i]);
		i++;
	}
}



/******************************************************************
[Function Name] : LCD_moveCursor                                  *
[Description]   : Moves the cursor to a certain position          *
|                 the screen                                      *
[Args]:         : u8 row,u8 col                                   *
[in]	        : row Number & col Number "0 or 1"                *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void LCD_moveCursor(u8 row, u8 col)
{
    u8 position = 0x80; /* Base address for the first row */

    if (row == 1) {
        position = 0xC0; /* Base address for the second row */
    }

    position += col; /* Adjust for the column */

    LCD_sendCommand(position | 0x80); /* Set cursor to the calculated position */
}



/******************************************************************
[Function Name] : LCD_displayStringRowColumn                      *
[Description]   : Displays a string in a certain position         *
[Args]:         : u8 row,u8 col                                   *
[in]	        : row Number & col Number "0 or 1"                *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void LCD_displayStringRowColumn(u8 row, u8 col, const u8 *str)
{
	LCD_moveCursor(row,col); /* go to to the required LCD position */
	LCD_displayString(str); /* display the string */
}



/******************************************************************
[Function Name] : LCD_clearScreen                                  *
[Description]   : Clears the Screen                               *
[Args]:         : void                                            *
[in]	        : NOTHING                                         *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* Send clear display command */
}

