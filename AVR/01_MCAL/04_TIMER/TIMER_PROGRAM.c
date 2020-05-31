#include "std_types.h"
#include "bits.h"
#include "TIMER_CONFIG.h"
#include "TIMER_INTERFACE.h"
#include "TIMER_REGISTERS.h"
#include "TIMER_CONFIG.h"
#include "TIMER_PRIVATE.h"

static void (*Timer0_pvCallBackPtr)(void)=NULL;
 
void Timer0_voidInit(void)
{
	/*Initialize interrupt to give an interrupt every 1 MSec*/
	/*Set waveform Generation mode to Normal mode*/
	
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);
	
	/*Enable timer0 overflow interrupt*/
	SET_BIT(TIMSK,TIMSK_TOIE0);
	
	/*preloadValue=131
	  TCNT0=131*/
	TCNT0=131;
	
	SET_BIT(TCCR0,TCCR0_CS00);
    SET_BIT(TCCR0,TCCR0_CS01);
    CLR_BIT(TCCR0,TCCR0_CS02);	
	  	
}


void Timer0_voidSetCallBack(void (*Copy_pvCallBackPtr)(void))
{
	if(Copy_pvCallBackPtr != NULL)
	{
		Timer0_pvCallBackPtr=Copy_pvCallBackPtr;
	}
	else
	{
		/*do nothing*/
	}
	
}

void __vector_11(void)
{
	
	if(Timer0_pvCallBackPtr !=NULL)
	{
		Timer0_pvCallBackPtr();
	}
}