/********************************************************************
 * Module       : nvic                                              *
 * File Name    : nvic_private.h                                    *
 * Description  : contains private definitions & types              *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H


#define NVIC_BASE_ADDRESS					(0xE000E100)
#define SCB_BASE_ADDRESS					(0xE000ED00)

/* we only have 59 external interrupt */
#define NVIC_ISER0							(*(volatile u32 *) (NVIC_BASE_ADDRESS + 0x000))
#define NVIC_ISER1							(*(volatile u32 *) (NVIC_BASE_ADDRESS + 0x004))

#define NVIC_ICER0							(*(volatile u32 *) (NVIC_BASE_ADDRESS + 0x080))
#define NVIC_ICER1							(*(volatile u32 *) (NVIC_BASE_ADDRESS + 0x084))

#define NVIC_ISPR0							(*(volatile u32 *) (NVIC_BASE_ADDRESS + 0x100))
#define NVIC_ISPR1							(*(volatile u32 *) (NVIC_BASE_ADDRESS + 0x104))

#define NVIC_ICPR0							(*(volatile u32 *) (NVIC_BASE_ADDRESS + 0x180))
#define NVIC_ICPR1							(*(volatile u32 *) (NVIC_BASE_ADDRESS + 0x184))

#define NVIC_IABR0							(*(volatile const u32 *) (NVIC_BASE_ADDRESS + 0x200))
#define NVIC_IABR1							(*(volatile const u32 *) (NVIC_BASE_ADDRESS + 0x204))

#define NVIC_IPR							((volatile u8 *) (NVIC_BASE_ADDRESS + 0x300))

#define SCB_AIRCR							(*(volatile u32 *) (SCB_BASE_ADDRESS + 0x0C))


#define NVIC_4G0S			0
#define NVIC_3G1S			1
#define NVIC_2G2S			2
#define NVIC_1G3S			3
#define NVIC_0G4S			4


/* Macros for assembly */

#define GlobalInterruptEnableMacro() 			__asm("CPSIE I")
#define GlobalInterruptDisableMacro() 			__asm("CPSID I")

#define FaultsEnableMacro() 					__asm("CPSIE F")
#define FaultsDisableMacro() 					__asm("CPSID F")


#endif  /* NVIC_PRIVATE_H */
