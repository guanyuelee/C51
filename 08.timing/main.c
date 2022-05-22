#include <REGX52.H>
#include "timer0.h"
#include "key.h"
#include "INTRINS.H"

unsigned char key, mode=0; 

void main(){
	timer0Init();
	P2 = 0xFE; 
	while(1){
		key = listenKey(); 
		if(key){
			if(key == 1) {mode = 1; key = 0;} 
			if(key == 2) {mode = 2; key = 0;} 
		}
	}
}

unsigned int T0Count = 0; 

void timer0Routine() interrupt 1
{
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count++; 
	if(T0Count >= 500){
		if(mode == 1){
			P2 = _crol_(P2, 1);
		} 
		if(mode == 2){
			P2 = _cror_(P2, 1);
		}
		T0Count = 0; 
	}
}