/********************************************************************
 * Module       : dio                                               *
 * File Name    : dio.c                                             *
 * Description  : dio Implementation                                *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/

#include "bit_math.h"
#include "dio.h"
#include "dio_private.h"


/*******************************************************************************
 *                             Functions Definition                            *
 *******************************************************************************/


/******************************************************************
[Function Name] : DIO_writePin                                    *
[Description]   : Writes a value on a pin                         *
[Args]:         : u8 portID, u8 pinID, u8 pinLevel                *
[in]	        : port & pin numbers and pin Level                *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void DIO_writePin(u8 portID, u8 pinID, u8 pinLevel)
{
    if(DIO_PIN_HIGH == pinLevel)
    {
        DIO[portID]->BSRR = (1<<pinID);
    }
    else
    {
        DIO[portID]->BSRR = (1<<(pinID+16));
    }
}


/******************************************************************
[Function Name] : DIO_readPin                                     *
[Description]   : reads a value on a pin                          *
[Args]:         : u8 portID, u8 pinID                             *
[in]	        : port & pin numbers and pin Level                *
[out]	        : Pin Level                                       *
[in/out]        : NOTHING                                         *
[Returns]       : u8                                              *
*******************************************************************/
u8 DIO_readPin(u8 portID, u8 pinID)
{
    return GET_BIT(DIO[portID]->IDR, pinID);
}


/******************************************************************
[Function Name] : DIO_writePinGroup                               *
[Description]   : Writes a value on a pin group                   *
[Args]:         : DIO_pinGroupType *pinGroupPtr, u16 pinGroupLevel*
[in]	        : pin group & its level                           *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void DIO_writePinGroup(DIO_pinGroupType *pinGroupPtr, u16 pinGroupLevel)
{
    DIO[pinGroupPtr->portID]->ODR &= ~(pinGroupPtr->mask << pinGroupPtr->offset);
    DIO[pinGroupPtr->portID]->ODR |= (pinGroupLevel << pinGroupPtr->offset);
}


/******************************************************************
[Function Name] : DIO_readPinGroup                                *
[Description]   : reads a value on a pin group                    *
[Args]:         : DIO_pinGroupType *pinGroupPtr                   *
[in]	        : pin group & its level                           *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : pin group levels                                *
*******************************************************************/
u16 DIO_readPinGroup(DIO_pinGroupType *pinGroupPtr)
{
    u16 pinsValue = ((DIO[pinGroupPtr->portID]->IDR & (pinGroupPtr->mask << pinGroupPtr->offset)) >> pinGroupPtr->offset);
    return pinsValue;
}



