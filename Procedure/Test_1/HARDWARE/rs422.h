#ifndef __RS422_H
#define __RS422_H
#include "basic.h"
//typedef enum
//{
//	 Rcv_IDLE, //���տ���
//   Rcv_HEAD, //���ձ���ͷ
//   Rcv_AFN,  //���չ�����
//	 Rcv_LEN,  //���ճ���
//	 Rcv_DAT,  //����������
//	 Rcv_CS,   //����У��
//	 Rcv_TILE, //����β
//}eRCVSTA;    //���ڽ���

void RS422_Init(u32 bound);//��ʼ��RS422��ͨ��
void SendMsg(unsigned char *pBuf,int len);//���ڷ��ͳ���

#endif

