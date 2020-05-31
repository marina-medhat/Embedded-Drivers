/*
 * Sched_config.c
 *
 *  Created on: Mar 10, 2020
 *      Author: MOSTAFA
 */

#include "Sched.h"
#include "Sched_config.h"
extern task_t SwitchTask;
extern task_t LCDTask;
extern task_t AppTask;


const TaskBaseInfo_t SysTask_info[MAX_TASKS]={
		{.AppTask=&SwitchTask,.FirstDelay=0},
		{.AppTask=&LCDTask,.FirstDelay=1},
		{.AppTask=&AppTask,.FirstDelay=100}
};
