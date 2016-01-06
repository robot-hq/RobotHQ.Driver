#ifndef __DELAY_H
#define __DELAY_H
#include "stm32f4xx.h"
 /******************************************************************************
  * 文件路径  ：   Hardware/delay/delay.h 
  * 作者      ：   农晓明   QQ：382421307
  * 固件库版本：   V1.0.0
  * 日期      ：   2012-03-28
  * 文件描述  ：   提供基本的延时函数
  ******************************************************************************/
/***************************************************************************
*函数名：SysTick_Init()
*参数：void
*返回值:void
*功能：系统节拍时钟初始化函数
*****************************************************************************/
void SysTick_Init(void);
/***************************************************************************
*函数名：delay_nus()
*参数：u32 n  时钟延时的微秒数
*返回值:void
*功能：使用系统节拍时钟精准延时n个微秒函数
*****************************************************************************/
void delay_nus(u32 n);
 /***************************************************************************
*函数名：delay_1ms()
*参数：void
*返回值:void
*功能：使用系统节拍时钟精准延时1个毫秒函数
*****************************************************************************/
void delay_1ms(void);
/***************************************************************************
*函数名：delay_nms()
*参数：u32 n  时钟延时的毫秒数
*返回值:void
*功能：系统节拍时钟初始化函数
*****************************************************************************/
void delay_nms(u32 n);
#endif
