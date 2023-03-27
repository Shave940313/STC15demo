/* Includes ------------------------------------------------------------------*/
#include <main.h>

/* Private define-------------------------------------------------------------*/

/* Private variables----------------------------------------------------------*/
static void Run_LED_ON(void); 
static void Run_LED_OFF(void);
static void Run_LED_Flip(void);

/* Public variables-----------------------------------------------------------*/
LED_t LED_Run = 
{
	Run_LED_ON,
	Run_LED_OFF,
	Run_LED_Flip
};

/* Private function prototypes------------------------------------------------*/      

/*
	* @name   Run_LED_ON
	* @brief  关闭运行指示灯
	* @param  None
	* @retval None      
*/
static void Run_LED_ON()
{
	MCU_Run_LED = MCU_Run_LED_ON;
}

/*
	* @name   Run_LED_OFF
	* @brief  打开运行指示灯
	* @param  None
	* @retval None      
*/
static void Run_LED_OFF()
{
	MCU_Run_LED = MCU_Run_LED_OFF;
}

/*
	* @name   Run_LED_Flip
	* @brief  翻转充电指示灯
	* @param  None
	* @retval None      
*/
static void Run_LED_Flip()
{
	MCU_Run_LED = ~MCU_Run_LED;
}
/********************************************************
  End Of File
********************************************************/