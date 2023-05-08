#ifndef __MAX31856_H
#define __MAX31856_H
#include "basic.h"

void Max31856Init(void);//��ʼ��
void Max31856_CS1_Write(unsigned char Add,unsigned char Dat);
void Max31856_CS2_Write(unsigned char Add,unsigned char Dat);
unsigned char Max31856_CS1_Read(unsigned char Add);
unsigned char Max31856_CS2_Read(unsigned char Add);
unsigned char DRDY_pin_Value(void);//��ȡ�����Ƿ�׼����
unsigned char FAULT_pin_Value(void);//��ȡ��������״̬
void StartConvert2(void);//��ʼת��
void StopConvert2(void);//ֹͣת��
unsigned char Max31856_CS1_ReadnByte(unsigned char Add,unsigned char *pBuf,unsigned char nBytes);
unsigned char Max31856_CS2_ReadnByte(unsigned char Add,unsigned char *pBuf,unsigned char nBytes);
#endif
