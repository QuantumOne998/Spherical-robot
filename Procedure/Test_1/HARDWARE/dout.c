#include "dout.h" 

/********************************************************************
**名称:Run_LED_Init
**功能:运行指示灯初始化
**说明:PB6,高有效
********************************************************************/
void Run_LED_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);//使能端口时钟

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;//引脚号
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//下拉
   GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化端口
	
   GPIO_ResetBits(GPIOB,GPIO_Pin_6);//置低无输出
}


/********************************************************************
**名称:Dout_LED_Init
**功能:LED初始化
**说明:,高有效
********************************************************************/
void Dout_LED_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//使能端口时钟

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;//引脚号
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//下拉
   GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化端口
	
   GPIO_ResetBits(GPIOA,GPIO_Pin_0);//置低无输出
}


/********************************************************************
**名称:Dout_Y1_Init
**功能:有源输出1初始化
**说明:PD7,高有效
********************************************************************/
void Dout_Y1_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//使能端口时钟

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;//引脚号
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//下拉
   GPIO_Init(GPIOD, &GPIO_InitStructure);//初始化端口
	
   GPIO_ResetBits(GPIOD,GPIO_Pin_7);//置低无输出
}

/********************************************************************
**名称:Dout_Y2_Init
**功能:有源输出2初始化
**说明:PG9,高有效
********************************************************************/
void Dout_Y2_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);//使能端口时钟

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;//引脚号
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//下拉
   GPIO_Init(GPIOG, &GPIO_InitStructure);//初始化端口
	
   GPIO_ResetBits(GPIOG,GPIO_Pin_9);//置低无输出
}

/********************************************************************
**名称:Dout_Y3_Init
**功能:有源输出3初始化
**说明:PG11,高有效
********************************************************************/
void Dout_Y3_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);//使能端口时钟

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//引脚号
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//下拉
   GPIO_Init(GPIOG, &GPIO_InitStructure);//初始化端口
	
   GPIO_ResetBits(GPIOG,GPIO_Pin_10);//置低无输出
}

/********************************************************************
**名称:Dout_Y4_Init
**功能:有源输出4初始化
**说明:PG12,高有效
********************************************************************/
void Dout_Y4_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);//使能端口时钟

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;//引脚号
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//下拉
   GPIO_Init(GPIOG, &GPIO_InitStructure);//初始化端口
	
   GPIO_ResetBits(GPIOG,GPIO_Pin_12);//置低无输出
}

/********************************************************************
**名称:Dout_Y5_Init
**功能:有源输出5初始化
**说明:PG15,高有效
********************************************************************/
void Dout_Y5_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);//使能端口时钟

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;//引脚号
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//下拉
   GPIO_Init(GPIOG, &GPIO_InitStructure);//初始化端口
	
   GPIO_ResetBits(GPIOG,GPIO_Pin_15);//置低无输出
}
/********************************************************************
**名称:
**功能:
**说明:
********************************************************************/
void rs422_init(void)
{
   GPIO_InitTypeDef GPIO_InitStructure;//?????????
   USART_InitTypeDef USART_InitStruct;//?????????
	
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE); //??GPIOD??
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);//??USART3??

   GPIO_PinAFConfig(GPIOD,GPIO_PinSource8,GPIO_AF_USART3); //PD8??????
   GPIO_PinAFConfig(GPIOD,GPIO_PinSource9,GPIO_AF_USART3); //PD9??????
	
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9; 
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
   GPIO_Init(GPIOD,&GPIO_InitStructure);

   USART_InitStruct.USART_BaudRate = 9600;
   USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//?????? 
   USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;//????
   USART_InitStruct.USART_Parity = USART_Parity_No;//???
   USART_InitStruct.USART_StopBits = USART_StopBits_1;
   USART_InitStruct.USART_WordLength = USART_WordLength_8b;
   USART_Init(USART3,&USART_InitStruct);
	 
   USART_Cmd(USART3, ENABLE);
	 
   USART_ClearFlag(USART3, USART_FLAG_TC);
}

/********************************************************************
**名称:Switch_Init
**功能:低温通道选择
**说明:000-110对应六个通道
A0——PF15
A1——PG0
A2——PG1
********************************************************************/
void Switch_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);//使能端口时钟
	 RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//使能端口时钟
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;//引脚号
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//下拉
   GPIO_Init(GPIOG, &GPIO_InitStructure);//初始化端口
	
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;//引脚号
   GPIO_Init(GPIOF, &GPIO_InitStructure);//初始化端口
	
	 GPIO_ResetBits(GPIOF,GPIO_Pin_15);//置低无输出
   GPIO_ResetBits(GPIOG,GPIO_Pin_0|GPIO_Pin_1);//置低无输出
}


/********************************************************************
**名称:GJD_out
**功能:干接点输出
**说明:
********************************************************************/

void GJD_out(void)
{
	   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);//使能端口时钟

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12;//引脚号
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//下拉
   GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化端口
	
   GPIO_ResetBits(GPIOG,GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12);//置低无输出



}

