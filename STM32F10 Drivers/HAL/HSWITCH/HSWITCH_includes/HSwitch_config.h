/*
 * HSwitch_config.h
 *
 *  Created on: Mar 16, 2020
 *      Author: Mohanad
 */

#ifndef HSWITCH_CONFIG_H_
#define HSWITCH_CONFIG_H_

#define NUM_OF_SWITCH 5

#define PULL_UP_SWITCH 0xdd
#define PULL_DOWN_SWITCH 0xee

typedef struct
{
	uint_8t SwitchNum;
	GPIO_t SwitchConfig;
	uint_8t Mode;

}Switch_t;

#endif
