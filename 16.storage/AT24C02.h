/*
 * @Author       : Guanyue li
 * @Date         : 2022-05-27 19:08:28
 * @LastEditTime : 2022-05-27 22:56:35
 * @Description  : file content
 * @FilePath     : \16.storage\AT24C02.h
 */
#ifndef __AT24C02_H__
#define __AT24C02_H__

/**
 * @description: 这是给AT24C02写入一个地址为address的字节byte.
 * @param {unsigned char} address: 要写入的地址
 * @param {unsigned char} byte: 要写入的字节
 * @return {无}
 */
void AT24C02_WriteByte(unsigned char address, unsigned char byte);


/**
 * @description: 读取位于地址address的字节
 * @param {unsigned char} address： 要写入的地址
 * @return {读取的字节}
 */
unsigned char AT24C02_ReadByte(unsigned char address); 

#endif