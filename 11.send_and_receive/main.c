#include <REGX52.H>
#include "uart.h"

void main(){
	UARTInitSend(); 
	while(1); 
}

void UART_Routine() interrupt 4
{
	if(RI == 1){
		P2 = ~SBUF; 
		UARTSendByte(SBUF);
		RI = 0;
	}
}

/**
void UART_Routine() interrupt 4
{
	if(RI == 1){
		P2 = ~SBUF; 
		UARTSendByte(SBUF);
		RI = 0;
	}
}
*/