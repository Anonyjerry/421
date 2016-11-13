/**
  ******************************************************************************
  * @file    bsp_led.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   led应用函数接口
  ******************************************************************************
  * @attention
  *
  * 实验平台:秉火 F103-霸道 STM32 开发板 
	
	DCM.DLL
	-pCM3
	TCM.DLL
	-pCM3
  *
  ******************************************************************************
  */
  
#include "bsp_led.h"   

/*
设置编码器的IO

*/

void SSI_GPIO_Config(void)
{

//rename a GPIO_InitTypedefine structure

GPIO_InitTypeDef GPIO_InitStruct;
RCC_APB2PeriphClockCmd(SSI_GPIO_CLK,ENABLE);

GPIO_InitStruct.GPIO_Pin=SSI_GPIO_PIN;
GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;

GPIO_Init(SSI_GPIO_PORT,&GPIO_InitStruct);

GPIO_SetBits(SSI_GPIO_PORT,SSI_GPIO_PIN);

}

int SSI_GET_data(uint8_t n){
	uint8_t i;
	uint16_t Data_temp;
	uint32_t GET_data;
	
	LED1_OFF;
	__nop();
	__nop();

	for (i=n;i=0;i--)
	{
		LED1_ON;

		__nop();
		__nop();
		__nop();
		__nop();

		Data_temp=SSI_GPIO_PIN;
		GET_data<<=1;

		GET_data=GET_data|(Data_temp&&0x01);
		LED1_OFF;

		__nop();
		__nop();
		__nop();
		
	}
	LED1_ON;
	return GET_data;
	
}



 /**
  * @brief  初始化控制LED的IO
  * @param  无
  * @retval 无
  */
void LED_GPIO_Config(void)
{		
		/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*开启LED相关的GPIO外设时钟*/
		RCC_APB2PeriphClockCmd( LED1_GPIO_CLK | LED2_GPIO_CLK | LED3_GPIO_CLK, ENABLE);
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LED3_GPIO_PIN;	

		/*设置引脚模式为通用推挽输出*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;   

		/*设置引脚速率为50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*调用库函数，初始化GPIO*/
		GPIO_Init(LED3_GPIO_PORT, &GPIO_InitStructure);	

				/*设置引脚模式为通用推挽输出*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
		
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LED1_GPIO_PIN;

		/*调用库函数，初始化GPIO*/
		GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStructure);
		
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LED2_GPIO_PIN;

		/*调用库函数，初始化GPIOF*/
		GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStructure);

		/* 关闭所有led灯	*/
		GPIO_SetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
		
		/* 关闭所有led灯	*/
		GPIO_SetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);	 
    
    /* 关闭所有led灯	*/
		GPIO_SetBits(LED3_GPIO_PORT, LED3_GPIO_PIN);
}

/*********************************************END OF FILE**********************/
