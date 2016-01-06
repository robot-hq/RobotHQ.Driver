#include "led.h"
#include "ucos_ii.h"
#include "app_cfg.h"
#include "bsp.h"

void LED_Init(void)
{
   GPIO_InitTypeDef GPIO_InitStructure;		                                              //定义GPIO初始化结构体
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);			      //使能GPIOA和GPIOB的AHP1时钟
   GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;												                      //定义初始化的管脚为Pin1
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;										                    //设置初始化模式为输出模式
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;										                    //设置输出类型为推挽输出
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;									                  //设置输出速度为100Mhz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;										                  //设置上/下拉电阻为无上拉下拉电阻
   GPIO_Init(GPIOD, &GPIO_InitStructure);												                        //初始化GPIOA的Pin_1管脚

   GPIO_ResetBits(GPIOD,GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);														                          //使GPIOB的Pin_14输出高电平
}

