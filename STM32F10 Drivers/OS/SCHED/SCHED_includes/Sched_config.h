/*
 * Sched_config.h
 *
 *  Created on: Mar 10, 2020
 *      Author: Marina
 */

#ifndef SCHED_CONFIG_H_
#define SCHED_CONFIG_H_

/*************************************
 **********SCHEDULER_TICK_TIME********
 *************************************/
#define SCHED_TICK_mSEC 1

/*************************************
 *******SCHEDULER_TASKS_NUMBER********
 *************************************/
#define MAX_TASKS 1

/********************************************
 ********TASK_BASEINFO_STRUCT****************
 *********** AppTask   : Task's runnable*****
 *********** FirstDelay: Task's First Delay**
 ********************************************/
typedef struct
{
	task_t * AppTask;
	uint_32t FirstDelay;
}TaskBaseInfo_t;


#endif /* SCHED_CONFIG_H_ */
