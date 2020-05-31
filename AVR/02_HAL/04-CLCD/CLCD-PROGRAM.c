/*****************************/
/*Author: Marina Medhat */
/*Version: V01 */
/*Date 14 Jan 2020m */
/*****************************/

#include "BIT_MATH.h"

#include "STD_TYPES.h"
#include "Delay_ms.h"


#include "PORT_INTERFACE.h"
#include "DIO_INTERFACE.h"
#include "CLCDINTERFACE.h"
#include "CLCD-CONFIG.h"
#include "CLCD_PRIVATE.h"


/*Description: This API shall initialize LCD*/
void CLCD_voidInitialize(void)
{   Delay_ms(40);
#if CLCD_u8_DATA_LENGTH==EIGHT_BITS_MODE
CLCD_voidWriteCmd(0b00111000);
#elif CLCD_u8_DATA_LENGTH==FOUR_BITS_MODE
/*Set RS =0*/
SetPinValue(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN,0);

/*Set RW =0*/
SetPinValue(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN,0);

/*Send 0010*/
CLCD_voidSetHalfDataPort(0b0010);
/*Send Enable Pulse*/
CLCD_vidSetEnablePulse();

/*Send 0010*/
CLCD_voidSetHalfDataPort(0b0010);
/*Send Enable Pulse*/
CLCD_vidSetEnablePulse();

/*Send 0010*/
CLCD_voidSetHalfDataPort(0b1000);
/*Send Enable Pulse*/
CLCD_vidSetEnablePulse();

#else #error "Wrong Data Length Choice"
#endif

CLCD_voidWriteCmd(0b00001100);
CLCD_voidWriteCmd(0b00000001);
Delay_ms(2);

}

/*Description: This API shall display data on LCD*/
void CLCD_voidWriteData(u8 copy_u8Data)
{


	/*Set RS =1*/
	SetPinValue(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN,1);


	/*Set RW =0*/
	SetPinValue(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN,0);

	/*Set Data On Data Port */
#if CLCD_u8_DATA_LENGTH == FOUR_BITS_MODE

	/* Set Higher Order 4bits of The command*/
	CLCD_voidSetHalfDataPort(copy_u8Data>>4);

	/*Set Enable pulse*/
	CLCD_vidSetEnablePulse();

	/* Set Higher Order 4bits of The command*/
	CLCD_voidSetHalfDataPort(copy_u8Data);

	/*Set Enable pulse*/
	CLCD_vidSetEnablePulse();


#elif CLCD_u8_DATA_LENGTH == EIGHT_BITS_MODE

	/*Set Data On Data Port */
	CLCD_voidSetDataPort(u8 copy_u8Data);

	/*Set Enable pulse*/
	CLCD_vidSetEnablePulse();

#else #error "Wrong Data Length Choice"

#endif



}

/*Description: This API shall execute command on LCD*/
void CLCD_voidWriteCmd(u8 copy_u8Cmd)
{
	/*Set RS =0*/
	SetPinValue(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN,0);

	/*Set RW =0*/
	SetPinValue(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN,0);

#if CLCD_u8_DATA_LENGTH == FOUR_BITS_MODE

	/* Set Higher Order 4bits of The command*/
	CLCD_voidSetHalfDataPort(copy_u8Cmd>>4);

	/*Set Enable pulse*/
	CLCD_vidSetEnablePulse();

	/* Set Higher Order 4bits of The command*/
	CLCD_voidSetHalfDataPort(copy_u8Cmd);

	/*Set Enable pulse*/
	CLCD_vidSetEnablePulse();


#elif CLCD_u8_DATA_LENGTH == EIGHT_BITS_MODE

	/*Set Data On Data Port */
	CLCD_voidSetDataPort(u8 copy_u8Cmd);

	/*Set Enable pulse*/
	CLCD_vidSetEnablePulse();

#else #error "Wrong Data Length Choice"

#endif

}



/*Description: This API shall change position to write or read on LCD*/
void CLCD_voidGoToXYPos(u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8DDRamAdd;
	if(Copy_u8XPos==CLCD_U8_LINE_ONE)
	{
		Local_u8DDRamAdd=Copy_u8XPos;
	}
	else if(Copy_u8XPos==CLCD_U8_LINE_TWO)
	{
		Local_u8DDRamAdd=Copy_u8XPos+CLCD_u8_LINE2_ADD_OFFSET;
	}
	else
	{
		/*Nth*/
	}
	CLCD_voidWriteCmd(Local_u8DDRamAdd|CLCD_u8_SET_DDRAM_ADD_CMD);
}

/*Description: This API shall write String on LCD*/
void CLCD_voidWriteString(const char* Copy_pchString)
{
	while(*Copy_pchString!='\0')
	{
		CLCD_voidWriteData(*Copy_pchString);
		Copy_pchString++;
	}

}

static void CLCD_voidSetHalfDataPort(u8 Copy_u8Data)
{

	u8 Local_u8BitVal;

	Local_u8BitVal=GET_BIT(Copy_u8Data,0);
	SetPinValue(CLCD_u8_D0_PORT,CLCD_u8_D4_PIN,Local_u8BitVal);

	Local_u8BitVal=GET_BIT(Copy_u8Data,1);
	SetPinValue(CLCD_u8_D1_PORT,CLCD_u8_D5_PIN,Local_u8BitVal);

	Local_u8BitVal=GET_BIT(Copy_u8Data,2);
	SetPinValue(CLCD_u8_D2_PORT,CLCD_u8_D6_PIN,Local_u8BitVal);

	Local_u8BitVal=GET_BIT(Copy_u8Data,3);
	SetPinValue(CLCD_u8_D3_PORT,CLCD_u8_D7_PIN,Local_u8BitVal);


}


static void CLCD_voidSetDataPort(u8 Copy_u8Data)
{

	u8 Local_u8BitVal;

	/*Set Data On Data Port */
	Local_u8BitVal=GET_BIT(Copy_u8Data,0);
	SetPinValue(CLCD_u8_D0_PORT,CLCD_u8_D0_PIN,Local_u8BitVal);

	Local_u8BitVal=GET_BIT(Copy_u8Data,1);
	SetPinValue(CLCD_u8_D1_PORT,CLCD_u8_D1_PIN,Local_u8BitVal);

	Local_u8BitVal=GET_BIT(Copy_u8Data,2);
	SetPinValue(CLCD_u8_D2_PORT,CLCD_u8_D2_PIN,Local_u8BitVal);

	Local_u8BitVal=GET_BIT(Copy_u8Data,3);
	SetPinValue(CLCD_u8_D3_PORT,CLCD_u8_D3_PIN,Local_u8BitVal);

	Local_u8BitVal=GET_BIT(Copy_u8Data,4);
	SetPinValue(CLCD_u8_D4_PORT,CLCD_u8_D4_PIN,Local_u8BitVal);

	Local_u8BitVal=GET_BIT(Copy_u8Data,5);
	SetPinValue(CLCD_u8_D5_PORT,CLCD_u8_D5_PIN,Local_u8BitVal);

	Local_u8BitVal=GET_BIT(Copy_u8Data,6);
	SetPinValue(CLCD_u8_D6_PORT,CLCD_u8_D6_PIN,Local_u8BitVal);

	Local_u8BitVal=GET_BIT(Copy_u8Data,7);
	SetPinValue(CLCD_u8_D7_PORT,CLCD_u8_D7_PIN,Local_u8BitVal);


}


static void CLCD_vidSetEnablePulse(void)
{
	SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,1);
	Delay_ms(1);
	SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,0);
	Delay_ms(1);

}
