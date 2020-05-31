#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include "DIO_REGISTER.h"
#include "DIO_PRIVATE.h"
#include "DIO_CONFIG.h"

extern void DIO_SetPinMode(u8 port , u8 pin , u8 mode)
{
	switch(port)
	{
		case 'A':
				if(pin<=7)
				{
					/*clear 4 bits */
				  PORTA_CRL&=~(0b1111<<(pin*4)); // el pin be 4 bits w ana 3aiza asafr abl ma a7ot bel or 3lshan y7oteli el ana 3aizah
                    /*set mode in 4 bits*/				  
				  PORTA_CRL|=mode << (pin*4);	
				}
				else if(pin<=15)
				{
				  pin=pin-8;	
					/*clear 4 bits */
				  PORTA_CRH&=~(0b1111<<(pin*4)); // el pin be 4 bits w ana 3aiza asafr abl ma a7ot bel or 3lshan y7oteli el ana 3aizah
                    /*set mode in 4 bits*/				  
				  PORTA_CRH|=mode << (pin*4);	
				}
				break;
		case 'B':
		       if(pin<=7)
				{
					/*clear 4 bits */
				  PORTB_CRL&=~(0b1111<<(pin*4)); // el pin be 4 bits w ana 3aiza asafr abl ma a7ot bel or 3lshan y7oteli el ana 3aizah
                    /*set mode in 4 bits*/				  
				  PORTB_CRL|=mode << (pin*4);	
				}
				else if(pin<=15)
				{
				  pin=pin-8;	
					/*clear 4 bits */
				  PORTB_CRH&=~(0b1111<<(pin*4)); // el pin be 4 bits w ana 3aiza asafr abl ma a7ot bel or 3lshan y7oteli el ana 3aizah
                    /*set mode in 4 bits*/				  
				  PORTB_CRH|=mode << (pin*4);	
				}
				break;
		case 'C':
		     
				if((pin>=13)&&(pin<=15))
				{
				  pin=pin-8;	
					/*clear 4 bits */
				  PORTC_CRH&=~(0b1111<<(pin*4)); // el pin be 4 bits w ana 3aiza asafr abl ma a7ot bel or 3lshan y7oteli el ana 3aizah
                    /*set mode in 4 bits*/				  
				  PORTC_CRH|=mode << (pin*4);	
				}
				break;
	}
	
}
extern void DIO_SetPinVal(u8 port , u8 pin , u8 val)
{
	switch(port)
	{
		case 'A':
		    if(val ==1)
			{
			  SET_BIT(PORTA_ODR,pin);	
			}
			else
			{
			  CLR_BIT(PORTA_ODR,pin);			
			}
			break;
			
		case 'B':
		    if(val ==1)
			{
			  SET_BIT(PORTB_ODR,pin);	
			}
			else
			{
			  CLR_BIT(PORTB_ODR,pin);			
			}
			break;
		case 'C':
		    if(val ==1)
			{
			  SET_BIT(PORTC_ODR,pin);	
			}
			else
			{
			  CLR_BIT(PORTC_ODR,pin);			
			}
			break;
		
	}
}

extern u8 DIO_GetPinVal(u8 port , u8 pin )
{
	u8 result;
	  switch(port)
	  {
		  case 'A': result=GET_BIT(PORTA_IDR,pin); break;
		  case 'B': result=GET_BIT(PORTB_IDR,pin); break;
		  case 'C': result=GET_BIT(PORTC_IDR,pin); break;  
	  }
	  return result;
}



