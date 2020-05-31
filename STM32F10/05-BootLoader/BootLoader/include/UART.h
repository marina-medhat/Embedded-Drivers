/*
 * UART.h
 *
 *  Created on: Mar 25, 2020
 *      Author: MOSTAFA
 */
#ifndef DUART_H_
#define DUART_H_


#define BUSY	2

/*************************************
 *******UART_TX_INTERRUPT_ENABLES*****
 *************************************/
#define USART_TCEIE_ENABLE				0x00000040
#define USART_TXEIE_ENABLE				0x00000080

/*************************************
 *******UART_RX_INTERRUPT_ENABLE*****
 *************************************/
#define USART_RXNEIE_ENABLE				0x00000020

/*************************************
 *******UART_CALL_BACK_FUNCTIONS******
 *************************************/
typedef void(*TxCbf_t)(void);
typedef void(*RxCbf_t)(void);
typedef void(*LBDCbf_t)(void);

/****************************************************************************************************
 * Function name: DUART_Init                                                                        *
 *                                                                                                  *
 * parameters:  Input:                                                                              *
 *                 BaudRateMantissa                                                                 *
 *                     type: uint_32t                                                               *
 *                     Description: Baudrate's mantissa paramter                                    *
 *                 BaudRateFraction                                                                 *
 *                     type: uint_32t                                                               *
 *                     Description: Baudrate's fraction paramter                                    *
 *                 ParityBits                                                                       *
 *                     type: uint_32t                                                               *
 *                     Description: even parity , odd parity                                        *                                                       *
 *                 DataSize                                                                         *                            *
 *                     type: uint_32t                                                               *
 *                     Description: Data length 5->9 bits                                           *
 *                 StopBits                                                                         *
 *                     type: uint_32t                                                               *
 *                     Description: one stop bit , two stop bits                                    *
 *				                                                                                    *
 *				Output: NA         			                                                        *
 *				In/out: NA         			                                                        *
 *                                 			                                                        *
 * return: E_OK, E_NOK             			                                                        *
 * Description: a function that initializes the UART                                                *
 ****************************************************************************************************/
uint_8t DUART_Init(uint_32t BaudRateMantissa, uint_32t BaudRateFraction,uint_32t ParityBits,uint_32t DataSize,uint_32t StopBits);

/****************************************************************************************************
 * Function name: DUART_Send                                                                        *
 *                                                                                                  *
 * parameters:  Input:                                                                              *
 *                 Buffer                                                                           *
 *                     type: uint_8t (pointer to uint_8t)                                           *
 *                     Description: Buffer that contains data to be sent                            *
 *                 Length                                                                           *
 *                     type: uint_16t                                                               *
 *                     Description: Length of data to be sent                                       *
 *                                                                                                  *
 *              Output: NA                                                                          *
 *              In/out: NA                                                                          *
 * return: E_OK, E_NOK                                                                              *
 * Description: a function that sends buffer of data thorught uart using interrupt or dma modes     *
 ****************************************************************************************************/
uint_8t DUART_Send(uint_8t *Buffer, uint_16t Length);


/****************************************************************************************************
 * Function name: DUART_Receive                                                                     *
 *                                                                                                  *
 * parameters:  Input:                                                                              *                                          *
 *                 Length                                                                           *
 *                     type: uint_16t                                                               *
 *                     Description: Length of data to be received                                   *
 *                                                                                                  *
 *              Output: NA                                                                          *
 *              In/out:                                                                             *
 *					Buffer                                                                          *
 *                     type: uint_8t (pointer to uint_8t)                                           *                    
 *                     Description: buffer that store the received data	(out)			         	*
 * return: E_OK, E_NOK                                                                              *
 * Description: a function receives a buffer of data using interrupt or DMA                         *
 ****************************************************************************************************/
uint_8t DUART_Receive(uint_8t *Buffer, uint_16t Length);

