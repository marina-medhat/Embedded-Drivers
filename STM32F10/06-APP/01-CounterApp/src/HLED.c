#include "DGPIO.h"
#include "HLED.h"
#include "HLED_config.h"

extern HLED_map LED[LED_NUM];
extern GPIO_t LED_Init[LED_NUM];

uint_8t HLED_Init(void)
{
	uint_8t LocalError=OK;
	uint_8t CountLed;
	for(CountLed=0;CountLed<LED_NUM;CountLed++)
	{
		LocalError|=GPIO_Config(&LED_Init[CountLed]);
	}
	return LocalError;
}



uint_8t HLED_SetLedState(uint_8t Led_Number,uint_8t Led_State)
{
	uint_8t LocalError=OK;
	switch(Led_State)
	{
		case SET:
			LocalError= GPIO_Writee(LED[Led_Number].Led_Port, LED[Led_Number].Led_Pin , LED[Led_Number].Led_ON);
		break;
		
		case CLEAR:
			LocalError=GPIO_Writee(LED[Led_Number].Led_Port, LED[Led_Number].Led_Pin , (LED[Led_Number].Led_ON ^ 0x1));
		break;			
	}
	return LocalError;
}
