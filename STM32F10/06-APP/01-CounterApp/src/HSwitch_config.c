/*
 * HSwitch_config.c
 *
 *  Created on: Mar 16, 2020
 *      Author: MOSTAFA
 */
#include "DGPIO.h"
#include "HSwitch.h"
#include "HSwitch_config.h"

Switch_t MySwitches [NUM_OF_SWITCH] ={
{.SwitchNum=COUNTER_SWITCH,.SwitchConfig.Port=PORT_B,.SwitchConfig.Pin=PIN_5,.SwitchConfig.Mode=MODE_PIN5_IP_PUR,.SwitchConfig.Speed=SPEED_PIN5_INPUT,.Mode=PULL_UP_SWITCH},
};

