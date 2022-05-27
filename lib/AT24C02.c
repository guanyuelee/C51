/*
 * @Author       : Guanyue li
 * @Date         : 2022-05-27 19:09:08
 * @LastEditTime : 2022-05-27 23:30:18
 * @Description  : file content
 * @FilePath     : \16.storage\AT24C02.c
 */
#include <REGX52.H>
#include "I2C.h"

#define AT24C02_ADDRESS 0xA0

void AT24C02_WriteByte(unsigned char address, unsigned char byte){
	I2C_Start();
	I2C_SendByte(AT24C02_ADDRESS); 
	I2C_ReceiveAck(); 
	I2C_SendByte(address);
	I2C_ReceiveAck(); 
	I2C_SendByte(byte); 
	I2C_ReceiveAck(); 
	I2C_Stop();
	// Note: 调用写入内容后记得要sleep一段时间（>=5ms） 
}

unsigned char AT24C02_ReadByte(unsigned char address){
	unsigned char results;
	I2C_Start();
	I2C_SendByte(AT24C02_ADDRESS); 
	I2C_ReceiveAck(); 
	I2C_SendByte(address);
	I2C_ReceiveAck(); 
	I2C_Start();
	// 设置地址为读取
	I2C_SendByte(AT24C02_ADDRESS|0x01); 
	I2C_ReceiveAck();
	results = I2C_ReceiveByte();
	I2C_SendAck(1); 
	return results; 
}