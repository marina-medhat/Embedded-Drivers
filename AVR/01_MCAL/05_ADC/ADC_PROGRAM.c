#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_CONFIG.h"
#include "ADC_INTERFACE.h"
#include "ADC_REGISTERS.h"
#include "ADC_CONFIG.h"
#include "ADC_PRIVATE.h"

void ADC_voidInit(void)
{
	/* 8 bits mode , a vcc ref voltage, polling(not interrupt) */
	
	/*avcc reference voltage*/
	CLR_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);
	
	/*activate left adjust mode */
	SET_BIT(ADMUX,5);
	
	/*ADC enable*/
	SET_BIT(ADCSRA,7);
	
	/*prescaller division by 128*/
	SET_BIT(ADCSRA,2);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,0);
}


u8 ADC_u8GetChannelReading(u8 Channel)
{
	/*awl 7aga an ana a5od el value of channel de w a7otaha fe 5 bits bto3 ADMUX*/
    ADMUX&=0b11100000;
    ADMUX|=Channel;

    /*Start Conversion*/
    SET_BIT(ADCSRA,6);

    /*polling on the conversion complete flag*/

   while((GET_BIT(ADCSRA,4))==0);

   /*CLEAR THE FLAG*/
   SET_BIT(ADCSRA,4);

   /*get the result*/

   return ADCH;


}
