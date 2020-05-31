#ifndef STD_TYPES_H
#define STD_TYPES_H

	typedef unsigned char u8;
	typedef unsigned short u16;
	typedef unsigned long int u32;
	typedef signed char s8;
	typedef signed short s16;
	typedef signed long int s32;
	typedef float f32 ;
	typedef double f64 ;
	typedef long double f128 ;
	typedef u8*  pu8;
	typedef u16* pu16;
	typedef u32* pu32;
	typedef s8*  ps8;
	typedef s16* ps16;
	typedef s32* ps32;
	typedef f32* pf32;
	typedef f64* pf64;
	
	typedef u8 ErrorStatus;

	#define NULL ((void*)0)

	#define ERROR_OK 		0
	#define ERROR_NOK		1
	#define ERROR_TIMEOUT	2
	#define ERROR_BUSY		3



	#endif
