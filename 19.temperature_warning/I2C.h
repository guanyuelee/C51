#ifndef __I2C_H__
#define __I2C_H__
/****
	* @brief I2C开始
	* @param 无
	* @retval 无
	*/
void I2C_Start(void);

/****
	* @brief I2C停止发送
	* @param 无
	* @retval 无
	*/
void I2C_Stop(void);

/****
	* @brief I2C发送一个字节，8位
	* @param byte要发送的数据
	* @retval 无
	*/
void I2C_SendByte(unsigned char byte);

/****
	* @brief I2C接受数据，8位
	* @param 无
	* @retval 收到的数据
	*/
unsigned char I2C_ReceiveByte(void);

/****
	* @brief I2C发送应答
	* @param ack应答，ack=0为应答，1为非应答
	* @retval 无
	*/
void I2C_SendAck(unsigned char ack);

/****
	* @brief I2C接受应答
	* @param 无
	* @retval 应答，0为应答，1为非应答
	*/
unsigned char I2C_ReceiveAck(void);

#endif