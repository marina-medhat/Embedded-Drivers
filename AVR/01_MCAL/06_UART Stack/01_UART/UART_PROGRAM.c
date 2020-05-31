/**************************************************************************/
/*Author  :Marina Medhat                                                 */
/*Date    :9 March 2010                                                   */
/*Version :V01                                                            */
/**************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_CONFIG.h"
#include "UART_INTERFACE.h"
#include "UART_REGISTERS.h"
#include "UART_CONFIG.h"
#include "UART_PRIVATE.h"


/*LOOK UP Table */
const u8 BaudRateValue[3][3]=
{
	/* 4800  , 9600  , 115200  */
	{  0x67  , 0x33  , 0x03         },   /*Clock System 0 = 8MHZ*/
	{  154   , 77    , 6            },   /*Clock System 1 = 12MHZ*/
    {  0xCF  , 0x67  , 0x08         }	 /*Clock System 2 = 16MHZ*/
};

void (*EndOfTransmitCB)(void);             
void (*EndOfRecieveCB)(u8);

void UART_voidInit(void)
{
	/*Assign Baud Rate*/
	//UBRRL = BaudRateValue[UART_u8_SYS_FREQ][UART_u8_BAUD_RATE];
	UBRRL = 51;
	/*U2X = 0*/
	CLR_BIT(UCSRA,1);
	
	/*disabled all UART interrupt*/
	/*enabled Tx,Rx */
	/*Character size 8 bits */
	UCSRB = 0x18;
	
    /*Asynch Mode*/
	/*Character size 8 bits */
	UCSRC =( (1<<7) | (UART_u8_PARITY << 4) | (UART_u8_STOP_BITS << 3) | (3 << 1) );
	
	
	
	
	
}


u8 UART_voidTransmitDataSynch(u8 Copy_u8Data)
{
	u32 Local_u32Timeout = 0;
	u8 Local_u8Error = STD_OK;
	
	/*Send data on UDR*/
	UDR_T = Copy_u8Data;
	
	/*wait till flag is raised*/
	while(  (GET_BIT(UCSRA,7) == 0)  &&(Local_u32Timeout<UART_u32_TIME_OUT_TH) )
	{
		Local_u32Timeout++;
	}
	
	/*Time Out Happend*/
	if(Local_u32Timeout >= UART_u32_TIME_OUT_TH)
	{
		Local_u8Error=STD_ERROR;
	}
	else
	{
		/*Clear Flag*/
		SET_BIT(UCSRA,6);
	}
	
	return Local_u8Error;
}


void UART_voidTransmitDataASynch(u8 Copy_u8Data, void (*Copy_ptr)(void))
{
	
	/*Enable Interrupt*/
	SET_BIT(UCSRB,6);
	/*Set Recieved data to UDR*/
	UDR_T=Copy_u8Data;
	
	/*saved call back address*/
	EndOfTransmitCB=Copy_ptr;
}


u8   UART_voidReceiveDataSynch(u8 * Copy_pu8Data)
{
	u32 Local_u32Timeout = 0;
	u8 Local_u8Error = STD_OK;
	
	
	/*wait till flag is raised*/
	while(  (GET_BIT(UCSRA,7) == 0)  &&(Local_u32Timeout<UART_u32_TIME_OUT_TH) )
	{
		Local_u32Timeout++;
	}
	
	/*Time Out Happend*/
	if(Local_u32Timeout >= UART_u32_TIME_OUT_TH)
	{
		Local_u8Error=STD_ERROR;
	}
	else
	{
		/*Set data to recieved pointer*/
		/*msh m7taga a3ml clear lel flag hwa hayt clear wa7do*/
		*Copy_pu8Data=UDR_R;
	}
	
	return Local_u8Error;

	
}

void UART_voidReceiveDataASynch(void (*Copy_ptr)(u8))
{
	/*ya tla2y el flag marfo3 ya tla2eh msh marfo3*/
	/*Check if there is data to recieve*/
	if( (GET_BIT(UCSRA,7) == 1))

	{
		Copy_ptr(UDR_R);
	}
	
	/**/
	else
	{
	/*Enable Rx Interrupt*/
	SET_BIT(UCSRB,7);
	
	/*save call back in global variable*/
	EndOfRecieveCB = Copy_ptr;
		
	}
} 
