#ifndef __Sys_init_H__
#define __Sys_init_H__

//定义结构体类型
typedef struct
{
  void (*GPIO_Init)(void);           //通用输入输出端口初始化
	void (*IE_init)(void);             //中断初始化
  void (*Power_ON_Indication)(void); //上电指示
  void (*Sys_Init)(void);            //系统初始化
} Hardware_Init_t;

/* extern variables-----------------------------------------------------------*/
extern Hardware_Init_t Hardware_Init;

#endif
/********************************************************
  End Of File
********************************************************/