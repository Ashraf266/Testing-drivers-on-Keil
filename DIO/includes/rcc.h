/********************************************************************
 * Module       : rcc                                               *
 * File Name    : rcc.h                                             *
 * Description  : contains definitions & interfaces for rcc driver  *
 * Author       : Mohamed Ashraf                                    *
 *******************************************************************/

#ifndef RCC_H
#define RCC_H

#include "rcc_cfg.h"
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/******* RCC BUS IDs *******/
#define RCC_AHB                             (0u)
#define RCC_APB1                            (1u)
#define RCC_APB2                            (2u)

/******* AHB peripherals *******/
#define RCC_AHB_DMA1                        (0u)
#define RCC_AHB_DMA2                        (1u)
#define RCC_AHB_SRAM                        (2u)
#define RCC_AHB_FLITF                       (4u)
#define RCC_AHB_CRC                         (6u)
#define RCC_AHB_FSMC                        (8u)
#define RCC_AHB_SDIO                        (10u)

/******* APB1 peripherals *******/
#define RCC_APB1_TIM2                        (0u)
#define RCC_APB1_TIM3                        (1u)
#define RCC_APB1_TIM4                        (2u)
#define RCC_APB1_TIM5                        (3u)
#define RCC_APB1_TIM6                        (4u)
#define RCC_APB1_TIM7                        (5u)
#define RCC_APB1_TIM12                       (6u)
#define RCC_APB1_TIM13                       (7u)
#define RCC_APB1_TIM14                       (8u)
#define RCC_APB1_WWDG                        (11u)
#define RCC_APB1_SPI2                        (14u)
#define RCC_APB1_SPI3                        (15u)
#define RCC_APB1_USART2                      (17u)
#define RCC_APB1_USART3                      (18u)
#define RCC_APB1_UART4                       (19u)
#define RCC_APB1_UART5                       (20u)
#define RCC_APB1_I2C1                        (21u)
#define RCC_APB1_I2C2                        (22u)
#define RCC_APB1_USB                         (23u)
#define RCC_APB1_CAN                         (25u)
#define RCC_APB1_BKP                         (27u)
#define RCC_APB1_PWR                         (28u)
#define RCC_APB1_DAC                         (29u)

/******* APB2 peripherals *******/
#define RCC_APB2_AFIO                        (0u)
#define RCC_APB2_PORT_A                      (2u)
#define RCC_APB2_PORT_B                      (3u)
#define RCC_APB2_PORT_C                      (4u)
#define RCC_APB2_ADC1                        (9u)
#define RCC_APB2_ADC2                        (10u)
#define RCC_APB2_TIM1                        (11u)
#define RCC_APB2_SPI1                        (12u)
#define RCC_APB2_TIM8                        (13u)
#define RCC_APB2_USART1                      (14u)
#define RCC_APB2_ADC3                        (15u)
#define RCC_APB2_TIM9                        (19u)
#define RCC_APB2_TIM10                       (20u)
#define RCC_APB2_TIM11                       (21u)

/*******************************************************************************
 *                             Functions Prototypes                            *
 *******************************************************************************/

/******************************************************************
[Function Name] : RCC_init                                        *
[Description]   : Initializes the Clock based on static cfg       *
[Args]:         : void                                            *
[in]	        : NOTHING                                         *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void RCC_init(void);


/******************************************************************
[Function Name] : RCC_init                                        *
[Description]   : Enables Clock for specific Peripheral           *
[Args]:         : u8 BusID  &  u8 PerID                           *
[in]	        : NOTHING                                         *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void RCC_EnableClock(u8 BusID, u8 PerID);


/******************************************************************
[Function Name] : RCC_init                                        *
[Description]   : Disable Clock for specific Peripheral           *
[Args]:         : u8 BusID  &  u8 PerID                           *
[in]	        : NOTHING                                         *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void RCC_DisableClock(u8 BusID, u8 PerID);



#endif /* RCC_H */
