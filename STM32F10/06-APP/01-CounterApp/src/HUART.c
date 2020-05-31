/*
 * HUART.c
 *
 *  Created on: Mar 28, 2020
 *      Author: MOSTAFA
 */
#include "DRCC.h"
#include "DGPIO.h"
#include "UART.h"
#include "HUART_config.h"
#include "HUART.h"
uint_32t Clk;
uint_8t HUART_Init(void)
{
	uint_8t Local_Error=OK;
	uint_32t BaudRate_Fraction;
	uint_32t BaudRate_Mantissa;
	/*configure GPIO Pins*/

	GPIO_t GPIO;
	GPIO.Mode=MODE_PIN10_IP_PUR|MODE_PIN9_AF_PP;
	GPIO.Speed=SPEED_PIN10_INPUT|SPEED_PIN9_2MHZ;
	GPIO.Port=PORT_A;
	GPIO.Pin=PIN_9|PIN_10;
	Local_Error=GPIO_Config(&GPIO);
	/*Set UART initial configuration*/
	Local_Error|=RCC_GetBusClock(APB2_BUS,&Clk);
	BaudRate_Mantissa = ( (Clk) / (16*BAUD_RATE) );
	BaudRate_Fraction = (( ( (Clk) % (16*BAUD_RATE) ) *16 ) / (16*BAUD_RATE));
	Local_Error|=UART_Init(BaudRate_Mantissa,BaudRate_Fraction,PARITY_BIT,DATA_BITS,STOP_BITS);
	return Local_Error;
}
uint_8t HUART_Send(uint_8t *Buffer, uint_16t Length)
{
	uint_8t localError=OK;
	localError= UART_Send(Buffer,Length);
	return localError;
}
uint_8t HUART_Receive(uint_8t *Buffer, uint_16t Length)
{
	uint_8t localError=OK;
	localError= UART_Receive(Buffer,Length);
	return localError;
}
uint_8t HUART_Config(uint_32t BaudRate,uint_32t ParityBits,uint_32t DataSize,uint_32t StopBits)
{
	uint_8t Local_Error=OK;
	uint_32t BaudRate_Fraction;
	uint_32t BaudRate_Mantissa;
	if((ParityBits==PARITY_DISABLED || ParityBits==PARITY_EVEN || ParityBits==PARITY_ODD) && (DataSize==DATA_8_BITS || DataSize==DATA_9_BITS) && (StopBits==ONE_STOP_BIT || StopBits==TWO_STOP_BIT))
	{
		BaudRate_Mantissa = ( (Clk) / (16*BaudRate) );
		BaudRate_Fraction = (( ( (Clk) % (16*BaudRate) ) *16 ) / (16*BaudRate));
		Local_Error=UART_Config(BaudRate_Mantissa,BaudRate_Fraction,ParityBits,DataSize,StopBits);
	}
	else
	{
		Local_Error=NOT_OK;
	}
	return Local_Error;
}
uint_8t HUART_SetTxCbf(TxCbf_t TxCbf)
{
	uint_8t LocalError=OK;
	if(TxCbf)
	{
		LocalError = UART_SetTxCbf(TxCbf);
	}
	else
	{
		LocalError=NOT_OK;
	}
	return LocalError;

}
uint_8t HUART_SetRxCbf(RxCbf_t RxCbf)
{
	uint_8t LocalError=OK;
	if(RxCbf)
	{
		LocalError = UART_SetRxCbf(RxCbf);
	}
	else
	{
		LocalError=NOT_OK;
	}
	return LocalError;
}
