/********************************************************************
 * Module       : lcd                                              *
 * File Name    : lcd.h                                            *
 * Description  : contains definitions & interfaces for lcd driver *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/

#ifndef LCD_H
#define LCD_H

#include "lcd_cfg.h"
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/******* LCD Commands *******/
#define LCD_CLEAR_COMMAND                    0x01
#define LCD_GO_TO_HOME                       0x02
#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_ON                        0x0E



/*******************************************************************************
 *                             Functions Prototypes                            *
 *******************************************************************************/


/******************************************************************
[Function Name] : LCD_init                                        *
[Description]   : Initializes The LCD                             *
[Args]:         : void                                            *
[in]	        : NOTHING                                         *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void LCD_init(void);



/******************************************************************
[Function Name] : LCD_sendCommand                                 *
[Description]   : Sends command to The LCD                        *
[Args]:         : u8 command                                      *
[in]	        : command to be send to the LCD                   *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void LCD_sendCommand(u8 command);



/******************************************************************
[Function Name] : LCD_displayCharacter                            *
[Description]   : Displays a character on the screen              *
[Args]:         : u8 data                                         *
[in]	        : Character to be displayed on the LCD            *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void LCD_displayCharacter(u8 data);



/******************************************************************
[Function Name] : LCD_displayString                               *
[Description]   : Displays a string on the screen                 *
[Args]:         : const u8 *str                                   *
[in]	        : pointer to the first character in the string    *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void LCD_displayString(const u8 *str);



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
void LCD_moveCursor(u8 row,u8 col);



/******************************************************************
[Function Name] : LCD_displayStringRowColumn                      *
[Description]   : Displays a string in a certain position         *
[Args]:         : u8 row,u8 col                                   *
[in]	        : row Number & col Number "0 or 1"                *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void LCD_displayStringRowColumn(u8 row ,u8 col, const u8 *str);



/******************************************************************
[Function Name] : LCD_clearScreen                                  *
[Description]   : Clears the Screen                               *
[Args]:         : void                                            *
[in]	        : NOTHING                                         *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void LCD_clearScreen(void);



#endif /* LCD_H */
