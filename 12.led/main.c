#include <REGX52.H>
#include "sleep.h"
#include "display.h"

void main(){
	matrixLedInit(); 
	while(1){
		matrixLedShowColumn(0, 0x70); 
		matrixLedShowColumn(1, 0xF8); 
		matrixLedShowColumn(2, 0xFC); 
		matrixLedShowColumn(3, 0x7E); 
		matrixLedShowColumn(4, 0x7E); 
		matrixLedShowColumn(5, 0xFC); 
		matrixLedShowColumn(6, 0xF8); 
		matrixLedShowColumn(7, 0x70); 
	}
}


