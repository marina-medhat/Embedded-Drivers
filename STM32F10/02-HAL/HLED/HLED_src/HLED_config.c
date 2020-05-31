#include "DGPIO.h"
#include "HLED_config.h"
#include "HLED.h"


const HLED_map LED[LED_NUM] = {
	
	{COUNTER_LED,PORT_C,PIN_13,ACTIVE_LOW}
};


const GPIO_t LED_Init[LED_NUM] = {

		{PIN_13,MODE_PIN13_OP_PP,SPEED_PIN13_10MHZ,PORT_C},
};
