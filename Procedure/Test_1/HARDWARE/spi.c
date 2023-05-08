#include "spi.h"
volatile uint32_t TIMEOUT=LONG_TIMEOUT;
/********************************************************************
**名称:SPI2Init
**功能:初始化
**说明:SPI2Init
       SDI------pin95---PB15---SPI2MOSI
			 SDO------pin94---PB14---SPI2MISO
			 SCK------pin93---PB13---SPI2SCK
			 CS1------pin106--PG2
			 CS2------pin107--PG3  first
			 FAULT----pin85---PH8
			 DRDY-----pin86---PH9
			 
			 256分频脉宽约2.7微秒
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
	 
	 SPIIni.SPI_Direction = SPI_Direction_2Lines_FullDuplex;//√
	 SPIIni.SPI_CPHA = SPI_CPHA_2Edge;//√时钟相位选择，第2个时钟跳边沿采样数据
	 SPIIni.SPI_CPOL = SPI_CPOL_Low;//√时钟极性选择,空闲时时钟为高电平
	 SPIIni.SPI_Mode = SPI_Mode_Master;//√,主从选择
	 SPIIni.SPI_DataSize = SPI_DataSize_8b;
	 SPIIni.SPI_NSS = SPI_NSS_Soft;//NSS由软件控制
	 SPIIni.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_8;//预分频8
	 SPIIni.SPI_FirstBit = SPI_FirstBit_MSB;//高位先传
	 SPIIni.SPI_CRCPolynomial = 7;
	 SPI_Init(SPI2,&SPIIni);
	 
   SPI_Cmd(SPI2,ENABLE);
}

//SPI写(0成功,1超时失败)
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

//SPI读,(0成功,1超时失败)
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

//SPI写字节(0成功,1超时失败)
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

//SPI读字节(0成功,1超时失败)
unsigned char SPI_ReadByte(void)
{
   SPI_I2S_ReceiveData(SPI2);
   while(SPI_I2S_GetFlagStatus(SPI2,SPI_I2S_FLAG_TXE)==RESET);
   SPI_I2S_SendData(SPI2,0x00);
	 while(SPI_I2S_GetFlagStatus(SPI2,SPI_I2S_FLAG_RXNE)==RESET);
	 return (SPI_I2S_ReceiveData(SPI2));
}
