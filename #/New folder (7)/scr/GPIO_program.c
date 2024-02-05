/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 26/10/2023				*/
/****************************************/


/*---------------------------------- Includes ----------------------------------*/

#include "std_types.h"
#include "bit_math.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"

/*---------------------------- Function Definitions -------------------------*/
void GPIO_voidSetPinDirection(u8 copy_u8PORT, u16 copy_u16PIN, u8 copy_u8MODE)
{
	
	switch(copy_u8PORT)
	{
		/* remember next time to make the ports as an array not to repeat each ports code */
		case GPIO_PORTA_NUM:
						if(copy_u16PIN < 8)
						{
							GPIO_PORTA->CRL &= ~(((0xF) << (4 * copy_u16PIN)));
							if( (copy_u8MODE != GPIO_INPUT_INTERNAL_PULL_UP) &&  (copy_u8MODE != GPIO_INPUT_INTERNAL_PULL_DOWN) )
							{
								GPIO_PORTA->CRL |= (copy_u8MODE << (4 * copy_u16PIN));
							}
							else
							{
								if(	copy_u8MODE == GPIO_INPUT_INTERNAL_PULL_DOWN )
								{
									GPIO_PORTA->CRL |= (0b1000 << (4 * copy_u16PIN));
									CLR_BIT(GPIO_PORTA->ODR, copy_u16PIN);
								}
								else
								{
									GPIO_PORTA->CRL |= (0b1000 << (4 * copy_u16PIN));
									SET_BIT(GPIO_PORTA->ODR, copy_u16PIN);
								}
							}
						}
						else if(copy_u16PIN >= 8)
						{
							GPIO_PORTA->CRH &= ~((0xF) << (4 * (copy_u16PIN-8)));
							if( (copy_u8MODE != GPIO_INPUT_INTERNAL_PULL_UP) &&  (copy_u8MODE != GPIO_INPUT_INTERNAL_PULL_DOWN) )
							{
								GPIO_PORTA->CRH |= (copy_u8MODE << (4 * (copy_u16PIN-8)));
							}
							else
							{
								if(	copy_u8MODE == GPIO_INPUT_INTERNAL_PULL_DOWN )
								{
									GPIO_PORTA->CRH |= (0b1000 << (4 * (copy_u16PIN-8)));
									CLR_BIT(GPIO_PORTA->ODR, copy_u16PIN);
								}
								else
								{
									GPIO_PORTA->CRH |= (0b1000 << (4 * (copy_u16PIN-8)));
									SET_BIT(GPIO_PORTA->ODR, copy_u16PIN);
								}
							}
						}
						else
						{
							return;
						}
						
						break;
		
		case GPIO_PORTB_NUM:
		
						if(copy_u16PIN < 8)
						{
							GPIO_PORTB->CRL &= ~(((0xF) << (4 * copy_u16PIN)));
							if( (copy_u8MODE != GPIO_INPUT_INTERNAL_PULL_UP) &&  (copy_u8MODE != GPIO_INPUT_INTERNAL_PULL_DOWN) )
							{
								GPIO_PORTB->CRL |= (copy_u8MODE << (4 * copy_u16PIN));
							}
							else
							{
								if(	copy_u8MODE == GPIO_INPUT_INTERNAL_PULL_DOWN )
								{
									GPIO_PORTB->CRL |= (0b1000 << (4 * copy_u16PIN));
									CLR_BIT(GPIO_PORTB->ODR, copy_u16PIN);
								}
								else
								{
									GPIO_PORTB->CRL |= (0b1000 << (4 * copy_u16PIN));
									SET_BIT(GPIO_PORTB->ODR, copy_u16PIN);
								}
							}
						}
						else if(copy_u16PIN >= 8)
						{
							GPIO_PORTB->CRH &= ~((0xF) << (4 * (copy_u16PIN-8)));
							if( (copy_u8MODE != GPIO_INPUT_INTERNAL_PULL_UP) &&  (copy_u8MODE != GPIO_INPUT_INTERNAL_PULL_DOWN) )
							{
								GPIO_PORTB->CRH |= (copy_u8MODE << (4 * (copy_u16PIN-8)));
							}
							else
							{
								if(	copy_u8MODE == GPIO_INPUT_INTERNAL_PULL_DOWN )
								{
									GPIO_PORTB->CRH |= (0b1000 << (4 * (copy_u16PIN-8)));
									CLR_BIT(GPIO_PORTB->ODR, copy_u16PIN);
								}
								else
								{
									GPIO_PORTB->CRH |= (0b1000 << (4 * (copy_u16PIN-8)));
									SET_BIT(GPIO_PORTB->ODR, copy_u16PIN);
								}
							}
						}
						else
						{
							return;
						}
						
						break;
						
		case GPIO_PORTC_NUM:
		
						if(copy_u16PIN < 3)
						{
							GPIO_PORTC->CRL &= ~(((0xF) << (4 * copy_u16PIN)));
							if( (copy_u8MODE != GPIO_INPUT_INTERNAL_PULL_UP) &&  (copy_u8MODE != GPIO_INPUT_INTERNAL_PULL_DOWN) )
							{
								GPIO_PORTC->CRL |= (copy_u8MODE << (4 * copy_u16PIN));
							}
							else
							{
								if(	copy_u8MODE == GPIO_INPUT_INTERNAL_PULL_DOWN )
								{
									GPIO_PORTC->CRL |= (0b1000 << (4 * copy_u16PIN));
									CLR_BIT(GPIO_PORTC->ODR, copy_u16PIN);
								}
								else
								{
									GPIO_PORTC->CRL |= (0b1000 << (4 * copy_u16PIN));
									SET_BIT(GPIO_PORTC->ODR, copy_u16PIN);
								}
							}
						}
						else
						{
							return;
						}
						
						break;
						
		default:
						return;
	}
	
	
	
}


