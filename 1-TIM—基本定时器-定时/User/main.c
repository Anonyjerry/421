
// 基本定时器TIMx,x[6,7]定时应用
#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_TiMbase.h"
#include "bsp_usart.h"


uint8_t Out_data_m=0;
uint16_t Out_data_s=0;

volatile uint32_t time = 0; // ms 计时变量 


/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main(void)
{

	
	/* led 端口配置 */ 
	LED_GPIO_Config();
	
	SSI_GPIO_Config();
	//USART_Config();
	BASIC_TIM_Init();
  while(1)
  {

#if 0
    if ( time == 1 ) /* 1000 * 1 ms = 1s 时间到 */
    { 
			time = 0;
		LED1_TOGGLE;
			
	//	Out_data=SSI_GET_data(16);
	//  printf("%d\n",Out_data);
	/* LED1 取反 */      
//	 SSI_TOGGLE;			
    }

#endif



  }
}
/*********************************************END OF FILE**********************/










