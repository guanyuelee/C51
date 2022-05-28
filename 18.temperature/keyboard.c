/*
 * @Author       : Guanyue li
 * @Date         : 2022-05-28 00:10:08
 * @LastEditTime : 2022-05-28 10:55:46
 * @Description  : file content
 * @FilePath     : \17.listenerKeyboard\keyboard.c
 */
#include <REGX52.H>
#include "sleep.h"

unsigned char LINEKB_KEY_PRESS; 

unsigned char listenMatrixKey(){
	unsigned char KeyNumber = 0;
	
	P1 = 0xFF; 
	P1_3 = 0; 
	if(P1_7 == 0) {sleep(20); while(P1_7 == 0); sleep(20); KeyNumber=1; }
	if(P1_6 == 0) {sleep(20); while(P1_6 == 0); sleep(20); KeyNumber=5; }
	if(P1_5 == 0) {sleep(20); while(P1_5 == 0); sleep(20); KeyNumber=9; }
	if(P1_4 == 0) {sleep(20); while(P1_4 == 0); sleep(20); KeyNumber=13; }
	
	P1 = 0xFF; 
	P1_2 = 0; 
	if(P1_7 == 0) {sleep(20); while(P1_7 == 0); sleep(20); KeyNumber=2; }
	if(P1_6 == 0) {sleep(20); while(P1_6 == 0); sleep(20); KeyNumber=6; }
	if(P1_5 == 0) {sleep(20); while(P1_5 == 0); sleep(20); KeyNumber=10; }
	if(P1_4 == 0) {sleep(20); while(P1_4 == 0); sleep(20); KeyNumber=14; }
	
	P1 = 0xFF; 
	P1_1 = 0; 
	if(P1_7 == 0) {sleep(20); while(P1_7 == 0); sleep(20); KeyNumber=3; }
	if(P1_6 == 0) {sleep(20); while(P1_6 == 0); sleep(20); KeyNumber=7; }
	if(P1_5 == 0) {sleep(20); while(P1_5 == 0); sleep(20); KeyNumber=11; }
	if(P1_4 == 0) {sleep(20); while(P1_4 == 0); sleep(20); KeyNumber=15; }
	
	P1 = 0xFF; 
	P1_0 = 0; 
	if(P1_7 == 0) {sleep(20); while(P1_7 == 0); sleep(20); KeyNumber=4; }
	if(P1_6 == 0) {sleep(20); while(P1_6 == 0); sleep(20); KeyNumber=8; }
	if(P1_5 == 0) {sleep(20); while(P1_5 == 0); sleep(20); KeyNumber=12; }
	if(P1_4 == 0) {sleep(20); while(P1_4 == 0); sleep(20); KeyNumber=16; }
	
	return KeyNumber; 
}

unsigned char listenLineKey(){
	unsigned char tmp = LINEKB_KEY_PRESS; 
	LINEKB_KEY_PRESS = 0; 
	return tmp; 
}

unsigned char getKeyState(){
	unsigned char keyState = 0;

	if(P3_1 == 0){ keyState = 1; }
	if(P3_0 == 0){ keyState = 2; }
	if(P3_2 == 0){ keyState = 3; }
	if(P3_3 == 0){ keyState = 4; }

	return keyState; 
}

void listenKeyLoop(){
	static unsigned char cur_state, last_state;
	last_state = cur_state; 
	cur_state = getKeyState(); 
	if (last_state == 1 && cur_state == 0) {
		LINEKB_KEY_PRESS = 1; 
	} else if (last_state == 2 && cur_state == 0) {
		LINEKB_KEY_PRESS = 2; 
	} else if (last_state == 3 && cur_state == 0) {
		LINEKB_KEY_PRESS = 3; 
	} else if (last_state == 4 && cur_state == 0) {
		LINEKB_KEY_PRESS = 4; 
	}
}

