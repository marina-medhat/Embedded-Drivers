/*
 * Sched_config.c
 *
 *  Created on: Mar 10, 2020
 *      Author: Marina
 */

#include "Sched.h"
#include "Sched_config.h"

extern task_t LCDTask;
/*extern task_t mainTask;*/
extern task_t SwitchTask;
extern task_t LIN_Task;


const TaskBaseInfo_t SysTask_info[MAX_TASKS]={
		/*{.AppTask=&SwitchTask,.FirstDelay=0},
		{.AppTask=&mainTask,.FirstDelay=0},
		{.AppTask=&LCDTask,.FirstDelay=0}*/
		{.AppTask=&LIN_Task,.FirstDelay=0},
};
