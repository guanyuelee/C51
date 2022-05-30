#include <REGX52.H>
#include "sleep.h"

sbit LCD_RS = P2^6; 
sbit LCD_RW = P2^5; 
sbit LCD_E = P2^7; 

#define LCD_DataPort P0

void LCD_WriteCommand(unsigned char command){
	LCD_RS = 0; 
	LCD_RW = 0; 
	LCD_DataPort = command; 
	LCD_E = 1; 
	sleep(1); 
	LCD_E = 0;
	sleep(1); 
}

void LCD_WriteData(unsigned char byte){
	LCD_RS = 1; 
	LCD_RW = 0; 
	LCD_DataPort = byte; 
	LCD_E = 1; 
	sleep(1); 
	LCD_E = 0;
	sleep(1); 
}

void LCD_Init(void){
	LCD_WriteCommand(0x38); 
	LCD_WriteCommand(0x0C); 
	LCD_WriteCommand(0x06);
	LCD_WriteCommand(0x01); 
}

void LCD_ShowChar(unsigned char line, unsigned char column, unsigned char ch){
	if(line == 1){
		LCD_WriteCommand(0x80|(column - 1));
	}
	else{
		LCD_WriteCommand(0x80|(column - 1) + 0x40); 
	}
	LCD_WriteData(ch); 
}

void LCD_SetCursor(unsigned char line, unsigned char column){
	if(line == 1){
		LCD_WriteCommand(0x80|(column - 1));
	} 
	else{
		LCD_WriteCommand(0x80|(column - 1) + 0x40); 
	}
}

void LCD_ShowString(unsigned char line, unsigned char column, unsigned char str[]){
	unsigned char i; 
	LCD_SetCursor(line, column); 
	for(i=0; str[i] != '\0'; i++){
		LCD_WriteData(str[i]); 
	}
}











