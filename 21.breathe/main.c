#include <REGX52.H>
#include "sleep.h"
#include "keyboard.h"
#include "display.h"
#include "timer0.h"

unsigned char count = 0, thred, speed, key; 

sbit LED = P2^1; 
sbit MOTOR = P1^0; 

void main(){
	timer0Init(); 

	while(1){
		key = listenLineKey(); 
		if(key == 1){
			speed++; 
			speed%=4; 

			if(speed == 0){
				thred=0; 
			}
			else if(speed == 1){
				thred=50; 
			}
			else if(speed == 2){
				thred=80; 
			}
			else {
				thred=100;
			}
		}
		setNixieBuffer(1, speed); 
	}
}

/**
 * @description: 产生100us的定时器
 * @return {*} 无
 */
void timer0Routine() interrupt 1{
	static unsigned char count_nixie, count_kb=0; 
	TL0 = 0xA4;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	count ++;
	count %= 100; 
	if(count > thred) {
		LED = 0; 
		MOTOR = 0; 
	}else{
		LED = 1; 
		MOTOR = 1; 
	}

	count_nixie++; 
	if(count_nixie > 10){
		nixieLoop(); 
		count_nixie=0; 
	}
	
	// 
	count_kb++;
	if(count_kb > 20){
		listenKeyLoop(); 
		count_kb = 0; 
	}
}

/* sbit LED = P2^0; 

unsigned char time, i; 
void sleep2(unsigned char time);

void main(){
	
	while(1){
		for(time=0; time < 101; time++){
			for(i=0; i<20; i++){
				LED = 1; 
				sleep2(time); 
				LED = 0; 
				sleep2(100 - time);
			}
		}
		
		for(time=0; time < 101; time++){
			for(i=0; i<20; i++){
				LED = 1; 
				sleep2(100 - time); 
				LED = 0; 
				sleep2(time);
			}
		}
	}
}

void sleep2(unsigned char time)
{
	while(time--);
} */
