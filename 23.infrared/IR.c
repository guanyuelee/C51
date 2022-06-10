/*
 * @Author       : Guanyue li
 * @Date         : 2022-05-30 20:51:34
 * @LastEditTime : 2022-05-30 23:11:15
 * @Description  : file content
 * @FilePath     : \23.infrared\IR.c
 */
#include <REGX52.H>
#include "Timer0.h"
#include "Int0.h"

unsigned int IR_Time; 
unsigned char IR_State; 

unsigned char IR_Data[4]; 
unsigned char IR_pData; 

unsigned char IR_DataFlag; 
unsigned char IR_RepeatFlag; 
unsigned char IR_Address; 
unsigned char IR_Command; 


void IR_Init(void){
    timer0Init(); 
    Int0_Init(); 
}

void Int0_routine(void) interrupt 0{
    if(IR_State == 0){
        timer0SetCounter(0); 
        timer0Run(1); 
        IR_State = 1; 
    }
    else if(IR_State == 1)
    {   
        IR_Time = timer0GetCount(); 
        timer0SetCounter(0);
        if(IR_Time > 12480 - 500 && IR_Time < 12480 + 500){
            IR_State = 2; 
        } 
        else if(IR_Time > 10368 - 500 && IR_Time < 10368 + 500){
            IR_RepeatFlag = 1; 
            timer0Run(0);
            IR_State = 0;
        }else{
            IR_State = 0; 
        }
    }
    else if(IR_State == 2){
        IR_Time = timer0GetCount(); 
        timer0SetCounter(0); 
        if(IR_Time > 1032 - 300 && IR_Time < 1032 + 300){
            IR_Data[IR_pData/8] &= ~(0x01 << (IR_pData % 8)); 
            IR_pData ++; 
        }
        else if(IR_Time > 2074 - 300 && IR_Time < 2074 + 300){
            IR_Data[IR_pData/8] |= (0x01 << (IR_pData % 8)); 
            IR_pData ++; 
        }else{
            IR_State=0;
            IR_pData=0;
        }
        if(IR_pData >= 32){
            IR_pData = 0;
            if((IR_Data[0] == ~IR_Data[1]) && (IR_Data[2] == ~IR_Data[3])){
                IR_DataFlag = 1; 
                IR_Address = IR_Data[0]; 
                IR_Command = IR_Data[2];
            }
            timer0Run(0); 
            IR_State = 0;
        }
    }
}

unsigned char IR_GetDataFlag(void){
    if(IR_DataFlag){
        IR_DataFlag = 0; 
        return 1; 
    }
    return 0; 
}

unsigned char IR_GetRepeatFlag(void){
    if(IR_RepeatFlag){
        IR_RepeatFlag = 0; 
        return 1; 
    }
    return 0; 
}

unsigned char IR_GetAddress(void){
    return IR_Address; 
}

unsigned char IR_GetCommand(void){
    return IR_Command; 
}