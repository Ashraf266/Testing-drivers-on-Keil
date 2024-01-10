/********************************************************************
 * Module       : nvic                                              *
 * File Name    : nvic.h                                            *
 * Description  : contains definitions & interfaces for nvic driver *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/

#ifndef NVIC_H
#define NVIC_H

#include "nvic_cfg.h"
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/******* Interrupts IDs *******/

#define NVIC_EXTI0                          (6u)
#define NVIC_EXTI1                          (7u)
#define NVIC_EXTI2                          (8u)
#define NVIC_EXTI3                          (9u)
#define NVIC_EXTI4                          (10u)
#define NVIC_EXTI9_5                        (23u)
#define NVIC_EXTI15_10                      (40u)

#define NVIC_DMA1_Channel1                  (11u)
#define NVIC_DMA1_Channel2                  (12u)
#define NVIC_DMA1_Channel3                  (13u)
#define NVIC_DMA1_Channel4                  (14u)
#define NVIC_DMA1_Channel5                  (15u)
#define NVIC_DMA1_Channel6                  (16u)
#define NVIC_DMA1_Channel7                  (17u)

#define NVIC_SPI1                           (35u)
#define NVIC_SPI2                           (36u)
#define NVIC_SPI3                           (51u)

#define NVIC_USART1                         (37u)
#define NVIC_USART2                         (38u)
#define NVIC_USART3                         (39u)



/*******************************************************************************
 *                             Functions Prototypes                            *
 *******************************************************************************/

/******************************************************************
[Function Name] : NVIC_globalInterruptEnable                      *
[Description]   : Sets Global interrupt bit                       *
[Args]:         : void                                            *
[in]	        : NOTHING                                         *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void NVIC_globalInterruptEnable(void);


/******************************************************************
[Function Name] : NVIC_globalInterruptDisable                     *
[Description]   : Disables All interrupts                         *
[Args]:         : void                                            *
[in]	        : NOTHING                                         *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void NVIC_globalInterruptDisable(void);


/******************************************************************
[Function Name] : NVIC_hardFaultEnable                            *
[Description]   : Enables Hard Faults                             *
[Args]:         : void                                            *
[in]	        : NOTHING                                         *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void NVIC_hardFaultEnable(void);


/******************************************************************
[Function Name] : NVIC_hardFaultDisable                           *
[Description]   : Disables Hard Faults                            *
[Args]:         : void                                            *
[in]	        : NOTHING                                         *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void NVIC_hardFaultDisable(void);


/******************************************************************
[Function Name] : NVIC_enableInterrupt                            *
[Description]   : Enables a peripheral's interrupt                *
[Args]:         : u8 interruptID                                  *
[in]	        : interrupt ID from the interrupt table           *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void NVIC_enableInterrupt(u8 interruptID);


/******************************************************************
[Function Name] : NVIC_disableInterrupt                           *
[Description]   : Disables a peripheral's interrupt               *
[Args]:         : u8 interruptID                                  *
[in]	        : interrupt ID from the interrupt table           *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void NVIC_disableInterrupt(u8 interruptID);


/******************************************************************
[Function Name] : NVIC_setPendingFlag                             *
[Description]   : Triggers a peripheral interrupt                 *
[Args]:         : u8 interruptID                                  *
[in]	        : interrupt ID from the interrupt table           *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void NVIC_setPendingFlag(u8 interruptID);


/******************************************************************
[Function Name] : NVIC_clearPendingFlag                           *
[Description]   : Clears the interrupt flag                       *
[Args]:         : u8 interruptID                                  *
[in]	        : interrupt ID from the interrupt table           *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void NVIC_clearPendingFlag(u8 interruptID);


/******************************************************************
[Function Name] : NVIC_getActiveFlag                           *
[Description]   : returns the interrupt flag status               *
[Args]:         : u8 interruptID                                  *
[in]	        : interrupt ID from the interrupt table           *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : u8                                              *
*******************************************************************/
u8	 NVIC_getActiveFlag(u8 interruptID);


/******************************************************************
[Function Name] : NVIC_setPrioriy                                 *
[Description]   : returns the interrupt flag status               *
[Args]:         : u8 interruptID, u8 groupPriority, u8 subPrioriy *
[in]	        : interrupt ID from the interrupt table           *
|                 interrupt group priority                        *
|                 interrupt subGroup priority                     *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : u8                                              *
*******************************************************************/
void NVIC_setPrioriy(u8 interruptID, u8 groupPriority, u8 subPrioriy);



#endif /* NVIC_H */
