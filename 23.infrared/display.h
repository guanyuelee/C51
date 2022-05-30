/*
 * @Author       : Guanyue li
 * @Date         : 2022-05-28 00:05:39
 * @LastEditTime : 2022-05-28 11:20:24
 * @Description  : file content
 * @FilePath     : \17.listenerKeyboard\display.h
 */
#ifndef __DISPLAY_H__
#define __DISPLAY_H__

// 这个是单笔画输出，按中国汉字的“日”字书写顺序来表示数码管的每个笔画。
#define NIXIE_SGL_1 17  
#define NIXIE_SGL_2 18
#define NIXIE_SGL_3 19
#define NIXIE_SGL_4 20
#define NIXIE_SGL_5 21
#define NIXIE_SGL_6 22
#define NIXIE_SGL_7 23
#define NIXIE_SGL_8 24  

// Nixie utilities. 
#define NIXIE_FPS 500
#define MATRIX_LED_PORT P0
#define NIXIE_DEFAULT 16

void displayInNixie(unsigned char location, unsigned char number); 
void setNixieBuffer(unsigned char location, unsigned char number); 
void nixieLoop(); 

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