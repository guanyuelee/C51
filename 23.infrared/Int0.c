/*
 * @Author       : Guanyue li
 * @Date         : 2022-05-30 20:24:03
 * @LastEditTime : 2022-05-30 20:47:29
 * @Description  : file content
 * @FilePath     : \23.infrared\Int0.c
 */
#include<REGX52.H>

void Int0_Init(void){
	IT0 = 1; 
	IE0 = 0; 
	EX0 = 1;
	EA = 1;
	PX0 = 1; 
}


