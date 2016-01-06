#include "gui.h"
#include "stm32f4xx.h"
#include "delay.h"
#include "led.h"
#include "usart.h"
#include "ucos_ii.h"
#include "pwm.h"
#include "control.h"
#include "app_cfg.h"
#include "bsp.h"
#include "24l01.h"
#include "spi.h"

//Task Stack Setting
#define  APP_TASK_START_STK_SIZE           512
#define  APP_LED1_STK_SIZE			   	   1024
#define  APP_NRF24L01_STK_SIZE			   1024
#define  APP_LED3_STK_SIZE			       1024

//Task Priority
#define  APP_TASK_START_PRIO               3
#define  APP_LED1_PRIO                     5
#define  APP_NRF24L01_PRIO                 4
#define  APP_LED3_PRIO                     7

//Stack Size setting 
static  OS_STK App_TaskStartStk[APP_TASK_START_STK_SIZE];
static  OS_STK App_LED1Stk[APP_LED1_STK_SIZE];
static  OS_STK App_NRF24L01Stk[APP_NRF24L01_STK_SIZE];
static  OS_STK App_LED3Stk[APP_LED3_STK_SIZE];

//Function Statement
static  void  App_TaskStart(void *p_arg);
static  void  App_Task_LED1(void *p_arg);
static  void  App_Task_NRF24L01(void *p_arg);
static  void  App_Task_ACTION(void *p_arg);

u8 tmp_buf[33];//data received buffer
u8 cmd_last = 0xff;
static u8 cmd = 0;     //command of action

int main(void)
{  
    OSInit();      			   //uC/OS-II init
	TIM_Init();
	NRF24L01_Init();    
//	Stand_Up();
	LED_Init();         		//LED Init
	while(NRF24L01_Check())
	{
    	LED1(On);
		OSTimeDlyHMSM(0,0,0,50);
		LED1(Off);
		OSTimeDlyHMSM(0,0,0,50);
	}
	RX_Mode();						
    OSTaskCreate(App_TaskStart,(void*)0,(OS_STK*)&App_TaskStartStk[APP_TASK_START_STK_SIZE-1],APP_TASK_START_PRIO);    
    OSStart();                                                     
    return (0);
}
static  void  App_TaskStart (void *p_arg)//construct new task in this function
{	 
    OS_CPU_SysTickInit();         //Init System Clock
    BSP_Init(); 
    OSTaskCreate(App_Task_LED1,(void*)0,(OS_STK*)&App_LED1Stk[APP_LED1_STK_SIZE-1],APP_LED1_PRIO);    
    OSTaskCreate(App_Task_NRF24L01,(void*)0,(OS_STK*)&App_NRF24L01Stk[APP_NRF24L01_STK_SIZE-1],APP_NRF24L01_PRIO);    
    OSTaskCreate(App_Task_ACTION,(void*)0,(OS_STK*)&App_LED3Stk[APP_LED3_STK_SIZE-1],APP_LED3_PRIO);    
 	OSTaskSuspend(APP_TASK_START_PRIO);	//suspend but not delete
}

static  void  App_Task_LED1 (void *p_arg)//construct new task in this function
{	 
    while (1) 
	{ 	
    	LED1(On);
		LED0(Off);
		OSTimeDlyHMSM(0,0,0,50);
		LED1(Off);
    	LED0(On);
		OSTimeDlyHMSM(0,0,0,50);
    }
}
static  void  App_Task_NRF24L01 (void *p_arg)//construct new task in this function
{	 
    while (1) 
	{ 	
		if(NRF24L01_RxPacket(tmp_buf)==0)
		{
	    	LED2(On);
			OSTimeDlyHMSM(0,0,0,30);
			LED2(Off);
			OSTimeDlyHMSM(0,0,0,30);
		}else 			
			OSTimeDlyHMSM(0,0,0,1);	
		if((tmp_buf[0] == tmp_buf[1])&&(tmp_buf[0] == tmp_buf[2]))
		{
			cmd = tmp_buf[0];
		}
    }
}
static  void  App_Task_ACTION (void *p_arg)//construct new task in this function
{	
    while (1) 
	{ 	
		if(cmd != cmd_last)
		{
			cmd_last = cmd;
			switch ( cmd )
			{
				case '1':Stand_Up(ACTION_DELAY);break;
				case '2':Stamp('2',&cmd);break;
				case '3':Sit_Down(ACTION_DELAY);break;
				case '4':Go_straight('4',&cmd);break;
				case '5':LED3(On);	break;	
				case '6':Turn('6',&cmd);  break;
				default :break;
			}
		}
    }
}


