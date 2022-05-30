/*
 * @Author       : Guanyue li
 * @Date         : 2022-05-30 14:13:32
 * @LastEditTime : 2022-05-30 16:17:18
 * @Description  : file content
 * @FilePath     : \22.AD_DA_conversion\main.c
 */
#include <REGX52.H>
#include "display.h"
#include "sleep.h"
#include "XPT2046.h"

unsigned int ADValue=0; 

void main(){
    LCD_Init(); 
    LCD_ShowString(1, 1, "ADJ  NTC  RG"); 
    while(1){
        ADValue = XPT2046_ReadAD(XPT2046_XP_8); 
        LCD_ShowNum(2, 1, ADValue, 3); 
        sleep(10); 
		ADValue = XPT2046_ReadAD(XPT2046_YP_8); 
        LCD_ShowNum(2, 6, ADValue, 3); 
        sleep(10); 
		ADValue = XPT2046_ReadAD(XPT2046_VBAT_8); 
        LCD_ShowNum(2, 11, ADValue, 3); 
        sleep(10); 
    }
}