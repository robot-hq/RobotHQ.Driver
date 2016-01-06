#include "led.h"
#include "ucos_ii.h"
#include "app_cfg.h"
#include "bsp.h"

void LED_Init(void)
{
   GPIO_InitTypeDef GPIO_InitStructure;		                                              //����GPIO��ʼ���ṹ��
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);			      //ʹ��GPIOA��GPIOB��AHP1ʱ��
   GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;												                      //�����ʼ���Ĺܽ�ΪPin1
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;										                    //���ó�ʼ��ģʽΪ���ģʽ
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;										                    //�����������Ϊ�������
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;									                  //��������ٶ�Ϊ100Mhz
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;										                  //������/��������Ϊ��������������
   GPIO_Init(GPIOD, &GPIO_InitStructure);												                        //��ʼ��GPIOA��Pin_1�ܽ�

   GPIO_ResetBits(GPIOD,GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);														                          //ʹGPIOB��Pin_14����ߵ�ƽ
}

