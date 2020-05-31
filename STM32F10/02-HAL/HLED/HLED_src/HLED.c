#include "DGPIO.h"
#include "HLED.h"
#include "HLED_config.h"

extern HLED_map LED[LED_NUM];
extern GPIO_t LED_Init[LED_NUM];

uint_8t HLED_Init(void)
{
	uint_8t Local_Error=OK;
	uint_8t CountLed;
	for(CountLed=0;CountLed<LED_NUM;CountLed++)
	{
		Local_Error=DGPIO_Config(&LED_Init[CountLed]);
	}
	return Local_Error;
}



uint_8t HLED_SetLedState(uint_8t Led_Number,uint_8t Led_State)
{
	uint_8t Local_Error=OK;
	switch(Led_State)
	{
		case SET:
		Local_Error=DGPIO_Write(LED[Led_Number].Led_Port, LED[Led_Number].Led_Pin , LED[Led_Number].Led_ON);
		break;
		
		case CLEAR:
		Local_Error=DGPIO_Write(LED[Led_Number].Led_Port, LED[Led_Number].Led_Pin , (LED[Led_Number].Led_ON ^ 0x1));
		break;			
	}
	return Local_Error;
	
}
