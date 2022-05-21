#include <REGX52.H>

unsigned char numberTable[17] = {
	0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 
	0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x00
};

void displayInBoard(unsigned char location, unsigned char number){
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

void sleep(unsigned int time){
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

unsigned int numbers[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; 
unsigned int locations[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 

void main(){
	while(1){
		unsigned char i = 0;
		while(i < 10){
			displayInBoard(locations[i], numbers[i]); 
			i += 1; 
			sleep(500); 
		}
	}
}