void GPIO_voidSetPinValue(u8 copy_u8PORT, u16 copy_u16PIN, u8 copy_u8Value)
{
	
	switch(copy_u8PORT)
	{
		case GPIO_PORTA_NUM:
						if(copy_u8Value == GPIO_HIGH)
						{
							SET_BIT(GPIO_PORTA->ODR, copy_u16PIN);
						}
						else
						{
							CLR_BIT(GPIO_PORTA->ODR, copy_u16PIN);
						}
						
						break;
		
		case GPIO_PORTB_NUM:
						if(copy_u8Value == GPIO_HIGH)
						{
							SET_BIT(GPIO_PORTB->ODR, copy_u16PIN);
						}
						else
						{
							CLR_BIT(GPIO_PORTB->ODR, copy_u16PIN);
						}

						
						break;
						
		case GPIO_PORTC_NUM:
						if(copy_u8Value == GPIO_HIGH)
						{
							SET_BIT(GPIO_PORTC->ODR, copy_u16PIN);
						}
						else
						{
							CLR_BIT(GPIO_PORTC->ODR, copy_u16PIN);
						}
						
						break;
						
		default:
						return;
	}
		
}

u8 GPIO_u8GetPinValue(u8 copy_u8PORT, u16 copy_u16PIN)
{
	
	u8 pinValue = 0;
	
	switch(copy_u8PORT)
	{
		case GPIO_PORTA_NUM:
						
						pinValue = GET_BIT(GPIO_PORTA->IDR, copy_u16PIN);
						break;
		
		case GPIO_PORTB_NUM:

						pinValue = GET_BIT(GPIO_PORTB->IDR, copy_u16PIN);
						break;
						
		case GPIO_PORTC_NUM:

						pinValue = GET_BIT(GPIO_PORTC->IDR, copy_u16PIN);
						break;
						
		default:
						return;
	}
	
	
	return pinValue;
}