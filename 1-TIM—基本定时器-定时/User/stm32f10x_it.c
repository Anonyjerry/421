/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTI
  
  AL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"
#include "bsp_TiMbase.h"
#include "bsp_led.h"
#include "bsp_usart.h"
#include "stm32f10x_gpio.h"



extern volatile uint32_t time;
extern volatile uint8_t Out_data_m;
extern volatile uint16_t Out_data_s;

/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles TIM2 interrupt request.
  * @param  None
  * @retval None
  */


void delay(unsigned char i){   
    while(i){   
        i--;   
        }   
    }   


void  BASIC_TIM_IRQHandler (void)
{
  unsigned char i,Data_temp,X,Y;

	if ( TIM_GetITStatus( BASIC_TIM, TIM_IT_Update) != RESET ) 
	{	
		time++;
		
		if(time==0) { LED1_ON;LED2_ON;Out_data_m=0;Out_data_s=0;X=0;Y=0;}//Init data
		else if((time>0)&&(time<=40))
		{
			if(time%2==1)  
			{
				LED1_ON;LED2_ON;
				delay(1);	
			}
			//receive the former
			else if (time<15){
				X++;
				LED1_OFF;LED2_OFF;
				//GPIO_ReadInputDataBit;
				Data_temp=GPIO_ReadOutputDataBit(LED3_GPIO_PORT,LED3_GPIO_PIN);
				//Data_temp=SSI_GPIO_PIN;
				Out_data_m<<=1;
				Out_data_m=Out_data_m|(Data_temp&&0x01);
			}
			//receive behand
			else if (time<=40&&time>=15)
			{	Y++;
				LED1_OFF;LED2_OFF;
				Data_temp=GPIO_ReadOutputDataBit(LED3_GPIO_PORT,LED3_GPIO_PIN);
				// Data_temp=SSI_GPIO_PIN;
				Out_data_s<<=1;
				Out_data_s=Out_data_s|(Data_temp&&0x01);
			}

		}
		else if(time==42){	printf("%d--%d\n\r\n\r",X,Y);LED1_OFF;LED2_OFF; X=0;Y=0; }
		else if(time==200)
		{
		//Out_data_s=0;
		printf("--Out_data_m==%d\n\r--Out_data_s==%d\n\r\n\r",Out_data_m,Out_data_s);

		}

		if(time==2000)time=0;
		TIM_ClearITPendingBit(BASIC_TIM , TIM_FLAG_Update);  		 
	}		 	
}

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
