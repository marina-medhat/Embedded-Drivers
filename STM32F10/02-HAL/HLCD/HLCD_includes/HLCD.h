#ifndef HLCD_H_
#define HLCD_H_


/*************************************
 **************LCD_ROWS***************
 *************************************/
#define FIRST_ROW   0
#define SECOND_ROW  1

/*************************************
 *******LCD_POINTER_TO_FUNCTION*******
 *************************************/
typedef void(*LCDCbf_t)(void);

/****************************************************************************************************
 * Function name: HLCD_Init                                                                         *
 *                                                                                                  *
 * parameters:  Input:  NA                                                                          *
 *              Output: NA                                                                          *
 *              In/out: NA                                                                          *
 * return: E_OK, E_NOK                                                                              *
 * Description: a function that initializes the LCD through the states defined in the state machine *
 ****************************************************************************************************/
uint_8t HLCD_Init (void);

/****************************************************************************************************
 * Function name: HLCD_WriteData                                                                    *
 *                                                                                                  *
 * parameters:  Input:                                                                              *
 *                 data                                                                             *
 *                     type: uint_8t (pointer to uint_8t)                                           *
 *                     Description: Data displayed on LCD                                           *
 *                 DataLength                                                                       *
 *                     type: uint_8t                                                                *
 *                     Description: Length of data                                                  *
 *                                                                                                  *
 *              Output: NA                                                                          *
 *              In/out: NA                                                                          *
 * return: E_OK, E_NOK                                                                              *
 * Description: a function that displays data on LCD                                                *
 ****************************************************************************************************/
uint_8t HLCD_WriteData (const uint_8t *data,uint_8t DataLength);

/****************************************************************************************************
 * Function name: HLCD_ClearLCD                                                                     *
 *                                                                                                  *
 * parameters:  Input:  NA	                                                                        *
 *                                                                                                  *
 *              Output: NA                                                                          *
 *              In/out: NA                                                                          *
 * return: E_OK, E_NOK                                                                              *
 * Description: a function that clears the LCD                                             		    *
 ****************************************************************************************************/
uint_8t HLCD_ClearLCD (void);

/****************************************************************************************************
 * Function name: HLCD_SetPosition                                                                  *
 *                                                                                                  *
 * parameters:  Input:                                                                              *
 *                 YPos                                                                             *
 *                     type: uint_8t                                          					    *
 *                     Description:    FIRST_ROW - SECOND_ROW                                       *
 *                 XPos                                                                   	        *
 *                     type: uint_8t                                                                *
 *                     Description:    0 ... 15                                                     *
 *                                                                                                  *
 *              Output: NA                                                                          *
 *              In/out: NA                                                                          *
 * return: E_OK, E_NOK                                                                              *
 * Description: a function that sets the LCD cursor's position                                      *
 ****************************************************************************************************/
uint_8t HLCD_SetPosition (uint_8t YPos,uint_8t XPos);

/****************************************************************************************************
 * Function name: HLCD_SetWriteCallBackFunction                                                     *
 *                                                                                                  *
 * parameters:  Input:                                                                              *
 *                 data                                                                             *
 *                     type: LCDCbf_t (pointer to function)                                         *
 *                     Description: Call back function                                              *
 *              Output: NA                                                                          *
 *              In/out: NA                                                                          *
 * return: E_OK, E_NOK                                                                              *
 * Description: a function that sets the LCD's call back function                                   *
 ****************************************************************************************************/
uint_8t HLCD_SetWriteCallBackFunction (LCDCbf_t cbf);
#endif
