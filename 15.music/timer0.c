#include <REGX52.H>

// 1 ms. 
void timer0Init(){
	// TMOD = 0x01
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0 = 1;
	EA = 1;
	PT0 = 0;
}

/*
void timer0Routine() interrupt 1{
	static unsigned int count;
	TL0 = 0x66;	
	TH0 = 0xFC;	
	count ++;
	if(count >= 500){
		count = 0;
		
	}
}
*/
