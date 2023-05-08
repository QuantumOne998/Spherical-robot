#include "adc.h"

/********************************************************************
**名称:Adc_HT1_Init
**功能:高温检测1,初始化
**资源:1.MCU-----PF3,ADC3-IN9,
       2.硬件----K型热电偶
			 3.原理图--LT1
**原理:利用规则通道的单次转换
********************************************************************/
void Adc_LT1_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;//端口初始化
   ADC_CommonInitTypeDef ADC_CommonInitStructure;//
   ADC_InitTypeDef       ADC_InitStructure;
	
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//使能端口时钟
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE); //使能ADC3时钟
	
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;//引脚
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;//模拟输入
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//不上下拉
   GPIO_Init(GPIOF, &GPIO_InitStructure);//初始化端口
	
   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,ENABLE);	  //ADC3复位
   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,DISABLE);	  //复位结束	 
 
   ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;//独立模式
   ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;//两个采样阶段之间的延迟5个时钟
   ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled; //DMA失能
   ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div4;//预分频4分频。ADCCLK=PCLK2/4=84/4=21Mhz,ADC时钟最好不要超过36Mhz 
   ADC_CommonInit(&ADC_CommonInitStructure);//初始化
	
   ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;//12位模式
   ADC_InitStructure.ADC_ScanConvMode = DISABLE;//非扫描模式	
   ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;//关闭连续转换
   ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;//禁止触发检测，使用软件触发
   ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//右对齐	
   ADC_InitStructure.ADC_NbrOfConversion = 1;//规则序列的长度，1个转换在规则序列中 也就是只转换规则序列1 
   ADC_Init(ADC3, &ADC_InitStructure);//ADC初始化
	
   ADC_Cmd(ADC3, ENABLE);//开启AD转换器
}

/********************************************************************
**名称:Adc_LT5_Init
**功能:低温检测5,初始化
**资源:1.MCU-----PF10,ADC3-IN8,
       2.硬件----3线制热电阻
			 3.原理图--RT5
**原理:1.利用规则通道的单次转换
**接线:1.传感器用的是3线制热电阻，两根红色线一样，可以互换，对于第一版硬件分别接 RT5-2、AGND
       2.白色线接RT5-1
**注意:原理图改动 R51-->2K    R50-->91欧(01A并上01B)
********************************************************************/
//void Adc_LT5_Init(void)
//{
//   GPIO_InitTypeDef  GPIO_InitStructure;//端口初始化
//   ADC_CommonInitTypeDef ADC_CommonInitStructure;//
//   ADC_InitTypeDef       ADC_InitStructure;
//	
//   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//使能端口时钟
//   RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE); //使能ADC3时钟
//	
//   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//引脚
//   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;//模拟输入
//   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//不上下拉
//   GPIO_Init(GPIOF, &GPIO_InitStructure);//初始化端口
//	
//   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,ENABLE);	  //ADC3复位
//   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,DISABLE);	  //复位结束	 
// 
//   ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;//独立模式
//   ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;//两个采样阶段之间的延迟5个时钟
//   ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled; //DMA失能
//   ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div4;//预分频4分频。ADCCLK=PCLK2/4=84/4=21Mhz,ADC时钟最好不要超过36Mhz 
//   ADC_CommonInit(&ADC_CommonInitStructure);//初始化
//	
//   ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;//12位模式
//   ADC_InitStructure.ADC_ScanConvMode = DISABLE;//非扫描模式	
//   ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;//关闭连续转换
//   ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;//禁止触发检测，使用软件触发
//   ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//右对齐	
//   ADC_InitStructure.ADC_NbrOfConversion = 1;//规则序列的长度，1个转换在规则序列中 也就是只转换规则序列1 
//   ADC_Init(ADC3, &ADC_InitStructure);//ADC初始化
//	
//   ADC_Cmd(ADC3, ENABLE);//开启AD转换器
//}

