#ifndef __Timer0_H__
#define __Timer0_H__

//����ö������
typedef enum
{
	TIMER0_50mS  	= (uint16_t)10,
	TIMER0_100mS	= (uint16_t)20,
	TIMER0_500mS	= (uint16_t)100,
	TIMER0_1S     = (uint16_t)200,
}TIMER0_Value_t;

//����ṹ������
typedef struct
{
  uint16_t volatile usMCU_Run_Timer;  //ϵͳ���ж�ʱ��
	void (*Timer0_Init)(void);          //��ʱ��0��ʼ��
} Timer0_t;

/* extern variables-----------------------------------------------------------*/
extern Timer0_t  Timer0;

#endif
/********************************************************
  End Of File
********************************************************/