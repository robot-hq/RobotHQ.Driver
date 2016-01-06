#include "delay.h"
 /******************************************************************************
  * 文件路径  ：   Hardware/delay/delay.c 
  * 作者      ：   农晓明   QQ：382421307
  * 固件库版本：   V1.0.0
  * 日期      ：   2012-03-28
  * 文件描述  ：   提供基本的延时函数
  ******************************************************************************/
 static __IO uint32_t TimingDelay;
/***************************************************************************
*函数名：SysTick_Init()
*参数：void
*返回值:void
*功能：系统节拍时钟初始化函数
*****************************************************************************/
void SysTick_Init(void)
{
	 /****************************************
	 *SystemFrequency/1000      1ms中断一次  *
	 *SystemFrequency/100000    10us中断一次 *
	 *SystemFrequency/1000000   1us中断一次  *
	 *****************************************/
    while(SysTick_Config(SystemCoreClock/1000)!=0);    //设置系统节拍时钟为1us中断一次
	
	/*附加笔记：
	SysTick_Config(uint32_t ticks)函数为core_cm4.h中定义的设置节拍时钟的函数，当设置成功时，返回0，失败返回1
	*/
}
/***************************************************************************
*函数名：TimeTick_Decrement()
*参数：void
*返回值:void
*功能：系统节拍时钟中断计数，给系统节拍中断函数调用
*****************************************************************************/ 
void TimeTick_Decrement(void)
{
  if (TimingDelay != 0x00)
  { 
    TimingDelay--;
  }
}
/***************************************************************************
*函数名：delay_nus()
*参数：u32 n  时钟延时的微秒数
*返回值:void
*功能：使用系统节拍时钟精准延时n个微秒函数
*****************************************************************************/
void delay_nus(u32 n)
{
	TimingDelay=n;
	while(TimingDelay!=0);
}
 /***************************************************************************
*函数名：delay_1ms()
*参数：void
*返回值:void
*功能：使用系统节拍时钟精准延时1个毫秒函数
*****************************************************************************/
void delay_1ms(void)
{
    TimingDelay=1;
	while(TimingDelay!=0);
}
/***************************************************************************
*函数名：delay_nms()
*参数：u32 n  时钟延时的毫秒数
*返回值:void
*功能：系统节拍时钟初始化函数
*****************************************************************************/
void delay_nms(u32 n)
{
  while(n--)delay_1ms();
}
