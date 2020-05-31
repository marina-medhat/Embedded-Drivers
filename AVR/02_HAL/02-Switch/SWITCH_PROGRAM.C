#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include "SWITCH_INTERFACE.h"
#include "SWITCH_PRIVATE.h"
#include "SWITCH_CONFIG.h"

u8 GetVal (void)
{
	u8 result;
	result=GetPinValue(SWITCH_Port,SWITCH_Pin);
	
	#if RELEASE_STATE==0
		return result;
	#else
		return result^0x01;
	#endif
	
	
	
	
}


