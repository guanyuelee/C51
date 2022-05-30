#include <REGX52.H>

sbit LED = P2^0; 

unsigned char time, i; 
void sleep2(unsigned char time);

void main(){
	
	while(1){
		for(time=0; time < 101; time++){
			for(i=0; i<20; i++){
				LED = 1; 
				sleep2(time); 
				LED = 0; 
				sleep2(100 - time);
			}
		}
		
		for(time=0; time < 101; time++){
			for(i=0; i<20; i++){
				LED = 1; 
				sleep2(100 - time); 
				LED = 0; 
				sleep2(time);
			}
		}
	}
}

void sleep2(unsigned char time)
{
	while(time--);
}
