/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 31/10/2023				*/
/****************************************/

#ifndef LEDMRX_CONFIG_H
#define LEDMRX_CONFIG_H



/* Enter ROW X COL */
#define LEDMRX_ROW_SIZE						(4u)
#define LEDMRX_COL_SIZE						(4u)


/* Enter PORT number & PIN offeset in the entered port */
#define LEDMRX_ROW_PORT_ID					GPIO_PORTA_NUM
#define LEDMRX_COL_PORT_ID					GPIO_PORTB_NUM

#define LEDMRX_ROW_FIRST_PIN				GPIO_PIN0
#define LEDMRX_COL_FIRST_PIN				GPIO_PIN5

/* The LED is ON when both ROWs & COLs are Active */
#define LEDMRX_ROW_ACTIVE					GPIO_HIGH
#define LEDMRX_ROW_NOT_ACTIVE				GPIO_LOW

#define LEDMRX_COL_ACTIVE					GPIO_LOW
#define LEDMRX_COL_NOT_ACTIVE				GPIO_HIGH

/* Enter Delay Value */
#define LEDMRX_DELAY_VALUE					3000


#endif  /* LEDMRX_CONFIG_H */