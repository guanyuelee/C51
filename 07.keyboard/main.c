#include <REGX52.H>
#include "display.h"
#include "sleep.h"
#include "keyboard.h"

unsigned char keyNum; 
unsigned int password = 5402; 
unsigned int input = 0; 
unsigned int count = 1; 

void main(){
	LCD_Init(); 
	LCD_ShowString(1, 1, "Password:"); 
	while(1) { 
		keyNum = listenKey();
		if(keyNum != 0 && keyNum <= 10){
			keyNum = keyNum % 10; 
			input = input * 10 + keyNum; 
			if(count > 4){
				LCD_ShowString(2, 1, "Length exceed!");
				input = 0;
				count = 1; 
			}else{
				LCD_Clear(2);
				LCD_ShowNum(2, 1, input, count); 
				count += 1; 
			}
		}else if(keyNum == 11){
			if(input == password){
				LCD_ShowString(2, 1, "Pwd correct!");
				sleep(1000); 
				break; 
			} else{
				LCD_ShowString(2, 1, "Pwd incorrect!");
				input = 0;
				count = 1;
			}
		}else if(keyNum == 12){
			LCD_ShowString(2, 1, "Reset");
			input = 0;
			count = 1; 
		}
	}
	
	LCD_Clear(1); 
	LCD_Clear(2); 
	while(1){
		LCD_ShowString(1, 1, "Welcome,");
		LCD_ShowString(2, 1, "My master.");
	}
}