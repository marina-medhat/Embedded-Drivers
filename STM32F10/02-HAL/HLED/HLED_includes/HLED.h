/**************************************
 ***MACROS_OF_ALL_LEDS_IN_THE_SYSTEM***
 **************************************/
#define LED_1	    0
#define LED_2	    1

/**************************************
 *****NUMBER_OF_LEDS_IN_THE_SYSTEM*****
 **************************************/
#define LED_NUM		2

/**************************************
 **************LED_MODES***************
 **************************************/
#define	ACTIVE_HIGH	    1
#define	ACTIVE_LOW	    0


/*************************************************************************
 * Function name: HLED_Init                                              *
 * parameters:  Input:  NA                                               *                                                                       *                                                                      *
 *              Output: NA                                               *
 *              In/out: NA                                               *
 * return: OK, NOT_OK                                                    *
 * Description: a function Configure GPIO pins of Leds in the system     *
 *************************************************************************/
uint_8t HLED_Init(void);

/*************************************************************************
 * Function name: HLED_SetLedState                                       *
 * parameters:  Input:                                                   *
 *                  Led_Number                                           *     
 *                      type: uint_8t                                    *
 *                       Description:variable that has the led number    *
 *						              Led Number:LED_x(LED_1,LED_2,..)   *
 *																		 *
 *					Led_State                                            *     
 *                        type: uint_8t                                  *
 *                         Description:variable that has the state of led*
 *						              Led State: (SET , CLEAR )          *
 *									                                     *
 *			                                                             *
 *              Output: NA                                               *
 *              In/out: NA                                               *
 * return: OK, NOT_OK                                                    *
 * Description:a function write the state of the pin of Led in the system*
 *************************************************************************/
uint_8t HLED_SetLedState(uint_8t Led_Number,uint_8t Led_State);
