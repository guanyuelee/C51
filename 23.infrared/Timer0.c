/*
 * @Author       : Guanyue li
 * @Date         : 2022-05-30 20:41:00
 * @LastEditTime : 2022-05-30 20:43:09
 * @Description  : file content
 * @FilePath     : \23.infrared\Timer0.c
 */
#include <REGX52.H>

// 1 ms. 
void timer0Init(void){
	// TMOD = 0x01
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0;		//设置定时初值
	TH0 = 0;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 0;		//定时器0不开始计时
}

void timer0SetCounter(unsigned int value){
    TH0 = value / 256; 
    TL0 = value % 256; 
}

unsigned int timer0GetCount(void){
    return (TH0 << 8) | TL0; 
}

void timer0Run(unsigned char flag){
    TR0 = flag; 
}