/********************************************************************
**名称:Adc_O1_Init
**功能:模拟电压1,初始化
**资源:1.MCU-----PF4 ADC3-IN14                      
       2.硬件---- 模拟量1                                  
			 3.原理图--                                    
**原理:利用规则通道的单次转换
**接线:
********************************************************************/
void Adc_O1_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;//端口初始化
   ADC_CommonInitTypeDef ADC_CommonInitStructure;//
   ADC_InitTypeDef       ADC_InitStructure;
	
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//使能端口时钟
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE); //使能ADC3时钟
	
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;//引脚
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;//模拟输入
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//不上下拉
   GPIO_Init(GPIOF, &GPIO_InitStructure);//初始化端口
	
   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,ENABLE);	  //ADC3复位
   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,DISABLE);	  //复位结束	 
 
   ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;//独立模式
   ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;//两个采样阶段之间的延迟5个时钟
   ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled; //DMA失能
   ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div4;//预分频4分频。ADCCLK=PCLK2/4=84/4=21Mhz,ADC时钟最好不要超过36Mhz 
   ADC_CommonInit(&ADC_CommonInitStructure);//初始化
	
   ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;//12位模式
   ADC_InitStructure.ADC_ScanConvMode = DISABLE;//非扫描模式	
   ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;//关闭连续转换
   ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;//禁止触发检测，使用软件触发
   ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//右对齐	
   ADC_InitStructure.ADC_NbrOfConversion = 1;//规则序列的长度，1个转换在规则序列中 也就是只转换规则序列1 
   ADC_Init(ADC3, &ADC_InitStructure);//ADC初始化
	
   ADC_Cmd(ADC3, ENABLE);//开启AD转换器
}

/********************************************************************
**名称:Adc_O2_Init
**功能:模拟电压2,初始化
**资源:1.MCU----- PF5 ADC3-PIN15                        
       2.硬件----                      
			 3.原理图--                           
**原理:利用规则通道的单次转换
**接线:                                        
********************************************************************/
void Adc_O2_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;//端口初始化
   ADC_CommonInitTypeDef ADC_CommonInitStructure;//
   ADC_InitTypeDef       ADC_InitStructure;
	
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//使能端口时钟
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE); //使能ADC3时钟
	
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;//引脚
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;//模拟输入
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//不上下拉
   GPIO_Init(GPIOF, &GPIO_InitStructure);//初始化端口

   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,ENABLE);	  //ADC3复位
   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,DISABLE);	  //复位结束	 
 
   ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;//独立模式
   ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;//两个采样阶段之间的延迟5个时钟
   ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled; //DMA失能
   ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div4;//预分频4分频。ADCCLK=PCLK2/4=84/4=21Mhz,ADC时钟最好不要超过36Mhz 
   ADC_CommonInit(&ADC_CommonInitStructure);//初始化
	
   ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;//12位模式
   ADC_InitStructure.ADC_ScanConvMode = DISABLE;//非扫描模式	
   ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;//关闭连续转换
   ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;//禁止触发检测，使用软件触发
   ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//右对齐	
   ADC_InitStructure.ADC_NbrOfConversion = 1;//规则序列的长度，1个转换在规则序列中 也就是只转换规则序列1 
   ADC_Init(ADC3, &ADC_InitStructure);//ADC初始化
	
   ADC_Cmd(ADC3, ENABLE);//开启AD转换器
}

/********************************************************************
**名称:Adc_O3_Init
**功能:模拟电压3,初始化
**资源:1.MCU-----PF6 ADC3-IN4
       2.硬件----
			 3.原理图--
**原理:利用规则通道的单次转换
**接线:
********************************************************************/
void Adc_O3_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;//端口初始化
   ADC_CommonInitTypeDef ADC_CommonInitStructure;//
   ADC_InitTypeDef       ADC_InitStructure;
	
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//使能端口时钟
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE); //使能ADC3时钟
	
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;//引脚
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;//模拟输入
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//不上下拉
   GPIO_Init(GPIOF, &GPIO_InitStructure);//初始化端口

   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,ENABLE);	  //ADC3复位
   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,DISABLE);	  //复位结束	 
 
   ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;//独立模式
   ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;//两个采样阶段之间的延迟5个时钟
   ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled; //DMA失能
   ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div4;//预分频4分频。ADCCLK=PCLK2/4=84/4=21Mhz,ADC时钟最好不要超过36Mhz 
   ADC_CommonInit(&ADC_CommonInitStructure);//初始化
	
   ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;//12位模式
   ADC_InitStructure.ADC_ScanConvMode = DISABLE;//非扫描模式	
   ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;//关闭连续转换
   ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;//禁止触发检测，使用软件触发
   ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//右对齐	
   ADC_InitStructure.ADC_NbrOfConversion = 1;//规则序列的长度，1个转换在规则序列中 也就是只转换规则序列1 
   ADC_Init(ADC3, &ADC_InitStructure);//ADC初始化
	
   ADC_Cmd(ADC3, ENABLE);//开启AD转换器
}

