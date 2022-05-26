#include <REGX52.H>
#include "sleep.h"
#include "timer0.h"
#include "display.h"

sbit BUZZER=P2^5;
sfr Nixie = 0x80;

#define P0	0
#define L1  1
#define L1_ 2
#define L2  3
#define L2_ 4
#define L3  5
#define L4  6
#define L4_ 7
#define L5  8
#define L5_ 9
#define L6  10
#define L6_ 11
#define L7  12

#define M1  13
#define M1_ 14
#define M2  15
#define M2_ 16
#define M3  17
#define M4  18
#define M4_ 19
#define M5  20
#define M5_ 21
#define M6  22
#define M6_ 23
#define M7  24

#define H1  25
#define H1_ 26
#define H2  27
#define H2_ 28
#define H3  29
#define H4  30
#define H4_ 31
#define H5  32
#define H5_ 33
#define H6  34
#define H6_ 35
#define H7  36

#define HH1  37
#define HH1_ 38
#define HH2  39
#define HH2_ 40
#define HH3  41
#define HH4  42
#define HH4_ 43
#define HH5  44
#define HH5_ 45
#define HH6  46
#define HH6_ 47
#define HH7  48

#define CON 49
#define END 50


// 初始化4个音阶的频率
unsigned int freqs[] = {0, 63628, 63731, 63835, 63928, 64021, 64103, 64185, 64260, 
64331, 64400, 64463, 64524, 64580, 64633, 64684, 64732, 64777, 64820, 64860, 
64898, 64934, 64968, 65000, 65030, 65058, 65085, 65110, 65134, 65157, 65178, 
65198, 65217, 65235, 65252, 65268, 65283, 65297, 65310, 65323, 65335, 65346, 
65357, 65367, 65377, 65385, 65394, 65402, 65409};
// 初始化乐谱 1 1# 2 2# 3 4 4# 5 5# 6 6# 7
//            1 2  3 4  5 6 7  8 9 10 11 12

/**
unsigned int music[] = {
	1, 1, 8, 8, 10, 10, 8, 6, 6, 5, 5, 3, 3, 1, 255};
// 初始化每个音符的长度，1表示1/8拍，2表示1/4拍，4表示1/2，8表示1拍，16表示2拍
unsigned int length[] ={
	8, 8, 8, 8, 8, 8, 16, 8, 8, 8, 8, 8, 8, 16};
// 初始化重低音，0表示低音阶，1表示普通音阶，2表示中音阶，3表示高音阶
unsigned int scales[] ={
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
// 初始化指示器
*/

