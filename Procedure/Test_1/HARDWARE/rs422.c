#include "rs422.h"

/********************************************************************
**����:RS422_U3_Init
**����:��ʼ��RS422��ͨ��
**˵��:PIN96,PD8,USART2-TX
       PIN97,PD9,USART2-RX
**Ӳ�����ӣ���ʤΪ�����ߣ�:
           1:��Ƭ��RX+  2:��Ƭ��RX-
           3:��Ƭ��TX+  4:��Ƭ��TX-
********************************************************************/
void RS422_Init(u32 bound)//��ʼ��RS422��ͨ��
{
   GPIO_InitTypeDef GPIO_InitStructure;
   USART_InitTypeDef USART_InitStructure;
   NVIC_InitTypeDef NVIC_InitStructure;
	
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE); //ʹ��GPIODʱ��
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);//ʹ��USART2ʱ��
 
   //����3��Ӧ���Ÿ���ӳ��
   GPIO_PinAFConfig(GPIOD,GPIO_PinSource8,GPIO_AF_USART2); //GPIOD5����ΪUSART2
   GPIO_PinAFConfig(GPIOD,GPIO_PinSource9,GPIO_AF_USART2); //GPIOD6����ΪUSART2
	
   //USART1�˿�����
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9; //GPIOD5��GPIOD6
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//���ù���
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//�ٶ�50MHz
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //���츴�����
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //����
   GPIO_Init(GPIOD,&GPIO_InitStructure); //��ʼ��PA9��PA10

   //USART1 ��ʼ������
   USART_InitStructure.USART_BaudRate = bound;//����������
   USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
   USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
   USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
   USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
   USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ
   USART_Init(USART3, &USART_InitStructure); //��ʼ������1
	
   USART_Cmd(USART3, ENABLE);  //ʹ�ܴ���1 
	
   USART_ClearFlag(USART3, USART_FLAG_TC);
	
   USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);//��������ж�

   //Usart1 NVIC ����

   NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;//����2�ж�ͨ��
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;//��ռ���ȼ�3
   NVIC_InitStructure.NVIC_IRQChannelSubPriority =3;		//�����ȼ�3
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
   NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ�����
}
///********************************************************************
//**����:HandleUart3Rcv
//**����:������3�յ��ı���
//********************************************************************/
//extern unsigned char RcvBuf[256];//���յ��ı��Ļ���
//static void HandleUart3Rcv(void)
//{
//   unsigned char TxBuff[100];//���ͻ���
//   unsigned char *pBuff;
//   uBYTE RcvDat1;//���յ���������1
//   uBYTE RcvDat2;//���յ���������2
////   uBYTE RcvDat3;//���յ���������3
////   uBYTE RcvDat4;//���յ���������4
//   switch(RcvBuf[0])
//	 {
//		 case 0x00:  //�ն˰汾��(��:68 00 03 18 12 20 4D 15)
//			    pBuff = TxBuff;//ָ���ʼ��   00
//			    *(pBuff++)  = 0x68;
//			    *(pBuff++)  = 0x00;
//			    *(pBuff++)  = 0x03;
//			    *(pBuff++)  = 0x18;//�ն˰汾��-��
//			    *(pBuff++)  = 0x12;//�ն˰汾��-��
//			    *(pBuff++)  = 0x26;//�ն˰汾��-��
//			    *pBuff  = GetCS(TxBuff+1,pBuff-TxBuff-1);
//			    pBuff++;
//			    *(pBuff++)  = 0x15;
//			    SendMsg(TxBuff,pBuff-TxBuff);
//		 		  break;
//		 case 0x01:
//			    break;
//		 case 0x11:
//			    RcvDat1.value = RcvBuf[2];
//			    RcvDat2.value = RcvBuf[3];
//			    if(0 == RcvDat1.BYTE.LL) //�ر���Դ���1
//					{
//						DY1 = DY_DISABLE;
//						pBuff = TxBuff;
//						*(pBuff++)  = 0x68;
//						*(pBuff++)  = 0x11;
//						*(pBuff++)  = 0x04;
//						*(pBuff++)  = 0xFC;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFF;
//						*pBuff  = GetCS(TxBuff+1,pBuff-TxBuff-1);
//						pBuff++;
//						*(pBuff++)  = 0x15;
//						SendMsg(TxBuff,pBuff-TxBuff);
//          }
//					if(1 == RcvDat1.BYTE.LL) //����Դ���1��[mark]�����ٸĽ�
//			    {
//						DY1 = DY_ENABLE;  //68 11 04 01 00 00 00 16 15
//						pBuff = TxBuff;
//						*(pBuff++)  = 0x68;
//						*(pBuff++)  = 0x11;
//						*(pBuff++)  = 0x04;
//						*(pBuff++)  = 0xFD;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFF;
//						*pBuff  = GetCS(TxBuff+1,pBuff-TxBuff-1);
//						pBuff++;
//						*(pBuff++)  = 0x15;
//						SendMsg(TxBuff,pBuff-TxBuff);						
//					}
//			    if(1 == RcvDat1.BYTE.LH) //����Դ���2��[mark]�����ٸĽ�
//					{
//						DY2 = DY_ENABLE;  //68 11 04 01 00 00 00 16 15
//						pBuff = TxBuff;
//						*(pBuff++)  = 0x68;
//						*(pBuff++)  = 0x11;
//						*(pBuff++)  = 0x04;
//						*(pBuff++)  = 0xF7;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFF;
//						*pBuff  = GetCS(TxBuff+1,pBuff-TxBuff-1);
//						pBuff++;
//						*(pBuff++)  = 0x15;
//						SendMsg(TxBuff,pBuff-TxBuff);
//          }
//					if(0 == RcvDat1.BYTE.LH) //�ر���Դ���2
//			    {
//						DY2 = DY_DISABLE;
//						pBuff = TxBuff;
//						*(pBuff++)  = 0x68;
//						*(pBuff++)  = 0x11;
//						*(pBuff++)  = 0x04;
//						*(pBuff++)  = 0xF3;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFF;
//						*pBuff  = GetCS(TxBuff+1,pBuff-TxBuff-1);
//						pBuff++;
//						*(pBuff++)  = 0x15;
//						SendMsg(TxBuff,pBuff-TxBuff);
//					}
//					///////////////
//			    if(1 == RcvDat1.BYTE.HL) //����Դ���3��[mark]�����ٸĽ�
//					{
//						DY3 = DY_ENABLE;  //68 11 04 01 00 00 00 16 15
//						pBuff = TxBuff;
//						*(pBuff++)  = 0x68;
//						*(pBuff++)  = 0x11;
//						*(pBuff++)  = 0x04;
//						*(pBuff++)  = 0xDF;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFF;
//						*pBuff  = GetCS(TxBuff+1,pBuff-TxBuff-1);
//						pBuff++;
//						*(pBuff++)  = 0x15;
//						SendMsg(TxBuff,pBuff-TxBuff);
//          }
//					if(0 == RcvDat1.BYTE.HL) //�ر���Դ���3
//			    {
//						DY3 = DY_DISABLE;
//						pBuff = TxBuff;
//						*(pBuff++)  = 0x68;
//						*(pBuff++)  = 0x11;
//						*(pBuff++)  = 0x04;
//						*(pBuff++)  = 0xCF;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFF;
//						*pBuff  = GetCS(TxBuff+1,pBuff-TxBuff-1);
//						pBuff++;
//						*(pBuff++)  = 0x15;
//						SendMsg(TxBuff,pBuff-TxBuff);
//					}	
//			    if(1 == RcvDat1.BYTE.HH) //����Դ���4��[mark]�����ٸĽ�
//					{
//						DY4 = DY_ENABLE;  //68 11 04 01 00 00 00 16 15
//						pBuff = TxBuff;
//						*(pBuff++)  = 0x68;
//						*(pBuff++)  = 0x11;
//						*(pBuff++)  = 0x04;
//						*(pBuff++)  = 0x7F;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFF;
//						*pBuff  = GetCS(TxBuff+1,pBuff-TxBuff-1);
//						pBuff++;
//						*(pBuff++)  = 0x15;
//						SendMsg(TxBuff,pBuff-TxBuff);
//          }
//					if(0 == RcvDat1.BYTE.HH) //�ر���Դ���4
//			    {
//						DY4 = DY_DISABLE;
//						pBuff = TxBuff;
//						*(pBuff++)  = 0x68;
//						*(pBuff++)  = 0x11;
//						*(pBuff++)  = 0x04;
//						*(pBuff++)  = 0x3F;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFF;
//						*pBuff  = GetCS(TxBuff+1,pBuff-TxBuff-1);
//						pBuff++;
//						*(pBuff++)  = 0x15;
//						SendMsg(TxBuff,pBuff-TxBuff);
//					}	
//			    if(1 == RcvDat2.BYTE.LL) //����Դ���4��[mark]�����ٸĽ�
//					{
//						DY5 = DY_ENABLE;  //68 11 04 01 00 00 00 16 15
//						pBuff = TxBuff;
//						*(pBuff++)  = 0x68;
//						*(pBuff++)  = 0x11;
//						*(pBuff++)  = 0x04;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFD;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFF;
//						*pBuff  = GetCS(TxBuff+1,pBuff-TxBuff-1);
//						pBuff++;
//						*(pBuff++)  = 0x15;
//						SendMsg(TxBuff,pBuff-TxBuff);
//          }
//					if(0 == RcvDat2.BYTE.LL) //�ر���Դ���4
//			    {
//						DY5 = DY_DISABLE;
//						pBuff = TxBuff;
//						*(pBuff++)  = 0x68;
//						*(pBuff++)  = 0x11;
//						*(pBuff++)  = 0x04;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFC;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFF;
//						*pBuff  = GetCS(TxBuff+1,pBuff-TxBuff-1);
//						pBuff++;
//						*(pBuff++)  = 0x15;
//						SendMsg(TxBuff,pBuff-TxBuff);
//					}								
//			    break;
//		 case 0x12://�̵���
//			    RcvDat1.value = RcvBuf[2];
//			    if(1 == RcvDat1.BYTE.LL) //�򿪼̵������1��[mark]�����ٸĽ�
//					{
//						DR1 = DR_ENABLE;  //68 11 04 01 00 00 00 16 15
//						pBuff = TxBuff;
//						*(pBuff++)  = 0x68;
//						*(pBuff++)  = 0x12;
//						*(pBuff++)  = 0x04;
//						*(pBuff++)  = 0xFD;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFF;
//						*pBuff  = GetCS(TxBuff+1,pBuff-TxBuff-1);
//						pBuff++;
//						*(pBuff++)  = 0x15;
//						SendMsg(TxBuff,pBuff-TxBuff);
//          }
//					if(0 == RcvDat1.BYTE.LL) //�رռ̵������1
//			    {
//						DR1 = DR_DISABLE;
//						pBuff = TxBuff;
//						*(pBuff++)  = 0x68;
//						*(pBuff++)  = 0x12;
//						*(pBuff++)  = 0x04;
//						*(pBuff++)  = 0xFC;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFF;
//						*pBuff  = GetCS(TxBuff+1,pBuff-TxBuff-1);
//						pBuff++;
//						*(pBuff++)  = 0x15;
//						SendMsg(TxBuff,pBuff-TxBuff);
//					}
//			    if(1 == RcvDat1.BYTE.LH) //�򿪼̵������2��[mark]�����ٸĽ�
//					{
//						DR2 = DR_ENABLE;  //68 11 04 01 00 00 00 16 15
//						pBuff = TxBuff;
//						*(pBuff++)  = 0x68;
//						*(pBuff++)  = 0x12;
//						*(pBuff++)  = 0x04;
//						*(pBuff++)  = 0xF7;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFF;
//						*pBuff  = GetCS(TxBuff+1,pBuff-TxBuff-1);
//						pBuff++;
//						*(pBuff++)  = 0x15;
//						SendMsg(TxBuff,pBuff-TxBuff);
//          }
//					if(0 == RcvDat1.BYTE.LH) //�رռ̵������2
//			    {
//						DR2 = DR_DISABLE;
//						pBuff = TxBuff;
//						*(pBuff++)  = 0x68;
//						*(pBuff++)  = 0x12;
//						*(pBuff++)  = 0x04;
//						*(pBuff++)  = 0xF3;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFF;
//						*pBuff  = GetCS(TxBuff+1,pBuff-TxBuff-1);
//						pBuff++;
//						*(pBuff++)  = 0x15;
//						SendMsg(TxBuff,pBuff-TxBuff);
//					}
//			    if(1 == RcvDat1.BYTE.HL) //�򿪼̵������3��[mark]�����ٸĽ�
//					{
//						DR3 = DR_ENABLE;  //68 11 04 01 00 00 00 16 15
//						pBuff = TxBuff;
//						*(pBuff++)  = 0x68;
//						*(pBuff++)  = 0x12;
//						*(pBuff++)  = 0x04;
//						*(pBuff++)  = 0xDF;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFF;
//						*pBuff  = GetCS(TxBuff+1,pBuff-TxBuff-1);
//						pBuff++;
//						*(pBuff++)  = 0x15;
//						SendMsg(TxBuff,pBuff-TxBuff);
//          }
//					if(0 == RcvDat1.BYTE.HL) //�رռ̵������3
//			    {
//						DR3 = DR_DISABLE;
//						pBuff = TxBuff;
//						*(pBuff++)  = 0x68;
//						*(pBuff++)  = 0x12;
//						*(pBuff++)  = 0x04;
//						*(pBuff++)  = 0xCF;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFF;
//						*(pBuff++)  = 0xFF;
//						*pBuff  = GetCS(TxBuff+1,pBuff-TxBuff-1);
//						pBuff++;
//						*(pBuff++)  = 0x15;
//						SendMsg(TxBuff,pBuff-TxBuff);
//					}						
//			    break;
//		 default: break;
//	 }
//}

