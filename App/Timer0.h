#ifndef __Timer0_H__
#define __Timer0_H__

//定义枚举类型
typedef enum
{
	TIMER0_50mS  	= (uint16_t)10,
	TIMER0_100mS	= (uint16_t)20,
	TIMER0_500mS	= (uint16_t)100,
	TIMER0_1S     = (uint16_t)200,
}TIMER0_Value_t;

//定义结构体类型
typedef struct
{
  uint16_t volatile usMCU_Run_Timer;  //系统运行定时器
	void (*Timer0_Init)(void);          //定时器0初始化
} Timer0_t;

/* extern variables-----------------------------------------------------------*/
extern Timer0_t  Timer0;

#endif
/********************************************************
  End Of File
********************************************************/