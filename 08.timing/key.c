#include <REGX52.H>
#include "sleep.h"

unsigned char listenKey(){
	unsigned char whatKey = 0; 
	
	if(P3_1 == 0) {sleep(20); while(P3_1 == 0); sleep(20); whatKey = 1;}
	if(P3_0 == 0) {sleep(20); while(P3_0 == 0); sleep(20); whatKey = 2;}
	if(P3_2 == 0) {sleep(20); while(P3_2 == 0); sleep(20); whatKey = 3;}
	if(P3_3 == 0) {sleep(20); while(P3_3 == 0); sleep(20); whatKey = 4;}
	
	return whatKey; 
}

