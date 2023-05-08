#include "basic.h"

/********************************************************************
**名称:AllInit
**功能:全部初始化
********************************************************************/
void AllInit(void)
{
   NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
   delay_init(168);		  //初始化延时函数
	
	 //--------ADC初始化------------------
//	  Adc_LT1_Init();//
//	  Adc_O1_Init(); //模拟电压_1
//    Adc_O2_Init(); //模拟电压_2
//    Adc_O3_Init(); //模拟电压_3
//    Adc_O4_Init(); //模拟电压_4
//    Adc_O5_Init(); //模拟电压_5
//    Adc_A1_Init(); //4-20mA电流_1
//    Adc_A2_Init(); //4-20mA电流_2
//    Adc_A3_Init(); //4-20mA电流_3
//	  //--------输出初始化------------------
//	 //Dout_LED_Init();//LED初始化	
//		 Dout_Y1_Init();//有源输出1初始化	
//		 Dout_Y2_Init();//有源输出2初始化	
//		 Dout_Y3_Init();//有源输出3初始化	
//		 Dout_Y4_Init();//有源输出4初始化
//		 Dout_Y5_Init();//有源输出4初始化
//	   GJD_out();     //干接点输出
	  //--------输入初始化------------------
 in_D_1_Init();
 in_D_2_Init();
 in_D_3_Init();
 in_D_4_Init();
 in_D_5_Init();
	
 in_D_6_Init();
 in_D_7_Init();
 in_D_8_Init();
 in_D_9_Init();
 in_D_10_Init();
	  //--------频率-输入俘获------------------
		TIM2_CH3_Cap_Init(0XFFFFFFFF,84-1); //以1Mhz的频率计数 
		TIM4_CH2_Cap_Init(0XFFFF,84-1); //以1Mhz的频率计数 		
		
		//---------PWM输出初始化------------------
		 Pwm_20mA_Init();
		 Pwm_5V_Init();
	
   Tim6_100ms_Init();
   RS422_Init(115200);    //初始化422
   Max31856Init();      //初始化热电偶
	 Switch_Init();       //低温通道选择
   Run_LED_Init();
}
