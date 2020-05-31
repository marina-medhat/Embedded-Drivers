
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


void SPI_voidInit(void);

ErrorStatus SPI_u8SendByteSynch(u8 Data);
ErrorStatus SPI_u8ReceiveByteSynch(u8 *Data);
ErrorStatus SPI_u8_Send_Receive_ByteSynch(u8 Data_S,u8 *Data_R);

ErrorStatus SPI_u8SendReceiveBufferASynch(u8 *Data_S,u8 *Data_R,u8 BufferSize,void(*NotificationFuction)(void));




#endif

