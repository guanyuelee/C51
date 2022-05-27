/*
 * @Author       : Guanyue li
 * @Date         : 2022-05-27 18:57:51
 * @LastEditTime : 2022-05-27 23:12:01
 * @Description  : file content
 * @FilePath     : \16.storage\main.c
 */

#include <REGX52.H>
#include "display.h"
#include "keyboard.h"
#include "AT24C02.h"

void main(){
	LCD_Init();
	LCD_ShowString(1, 1, "Hello"); 
	AT24C02_WriteByte(0, 0); 
	
	while(1){
		
	}
}