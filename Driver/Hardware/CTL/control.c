#include "stm32f4xx.h"
#include "control.h"
#include "delay.h"
#include <math.h>
#include "ucos_ii.h"
#include "pwm.h"


//default angle of all the engine 
//int pwm_init[26] = { 0,	   //no use	 
//	 			     590,  535,    0,  475,  605,		   //( 1 - 5 )
//				     795,  355,  530,  605,    0,	   	   //( 6 - 10)
//				       0,  475,    0,    0,  803,	       //( 11- 15)
//				     575,    0,  535,  535,  795,	       //( 16- 20)
//				     375,  575,  575,  365,    0,	       //( 21- 25)
//				    };    

//default angle of all the engine 
int pwm_init[26] = { 0,	   //no use	 
	 			     590,  535,    0,  475,  605,		   //( 1 - 5 )
				     790,  355,  530,  605,    0,	   	   //( 6 - 10)
				       0,  475,    0,    0,  793,	       //( 11- 15)
				     575,    0,  535,  535,  793,	       //( 16- 20)
				     375,  575,  575,  385,    0,	       //( 21- 25)
				    };       

void PWM_Init(void)
{
		TIM_SetCompare1(TIM1,pwm_init[1]);	 //1-1-1  	   
		TIM_SetCompare2(TIM1,pwm_init[5]);	 //2-1-5  	   
		TIM_SetCompare3(TIM1,pwm_init[9]);	 //3-1-9  	   
		TIM_SetCompare4(TIM1,pwm_init[2]);	 //2-3-2

		TIM_SetCompare3(TIM2,pwm_init[15]);	 //3-2-15  	   
		TIM_SetCompare4(TIM2,pwm_init[18]);	 //4-3-18
																   
		TIM_SetCompare1(TIM3,pwm_init[12]);	 //4-1-12  	   
		TIM_SetCompare2(TIM3,pwm_init[8]);	 //5-1-8  	   
		TIM_SetCompare3(TIM3,pwm_init[4]);	 //6-1-4  	   
		TIM_SetCompare4(TIM3,pwm_init[7]);	 //4-2-7

		TIM_SetCompare1(TIM4,pwm_init[23]);	 //6-3-23  	   
		TIM_SetCompare2(TIM4,pwm_init[24]);	 //6-2-24  	   
		TIM_SetCompare3(TIM4,pwm_init[20]);	 //1-2-20  	   
		TIM_SetCompare4(TIM4,pwm_init[19]);	 //1-3-19

		TIM_SetCompare1(TIM5,pwm_init[6]);	 //2-2-6  	   
		TIM_SetCompare2(TIM5,pwm_init[16]);	 //3-3-16  	   
		TIM_SetCompare3(TIM5,pwm_init[22]);	 //5-3-22  	   
		TIM_SetCompare4(TIM5,pwm_init[21]);	 //5-2-21
}

void Sit_Down(int delay_time)
{
		int pwm_tmp = 0;						//motor 2
		int pwm_tmp2 = 0;						//motor 1
		for (;pwm_tmp<=STAND_HIGHT;)				 //150 efect the height of stand
		{
//			delay_ms(ACTION_DELAY);
			OSTimeDlyHMSM(0,0,0,delay_time);//延时，参数：时，分，秒，微秒
			TIM_SetCompare3(TIM2,pwm_init[15] - pwm_tmp);	 //3-2-15	
			TIM_SetCompare3(TIM4,pwm_init[20] - pwm_tmp);	 //1-2-20
			TIM_SetCompare1(TIM5,pwm_init[6]  - pwm_tmp);	 //2-2-6	   	   

			TIM_SetCompare4(TIM3,pwm_init[7]  + pwm_tmp);	 //4-2-7	
			TIM_SetCompare2(TIM4,pwm_init[24] + pwm_tmp);	 //6-2-24 
			TIM_SetCompare4(TIM5,pwm_init[21] + pwm_tmp);	 //5-2-21
			
			TIM_SetCompare1(TIM1,pwm_init[1] - pwm_tmp2);	 //1-1-1  	   
			TIM_SetCompare2(TIM1,pwm_init[5] - pwm_tmp2);	 //2-1-5  	 
			TIM_SetCompare3(TIM1,pwm_init[9] - pwm_tmp2);	 //3-1-9  
			
			TIM_SetCompare1(TIM3,pwm_init[12] + pwm_tmp2);	 //4-1-12  	   
			TIM_SetCompare2(TIM3,pwm_init[8] + pwm_tmp2);	 //5-1-8  	   
			TIM_SetCompare3(TIM3,pwm_init[4] + pwm_tmp2);	 //6-1-4  	   
				   
			pwm_tmp += ACTION_SPEED;	
			pwm_tmp2 += SHRINK_SPEED;	
		}
		OSTimeDlyHMSM(0,0,0,100);//延时，参数：时，分，秒，微秒
		Close_All_TIM();		//close all timer
}