///********************************************************************
//**����:USART3_IRQHandler
//**����:RS422�ں���λ��ͨ�ţ����ڽ����ж�
//********************************************************************/
//eRCVSTA RcvSta = Rcv_IDLE;//���ڽ���״̬
//unsigned char RcvBuf[256] = {0};//���յ��ı��Ļ���
//unsigned char RcvDat = 0;//���ν��յ����ַ�
//unsigned char RcvLen = 0;//�ѽ������������ĳ���
//void USART3_IRQHandler(void)
//{
//   if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)//���յ�����
//   {
//      RcvDat = USART_ReceiveData(USART3);//;��ȡ���յ�������USART2->DR
//		  switch(RcvSta)
//			{
//				case Rcv_IDLE://���տ���
//				case Rcv_HEAD://���ձ���ͷ
//					   if(0x68==RcvDat)
//						 {
//						    RcvSta = Rcv_AFN;
//                RcvLen = 0;
//						 }
//						 break;
//				case Rcv_AFN:   //���չ�����
//					   RcvBuf[0] = RcvDat;//��AFN
//				     RcvSta = Rcv_LEN;//״̬��ת
//				     break;
//				case Rcv_LEN:   //���ճ���
//					   RcvBuf[1] = RcvDat;//��AFN
//				     if(RcvDat) RcvSta = Rcv_DAT;//������������Ȳ�Ϊ0״̬��ת
//				     else    //����������ĳ���Ϊ0
//						 {
//				        RcvSta = Rcv_CS;//״̬��ת
//						 }
//				     break;
//				case Rcv_DAT:   //����������
//					   RcvLen++;
//					   RcvBuf[1+RcvLen] = RcvDat;
//						 if(RcvLen == RcvBuf[1])//�������
//						 {
//							 RcvSta = Rcv_CS;//״̬��ת
//						 }
//				     break;
//				case Rcv_CS:   //����У��
//					   if(RcvDat==GetCS(RcvBuf,RcvBuf[1]+2))//��У��ͨ��
//						 {
//							 RcvSta = Rcv_TILE;//״̬��ת
//						 }
//						 else  //У��δͨ��
//						 {
//							 RcvSta = Rcv_IDLE;//״̬��ת
//						 }
//				     break;
//				case Rcv_TILE://����β	
//					   if(0x15==RcvDat)//βУ��ͨ��
//						 {
//							 HandleUart3Rcv();//���ձ��Ĵ���
//						 }
//						 RcvSta = Rcv_IDLE;//״̬��ת				   
//				     break;
//				default: break;					
//			}
//   }
//}

