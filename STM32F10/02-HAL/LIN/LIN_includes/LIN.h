#ifndef LIN_H_
#define LIN_H_

/*************************************
 *******LIN_CALL_BACK_FUNCTIONS*******
 *************************************/
typedef void(*TxCbf_t)(void);
typedef void(*RxCbf_t)(void);

/****************************************************************************************************
 * Function name: LIN_Init                                           	                            *
 *                                                                                                  *
 * parameters:  Input:  NA                                     							            *
 *                                                                                                  *
 *              Output: NA                                                                          *
 *              In/out: NA                                                                          *
 * return: E_OK, E_NOK                                                                              *
 * Description: a function that initialize the LIN										            *
 ****************************************************************************************************/
uint_8t LIN_Init(void);

/****************************************************************************************************
 * Function name: LIN_SendData                                                                      *
 *                                                                                                  *
 * parameters:  Input:                                                                              *
 *                 msgID                                                                            *
 *                     type: uint_8t 					                                            *
 *                     Description: ID of the msg to be sent                                        *
 *                 data                                                                             *
 *                     type: uint_8t (pointer to uint_8t)					                        *
 *                     Description: data buffer to be sent                                          *
 *                                                                                                  *
 *              Output: NA                                                                          *
 *              In/out: NA                                                                          *
 * return: E_OK, E_NOK                                                                              *
 * Description: a function that send maximum of 8 data bytes with a certain ID                      *
 ****************************************************************************************************/
uint_8t LIN_SendData(uint_8t msgID, uint_8t * data);

/****************************************************************************************************
 * Function name: LIN_ReceiveData                                                                   *
 *                                                                                                  *
 * parameters:  Input:                                                                              *
 *                 msgID                                                                            *
 *                     type: uint_8t 					                                            *
 *                     Description: ID of the msg to be sent                                        *
 *                                                                                                  *
 *              Output: NA                                                                          *
 *              In/out:                                                                             *
 *                 data                                                                             *
 *                     type: uint_8t (pointer to uint_8t)					                        *
 *                     Description: data buffer to be received                                      *
 * return: E_OK, E_NOK                                                                              *
 * Description: a function taht receives maximum of 8 data bytes with a certain ID                  *
 ****************************************************************************************************/
uint_8t LIN_ReceiveData(uint_8t msgID, uint_8t * data);

/****************************************************************************************************
 * Function name: LIN_SetTxCbf                                                                      *
 *                                                                                                  *
 * parameters:  Input:                                                                              *
 *                 TxCbf                                                                            *
 *                     type: TxCbf_t (pointer to function)                                          *
 *                     Description: call back function                                              *                                               *
 *                                                                                                  *
 *              Output: NA                                                                          *
 *              In/out: NA                                                                          *
 * return: E_OK, E_NOK                                                                              *
 * Description: a function that sets the call back function of the LIN transmission complete        *
 ****************************************************************************************************/
uint_8t LIN_SetTxCbf(TxCbf_t TxCbf);

/****************************************************************************************************
 * Function name: LIN_SetRxCbf                                                                      *
 *                                                                                                  *
 * parameters:  Input:                                                                              *
 *                 RxCbf                                                                            *
 *                     type: RxCbf_t (pointer to function)                                          *
 *                     Description: call back function                                              *                                               *
 *                                                                                                  *
 *              Output: NA                                                                          *
 *              In/out: NA                                                                          *
 * return: E_OK, E_NOK                                                                              *
 * Description: a function that sets the call back function of the LIN receiving complete           *
 ****************************************************************************************************/
uint_8t LIN_SetRxCbf(RxCbf_t RxCbf);

#endif
