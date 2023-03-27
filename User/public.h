#ifndef __PUBLIC_H_
#define __PUBLIC_H_

//数据类型重定义
typedef	signed   char      sint8_t;
typedef signed   short int sint16_t;
typedef signed   long  int sint32_t;

typedef unsigned char      uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned long  int uint32_t;

//定义结构体类型
typedef struct
{
	void (*Delay_ms)(uint16_t);            //ms延时函数
} Public_t;

/* extern variables-----------------------------------------------------------*/
extern Public_t  Public;
#endif
/********************************************************
  End Of File
********************************************************/