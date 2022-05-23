#include <REGX52.H>
#include "sleep.h"
#include "uart.h"

void main(){
	UARTInit();
	while(1){
		UARTSendByte(0x11); 
		sleep(1000); 
	}
}