unsigned int code music[] = {
	/**第一部分**/
	// 如果你突然打了个喷嚏 那一定就是我在想你
	P0, 4, 
	P0, 4, 
	P0, 4, 
	P0, 2, 
	M1, 1, 
	M1, 1, 
	
	M1, 1, 
	M1, 1, 
	M1, 1, 
	M1, 1,
	M1, 2, 
	M1, 1, 
	L6, 1+2, 
	M1, 2, 
	P0, 2+1, 
	M1, 1,
	
	// 如果半夜被手机吵醒 啊 那是因为我关心
	L5, 1, 
	L5, 1, 
	L5, 1, 
	L5, 1, 
	M2, 2, 
	L7, 1, 
	M1, 1+2, 
	L5, 2, 
	P0, 2, 
	L5, 1, 
	L1, 1, 
	
	M1, 1, 
	M1, 2, 
	M1, 1, 
	M3, 2, 
	M1, 1, 
	M1, 1+2, 
	L6, 2, 
	P0, 2, 
	L6, 2, 
	
	L5, 1, 
	L5, 1, 
	L5, 1, 
	L5, 1, 
	M2, 2, 
	L7, 1, 
	M1, 1+4,
	L3, 2, 
	L4, 2,
	
	// 常常想你说的话 是不是别有用心
	L5, 4, 
	M1, 4, 
	L7, 2, 
	L7, 2, 
	L6, 2, 
	L6, 1, 
	L6, 1+2, 
	L5, 2, 
	L2, 2, 
	L4, 1, 
	L4, 1+2, 
	L3, 2, 
	P0, 2, 
	L1, 2+2, 
	// 明明很想相信 却又忍不住怀疑
	L1, 2, 
	L6, 2, 
	L7, 1, L6, 1+2, 
	L5, 2, 
	P0, 2, 
	L3, 2, 
	
	L4, 2, 
	L5, 2, 
	L6, 2, 
	L7, 1, 
	L6, 1+2, 
	L5, 2, 
	P0, 4, 
	
	//在你的心里 
	L5, 4, 
	M1, 2, 
	M1, 1, 
	M1, 1, 
	L6, 2, 
	L6, 2, 
	P0, 2, 
	L6, 2, 
	//我是否就是唯一 爱就是有我常烦着你
	L5, 2, 
	M2, 2, 
	M2, 2, 
	L7, 1, 
	M1, 1, 
	M1, 2, 
	M3, 2, 
	P0, 2, 
	M4, 2 + 2, 
	M4, 2, 
	M3, 2, 
	M1, 2, 
	M1, 2, 
	L6, 2, 
	CON, 0,
	L7, 2, 
	M1, 1, 
	M2, 1,
	
	//so baby 
	M2, 4 + 4, 
	P0, 2, 
	M1, 2, 
	M1, 2, 
	M2, 2,
	
	// 情话多说一点 想我就多看一眼
	M3, 2,
	M5, 2, 
	M5, 2, 
	M5, 1, 
	M5, 1+2, 
	M4, 2, 
	P0, 2,
	M1, 2,
	
	M2, 2, 
	M2, 2, 
	M4, 2, 
	M5, 1, 
	M4, 1+2, 
	M3, 2, 
	P0, 4, 
	//表现多一点点 让我能真的看见
	M1, 2, 
	M1, 2, 
	M3, 2, 
	M4, 1, 
	M3, 1+2, 
	M2, 2, 
	L6, 2, 
	L7, 2, 
	
	M1, 4, 
	M3, 2, 
	M4, 1, 
	M3, 1+2, 
	M2, 2, 
	P0, 2, 
	L5, 2, 
	
	// oh bye 少说一点
	M3, 4, 
	CON, 0, 
	M5, 2, 
	M5, 1, 
	M5, 1, 
	M5, 2, 
	M4, 2, 
	P0, 2, 
	M1, 2, 
	
	// 想陪你不只一天 多一点让我心甘情愿 爱你
	M2, 2, 
	M2, 2, 
	M4, 2, 
	M5, 1, 
	M4, 1+2, 
	M3, 2, 
	P0, 2, 
	M1, 2,
	
	M1, 2, 
	M6, 2, 
	P0, 2, 
	M1, 2, 
	L7, 4, 
	M3, 2, 
	M3, 1, 
	M3, 1+2, 
	M1, 2, 
	P0, 2, 
	M2, 1, 
	M1, 1+4, 
	P0, 4,
	
	// 如果你突然打了个喷嚏 那一定就是我在想你
	P0, 4, 
	P0, 4, 
	P0, 4, 
	P0, 2, 
	M1, 1, 
	M1, 1, 
	
	M1, 1, 
	M1, 1, 
	M1, 1, 
	M1, 1,
	M1, 2, 
	M1, 1, 
	L6, 1+2, 
	M1, 2, 
	P0, 2+1, 
	M1, 1,
	
	// 如果半夜被手机吵醒 啊 那是因为我关心
	L5, 1, 
	L5, 1, 
	L5, 1, 
	L5, 1, 
	M2, 2, 
	L7, 1, 
	M1, 1+2, 
	L5, 2, 
	P0, 2, 
	L5, 1, 
	L1, 1, 
	
	M1, 1, 
	M1, 2, 
	M1, 1, 
	M3, 2, 
	M1, 1, 
	M1, 1+2, 
	L6, 2, 
	P0, 2, 
	L6, 2, 
	
	L5, 1, 
	L5, 1, 
	L5, 1, 
	L5, 1, 
	M2, 2, 
	L7, 1, 
	M1, 1+4,
	L3, 2, 
	L4, 2,
	
	// 常常想你说的话 是不是别有用心
	L5, 4, 
	M1, 4, 
	L7, 2, 
	L7, 2, 
	L6, 2, 
	L6, 1, 
	L6, 1+2, 
	L5, 2, 
	L2, 2, 
	L4, 1, 
	L4, 1+2, 
	L3, 2, 
	P0, 2, 
	L1, 2+2, 
	// 明明很想相信 却又忍不住怀疑
	L1, 2, 
	L6, 2, 
	L7, 1, L6, 1+2, 
	L5, 2, 
	P0, 2, 
	L3, 2, 
	
	L4, 2, 
	L5, 2, 
	L6, 2, 
	L7, 1, 
	L6, 1+2, 
	L5, 2, 
	P0, 4, 
	
	//在你的心里 
	L5, 4, 
	M1, 2, 
	M1, 1, 
	M1, 1, 
	L6, 2, 
	L6, 2, 
	P0, 2, 
	L6, 2, 
	//我是否就是唯一 爱就是有我常烦着你
	L5, 2, 
	M2, 2, 
	M2, 2, 
	L7, 1, 
	M1, 1, 
	M1, 2, 
	M3, 2, 
	P0, 2, 
	M4, 2 + 2, 
	M4, 2, 
	M3, 2, 
	M1, 2, 
	M1, 2, 
	L6, 2, 
	CON, 0,
	L7, 2, 
	M1, 1, 
	M2, 1,
	
	//so baby 
	M2, 4 + 4, 
	P0, 2, 
	M1, 2, 
	M1, 2, 
	M2, 2,
	
	// 情话多说一点 想我就多看一眼
	M3, 2,
	M5, 2, 
	M5, 2, 
	M5, 1, 
	M5, 1+2, 
	M4, 2, 
	P0, 2,
	M1, 2,
	
	M2, 2, 
	M2, 2, M4, 2, 
	M5, 1, 
	M4, 1+2, 
	M3, 2, 
	P0, 4, 
	//表现多一点点 让我能真的看见
	M1, 2, 
	M1, 2, 
	M3, 2, 
	M4, 1, 
	M3, 1+2, 
	M2, 2, 
	L6, 2, 
	L7, 2, 
	
	M1, 4, 
	M3, 2, 
	M4, 1, 
	M3, 1+2, 
	M2, 2, 
	P0, 2, 
	L5, 2, 
	
	// oh bye 少说一点
	M3, 4, 
	CON, 0, 
	M5, 2, 
	M5, 1, 
	M5, 1, 
	M5, 2, 
	M4, 2, 
	P0, 2, 
	M1, 2, 
	
	// 想陪你不只一天 多一点让我心甘情愿 爱你
	M2, 2, 
	M2, 2, 
	M4, 2, 
	M5, 1, 
	M4, 1+2, 
	M3, 2, 
	P0, 2, 
	M1, 2,
	
	M1, 2, 
	M6, 2, 
	P0, 2, 
	M1, 2, 
	L7, 4, 
	M3, 2, 
	M3, 1, 
	M3, 1+2, 
	M1, 2, 
	P0, 2, 
	M2, 1, 
	M1, 1+4, 
	P0, 4,
	/**第四部分
	M3, 2, 
	M1, 2, 
	P0, 2,
	M2, 1, 
	M1, 1+2, 
	M3, 2, 
	M2, 2, 
	M1, 2, 
	
	L7, 2+1, 
	M1, 1+2, 
	M1, 2, 
	L7, 2+1, 
	M1, 1+4, 
	
	P0, 2, 
	M1, 2, M1, 1, M2, 2, 
	M3, 1+2, 
	M2, 2, 
	M1, 2, 
	L7, 2, 
	
	L7, 2+1, 
	M1, 1+2, 
	M2, 2, 
	M7, 2+1, 
	M1, 1+4, 
	
	P0, 2, 
	M1, 2, 
	M1, 1, M2, 2, 
	M3, 1+2, 
	M4, 2, 
	M3, 2, 
	M5, 2+4+4+2, 
	CON,0, 
	M4, 2,
	CON, 0, 
	M3, 2, 
	M2, 2+4+4, 
	P0, 2, 
	M1, 2, 
	M1, 2, M2, 2, 
	第四部分*/
	
	/**结尾
	M3, 2, M1, 2,
	P0, 2, 
	M2, 1, M1, 1+4, 
	P0, 2, 
	M1, 2, 
	M1, 2, 
	M6, 2, 
	P0, 2, 
	M1, 2, 
	L7, 4, 
	M3, 2, 
	M3, 1, 
	M3, 1+2, 
	M1, 2+4, 
	M1, 4+2, 
	M4, 2, 
	M3, 2, M2, 2, 
	P0, 2, 
	M1, 2, 
	M1, 2, 
	L7, 2, 
	L6, 1, 
	L7, 2, 
	M1, 1+4+4+4+4,
	结尾*/
	END
};

