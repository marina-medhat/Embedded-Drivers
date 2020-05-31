/*
 * HSwitch.h
 *
 *  Created on: Mar 16, 2020
 *      Author: Mohanad Sallam
 */

#ifndef HSWITCH_H_
#define HSWITCH_H_
#include "HSwitch_SwitchNumber.h"

typedef unsigned char uint_8t;
typedef unsigned short int uint_16t;
typedef unsigned long int uint_32t;
typedef unsigned long long uint_64t;
typedef signed char int_8t;
typedef signed short int int_16t;
typedef signed short int int_32t;

#define OK       0
#define NOT_OK   1

/*************************************
 ************SWITCH_STATE*************
 *************************************/
#define SWITCH_PRESSED 0xfa
#define SWITCH_RELEASED 0xbb


/************************************************************************
 * Function name: Switch_Init
 *
 * parameters:  Input: NA      
 *
 *
 *              Output: NA
 *              In/out: NA
 * return: OK, NOT_OK
 * Description: a function to initialize switch
 ***************************************************************************/
 
uint_8t Switch_Init (void);

/************************************************************************
 * Function name: Switch_GetSwitchState
 *
 * parameters:  Input: 
 *                 SwitchNum
 *                     Type: uint_8t
 *                     Description: Switch Name and Number (Hswitch_LED...)
 *
 *              Output: NA
 *              In/out: state
 *                     type: pointer to uint_8t
 *                     Description: Switch State which to be read
 * return: OK, NOT_OK
 * Description: a function to read Switch State
 ***************************************************************************/
 
uint_8t Switch_GetSwitchState(uint_8t SwitchNum,uint_8t * state);


#endif /* HSWITCH_H_ */
