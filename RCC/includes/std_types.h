/********************************************************
 * Module       : Common - Platform Types Abstraction   *
 * File Name    : std_types.h                           *
 * Description  : standard types frequently used        *
 * Author       : Mohamed Ashraf                        *
 *******************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

/*Boolean Data Type*/
typedef unsigned char boolean;

/*Boolean Values*/

#ifndef TRUE
#define TRUE 				(1u)
#endif
#ifndef FALSE
#define FALSE 				(0u)
#endif

#define LOGIC_HIGH  		(1u)
#define LOGIC_LOW  			(0u)

/*NULL*/
#define NULL_PTR 			((void*)0)


typedef unsigned char            u8;
typedef signed char              s8;
typedef unsigned short           u16;
typedef signed short             s16;
typedef unsigned long            u32;
typedef signed long              s32;
typedef unsigned long long       u64;
typedef signed long long         s64;
typedef float                    float32;
typedef double                   float64;


#endif /* STD_TYPES_H */
