#include "usart.h"
 /******************************************************************************
  * �ļ�·��  ��   Hardware/usart/usart.c 
  * ����      ��   ũ����   QQ��382421307
  * �̼���汾��   V1.0.0
  * ����      ��   2012-03-28
  * �ļ�����  ��   �ṩ�԰��ϴ��ڵ�����
  ******************************************************************************/
/*******************************************************************************************************************************
 * ��������USART1_Config()
 * ��������
 *����ֵ����
 * ���ܣ�����USART1������ʼ��
********************************************************************************************************************************/																		
void USART1_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;                                          //����GPIO��ʼ���ṹ��
	USART_InitTypeDef USART_InitStructure;                                         //����USART��ʼ���ṹ��
	/*���ø��ùܽ�TXD(PA9)��RXD(PA10)���ӵ�USART1*/
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_USART1);						             //����PA9�������ӵ�USART1
    GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_USART1);					           //����PA10�������ӵ�USART1
		/*����USART1��Ӧ��ʱ��*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);                          //ʹ��GPIOA��AHB1ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);                        //ʹ��USART1��APB2ʱ��
	/*����USART1�ķ��͹ܽ�TXD(PA9)Ϊ�����������*/
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;                                       //���ó�ʼ��GPIOΪPIN9
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;                               //����GPIO���ٶ�Ϊ50MHz
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;                                    //����GPIOģʽΪ����ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								                //����GPIO�������Ϊ�������
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;						                    //����GPIOΪ������������
	GPIO_Init(GPIOA,&GPIO_InitStructure);                                         //��ʼ��GPIOA��PIN9
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;                                      //���ó�ʼ��GPIOΪPIN10
	/*����USART1�Ľ��չܽ�RXD(PA10)Ϊ��������*/
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;                                    //����GPIO��ģʽΪ����ģʽ
	GPIO_Init(GPIOA,&GPIO_InitStructure);                                         //��ʼ��GPIOA��PIN10

	/*����USART1��ģʽ*/
    USART_InitStructure.USART_BaudRate=115200;                                    //����USART�Ĳ�����Ϊ115200
    USART_InitStructure.USART_Parity=USART_Parity_No;                             //����USART��У��λΪNone
    USART_InitStructure.USART_WordLength=USART_WordLength_8b;                     //����USART������λΪ8bit
    USART_InitStructure.USART_StopBits=USART_StopBits_1;                          //����USART��ֹͣλΪ1
    USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None; //ʧ��Ӳ��������
    USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;                   //����USART��ģʽΪ���ͽ���ģʽ
    USART_Init(USART1,&USART_InitStructure);                                      //��ʼ��USART1
    USART_Cmd(USART1,ENABLE);                                                     //ʹ��USART1
}


/********************************************************************************************************************************
*��������fputc()
* ������int ch��FILE *f
* ����ֵ��int
* ���ܣ����¶���stdio.h�е�fputc()������ʹprintf()�����USART1
*********************************************************************************************************************************/
int fputc(int ch,FILE *f)
{
  USART_SendData(USART1,(u8)ch);	                                                   //��ch��USART1���ͳ�ȥ
  while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)				               //�ȴ��������
  {
  }											  
  return ch;																	   //���� ch
}																		           








