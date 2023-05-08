#include "input.h"


/********************************************************************
**名称:in_Y1_Init
**功能:有源输入1初始化
**说明:PE2,低有效
********************************************************************/
void in_D_1_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//使能端口时钟

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;//引脚号
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
   GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化端口
}
/********************************************************************
**名称:in_Y2_Init
**功能:有源输入2初始化
**说明:PI6,低有效
********************************************************************/
void in_D_2_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//使能端口时钟

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;//引脚号
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
   GPIO_Init(GPIOI, &GPIO_InitStructure);//初始化端口
}
/********************************************************************
**名称:in_Y3_Init
**功能:有源输入3初始化
**说明:PE3,低有效
********************************************************************/
void in_D_3_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//使能端口时钟

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;//引脚号
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
   GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化端口
}
/********************************************************************
**名称:in_Y4_Init
**功能:有源输入4初始化
**说明:PE4,低有效
********************************************************************/
void in_D_4_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//使能端口时钟

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;//引脚号
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
   GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化端口
}
/********************************************************************
**名称:in_Y5_Init
**功能:有源输入5初始化
**说明:PI7,低有效
********************************************************************/
void in_D_5_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//使能端口时钟

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;//引脚号
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
   GPIO_Init(GPIOI, &GPIO_InitStructure);//初始化端口
}


/********************************************************************
**名称:in_W1_Init
**功能:无源输入1初始化
**说明:PH15,低有效
********************************************************************/
void in_D_6_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//使能端口时钟

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;//引脚号
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
   GPIO_Init(GPIOH, &GPIO_InitStructure);//初始化端口
}
/********************************************************************
**名称:in_W2_Init
**功能:无源输入2初始化
**说明:PI0,低有效
********************************************************************/
void in_D_7_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//使能端口时钟

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;//引脚号
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
   GPIO_Init(GPIOI, &GPIO_InitStructure);//初始化端口
}
/********************************************************************
**名称:in_W3_Init
**功能:无源输入3初始化
**说明:PI2,低有效
********************************************************************/
void in_D_8_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//使能端口时钟

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;//引脚号
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
   GPIO_Init(GPIOI, &GPIO_InitStructure);//初始化端口
}
/********************************************************************
**名称:in_W4_Init
**功能:无源输入4初始化
**说明:PI3,低有效
********************************************************************/
void in_D_9_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//使能端口时钟

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;//引脚号
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
   GPIO_Init(GPIOI, &GPIO_InitStructure);//初始化端口
}
/********************************************************************
**名称:in_W5_Init
**功能:无源输入5初始化
**说明:PI1,低有效
********************************************************************/
void in_D_10_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//使能端口时钟

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;//引脚号
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
   GPIO_Init(GPIOI, &GPIO_InitStructure);//初始化端口
}


/********************************************************************
**名称:
**功能:
**说明:输入俘获初始化
**arr：自动重装值(TIM2,TIM5是32位的!!)
**psc：时钟预分频数
********************************************************************/
//定时器2通道3输入捕获配置
TIM_ICInitTypeDef  TIM2_ICInitStructure;

