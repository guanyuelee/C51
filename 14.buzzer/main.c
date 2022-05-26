#include <REGX52.H>
#include "display.h"
#include "keyboard.h"
#include "buzzer.h"

unsigned char key;

void main(){
	displayInNixie(1, 0); 
	while(1){
		key = listenLineKey(); 
		if(key){
			buzzerTime(100); 
			displayInNixie(1, key); 
		}
	}
}
