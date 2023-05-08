#include "rs422.h"

/********************************************************************
**名称:RS422_U3_Init
**功能:初始化RS422口通信
**说明:PIN96,PD8,USART2-TX
       PIN97,PD9,USART2-RX
**硬件连接（和胜为串口线）:
           1:单片机RX+  2:单片机RX-
           3:单片机TX+  4:单片机TX-
********************************************************************/
void RS422_Init(u32 bound)//初始化RS422口通信
{
   GPIO_InitTypeDef GPIO_InitStructure;
   USART_InitTypeDef USART_InitStructure;
   NVIC_InitTypeDef NVIC_InitStructure;
	
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE); //使能GPIOD时钟
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);//使能USART2时钟
 
   //串口3对应引脚复用映射
   GPIO_PinAFConfig(GPIOD,GPIO_PinSource8,GPIO_AF_USART2); //GPIOD5复用为USART2
   GPIO_PinAFConfig(GPIOD,GPIO_PinSource9,GPIO_AF_USART2); //GPIOD6复用为USART2
	
   //USART1端口配置
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9; //GPIOD5与GPIOD6
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用功能
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//速度50MHz
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //推挽复用输出
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //上拉
   GPIO_Init(GPIOD,&GPIO_InitStructure); //初始化PA9，PA10

   //USART1 初始化设置
   USART_InitStructure.USART_BaudRate = bound;//波特率设置
   USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
   USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
   USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
   USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
   USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式
   USART_Init(USART3, &USART_InitStructure); //初始化串口1
	
   USART_Cmd(USART3, ENABLE);  //使能串口1 
	
   USART_ClearFlag(USART3, USART_FLAG_TC);
	
   USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);//开启相关中断

   //Usart1 NVIC 配置

   NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;//串口2中断通道
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;//抢占优先级3
   NVIC_InitStructure.NVIC_IRQChannelSubPriority =3;		//子优先级3
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
   NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器、
}
///********************************************************************
//**名称:HandleUart3Rcv
//**功能:处理串口3收到的报文
//********************************************************************/
//extern unsigned char RcvBuf[256];//接收到的报文缓存
//static void HandleUart3Rcv(void)
//{
//   unsigned char TxBuff[100];//发送缓存
//   unsigned char *pBuff;
//   uBYTE RcvDat1;//接收到的数据区1
//   uBYTE RcvDat2;//接收到的数据区2
////   uBYTE RcvDat3;//接收到的数据区3
////   uBYTE RcvDat4;//接收到的数据区4
//   switch(RcvBuf[0])
//	 {
//		 case 0x00:  //终端版本号(例:68 00 03 18 12 20 4D 15)
//			    pBuff = TxBuff;//指针初始化   00
//			    *(pBuff++)  = 0x68;
//			    *(pBuff++)  = 0x00;
//			    *(pBuff++)  = 0x03;
//			    *(pBuff++)  = 0x18;//终端版本号-年
//			    *(pBuff++)  = 0x12;//终端版本号-月
//			    *(pBuff++)  = 0x26;//终端版本号-日
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
//			    if(0 == RcvDat1.BYTE.LL) //关闭有源输出1
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
//					if(1 == RcvDat1.BYTE.LL) //打开有源输出1，[mark]可以再改进
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
//			    if(1 == RcvDat1.BYTE.LH) //打开有源输出2，[mark]可以再改进
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
//					if(0 == RcvDat1.BYTE.LH) //关闭有源输出2
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
//			    if(1 == RcvDat1.BYTE.HL) //打开有源输出3，[mark]可以再改进
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
//					if(0 == RcvDat1.BYTE.HL) //关闭有源输出3
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
//			    if(1 == RcvDat1.BYTE.HH) //打开有源输出4，[mark]可以再改进
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
//					if(0 == RcvDat1.BYTE.HH) //关闭有源输出4
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
//			    if(1 == RcvDat2.BYTE.LL) //打开有源输出4，[mark]可以再改进
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
//					if(0 == RcvDat2.BYTE.LL) //关闭有源输出4
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
//		 case 0x12://继电器
//			    RcvDat1.value = RcvBuf[2];
//			    if(1 == RcvDat1.BYTE.LL) //打开继电器输出1，[mark]可以再改进
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
//					if(0 == RcvDat1.BYTE.LL) //关闭继电器输出1
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
//			    if(1 == RcvDat1.BYTE.LH) //打开继电器输出2，[mark]可以再改进
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
//					if(0 == RcvDat1.BYTE.LH) //关闭继电器输出2
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
//			    if(1 == RcvDat1.BYTE.HL) //打开继电器输出3，[mark]可以再改进
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
//					if(0 == RcvDat1.BYTE.HL) //关闭继电器输出3
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
//**名称:USART3_IRQHandler
//**功能:RS422口和上位机通信，串口接收中断
//********************************************************************/
//eRCVSTA RcvSta = Rcv_IDLE;//串口接收状态
//unsigned char RcvBuf[256] = {0};//接收到的报文缓存
//unsigned char RcvDat = 0;//本次接收到的字符
//unsigned char RcvLen = 0;//已接收数据区报文长度
//void USART3_IRQHandler(void)
//{
//   if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)//接收到数据
//   {
//      RcvDat = USART_ReceiveData(USART3);//;读取接收到的数据USART2->DR
//		  switch(RcvSta)
//			{
//				case Rcv_IDLE://接收空闲
//				case Rcv_HEAD://接收报文头
//					   if(0x68==RcvDat)
//						 {
//						    RcvSta = Rcv_AFN;
//                RcvLen = 0;
//						 }
//						 break;
//				case Rcv_AFN:   //接收功能码
//					   RcvBuf[0] = RcvDat;//存AFN
//				     RcvSta = Rcv_LEN;//状态跳转
//				     break;
//				case Rcv_LEN:   //接收长度
//					   RcvBuf[1] = RcvDat;//存AFN
//				     if(RcvDat) RcvSta = Rcv_DAT;//如果数据区长度不为0状态跳转
//				     else    //如果数据区的长度为0
//						 {
//				        RcvSta = Rcv_CS;//状态跳转
//						 }
//				     break;
//				case Rcv_DAT:   //接收数据项
//					   RcvLen++;
//					   RcvBuf[1+RcvLen] = RcvDat;
//						 if(RcvLen == RcvBuf[1])//接收完成
//						 {
//							 RcvSta = Rcv_CS;//状态跳转
//						 }
//				     break;
//				case Rcv_CS:   //接收校验
//					   if(RcvDat==GetCS(RcvBuf,RcvBuf[1]+2))//和校验通过
//						 {
//							 RcvSta = Rcv_TILE;//状态跳转
//						 }
//						 else  //校验未通过
//						 {
//							 RcvSta = Rcv_IDLE;//状态跳转
//						 }
//				     break;
//				case Rcv_TILE://接收尾	
//					   if(0x15==RcvDat)//尾校验通过
//						 {
//							 HandleUart3Rcv();//接收报文处理
//						 }
//						 RcvSta = Rcv_IDLE;//状态跳转				   
//				     break;
//				default: break;					
//			}
//   }
//}

