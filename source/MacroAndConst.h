/*
* Copyright (c) 2016,
* All rights reserved.
*
* 文件名称： MacroAndConst.h
* 文件标识： 见配置管理计划书
* 摘 要： 宏定义和常量定义，所有C源文件都需要包含
*
* 当前版本： 1.0
* 作 者： vivi
* 完成日期： 2016年4月13日
* *
*/

#ifndef _MACRO_AND_CONST_H_
#define _MACRO_AND_CONST_H_
/***************************
数据类型typedef
****************************/

typedef unsigned int uint16;
typedef unsigned int UINT;
typedef unsigned int uint;
typedef unsigned int UINT16;
typedef unsigned int WORD;
typedef unsigned int word;
typedef int* pint16;
typedef int int16;
typedef int INT16;
typedef unsigned long uint32;
typedef unsigned long UINT32;
typedef unsigned long DWORD;
typedef unsigned long dword;
typedef long int32;
typedef long INT32;
typedef signed char int8;
typedef signed char INT8;
typedef unsigned char byte;
typedef unsigned char BYTE;
typedef unsigned char uchar;
typedef unsigned char UINT8;
typedef unsigned char uint8;

typedef unsigned char BOOL;

/***************************
数据常量define
****************************/
#ifndef TRUE
#define FALSE 0
#define TRUE (!FALSE)
#endif



#endif