#include "STD_TYPES.h"
#include "Delay_ms.h"
#include "MAP.h"


s32 Map_Ranges(s32 InputValue , s32 Range1Min,s32 Range1Max ,s32 Range2Min,s32 Range2Max )
{
	s32 OutputValue;
	
	OutputValue=(((InputValue-Range1Min)*(Range2Max-Range2Min))/(Range1Max-Range1Min))+Range2Min;
	
	return OutputValue;
	
	
}