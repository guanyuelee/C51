#include <REGX52.H>
#include "sleep.h"

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
	unsigned char whatKey = 0; 
	
	if(P3_1 == 0) {sleep(20); while(P3_1 == 0); sleep(20); whatKey = 1;}
	if(P3_0 == 0) {sleep(20); while(P3_0 == 0); sleep(20); whatKey = 2;}
	if(P3_2 == 0) {sleep(20); while(P3_2 == 0); sleep(20); whatKey = 3;}
	if(P3_3 == 0) {sleep(20); while(P3_3 == 0); sleep(20); whatKey = 4;}
	
	return whatKey; 
}