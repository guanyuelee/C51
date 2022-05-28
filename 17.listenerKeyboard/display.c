#include <REGX52.H>
#include "sleep.h"
#include "display.h"

sbit RCK = P3^5;   // RCLK 
sbit SCK = P3^6;   // SRCLK
sbit SER = P3^4;   // SER

// 这个是数码管的显示缓存，他每隔n秒被刷新一次。初始化为全部不显示。
unsigned char nixieBuffer[9] = {NIXIE_DEFAULT,NIXIE_DEFAULT,NIXIE_DEFAULT,
NIXIE_DEFAULT,NIXIE_DEFAULT,NIXIE_DEFAULT,
NIXIE_DEFAULT,NIXIE_DEFAULT,NIXIE_DEFAULT}; 

// 这个是数字的16进制显示对照表，0x3F代表0，0x71代表F,0x00代表不显示
unsigned char numberTable[17] = {
	0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 
	0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x00
};
/**
 * @description: 显示数码管的函数，往缓存存先要显示的文字。
 * @param {unsigned char} 显示数字的位置，1-8
 * @param {unsigned char} 显示的数字，0 1 - 15
 * @return {*} 无
 */
void setNixieBuffer(unsigned char location, unsigned char number){
	nixieBuffer[location] = number; 
}

/**
 * @description: 显示数码管的函数
 * @param {unsigned char} location 显示的位置，1-8
 * @param {unsigned char} number 显示的数字，0 1 - 15
 * @return {*} 无
 */
void displayInNixie(unsigned char location, unsigned char number){
	P0 = 0x00;
	switch(location){
		case 1: P2_4 = 1; P2_3 = 1; P2_2 = 1; break;
		case 2: P2_4 = 1; P2_3 = 1; P2_2 = 0; break;
		case 3: P2_4 = 1; P2_3 = 0; P2_2 = 1; break;
		case 4: P2_4 = 1; P2_3 = 0; P2_2 = 0; break;
		case 5: P2_4 = 0; P2_3 = 1; P2_2 = 1; break;
		case 6: P2_4 = 0; P2_3 = 1; P2_2 = 0; break;
		case 7: P2_4 = 0; P2_3 = 0; P2_2 = 1; break;
		case 8: P2_4 = 0; P2_3 = 0; P2_2 = 0; break;
	}
	P0 = numberTable[number];
}

/**
 * @description: 数码管定时器循环的函数，在main函数中每隔1000/NIXIE_FPS的间隔进行循环。
 * @return {*} 无
 * 
 * Example:
 
void timer0Routine() interrupt 1{
	static unsigned int count_nixie;
	TL0 = 0x66;	
	TH0 = 0xFC;	
	
    count_nixie++; 
    if(count_nixie >= 1000/NIXIE_FPS){
        nixieLoop(); 
        count_nixie=0; 
	}
}
 */
void nixieLoop(){
	static unsigned char i = 1; 
	displayInNixie(i, nixieBuffer[i]);
	i++; 
	if(i>8) i=1;
}



//引脚配置：
sbit LCD_RS=P2^6;
sbit LCD_RW=P2^5;
sbit LCD_EN=P2^7;
#define LCD_DataPort P0

//函数定义：
/**
  * @brief  LCD1602延时函数，12MHz调用可延时1ms
  * @param  无
  * @retval 无
  */
void LCD_Delay()
{
	unsigned char i, j;

	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
}

/**
  * @brief  LCD1602写命令
  * @param  Command 要写入的命令
  * @retval 无
  */
void LCD_WriteCommand(unsigned char Command)
{
	LCD_RS=0;
	LCD_RW=0;
	LCD_DataPort=Command;
	LCD_EN=1;
	LCD_Delay();
	LCD_EN=0;
	LCD_Delay();
}

/**
  * @brief  LCD1602写数据
  * @param  Data 要写入的数据
  * @retval 无
  */
void LCD_WriteData(unsigned char Data)
{
	LCD_RS=1;
	LCD_RW=0;
	LCD_DataPort=Data;
	LCD_EN=1;
	LCD_Delay();
	LCD_EN=0;
	LCD_Delay();
}

/**
  * @brief  LCD1602设置光标位置
  * @param  Line 行位置，范围：1~2
  * @param  Column 列位置，范围：1~16
  * @retval 无
  */
void LCD_SetCursor(unsigned char Line,unsigned char Column)
{
	if(Line==1)
	{
		LCD_WriteCommand(0x80|(Column-1));
	}
	else if(Line==2)
	{
		LCD_WriteCommand(0x80|(Column-1+0x40));
	}
}

/**
  * @brief  LCD1602初始化函数
  * @param  无
  * @retval 无
  */
