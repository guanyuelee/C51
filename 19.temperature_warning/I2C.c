#include <REGX52.H>

sbit I2C_SCL=P2^1;
sbit I2C_SDA=P2^0; 

/****
	* @brief I2C开始
	* @param 无
	* @retval 无
	*/
void I2C_Start(void){
	I2C_SDA = 1;
	I2C_SCL = 1; 
	I2C_SDA = 0;	
	I2C_SCL = 0;
}

/****
	* @brief I2C停止发送
	* @param 无
	* @retval 无
	*/
void I2C_Stop(void){
	I2C_SDA = 0;
	I2C_SCL = 1;
	I2C_SDA = 1;
}

/****
	* @brief I2C发送一个字节，8位
	* @param byte要发送的数据
	* @retval 无
	*/
void I2C_SendByte(unsigned char byte){
	unsigned char i;
	for(i=0; i<8; i++){
		I2C_SDA = byte & (0x80>>i); 
		I2C_SCL = 1;
		I2C_SCL = 0;
	}
}

/****
	* @brief I2C接受数据，8位
	* @param 无
	* @retval 收到的数据
	*/
unsigned char I2C_ReceiveByte(void){
	unsigned char byte, i;	
	I2C_SDA = 1; 
	for(i=0; i<8; i++){
		I2C_SCL = 1; 
		if(I2C_SDA){ byte |= (0x80>>i); }
		I2C_SCL = 0;
	}
	return byte; 
}

/****
	* @brief I2C发送应答
	* @param ack应答，ack=0为应答，1为非应答
	* @retval 无
	*/
void I2C_SendACK(unsigned char ack){
	I2C_SDA = ack; 
	I2C_SCL = 1; 
	I2C_SCL = 0; 
}

/****
	* @brief I2C接受应答
	* @param 无
	* @retval 应答，0为应答，1为非应答
	*/
unsigned char I2C_ReceiveACK(void){
	unsigned char ack; 
	I2C_SDA = 1; 
	I2C_SCL = 1; 
	ack = I2C_SDA; 
	I2C_SCL = 0; 
	return ack;
}
