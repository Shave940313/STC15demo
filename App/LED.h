#ifndef __LED_H__
#define __LED_H__

//RUN LED
#define   MCU_Run_LED			       P34
#define   MCU_Run_LED_ON 	       (bit)1
#define   MCU_Run_LED_OFF        (bit)0

//定义结构体类型
typedef struct
{
	void (*LED_ON)(void);     //打开
	void (*LED_OFF)(void);    //关闭
	void (*LED_Flip)(void);   //翻转
} LED_t;

/* extern variables-----------------------------------------------------------*/
extern LED_t  LED_Run;
/* extern function prototypes-------------------------------------------------*/

#endif
/********************************************************
  End Of File
********************************************************/