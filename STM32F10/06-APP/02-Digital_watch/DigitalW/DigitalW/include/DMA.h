/*
 * DMA.h
 *
 *  Created on: Apr 15, 2020
 *      Author: MOSTAFA
 */

#ifndef DMA_H_
#define DMA_H_


typedef unsigned char uint_8t;
typedef unsigned short int uint_16t;
typedef unsigned long int uint_32t;
typedef unsigned long long uint_64t;
typedef signed char int_8t;
typedef signed short int int_16t;
typedef signed short int int_32t;

#define OK	0
#define NOK	1

#define CHANNEL_ONE		0
#define CHANNEL_TWO		1
#define CHANNEL_THREE	2
#define CHANNEL_FOUR	3
#define CHANNEL_FIVE	4
#define CHANNEL_SIX		5
#define CHANNEL_SEVEN	6

typedef void (*TC_Notification)(void);
typedef void (*HTC_Notification)(void);
typedef void (*TE_Notification)(void);


typedef struct
{
	TC_Notification		TC;
	HTC_Notification	HTC;
	TE_Notification		TE;
}Notify_t;

uint_8t D_DMA_Init(void);
uint_8t D_DMA_Start(uint_32t MemoryAddress,uint_32t PeripheralAddress,uint_32t Counter,uint_8t ChannelNumber);
uint_8t D_DMA_SetNotifyCbf(Notify_t *Notification, uint_8t Channel_Number);



#endif /* DMA_H_ */
