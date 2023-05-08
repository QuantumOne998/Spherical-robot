#include "pwm.h"

/********************************************************************
**����:Pwm_20ma_Init
**����:PWMת4-20mA��ʼ��
**˵��:PIN89,PH12,TIM5-CH3	
**˵��:ʱ��Դ84MHZ ��PWM����250HZ��   
********************************************************************/
void Pwm_20mA_Init(void)
{
   GPIO_InitTypeDef GPIO_InitStructure;
   TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
   TIM_OCInitTypeDef  TIM_OCInitStructure;
	 
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);  	//TIM5ʱ��ʹ��    
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH, ENABLE); 	//ʹ�ܶ˿�ʱ��	
   GPIO_PinAFConfig(GPIOH,GPIO_PinSource11,GPIO_AF_TIM5); //����Ϊ��ʱ��5
	
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;          //���ź�
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;     //�������GPIO_OType_PP
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;      //����
   GPIO_Init(GPIOH,&GPIO_InitStructure);              //��ʼ������
	  
   TIM_TimeBaseStructure.TIM_Prescaler=336-1;  //Ԥ��Ƶ
   TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
   TIM_TimeBaseStructure.TIM_Period = 999;   //�Զ���װ��ֵ
   TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; //ʱ�ӷָ�
   TIM_TimeBaseInit(TIM5,&TIM_TimeBaseStructure);//��ʼ����ʱ��
	
	//��ʼ��ͨ��1
   TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
   TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
   TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
   TIM_OC2Init(TIM5, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM1 4OC1

   TIM_OC2PreloadConfig(TIM5, TIM_OCPreload_Enable);  //ʹ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
 
   TIM_ARRPreloadConfig(TIM5,ENABLE);//ARPEʹ�� 
	
   TIM_Cmd(TIM5, ENABLE);  //ʹ��
	 //TIM_SetCompare2(TIM5,499);	//�޸ıȽ�ֵ���޸�ռ�ձ�   
}

/********************************************************************
**����:Pwm_5V_Init
**����:PWMת0-5V/10V��ʼ��
**˵��:PIN88,PH11,TIM5-CH2	
**˵��:ʱ��Դ84MHZ ��PWM����250HZ��   
********************************************************************/
void Pwm_5V_Init(void)
{
   GPIO_InitTypeDef GPIO_InitStructure;
   TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
   TIM_OCInitTypeDef  TIM_OCInitStructure;
	 
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);  	//TIM5ʱ��ʹ��    
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH, ENABLE); 	//ʹ�ܶ˿�ʱ��	
   GPIO_PinAFConfig(GPIOH,GPIO_PinSource10,GPIO_AF_TIM5); //����Ϊ��ʱ��5
	
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;          //���ź�
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;     //���츴�����
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;   //��������
   GPIO_Init(GPIOH,&GPIO_InitStructure);              //��ʼ������
	  
   TIM_TimeBaseStructure.TIM_Prescaler=336-1;  //Ԥ��Ƶ
   TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
   TIM_TimeBaseStructure.TIM_Period = 999;   //�Զ���װ��ֵ
   TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; //ʱ�ӷָ�
   TIM_TimeBaseInit(TIM5,&TIM_TimeBaseStructure);//��ʼ����ʱ��
	
	//��ʼ��ͨ��1
   TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
   TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
   TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
   TIM_OC1Init(TIM5, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM1 4OC1

   TIM_OC1PreloadConfig(TIM5, TIM_OCPreload_Enable);  //ʹ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
 
   TIM_ARRPreloadConfig(TIM5,ENABLE);//ARPEʹ�� 
	
   TIM_Cmd(TIM5, ENABLE);  //ʹ��
	// TIM_SetCompare1(TIM5,999);	//�޸ıȽ�ֵ���޸�ռ�ձ�   
}