void Stand_Up(int delay_time)
{
		int pwm_tmp = 0;
		int pwm_tmp2 = 0;
		Open_All_TIM();			//Open all timer
		TIM_SetCompare4(TIM1,pwm_init[2]);	 //2-3-2
		TIM_SetCompare4(TIM2,pwm_init[18]);	 //4-3-18
		TIM_SetCompare1(TIM4,pwm_init[23]);	 //6-3-23  	   
		TIM_SetCompare4(TIM4,pwm_init[19]);	 //1-3-19
		TIM_SetCompare2(TIM5,pwm_init[16]);	 //3-3-16  	   
		TIM_SetCompare3(TIM5,pwm_init[22]);	 //5-3-22  	   
		for (;pwm_tmp<=STAND_HIGHT;)				 //150 efect the height of stand
		{
//			delay_ms(ACTION_DELAY);	
			OSTimeDlyHMSM(0,0,0,delay_time);//延时，参数：时，分，秒，微秒
			TIM_SetCompare3(TIM2,pwm_init[15] - STAND_HIGHT + pwm_tmp);	 //3-2-15	   
			TIM_SetCompare3(TIM4,pwm_init[20] - STAND_HIGHT + pwm_tmp);	 //1-2-20
			TIM_SetCompare1(TIM5,pwm_init[6]  - STAND_HIGHT + pwm_tmp);	 //2-2-6	   	   
	   	   

			TIM_SetCompare4(TIM3,pwm_init[7]  + STAND_HIGHT - pwm_tmp);	 //4-2-7	
			TIM_SetCompare2(TIM4,pwm_init[24] + STAND_HIGHT - pwm_tmp);  //6-2-24 
			TIM_SetCompare4(TIM5,pwm_init[21] + STAND_HIGHT - pwm_tmp);	 //5-2-21
			
			TIM_SetCompare1(TIM1,pwm_init[1] - SHRINK_DEGREE + pwm_tmp2);	 //1-1-1  	   
			TIM_SetCompare2(TIM1,pwm_init[5] - SHRINK_DEGREE + pwm_tmp2);	 //2-1-5  	   
			TIM_SetCompare3(TIM1,pwm_init[9] - SHRINK_DEGREE + pwm_tmp2);	 //3-1-9  
			
			TIM_SetCompare1(TIM3,pwm_init[12] + SHRINK_DEGREE - pwm_tmp2);	 //4-1-12  	   
			TIM_SetCompare2(TIM3,pwm_init[8]  + SHRINK_DEGREE - pwm_tmp2);	 //5-1-8  	   
			TIM_SetCompare3(TIM3,pwm_init[4]  + SHRINK_DEGREE - pwm_tmp2);	 //6-1-4  	   
			
			pwm_tmp += ACTION_SPEED;	
			pwm_tmp2 += SHRINK_SPEED;	
		}
}

