/*
 * @Author       : Guanyue li
 * @Date         : 2022-05-30 20:41:13
 * @LastEditTime : 2022-05-30 20:45:41
 * @Description  : file content
 * @FilePath     : \23.infrared\Timer0.h
 */
#ifndef __TIMER0_H__
#define __TIMER0_H__

void timer0Init(void); 

void timer0SetCounter(unsigned int value);

unsigned int timer0GetCount(void);

void timer0Run(unsigned char flag); 

#endif