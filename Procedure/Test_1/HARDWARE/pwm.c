#include "pwm.h"

/********************************************************************
**名称:Pwm_20ma_Init
**功能:PWM转4-20mA初始化
**说明:PIN89,PH12,TIM5-CH3	
**说明:时钟源84MHZ （PWM周期250HZ）   
********************************************************************/
void Pwm_20mA_Init(void)
{
   GPIO_InitTypeDef GPIO_InitStructure;
   TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
   TIM_OCInitTypeDef  TIM_OCInitStructure;
	 
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);  	//TIM5时钟使能    
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH, ENABLE); 	//使能端口时钟	
   GPIO_PinAFConfig(GPIOH,GPIO_PinSource11,GPIO_AF_TIM5); //复用为定时器5
	
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;          //引脚号
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //复用功能
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;     //推挽输出GPIO_OType_PP
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;      //下拉
   GPIO_Init(GPIOH,&GPIO_InitStructure);              //初始化引脚
	  
   TIM_TimeBaseStructure.TIM_Prescaler=336-1;  //预分频
   TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
   TIM_TimeBaseStructure.TIM_Period = 999;   //自动重装载值
   TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; //时钟分割
   TIM_TimeBaseInit(TIM5,&TIM_TimeBaseStructure);//初始化定时器
	
	//初始化通道1
   TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1
   TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
   TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性高
   TIM_OC2Init(TIM5, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1

   TIM_OC2PreloadConfig(TIM5, TIM_OCPreload_Enable);  //使能TIM14在CCR1上的预装载寄存器
 
   TIM_ARRPreloadConfig(TIM5,ENABLE);//ARPE使能 
	
   TIM_Cmd(TIM5, ENABLE);  //使能
	 //TIM_SetCompare2(TIM5,499);	//修改比较值，修改占空比   
}

/********************************************************************
**名称:Pwm_5V_Init
**功能:PWM转0-5V/10V初始化
**说明:PIN88,PH11,TIM5-CH2	
**说明:时钟源84MHZ （PWM周期250HZ）   
********************************************************************/
void Pwm_5V_Init(void)
{
   GPIO_InitTypeDef GPIO_InitStructure;
   TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
   TIM_OCInitTypeDef  TIM_OCInitStructure;
	 
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);  	//TIM5时钟使能    
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH, ENABLE); 	//使能端口时钟	
   GPIO_PinAFConfig(GPIOH,GPIO_PinSource10,GPIO_AF_TIM5); //复用为定时器5
	
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;          //引脚号
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //复用功能
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;     //推挽复用输出
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;   //不上下拉
   GPIO_Init(GPIOH,&GPIO_InitStructure);              //初始化引脚
	  
   TIM_TimeBaseStructure.TIM_Prescaler=336-1;  //预分频
   TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
   TIM_TimeBaseStructure.TIM_Period = 999;   //自动重装载值
   TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; //时钟分割
   TIM_TimeBaseInit(TIM5,&TIM_TimeBaseStructure);//初始化定时器
	
	//初始化通道1
   TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1
   TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
   TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性高
   TIM_OC1Init(TIM5, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1

   TIM_OC1PreloadConfig(TIM5, TIM_OCPreload_Enable);  //使能TIM14在CCR1上的预装载寄存器
 
   TIM_ARRPreloadConfig(TIM5,ENABLE);//ARPE使能 
	
   TIM_Cmd(TIM5, ENABLE);  //使能
	// TIM_SetCompare1(TIM5,999);	//修改比较值，修改占空比   
}
