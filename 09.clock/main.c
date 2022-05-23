#include <REGX52.H>
#include "display.h"
#include "sleep.h"
#include "timer0.h"

unsigned int sec = 0; 
unsigned int min = 0; 
unsigned int hour = 0; 
unsigned int msec = 0; 

static unsigned int t0Count = 0; 

void main(){
	LCD_Init(); 
	timer0Init(); 
	
	LCD_ShowString(1, 1, "Clock: "); 
	
	while(1){
		LCD_ShowNum(2, 1, hour, 2);
		LCD_ShowString(2, 3, ":"); 
		
		LCD_ShowNum(2, 4, min, 2);
		LCD_ShowString(2, 6, ":"); 
		
		LCD_ShowNum(2, 7, sec, 2);
		LCD_ShowString(2, 9, ":"); 
		
		LCD_ShowNum(2, 10, msec, 2);
	}
}

void Timer0_Routine() interrupt 1{
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	t0Count ++; 
	if(t0Count >= 100){
		t0Count = 0; 
		msec ++;
		if(msec >= 10) {
			msec = msec % 10; 
			sec++; 
		}
		if(sec >= 60){
			sec = sec % 60; 
			min++; 
		}
		if(min >= 60){
			min = min % 60;
			hour++; 
		}
		if(hour >= 24){
			hour = hour % 24;
		}
	}
}