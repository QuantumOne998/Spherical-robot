#include "adc.h"

/********************************************************************
**����:Adc_HT1_Init
**����:���¼��1,��ʼ��
**��Դ:1.MCU-----PF3,ADC3-IN9,
       2.Ӳ��----K���ȵ�ż
			 3.ԭ��ͼ--LT1
**ԭ��:���ù���ͨ���ĵ���ת��
********************************************************************/
void Adc_LT1_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;//�˿ڳ�ʼ��
   ADC_CommonInitTypeDef ADC_CommonInitStructure;//
   ADC_InitTypeDef       ADC_InitStructure;
	
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//ʹ�ܶ˿�ʱ��
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE); //ʹ��ADC3ʱ��
	
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;//����
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;//ģ������
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//��������
   GPIO_Init(GPIOF, &GPIO_InitStructure);//��ʼ���˿�
	
   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,ENABLE);	  //ADC3��λ
   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,DISABLE);	  //��λ����	 
 
   ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;//����ģʽ
   ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;//���������׶�֮����ӳ�5��ʱ��
   ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled; //DMAʧ��
   ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div4;//Ԥ��Ƶ4��Ƶ��ADCCLK=PCLK2/4=84/4=21Mhz,ADCʱ����ò�Ҫ����36Mhz 
   ADC_CommonInit(&ADC_CommonInitStructure);//��ʼ��
	
   ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;//12λģʽ
   ADC_InitStructure.ADC_ScanConvMode = DISABLE;//��ɨ��ģʽ	
   ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;//�ر�����ת��
   ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;//��ֹ������⣬ʹ���������
   ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//�Ҷ���	
   ADC_InitStructure.ADC_NbrOfConversion = 1;//�������еĳ��ȣ�1��ת���ڹ��������� Ҳ����ֻת����������1 
   ADC_Init(ADC3, &ADC_InitStructure);//ADC��ʼ��
	
   ADC_Cmd(ADC3, ENABLE);//����ADת����
}

/********************************************************************
**����:Adc_LT5_Init
**����:���¼��5,��ʼ��
**��Դ:1.MCU-----PF10,ADC3-IN8,
       2.Ӳ��----3�����ȵ���
			 3.ԭ��ͼ--RT5
**ԭ��:1.���ù���ͨ���ĵ���ת��
**����:1.�������õ���3�����ȵ��裬������ɫ��һ�������Ի��������ڵ�һ��Ӳ���ֱ�� RT5-2��AGND
       2.��ɫ�߽�RT5-1
**ע��:ԭ��ͼ�Ķ� R51-->2K    R50-->91ŷ(01A����01B)
********************************************************************/
//void Adc_LT5_Init(void)
//{
//   GPIO_InitTypeDef  GPIO_InitStructure;//�˿ڳ�ʼ��
//   ADC_CommonInitTypeDef ADC_CommonInitStructure;//
//   ADC_InitTypeDef       ADC_InitStructure;
//	
//   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//ʹ�ܶ˿�ʱ��
//   RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE); //ʹ��ADC3ʱ��
//	
//   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//����
//   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;//ģ������
//   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//��������
//   GPIO_Init(GPIOF, &GPIO_InitStructure);//��ʼ���˿�
//	
//   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,ENABLE);	  //ADC3��λ
//   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,DISABLE);	  //��λ����	 
// 
//   ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;//����ģʽ
//   ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;//���������׶�֮����ӳ�5��ʱ��
//   ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled; //DMAʧ��
//   ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div4;//Ԥ��Ƶ4��Ƶ��ADCCLK=PCLK2/4=84/4=21Mhz,ADCʱ����ò�Ҫ����36Mhz 
//   ADC_CommonInit(&ADC_CommonInitStructure);//��ʼ��
//	
//   ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;//12λģʽ
//   ADC_InitStructure.ADC_ScanConvMode = DISABLE;//��ɨ��ģʽ	
//   ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;//�ر�����ת��
//   ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;//��ֹ������⣬ʹ���������
//   ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//�Ҷ���	
//   ADC_InitStructure.ADC_NbrOfConversion = 1;//�������еĳ��ȣ�1��ת���ڹ��������� Ҳ����ֻת����������1 
//   ADC_Init(ADC3, &ADC_InitStructure);//ADC��ʼ��
//	
//   ADC_Cmd(ADC3, ENABLE);//����ADת����
//}

