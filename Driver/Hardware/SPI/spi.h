#ifndef __SPI_H
#define __SPI_H
 				  	    													  
void SPI1_Init(void);			 //��ʼ��SPI��
void SPI1_SetSpeed(uint8_t SpeedSet); //����SPI�ٶ�   
uint8_t SPI1_ReadWriteByte(uint8_t TxData);//SPI���߶�дһ���ֽ�
		 
#endif

