#include <REGX52.H>
#include "display.h"
#include "DS1302.h"
#include "sleep.h"
#include "keyboard.h"
#include "timer0.h"

#define KEY_MODE 4
#define KEY_NEXT 1
#define KEY_UP 2
#define KEY_DOWN 3

#define YEAR_IDX 0
#define MONTH_IDX 1
#define DATE_IDX 2
#define HOUR_IDX 3
#define MINUTE_IDX 4
#define SECOND_IDX 5
#define DAY_IDX 6


char* weekday = "Sun.";
unsigned char whatKey, MODE=0, select=0, flashFlag; 
void timerShow();
void timerSet(); 
void printTime(); 
unsigned char isLeap(); 
unsigned char isBigMonth(); 
unsigned char isSmallMonth();
unsigned char isFreb();

void changeYear();
void changeMonth();
void changeDate();
void changeHour();
void changeMinute();
void changeSecond();
void changeDay();

unsigned char getYear();
unsigned char getMonth();
unsigned char getDate();
unsigned char getHour();
unsigned char getMinute();
unsigned char getSecond();
unsigned char getDay();
unsigned char getMaxDate(); 

void setYear(unsigned char n);
void setMonth(unsigned char n);
void setDate(unsigned char n);
void setHour(unsigned char n);
void setMinute(unsigned char n);
void setSecond(unsigned char n);
void setDay(unsigned char n);

void main(){
	// unsigned char results; 
	
	LCD_Init(); 
	DS1302_Init(); 
	DS1302_SetTime();
	timer0Init();
	
	while(1){
		whatKey = listenLineKey();
		if(whatKey == KEY_MODE){
			MODE++; 
			MODE %= 2; 
			if(MODE == 0){
				LCD_ShowString(1, 12, "   ");
				DS1302_SetTime();
			}
		}
		switch(MODE){
			case 0: DS1302_ReadTime(); timerShow(); break;  
			case 1: timerSet(); break;
		}
	}
}

void timerShow(){
	printTime(); 
} 

void timerSet()
{
	if(whatKey == KEY_NEXT){ select ++; select = select % 7;}
	
	switch(select){
		case YEAR_IDX: changeYear(); break; 
		case MONTH_IDX: changeMonth(); break; 
		case DATE_IDX: changeDate(); break; 
		case HOUR_IDX: changeHour(); break; 
		case MINUTE_IDX: changeMinute(); break; 
		case SECOND_IDX: changeSecond(); break; 
		case DAY_IDX: changeDay(); break; 
	}
	printTime(); 
} 