/********************************************************************
**����:Adc_O1_Init
**����:ģ���ѹ1,��ʼ��
**��Դ:1.MCU-----PF4 ADC3-IN14                      
       2.Ӳ��---- ģ����1                                  
			 3.ԭ��ͼ--                                    
**ԭ��:���ù���ͨ���ĵ���ת��
**����:
********************************************************************/
void Adc_O1_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;//�˿ڳ�ʼ��
   ADC_CommonInitTypeDef ADC_CommonInitStructure;//
   ADC_InitTypeDef       ADC_InitStructure;
	
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//ʹ�ܶ˿�ʱ��
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE); //ʹ��ADC3ʱ��
	
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;//����
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;//ģ������
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//��������
   GPIO_Init(GPIOF, &GPIO_InitStructure);//��ʼ���˿�
	
   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,ENABLE);	  //ADC3��λ
   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,DISABLE);	  //��λ����	 
 
   ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;//����ģʽ
   ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;//���������׶�֮����ӳ�5��ʱ��
   ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled; //DMAʧ��
   ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div4;//Ԥ��Ƶ4��Ƶ��ADCCLK=PCLK2/4=84/4=21Mhz,ADCʱ����ò�Ҫ����36Mhz 
   ADC_CommonInit(&ADC_CommonInitStructure);//��ʼ��
	
   ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;//12λģʽ
   ADC_InitStructure.ADC_ScanConvMode = DISABLE;//��ɨ��ģʽ	
   ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;//�ر�����ת��
   ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;//��ֹ������⣬ʹ���������
   ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//�Ҷ���	
   ADC_InitStructure.ADC_NbrOfConversion = 1;//�������еĳ��ȣ�1��ת���ڹ��������� Ҳ����ֻת����������1 
   ADC_Init(ADC3, &ADC_InitStructure);//ADC��ʼ��
	
   ADC_Cmd(ADC3, ENABLE);//����ADת����
}

/********************************************************************
**����:Adc_O2_Init
**����:ģ���ѹ2,��ʼ��
**��Դ:1.MCU----- PF5 ADC3-PIN15                        
       2.Ӳ��----                      
			 3.ԭ��ͼ--                           
**ԭ��:���ù���ͨ���ĵ���ת��
**����:                                        
********************************************************************/
void Adc_O2_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;//�˿ڳ�ʼ��
   ADC_CommonInitTypeDef ADC_CommonInitStructure;//
   ADC_InitTypeDef       ADC_InitStructure;
	
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//ʹ�ܶ˿�ʱ��
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE); //ʹ��ADC3ʱ��
	
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;//����
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;//ģ������
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//��������
   GPIO_Init(GPIOF, &GPIO_InitStructure);//��ʼ���˿�

   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,ENABLE);	  //ADC3��λ
   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,DISABLE);	  //��λ����	 
 
   ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;//����ģʽ
   ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;//���������׶�֮����ӳ�5��ʱ��
   ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled; //DMAʧ��
   ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div4;//Ԥ��Ƶ4��Ƶ��ADCCLK=PCLK2/4=84/4=21Mhz,ADCʱ����ò�Ҫ����36Mhz 
   ADC_CommonInit(&ADC_CommonInitStructure);//��ʼ��
	
   ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;//12λģʽ
   ADC_InitStructure.ADC_ScanConvMode = DISABLE;//��ɨ��ģʽ	
   ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;//�ر�����ת��
   ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;//��ֹ������⣬ʹ���������
   ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//�Ҷ���	
   ADC_InitStructure.ADC_NbrOfConversion = 1;//�������еĳ��ȣ�1��ת���ڹ��������� Ҳ����ֻת����������1 
   ADC_Init(ADC3, &ADC_InitStructure);//ADC��ʼ��
	
   ADC_Cmd(ADC3, ENABLE);//����ADת����
}

