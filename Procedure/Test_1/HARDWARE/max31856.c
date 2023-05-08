#include "max31856.h"
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
			 DRDY-----pin86---PH9  �͵�ƽʱ����׼������
			 
			 256��Ƶ����Լ2.7΢��
********************************************************************/

//��DRDY����Ϊ����
static void Set_DRDY_pin_INPUT(void)
{
   GPIO_InitTypeDef GPIO_Ini;
   GPIO_Ini.GPIO_Pin = GPIO_Pin_9;
   GPIO_Ini.GPIO_Speed = GPIO_Speed_50MHz;
	 GPIO_Ini.GPIO_Mode = GPIO_Mode_IN;
	 GPIO_Init(GPIOH,&GPIO_Ini);
}

//��FAULT����Ϊ����
static void Set_FAULT_pin_INPUT(void)
{
   GPIO_InitTypeDef GPIO_Ini;
   GPIO_Ini.GPIO_Pin = GPIO_Pin_8;
   GPIO_Ini.GPIO_Speed = GPIO_Speed_50MHz;
	 GPIO_Ini.GPIO_Mode = GPIO_Mode_IN;
	 GPIO_Init(GPIOH,&GPIO_Ini);
}


//��ȡDRDY��ֵ
//0-�����Ѿ���
unsigned char DRDY_pin_Value(void)
{
   return(GPIO_ReadInputDataBit(GPIOH,GPIO_Pin_9));
}

unsigned char FAULT_pin_Value(void)
{
   return(GPIO_ReadInputDataBit(GPIOH,GPIO_Pin_8));
}

//д31856�Ĵ���
void Max31856_CS1_Write(unsigned char Add,unsigned char Dat)
{
   SPI_CS1_EN;
   SPI_WriteByte(Add);
   SPI_WriteByte(Dat);
	 SPI_CS1_DIS;
}

//д31856�Ĵ���
void Max31856_CS2_Write(unsigned char Add,unsigned char Dat)
{
   SPI_CS2_EN;
   SPI_WriteByte(Add);
   SPI_WriteByte(Dat);
	 SPI_CS2_DIS;
}

//��31856�Ĵ���
unsigned char Max31856_CS1_Read(unsigned char Add)
{
   unsigned char Dat;
   SPI_CS1_EN;
   SPI_WriteByte(Add);
   Dat = SPI_ReadByte();
	 SPI_CS1_DIS;
   return  Dat;
}

//��31856�Ĵ���
unsigned char Max31856_CS2_Read(unsigned char Add)
{
   unsigned char Dat;
   SPI_CS2_EN;
   SPI_WriteByte(Add);
   Dat = SPI_ReadByte();
	 SPI_CS2_DIS;
   return  Dat;
}

//��31856�Ĵ��� ����ֽ�һ���
unsigned char Max31856_CS1_ReadnByte(unsigned char Add,unsigned char *pBuf,unsigned char nBytes)
{
   unsigned char Dat;
   SPI_CS1_EN;
   SPI_WriteByte(Add);
   SPI_Read(pBuf,nBytes);
	 SPI_CS1_DIS;
   return  Dat;
}

//��31856�Ĵ��� ����ֽ�һ���
unsigned char Max31856_CS2_ReadnByte(unsigned char Add,unsigned char *pBuf,unsigned char nBytes)
{
   unsigned char Dat;
   SPI_CS2_EN;
   SPI_WriteByte(Add);//m
   SPI_Read(pBuf,nBytes);
	 SPI_CS2_DIS;
   return  Dat;
}

//��ʼת��
void StartConvert2(void)
{
   unsigned char RegTmp;
   RegTmp = Max31856_CS2_Read(0x00);
   RegTmp &= 0x3F;
   RegTmp |= 0x40;//ִ��һ����˺��ȵ�żת��
   Max31856_CS2_Write(0x80,RegTmp);   
}

//ֹͣת��
void StopConvert2(void)
{
   unsigned char RegTmp = 0;
	 RegTmp = Max31856_CS2_Read(0x00);
	 RegTmp &= 0x3F;
   Max31856_CS2_Write(0x80,RegTmp);
}
//��ʼ��
void Max31856Init(void)//��ʼ���ȵ�ż
{
	 unsigned char Reg[16] = {0,0,0,0x7F,0xC0,0x7F,0xFF,0x80,0,0,0,0,0,0,0,0};
   SPI2Init();//SPI��ʼ��
   Set_DRDY_pin_INPUT();//����׼���ų�ʼ��
   Set_FAULT_pin_INPUT();//��FAULT����Ϊ����
   
	 Reg[0] |= (0x10);//|(0x01); //OCFAULT���߼�⣬
	 Max31856_CS1_Write(0x80,Reg[0]);
	 Max31856_CS1_Write(0x82,Reg[2]); 	 

	 Max31856_CS1_Write(0x83,Reg[3]);
	 Max31856_CS1_Write(0x84,Reg[4]); 
	 Max31856_CS1_Write(0x85,Reg[5]);
	 Max31856_CS1_Write(0x86,Reg[6]); 
	 Max31856_CS1_Write(0x87,Reg[7]);
	 Max31856_CS1_Write(0x88,Reg[8]); 
	 Max31856_CS1_Write(0x89,Reg[9]);
	 Max31856_CS1_Write(0x8A,Reg[10]); 
	 Max31856_CS1_Write(0x8B,Reg[11]);
}
