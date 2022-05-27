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
	I2C_SendByte(address|0x01); 
	I2C_ReceiveAck();
	results = I2C_ReceiveByte();
	I2C_SendAck(1); 
	return results; 
}