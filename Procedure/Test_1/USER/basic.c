#include "basic.h"

/********************************************************************
**����:AllInit
**����:ȫ����ʼ��
********************************************************************/
void AllInit(void)
{
   NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
   delay_init(168);		  //��ʼ����ʱ����
	
	 //--------ADC��ʼ��------------------
//	  Adc_LT1_Init();//
//	  Adc_O1_Init(); //ģ���ѹ_1
//    Adc_O2_Init(); //ģ���ѹ_2
//    Adc_O3_Init(); //ģ���ѹ_3
//    Adc_O4_Init(); //ģ���ѹ_4
//    Adc_O5_Init(); //ģ���ѹ_5
//    Adc_A1_Init(); //4-20mA����_1
//    Adc_A2_Init(); //4-20mA����_2
//    Adc_A3_Init(); //4-20mA����_3
//	  //--------�����ʼ��------------------
//	 //Dout_LED_Init();//LED��ʼ��	
//		 Dout_Y1_Init();//��Դ���1��ʼ��	
//		 Dout_Y2_Init();//��Դ���2��ʼ��	
//		 Dout_Y3_Init();//��Դ���3��ʼ��	
//		 Dout_Y4_Init();//��Դ���4��ʼ��
//		 Dout_Y5_Init();//��Դ���4��ʼ��
//	   GJD_out();     //�ɽӵ����
	  //--------�����ʼ��------------------
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
	  //--------Ƶ��-�������------------------
		TIM2_CH3_Cap_Init(0XFFFFFFFF,84-1); //��1Mhz��Ƶ�ʼ��� 
		TIM4_CH2_Cap_Init(0XFFFF,84-1); //��1Mhz��Ƶ�ʼ��� 		
		
		//---------PWM�����ʼ��------------------
		 Pwm_20mA_Init();
		 Pwm_5V_Init();
	
   Tim6_100ms_Init();
   RS422_Init(115200);    //��ʼ��422
   Max31856Init();      //��ʼ���ȵ�ż
	 Switch_Init();       //����ͨ��ѡ��
   Run_LED_Init();
}
