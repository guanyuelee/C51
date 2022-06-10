/*
 * @Author       : Guanyue li
 * @Date         : 2022-05-30 18:21:58
 * @LastEditTime : 2022-05-30 23:29:34
 * @Description  : file content
 * @FilePath     : \23.infrared\main.c
 */
#include <REGX52.H>
#include "display.h"
#include "sleep.h"
#include "Int0.h"
#include "Timer0.h"
#include "IR.h"

unsigned char num; 
unsigned int time; 
unsigned char address, command; 

void main(){
	LCD_Init();  
	IR_Init(); 

	LCD_ShowString(1, 1, "ADDR  CMD  NUM");
	LCD_ShowString(2, 1, "00    00   000");

	while (1)
	{
		if(IR_GetDataFlag() || IR_GetRepeatFlag()){
			address = IR_GetAddress();
			command = IR_GetCommand();
			LCD_ShowHexNum(2, 1, address, 2);
			LCD_ShowHexNum(2, 7, command, 2);

			if(command == BTN_VOLUME_MINUS){
				num --; 
			}
			
			if(command == BTN_VOLUME_PLUS){
				num ++; 
			}

			LCD_ShowNum(2, 12, num, 3);
		}
	}
}


