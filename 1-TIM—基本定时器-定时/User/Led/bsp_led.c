/**
  ******************************************************************************
  * @file    bsp_led.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   ledӦ�ú����ӿ�
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:���� F103-�Ե� STM32 ������ 
	
	DCM.DLL
	-pCM3
	TCM.DLL
	-pCM3
  *
  ******************************************************************************
  */
  
#include "bsp_led.h"   

/*
���ñ�������IO

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
  * @brief  ��ʼ������LED��IO
  * @param  ��
  * @retval ��
  */
void LED_GPIO_Config(void)
{		
		/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*����LED��ص�GPIO����ʱ��*/
		RCC_APB2PeriphClockCmd( LED1_GPIO_CLK | LED2_GPIO_CLK | LED3_GPIO_CLK, ENABLE);
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LED3_GPIO_PIN;	

		/*��������ģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;   

		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(LED3_GPIO_PORT, &GPIO_InitStructure);	

				/*��������ģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
		
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LED1_GPIO_PIN;

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStructure);
		
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LED2_GPIO_PIN;

		/*���ÿ⺯������ʼ��GPIOF*/
		GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStructure);

		/* �ر�����led��	*/
		GPIO_SetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
		
		/* �ر�����led��	*/
		GPIO_SetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);	 
    
    /* �ر�����led��	*/
		GPIO_SetBits(LED3_GPIO_PORT, LED3_GPIO_PIN);
}

/*********************************************END OF FILE**********************/
