#ifndef __ADC_H
#define __ADC_H
#include "sys.h"

void Adc_LT1_Init(void);//����_1
//void Adc_LT5_Init(void);//����_5
void Adc_O1_Init(void); //ģ���ѹ_1
void Adc_O2_Init(void); //ģ���ѹ_2
void Adc_O3_Init(void); //ģ���ѹ_3
void Adc_O4_Init(void); //ģ���ѹ_4
void Adc_O5_Init(void); //ģ���ѹ_5
void Adc_A1_Init(void); //4-20mA����_1
void Adc_A2_Init(void); //4-20mA����_2
void Adc_A3_Init(void); //4-20mA����_3
u16 Get_Adc(ADC_TypeDef *ADCx,u8 ch);

#endif
