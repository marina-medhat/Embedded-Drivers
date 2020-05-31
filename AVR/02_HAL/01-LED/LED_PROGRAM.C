#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include "LED_INTERFACE.h"
#include "LED_PRIVATE.h"
#include "LED_CONFIG.h"

void SetLedOn (void)
{
	SetPinValue(LED_Port,LED_Pin,LED_Mode);
	
	
}


void SetLedOff (void)
{
	
	SetPinValue(LED_Port,LED_Pin,LED_Mode^0X01);
	
}