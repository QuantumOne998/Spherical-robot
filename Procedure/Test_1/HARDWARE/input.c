#include "input.h"


/********************************************************************
**����:in_Y1_Init
**����:��Դ����1��ʼ��
**˵��:PE2,����Ч
********************************************************************/
void in_D_1_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//ʹ�ܶ˿�ʱ��

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;//���ź�
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
   GPIO_Init(GPIOE, &GPIO_InitStructure);//��ʼ���˿�
}
/********************************************************************
**����:in_Y2_Init
**����:��Դ����2��ʼ��
**˵��:PI6,����Ч
********************************************************************/
void in_D_2_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//ʹ�ܶ˿�ʱ��

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;//���ź�
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
   GPIO_Init(GPIOI, &GPIO_InitStructure);//��ʼ���˿�
}
/********************************************************************
**����:in_Y3_Init
**����:��Դ����3��ʼ��
**˵��:PE3,����Ч
********************************************************************/
void in_D_3_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//ʹ�ܶ˿�ʱ��

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;//���ź�
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
   GPIO_Init(GPIOE, &GPIO_InitStructure);//��ʼ���˿�
}
/********************************************************************
**����:in_Y4_Init
**����:��Դ����4��ʼ��
**˵��:PE4,����Ч
********************************************************************/
void in_D_4_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//ʹ�ܶ˿�ʱ��

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;//���ź�
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
   GPIO_Init(GPIOE, &GPIO_InitStructure);//��ʼ���˿�
}
/********************************************************************
**����:in_Y5_Init
**����:��Դ����5��ʼ��
**˵��:PI7,����Ч
********************************************************************/
void in_D_5_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//ʹ�ܶ˿�ʱ��

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;//���ź�
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
   GPIO_Init(GPIOI, &GPIO_InitStructure);//��ʼ���˿�
}


/********************************************************************
**����:in_W1_Init
**����:��Դ����1��ʼ��
**˵��:PH15,����Ч
********************************************************************/
void in_D_6_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//ʹ�ܶ˿�ʱ��

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;//���ź�
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
   GPIO_Init(GPIOH, &GPIO_InitStructure);//��ʼ���˿�
}
/********************************************************************
**����:in_W2_Init
**����:��Դ����2��ʼ��
**˵��:PI0,����Ч
********************************************************************/
void in_D_7_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//ʹ�ܶ˿�ʱ��

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;//���ź�
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
   GPIO_Init(GPIOI, &GPIO_InitStructure);//��ʼ���˿�
}
/********************************************************************
**����:in_W3_Init
**����:��Դ����3��ʼ��
**˵��:PI2,����Ч
********************************************************************/
void in_D_8_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//ʹ�ܶ˿�ʱ��

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;//���ź�
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
   GPIO_Init(GPIOI, &GPIO_InitStructure);//��ʼ���˿�
}
/********************************************************************
**����:in_W4_Init
**����:��Դ����4��ʼ��
**˵��:PI3,����Ч
********************************************************************/
void in_D_9_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//ʹ�ܶ˿�ʱ��

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;//���ź�
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
   GPIO_Init(GPIOI, &GPIO_InitStructure);//��ʼ���˿�
}
/********************************************************************
**����:in_W5_Init
**����:��Դ����5��ʼ��
**˵��:PI1,����Ч
********************************************************************/
void in_D_10_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//ʹ�ܶ˿�ʱ��

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;//���ź�
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
   GPIO_Init(GPIOI, &GPIO_InitStructure);//��ʼ���˿�
}


/********************************************************************
**����:
**����:
**˵��:��������ʼ��
**arr���Զ���װֵ(TIM2,TIM5��32λ��!!)
**psc��ʱ��Ԥ��Ƶ��
********************************************************************/
//��ʱ��2ͨ��3���벶������
TIM_ICInitTypeDef  TIM2_ICInitStructure;

