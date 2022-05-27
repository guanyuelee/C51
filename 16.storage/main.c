/*
 * @Author       : Guanyue li
 * @Date         : 2022-05-27 18:57:51
 * @LastEditTime : 2022-05-27 23:48:31
 * @Description  : file content
 * @FilePath     : \16.storage\main.c
 */

#include <REGX52.H>
#include "display.h"
#include "keyboard.h"
#include "sleep.h"
#include "AT24C02.h"

// unsigned char byte; 
unsigned char key;
unsigned int num=66;

void main(){
	LCD_Init();
	// LCD_ShowString(1, 1, "Hello");
	// 注释掉是为了看掉电是否丢失内容
	// AT24C02_WriteByte(0, 111);
	// sleep(5);
	// AT24C02_WriteByte(1, 66);
	// sleep(5);
	// AT24C02_WriteByte(2, 40);
	// sleep(5);         // 必须暂停5ms保证写入。
	// byte = AT24C02_ReadByte(2);
	// LCD_ShowNum(2, 1, byte, 2);
	LCD_ShowNum(1, 1, num, 5);
	
	while(1){
		key = listenLineKey(); 
		
		if(key == 1){
			num++; 
			LCD_ShowNum(1, 1, num, 5);
		}else if(key == 2){
			num--; 
			LCD_ShowNum(1, 1, num, 5);
		}else if(key == 3){
			AT24C02_WriteByte(0, num/256); 
			sleep(5); 
			AT24C02_WriteByte(1, num%256);
			sleep(5);
			LCD_ShowString(2, 1, "Write Ok");
			sleep(1000);
			LCD_ShowString(2, 1, "        ");
		}else if(key == 4){
			num = AT24C02_ReadByte(0); 
			num = AT24C02_ReadByte(1) | (num << 8);
			LCD_ShowNum(1, 1, num, 5);
			LCD_ShowString(2, 1, "Read Ok");
			sleep(1000);
			LCD_ShowString(2, 1, "       ");
		}
	}
}