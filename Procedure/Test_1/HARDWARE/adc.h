#ifndef __ADC_H
#define __ADC_H
#include "sys.h"

void Adc_LT1_Init(void);//高温_1
//void Adc_LT5_Init(void);//低温_5
void Adc_O1_Init(void); //模拟电压_1
void Adc_O2_Init(void); //模拟电压_2
void Adc_O3_Init(void); //模拟电压_3
void Adc_O4_Init(void); //模拟电压_4
void Adc_O5_Init(void); //模拟电压_5
void Adc_A1_Init(void); //4-20mA电流_1
void Adc_A2_Init(void); //4-20mA电流_2
void Adc_A3_Init(void); //4-20mA电流_3
u16 Get_Adc(ADC_TypeDef *ADCx,u8 ch);

#endif
