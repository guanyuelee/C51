/*
 * @Author       : Guanyue li
 * @Date         : 2022-05-28 18:48:23
 * @LastEditTime : 2022-05-28 19:39:57
 * @Description  : file content
 * @FilePath     : \18.temperature\DS18B20.c
 */
#include <REGX52.H>
#include "oneWire.h"
#include "display.h"

#define DS18B20_SKIP_ROM 0xCC
#define DS18B20_CONVERT_T 0x44
#define DS18B20_READ_SCRATCHPAD 0xBE

void DS18B20_ConvertT(void){
    ONEWIRE_Init(); 
    ONEWIRE_SendByte(DS18B20_SKIP_ROM);
    ONEWIRE_SendByte(DS18B20_CONVERT_T);
}

float DS18B20_ReadTemperature(void){
    unsigned char TLSB, TMSB; 
    int temp; 
    float res; 
    ONEWIRE_Init(); 
    ONEWIRE_SendByte(DS18B20_SKIP_ROM);
    ONEWIRE_SendByte(DS18B20_READ_SCRATCHPAD);
    TLSB = ONEWIRE_ReceiveByte(); 
    TMSB = ONEWIRE_ReceiveByte(); 
    LCD_ShowBinNum(1, 1, TMSB, 8); 
    LCD_ShowBinNum(1, 9, TLSB, 8);
    temp = (TMSB << 8) | TLSB; 
    res = temp / 16.0;
}

