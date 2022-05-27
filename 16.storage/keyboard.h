/*
 * @Author       : Guanyue li
 * @Date         : 2022-05-27 18:58:51
 * @LastEditTime : 2022-05-27 23:38:46
 * @Description  : file content
 * @FilePath     : \16.storage\keyboard.h
 */
#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

// They listen the key pressed by the user. 

/**
 * @description: 监听矩阵按键 
 * @return {返回一个1-16的值，代表被按的按键}
 */
unsigned char listenMatrixKey();

/**
 * @description: 监听一行的按键
 * @return {返回1-4的值，代表被按下的按键}
 */
unsigned char listenLineKey(); 

#endif
