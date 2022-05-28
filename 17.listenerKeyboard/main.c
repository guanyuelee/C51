/*
 * @Author       : Guanyue li
 * @Date         : 2022-05-28 00:05:45
 * @LastEditTime : 2022-05-28 18:36:14
 * @Description  : file content
 * @FilePath     : \17.listenerKeyboard\main.c
 */
#include <REGX52.H>
#include "timer0.h"
#include "keyboard.h"
#include "display.h"
#include "AT24C02.h"
#include "sleep.h"

unsigned char key;
unsigned char min = 0, sec = 0, msec = 0;
unsigned char secLoopFlag;

void main()
{
    timer0Init();
    while (1)
    {
        key = listenLineKey();
        if (key == 1)
        {
            secLoopFlag = !secLoopFlag;
        }
        if (key == 2) {
            min = 0; sec = 0; msec = 0; 
        }
        if(key == 3){
            AT24C02_WriteByte(0, min);
            AT24C02_WriteByte(1, sec);
            AT24C02_WriteByte(2, msec); 
            
        }
        if(key == 4){
            min = AT24C02_ReadByte(0);
            sec = AT24C02_ReadByte(1);
            msec = AT24C02_ReadByte(2);
        }
        setNixieBuffer(1, min / 10);
        setNixieBuffer(2, min % 10);
        setNixieBuffer(3, NIXIE_SGL_6);
        setNixieBuffer(4, sec / 10);
        setNixieBuffer(5, sec % 10);
        setNixieBuffer(6, NIXIE_SGL_6);
        setNixieBuffer(7, msec / 10);
        setNixieBuffer(8, msec % 10);
    }
}

void secLoop()
{
    if (secLoopFlag)
    {
        msec++;
        if (msec >= 100)
        {
            sec++;
            msec = 0;
        }
        if (sec >= 60)
        {
            min++;
            sec = 0;
        }
        if (min >= 100)
        {
            min = 0;
            sec = 0;
            msec = 0;
        }
    }
}

void timer0Routine() interrupt 1
{
    static unsigned int count_linekb, count_nixie, count_sec;
    TL0 = 0x66;
    TH0 = 0xFC;
    count_linekb++;
    if (count_linekb >= 20)
    {
        listenKeyLoop();
        count_linekb = 0;
    }
    count_nixie++;
    if (count_nixie >= 1000 / NIXIE_FPS)
    {
        nixieLoop();
        count_nixie = 0;
    }
    count_sec++;
    if (count_sec >= 10)
    {
        secLoop();
        count_sec = 0;
    }
}