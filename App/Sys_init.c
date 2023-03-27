/* Includes ------------------------------------------------------------------*/
#include <main.h>

/* Private define-------------------------------------------------------------*/

/* Private variables----------------------------------------------------------*/
static void GPIO_Init(void);           //ͨ����������˿ڳ�ʼ��
static void IE_init(void);             //�жϳ�ʼ��
static void Power_ON_Indication(void); //�ϵ�ָʾ
static void Sys_Init(void);            //ϵͳ��ʼ��

/* Public variables-----------------------------------------------------------*/
Hardware_Init_t Hardware_Init = 
{
	GPIO_Init,
	IE_init,
	Power_ON_Indication,
	Sys_Init
};

/* Private function prototypes------------------------------------------------*/      

/*
	* @name   GPIO_Init
	* @brief  ͨ����������˿ڳ�ʼ��
	* @param  None
	* @retval None      
*/
static void GPIO_Init()
{
	//M1  M0
		//0   0	     ׼˫���
		//0   1	     �������
		//1   0	     ��������
		//1   1	     ��©
	
	//P3 -> P34,P35����Ϊ�������  
	P3M1 = 0x00; //0000 0000
	P3M0 = 0x30; //0011 0000

	P34  = 0;  //�ر�����ָʾ��
	P35  = 0;  //�ر�PWMָʾ��
}

/*
	* @name   IE_init
	* @brief  �жϳ�ʼ��
	* @param  None
	* @retval None      
*/
static void IE_init()
{	
	ET0 =  1;             //�򿪶�ʱ��0�ж�
	
	EA  =  1;       			//�����ж�
}

/*
	* @name   Power_ON_Indication
	* @brief  �ϵ�ָʾ
	* @param  None
	* @retval None      
*/
static void Power_ON_Indication()
{
	uint8_t i = 5;

	while(i--)
	{
		LED_Run.LED_ON();
		Public.Delay_ms(100);
		LED_Run.LED_OFF();
		Public.Delay_ms(100);
	}
}

/*
	* @name   Sys_Init
	* @brief  ϵͳ��ʼ��
	* @param  None
	* @retval None      
*/
static void Sys_Init()
{	
	Public.Delay_ms(50);                //�ϵ���ʱ50ms
	Hardware_Init.GPIO_Init();          //GPIO�ڳ�ʼ��
	Hardware_Init.Power_ON_Indication();//�ϵ�ָʾ
	Timer0.Timer0_Init();               //��ʱ��0��ʼ��
	Hardware_Init.IE_init();            //�жϳ�ʼ��
}
/********************************************************
  End Of File
********************************************************/