void Pace_135_Motor1(int pwm_default,int amplitude,int delay_time)
{
	int pwm_tmp = 0;
	for(;fabs(pwm_tmp)<=fabs(amplitude);)
	{
//		delay_ms(ACTION_DELAY);		
		OSTimeDlyHMSM(0,0,0,delay_time);//延时，参数：时，分，秒，微秒						 
		TIM_SetCompare1(TIM1,pwm_init[1] - pwm_default - pwm_tmp);	 //1-1-1  	   
		TIM_SetCompare3(TIM1,pwm_init[9] - pwm_default - pwm_tmp);	 //3-1-9  	   
		TIM_SetCompare2(TIM3,pwm_init[8] + pwm_default + pwm_tmp);	 //5-1-8  	   
		if(amplitude > 0)
			pwm_tmp += ACTION_SPEED;
		else 
			pwm_tmp -= ACTION_SPEED;
	}
}
void Pace_135_Motor2(int pwm_default,int amplitude,int delay_time)
{
	int pwm_tmp = 0;
	for(;fabs(pwm_tmp)<=fabs(amplitude);)
	{
//		delay_ms(ACTION_DELAY);		
		OSTimeDlyHMSM(0,0,0,delay_time);//延时，参数：时，分，秒，微秒						 
		TIM_SetCompare3(TIM4,pwm_init[20] - pwm_default - pwm_tmp);	 //1-2-20 
		TIM_SetCompare3(TIM2,pwm_init[15] - pwm_default - pwm_tmp);	 //3-2-15 
		TIM_SetCompare4(TIM5,pwm_init[21] + pwm_default + pwm_tmp);	 //5-2-21
		if(amplitude > 0)
			pwm_tmp += ACTION_SPEED;
		else 
			pwm_tmp -= ACTION_SPEED;
	}
}
void Pace_135_Motor3(int pwm_default,int amplitude,int delay_time)
{
	int pwm_tmp = 0;
	for(;fabs(pwm_tmp)<=fabs(amplitude);)
	{
//		delay_ms(ACTION_DELAY);
		OSTimeDlyHMSM(0,0,0,delay_time);//延时，参数：时，分，秒，微秒	
		TIM_SetCompare4(TIM4,pwm_init[19] + pwm_default + pwm_tmp);	 //1-3-19
		TIM_SetCompare2(TIM5,pwm_init[16] + pwm_default + pwm_tmp);	 //3-3-16  	   
		TIM_SetCompare3(TIM5,pwm_init[22] - pwm_default - pwm_tmp);	 //5-3-22 
		if(amplitude > 0)
			pwm_tmp += ACTION_SPEED;
		else 
			pwm_tmp -= ACTION_SPEED;
	}
}
void Pace_135_Motor3_Different(int pwm_default,int amplitude,int delay_time)
{
	int pwm_tmp = 0;
	for(;fabs(pwm_tmp)<=fabs(amplitude);)
	{
//		delay_ms(ACTION_DELAY);
		OSTimeDlyHMSM(0,0,0,delay_time);//延时，参数：时，分，秒，微秒	
		TIM_SetCompare4(TIM4,pwm_init[19] + pwm_default + pwm_tmp);	 //1-3-19
		TIM_SetCompare2(TIM5,pwm_init[16] + pwm_default + pwm_tmp);	 //3-3-16  	   
		TIM_SetCompare3(TIM5,pwm_init[22] + pwm_default + pwm_tmp);	 //5-3-22 
		if(amplitude > 0)
			pwm_tmp += ACTION_SPEED;
		else 
			pwm_tmp -= ACTION_SPEED;
	}
}
void Pace_246_Motor2(int pwm_default,int amplitude,int delay_time)
{
	int pwm_tmp = 0;
	for(;fabs(pwm_tmp)<=fabs(amplitude);)
	{
//		delay_ms(ACTION_DELAY);
		OSTimeDlyHMSM(0,0,0,delay_time);//延时，参数：时，分，秒，微秒		TIM_SetCompare1(TIM5,pwm_init[6]  - pwm_default - pwm_tmp);	 //2-2-6  
		TIM_SetCompare4(TIM3,pwm_init[7]  + pwm_default + pwm_tmp);	 //4-2-7
		TIM_SetCompare2(TIM4,pwm_init[24] + pwm_default + pwm_tmp);	 //6-2-24  	 
		TIM_SetCompare1(TIM5,pwm_init[6] - pwm_default - pwm_tmp);	 //2-2-6  	 
		if(amplitude > 0)
			pwm_tmp += ACTION_SPEED;
		else 
			pwm_tmp -= ACTION_SPEED;
	}
}
void Pace_246_Motor3(int pwm_default,int amplitude,int delay_time)
{	   
	int pwm_tmp = 0;
	for(;fabs(pwm_tmp)<=fabs(amplitude);)
	{
//		delay_ms(ACTION_DELAY);
		OSTimeDlyHMSM(0,0,0,delay_time);//延时，参数：时，分，秒，微秒		TIM_SetCompare1(TIM5,pwm_init[6]  - pwm_default - pwm_tmp);	 //2-2-6  
		TIM_SetCompare4(TIM1,pwm_init[2]  + pwm_default + pwm_tmp);	 //2-3-2  
		TIM_SetCompare4(TIM2,pwm_init[18] - pwm_default - pwm_tmp);	 //4-3-18
		TIM_SetCompare1(TIM4,pwm_init[23] - pwm_default - pwm_tmp);	 //6-3-23  	   
		if(amplitude > 0)
			pwm_tmp += ACTION_SPEED;
		else 
			pwm_tmp -= ACTION_SPEED;
	}
}
void Pace_246_Motor3_Different(int pwm_default,int amplitude,int delay_time)
{	   
	int pwm_tmp = 0;
	for(;fabs(pwm_tmp)<=fabs(amplitude);)
	{
//		delay_ms(ACTION_DELAY);
		OSTimeDlyHMSM(0,0,0,delay_time);//延时，参数：时，分，秒，微秒		TIM_SetCompare1(TIM5,pwm_init[6]  - pwm_default - pwm_tmp);	 //2-2-6  
		TIM_SetCompare4(TIM1,pwm_init[2]  + pwm_default + pwm_tmp);	 //2-3-2  
		TIM_SetCompare4(TIM2,pwm_init[18] + pwm_default + pwm_tmp);	 //4-3-18
		TIM_SetCompare1(TIM4,pwm_init[23] + pwm_default + pwm_tmp);	 //6-3-23  	   
		if(amplitude > 0)
			pwm_tmp += ACTION_SPEED;
		else 
			pwm_tmp -= ACTION_SPEED;
	}
}
void Pace_135_246_Motor3(int pwm_def1,int pwm_def2,int amplitude,int delay_time)
{	   
	int pwm_tmp = 0;
	for(;fabs(pwm_tmp)<=fabs(amplitude);)
	{
		OSTimeDlyHMSM(0,0,0,delay_time);//延时，参数：时，分，秒，微秒		

		TIM_SetCompare4(TIM4,pwm_init[19] + pwm_def1 + pwm_tmp);	 //1-3-19
		TIM_SetCompare2(TIM5,pwm_init[16] + pwm_def1 + pwm_tmp);	 //3-3-16  	   
		TIM_SetCompare3(TIM5,pwm_init[22] + pwm_def1 + pwm_tmp);	 //5-3-22  	   

		TIM_SetCompare4(TIM1,pwm_init[2]  + pwm_def2 + pwm_tmp);	 //2-3-2  
		TIM_SetCompare4(TIM2,pwm_init[18] + pwm_def2 + pwm_tmp);	 //4-3-18
		TIM_SetCompare1(TIM4,pwm_init[23] + pwm_def2 + pwm_tmp);	 //6-3-23  
		
		if(amplitude > 0)
			pwm_tmp += ACTION_SPEED;
		else 
			pwm_tmp -= ACTION_SPEED;
	}
}
void Go_straight(u8 Com_Num,u8 * Input_num)
{
	Pace_135_Motor2(0,100,STRAIGHT_DELAY);		//UP
	while(Com_Num == *Input_num)
	{
		Pace_246_Motor3(0,80,STRAIGHT_DELAY);		//FRONT
	   	Pace_135_Motor2(100,-100,STRAIGHT_DELAY);	//DOWM
		Pace_246_Motor2(0,100,STRAIGHT_DELAY);		//UP
		Pace_246_Motor3(80,-80,STRAIGHT_DELAY);		//RETURN
		Pace_135_Motor3(0,80,STRAIGHT_DELAY);		//FRONT
		Pace_246_Motor2(100,-100,STRAIGHT_DELAY);	//DOWM
		Pace_135_Motor2(0,100,STRAIGHT_DELAY);		//UP
		Pace_135_Motor3(80,-80,STRAIGHT_DELAY);		//RETURN
	}
	Pace_135_Motor2(100,-100,STRAIGHT_DELAY);		//DOWM
}
void Go_back(u8 Com_Num,u8 * Input_num)
{
	Pace_135_Motor2(0,100,ACTION_DELAY);		//UP
	while(Com_Num == *Input_num)
	{
		Pace_246_Motor3(0,-80,ACTION_DELAY);	//BACK
	   	Pace_135_Motor2(100,-100,ACTION_DELAY);	//DOWM
		Pace_246_Motor2(0,100,ACTION_DELAY);	//UP
		Pace_246_Motor3(-80,80,ACTION_DELAY);	//RETURN
		Pace_135_Motor3(0,-80,ACTION_DELAY);	//BACK
		Pace_246_Motor2(100,-100,ACTION_DELAY);	//DOWM
		Pace_135_Motor2(0,100,ACTION_DELAY);	//UP
		Pace_135_Motor3(-80,80,ACTION_DELAY);	//RETURN
	}
	Pace_135_Motor2(100,-100,ACTION_DELAY);	//DOWM
}
void Stamp(u8 Com_Num,u8 * Input_num)
{
	Pace_135_Motor2(0,150,STAMP_DELAY);		//UP
	while(Com_Num == *Input_num)
	{
	   	Pace_135_Motor2(150,-150,STAMP_DELAY);	//DOWM
		Pace_246_Motor2(0,150,STAMP_DELAY);	//UP
		Pace_246_Motor2(150,-150,STAMP_DELAY);	//DOWM
		Pace_135_Motor2(0,150,STAMP_DELAY);	//UP
	}
	Pace_135_Motor2(150,-150,STAMP_DELAY);	//DOWM
}
void Turn(u8 Com_Num,u8 * Input_num)
{
	while(Com_Num == *Input_num)
	{
		Pace_135_246_Motor3(0,0,70,TURN_DELAY);     //turn body left

		Pace_246_Motor2(0,100,TURN_DELAY);			  //UP
		Pace_246_Motor3_Different(70,-70,TURN_DELAY);	  //2,4,6 leg return
		Pace_246_Motor2(100,-100,TURN_DELAY);		      //DOWM
		
		Pace_135_Motor2(0,100,TURN_DELAY);			  //UP
		Pace_135_Motor3_Different(70,-70,TURN_DELAY);	  //1,3,5 leg return
		Pace_135_Motor2(100,-100,TURN_DELAY);		      //DOWM
		
	}
}
