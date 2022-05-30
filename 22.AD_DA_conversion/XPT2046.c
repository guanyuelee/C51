/*
 * @Author       : Guanyue li
 * @Date         : 2022-05-30 14:14:24
 * @LastEditTime : 2022-05-30 16:40:09
 * @Description  : file content
 * @FilePath     : \22.AD_DA_conversion\XPT2046.c
 */
#include <REGX52.H>
#include "sleep.h"

sbit XPT2046_CS = P3^5; 
sbit XPT2046_DCLK = P3^6; 
sbit XPT2046_DIN = P3^4; 
sbit XPT2046_DOUT = P3^7; 

unsigned int XPT2046_ReadAD(unsigned char command){
    unsigned int ad_value=0; 
    unsigned char i; 

    XPT2046_DCLK = 0; 
    XPT2046_CS = 0; 
    
    for(i=0; i<8; i++){
        XPT2046_DIN = (command & (0x80 >> i)); 
        XPT2046_DCLK = 1; 
        XPT2046_DCLK = 0; 
    }
	XPT2046_DIN = 0; 
    
    for(i=0; i<16; i++){
        XPT2046_DCLK = 1; 
        XPT2046_DCLK = 0; 
        if(XPT2046_DOUT){
            ad_value |= (0x8000 >> i);
        }
    }
    XPT2046_CS = 1; 
    
	if(command & 0x08){
		return ad_value >> 8; 
	}else{
		return ad_value >> 4;
	}
		
    return ad_value >> 8; 
}