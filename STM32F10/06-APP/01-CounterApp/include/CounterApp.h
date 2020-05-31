/*
 * CounterApp.h
 *
 *  Created on: Mar 28, 2020
 *      Author: MOSTAFA
 */

#ifndef COUNTERAPP_H_
#define COUNTERAPP_H_
typedef unsigned char uint_8t;
typedef unsigned short int uint_16t;
typedef unsigned long int uint_32t;
typedef unsigned long long uint_64t;
typedef signed char int_8t;
typedef signed short int int_16t;
typedef signed short int int_32t;

#define OK       0
#define NOT_OK   1
#define SEND_LED_ON 0xCC
#define SEND_LED_OFF 0xAA
uint_8t MyAPP_init(void);
uint_8t MyApp (void);



#endif /* COUNTERAPP_H_ */
