#include <REGX52.H>

void UARTInit(){
	PCON &= 0x7F;		//波特率不倍速  0111 1111
	SCON = 0x40; 
	TMOD &= 0x0F;		//清除定时器1模式位
	TMOD |= 0x20;		//设定定时器1为8位自动重装方式
	TL1 = 0xFA;		//设定定时初值
	TH1 = 0xFA;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
}

void UARTSendByte(unsigned char byte){
	SBUF = byte; 
	while(TI == 0);
	TI = 0; 
}