void LCD_Init()
{
	LCD_WriteCommand(0x38);//八位数据接口，两行显示，5*7点阵
	LCD_WriteCommand(0x0c);//显示开，光标关，闪烁关
	LCD_WriteCommand(0x06);//数据读写操作后，光标自动加一，画面不动
	LCD_WriteCommand(0x01);//光标复位，清屏
}

/**
  * @brief  在LCD1602指定位置上显示一个字符
  * @param  Line 行位置，范围：1~2
  * @param  Column 列位置，范围：1~16
  * @param  Char 要显示的字符
  * @retval 无
  */
void LCD_ShowChar(unsigned char Line,unsigned char Column,char Char)
{
	LCD_SetCursor(Line,Column);
	LCD_WriteData(Char);
}

/**
  * @brief  在LCD1602指定位置开始显示所给字符串
  * @param  Line 起始行位置，范围：1~2
  * @param  Column 起始列位置，范围：1~16
  * @param  String 要显示的字符串
  * @retval 无
  */
void LCD_ShowString(unsigned char Line,unsigned char Column,char *String)
{
	unsigned char i;
	LCD_SetCursor(Line,Column);
	for(i=0;String[i]!='\0';i++)
	{
		LCD_WriteData(String[i]);
	}
}

/**
  * @brief  返回值=X的Y次方
  */
int LCD_Pow(int X,int Y)
{
	unsigned char i;
	int Result=1;
	for(i=0;i<Y;i++)
	{
		Result*=X;
	}
	return Result;
}

/**
  * @brief  在LCD1602指定位置开始显示所给数字
  * @param  Line 起始行位置，范围：1~2
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：0~65535
  * @param  Length 要显示数字的长度，范围：1~5
  * @retval 无
  */
void LCD_ShowNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length)
{
	unsigned char i;
	LCD_SetCursor(Line,Column);
	for(i=Length;i>0;i--)
	{
		LCD_WriteData(Number/LCD_Pow(10,i-1)%10+'0');
	}
}

/**
  * @brief  在LCD1602指定位置开始以有符号十进制显示所给数字
  * @param  Line 起始行位置，范围：1~2
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：-32768~32767
  * @param  Length 要显示数字的长度，范围：1~5
  * @retval 无
  */
void LCD_ShowSignedNum(unsigned char Line,unsigned char Column,int Number,unsigned char Length)
{
	unsigned char i;
	unsigned int Number1;
	LCD_SetCursor(Line,Column);
	if(Number>=0)
	{
		LCD_WriteData('+');
		Number1=Number;
	}
	else
	{
		LCD_WriteData('-');
		Number1=-Number;
	}
	for(i=Length;i>0;i--)
	{
		LCD_WriteData(Number1/LCD_Pow(10,i-1)%10+'0');
	}
}

/**
  * @brief  在LCD1602指定位置开始以十六进制显示所给数字
  * @param  Line 起始行位置，范围：1~2
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：0~0xFFFF
  * @param  Length 要显示数字的长度，范围：1~4
  * @retval 无
  */
void LCD_ShowHexNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length)
{
	unsigned char i,SingleNumber;
	LCD_SetCursor(Line,Column);
	for(i=Length;i>0;i--)
	{
		SingleNumber=Number/LCD_Pow(16,i-1)%16;
		if(SingleNumber<10)
		{
			LCD_WriteData(SingleNumber+'0');
		}
		else
		{
			LCD_WriteData(SingleNumber-10+'A');
		}
	}
}

/**
  * @brief  在LCD1602指定位置开始以二进制显示所给数字
  * @param  Line 起始行位置，范围：1~2
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：0~1111 1111 1111 1111
  * @param  Length 要显示数字的长度，范围：1~16
  * @retval 无
  */
void LCD_ShowBinNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length)
{
	unsigned char i;
	LCD_SetCursor(Line,Column);
	for(i=Length;i>0;i--)
	{
		LCD_WriteData(Number/LCD_Pow(2,i-1)%2+'0');
	}
}

void LCD_Clear(unsigned Line) {
	LCD_ShowString(Line, 1, "                "); 
}

/**
* @brief  74HC595输出数据。
* @param  byte表示数据 范围：0xFF-0x00
* @retval 无
*/
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

/**
* @brief  在LCD面板的第col列画出数据d的内容。
* @param  col 表示第几列 范围：0-7
* @param  d表示数据，范围：0xFF-0x00
* @retval 无
*/
void matrixLedShowColumn(unsigned char col, unsigned char d){
	_74HC595_WriteByte(d); 
	MATRIX_LED_PORT = ~(0x80 >> col);
	sleep(1); 
	MATRIX_LED_PORT = 0xFF; 
}

void matrixLedInit(){
	SCK = 0; 
	RCK = 0;
}
