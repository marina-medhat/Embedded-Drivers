/*
 * CounterApp.c
 *
 *  Created on: Mar 28, 2020
 *      Author: MOSTAFA
 */
#include "Sched.h"
#include "DRCC.h"
#include "HLCD.h"
#include "HLED.h"
#include "HSwitch.h"
#include "HUART.h"
#include "CounterApp.h"
static void App_AppTask (void);
void APP_ReceiveDone(void);
void APP_TransmitDone(void);
void App_WriteDone (void);
task_t AppTask;
static uint_8t ReceiveFrame [5];
static uint_8t SentFrame [5];
uint_8t MyAPP_init(void)
{
	uint_8t LocalError=OK;
	/*Configure RCC Clock system*/
	RCC_SetPriephralStatus(USART_1_ENABLE,ON);
	RCC_SetPriephralStatus(GPIO_A_ENABLE,ON);
	RCC_SetPriephralStatus(GPIO_C_ENABLE,ON);
	RCC_SetBusPrescale(APB2_PRESCALER,APB2_PRESCALER_DIV_2);
	/*Configure Basic software component*/
	LocalError|=LCD_Init();
	LocalError|=LCD_SetWriteCallBackFunction(App_WriteDone);

	LocalError|=HLED_Init();
	LocalError|=HLED_SetLedState(COUNTER_LED,RESET);

	LocalError|=Switch_Init();
	LocalError|=HUART_Init();
	LocalError|=HUART_SetRxCbf(APP_ReceiveDone);
	LocalError|=HUART_SetTxCbf(APP_TransmitDone);
	/*Configure AppTask*/
	AppTask.Runnable=App_AppTask;
	AppTask.periodicity=110;
	/*	Configure Scheduler*/
	SentFrame[0]='0';
	SentFrame[1]='0';
	SentFrame[2]='0';
	SentFrame[3]='0';
	SentFrame[4]=SEND_LED_OFF;
	
	HUART_Send(SentFrame,(uint_16t)5);
	//HUART_Send(SentFrame,2);
	HUART_Receive(ReceiveFrame,(uint_16t)5);
	//HUART_Receive(ReceiveFrame,2);
	LocalError|=Sched_Init();
	return LocalError;
}
uint_8t MyApp (void)
{
	uint_8t LocalError=OK;
	/*Start scheduler*/
	LocalError=Sched_Start();

	/* Infinite loop*/
	while (1)
	{
		/* Do Nothing.*/
		asm ("NOP");
	}
	return LocalError;
}

static void App_AppTask (void)
{

	static uint_8t *temp;
	static uint_32t counter;
	static uint_8t LED_State;
	uint_8t switchVal;
	Switch_GetSwitchState(COUNTER_SWITCH,&switchVal);
	if (switchVal == SWITCH_PRESSED)
	{
		counter ++;
		LED_State = SEND_LED_ON;
	}
	else if (switchVal == SWITCH_RELEASED)
	{
		LED_State = SEND_LED_OFF;
	}
	else
	{
		/*Do Nothing*/
		asm ("NOP");
	}
	if (!counter)
	{
		SentFrame[0]=0xFF;
		SentFrame[1]=0xFF;
		SentFrame[2]=0xFF;
		SentFrame[3]=0xFF;
		SentFrame[4]=LED_State;
	}
	else
	{
		temp=(uint_8t *)&counter;
		SentFrame[0]=*temp;
		SentFrame[1]=*(temp+1);
		SentFrame[2]=*(temp+2);
		SentFrame[3]=*(temp+3);
		SentFrame[4]=LED_State;
		/*
		 *
	 temp=(uint_8t)((counter>>24) & 0x000000FF);
	SentFrame[0]=temp;
	temp=(uint_8t)((counter>>16) & 0x000000FF);
	SentFrame[1]=temp;
	temp=(uint_8t)((counter>>8)  & 0x000000FF);
	SentFrame[2]=temp;
	temp=(uint_8t)((counter)     & 0x000000FF);
	SentFrame[3]=temp;
		 */
	}

	/*uint_8t x;
	Switch_GetSwitchState(COUNTER_SWITCH,&x);
	if (x==SWITCH_PRESSED)
	{
		temp++;
		SentFrame[0]=temp;
		SentFrame[1]=SEND_LED_ON;
	}
	else if (x==SWITCH_RELEASED)
	{
		SentFrame[1]=SEND_LED_OFF;
	}
	else
	{
		asm ("NOP");
	}
	LCD_WriteData(ReceiveFrame,1);
	 */

}

void APP_ReceiveDone(void)
{
	uint_8t *ptr;
	uint_8t idx=0;
	uint_8t Display[16];
	static uint_32t RecCounter;
	uint_32t temp=5;
	if (ReceiveFrame[0] == 0xFF && ReceiveFrame[1] == 0xFF  &&ReceiveFrame[2] == 0xFF && ReceiveFrame[3] == 0xFF)
	{
		RecCounter=0;
		Display[0]='0';
		LCD_WriteData(Display,1);

	}
	else
	{
		if (ReceiveFrame[4] ==SEND_LED_ON)
		{
			HLED_SetLedState(COUNTER_LED,SETT);
		}
		else if (ReceiveFrame[4] ==SEND_LED_OFF)
		{
			HLED_SetLedState(COUNTER_LED,RESET);
		}
		ptr=(uint_8t*)&RecCounter;
	 	*ptr=ReceiveFrame[0];
		*(ptr+1)=ReceiveFrame[1];
		*(ptr+2)=ReceiveFrame[2];
		*(ptr+3)=ReceiveFrame[3];
		/*
		RecCounter=0;
		RecCounter|=(uint_32t)((((uint_32t)ReceiveFrame[0])<<24) | (((uint_32t)ReceiveFrame[1])<<16) | (((uint_32t)ReceiveFrame[2])<<8) | ((uint_32t)ReceiveFrame[3]));
		 */
		while (RecCounter!=0)
		{
			temp*=10;
			temp+=RecCounter%10;
			RecCounter/=10;
		}
		while (temp!=5)
		{
			Display[idx]=(temp%10)+'0';
			temp/=10;
			idx++;
		}
		LCD_WriteData(Display,idx);
	}
	HUART_Receive(ReceiveFrame,5);

	/*	if (ReceiveFrame[0]=='M')
	{
		ReceiveFrame[0]=0;
		HLED_SetLedState(COUNTER_LED,RESET);
	}
	else
	{
		if (ReceiveFrame[1]== SEND_LED_OFF)
		{
			HLED_SetLedState(COUNTER_LED,RESET);

		}
		else if (ReceiveFrame[1]== SEND_LED_ON)
		{

			HLED_SetLedState(COUNTER_LED,SETT);
		}
		else
		{
			HLED_SetLedState(COUNTER_LED,RESET);

		}
	}
	ReceiveFrame[0]+='0';
	LCD_WriteData(ReceiveFrame,1);
	HUART_Receive(ReceiveFrame,2);
	 */
}

void App_WriteDone (void)
{
	LCD_SetPosition(FIRST_ROW,0);
}
void APP_TransmitDone(void)
{
	HUART_Send(SentFrame,5);
	//HUART_Send(SentFrame,2);
}
