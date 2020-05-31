#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"

void main(void)
{
	
	u8 switchState;
	
	SetPinDir('A',0,0);
	SetPinDir('A',1,1);
	
	switchState=GetPinValue('A',0);
	//sh8alyen pull up
	while(1)
	{
	if(switchState == 1)
	{
		SetPinValue('A',1,0);
		
		
	}
	else{
		SetPinValue('A',1,1);
		
	}
	
	}
	
}
