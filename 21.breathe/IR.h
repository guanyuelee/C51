/*
 * @Author       : Guanyue li
 * @Date         : 2022-05-30 20:51:42
 * @LastEditTime : 2022-05-30 23:24:28
 * @Description  : file content
 * @FilePath     : \23.infrared\IR.h
 */
#ifndef __IR_H__
#define __IR_H__

#define BTN_POWER_OFF 0x45
#define BTN_MODE 0x46
#define BTN_MUTE 0x47

#define BTN_STOP_AND_PLAY 0x44
#define BTN_LEFT 0x40
#define BTN_RIGHT 0x43

#define BTN_EQ 0x07
#define BTN_VOLUME_MINUS 0x15
#define BTN_VOLUME_PLUS 0x09

#define BTN_NUM_0 0x16
#define BTN_RPT 0x19
#define BTN_U_AND_SD 0x0D

#define BTN_NUM_1 0x0C
#define BTN_NUM_2 0x18
#define BTN_NUM_3 0x5E

#define BTN_NUM_4 0x08
#define BTN_NUM_5 0x1C
#define BTN_NUM_6 0x5A

#define BTN_NUM_7 0x42
#define BTN_NUM_8 0x52
#define BTN_NUM_9 0x4A

void IR_Init(void); 

unsigned char IR_GetDataFlag(void); 

unsigned char IR_GetRepeatFlag(void);

unsigned char IR_GetAddress(void);

unsigned char IR_GetCommand(void); 

#endif