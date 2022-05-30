/*
 * @Author       : Guanyue li
 * @Date         : 2022-05-28 18:38:36
 * @LastEditTime : 2022-05-28 19:43:49
 * @Description  : file content
 * @FilePath     : \18.temperature\main.c
 */
#include <REGX52.H>
#include "display.h"
#include "oneWire.h"
#include "sleep.h"
#include "DS18B20.h"

unsigned char ack; 
float temperature; 

void main(){
    DS18B20_ConvertT(); 
    sleep(1000); 

    LCD_Init();
    // LCD_ShowString(1, 1, "Temperature: "); 
    
    while(1){
        DS18B20_ConvertT(); 
        temperature = DS18B20_ReadTemperature(); 
        if(temperature < 0){
            LCD_ShowChar(2, 1, '-');
            temperature = -temperature;  
        }
        else{
            LCD_ShowChar(2, 1, '+');
        }
        LCD_ShowNum(2, 2, temperature, 3);
        LCD_ShowChar(2, 5, '.');
        LCD_ShowNum(2, 6, (unsigned long)(temperature*10000)%10000, 4);
    }
}
