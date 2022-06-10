/*
 * @Author       : Guanyue li
 * @Date         : 2022-05-30 23:41:42
 * @LastEditTime : 2022-05-31 00:15:12
 * @Description  : file content
 * @FilePath     : \21.breathe\motor.c
 */
#include <REGX52.H>
#include "timer1.h"

sbit MOTOR = P1^0; 

unsigned char speed=0, count = 0, thred=0; 

void MOTOR_Init(void){
	timer1Init(); 
}

void MOTOR_SetSpeed(unsigned char s){
	if(s > 3){
		speed = 0;
	}
	else{
		speed = s;
	} 
}

unsigned char MOTOR_GetSpeed(void){
	return speed;  
}

void MOTOR_SetThred(unsigned char s){
	thred = s; 
}

void MOTOR_Loop(void){
	count++; 
	if(count >= thred) {
		MOTOR = 0; 
	}else{
		MOTOR = 1; 
	}
}

/*
void timer1Routine() interrupt 3{
	static unsigned char count_nixie=0, count_kb=0; 
	TL1 = 0xA4;		//设置定时初值
	TH1 = 0xFF;		//设置定时初值
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
*/