/********************************************************************
**名称:SendMsg()
**功能:串口发送程序
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
//**名称:USART3_DMAInit
//**功能:USART3DMA传输
//**说明:PIN96,PD8,USART3-TX
//       PIN97,PD9,USART3-RX
//**DMA: USART3-TX使用DMA资源(DMA1，数据流3，通道4)
//**硬件连接（和胜为串口线）:
//           1:单片机RX+  2:单片机RX-
//           3:单片机TX+  4:单片机TX-
//********************************************************************/
//void USART3_DMAInit()
//{
////   DMA_InitTypeDef  DMA_InitStructure; //DMA数据流初始化
////   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1,ENABLE);//使能DMA时钟
////	
////	 while (DMA_GetCmdStatus(DMA1_Stream3) != DISABLE){}//等待DMA可配置(DMA1-数据流3)
////		 
////   DMA_InitStructure.DMA_Channel = DMA_Channel_4;//通道4  ∈[DMA_Channel_0,DMA_Channel_7]
////	 //DMA_SetCurrDataCounter()设置DMA一次传输数量               
////   DMA_InitStructure.DMA_PeripheralBaseAddr = USART3->DR;//外设地址
////	 
////	 DMA_Init(DMA1_Stream3,&DMA_InitStructure);//DMA1-通道3初始化
//}

