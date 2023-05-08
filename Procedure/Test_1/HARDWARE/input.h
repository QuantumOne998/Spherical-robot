#ifndef __INPUT_H
#define __INPUT_H
//#include "input.h"
#include "sys.h"

#define D_1  PDin(2)	// 有源输入1
#define D_2  PDin(6)	// 有源输入2
#define D_3  PDin(3)	// 有源输入3
#define D_4  PDin(4)	// 有源输入4
#define D_5  PDin(7)	// 有源输入3
#define D_6  PDin(15)	
#define D_7  PDin(0)	
#define D_8  PDin(2)	
#define D_9  PDin(3)	
#define D_10 PDin(1)	


void in_D_1_Init(void);
void in_D_2_Init(void);
void in_D_3_Init(void);
void in_D_4_Init(void);
void in_D_5_Init(void);
	
void in_D_6_Init(void);
void in_D_7_Init(void);
void in_D_8_Init(void);
void in_D_9_Init(void);
void in_D_10_Init(void);

//void TIM1_CH4_Cap_Init(u32 arr,u16 psc);

void TIM2_CH3_Cap_Init(u32 arr,u16 psc);
void TIM4_CH2_Cap_Init(u32 arr,u16 psc);

#endif