/********************************************************************
**����:SendMsg()
**����:���ڷ��ͳ���
********************************************************************/
void SendMsg(unsigned char *pBuf,int len)
{
   while(len--)
	 {
      USART_SendData(USART3,*(pBuf++));
      while(USART_GetFlagStatus(USART3,USART_FLAG_TXE)!=SET) {;}
	 }
}

///********************************************************************
//**����:USART3_DMAInit
//**����:USART3DMA����
//**˵��:PIN96,PD8,USART3-TX
//       PIN97,PD9,USART3-RX
//**DMA: USART3-TXʹ��DMA��Դ(DMA1��������3��ͨ��4)
//**Ӳ�����ӣ���ʤΪ�����ߣ�:
//           1:��Ƭ��RX+  2:��Ƭ��RX-
//           3:��Ƭ��TX+  4:��Ƭ��TX-
//********************************************************************/
//void USART3_DMAInit()
//{
////   DMA_InitTypeDef  DMA_InitStructure; //DMA��������ʼ��
////   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1,ENABLE);//ʹ��DMAʱ��
////	
////	 while (DMA_GetCmdStatus(DMA1_Stream3) != DISABLE){}//�ȴ�DMA������(DMA1-������3)
////		 
////   DMA_InitStructure.DMA_Channel = DMA_Channel_4;//ͨ��4  ��[DMA_Channel_0,DMA_Channel_7]
////	 //DMA_SetCurrDataCounter()����DMAһ�δ�������               
////   DMA_InitStructure.DMA_PeripheralBaseAddr = USART3->DR;//�����ַ
////	 
////	 DMA_Init(DMA1_Stream3,&DMA_InitStructure);//DMA1-ͨ��3��ʼ��
//}

