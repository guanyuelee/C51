/* 遥控控制电机速度。
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
#include "IR.h"

unsigned char command;

void main()
{
	MOTOR_Init();
	IR_Init(); 

	setNixieBuffer(1, MOTOR_GetSpeed());
	while (1)
	{
		if (IR_GetDataFlag() || IR_GetRepeatFlag())
		{
			command = IR_GetCommand();

			if (command == BTN_NUM_0)
			{
				MOTOR_SetSpeed(0);
				MOTOR_SetThred(0);
			}
			else if (command == BTN_NUM_1)
			{
				MOTOR_SetSpeed(1);
				MOTOR_SetThred(50);
			}
			else if (command == BTN_NUM_2)
			{
				MOTOR_SetSpeed(2);
				MOTOR_SetThred(75);
			}
			else if (command == BTN_NUM_3)
			{
				MOTOR_SetSpeed(3);
				MOTOR_SetThred(100);
			}
			else{
				MOTOR_SetSpeed(0);
				MOTOR_SetThred(0);
			}

			setNixieBuffer(1, MOTOR_GetSpeed());
		}
	}
}

/**
 * @description: 产生100us的定时器
 * @return {*} 无
 */
void timer1Routine() interrupt 3
{
	static unsigned char count_motor = 0, count_nixie = 0;
	TL1 = 0xA4; //设置定时初值
	TH1 = 0xFF; //设置定时初值

	count_motor++;
	if (count_motor >= 2)
	{
		MOTOR_Loop();
		count_motor = 0;
	}

	count_nixie++;
	if (count_nixie > 10)
	{
		nixieLoop();
		count_nixie = 0;
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
