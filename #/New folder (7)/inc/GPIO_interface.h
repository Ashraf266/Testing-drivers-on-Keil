/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 26/10/2023				*/
/****************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H




/*---------------------------------- Definitions ----------------------------------*/

/* ports */
#define GPIO_PORTA_NUM								(0u)
#define GPIO_PORTB_NUM								(1u)
#define GPIO_PORTC_NUM								(2u)

/* pins */
#define GPIO_PIN0									(0u)									
#define GPIO_PIN1                                   (1u)
#define GPIO_PIN2                                   (2u)
#define GPIO_PIN3                                   (3u)
#define GPIO_PIN4                                   (4u)
#define GPIO_PIN5                                   (5u)
#define GPIO_PIN6                                   (6u)
#define GPIO_PIN7                                   (7u)
#define GPIO_PIN8                                   (8u)
#define GPIO_PIN9                                   (9u)
#define GPIO_PIN10                                  (10u)
#define GPIO_PIN11                                  (11u)
#define GPIO_PIN12                                  (12u)
#define GPIO_PIN13                                  (13u)
#define GPIO_PIN14                                  (14u)
#define GPIO_PIN15                                  (15u) 



/* GPIO Modes */

#define GPIO_INPUT_ANALOG                           (0b0000u)
#define GPIO_INPUT_FLOATING                         (0b0100u)
#define GPIO_INPUT_INTERNAL_PULL_DOWN	            (0b1000u)
#define GPIO_INPUT_INTERNAL_PULL_UP	            	(0b1100u)

#define GPIO_INTERNAL_PULL_UP						(0u)
#define GPIO_INTERNAL_PULL_DOWN						(1u)

#define GPIO_OUTPUT_PUSH_PULL_10MHZ					(0b0001u)
#define GPIO_OUTPUT_OPEN_DRAIN_10MHZ                (0b0101u)
#define GPIO_ALTER_FUNC_OUTPUT_PUSH_PULL_10MHZ      (0b1001u)
#define GPIO_ALTER_FUNC_OUTPUT_OPEN_DRAIN_10MHZ     (0b1101u)

#define GPIO_OUTPUT_PUSH_PULL_2MHZ					(0b0010u)
#define GPIO_OUTPUT_OPEN_DRAIN_2MHZ                 (0b0110u)
#define GPIO_ALTER_FUNC_OUTPUT_PUSH_PULL_2MHZ       (0b1010u)
#define GPIO_ALTER_FUNC_OUTPUT_OPEN_DRAIN_2MHZ      (0b1110u)

#define GPIO_OUTPUT_PUSH_PULL_50MHZ					(0b0011u)
#define GPIO_OUTPUT_OPEN_DRAIN_50MHZ                (0b0111u)
#define GPIO_ALTER_FUNC_OUTPUT_PUSH_PULL_50MHZ      (0b1011u)
#define GPIO_ALTER_FUNC_OUTPUT_OPEN_DRAIN_50MHZ     (0b1111u)

#define GPIO_HIGH									(1u)
#define GPIO_LOW									(0u)


/*---------------------------- Function Declarations -------------------------*/
 
void GPIO_voidSetPinDirection(u8 copy_u8PORT, u16 copy_u16PIN, u8 copy_u8MODE);
void GPIO_voidSetPinValue(u8 copy_u8PORT, u16 copy_u16PIN, u8 copy_u8Value);
u8 GPIO_u8GetPinValue(u8 copy_u8PORT, u16 copy_u16PIN);

#endif /* GPIO_INTERFACE_H */
