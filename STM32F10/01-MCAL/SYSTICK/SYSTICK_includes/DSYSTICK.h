/*************************************
 *****MACROS_AHB_CLK_PRESCALER********
 *************************************/
#define SYSTICK_CLK_AHB  	   0x00000004
#define SYSTICK_CLK_AHB_DIV_8  0x00000000


/*************************************
 ****MACROS_SYSTICK_TICK_INTERRUPT****
 *************************************/
#define SYSTICK_TICK_INT_ENABLE  0x00000002
#define SYSTICK_TICK_INT_DISABLE 0x00000000

typedef void (*systickcbf_t) (void);

/******************************************************************************     
 * Function name: SYSTICK_Init                                                *
 * parameters:  Input:  NA                                                    *
 *              Output: NA                                                    *
 *              In/out: NA                                                    *
 * return: OK, NOT_OK                                                         *
 * Description: a function initialize the clk source and interrupt of SYSTICK *
 ******************************************************************************/
uint_8t SYSTICK_Init (void);

/**************************************************************************
 * Function name: SYSTICK_Start                                           *
 * parameters:  Input:  NA                                                *
 *              Output: NA                                                *
 *              In/out: NA                                                *
 * return: OK, NOT_OK                                                     *
 * Description: a function Start SYSYTICK                                 *
 *************************************************************************/
uint_8t SYSTICK_Start (void);

/*************************************************************************
 * Function name: SYSTICK_Stop                                           *
 * parameters:  Input:  NA                                               *
 *              Output: NA                                               *
 *              In/out: NA                                               *
 * return: OK, NOT_OK                                                    *
 * Description: a function Stop SYSYTICK                                 *
 *************************************************************************/
uint_8t SYSTICK_Stop (void);

/*************************************************************************
 * Function name: SYSTICK_SetCallback                                    *
 * parameters:  Input:                                                   *
 *                 cbf                                                   *
 *                     type: systickcbf_t                                *
 *                      Description:Call Back Function indicate the      *
 *                                   SYSTICK Counter finished            *
 *              Output: NA                                               *
 *              In/out: NA                                               *
 * return: OK, NOT_OK                                                    *
 * Description: a function set call back function                        *
 *************************************************************************/
uint_8t SYSTICK_SetCallback (systickcbf_t cbf);

/*************************************************************************
 * Function name: SYSTICK_SetTime                                        *
 * parameters:  Input:                                                   *
 *                 timeus                                                *
 *                     type: uint_32t                                    *
 *                      Description:variable that contains time          *
                                    in micro secs                        * 
 *                 clk                                                   *
 *                     type: uint_32t                                    *
 *                      Description:variable that contains System clk    *
 *              Output: NA                                               *
 *              In/out: NA                                               *
 * return: OK, NOT_OK                                                    *
 * Description: a function sets the time to be counted until interuupt   *
 *              fires                                                    *
 *************************************************************************/
uint_8t SYSTICK_SetTime (uint_32t timeus,uint_32t clk);


