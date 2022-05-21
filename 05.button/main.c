#include <REGX52.H>

void Delay(unsigned int time)		//@12.000MHz
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
	// Control: Control the light by shifting. 
	unsigned char LEDNum = 1;
	while(1)
	{
		P2 = ~LEDNum; 
		if(P3_1 == 0){
			Delay(20);
			while(P3_1 == 0);
			Delay(20);
			LEDNum = LEDNum << 1;
			P2 = ~LEDNum; 
			if(LEDNum == 0){
				LEDNum = 1; 
			}
		}
	}
	
	/**
	// Control: Control the light by binary. 
	unsigned char LEDNum = 0; 
	while(1){
		if(P3_1 == 0){
			Delay(20); 
			while(P3_1 == 0);
			Delay(20);
			LEDNum += 1; 
			P2 = ~LEDNum;
		}
	}
	*/
	
	/**
	// Control: Control the light by the button. 
	while(1){
		if(P3_1 == 0){
			Delay(20); 
			while(P3_1 == 0);
			Delay(20);
			
			P2_0 = ~P2_0;
		}
	}*/
	
	/**
	// Control: Press the button, the light is on. 
	// Unpress the button, the light is off. 
	P2 = 0xFE;
	P2_0 = 0;
	while(1){
		if(P3_1 == 0){
			P2_0 = 0;
		}else{
			P2_0 = 1;
		}
	}
	*/
}
