/* Includes ------------------------------------------------------------------*/
#include <main.h>

/* Private define-------------------------------------------------------------*/

/* Private variables----------------------------------------------------------*/
static void GPIO_Init(void);           //通用输入输出端口初始化
static void IE_init(void);             //中断初始化
static void Power_ON_Indication(void); //上电指示
static void Sys_Init(void);            //系统初始化

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
	* @brief  通用输入输出端口初始化
	* @param  None
	* @retval None      
*/
static void GPIO_Init()
{
	//M1  M0
		//0   0	     准双向口
		//0   1	     推挽输出
		//1   0	     高阻输入
		//1   1	     开漏
	
	//P3 -> P34,P35设置为推挽输出  
	P3M1 = 0x00; //0000 0000
	P3M0 = 0x30; //0011 0000

	P34  = 0;  //关闭运行指示灯
	P35  = 0;  //关闭PWM指示灯
}

/*
	* @name   IE_init
	* @brief  中断初始化
	* @param  None
	* @retval None      
*/
static void IE_init()
{	
	ET0 =  1;             //打开定时器0中断
	
	EA  =  1;       			//打开总中断
}

/*
	* @name   Power_ON_Indication
	* @brief  上电指示
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
	* @brief  系统初始化
	* @param  None
	* @retval None      
*/
static void Sys_Init()
{	
	Public.Delay_ms(50);                //上电延时50ms
	Hardware_Init.GPIO_Init();          //GPIO口初始化
	Hardware_Init.Power_ON_Indication();//上电指示
	Timer0.Timer0_Init();               //定时器0初始化
	Hardware_Init.IE_init();            //中断初始化
}
/********************************************************
  End Of File
********************************************************/