/********************************************************************
**����:Adc_O3_Init
**����:ģ���ѹ3,��ʼ��
**��Դ:1.MCU-----PF6 ADC3-IN4
       2.Ӳ��----
			 3.ԭ��ͼ--
**ԭ��:���ù���ͨ���ĵ���ת��
**����:
********************************************************************/
void Adc_O3_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;//�˿ڳ�ʼ��
   ADC_CommonInitTypeDef ADC_CommonInitStructure;//
   ADC_InitTypeDef       ADC_InitStructure;
	
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//ʹ�ܶ˿�ʱ��
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE); //ʹ��ADC3ʱ��
	
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;//����
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;//ģ������
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//��������
   GPIO_Init(GPIOF, &GPIO_InitStructure);//��ʼ���˿�

   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,ENABLE);	  //ADC3��λ
   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,DISABLE);	  //��λ����	 
 
   ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;//����ģʽ
   ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;//���������׶�֮����ӳ�5��ʱ��
   ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled; //DMAʧ��
   ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div4;//Ԥ��Ƶ4��Ƶ��ADCCLK=PCLK2/4=84/4=21Mhz,ADCʱ����ò�Ҫ����36Mhz 
   ADC_CommonInit(&ADC_CommonInitStructure);//��ʼ��
	
   ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;//12λģʽ
   ADC_InitStructure.ADC_ScanConvMode = DISABLE;//��ɨ��ģʽ	
   ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;//�ر�����ת��
   ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;//��ֹ������⣬ʹ���������
   ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//�Ҷ���	
   ADC_InitStructure.ADC_NbrOfConversion = 1;//�������еĳ��ȣ�1��ת���ڹ��������� Ҳ����ֻת����������1 
   ADC_Init(ADC3, &ADC_InitStructure);//ADC��ʼ��
	
   ADC_Cmd(ADC3, ENABLE);//����ADת����
}

/********************************************************************
**����:Adc_O4_Init
**����:ģ���ѹ4,��ʼ��
**��Դ:1.MCU-----PF7 ADC3-IN5
       2.Ӳ��----
			 3.ԭ��ͼ--
**ԭ��:���ù���ͨ���ĵ���ת��
**����:
********************************************************************/
void Adc_O4_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;//�˿ڳ�ʼ��
   ADC_CommonInitTypeDef ADC_CommonInitStructure;//
   ADC_InitTypeDef       ADC_InitStructure;
	
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//ʹ�ܶ˿�ʱ��
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE); //ʹ��ADC3ʱ��
	
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;//����
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;//ģ������
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//��������
   GPIO_Init(GPIOF, &GPIO_InitStructure);//��ʼ���˿�

   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,ENABLE);	  //ADC3��λ
   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,DISABLE);	  //��λ����	 
 
   ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;//����ģʽ
   ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;//���������׶�֮����ӳ�5��ʱ��
   ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled; //DMAʧ��
   ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div4;//Ԥ��Ƶ4��Ƶ��ADCCLK=PCLK2/4=84/4=21Mhz,ADCʱ����ò�Ҫ����36Mhz 
   ADC_CommonInit(&ADC_CommonInitStructure);//��ʼ��
	
   ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;//12λģʽ
   ADC_InitStructure.ADC_ScanConvMode = DISABLE;//��ɨ��ģʽ	
   ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;//�ر�����ת��
   ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;//��ֹ������⣬ʹ���������
   ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//�Ҷ���	
   ADC_InitStructure.ADC_NbrOfConversion = 1;//�������еĳ��ȣ�1��ת���ڹ��������� Ҳ����ֻת����������1 
   ADC_Init(ADC3, &ADC_InitStructure);//ADC��ʼ��
	
   ADC_Cmd(ADC3, ENABLE);//����ADת����
}