/********************************************************************
**名称:Adc_O4_Init
**功能:模拟电压4,初始化
**资源:1.MCU-----PF7 ADC3-IN5
       2.硬件----
			 3.原理图--
**原理:利用规则通道的单次转换
**接线:
********************************************************************/
void Adc_O4_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;//端口初始化
   ADC_CommonInitTypeDef ADC_CommonInitStructure;//
   ADC_InitTypeDef       ADC_InitStructure;
	
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//使能端口时钟
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE); //使能ADC3时钟
	
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;//引脚
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;//模拟输入
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//不上下拉
   GPIO_Init(GPIOF, &GPIO_InitStructure);//初始化端口

   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,ENABLE);	  //ADC3复位
   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,DISABLE);	  //复位结束	 
 
   ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;//独立模式
   ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;//两个采样阶段之间的延迟5个时钟
   ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled; //DMA失能
   ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div4;//预分频4分频。ADCCLK=PCLK2/4=84/4=21Mhz,ADC时钟最好不要超过36Mhz 
   ADC_CommonInit(&ADC_CommonInitStructure);//初始化
	
   ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;//12位模式
   ADC_InitStructure.ADC_ScanConvMode = DISABLE;//非扫描模式	
   ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;//关闭连续转换
   ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;//禁止触发检测，使用软件触发
   ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//右对齐	
   ADC_InitStructure.ADC_NbrOfConversion = 1;//规则序列的长度，1个转换在规则序列中 也就是只转换规则序列1 
   ADC_Init(ADC3, &ADC_InitStructure);//ADC初始化
	
   ADC_Cmd(ADC3, ENABLE);//开启AD转换器
}

/********************************************************************
**名称:Adc_O5_Init
**功能:模拟电压5,初始化
**资源:1.MCU-----PF8 ADC3-IN6
       2.硬件----
			 3.原理图--
**原理:利用规则通道的单次转换
**接线:
********************************************************************/
void Adc_O5_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;//端口初始化
   ADC_CommonInitTypeDef ADC_CommonInitStructure;//
   ADC_InitTypeDef       ADC_InitStructure;
	
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//使能端口时钟
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC2, ENABLE); //使能ADC2时钟
	
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;//引脚
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;//模拟输入
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//不上下拉
   GPIO_Init(GPIOF, &GPIO_InitStructure);//初始化端口

   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC2,ENABLE);	  //ADC3复位
   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC2,DISABLE);	  //复位结束	 
 
   ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;//独立模式
   ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;//两个采样阶段之间的延迟5个时钟
   ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled; //DMA失能
   ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div4;//预分频4分频。ADCCLK=PCLK2/4=84/4=21Mhz,ADC时钟最好不要超过36Mhz 
   ADC_CommonInit(&ADC_CommonInitStructure);//初始化
	
   ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;//12位模式
   ADC_InitStructure.ADC_ScanConvMode = DISABLE;//非扫描模式	
   ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;//关闭连续转换
   ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;//禁止触发检测，使用软件触发
   ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//右对齐	
   ADC_InitStructure.ADC_NbrOfConversion = 1;//规则序列的长度，1个转换在规则序列中 也就是只转换规则序列1 
   ADC_Init(ADC2, &ADC_InitStructure);//ADC初始化
	
   ADC_Cmd(ADC2, ENABLE);//开启AD转换器
}

/********************************************************************
**名称:Adc_A1_Init
**功能:4-20mA_1,初始化
**资源:1.MCU-----PF9 ADC3-IN7
       2.硬件----4-20mA电流
**原理:利用规则通道的单次转换
**接线:250欧姆采样电阻 
********************************************************************/
void Adc_A1_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;//端口初始化
   ADC_CommonInitTypeDef ADC_CommonInitStructure;//
   ADC_InitTypeDef       ADC_InitStructure;
	
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//使能端口时钟
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE); //使能ADC2时钟
	
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;//引脚
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;//模拟输入
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//不上下拉
   GPIO_Init(GPIOF, &GPIO_InitStructure);//初始化端口

   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,ENABLE);	  //ADC3复位
   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,DISABLE);	  //复位结束	 
 
   ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;//独立模式
   ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;//两个采样阶段之间的延迟5个时钟
   ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled; //DMA失能
   ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div4;//预分频4分频。ADCCLK=PCLK2/4=84/4=21Mhz,ADC时钟最好不要超过36Mhz 
   ADC_CommonInit(&ADC_CommonInitStructure);//初始化
	
   ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;//12位模式
   ADC_InitStructure.ADC_ScanConvMode = DISABLE;//非扫描模式	
   ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;//关闭连续转换
   ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;//禁止触发检测，使用软件触发
   ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//右对齐	
   ADC_InitStructure.ADC_NbrOfConversion = 1;//规则序列的长度，1个转换在规则序列中 也就是只转换规则序列1 
   ADC_Init(ADC3, &ADC_InitStructure);//ADC初始化
	
   ADC_Cmd(ADC3, ENABLE);//开启AD转换器
}

