/*
 * HSwitch.h
 *
 *  Created on: Mar 16, 2020
 *      Author: MOSTAFA 
 */

#ifndef HSWITCH_H_
#define HSWITCH_H_
typedef unsigned char uint_8t;
typedef unsigned short int uint_16t;
typedef unsigned long int uint_32t;
typedef unsigned long long uint_64t;
typedef signed char int_8t;
typedef signed short int int_16t;
typedef signed short int int_32t;

#define OK       0
#define NOT_OK   1


#define SWITCH_PRESSED 0xfa
#define SWITCH_RELEASED 0xbb
/************Define switch numbers here***************************************/
#define COUNTER_SWITCH 0
/*****************************************************************************/

uint_8t Switch_Init (void);
uint_8t Switch_GetSwitchState(uint_8t SwitchNum,uint_8t * state);


#endif /* HSWITCH_H_ */
