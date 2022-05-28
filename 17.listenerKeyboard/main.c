/*
 * @Author       : Guanyue li
 * @Date         : 2022-05-28 00:05:45
 * @LastEditTime : 2022-05-28 10:57:18
 * @Description  : file content
 * @FilePath     : \17.listenerKeyboard\main.c
 */
#include <REGX52.H>
#include "timer0.h"
#include "keyboard.h"
#include "display.h"

unsigned char key; 

void main(){
    timer0Init(); 
    while(1){
        key = listenLineKey();
        if(key != 0){
            setNixieBuffer(1, key);
            setNixieBuffer(2, key);
            setNixieBuffer(3, key);
        }
    }
}

void timer0Routine() interrupt 1{
	static unsigned int count_linekb, count_nixie;
	TL0 = 0x66;	
	TH0 = 0xFC;	
	count_linekb ++;
	if(count_linekb >= 20){
        listenKeyLoop(); 
        count_linekb=0; 
	}
    count_nixie++; 
    if(count_nixie >= 1000/NIXIE_FPS){
        nixieLoop(); 
        count_nixie=0; 
	}
}