void TIM2_CH3_Cap_Init(u32 arr,u16 psc)
{
	GPIO_InitTypeDef GPIO1_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM1_TimeBaseStructure;
	NVIC_InitTypeDef NVIC1_InitStructure;

	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);  	//TIM2时钟使能    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); 	//使能PORTA时钟	
	
	GPIO1_InitStructure.GPIO_Pin = GPIO_Pin_10; //GPIOB10
	GPIO1_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用功能
	GPIO1_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO1_InitStructure.GPIO_OType = GPIO_OType_PP; //推挽复用输出
	GPIO1_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN; //下拉
	GPIO_Init(GPIOB,&GPIO1_InitStructure); //初始化PA0

	GPIO_PinAFConfig(GPIOB,GPIO_PinSource10,GPIO_AF_TIM2); //PA0复用位定时器5
  
	  
	TIM1_TimeBaseStructure.TIM_Prescaler=psc;  //定时器分频
	TIM1_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	TIM1_TimeBaseStructure.TIM_Period=arr;   //自动重装载值
	TIM1_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM2,&TIM1_TimeBaseStructure);
	

	//初始化TIM5输入捕获参数
	TIM2_ICInitStructure.TIM_Channel = TIM_Channel_3; //CC1S=01 	选择输入端 IC1映射到TI1上
  TIM2_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	//上升沿捕获
  TIM2_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //映射到TI1上
  TIM2_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 //配置输入分频,不分频 
  TIM2_ICInitStructure.TIM_ICFilter = 0x00;//IC1F=0000 配置输入滤波器 不滤波
  TIM_ICInit(TIM2, &TIM2_ICInitStructure);
		
	TIM_ITConfig(TIM2,TIM_IT_Update|TIM_IT_CC3,ENABLE);//允许更新中断 ,允许CC1IE捕获中断	
	
  TIM_Cmd(TIM2,ENABLE ); 	//使能定时器5

 
  NVIC1_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC1_InitStructure.NVIC_IRQChannelPreemptionPriority=2;//抢占优先级3
	NVIC1_InitStructure.NVIC_IRQChannelSubPriority =0;		//子优先级3
	NVIC1_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC1_InitStructure);	//根据指定的参数初始化VIC寄存器、
	
	
}
//捕获状态
//[7]:0,没有成功的捕获;1,成功捕获到一次.
//[6]:0,还没捕获到低电平;1,已经捕获到低电平了.
//[5:0]:捕获低电平后溢出的次数(对于32位定时器来说,1us计数器加1,溢出时间:4294秒)
u8  TIM2CH3_CAPTURE_STA=0;	//输入捕获状态		    				
u32	TIM2CH3_CAPTURE_VAL;	//输入捕获值(TIM2/TIM5是32位)
//定时器5中断服务程序	 
void TIM2_IRQHandler(void)
{ 		    

 	if((TIM2CH3_CAPTURE_STA&0X80)==0)//还未成功捕获	
	{
		if(TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)//溢出
		{	     
			if(TIM2CH3_CAPTURE_STA&0X40)//已经捕获到高电平了
			{
				if((TIM2CH3_CAPTURE_STA&0X3F)==0X3F)//高电平太长了
				{
					TIM2CH3_CAPTURE_STA|=0X80;		//标记成功捕获了一次
					TIM2CH3_CAPTURE_VAL=0XFFFFFFFF;
				}else TIM2CH3_CAPTURE_STA++;
			}	 
		}
		if(TIM_GetITStatus(TIM2, TIM_IT_CC3) != RESET)//捕获1发生捕获事件
		{	
			if(TIM2CH3_CAPTURE_STA&0X40)		//捕获到一个下降沿 		
			{	  			
				TIM2CH3_CAPTURE_STA|=0X80;		//标记成功捕获到一次高电平脉宽
			  TIM2CH3_CAPTURE_VAL=TIM_GetCapture3(TIM2);//获取当前的捕获值.
	 			TIM_OC1PolarityConfig(TIM2,TIM_ICPolarity_Rising); //CC1P=0 设置为上升沿捕获
			}else  								//还未开始,第一次捕获上升沿
			{
				TIM2CH3_CAPTURE_STA=0;			//清空
				TIM2CH3_CAPTURE_VAL=0;
				TIM2CH3_CAPTURE_STA|=0X40;		//标记捕获到了上升沿
				TIM_Cmd(TIM2,DISABLE ); 	//关闭定时器5
	 			TIM_SetCounter(TIM2,0);
	 			TIM_OC1PolarityConfig(TIM2,TIM_ICPolarity_Falling);		//CC1P=1 设置为下降沿捕获
				TIM_Cmd(TIM2,ENABLE ); 	//使能定时器5
			}		    
		}			     	    					   
 	}
	TIM_ClearITPendingBit(TIM2, TIM_IT_CC3|TIM_IT_Update); //清除中断标志位
}

/********************************************************************
**名称:
**功能:
**说明:输入俘获初始化
**arr：自动重装值
**psc：时钟预分频数
********************************************************************/
//定时器4通道2输入捕获配置
TIM_ICInitTypeDef  TIM4_ICInitStructure;

