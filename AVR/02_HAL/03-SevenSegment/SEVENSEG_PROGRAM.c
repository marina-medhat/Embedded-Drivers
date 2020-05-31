#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include "SWITCH_INTERFACE.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include "SEVENSEG_INTERFACE.h"
#include "SEVENSEG_PRIVATE.h"
#include "SEVENSEG_CONFIG.h"


u8 SEVENSEG_ENABLE_Ports [SEVENSEGMENTS_NUMBER]=SEVENSEGMENTS_PORTS;
u8 SEVENSEG_ENABLE_Pins [SEVENSEGMENTS_NUMBER]=SEVENSEGMENTS_PINS;


void SEVENSEG_SetNumber(u8 number)
{
	u8 result;
	switch(number)
	{
		case 0:
		result=Zero;
		 break;
		 
		case 1:
		result=One;
		 break;
		 
		case 2:
		result=Two;
		 break;
		 
		case 3:
		result=Three;
		 break;
		 
		case 4:
		result=Four;
		 break;
		 
		case 5:
		result=Five;
		 break;
		 
		case 6:
		result=Six;
		 break;
		 
		case 7:
		result=Seven;
		 break;
		 
		case 8:
		result=Eight;
		 break;
		 
		case 9:
		result=Nine;
		 break;
		 
		 
		
	}
	if(SEVENSEG_Mode==1)
	{		
	SetPinValue(SEVENSEG_PinA_PORT,SEVENSEG_PinA_Number,GET_BIT(result,0));
	SetPinValue(SEVENSEG_PinB_PORT,SEVENSEG_PinB_Number,GET_BIT(result,1));
	SetPinValue(SEVENSEG_PinC_PORT,SEVENSEG_PinC_Number,GET_BIT(result,2));
	SetPinValue(SEVENSEG_PinD_PORT,SEVENSEG_PinD_Number,GET_BIT(result,3));
	SetPinValue(SEVENSEG_PinE_PORT,SEVENSEG_PinE_Number,GET_BIT(result,4));
	SetPinValue(SEVENSEG_PinF_PORT,SEVENSEG_PinF_Number,GET_BIT(result,5));
	SetPinValue(SEVENSEG_PinG_PORT,SEVENSEG_PinG_Number,GET_BIT(result,6));
	SetPinValue(SEVENSEG_PinH_PORT,SEVENSEG_PinH_Number,GET_BIT(result,7));
	}
	else
	{
		result=~result;
	SetPinValue(SEVENSEG_PinA_PORT,SEVENSEG_PinA_Number,GET_BIT(result,0));
	SetPinValue(SEVENSEG_PinB_PORT,SEVENSEG_PinB_Number,GET_BIT(result,1));
	SetPinValue(SEVENSEG_PinC_PORT,SEVENSEG_PinC_Number,GET_BIT(result,2));
	SetPinValue(SEVENSEG_PinD_PORT,SEVENSEG_PinD_Number,GET_BIT(result,3));
	SetPinValue(SEVENSEG_PinE_PORT,SEVENSEG_PinE_Number,GET_BIT(result,4));
	SetPinValue(SEVENSEG_PinF_PORT,SEVENSEG_PinF_Number,GET_BIT(result,5));
	SetPinValue(SEVENSEG_PinG_PORT,SEVENSEG_PinG_Number,GET_BIT(result,6));
	SetPinValue(SEVENSEG_PinH_PORT,SEVENSEG_PinH_Number,GET_BIT(result,7));

		
		
	}
	
}


void SEVENSEG_Enable(u8 sevSegNum)
{
	//msh haynf3 asta5dm #if 3lshan bydeni sevsegnum fel runtime
	
	SetPinValue(SEVENSEG_ENABLE_Ports[sevSegNum],SEVENSEG_ENABLE_Pins[sevSegNum],SEVENSEG_Mode);
	
	/*SetPinValue(SEVENSEG_PinA_PORT,SEVENSEG_PinA_Number,GET_BIT(SEVENSEG_InitialVal,0));
	SetPinValue(SEVENSEG_PinB_PORT,SEVENSEG_PinB_Number,GET_BIT(SEVENSEG_InitialVal,1));
	SetPinValue(SEVENSEG_PinC_PORT,SEVENSEG_PinC_Number,GET_BIT(SEVENSEG_InitialVal,2));
	SetPinValue(SEVENSEG_PinD_PORT,SEVENSEG_PinD_Number,GET_BIT(SEVENSEG_InitialVal,3));
	SetPinValue(SEVENSEG_PinE_PORT,SEVENSEG_PinE_Number,GET_BIT(SEVENSEG_InitialVal,4));
	SetPinValue(SEVENSEG_PinF_PORT,SEVENSEG_PinF_Number,GET_BIT(SEVENSEG_InitialVal,5));
	SetPinValue(SEVENSEG_PinG_PORT,SEVENSEG_PinG_Number,GET_BIT(SEVENSEG_InitialVal,6));
	SetPinValue(SEVENSEG_PinH_PORT,SEVENSEG_PinH_Number,GET_BIT(SEVENSEG_InitialVal,7));*/
	
}

void SEVENSEG_Didable(u8 sevSegNum )
{
	SetPinValue(SEVENSEG_ENABLE_Ports[sevSegNum],SEVENSEG_ENABLE_Pins[sevSegNum],SEVENSEG_Mode ^ 0x01);
	
}
