#include "basic.h"

extern int Tim10Ms;
unsigned char Max31856Value2[6] = {0,0,0,0,0,0};

u16 adc_LT_1;
u16 adc_1,adc_2,adc_3,adc_4,adc_5;
u16 adc_A1,adc_A2,adc_A3;
u16 Pwm_5v=500-1;
u16 Pwm_20mA=500-1;
//------------Ƶ�ʼ��㶨��--------------------------
extern u8   TIM2CH3_CAPTURE_STA;		//���벶��״̬		    				
extern u32	TIM2CH3_CAPTURE_VAL;	//���벶��ֵ  
long long temp_1=0;  

extern u8   TIM4CH2_CAPTURE_STA;		//���벶��״̬		    				
extern u32	TIM4CH2_CAPTURE_VAL;	//���벶��ֵ  
long long temp_2=0;  

//------------���ݷ��ͻ���------------------------------------
unsigned char adc_LT_1_data[2]={0,0};
//unsigned char adc_1_data[2]={0,0};
//unsigned char adc_2_data[2]={0,0};
//unsigned char adc_3_data[2]={0,0};
//unsigned char adc_4_data[2]={0,0};
//unsigned char adc_5_data[2]={0,0};
//unsigned char adc_A1_data[2]={0,0};
//unsigned char adc_A2_data[2]={0,0};
//unsigned char adc_A3_data[2]={0,0};
unsigned char INput_data[5]={0,0,0,0,0};  //��Դ���� 5��������+��Դ�������������
//unsigned char PWM_OUT_data[4]={0,0,0,0};
//unsigned char Frequency_1[4]={0,0,0,0};   //Ƶ�ʼ���  1  PB10
//unsigned char Frequency_2[4]={0,0,0,0};   //             PD13
//unsigned char Frequency_3[4]={0,0,0,0}; 


int main(void)
{
	 unsigned char  Head[] = {0xA5,0x5A};
	// unsigned char  HeadE[] = {0xA5,0xFF};//�й��ϵı���ͷ
   AllInit();
   //Max31856_CS2_Write(0x81,0xCD);
   while(1)
   {
		 
			 
				 //----------����������--------------------
				 INput_data[0] = (D_1 & 0x0F) + ((D_2 & 0x0F)<<4);   
				 INput_data[1] = (D_3 & 0x0F) + ((D_4 & 0x0F)<<4);   
 				 INput_data[2] = (D_5 & 0x0F) + ((D_6 & 0x0F)<<4);   
				 INput_data[3] = (D_7 & 0x0F) + ((D_8 & 0x0F)<<4);   
         INput_data[4] = (D_9 & 0x0F) + ((D_10 & 0x0F)<<4);   


      if(Tim10Ms==0)//����
      {
         
          Tim10Ms = 10;
				  RUN_LEDTOGGLE;
//					if(FAULT_pin_Value()==0)//���������й������
//					 {
//							SendMsg(HeadE,sizeof(HeadE));
//					 }
//					 else
//					 {                                                  //               �ֽ���
							SendMsg(Head,sizeof(Head));                       //����ͷ           2       0   1
//							SendMsg(Max31856Value2,sizeof(Max31856Value2));   //���¼��         6       2   3 4 5 6 7
//							SendMsg(adc_LT_1_data,sizeof(adc_LT_1_data));     //���¼��    		 2       8   9 
//							SendMsg(adc_1_data,sizeof(adc_LT_1_data));        //ģ��1       		 2       10  11
//							SendMsg(adc_2_data,sizeof(adc_2_data));           //ģ��2       		 2       12  13
//							SendMsg(adc_3_data,sizeof(adc_3_data));           //ģ��3       		 2       14  15
//							SendMsg(adc_4_data,sizeof(adc_4_data));           //ģ��4       		 2       16  17
//							SendMsg(adc_5_data,sizeof(adc_5_data));           //ģ��5       		 2       18  19
//							SendMsg(adc_A1_data,sizeof(adc_A1_data));         //����1       		 2       20  21
//							SendMsg(adc_A2_data,sizeof(adc_A2_data));         //����2       		 2       22  23
//							SendMsg(adc_A3_data,sizeof(adc_A3_data));         //����3       		 2       24  25
							SendMsg(INput_data,sizeof(INput_data));           //��Դ����Դ����   5       26  27 28 29 30
//							SendMsg(PWM_OUT_data,sizeof(PWM_OUT_data));       //5v20mA PWMռ�ձ� 4       31  32 33 34
//						  SendMsg(Frequency_1,sizeof(Frequency_1));         //Ƶ��1            4       35  36 37 38
//						  SendMsg(Frequency_2,sizeof(Frequency_2));         //Ƶ��1            2       39  40
//							
																																//��               
//					 }
      }
   }
}