/********************************************************************
**����:Adc_O5_Init
**����:ģ���ѹ5,��ʼ��
**��Դ:1.MCU-----PF8 ADC3-IN6
       2.Ӳ��----
			 3.ԭ��ͼ--
**ԭ��:���ù���ͨ���ĵ���ת��
**����:
********************************************************************/
void Adc_O5_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;//�˿ڳ�ʼ��
   ADC_CommonInitTypeDef ADC_CommonInitStructure;//
   ADC_InitTypeDef       ADC_InitStructure;
	
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//ʹ�ܶ˿�ʱ��
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC2, ENABLE); //ʹ��ADC2ʱ��
	
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;//����
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;//ģ������
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//��������
   GPIO_Init(GPIOF, &GPIO_InitStructure);//��ʼ���˿�

   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC2,ENABLE);	  //ADC3��λ
   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC2,DISABLE);	  //��λ����	 
 
   ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;//����ģʽ
   ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;//���������׶�֮����ӳ�5��ʱ��
   ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled; //DMAʧ��
   ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div4;//Ԥ��Ƶ4��Ƶ��ADCCLK=PCLK2/4=84/4=21Mhz,ADCʱ����ò�Ҫ����36Mhz 
   ADC_CommonInit(&ADC_CommonInitStructure);//��ʼ��
	
   ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;//12λģʽ
   ADC_InitStructure.ADC_ScanConvMode = DISABLE;//��ɨ��ģʽ	
   ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;//�ر�����ת��
   ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;//��ֹ������⣬ʹ���������
   ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//�Ҷ���	
   ADC_InitStructure.ADC_NbrOfConversion = 1;//�������еĳ��ȣ�1��ת���ڹ��������� Ҳ����ֻת����������1 
   ADC_Init(ADC2, &ADC_InitStructure);//ADC��ʼ��
	
   ADC_Cmd(ADC2, ENABLE);//����ADת����
}

/********************************************************************
**����:Adc_A1_Init
**����:4-20mA_1,��ʼ��
**��Դ:1.MCU-----PF9 ADC3-IN7
       2.Ӳ��----4-20mA����
**ԭ��:���ù���ͨ���ĵ���ת��
**����:250ŷķ�������� 
********************************************************************/
void Adc_A1_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;//�˿ڳ�ʼ��
   ADC_CommonInitTypeDef ADC_CommonInitStructure;//
   ADC_InitTypeDef       ADC_InitStructure;
	
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//ʹ�ܶ˿�ʱ��
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE); //ʹ��ADC2ʱ��
	
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;//����
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;//ģ������
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//��������
   GPIO_Init(GPIOF, &GPIO_InitStructure);//��ʼ���˿�

   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,ENABLE);	  //ADC3��λ
   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,DISABLE);	  //��λ����	 
 
   ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;//����ģʽ
   ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;//���������׶�֮����ӳ�5��ʱ��
   ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled; //DMAʧ��
   ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div4;//Ԥ��Ƶ4��Ƶ��ADCCLK=PCLK2/4=84/4=21Mhz,ADCʱ����ò�Ҫ����36Mhz 
   ADC_CommonInit(&ADC_CommonInitStructure);//��ʼ��
	
   ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;//12λģʽ
   ADC_InitStructure.ADC_ScanConvMode = DISABLE;//��ɨ��ģʽ	
   ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;//�ر�����ת��
   ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;//��ֹ������⣬ʹ���������
   ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//�Ҷ���	
   ADC_InitStructure.ADC_NbrOfConversion = 1;//�������еĳ��ȣ�1��ת���ڹ��������� Ҳ����ֻת����������1 
   ADC_Init(ADC3, &ADC_InitStructure);//ADC��ʼ��
	
   ADC_Cmd(ADC3, ENABLE);//����ADת����
}