void TIM2_CH3_Cap_Init(u32 arr,u16 psc)
{
	GPIO_InitTypeDef GPIO1_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM1_TimeBaseStructure;
	NVIC_InitTypeDef NVIC1_InitStructure;

	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);  	//TIM2ʱ��ʹ��    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); 	//ʹ��PORTAʱ��	
	
	GPIO1_InitStructure.GPIO_Pin = GPIO_Pin_10; //GPIOB10
	GPIO1_InitStructure.GPIO_Mode = GPIO_Mode_AF;//���ù���
	GPIO1_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
	GPIO1_InitStructure.GPIO_OType = GPIO_OType_PP; //���츴�����
	GPIO1_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN; //����
	GPIO_Init(GPIOB,&GPIO1_InitStructure); //��ʼ��PA0

	GPIO_PinAFConfig(GPIOB,GPIO_PinSource10,GPIO_AF_TIM2); //PA0����λ��ʱ��5
  
	  
	TIM1_TimeBaseStructure.TIM_Prescaler=psc;  //��ʱ����Ƶ
	TIM1_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
	TIM1_TimeBaseStructure.TIM_Period=arr;   //�Զ���װ��ֵ
	TIM1_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM2,&TIM1_TimeBaseStructure);
	

	//��ʼ��TIM5���벶�����
	TIM2_ICInitStructure.TIM_Channel = TIM_Channel_3; //CC1S=01 	ѡ������� IC1ӳ�䵽TI1��
  TIM2_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	//�����ز���
  TIM2_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //ӳ�䵽TI1��
  TIM2_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 //���������Ƶ,����Ƶ 
  TIM2_ICInitStructure.TIM_ICFilter = 0x00;//IC1F=0000 ���������˲��� ���˲�
  TIM_ICInit(TIM2, &TIM2_ICInitStructure);
		
	TIM_ITConfig(TIM2,TIM_IT_Update|TIM_IT_CC3,ENABLE);//��������ж� ,����CC1IE�����ж�	
	
  TIM_Cmd(TIM2,ENABLE ); 	//ʹ�ܶ�ʱ��5

 
  NVIC1_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC1_InitStructure.NVIC_IRQChannelPreemptionPriority=2;//��ռ���ȼ�3
	NVIC1_InitStructure.NVIC_IRQChannelSubPriority =0;		//�����ȼ�3
	NVIC1_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC1_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ�����
	
	
}
//����״̬
//[7]:0,û�гɹ��Ĳ���;1,�ɹ�����һ��.
//[6]:0,��û���񵽵͵�ƽ;1,�Ѿ����񵽵͵�ƽ��.
//[5:0]:����͵�ƽ������Ĵ���(����32λ��ʱ����˵,1us��������1,���ʱ��:4294��)
u8  TIM2CH3_CAPTURE_STA=0;	//���벶��״̬		    				
u32	TIM2CH3_CAPTURE_VAL;	//���벶��ֵ(TIM2/TIM5��32λ)
//��ʱ��5�жϷ������	 
void TIM2_IRQHandler(void)
{ 		    

 	if((TIM2CH3_CAPTURE_STA&0X80)==0)//��δ�ɹ�����	
	{
		if(TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)//���
		{	     
			if(TIM2CH3_CAPTURE_STA&0X40)//�Ѿ����񵽸ߵ�ƽ��
			{
				if((TIM2CH3_CAPTURE_STA&0X3F)==0X3F)//�ߵ�ƽ̫����
				{
					TIM2CH3_CAPTURE_STA|=0X80;		//��ǳɹ�������һ��
					TIM2CH3_CAPTURE_VAL=0XFFFFFFFF;
				}else TIM2CH3_CAPTURE_STA++;
			}	 
		}
		if(TIM_GetITStatus(TIM2, TIM_IT_CC3) != RESET)//����1���������¼�
		{	
			if(TIM2CH3_CAPTURE_STA&0X40)		//����һ���½��� 		
			{	  			
				TIM2CH3_CAPTURE_STA|=0X80;		//��ǳɹ�����һ�θߵ�ƽ����
			  TIM2CH3_CAPTURE_VAL=TIM_GetCapture3(TIM2);//��ȡ��ǰ�Ĳ���ֵ.
	 			TIM_OC1PolarityConfig(TIM2,TIM_ICPolarity_Rising); //CC1P=0 ����Ϊ�����ز���
			}else  								//��δ��ʼ,��һ�β���������
			{
				TIM2CH3_CAPTURE_STA=0;			//���
				TIM2CH3_CAPTURE_VAL=0;
				TIM2CH3_CAPTURE_STA|=0X40;		//��ǲ�����������
				TIM_Cmd(TIM2,DISABLE ); 	//�رն�ʱ��5
	 			TIM_SetCounter(TIM2,0);
	 			TIM_OC1PolarityConfig(TIM2,TIM_ICPolarity_Falling);		//CC1P=1 ����Ϊ�½��ز���
				TIM_Cmd(TIM2,ENABLE ); 	//ʹ�ܶ�ʱ��5
			}		    
		}			     	    					   
 	}
	TIM_ClearITPendingBit(TIM2, TIM_IT_CC3|TIM_IT_Update); //����жϱ�־λ
}

/********************************************************************
**����:
**����:
**˵��:��������ʼ��
**arr���Զ���װֵ
**psc��ʱ��Ԥ��Ƶ��
********************************************************************/
//��ʱ��4ͨ��2���벶������
TIM_ICInitTypeDef  TIM4_ICInitStructure;

