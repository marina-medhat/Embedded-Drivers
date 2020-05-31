/*
 * HSwitch.c
 *
 *  Created on: Mar 16, 2020
 *      Author: MOSTAFA
 */
#include "Sched.h"
#include "DGPIO.h"
#include "DRCC.h"
#include "HSwitch.h"
#include "HSwitch_config.h"
task_t SwitchTask;
uint_8t SwitchStates [NUM_OF_SWITCH];
static void Switch_SwitchTask (void)
{
	uint_8t i=0;
	static uint_8t previousState[NUM_OF_SWITCH] ;
	static uint_8t counter[NUM_OF_SWITCH] ;
	uint_8t currentState ;
	for (i=0;i<NUM_OF_SWITCH;i++)
	{
		GPIO_ReadPin(MySwitches[i].SwitchConfig.Port,MySwitches[i].SwitchConfig.Pin,&currentState);
		if (currentState==previousState[i])
		{
			counter[i]++;
		}
		else
		{
			counter[i]=0;
			previousState[i]=currentState;
		}
		if (counter[i]==5)
		{
			if ((MySwitches[i].Mode == PULL_UP_SWITCH) && (currentState))
			{
				SwitchStates[i]=SWITCH_RELEASED;
			}
			else if ((MySwitches[i].Mode == PULL_UP_SWITCH) && (!currentState))
			{
				SwitchStates[i]=SWITCH_PRESSED;
			}
			else if ((MySwitches[i].Mode == PULL_DOWN_SWITCH) && (currentState))
			{
				SwitchStates[i]=SWITCH_PRESSED;
			}
			else if ((MySwitches[i].Mode == PULL_DOWN_SWITCH) && (! currentState))
			{
				SwitchStates[i]=SWITCH_RELEASED;
			}
			else
			{

			}
			counter[i]=0;
		}
	}
}
uint_8t Switch_Init (void)
{
	uint_8t LocalError=OK;
	uint_8t i;
	SwitchTask.Runnable = Switch_SwitchTask;
	SwitchTask.periodicity = 5;
	for (i=0;i<NUM_OF_SWITCH;i++)
	{
		if (MySwitches[i].SwitchConfig.Port==PORT_A)
		{
			RCC_SetPriephralStatus(GPIO_A_ENABLE,ON);
		}
		else if (MySwitches[i].SwitchConfig.Port==PORT_B)
		{
			RCC_SetPriephralStatus(GPIO_B_ENABLE,ON);
		}
		else if (MySwitches[i].SwitchConfig.Port==PORT_C)
		{
			RCC_SetPriephralStatus(GPIO_C_ENABLE,ON);
		}
		else if (MySwitches[i].SwitchConfig.Port==PORT_D)
		{
			RCC_SetPriephralStatus(GPIO_D_ENABLE,ON);
		}
		else if (MySwitches[i].SwitchConfig.Port==PORT_E)
		{
			RCC_SetPriephralStatus(GPIO_E_ENABLE,ON);
		}
		else if (MySwitches[i].SwitchConfig.Port==PORT_F)
		{
			RCC_SetPriephralStatus(GPIO_F_ENABLE,ON);
		}
		else if (MySwitches[i].SwitchConfig.Port==PORT_G)
		{
			RCC_SetPriephralStatus(GPIO_G_ENABLE,ON);
		}
		LocalError=GPIO_Config(&MySwitches[i].SwitchConfig);


	}
	return LocalError;
}
uint_8t Switch_GetSwitchState(uint_8t SwitchNum , uint_8t * state)
{
	uint_8t i=0;
	uint_8t LocalError=OK;
	if (state)
	{
		for (i=0;i<NUM_OF_SWITCH;i++)
		{
			if (MySwitches[i].SwitchNum==SwitchNum)
			{
				if (!SwitchStates[i]) //Not initialized
				{
					SwitchStates[i]=SWITCH_RELEASED;
				}
				*state=SwitchStates[i];
				break;
			}
		}
	}
	else
	{
		LocalError=NOT_OK;
	}
	return LocalError;
}


