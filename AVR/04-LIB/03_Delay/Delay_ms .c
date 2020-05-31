#include "STD_TYPES.h"
#include "Delay_ms.h"



/*for loop time t1=5.39875 us */
/*calculation time t2=627.875 us */
/*context switching into t3=3.995 us */
/*context switching out t4=2.255 us */


void Delay_ms(u32 value)
{
    u32 i;
	u32 count=(u32)((float)value-tm)/t1;
	
	for(i=0;i<count;i++)
	{
		asm("NOP");
	}
	
}