void TIM4_CH2_Cap_Init(u32 arr,u16 psc)
{
	GPIO_InitTypeDef GPIO2_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM2_TimeBaseStructure;
	NVIC_InitTypeDef NVIC2_InitStructure;

	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);  	//TIM2ʱ��ʹ��    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE); 	//ʹ��PORTAʱ��	
	
	GPIO2_InitStructure.GPIO_Pin = GPIO_Pin_13; //GPIOB10
	GPIO2_InitStructure.GPIO_Mode = GPIO_Mode_AF;//���ù���
	GPIO2_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
	GPIO2_InitStructure.GPIO_OType = GPIO_OType_PP; //���츴�����
	GPIO2_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN; //����
	GPIO_Init(GPIOD,&GPIO2_InitStructure); //��ʼ��PA0

	GPIO_PinAFConfig(GPIOD,GPIO_PinSource13,GPIO_AF_TIM4); //PA0����λ��ʱ��5
  
	  
	TIM2_TimeBaseStructure.TIM_Prescaler=psc;  //��ʱ����Ƶ
	TIM2_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
	TIM2_TimeBaseStructure.TIM_Period=arr;   //�Զ���װ��ֵ
	TIM2_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM4,&TIM2_TimeBaseStructure);
	

	//��ʼ��TIM5���벶�����
	TIM4_ICInitStructure.TIM_Channel = TIM_Channel_2; //CC1S=01 	ѡ������� IC1ӳ�䵽TI1��
  TIM4_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	//�����ز���
  TIM4_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //ӳ�䵽TI1��
  TIM4_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 //���������Ƶ,����Ƶ 
  TIM4_ICInitStructure.TIM_ICFilter = 0x00;//IC1F=0000 ���������˲��� ���˲�
  TIM_ICInit(TIM4, &TIM4_ICInitStructure);
		
	TIM_ITConfig(TIM4,TIM_IT_Update|TIM_IT_CC2,ENABLE);//��������ж� ,����CC1IE�����ж�	
	
  TIM_Cmd(TIM4,ENABLE ); 	//ʹ�ܶ�ʱ��5

 
  NVIC2_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
	NVIC2_InitStructure.NVIC_IRQChannelPreemptionPriority=2;//��ռ���ȼ�3
	NVIC2_InitStructure.NVIC_IRQChannelSubPriority =0;		//�����ȼ�3
	NVIC2_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC2_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ�����
	
	
}
//����״̬
//[7]:0,û�гɹ��Ĳ���;1,�ɹ�����һ��.
//[6]:0,��û���񵽵͵�ƽ;1,�Ѿ����񵽵͵�ƽ��.
//[5:0]:����͵�ƽ������Ĵ���(����32λ��ʱ����˵,1us��������1,���ʱ��:4294��)
u8  TIM4CH2_CAPTURE_STA=0;	//���벶��״̬		    				
u32	TIM4CH2_CAPTURE_VAL;	//���벶��ֵ(TIM2/TIM5��32λ)
//��ʱ��4�жϷ������	 
void TIM4_IRQHandler(void)
{ 		    

 	if((TIM4CH2_CAPTURE_STA&0X80)==0)//��δ�ɹ�����	
	{
		if(TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)//���
		{	     
			if(TIM4CH2_CAPTURE_STA&0X40)//�Ѿ����񵽸ߵ�ƽ��
			{
				if((TIM4CH2_CAPTURE_STA&0X3F)==0X3F)//�ߵ�ƽ̫����
				{
					TIM4CH2_CAPTURE_STA|=0X80;		//��ǳɹ�������һ��
					TIM4CH2_CAPTURE_VAL=0XFFFF;
				}else TIM4CH2_CAPTURE_STA++;
			}	 
		}
		if(TIM_GetITStatus(TIM4, TIM_IT_CC2) != RESET)//����1���������¼�
		{	
			if(TIM4CH2_CAPTURE_STA&0X40)		//����һ���½��� 		
			{	  			
				TIM4CH2_CAPTURE_STA|=0X80;		//��ǳɹ�����һ�θߵ�ƽ����
			  TIM4CH2_CAPTURE_VAL=TIM_GetCapture2(TIM4);//��ȡ��ǰ�Ĳ���ֵ.
	 			TIM_OC1PolarityConfig(TIM4,TIM_ICPolarity_Rising); //CC1P=0 ����Ϊ�����ز���
			}else  								//��δ��ʼ,��һ�β���������
			{
				TIM4CH2_CAPTURE_STA=0;			//���
				TIM4CH2_CAPTURE_VAL=0;
				TIM4CH2_CAPTURE_STA|=0X40;		//��ǲ�����������
				TIM_Cmd(TIM4,DISABLE ); 	//�رն�ʱ��5
	 			TIM_SetCounter(TIM4,0);
	 			TIM_OC1PolarityConfig(TIM4,TIM_ICPolarity_Falling);		//CC1P=1 ����Ϊ�½��ز���
				TIM_Cmd(TIM4,ENABLE ); 	//ʹ�ܶ�ʱ��5
			}		    
		}			     	    					   
 	}
	TIM_ClearITPendingBit(TIM4, TIM_IT_CC2|TIM_IT_Update); //����жϱ�־λ
}