void TIM4_CH2_Cap_Init(u32 arr,u16 psc)
{
	GPIO_InitTypeDef GPIO2_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM2_TimeBaseStructure;
	NVIC_InitTypeDef NVIC2_InitStructure;

	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);  	//TIM2时钟使能    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE); 	//使能PORTA时钟	
	
	GPIO2_InitStructure.GPIO_Pin = GPIO_Pin_13; //GPIOB10
	GPIO2_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用功能
	GPIO2_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO2_InitStructure.GPIO_OType = GPIO_OType_PP; //推挽复用输出
	GPIO2_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN; //下拉
	GPIO_Init(GPIOD,&GPIO2_InitStructure); //初始化PA0

	GPIO_PinAFConfig(GPIOD,GPIO_PinSource13,GPIO_AF_TIM4); //PA0复用位定时器5
  
	  
	TIM2_TimeBaseStructure.TIM_Prescaler=psc;  //定时器分频
	TIM2_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	TIM2_TimeBaseStructure.TIM_Period=arr;   //自动重装载值
	TIM2_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM4,&TIM2_TimeBaseStructure);
	

	//初始化TIM5输入捕获参数
	TIM4_ICInitStructure.TIM_Channel = TIM_Channel_2; //CC1S=01 	选择输入端 IC1映射到TI1上
  TIM4_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	//上升沿捕获
  TIM4_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //映射到TI1上
  TIM4_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 //配置输入分频,不分频 
  TIM4_ICInitStructure.TIM_ICFilter = 0x00;//IC1F=0000 配置输入滤波器 不滤波
  TIM_ICInit(TIM4, &TIM4_ICInitStructure);
		
	TIM_ITConfig(TIM4,TIM_IT_Update|TIM_IT_CC2,ENABLE);//允许更新中断 ,允许CC1IE捕获中断	
	
  TIM_Cmd(TIM4,ENABLE ); 	//使能定时器5

 
  NVIC2_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
	NVIC2_InitStructure.NVIC_IRQChannelPreemptionPriority=2;//抢占优先级3
	NVIC2_InitStructure.NVIC_IRQChannelSubPriority =0;		//子优先级3
	NVIC2_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC2_InitStructure);	//根据指定的参数初始化VIC寄存器、
	
	
}
//捕获状态
//[7]:0,没有成功的捕获;1,成功捕获到一次.
//[6]:0,还没捕获到低电平;1,已经捕获到低电平了.
//[5:0]:捕获低电平后溢出的次数(对于32位定时器来说,1us计数器加1,溢出时间:4294秒)
u8  TIM4CH2_CAPTURE_STA=0;	//输入捕获状态		    				
u32	TIM4CH2_CAPTURE_VAL;	//输入捕获值(TIM2/TIM5是32位)
//定时器4中断服务程序	 
void TIM4_IRQHandler(void)
{ 		    

 	if((TIM4CH2_CAPTURE_STA&0X80)==0)//还未成功捕获	
	{
		if(TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)//溢出
		{	     
			if(TIM4CH2_CAPTURE_STA&0X40)//已经捕获到高电平了
			{
				if((TIM4CH2_CAPTURE_STA&0X3F)==0X3F)//高电平太长了
				{
					TIM4CH2_CAPTURE_STA|=0X80;		//标记成功捕获了一次
					TIM4CH2_CAPTURE_VAL=0XFFFF;
				}else TIM4CH2_CAPTURE_STA++;
			}	 
		}
		if(TIM_GetITStatus(TIM4, TIM_IT_CC2) != RESET)//捕获1发生捕获事件
		{	
			if(TIM4CH2_CAPTURE_STA&0X40)		//捕获到一个下降沿 		
			{	  			
				TIM4CH2_CAPTURE_STA|=0X80;		//标记成功捕获到一次高电平脉宽
			  TIM4CH2_CAPTURE_VAL=TIM_GetCapture2(TIM4);//获取当前的捕获值.
	 			TIM_OC1PolarityConfig(TIM4,TIM_ICPolarity_Rising); //CC1P=0 设置为上升沿捕获
			}else  								//还未开始,第一次捕获上升沿
			{
				TIM4CH2_CAPTURE_STA=0;			//清空
				TIM4CH2_CAPTURE_VAL=0;
				TIM4CH2_CAPTURE_STA|=0X40;		//标记捕获到了上升沿
				TIM_Cmd(TIM4,DISABLE ); 	//关闭定时器5
	 			TIM_SetCounter(TIM4,0);
	 			TIM_OC1PolarityConfig(TIM4,TIM_ICPolarity_Falling);		//CC1P=1 设置为下降沿捕获
				TIM_Cmd(TIM4,ENABLE ); 	//使能定时器5
			}		    
		}			     	    					   
 	}
	TIM_ClearITPendingBit(TIM4, TIM_IT_CC2|TIM_IT_Update); //清除中断标志位
}




