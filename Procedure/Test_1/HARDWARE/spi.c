#include "spi.h"
volatile uint32_t TIMEOUT=LONG_TIMEOUT;
/********************************************************************
**����:SPI2Init
**����:��ʼ��
**˵��:SPI2Init
       SDI------pin95---PB15---SPI2MOSI
			 SDO------pin94---PB14---SPI2MISO
			 SCK------pin93---PB13---SPI2SCK
			 CS1------pin106--PG2
			 CS2------pin107--PG3  first
			 FAULT----pin85---PH8
			 DRDY-----pin86---PH9
			 
			 256��Ƶ����Լ2.7΢��
********************************************************************/
void SPI2Init(void)
{
   GPIO_InitTypeDef GPIOIni;
   SPI_InitTypeDef  SPIIni;
	
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);//config SPI pins: SDI SDO SCK
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG,ENABLE);//config SPI pins: CS1 CS2
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH,ENABLE);//config SPI pins: FAULT DRDY
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2,ENABLE);
	
   GPIO_PinAFConfig(GPIOB,GPIO_PinSource15,GPIO_AF_SPI2);//MOSI
   GPIO_PinAFConfig(GPIOB,GPIO_PinSource14,GPIO_AF_SPI2);//MISO 
   GPIO_PinAFConfig(GPIOB,GPIO_PinSource13,GPIO_AF_SPI2);//SCK

   GPIOIni.GPIO_Pin = GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;//config SPI pins:SCK MISO MOSI
	 GPIOIni.GPIO_Mode = GPIO_Mode_AF;
   GPIOIni.GPIO_OType = GPIO_OType_PP;
	 GPIOIni.GPIO_PuPd = GPIO_PuPd_NOPULL;
	 GPIOIni.GPIO_Speed = GPIO_Speed_50MHz;
	 GPIO_Init(GPIOB,&GPIOIni);

   GPIOIni.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3;//config SPI pins: CS1 CS2
	 GPIOIni.GPIO_Mode = GPIO_Mode_OUT;
   GPIOIni.GPIO_OType = GPIO_OType_PP;
	 GPIOIni.GPIO_PuPd = GPIO_PuPd_NOPULL;
	 GPIOIni.GPIO_Speed = GPIO_Speed_50MHz;
	 GPIO_Init(GPIOG,&GPIOIni);
	 
   GPIO_SetBits(GPIOB,GPIO_Pin_14|GPIO_Pin_15);//MISO MOSI
   GPIO_ResetBits(GPIOB,GPIO_Pin_13);//SCK
   GPIO_SetBits(GPIOG,GPIO_Pin_2);//CS1
	 GPIO_SetBits(GPIOG,GPIO_Pin_3);//CS2
	 
	 SPIIni.SPI_Direction = SPI_Direction_2Lines_FullDuplex;//��
	 SPIIni.SPI_CPHA = SPI_CPHA_2Edge;//��ʱ����λѡ�񣬵�2��ʱ�������ز�������
	 SPIIni.SPI_CPOL = SPI_CPOL_Low;//��ʱ�Ӽ���ѡ��,����ʱʱ��Ϊ�ߵ�ƽ
	 SPIIni.SPI_Mode = SPI_Mode_Master;//��,����ѡ��
	 SPIIni.SPI_DataSize = SPI_DataSize_8b;
	 SPIIni.SPI_NSS = SPI_NSS_Soft;//NSS���������
	 SPIIni.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_8;//Ԥ��Ƶ8
	 SPIIni.SPI_FirstBit = SPI_FirstBit_MSB;//��λ�ȴ�
	 SPIIni.SPI_CRCPolynomial = 7;
	 SPI_Init(SPI2,&SPIIni);
	 
   SPI_Cmd(SPI2,ENABLE);
}

//SPIд(0�ɹ�,1��ʱʧ��)
unsigned char SPI_Write(unsigned char *buffer,unsigned char nBytes)
{
   unsigned char i;
   for(i=0;i<nBytes;i++)
   {
      TIMEOUT=LONG_TIMEOUT;
      while(SPI_I2S_GetFlagStatus(SPI2,SPI_I2S_FLAG_TXE)==RESET)
			{
			   if((TIMEOUT--) == 0) return (1);
			}
			SPI_I2S_SendData(SPI2,buffer[i]);
			TIMEOUT=LONG_TIMEOUT;
			while(SPI_I2S_GetFlagStatus(SPI2,SPI_I2S_FLAG_RXNE)==RESET)
			{
				 if((TIMEOUT--) == 0) return (1);
			}
			SPI_I2S_ReceiveData(SPI2);
   }
	 return (0);
}

//SPI��,(0�ɹ�,1��ʱʧ��)
unsigned char SPI_Read(unsigned char *buffer,unsigned char nBytes)
{
   unsigned char i;
   SPI_I2S_ReceiveData(SPI2);
	 for(i=0;i<nBytes;i++)
   {
      TIMEOUT=LONG_TIMEOUT;
      while(SPI_I2S_GetFlagStatus(SPI2,SPI_I2S_FLAG_TXE)==RESET)
      {
			   if((TIMEOUT--) == 0) return (1);
      }
      SPI_I2S_SendData(SPI2,0x00);
      TIMEOUT=LONG_TIMEOUT;
      while(SPI_I2S_GetFlagStatus(SPI2,SPI_I2S_FLAG_RXNE)==RESET)
      {
				 if((TIMEOUT--) == 0) return (1);
      }
			buffer[i] = SPI_I2S_ReceiveData(SPI2);
	 }
	 return (0);
}

//SPIд�ֽ�(0�ɹ�,1��ʱʧ��)
unsigned char SPI_WriteByte(unsigned char dat)
{
   TIMEOUT=LONG_TIMEOUT;
   while(SPI_I2S_GetFlagStatus(SPI2,SPI_I2S_FLAG_TXE)==RESET)
   {
      if((TIMEOUT--) == 0) return (1);
   }
   SPI_I2S_SendData(SPI2,dat);
   TIMEOUT=LONG_TIMEOUT;
   while(SPI_I2S_GetFlagStatus(SPI2,SPI_I2S_FLAG_RXNE)==RESET)
   {
      if((TIMEOUT--) == 0) return (1);
   }
   SPI_I2S_ReceiveData(SPI2);
	 SPI_I2S_ReceiveData(SPI2);
   return (0);
}

//SPI���ֽ�(0�ɹ�,1��ʱʧ��)
unsigned char SPI_ReadByte(void)
{
   SPI_I2S_ReceiveData(SPI2);
   while(SPI_I2S_GetFlagStatus(SPI2,SPI_I2S_FLAG_TXE)==RESET);
   SPI_I2S_SendData(SPI2,0x00);
	 while(SPI_I2S_GetFlagStatus(SPI2,SPI_I2S_FLAG_RXNE)==RESET);
	 return (SPI_I2S_ReceiveData(SPI2));
}
