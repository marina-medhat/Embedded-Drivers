/*
 * LIN_cfg.c
 *
 *  Created on: May 8, 2020
 *      Author: Marina
 */

#include "LIN.h"
#include "LIN_cfg.h"

#if NODE_STATE == MASTER_NODE
LIN_Mastercfg_t master_LDF[MAX_MSGS_NUM]={
		{.ID=1 , .ExecTime=30},
        {.ID=2 , .ExecTime=5},
		{.ID=3 , .ExecTime=15}
};
#endif

LIN_Slavecfg_t slave_Msgs[NUMBER_OF_MSGS]={
		{.ID=1 ,.msgState = OWNER, .dataSize=3 },
		{.ID=1 ,.msgState = LISTENER, .dataSize=3 }
};