void printTime(){
	LCD_ShowString(1, 1, "    -  -");
	LCD_ShowString(2, 1, "  :  :  ");
	
	if(MODE==1){
		if(flashFlag){
			LCD_ShowString(1, 12, "SET");
		}else{	
			LCD_ShowString(1, 12, "   ");
		}
	}
	
	if(MODE==1 && select==YEAR_IDX){
		if(flashFlag){
			LCD_ShowString(1, 1, "20");
			LCD_ShowNum(1, 3, DS1302_Time[YEAR_IDX], 2);
		}else{	
			LCD_ShowString(1, 3, "    ");
		}
	}else{
		LCD_ShowString(1, 1, "20");
		LCD_ShowNum(1, 3, DS1302_Time[YEAR_IDX], 2);
	}
	
	if(MODE==1 && select==MONTH_IDX){
		if(flashFlag){
			LCD_ShowNum(1, 6, DS1302_Time[MONTH_IDX], 2);
		}else{	
			LCD_ShowString(1, 6, "  ");
		}
	}else{
		LCD_ShowNum(1, 6, DS1302_Time[MONTH_IDX], 2);
	}
	
	if(MODE==1 && select==DATE_IDX){
		if(flashFlag){
			LCD_ShowNum(1, 9, DS1302_Time[DATE_IDX], 2);
		}else{
			LCD_ShowString(1, 9, "  ");
		}
	}else{
		LCD_ShowNum(1, 9, DS1302_Time[DATE_IDX], 2);
	}
	
	if(MODE==1 && select==HOUR_IDX){
		if(flashFlag){
			LCD_ShowNum(2, 1, DS1302_Time[HOUR_IDX], 2);
		}else{	
			LCD_ShowString(2, 1, "  ");
		}
	}else{
		LCD_ShowNum(2, 1, DS1302_Time[HOUR_IDX], 2);
	}
	
	if(MODE==1 && select==MINUTE_IDX){
		if(flashFlag){
			LCD_ShowNum(2, 4, DS1302_Time[MINUTE_IDX], 2);
		}
		else{	
			LCD_ShowString(2, 4, "  ");
		}
	}else{
		LCD_ShowNum(2, 4, DS1302_Time[MINUTE_IDX], 2);
	}
	
	if(MODE==1 && select==SECOND_IDX){
		if(flashFlag){
			LCD_ShowNum(2, 7, DS1302_Time[SECOND_IDX], 2);
		}
		else{	
			LCD_ShowString(2, 7, "  ");
		}
	}else{
		LCD_ShowNum(2, 7, DS1302_Time[SECOND_IDX], 2);
	}
	
	switch(DS1302_Time[DAY_IDX]){
		case 7: weekday = "Sun."; break;
		case 1: weekday = "Mon."; break;
		case 2: weekday = "Tue."; break;
		case 3: weekday = "Wed."; break;
		case 4: weekday = "Thu."; break;
		case 5: weekday = "Fri."; break;
		case 6: weekday = "Sat."; break;
	}
	if(MODE==1 && select==DAY_IDX){
		if(flashFlag){
			LCD_ShowString(2, 10, weekday);
		}else{
			LCD_ShowString(2, 10, "    ");
		}
	}else{
		LCD_ShowString(2, 10, weekday);
	}
}


void changeYear(){
	if(whatKey == KEY_UP){
		if(getYear() == 99){
			setYear(0); 
		}else if(getYear() < 99){
			setYear(getYear() + 1);
		}
		if(!isLeap() && isFreb() && getDate() == 29){
			setDate(28);
		}
		DS1302_SetTime(); 
	}
	if(whatKey == KEY_DOWN){
		if(getYear() == 0){
			setYear(99); 
		}else if(getYear() > 0){
			setYear(getYear() - 1);
		}
		if(!isLeap() && isFreb() && getDate() == 29){
			setDate(28);
		}
		DS1302_SetTime(); 
	}
}

void changeMonth(){
	if(whatKey == KEY_UP){
		if(getMonth() == 12){
			setMonth(1); 
		}else if(getMonth() < 12){
			setMonth(getMonth() + 1);
		}
	}
	if(whatKey == KEY_DOWN){
		if(getMonth() == 0){
			setMonth(12); 
		}else if(getMonth() > 0){
			setMonth(getMonth() - 1);
		}
	}
	if(!isLeap() && isFreb() && getDate() > 28){
		setDate(28);
	}else if(isLeap() && isFreb() && getDate() > 29){
		setDate(29);
	}else if(isSmallMonth() && !isFreb() && getDate() > 30){
		setDate(30); 
	}
}

unsigned char getMaxDate(){
	unsigned char n_days = 0; 
	if(isFreb()){
		if(isLeap()) {n_days=29; }
		else{n_days=28;}
	}else if(isBigMonth()){
		n_days = 31; 
	}else{
		n_days = 30; 
	}
	return n_days;
}

void changeDate(){
	if(whatKey == KEY_UP){
		unsigned char n_days = getMaxDate(); 
		if(getDate() == n_days){
			setDate(1); 
		}else if(getDate() < n_days){
			setDate(getDate() + 1);
		}
	}
	if(whatKey == KEY_DOWN){
		unsigned char n_days = getMaxDate(); 
		if(getDate() == 1){
			setDate(n_days); 
		}else if(getDate() > 1){
			setDate(getDate() - 1);
		}
	}
}

