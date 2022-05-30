/*
 * @Author       : Guanyue li
 * @Date         : 2022-05-28 22:14:16
 * @LastEditTime : 2022-05-28 23:48:58
 * @Description  : file content
 * @FilePath     : \19.temperature_warning\main.c
 */
#include <REGX52.H>
#include "display.h"
#include "sleep.h"
#include "keyboard.h"
#include "AT24C02.h"
#include "DS18B20.h"
#include "timer0.h"

float temperature; 
char th, tl, key; 
void main(){
    DS18B20_ConvertT(); 
    sleep(1000); 
    
    timer0Init();
    LCD_Init(); 
    LCD_ShowString(1, 1, "T:        "); 
    LCD_ShowString(2, 1, "TH:"); 
    LCD_ShowString(2, 9, "TL:"); 
    
    th = AT24C02_ReadByte(0); 
    tl = AT24C02_ReadByte(1); 
    
    if(th >= 125 || tl < -55 || th <= tl){
        th = 25;
        tl = 18; 
    }

    while(1){
        key = listenLineKey();
        DS18B20_ConvertT();  
        temperature = DS18B20_ReadTemperature(); 
        LCD_ShowFloat(1, 3, temperature, 2, 4); 

        LCD_ShowSignedNum(2, 4, th, 3);
        LCD_ShowSignedNum(2, 12, tl, 3);

        if(key == 1){ th++; if(th >= 125){th = 125; } AT24C02_WriteByte(0, th);}
        if(key == 2){ th--; if(th <= tl){th++; } AT24C02_WriteByte(0, th);}
        if(key == 3){ tl++; if(th <= tl){tl--; } AT24C02_WriteByte(1, tl);}
        if(key == 4){ tl--; if(tl <= -55){tl=-55; } AT24C02_WriteByte(1, tl);}

        if(temperature > th) {
            LCD_ShowString(1, 12, "Hot "); 
        }
        else if(temperature < tl) {
            LCD_ShowString(1, 12, "Cold"); 
        }
		else{
			LCD_ShowString(1, 12, "    "); 
		}
    }
}

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