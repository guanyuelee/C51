/*
 * @Author       : Guanyue li
 * @Date         : 2022-05-30 23:41:49
 * @LastEditTime : 2022-05-30 23:57:46
 * @Description  : file content
 * @FilePath     : \21.breathe\motor.h
 */
#ifndef __MOTOR_H__
#define __MOTOR_H__

void MOTOR_Init(void); 

void MOTOR_SetSpeed(unsigned char s); 

unsigned char MOTOR_GetSpeed(void); 

void MOTOR_SetThred(unsigned char s);

void MOTOR_Loop(void);

#endif