/********************************************************************
**����:Adc_A2_Init
**����:4-20mA_2,��ʼ��
**��Դ:1.MCU-----PF3 ADC3-IN8
       2.Ӳ��----4-20mA����
**ԭ��:���ù���ͨ���ĵ���ת��
**����:250ŷķ�������� 
********************************************************************/
void Adc_A2_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;//�˿ڳ�ʼ��
   ADC_CommonInitTypeDef ADC_CommonInitStructure;//
   ADC_InitTypeDef       ADC_InitStructure;
	
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//ʹ�ܶ˿�ʱ��
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE); //ʹ��ADC2ʱ��
	
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;//����
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;//ģ������
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//��������
   GPIO_Init(GPIOF, &GPIO_InitStructure);//��ʼ���˿�

   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,ENABLE);	  //ADC3��λ
   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,DISABLE);	  //��λ����	 
 
   ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;//����ģʽ
   ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;//���������׶�֮����ӳ�5��ʱ��
   ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled; //DMAʧ��
   ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div4;//Ԥ��Ƶ4��Ƶ��ADCCLK=PCLK2/4=84/4=21Mhz,ADCʱ����ò�Ҫ����36Mhz 
   ADC_CommonInit(&ADC_CommonInitStructure);//��ʼ��
	
   ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;//12λģʽ
   ADC_InitStructure.ADC_ScanConvMode = DISABLE;//��ɨ��ģʽ	
   ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;//�ر�����ת��
   ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;//��ֹ������⣬ʹ���������
   ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//�Ҷ���	
   ADC_InitStructure.ADC_NbrOfConversion = 1;//�������еĳ��ȣ�1��ת���ڹ��������� Ҳ����ֻת����������1 
   ADC_Init(ADC3, &ADC_InitStructure);//ADC��ʼ��
	
   ADC_Cmd(ADC3, ENABLE);//����ADת����
}

/********************************************************************
**����:Adc_A3_Init
**����:4-20mA_3,��ʼ��
**��Դ:1.MCU-----PC0 ADC123-IN10
       2.Ӳ��----4-20mA����
**ԭ��:���ù���ͨ���ĵ���ת��
**����:250ŷķ�������� 
********************************************************************/
void Adc_A3_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;//�˿ڳ�ʼ��
   ADC_CommonInitTypeDef ADC_CommonInitStructure;//
   ADC_InitTypeDef       ADC_InitStructure;
	
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);//ʹ�ܶ˿�ʱ��
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE); //ʹ��ADC2ʱ��
	
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;//����
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;//ģ������
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//��������
   GPIO_Init(GPIOC, &GPIO_InitStructure);//��ʼ���˿�

   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,ENABLE);	  //ADC3��λ
   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,DISABLE);	  //��λ����	 
 
   ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;//����ģʽ
   ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;//���������׶�֮����ӳ�5��ʱ��
   ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled; //DMAʧ��
   ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div4;//Ԥ��Ƶ4��Ƶ��ADCCLK=PCLK2/4=84/4=21Mhz,ADCʱ����ò�Ҫ����36Mhz 
   ADC_CommonInit(&ADC_CommonInitStructure);//��ʼ��
	
   ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;//12λģʽ
   ADC_InitStructure.ADC_ScanConvMode = DISABLE;//��ɨ��ģʽ	
   ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;//�ر�����ת��
   ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;//��ֹ������⣬ʹ���������
   ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//�Ҷ���	
   ADC_InitStructure.ADC_NbrOfConversion = 1;//�������еĳ��ȣ�1��ת���ڹ��������� Ҳ����ֻת����������1 
   ADC_Init(ADC3, &ADC_InitStructure);//ADC��ʼ��
	
   ADC_Cmd(ADC3, ENABLE);//����ADת����
}




/********************************************************************
**����:Get_Adc
**����:�õ���ͨ��ADCֵ
**����:ͨ��ֵ0~16: ch: @ref ADC_channels
**����ֵ:
**ԭ��:���ù���ͨ���ĵ���ת��
********************************************************************/
//ch:ͨ��ֵ0~16: ch: @ref ADC_channels
//����ֵ:ת�����
u16 Get_Adc(ADC_TypeDef *ADCx,u8 ch)
{
   //����ָ��ADC�Ĺ�����ͨ����һ�����У�����ʱ��
   ADC_RegularChannelConfig(ADCx, ch, 1, ADC_SampleTime_480Cycles );
   ADC_SoftwareStartConv(ADCx); //ʹ��ָ����ADC1�����ת����������
   while(!ADC_GetFlagStatus(ADCx, ADC_FLAG_EOC ));//�ȴ�ת������
   return ADC_GetConversionValue(ADCx); //�������һ��ADC1�������ת�����
}



