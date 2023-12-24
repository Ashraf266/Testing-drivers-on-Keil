/********************************************************************
 * Module       : dio                                               *
 * File Name    : dio.h                                             *
 * Description  : contains definitions & interfaces for dio driver  *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/

#ifndef DIO_H
#define DIO_H

#include "dio_cfg.h"
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/******* PORT ID *******/
#define DIO_PORT_A_ID               (0u)
#define DIO_PORT_B_ID               (1u)
#define DIO_PORT_C_ID               (2u)

/******* PIN ID *******/
#define DIO_PIN_0_ID                (0u)
#define DIO_PIN_1_ID                (1u)
#define DIO_PIN_2_ID                (2u)
#define DIO_PIN_3_ID                (3u)
#define DIO_PIN_4_ID                (4u)
#define DIO_PIN_5_ID                (5u)
#define DIO_PIN_6_ID                (6u)
#define DIO_PIN_7_ID                (7u)
#define DIO_PIN_8_ID                (8u)
#define DIO_PIN_9_ID                (9u)
#define DIO_PIN_10_ID               (10u)
#define DIO_PIN_11_ID               (11u)
#define DIO_PIN_12_ID               (12u)
#define DIO_PIN_13_ID               (13u)
#define DIO_PIN_14_ID               (14u)
#define DIO_PIN_15_ID               (15u)

/******* PIN LEVELs *******/
#define DIO_PIN_LOW                 (0u)
#define DIO_PIN_HIGH                (1u)


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

/* Type for the definition of a pin group, which consists of several adjoining pins within a port. */
typedef struct
{
    u16 mask;
    u8  offset;
    u8  portID;
}DIO_pinGroupType;


/*******************************************************************************
 *                             Functions Prototypes                            *
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
void DIO_writePin(u8 portID, u8 pinID, u8 pinLevel);


/******************************************************************
[Function Name] : DIO_readPin                                     *
[Description]   : reads a value on a pin                          *
[Args]:         : u8 portID, u8 pinID                             *
[in]	        : port & pin numbers and pin Level                *
[out]	        : Pin Level                                       *
[in/out]        : NOTHING                                         *
[Returns]       : u8                                              *
*******************************************************************/
u8 DIO_readPin(u8 portID, u8 pinID);


/******************************************************************
[Function Name] : DIO_writePinGroup                               *
[Description]   : Writes a value on a pin group                   *
[Args]:         : DIO_pinGroupType *pinGroupPtr, u16 pinGroupLevel*
[in]	        : pin group & its level                           *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void DIO_writePinGroup(DIO_pinGroupType *pinGroupPtr, u16 pinGroupLevel);


/******************************************************************
[Function Name] : DIO_readPinGroup                                *
[Description]   : reads a value on a pin group                    *
[Args]:         : DIO_pinGroupType *pinGroupPtr                   *
[in]	        : pin group & its level                           *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : pin group levels                                *
*******************************************************************/
u16 DIO_readPinGroup(DIO_pinGroupType *pinGroupPtr);


#endif /* DIO_H */
