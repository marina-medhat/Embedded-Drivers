#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include "DAC_INTERFACE.h"
#include "DAC_PRIVATE.h"
#include "DAC_CONFIG.h"


void Dac_VoidSetAnalogVolt(u16 copy_u16AnalogMv)
{
	u8 Local_u8DigitalValue, Local_u8BitValue;
	//el result hatt cast lwa7deha  le u8 
	Local_u8DigitalValue=((u32)copy_u16AnalogMv*255UL)/DAC_u16_REFERENCE_VOLTAGE;
	
	
	Local_u8BitValue=GET_BIT(Local_u8DigitalValue,7);
	DIO_voidSetPinValue(DAC_u8_BIT7_PORT,DAC_u8_BIT7_PIN ,Local_u8BitValue);
	
	Local_u8BitValue=GET_BIT(Local_u8DigitalValue,6);
	DIO_voidSetPinValue(DAC_u8_BIT6_PORT,DAC_u8_BIT6_PIN ,Local_u8BitValue);

    Local_u8BitValue=GET_BIT(Local_u8DigitalValue,5);
	DIO_voidSetPinValue(DAC_u8_BIT5_PORT,DAC_u8_BIT5_PIN ,Local_u8BitValue);


    Local_u8BitValue=GET_BIT(Local_u8DigitalValue,4);
	DIO_voidSetPinValue(DAC_u8_BIT4_PORT,DAC_u8_BIT4_PIN ,Local_u8BitValue);


    Local_u8BitValue=GET_BIT(Local_u8DigitalValue,3);
	DIO_voidSetPinValue(DAC_u8_BIT3_PORT,DAC_u8_BIT3_PIN ,Local_u8BitValue);


    Local_u8BitValue=GET_BIT(Local_u8DigitalValue,2);
	DIO_voidSetPinValue(DAC_u8_BIT2_PORT,DAC_u8_BIT2_PIN ,Local_u8BitValue);


    Local_u8BitValue=GET_BIT(Local_u8DigitalValue,1);
	DIO_voidSetPinValue(DAC_u8_BIT1_PORT,DAC_u8_BIT1_PIN ,Local_u8BitValue);


    Local_u8BitValue=GET_BIT(Local_u8DigitalValue,0);
	DIO_voidSetPinValue(DAC_u8_BIT0_PORT,DAC_u8_BIT0_PIN ,Local_u8BitValue);

	
}