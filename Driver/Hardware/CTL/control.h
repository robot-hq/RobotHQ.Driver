#ifndef __CONTROL_H_
#define __CONTROL_H_

#define PWM_MAX  		1125
#define PWM_MIN  		225
#define PWM_TO_ANGLE	((PWM_MAX-PWM_MIN)/180) 

#define ACTION_SPEED 	8		 //range:0 - 10
#define SHRINK_SPEED 	((u8)((0.6)*ACTION_SPEED))
#define ACTION_DELAY 	10      //ms	    //20
#define TURN_DELAY 		3      //4
#define STRAIGHT_DELAY 	3      //ms	   //3
#define STAMP_DELAY 	3      //stamp delay
#define STAND_HIGHT 	200
#define SHRINK_DEGREE 	((u8)((0.6)*STAND_HIGHT))

void PWM_Init(void);
void Sit_Down(int delay_time);
void Stand_Up(int delay_time);

void Pace_135_Motor1(int pwm_default,int amplitude,int delay_time);
void Pace_135_Motor2(int pwm_default,int amplitude,int delay_time);
void Pace_135_Motor3(int pwm_default,int amplitude,int delay_time);
void Pace_246_Motor2(int pwm_default,int amplitude,int delay_time);
void Pace_246_Motor3(int pwm_default,int amplitude,int delay_time);

void Go_straight(u8 Com_Num,u8 * Input_num);
void Go_back(u8 Com_Num,u8 * Input_num);
void Stamp(u8 Com_Num,u8 * Input_num);
void Turn(u8 Com_Num,u8 * Input_num);

#endif
