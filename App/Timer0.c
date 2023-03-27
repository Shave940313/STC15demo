/* Includes ------------------------------------------------------------------*/
#include <main.h>

/* Private define-------------------------------------------------------------*/

/* Private variables----------------------------------------------------------*/

/* Private function prototypes------------------------------------------------*/      
static void Timer0_Init(void);//��ʱ��0��ʼ��

/* Public variables-----------------------------------------------------------*/
Timer0_t  Timer0 = 
{
	0,
	Timer0_Init
};


/*
	* @name   Timer0_Init
	* @brief  ��ʱ��0��ʼ��
	* @param  None
	* @retval None      
*/
static void Timer0_Init() //5����@11.0592MHz
{
	AUXR &= 0x7F;	//��ʱ��ʱ��12Tģʽ
	TMOD &= 0xF0;	//���ö�ʱ��ģʽ
	TL0 = 0x00;		//���ö�ʱ��ֵ
	TH0 = 0xEE;		//���ö�ʱ��ֵ
	TF0 = 0;		  //���TF0��־
	TR0 = 1;		  //��ʱ��0��ʼ��ʱ
}

/*
	* @name   Timer0_isr()
	* @brief  ��ʱ��0�жϺ���(5ms�ж�һ��)
	* @param  None
	* @retval None      
*/
/***********��ʱ��0�жϺ���***********/
void Timer0_isr() interrupt 1
{  
	if(++Timer0.usMCU_Run_Timer >= TIMER0_100mS)
	{
		Timer0.usMCU_Run_Timer = 0;
		LED_Run.LED_Flip();
	}
}
/********************************************************
  End Of File
********************************************************/