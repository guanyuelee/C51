/*
 * @Author       : Guanyue li
 * @Date         : 2022-05-28 18:47:59
 * @LastEditTime : 2022-05-28 19:03:04
 * @Description  : file content
 * @FilePath     : \18.temperature\oneWire.h
 */
#ifndef __ONEWIRE_H__
#define __ONEWIRE_H__

#include <REGX52.H>
#include <INTRINS.H>

sbit ONEWIRE_DQ = P3^7; 

unsigned char ONEWIRE_Init(); 
void ONEWIRE_SendBit(unsigned char Bit); 
void ONEWIRE_SendByte(unsigned char byte); 
unsigned char ONEWIRE_ReceiveBit(void);
unsigned char ONEWIRE_ReceiveByte(void);
#endif