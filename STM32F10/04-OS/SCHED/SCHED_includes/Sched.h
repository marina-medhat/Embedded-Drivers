/*
 * Sched.h
 *
 *  Created on: Mar 10, 2020
 *      Author: Marina
 */

#ifndef SCHED_H_
#define SCHED_H_

/*************************************
 *******POINTER_TO_TASK_RUNNABLE******
 *************************************/
typedef void (* Runnable_t)(void);

/********************************************
 ***********TASK_STRUCT**********************
 *********** Runnable   : Task's runnable****
 *********** periodicity: Task's periodicity*
 ********************************************/
typedef struct {
	Runnable_t Runnable;
	uint_32t periodicity;
}task_t;

/****************************************************************************************************
 * Function name: Sched_Init                                                                        *
 *                                                                                                  *
 * parameters:  Input:  NA                                                                          *
 *                                                                                                  *
 *              Output: NA                                                                          *
 *              In/out: NA                                                                          *
 * return: E_OK, E_NOK                                                                              *
 * Description: a function that initializes the scheduler                                           *
 ****************************************************************************************************/
uint_8t Sched_Init(void);

/****************************************************************************************************
 * Function name: Sched_Start                                                                       *
 *                                                                                                  *
 * parameters:  Input:  NA                                                                          *
 *                                                                                                  *
 *              Output: NA                                                                          *
 *              In/out: NA                                                                          *
 * return: E_OK, E_NOK                                                                              *
 * Description: a function that starts the scheduler                                                *
 ****************************************************************************************************/
uint_8t Sched_Start(void);

/****************************************************************************************************
 * Function name: Sched_Suspend                                                                     *
 *                                                                                                  *
 * parameters:  Input:  NA                                                                          *
 *                                                                                                  *
 *              Output: NA                                                                          *
 *              In/out: NA                                                                          *
 * return: E_OK, E_NOK                                                                              *
 * Description: a function that suspends a task                                                     *
 ****************************************************************************************************/
void Sched_Suspend(void);



#endif /* SCHED_H_ */
