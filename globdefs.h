#ifndef _GLOBDEFS_H
#define _GLOBDEFS_H

//#include <stm32l4xx.h>
#include <inttypes.h>
#include <stdbool.h>
#include <math.h>

/* Для IAR use of address of unaligned structure member */
/* #pragma diag_suppress=Pa039 */

typedef float f32;		/* long double не поддержываеца  */


typedef uint64_t u64;
typedef int64_t s64;

typedef int32_t s32;
typedef uint32_t u32;

typedef signed short s16;
typedef uint16_t u16;

typedef char c8;
typedef unsigned char u8;
typedef signed char s8;

/* Время UNIX */
typedef int64_t  unix_time_t;
typedef s32      rtc_time_t;


typedef uint64_t  u64;



#define		ROUND(x)   	(int)((x) + .5f)
#define		ABS(x)     	(((x) < 0)? (-x) : (x))
#define 	FINITE(x)	(isfinite(x)?  (x) : 0)
#define		IS_APROX(x)	((ABS((x) - SystemCoreClock) < 100)?   (x) : 0) 



#define		TIMER_NS_DIVIDER	(1000000000UL)
#define		TIMER_US_DIVIDER	(1000000)
#define		TIMER_MS_DIVIDER	(1000)



/* Переопределения malloc и free */
#define		malloc(x)	pvPortMalloc(x)
#define		free(x)	        vPortFree(x)


#endif /* globdefs.h */
