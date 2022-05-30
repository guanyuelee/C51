/*
 * @Author       : Guanyue li
 * @Date         : 2022-05-28 18:47:52
 * @LastEditTime : 2022-05-28 23:27:52
 * @Description  : file content
 * @FilePath     : \19.temperature_warning\oneWire.c
 */
#include "oneWire.h"

unsigned char ONEWIRE_Init(){
    unsigned char i, ack;
    EA = 0; 
    ONEWIRE_DQ = 1;
    ONEWIRE_DQ = 0; 
	_nop_(); i = 227; while (--i);  // Delay 500 us
    ONEWIRE_DQ = 1; 
    _nop_(); i = 29; while (--i);   // Delay 70 us
    ack = ONEWIRE_DQ; 
    _nop_(); i = 227; while (--i);  // Delay 500 us
    EA = 1;
    return ack;
}

void ONEWIRE_SendBit(unsigned char Bit){
    unsigned char i;
    EA = 0; 
    ONEWIRE_DQ = 0; 	
	_nop_(); i = 3; while (--i);    // delay 10 us
    ONEWIRE_DQ = Bit; 
    _nop_(); i = 20; while (--i);   // delay 50 us
    ONEWIRE_DQ = 1; 
    EA = 1; 
}

void ONEWIRE_SendByte(unsigned char byte){
    unsigned char i; 
    for(i=0; i<8; i++){
        ONEWIRE_SendBit(byte & (0x01 << i));
    }
}

unsigned char ONEWIRE_ReceiveBit(void){
    unsigned char res, i; 
    EA = 0; 
    ONEWIRE_DQ = 0;
    _nop_(); i = 1; while (--i);    // delay 5 us
    ONEWIRE_DQ = 1;
    _nop_(); i = 1; while (--i);    // delay 5 us
    res = ONEWIRE_DQ; 
    _nop_(); i = 20; while (--i);   // delay 50 us
    EA = 1; 
    return res; 
}

unsigned char ONEWIRE_ReceiveByte(void){
    unsigned char i, byte = 0x00;
    for(i=0; i<8; i++){
        if(ONEWIRE_ReceiveBit()){
            byte = byte | (0x01 << i); 
        }
    }
    return byte;
}