/********************************************************************
**名称:Adc_A2_Init
**功能:4-20mA_2,初始化
**资源:1.MCU-----PF3 ADC3-IN8
       2.硬件----4-20mA电流
**原理:利用规则通道的单次转换
**接线:250欧姆采样电阻 
********************************************************************/
void Adc_A2_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;//端口初始化
   ADC_CommonInitTypeDef ADC_CommonInitStructure;//
   ADC_InitTypeDef       ADC_InitStructure;
	
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//使能端口时钟
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE); //使能ADC2时钟
	
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;//引脚
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;//模拟输入
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//不上下拉
   GPIO_Init(GPIOF, &GPIO_InitStructure);//初始化端口

   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,ENABLE);	  //ADC3复位
   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,DISABLE);	  //复位结束	 
 
   ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;//独立模式
   ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;//两个采样阶段之间的延迟5个时钟
   ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled; //DMA失能
   ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div4;//预分频4分频。ADCCLK=PCLK2/4=84/4=21Mhz,ADC时钟最好不要超过36Mhz 
   ADC_CommonInit(&ADC_CommonInitStructure);//初始化
	
   ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;//12位模式
   ADC_InitStructure.ADC_ScanConvMode = DISABLE;//非扫描模式	
   ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;//关闭连续转换
   ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;//禁止触发检测，使用软件触发
   ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//右对齐	
   ADC_InitStructure.ADC_NbrOfConversion = 1;//规则序列的长度，1个转换在规则序列中 也就是只转换规则序列1 
   ADC_Init(ADC3, &ADC_InitStructure);//ADC初始化
	
   ADC_Cmd(ADC3, ENABLE);//开启AD转换器
}

/********************************************************************
**名称:Adc_A3_Init
**功能:4-20mA_3,初始化
**资源:1.MCU-----PC0 ADC123-IN10
       2.硬件----4-20mA电流
**原理:利用规则通道的单次转换
**接线:250欧姆采样电阻 
********************************************************************/
void Adc_A3_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;//端口初始化
   ADC_CommonInitTypeDef ADC_CommonInitStructure;//
   ADC_InitTypeDef       ADC_InitStructure;
	
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);//使能端口时钟
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE); //使能ADC2时钟
	
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;//引脚
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;//模拟输入
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//不上下拉
   GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化端口

   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,ENABLE);	  //ADC3复位
   RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,DISABLE);	  //复位结束	 
 
   ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;//独立模式
   ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;//两个采样阶段之间的延迟5个时钟
   ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled; //DMA失能
   ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div4;//预分频4分频。ADCCLK=PCLK2/4=84/4=21Mhz,ADC时钟最好不要超过36Mhz 
   ADC_CommonInit(&ADC_CommonInitStructure);//初始化
	
   ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;//12位模式
   ADC_InitStructure.ADC_ScanConvMode = DISABLE;//非扫描模式	
   ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;//关闭连续转换
   ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;//禁止触发检测，使用软件触发
   ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//右对齐	
   ADC_InitStructure.ADC_NbrOfConversion = 1;//规则序列的长度，1个转换在规则序列中 也就是只转换规则序列1 
   ADC_Init(ADC3, &ADC_InitStructure);//ADC初始化
	
   ADC_Cmd(ADC3, ENABLE);//开启AD转换器
}




/********************************************************************
**名称:Get_Adc
**功能:得单个通道ADC值
**参数:通道值0~16: ch: @ref ADC_channels
**返回值:
**原理:利用规则通道的单次转换
********************************************************************/
//ch:通道值0~16: ch: @ref ADC_channels
//返回值:转换结果
u16 Get_Adc(ADC_TypeDef *ADCx,u8 ch)
{
   //设置指定ADC的规则组通道，一个序列，采样时间
   ADC_RegularChannelConfig(ADCx, ch, 1, ADC_SampleTime_480Cycles );
   ADC_SoftwareStartConv(ADCx); //使能指定的ADC1的软件转换启动功能
   while(!ADC_GetFlagStatus(ADCx, ADC_FLAG_EOC ));//等待转换结束
   return ADC_GetConversionValue(ADCx); //返回最近一次ADC1规则组的转换结果
}



