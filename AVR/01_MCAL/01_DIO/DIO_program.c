#include "std_types.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "DIO_register.h"
#include "DIO_private.h"

ErrorStatus DIO_SetPinDirection(u8 Port,u8 Pin, u8 Direction)
{
	switch(Port)
	{
	case PORT_A:
		if(Direction==INPUT)
		{
			DDRA &= ~(1<<Pin);
		}
		else if(Direction==OUTPUT)
		{
			DDRA|= (1<<Pin);
		}
		else
		{
			return ERROR_NOK;
		}
		break;

	case PORT_B:
		if(Direction==INPUT)
		{
			DDRB &= ~(1<<Pin);

		}
		else if(Direction==OUTPUT)
		{
			DDRB|= (1<<Pin);
		}
		else
		{
			return ERROR_NOK;
		}
		break;

	case PORT_C:
		if(Direction==INPUT)
		{
			DDRC &=  ~(1<<Pin);
		}
		else if(Direction==OUTPUT)
		{
			DDRC|= (1<<Pin);
		}
		else
		{
			return ERROR_NOK;
		}
		break;

	case PORT_D:
		if(Direction==INPUT)
		{
			DDRD &= ~(1<<Pin);
		}
		else if(Direction==OUTPUT)
		{
			DDRD|= (1<<Pin);
		}
		else
		{
			return ERROR_NOK;
		}
		break;

	default: return ERROR_NOK;
	}
	return ERROR_OK;
}


ErrorStatus DIO_SetPinValue(u8 Port,u8 Pin, u8 Value)
{
	switch(Port)
	{
	case PORT_A:
		if(Value==LOW)
		{
			PORTA &= ~(1<<Pin);

		}
		else if(Value==HIGH)
		{
			PORTA|= (1<<Pin);
		}
		else
		{
			return ERROR_NOK;
		}
		break;

	case PORT_B:
		if(Value==LOW)
		{
			PORTB &= ~(1<<Pin);

		}
		else if(Value==HIGH)
		{
			PORTB|= (1<<Pin);
		}
		else
		{
			return ERROR_NOK;
		}
		break;

	case PORT_C:
		if(Value==LOW)
		{
			PORTC &= ~(1<<Pin);

		}
		else if(Value==HIGH)
		{
			PORTC|= (1<<Pin);
		}
		else
		{
			return ERROR_NOK;
		}
		break;

	case PORT_D:
		if(Value==LOW)
		{
			PORTD &= ~(1<<Pin);

		}
		else if(Value==HIGH)
		{
			PORTD|= (1<<Pin);
		}
		else
		{
			return ERROR_NOK;
		}
		break;

	default: return ERROR_NOK;
	}
	return ERROR_OK;
}

ErrorStatus DIO_SetPortDirecton(u8 Port,u8 Value)
{
	switch(Port)
	{
	case PORT_A:
		DDRA=Value;
		break;
	case PORT_B:
		DDRB=Value;
		break;
	case PORT_C:
		DDRC=Value;
		break;
	case PORT_D:
		DDRD=Value;
		break;
	default: return ERROR_NOK;
	}
	return ERROR_OK;
}

ErrorStatus DIO_SetPortValue(u8 Port,u8 Value)
{
	switch(Port)
	{
	case PORT_A:
		PORTA=Value;
		break;
	case PORT_B:
		PORTB=Value;
		break;
	case PORT_C:
		PORTC=Value;
		break;
	case PORT_D:
		PORTD=Value;
		break;
	default: return ERROR_NOK;
	}
	return ERROR_OK;
}


ErrorStatus DIO_GetPinValue(u8 Port,u8 Pin,u8 *Value)
{
	switch(Port)
	{
	case PORT_A:
		*Value= (( (PINA) & (1<< Pin)) >> (Pin));
		break;
	case PORT_B:
		*Value= (( (PINB) & (1<< Pin)) >> (Pin));
		break;
	case PORT_C:
		*Value= (( (PINC) & (1<< Pin)) >> (Pin));
		break;
	case PORT_D:
		*Value= (( (PIND) & (1<< Pin)) >> (Pin));
		break;
	default: return ERROR_NOK;
	}
	return ERROR_OK;
}

ErrorStatus DIO_GetPortValue(u8 Port,u8 *Value)
{
	switch(Port)
	{
	case PORT_A:
		*Value=PINA;
		break;
	case PORT_B:
		*Value=PINB;
		break;
	case PORT_C:
		*Value=PINC;
		break;
	case PORT_D:
		*Value=PIND;
		break;
	default: return ERROR_NOK;
	}
	return ERROR_OK;
}
