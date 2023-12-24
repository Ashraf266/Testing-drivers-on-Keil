#include "port.h"
#include "rcc.h"
#include "dio.h"
#include "lcd.h"
#include "systick.h"

/*
#define DELAY_VAL				(1u)

static void delay(u16 ms)
{
    volatile u32 i;
    for (i = 0; i < (ms*1000*LCD_CPU_CLK); i++)
    {
        __asm("NOP");
    }
}

DIO_pinGroupType LCD_dataPins = {
    0xF,
    7,
    1
    };

void command(u8 cmd)
{
	DIO_writePinGroup(&LCD_dataPins, (cmd>>4));
	DIO_writePin(0,0,0);
	DIO_writePin(0,1,1);
	delay(DELAY_VAL);
	DIO_writePin(0,1,0);
	delay(DELAY_VAL);
	
	DIO_writePinGroup(&LCD_dataPins, (cmd&0xF));
	DIO_writePin(0,1,1);
	delay(DELAY_VAL);
	DIO_writePin(0,1,0);
	
	delay(2);
}

void data(u8 cmd)
{
	DIO_writePinGroup(&LCD_dataPins, (cmd>>4));
	DIO_writePin(0,0,1);
	DIO_writePin(0,1,1);
	delay(DELAY_VAL);
	DIO_writePin(0,1,0);
	delay(DELAY_VAL);
	
	DIO_writePinGroup(&LCD_dataPins, (cmd&0xF));
	DIO_writePin(0,1,1);
	delay(DELAY_VAL);
	DIO_writePin(0,1,0);
	
	delay(2);
}


void LCD_set_cursor(u8 row, u8 col) {
    u8 position = 0x80; // Base address for the first row

    if (row == 1) {
        position = 0xC0; // Base address for the second row
    }

    position += col; // Adjust for the column

    LCD_sendCommand(position | 0x80); // Set cursor to the calculated position
}
*/


int main(void)
{
	volatile u8 i = 0;
	RCC_init();
	RCC_EnableClock(RCC_APB2, 2);
	RCC_EnableClock(RCC_APB2, 3);
	RCC_EnableClock(RCC_APB2, 4);
	
	PORT_init(&configurations);
	SYSTICK_init();
	
	/*

	delay(20);
    // Initialization sequence for 4-bit mode
    command(0x02); // 4-bit mode initialization
    command(0x28); // Function Set: 2 lines, 5x8 matrix
    command(0x0C); // Display On, Cursor Off, Blink Off
    command(0x06); // Entry Mode Set: Increment cursor, No display shift
    command(0x01); // Clear display
    delay(2); // Additional delay after clearing the display
	
	
	data('a');
	*/
	
	LCD_init();
	SYSTICK_setBusyWait(2000000);
	//LCD_sendCommand(LCD_CURSOR_ON);
	LCD_displayString((u8*)"LCD Testing...");
	//SYSTICK_setBusyWait(5000000);
	LCD_displayStringRowColumn(1,0,(u8*)"By Ashraf");
	
	while(1)
	{

	}
	
}
