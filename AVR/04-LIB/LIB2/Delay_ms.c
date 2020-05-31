#include "std_types.h"
#include "Delay_ms.h"

void Delay_ms(u32 Value)
{
	u32 i;
	u32 count=(u32)(float)(Value-tm)/t1;
	
	for(i=0;i<count;i++)
	{
		
		asm("NOP");
		
	}
	
}