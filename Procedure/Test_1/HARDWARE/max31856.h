#ifndef __MAX31856_H
#define __MAX31856_H
#include "basic.h"

void Max31856Init(void);//初始化
void Max31856_CS1_Write(unsigned char Add,unsigned char Dat);
void Max31856_CS2_Write(unsigned char Add,unsigned char Dat);
unsigned char Max31856_CS1_Read(unsigned char Add);
unsigned char Max31856_CS2_Read(unsigned char Add);
unsigned char DRDY_pin_Value(void);//获取数据是否准备好
unsigned char FAULT_pin_Value(void);//获取故障引脚状态
void StartConvert2(void);//开始转换
void StopConvert2(void);//停止转换
unsigned char Max31856_CS1_ReadnByte(unsigned char Add,unsigned char *pBuf,unsigned char nBytes);
unsigned char Max31856_CS2_ReadnByte(unsigned char Add,unsigned char *pBuf,unsigned char nBytes);
#endif
