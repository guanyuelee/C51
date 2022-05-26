#include <REGX52.H>
#include "DS1302.h"
#include "sleep.h"

unsigned char DS1302_Time[] = {00, 2, 29, 12, 59, 55, 7};

#define DS1302_SECOND   0x80
#define DS1302_MINUTE   0x82
#define DS1302_HOUR   	0x84
#define DS1302_DATE   	0x86
#define DS1302_MONTH   	0x88
#define DS1302_DAY   	0x8A
#define DS1302_YEAR   	0x8C
#define DS1302_WP   	0x8E

sbit DS1302_SCLK = P3^6; 
sbit DS1302_IO = P3^4; 
sbit DS1302_CE = P3^5;

void DS1302_Init(void){
	DS1302_CE = 0;
	DS1302_SCLK = 0;
}

void DS1302_WriteByte(unsigned char command, unsigned char what_data){
	unsigned int i=0; 
	DS1302_CE = 1; 
	
	for(i=0; i<8; i++){
		DS1302_IO = command & (0x01<<i);
		DS1302_SCLK = 1; 
		DS1302_SCLK = 0;
	}
	
	for(i=0; i<8; i++){
		DS1302_IO = what_data & (0x01<<i);
		DS1302_SCLK = 1; 
		DS1302_SCLK = 0;
	}
	DS1302_CE = 0; 
}



unsigned char DS1302_ReadByte(unsigned char command){
	unsigned char i, results=0x00; 
	
	DS1302_CE = 1; 
	
	for(i=0; i<8; i++){
		DS1302_IO = (command|0x01) & (0x01<<i);
		DS1302_SCLK = 0; 
		DS1302_SCLK = 1;
	}
	
	for(i=0; i<8; i++){
		DS1302_SCLK = 1; 
		DS1302_SCLK = 0;
		if(DS1302_IO){results |= (0x01<<i); }
	}
	DS1302_CE = 0;
	DS1302_IO = 0; 
	
	return results;	
}

void DS1302_SetTime(void){
	DS1302_WriteByte(DS1302_WP, 0x00);  
	DS1302_WriteByte(DS1302_YEAR, DS1302_Time[0]/10*16+DS1302_Time[0]%10); 
	DS1302_WriteByte(DS1302_MONTH, DS1302_Time[1]/10*16+DS1302_Time[1]%10); 
	DS1302_WriteByte(DS1302_DATE, DS1302_Time[2]/10*16+DS1302_Time[2]%10); 
	DS1302_WriteByte(DS1302_HOUR, DS1302_Time[3]/10*16+DS1302_Time[3]%10);
	DS1302_WriteByte(DS1302_MINUTE, DS1302_Time[4]/10*16+DS1302_Time[4]%10);
	DS1302_WriteByte(DS1302_SECOND, DS1302_Time[5]/10*16+DS1302_Time[5]%10);
	DS1302_WriteByte(DS1302_DAY, DS1302_Time[6]/10*16+DS1302_Time[6]%10);
	// DS1302_WriteByte(DS1302_WP, 0x80); 	
}

void DS1302_ReadTime(void){
	unsigned char temp; 
	temp = DS1302_ReadByte(DS1302_YEAR); 
	DS1302_Time[0] = temp / 16 * 10 + temp % 16;
	
	temp = DS1302_ReadByte(DS1302_MONTH); 
	DS1302_Time[1] = temp / 16 * 10 + temp % 16;
	
	temp = DS1302_ReadByte(DS1302_DATE); 
	DS1302_Time[2] = temp / 16 * 10 + temp % 16;
	
	temp = DS1302_ReadByte(DS1302_HOUR); 
	DS1302_Time[3] = temp / 16 * 10 + temp % 16;
	
	temp = DS1302_ReadByte(DS1302_MINUTE); 
	DS1302_Time[4] = temp / 16 * 10 + temp % 16;
	
	temp = DS1302_ReadByte(DS1302_SECOND); 
	DS1302_Time[5] = temp / 16 * 10 + temp % 16;
	
	temp = DS1302_ReadByte(DS1302_DAY); 
	DS1302_Time[6] = temp / 16 * 10 + temp % 16;
}
