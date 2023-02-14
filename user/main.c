#include "stm32f10x.h"
#include "main.h"
#include "delay.h"
#include "OLED_I2C.h"
#include "ds18b20.h"
short temperature;
u16 wd=300;
void KEY_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD ;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_WriteBit(GPIOB,GPIO_Pin_12,Bit_SET);//1
}

uint8_t Key_Scan2(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{
	if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin)==0)
	{
		delay_us(2);
		return 0;		
	}
	else return 1;	
		
}
int main(void)
{
	delay_init();	    	 
	KEY_GPIO_Config();
	DS18B20_Init();
	IIC_Init();	 									

 	OLED_Init();									
	OLED_Clear();									
	    OLED_ShowCHinese(0,0,0);
        OLED_ShowCHinese(16,0,1);
		OLED_ShowChar(32,0,':',16);
	while(1)
	{
			if(Key_Scan2(GPIOA,GPIO_Pin_1)==0)
			{	
				wd=wd+1;
			}
			if(Key_Scan2(GPIOA,GPIO_Pin_2)==0)
			{
				wd=wd-1;	
			}
	    temperature=DS18B20_GetTemperture()*10;
		  OLED_ShowNum(40,0,temperature/100,1,16);
      OLED_ShowNum(48,0,temperature%100/10,1,16);	
		  OLED_ShowChar(56,1,'.',0);
		  OLED_ShowNum(64,0,temperature%10,1,16);
		  OLED_ShowNum(90,0,wd/100,1,16);
      OLED_ShowNum(98,0,wd%100/10,1,16);
			OLED_ShowChar(106,1,'.',0);
			OLED_ShowNum(114,0,wd%10,1,16);
		
		 if(wd<temperature) GPIO_WriteBit(GPIOB,GPIO_Pin_12,Bit_RESET);
		 else GPIO_WriteBit(GPIOB,GPIO_Pin_12,Bit_SET);
	} 
}