void displayNixie(){
	displayInNixie(2, 6); 
	displayInNixie(3, 6);
	displayInNixie(4, 6); 
	displayInNixie(8, 8); 	
}

void displayLED(){
	matrixLedShowColumn(0, 0x70); 
	matrixLedShowColumn(1, 0xF8); 
	matrixLedShowColumn(2, 0xFC); 
	matrixLedShowColumn(3, 0x7E); 
	matrixLedShowColumn(4, 0x7E); 
	matrixLedShowColumn(5, 0xFC); 
	matrixLedShowColumn(6, 0xF8); 
	matrixLedShowColumn(7, 0x70); 
}

unsigned int count=0, speed=125, delay; 

// 初始化主函数
void main(){
	timer0Init(); 
	matrixLedInit(); 
	Nixie = 0x00; 
	
	while(1){
		// 0 表示空拍
		if(music[count*2] == P0){
			TR0 = 0;
			delay = speed * music[count*2+1]; 
			displayNixie();
			displayLED();
			sleep(delay);
			Nixie = 0x00; 
			TR0 = 1; 
			count ++; 
		}else if(music[count*2] != END){
			delay = speed * music[count*2+1]; 
			displayNixie();
			displayLED();
			sleep(delay);
			Nixie = 0x00; 
			if((count+1)*2!=CON){
				TR0 = 0; 
				sleep(5);
				TR0 = 1; 
			}
			count ++;
		}else{
			TR0 = 0; 
			displayLED();
			displayNixie();
		}
	}
}

// 初始化定时器，每1微秒翻转一次
void timer0Routine() interrupt 1{
	
	TL0 = freqs[music[count*2]] % 256;	
	TH0 = freqs[music[count*2]] / 256;
	
	
	BUZZER = !BUZZER; 
}