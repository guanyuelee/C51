#include <REGX52.H>

void Delayxms(unsigned int time)		//@12.000MHz
{
	unsigned char i, j;
	while(time){	
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		time--;
	}
}

void main(){
		P2 = 0xFE; // 1111 1110
		Delayxms(100); 
		P2 = 0xFD; // 1111 1101
		Delayxms(100);
		P2 = 0xFB; // 1111 1011
		Delayxms(100);
		P2 = 0xF7; // 1111 0111
		Delayxms(100);
		P2 = 0xEF; // 1110 1111
		Delayxms(100);
		P2 = 0xDF; // 1101 1111
		Delayxms(100);
		P2 = 0xBF; // 1011 1111
		Delayxms(100);
		P2 = 0x7F; // 0111 1111
		Delayxms(100);
}	



