#ifndef __DS1302_H__
#define __DS1302_H__

extern unsigned char DS1302_Time[];

void DS1302_Init(void); 
void DS1302_WriteByte(unsigned char command, what_data);
unsigned char DS1302_ReadByte(unsigned char command);
void DS1302_ReadTime(void); 
void DS1302_SetTime(void); 
#endif