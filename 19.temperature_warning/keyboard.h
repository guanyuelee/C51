/*
 * @Author       : Guanyue li
 * @Date         : 2022-05-27 18:58:51
 * @LastEditTime : 2022-05-28 23:05:42
 * @Description  : file content
 * @FilePath     : \19.temperature_warning\keyboard.h
 */
#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

// They listen the key pressed by the user. 

/**
 * @description: 监听矩阵按键 
 * @return {返回一个1-16的值，代表被按的按键}
 */
unsigned char listenMatrixKey();

/**
 * @description: 监听一行的按键
 * @return {返回1-4的值，代表被按下的按键}
 */
unsigned char listenLineKey(); 

/**
 * @description: 监听行按键的循环，需要在main函数中每隔一段时间循环。 
 * @return {*} 无
 * 实例：
 * 
void timer0Routine() interrupt 1{
	static unsigned int count_linekb;
	TL0 = 0x66;	
	TH0 = 0xFC;	
	count_linekb ++;
	if(count_linekb >= 20){
        listenKeyLoop(); 
        count_linekb=0; 
	}
}
 */
void listenKeyLoop();
#endif
