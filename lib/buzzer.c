#include "sleep.h"
#include <REGX52.H>
#include <INTRINS.H>

sbit BUZZER=P2^5;

//@11.0592MHz
void buzzerDelay500us(){
	unsigned char i;
	_nop_();
	i = 227;
	while (--i);
}

void buzzerTime(unsigned int ms){
	unsigned int i; 
	for(i=0; i<ms; i++){
		BUZZER = !BUZZER; 
		buzzerDelay500us(); 
	}
}