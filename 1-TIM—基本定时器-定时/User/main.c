
// ������ʱ��TIMx,x[6,7]��ʱӦ��
#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_TiMbase.h"
#include "bsp_usart.h"


uint8_t Out_data_m=0;
uint16_t Out_data_s=0;

volatile uint32_t time = 0; // ms ��ʱ���� 


/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
int main(void)
{

	
	/* led �˿����� */ 
	LED_GPIO_Config();
	
	SSI_GPIO_Config();
	//USART_Config();
	BASIC_TIM_Init();
  while(1)
  {

#if 0
    if ( time == 1 ) /* 1000 * 1 ms = 1s ʱ�䵽 */
    { 
			time = 0;
		LED1_TOGGLE;
			
	//	Out_data=SSI_GET_data(16);
	//  printf("%d\n",Out_data);
	/* LED1 ȡ�� */      
//	 SSI_TOGGLE;			
    }

#endif



  }
}
/*********************************************END OF FILE**********************/










