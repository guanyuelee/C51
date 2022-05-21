#include "sleep.h"
#include "display.h"

unsigned int numbers[8] = {0, 1, 2, 3, 4, 5, 6, 7}; 
unsigned int locations[8] = {1, 2, 3, 4, 5, 6, 7, 8}; 

void main(){
	LCD_Init();
	LCD_ShowChar(1, 1, 'A');
	LCD_ShowString(1, 3, "Hello"); 
	LCD_ShowNum(1, 9, 123, 3); 
	LCD_ShowSignedNum(1, 13, -66, 2); 
	LCD_ShowHexNum(2, 1, 0xA8, 2); 
	LCD_ShowBinNum(2, 4, 0xAA, 8);
	while(1); 
	
	/**
	LCD_Init(); 
	LCD_ShowString(1, 1, "Hi, Guanyue Li"); 
	LCD_ShowString(2, 1, "Welcome to C51!");
	while(1);
	*/
	
	/**
	while(1){
		unsigned char i = 0;
		while(i < 8){
			displayInNixie(locations[i], numbers[i]); 
			i += 1; 
		}
	}
	*/
}




