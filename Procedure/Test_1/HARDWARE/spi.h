#ifndef __SPI_H
#define __SPI_H
#include "basic.h"

#define FLAG_TIMEOUT  ((uint32_t)0x1000)
#define LONG_TIMEOUT  ((uint32_t)(10*FLAG_TIMEOUT))
#define SPI_CS1_EN    GPIO_ResetBits(GPIOG,GPIO_Pin_2);//CS1
#define SPI_CS1_DIS   GPIO_SetBits(GPIOG,GPIO_Pin_2);//CS1
#define SPI_CS2_EN    GPIO_ResetBits(GPIOG,GPIO_Pin_3);//CS2
#define SPI_CS2_DIS   GPIO_SetBits(GPIOG,GPIO_Pin_3);//CS2

void SPI2Init(void);//��ʼ��
unsigned char SPI_Write(unsigned char *buffer,unsigned char nBytes);//SPIд(0�ɹ�,1��ʱʧ��)
unsigned char SPI_Read(unsigned char *buffer,unsigned char nBytes);//SPI��(0�ɹ�,1��ʱʧ��)
unsigned char SPI_WriteByte(unsigned char dat);//SPIд�ֽ�(0�ɹ�,1��ʱʧ��)
unsigned char SPI_ReadByte(void);//SPI���ֽ�(0�ɹ�,1��ʱʧ��)

#endif
