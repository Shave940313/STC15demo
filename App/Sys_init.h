#ifndef __Sys_init_H__
#define __Sys_init_H__

//����ṹ������
typedef struct
{
  void (*GPIO_Init)(void);           //ͨ����������˿ڳ�ʼ��
	void (*IE_init)(void);             //�жϳ�ʼ��
  void (*Power_ON_Indication)(void); //�ϵ�ָʾ
  void (*Sys_Init)(void);            //ϵͳ��ʼ��
} Hardware_Init_t;

/* extern variables-----------------------------------------------------------*/
extern Hardware_Init_t Hardware_Init;

#endif
/********************************************************
  End Of File
********************************************************/