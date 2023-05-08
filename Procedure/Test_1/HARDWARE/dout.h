#ifndef __DOUT_H
#define __DOUT_H
#include "sys.h"

//��Դ���״̬����
#define DY_ENABLE  1
#define DY_DISABLE 0

//��Դ���λ������
#define DY1 PDout(7)	// ��Դ���1
#define DY2 PGout(9)	// ��Դ���2	 
#define DY3 PGout(10)	// ��Դ���3
#define DY4 PGout(12)	// ��Դ���4 
#define DY5 PGout(15)	// ��Դ���5

//�ɽӵ����
#define GJD1 PEout(10)	// �ɽӵ����1
#define GJD2 PEout(11)	// �ɽӵ����2
#define GJD3 PEout(12)	// �ɽӵ����3

//���¼��оƬ����
#define Switch_A0 PFout(15)	
#define Switch_A1 PGout(0)	
#define Switch_A2 PGout(1)	

#define LEDON  GPIO_ResetBits(GPIOA,GPIO_Pin_0);//����
#define LEDOFF  GPIO_SetBits(GPIOA,GPIO_Pin_0);//�ص�
#define LEDTOGGLE GPIO_ToggleBits(GPIOA,GPIO_Pin_0);//��ת

#define RUN_LEDON  GPIO_ResetBits(GPIOB,GPIO_Pin_6);//����
#define RUN_LEDOFF  GPIO_SetBits(GPIOB,GPIO_Pin_6);//�ص�
#define RUN_LEDTOGGLE GPIO_ToggleBits(GPIOB,GPIO_Pin_6);//��ת


void Dout_LED_Init(void);//��Դ���1��ʼ��	
void Dout_Y1_Init(void);//��Դ���1��ʼ��	
void Dout_Y2_Init(void);//��Դ���2��ʼ��	
void Dout_Y3_Init(void);//��Դ���3��ʼ��	
void Dout_Y4_Init(void);//��Դ���4��ʼ��
void Dout_Y5_Init(void);//��Դ���4��ʼ��

void GJD_out(void);     //�ɽӵ����
void Run_LED_Init(void);//����ָʾ�Ƴ�ʼ��

void rs422_init(void);
void Switch_Init(void);
#endif
