#ifndef __DOUT_H
#define __DOUT_H
#include "sys.h"

//有源输出状态定义
#define DY_ENABLE  1
#define DY_DISABLE 0

//有源输出位带定义
#define DY1 PDout(7)	// 有源输出1
#define DY2 PGout(9)	// 有源输出2	 
#define DY3 PGout(10)	// 有源输出3
#define DY4 PGout(12)	// 有源输出4 
#define DY5 PGout(15)	// 有源输出5

//干接点输出
#define GJD1 PEout(10)	// 干接点输出1
#define GJD2 PEout(11)	// 干接点输出2
#define GJD3 PEout(12)	// 干接点输出3

//高温检测芯片控制
#define Switch_A0 PFout(15)	
#define Switch_A1 PGout(0)	
#define Switch_A2 PGout(1)	

#define LEDON  GPIO_ResetBits(GPIOA,GPIO_Pin_0);//开灯
#define LEDOFF  GPIO_SetBits(GPIOA,GPIO_Pin_0);//关灯
#define LEDTOGGLE GPIO_ToggleBits(GPIOA,GPIO_Pin_0);//翻转

#define RUN_LEDON  GPIO_ResetBits(GPIOB,GPIO_Pin_6);//开灯
#define RUN_LEDOFF  GPIO_SetBits(GPIOB,GPIO_Pin_6);//关灯
#define RUN_LEDTOGGLE GPIO_ToggleBits(GPIOB,GPIO_Pin_6);//翻转


void Dout_LED_Init(void);//有源输出1初始化	
void Dout_Y1_Init(void);//有源输出1初始化	
void Dout_Y2_Init(void);//有源输出2初始化	
void Dout_Y3_Init(void);//有源输出3初始化	
void Dout_Y4_Init(void);//有源输出4初始化
void Dout_Y5_Init(void);//有源输出4初始化

void GJD_out(void);     //干接点输出
void Run_LED_Init(void);//运行指示灯初始化

void rs422_init(void);
void Switch_Init(void);
#endif
