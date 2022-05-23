#include <REGX52.H>
#include "sleep.h"

sbit RCK = P3^5;   // RCLK 
sbit SCK = P3^6;   // SRCLK
sbit SER = P3^4;   // SER

#define MATRIX_LED_PORT P0

void _74HC595_WriteByte(unsigned char byte){
	unsigned char i; 
	for(i=0; i<8; i++){
		SER = byte & (0x80 >> i); 
		SCK = 1; 
		SCK = 0;
	}
	RCK = 1; 
	RCK = 0; 
}

void matrixLedShowColumn(unsigned char col, unsigned char d){
	_74HC595_WriteByte(d); 
	MATRIX_LED_PORT = ~(0x80 >> col);
	sleep(1); 
	MATRIX_LED_PORT = 0xFF; 
}

void main(){
	SCK = 0; 
	RCK = 0;
	P0_0 = 0; 
	while(1){
		matrixLedShowColumn(0, 0x70); 
		matrixLedShowColumn(1, 0xF8); 
		matrixLedShowColumn(2, 0xFC); 
		matrixLedShowColumn(3, 0x7E); 
		matrixLedShowColumn(4, 0x7E); 
		matrixLedShowColumn(5, 0xFC); 
		matrixLedShowColumn(6, 0xF8); 
		matrixLedShowColumn(7, 0x70); 
	}
}


