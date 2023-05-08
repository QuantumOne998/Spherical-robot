#include "dout.h" 

/********************************************************************
**����:Run_LED_Init
**����:����ָʾ�Ƴ�ʼ��
**˵��:PB6,����Ч
********************************************************************/
void Run_LED_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);//ʹ�ܶ˿�ʱ��

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;//���ź�
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//����
   GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ���˿�
	
   GPIO_ResetBits(GPIOB,GPIO_Pin_6);//�õ������
}


/********************************************************************
**����:Dout_LED_Init
**����:LED��ʼ��
**˵��:,����Ч
********************************************************************/
void Dout_LED_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//ʹ�ܶ˿�ʱ��

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;//���ź�
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//����
   GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ���˿�
	
   GPIO_ResetBits(GPIOA,GPIO_Pin_0);//�õ������
}


/********************************************************************
**����:Dout_Y1_Init
**����:��Դ���1��ʼ��
**˵��:PD7,����Ч
********************************************************************/
void Dout_Y1_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//ʹ�ܶ˿�ʱ��

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;//���ź�
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//����
   GPIO_Init(GPIOD, &GPIO_InitStructure);//��ʼ���˿�
	
   GPIO_ResetBits(GPIOD,GPIO_Pin_7);//�õ������
}

/********************************************************************
**����:Dout_Y2_Init
**����:��Դ���2��ʼ��
**˵��:PG9,����Ч
********************************************************************/
void Dout_Y2_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);//ʹ�ܶ˿�ʱ��

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;//���ź�
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//����
   GPIO_Init(GPIOG, &GPIO_InitStructure);//��ʼ���˿�
	
   GPIO_ResetBits(GPIOG,GPIO_Pin_9);//�õ������
}

/********************************************************************
**����:Dout_Y3_Init
**����:��Դ���3��ʼ��
**˵��:PG11,����Ч
********************************************************************/
void Dout_Y3_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);//ʹ�ܶ˿�ʱ��

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//���ź�
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//����
   GPIO_Init(GPIOG, &GPIO_InitStructure);//��ʼ���˿�
	
   GPIO_ResetBits(GPIOG,GPIO_Pin_10);//�õ������
}

/********************************************************************
**����:Dout_Y4_Init
**����:��Դ���4��ʼ��
**˵��:PG12,����Ч
********************************************************************/
void Dout_Y4_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);//ʹ�ܶ˿�ʱ��

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;//���ź�
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//����
   GPIO_Init(GPIOG, &GPIO_InitStructure);//��ʼ���˿�
	
   GPIO_ResetBits(GPIOG,GPIO_Pin_12);//�õ������
}

/********************************************************************
**����:Dout_Y5_Init
**����:��Դ���5��ʼ��
**˵��:PG15,����Ч
********************************************************************/
void Dout_Y5_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);//ʹ�ܶ˿�ʱ��

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;//���ź�
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//����
   GPIO_Init(GPIOG, &GPIO_InitStructure);//��ʼ���˿�
	
   GPIO_ResetBits(GPIOG,GPIO_Pin_15);//�õ������
}
/********************************************************************
**����:
**����:
**˵��:
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
**����:Switch_Init
**����:����ͨ��ѡ��
**˵��:000-110��Ӧ����ͨ��
A0����PF15
A1����PG0
A2����PG1
********************************************************************/
void Switch_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);//ʹ�ܶ˿�ʱ��
	 RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//ʹ�ܶ˿�ʱ��
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;//���ź�
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//����
   GPIO_Init(GPIOG, &GPIO_InitStructure);//��ʼ���˿�
	
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;//���ź�
   GPIO_Init(GPIOF, &GPIO_InitStructure);//��ʼ���˿�
	
	 GPIO_ResetBits(GPIOF,GPIO_Pin_15);//�õ������
   GPIO_ResetBits(GPIOG,GPIO_Pin_0|GPIO_Pin_1);//�õ������
}


/********************************************************************
**����:GJD_out
**����:�ɽӵ����
**˵��:
********************************************************************/

void GJD_out(void)
{
	   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);//ʹ�ܶ˿�ʱ��

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12;//���ź�
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//����
   GPIO_Init(GPIOE, &GPIO_InitStructure);//��ʼ���˿�
	
   GPIO_ResetBits(GPIOG,GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12);//�õ������



}

