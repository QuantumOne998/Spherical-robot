#include "tim.h"

/********************************************************************
**����:Tim6_10ms_Init
**����:��ʱ��6��ʼ��,10ms�ж�1��
**����:ʱ��Դ84MHZ
**��ʽ:84M/840/1000 = 100Hz
********************************************************************/
void Tim6_100ms_Init(void)//������ʱ��
{  
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6,ENABLE);  	//TIM6ʱ��ʹ��    
   NVIC_InitTypeDef NVIC_InitStructure;
	
   TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
   TIM_TimeBaseStructure.TIM_Prescaler=840-1;  //Ԥ��Ƶ
   TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
   TIM_TimeBaseStructure.TIM_Period = 1000-1;   //�Զ���װ��ֵ
   TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; //ʱ�ӷָ�
   TIM_TimeBaseInit(TIM6,&TIM_TimeBaseStructure);//��ʼ����ʱ��9
	
   NVIC_InitStructure.NVIC_IRQChannel=TIM6_DAC_IRQn; //��ʱ��3�ж�
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x03; //��ռ���ȼ�1
   NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03; //��Ӧ���ȼ�3
   NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
   NVIC_Init(&NVIC_InitStructure);// �ܳ�ʼ��NVIC
   TIM_ITConfig(TIM6,TIM_IT_Update,ENABLE);

   TIM_Cmd(TIM6, ENABLE);  //ʹ��
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
