#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include "KEYPAD_INTERFACE.h"
#include "KEYPAD_PRIVATE.h"
#include "KEYPAD_CONFIG.h"

u8 KEYPAD_GetPressKey(void)
{
	
	u8 Keypad_RowsPortArr[KEYPAD_ROWS_NUM]=Keypad_ROWS_PORTS;
	u8 Keypad_ColsPortArr[KEYPAD_COLS_NUM]=Keypad_COLS_PORTS;
	
	u8 Keypad_RowsPinArr[KEYPAD_ROWS_NUM]=Keypad_ROWS_PINS;
	u8 Keypad_ColsPinArr[KEYPAD_COLS_NUM]=Keypad_COLS_PINS;
	
	u8 KeyPad_Keys[KEYPAD_ROWS_NUM][KEYPAD_COLS_NUM]=KeyPadKeys;
	
	u8 RowsIdx,ColIdx;
	u8 PinState, PressedKey;
	PressedKey=Keypad_default;
	
	for(RowsIdx=0;RowsIdx<KEYPAD_ROWS_NUM;RowsIdx++)
	{
		/*Activate Current Row*/
		SetPinValue(Keypad_RowsPortArr[RowsIdx],Keypad_RowsPinArr[RowsIdx],0);
		
		
		/*check columns if pressed */
		for(ColIdx=0;ColIdx<KEYPAD_COLS_NUM;ColIdx++)
		{
			PinState=GetPinValue(Keypad_ColsPortArr[ColIdx],Keypad_ColsPinArr[ColIdx]);
			/*check if the key is pressed*/
			if(PinState==0)
			{
			 	PressedKey=KeyPad_Keys[RowsIdx][ColIdx];
				while(!PinState)
				{
					PinState=GetPinValue(Keypad_ColsPortArr[ColIdx],Keypad_ColsPinArr[ColIdx]);
				}
				return PressedKey;
			}
			
		}
		
		SetPinValue(Keypad_RowsPortArr[RowsIdx],Keypad_RowsPinArr[RowsIdx],1);
	}
	return PressedKey;
	
	
}