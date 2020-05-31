/*
 * HUART.h
 *
 *  Created on: Mar 28, 2020
 *      Author: Marina
 */


#ifndef HUART_H_
#define HUART_H_

#define BUSY	2
typedef void(*TxCbf_t)(void);
typedef void(*RxCbf_t)(void);

/*************************************************************************
 * Function name: HUART_Init                                             *
 * parameters:  Input:  NA                                               *
 *              Output: NA                                               *
 *              In/out: NA                                               *
 * return: OK, NOT_OK                                                    *
 * Description: a function initilaize HUART                              *
 *************************************************************************/
uint_8t HUART_Init(void);

/*************************************************************************
 * Function name: HUART_Send                                             *
 * parameters:  Input:                                                   *
 *                 Buffer                                                *
 *                     type: uint_8t(pointer to uint_8t)                 *
 *                      Description:pointer that contain the bytes to be *
                                    sent                                 *
 *                 Length                                                *
 *                     type: uint_16t                                    *
 *                      Description:variable that contains the number of *
 *                                   Bytes to be sent                    *
 *              Output: NA                                               *
 *              In/out: NA                                               *
 * return: OK, NOT_OK                                                    *
 * Description: a function sends bytes using UART                        *
 *************************************************************************/
uint_8t HUART_Send(uint_8t *Buffer, uint_16t Length);

/*************************************************************************
 * Function name: HUART_Receive                                          *
 * parameters:  Input:                                                   *
 *                 Length                                                *
 *                     type: uint_16t                                    *
 *                      Description:variable that contains the number of *
 *                                   Bytes to be Received                *
 *              Output: NA                                               *
 *              In/out:                                                  *
 *                 Buffer                                                *
 *                     type: uint_8t(pointer to uint_8t)                 *
 *                      Description:pointer that will contain the        *
 *                                  Received  bytes                      *
 * return: OK, NOT_OK                                                    *
 * Description: a function receives bytes using UART                     *
 *************************************************************************/
uint_8t HUART_Receive(uint_8t *Buffer, uint_16t Length);

/*************************************************************************
 * Function name: HUART_Config                                           *
 * parameters:  Input:                                                   *
 *                 BaudRate                                              *
 *                     type: uint_32t                                    *
 *                      Description:variable that contains Baud Rate     *
 *                 ParityBits                                            *
 *                     type: uint_32t                                    *
 *                      Description:variable that contains ParityState   *
 *                                   ->PARITY_DISABLED	                 *                 
 *                                   ->PARITY_EVEN		                 *
 *                                   ->PARITY_ODD		                 *
 *                 DataSize                                              *
 *                     type: uint_32t                                    *
 *                      Description:variable that contains DataSize      *
 *                                  ->DATA_8_BITS                        *
 *									->DATA_9_BITS                        *
 *                 StopBits                                              *
 *                     type: uint_32t                                    *
 *                      Description:variable that contains number of     *
 *                                   StopBits                            *
 *                                  ->ONE_STOP_BIT                       *
 *                                  ->TWO_STOP_BIT                       *
 *              Output: NA                                               *
 *              In/out: NA                                               *
 * return: OK, NOT_OK                                                    *
 * Description: a function configure HUART                               *
 *************************************************************************/
uint_8t HUART_Config(uint_32t BaudRate,uint_32t ParityBits,uint_32t DataSize,uint_32t StopBits);

/*************************************************************************
 * Function name: HUART_SetTxCbf                                         *
 * parameters:  Input:                                                   *
 *                 TxCbf                                                 *
 *                     type: TxCbf_t(pointer to function)                *
 *                      Description:pointer take address of call back    *
 *                                  function                             *
 *              Output: NA                                               *
 *              In/out: NA                                               *
 * return: OK, NOT_OK                                                    *
 * Description: a function sets the send call back function              *
 *************************************************************************/
uint_8t HUART_SetTxCbf(TxCbf_t TxCbf);

/*************************************************************************
 * Function name: HUART_SetRxCbf                                         *
 * parameters:  Input:                                                   *
 *                 RxCbf                                                 *
 *                     type: RxCbf_t(pointer to function)                *
 *                      Description:pointer take address of call back    *
 *                                  function                             *
 *              Output: NA                                               *
 *              In/out: NA                                               *
 * return: OK, NOT_OK                                                    *
 * Description: a function sets the Received call back function          *
 *************************************************************************/
uint_8t HUART_SetRxCbf(RxCbf_t RxCbf);




#endif /* HUART_H_ */
