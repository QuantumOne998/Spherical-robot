#ifndef __RS422_H
#define __RS422_H
#include "basic.h"
//typedef enum
//{
//	 Rcv_IDLE, //接收空闲
//   Rcv_HEAD, //接收报文头
//   Rcv_AFN,  //接收功能码
//	 Rcv_LEN,  //接收长度
//	 Rcv_DAT,  //接收数据项
//	 Rcv_CS,   //接收校验
//	 Rcv_TILE, //接收尾
//}eRCVSTA;    //串口接收

void RS422_Init(u32 bound);//初始化RS422口通信
void SendMsg(unsigned char *pBuf,int len);//串口发送程序

#endif

