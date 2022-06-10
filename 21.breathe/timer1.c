/*
 * @Author       : Guanyue li
 * @Date         : 2022-05-28 00:05:39
 * @LastEditTime : 2022-05-28 10:28:46
 * @Description  : file content
 * @FilePath     : \17.listenerKeyboard\timer0.c
 */
#include <REGX52.H>

void timer1Init(){
	// TMOD = 0x01
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x10;		//设置定时器模式
	TL1 = 0x66;		//设置定时初值
	TH1 = 0xFC;		//设置定时初值
	TF1 = 0;		//清除TF1标志
	TR1 = 1;		//定时器1开始计时
	ET1 = 1;
	EA = 1;
	PT1 = 0;
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


/*
void timer0Routine() interrupt 3{
	static unsigned int count;
	TL1 = 0x66;	
	TH1 = 0xFC;	
	count ++;
	if(count >= 500){
		count = 0;	
	}
}
*/
