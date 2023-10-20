/********************************************************/
/* Author	: Taqi Eldeen								*/
/* Date		: 21/3/2023									*/
/* Version  : v01										*/
/********************************************************/
#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char           u8;
typedef unsigned short int      u16;
typedef unsigned long int       u32;
typedef unsigned long long int  u64;

typedef signed char             s8;
typedef signed short int        s16;
typedef signed long int         s32;
typedef signed long long int    s64;

typedef float   f32;
typedef double  f64;
/* All are 4 bytes anyway
typedef long double f128;
*/
#define ADDRESS_NULL ((void *)0x00)

typedef void (*ptr_func_t)(void);
typedef void (*ptr_func_Iu16_Ov)(u16);
typedef void (*ptr_func_Iu8_Ov)(u8);


#define TRUE 1
#define FALSE 0

typedef union
{
	struct
	{
		u8 Bit0 : 1;
		u8 Bit1 : 1;
		u8 Bit2 : 1;
		u8 Bit3 : 1;
		u8 Bit4 : 1;
		u8 Bit5 : 1;
		u8 Bit6 : 1;
		u8 Bit7 : 1;
	} BitAccess;
	u8 ByteAccess;
} Register;

#endif