/****************************************************************************************************
 * Function name: DUART_Config                                                                    *
 *                                                                                                  *
 * parameters:  Input:                                                                              *
 *                 BaudRateMantissa                                                                 *
 *                     type: uint_32t                                                               *
 *                     Description: Baudrate's mantissa paramter                                    *
 *                 BaudRateFraction                                                                 *
 *                     type: uint_32t                                                               *
 *                     Description: Baudrate's fraction paramter                                    *
 *                 ParityBits                                                                       *
 *                     type: uint_32t                                                               *
 *                     Description: even parity , odd parity                                        *                                                       *
 *                 DataSize                                                                         *                            *
 *                     type: uint_32t                                                               *
 *                     Description: Data length 5->9 bits                                           *
 *                 StopBits                                                                         *
 *                     type: uint_32t                                                               *
 *                     Description: one stop bit , two stop bits                                    *
 *                                                                                                  *
 *              Output: NA                                                                          *
 *              In/out: NA                                                                          *
 * return: E_OK, E_NOK                                                                              *
 * Description: a function configure the UART                                                       *
 ****************************************************************************************************/
uint_8t DUART_Config(uint_32t BaudRateMantissa, uint_32t BaudRateFraction,uint_32t ParityBits,uint_32t DataSize,uint_32t StopBits);

/****************************************************************************************************
 * Function name: DUART_SetTxCbf                                                                    *
 *                                                                                                  *
 * parameters:  Input:                                                                              *
 *                 TxCbf                                                                             *
 *                     type: TxCbf_t (pointer to function)                                          *
 *                     Description: call back function                                              *                                               *
 *                                                                                                  *
 *              Output: NA                                                                          *
 *              In/out: NA                                                                          *
 * return: E_OK, E_NOK                                                                              *
 * Description: a function that sets the call back function of the transmission complete            *
 ****************************************************************************************************/
uint_8t DUART_SetTxCbf(TxCbf_t TxCbf);

/****************************************************************************************************
 * Function name: DUART_SetRxCbf                                                                    *
 *                                                                                                  *
 * parameters:  Input:                                                                              *
 *                 RxCbf                                                                            *
 *                     type: RxCbf_t (pointer to function)                                          *
 *                     Description: call back function                                              *                                               *
 *                                                                                                  *
 *              Output: NA                                                                          *
 *              In/out: NA                                                                          *
 * return: E_OK, E_NOK                                                                              *
 * Description: a function that sets the call back function of the receiving is complete            *
 ****************************************************************************************************/
uint_8t DUART_SetRxCbf(RxCbf_t RxCbf);

/****************************************************************************************************
 * Function name: DUART_SetLBDCbf                                                                   *
 *                                                                                                  *
 * parameters:  Input:                                                                              *
 *                 LBDCbf                                                                           *
 *                     type: LBDCbf_t (pointer to function)                                         *
 *                     Description: call back function                                              *                                               *
 *                                                                                                  *
 *              Output: NA                                                                          *
 *              In/out: NA                                                                          *
 * return: E_OK, E_NOK                                                                              *
 * Description: a function that sets the call back function of the LIN break detection              *
 ****************************************************************************************************/
uint_8t DUART_SetLBDCbf(LBDCbf_t LBDCbf);

/****************************************************************************************************
 * Function name: DMA_ChannelFour_Finish                                                            *
 *                                                                                                  *
 * parameters:  Input:  NA                                         							        *
 *              Output: NA                                                                          *
 *              In/out: NA                                                                          *
 * return: NA                                                                                       *
 * Description: Function called when UART finishes transmission through DMA                         *
 ****************************************************************************************************/
void DMA_ChannelFour_Finish(void);

/****************************************************************************************************
 * Function name: DMA_ChannelFive_Finish                                                            *
 *                                                                                                  *
 * parameters:  Input:  NA                                         							        *
 *              Output: NA                                                                          *
 *              In/out: NA                                                                          *
 * return: NA                                                                                       *
 * Description: Function called when UART finishes receiving through DMA                            *
 ****************************************************************************************************/
void DMA_ChannelFive_Finish(void);

/****************************************************************************************************
 * Function name: DUART_SendBreak                                                            *
 *                                                                                                  *
 * parameters:  Input:  NA                                         							        *
 *              Output: NA                                                                          *
 *              In/out: NA                                                                          *
 * return: NA                                                                                       *
 * Description: a function that enables the bit that send a LIN break                               *
 ****************************************************************************************************/
void DUART_SendBreak(void);

#endif
