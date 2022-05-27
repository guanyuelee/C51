#ifndef __DISPLAY_H__
#define __DISPLAY_H__

// Nixie utilities. 
void displayInNixie(unsigned char location, unsigned char number); 

// LCD display utilities. 
void LCD_Init();
void LCD_ShowChar(unsigned char Line,unsigned char Column,char Char);
void LCD_ShowString(unsigned char Line,unsigned char Column,char *String);
void LCD_ShowNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);
void LCD_ShowSignedNum(unsigned char Line,unsigned char Column,int Number,unsigned char Length);
void LCD_ShowHexNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);
void LCD_ShowBinNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);
void LCD_Clear(unsigned Line); 

// LED display utilities. 
void _74HC595_WriteByte(unsigned char byte);
void matrixLedShowColumn(unsigned char col, unsigned char d); 
void matrixLedInit(); 

#endif