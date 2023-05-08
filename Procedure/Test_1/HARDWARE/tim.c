#include "tim.h"

/********************************************************************
**名称:Tim6_10ms_Init
**功能:定时器6初始化,10ms中断1次
**描述:时钟源84MHZ
**公式:84M/840/1000 = 100Hz
********************************************************************/
void Tim6_100ms_Init(void)//基本定时器
{  
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6,ENABLE);  	//TIM6时钟使能    
   NVIC_InitTypeDef NVIC_InitStructure;
	
   TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
   TIM_TimeBaseStructure.TIM_Prescaler=840-1;  //预分频
   TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
   TIM_TimeBaseStructure.TIM_Period = 1000-1;   //自动重装载值
   TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; //时钟分割
   TIM_TimeBaseInit(TIM6,&TIM_TimeBaseStructure);//初始化定时器9
	
   NVIC_InitStructure.NVIC_IRQChannel=TIM6_DAC_IRQn; //定时器3中断
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x03; //抢占优先级1
   NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03; //响应优先级3
   NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
   NVIC_Init(&NVIC_InitStructure);// ④初始化NVIC
   TIM_ITConfig(TIM6,TIM_IT_Update,ENABLE);

   TIM_Cmd(TIM6, ENABLE);  //使能
}

int Tim10Ms = 0;
void TIM6_DAC_IRQHandler(void)
{
   if(TIM_GetFlagStatus(TIM6,TIM_FLAG_Update)!=RESET)
	 {
		  TIM_ClearITPendingBit(TIM6,TIM_FLAG_Update);
		  if(Tim10Ms) Tim10Ms--;
	 }		 
}
