/*按键控制电机运动速度
 * @Author       : Guanyue li
 * @Date         : 2022-05-30 00:06:18
 * @LastEditTime : 2022-05-31 00:09:52
 * @Description  : file content
 * @FilePath     : \21.breathe\main.c
 */
#include <REGX52.H>
#include "sleep.h"
#include "keyboard.h"
#include "display.h"
#include "motor.h"

unsigned char key; 

sbit LED = P2^1; 

void main2(){
	MOTOR_Init(); 

	while(1){
		key = listenLineKey(); 
		if(key == 1){
			MOTOR_SetSpeed(MOTOR_GetSpeed() + 1);   

			if(MOTOR_GetSpeed() == 0){
				MOTOR_SetThred(0);
			}
			else if(MOTOR_GetSpeed() == 1){
				MOTOR_SetThred(50);
			}
			else if(MOTOR_GetSpeed() == 2){
				MOTOR_SetThred(80);
			}
			else {
				MOTOR_SetThred(100);
			}
		}
		setNixieBuffer(1, MOTOR_GetSpeed()); 
	}
}

/**
 * @description: 产生100us的定时器
 * @return {*} 无
 */
void timer1Routine() interrupt 3{
	static unsigned char count_motor=0, count_nixie=0, count_kb=0; 
	TL1 = 0xA4;		//设置定时初值
	TH1 = 0xFF;		//设置定时初值
	
	count_motor++;
	if(count_motor >= 2){
		MOTOR_Loop(); 
		count_motor = 0; 
	}
	
	count_nixie++; 
	if(count_nixie > 10){
		nixieLoop(); 
		count_nixie=0; 
	}
	count_kb++;
	if(count_kb > 20){
		listenKeyLoop(); 
		count_kb = 0; 
	}
}

/* 这里的代码是用来实现呼吸灯的。 

sbit LED = P2^0; 

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