void changeHour(){
	if(whatKey == KEY_UP){
		if(getHour() == 23){
			setHour(0); 
		}else if(getHour() < 23){
			setHour(getHour() + 1);
		}
	}
	if(whatKey == KEY_DOWN){
		if(getHour() == 0){
			setHour(23); 
		}else if(getHour() > 0){
			setHour(getHour() - 1);
		}
	}
}

void changeMinute(){
	if(whatKey == KEY_UP){
		if(getMinute() == 59){
			setMinute(0); 
		}else if(getMinute() < 59){
			setMinute(getMinute() + 1);
		}
	}
	if(whatKey == KEY_DOWN){
		if(getMinute() == 0){
			setMinute(59); 
		}else if(getMinute() > 0){
			setMinute(getMinute() - 1);
		}
	}
}

void changeSecond(){
	if(whatKey == KEY_UP){
		if(getSecond() == 59){
			setSecond(0); 
		}else if(getSecond() < 59){
			setSecond(getSecond() + 1);
		}
	}
	if(whatKey == KEY_DOWN){
		if(getSecond() == 0){
			setSecond(59); 
		}else if(getSecond() > 0){
			setSecond(getSecond() - 1);
		}
	}
}

void changeDay(){
	if(whatKey == KEY_UP){
		if(getDay() == 7){
			setDay(1); 
		}else if(getDay() < 7){
			setDay(getDay() + 1);
		}
	}
	if(whatKey == KEY_DOWN){
		if(getDay() == 1){
			setDay(7); 
		}else if(getDay() > 1){
			setDay(getDay() - 1);
		}
	}
}

unsigned char isLeap(){
	unsigned char res = 0; 
	if(DS1302_Time[0] % 4 == 0 || DS1302_Time[0] == 0){
		res = 1; 
	}
	return res; 
}


unsigned char isBigMonth(){
	unsigned char res = 0; 
	if(DS1302_Time[1] == 1 || DS1302_Time[1] == 3 || DS1302_Time[1] == 5 || DS1302_Time[1] == 7 || DS1302_Time[1] == 8 || DS1302_Time[1] == 10 || DS1302_Time[1] == 12){
		res = 1; 
	}
	return res; 
}

unsigned char isSmallMonth(){
	return !isBigMonth(); 
}

unsigned char isFreb(){
	if(DS1302_Time[1] == 2){
		return 1; 
	}else{
		return 0; 	
	}
}

unsigned char getYear(){
	return DS1302_Time[YEAR_IDX]; 
}
unsigned char getMonth(){
	return DS1302_Time[MONTH_IDX]; 
}
unsigned char getDate(){
	return DS1302_Time[DATE_IDX]; 
}
unsigned char getHour(){
	return DS1302_Time[HOUR_IDX]; 
}
unsigned char getMinute(){
	return DS1302_Time[MINUTE_IDX]; 
}
unsigned char getSecond(){
	return DS1302_Time[SECOND_IDX]; 
}
unsigned char getDay(){
	return DS1302_Time[DAY_IDX]; 
}

void setYear(unsigned char n){
	DS1302_Time[YEAR_IDX] = n;
}
void setMonth(unsigned char n){
	DS1302_Time[MONTH_IDX] = n;
}
void setDate(unsigned char n){
	DS1302_Time[DATE_IDX] = n;
}
void setHour(unsigned char n){
	DS1302_Time[HOUR_IDX] = n;
}
void setMinute(unsigned char n){
	DS1302_Time[MINUTE_IDX] = n;
}
void setSecond(unsigned char n){
	DS1302_Time[SECOND_IDX] = n;
}
void setDay(unsigned char n){
	DS1302_Time[DAY_IDX] = n;
}

void timer0Routine() interrupt 1{
	static unsigned int count;
	TL0 = 0x66;	
	TH0 = 0xFC;	
	count ++;
	if(count >= 500){
		count = 0;
		flashFlag = !flashFlag; 
	}
}