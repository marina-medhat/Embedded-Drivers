/*
 * SPI_program.c
 *
 *  Created on: Apr 20, 2020
 *      Author: Marina
 */

#include "std_types.h"
#include "bits.h"

#include "SPI_register.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_interface.h"


static u8 SPI_BusyFlag;

static u8 *SPI_TxBuffer = NULL;
static u8 *SPI_RxBuffer = NULL;
static u8 SPI_BufferSize;
static u8 SPI_BufferIdx;
static void(*SPI_NotificationFn)(void);


void SPI_voidInit(void)
{
	/*
	 1- Data order
	 2- Master/Slave
	 3- Clock Polarity
	 4- Clock phase
	 5- Enable SPI
	 */

#if	SPI_INT_STATE == SPI_INT_DISABLE
	CLR_BIT(SPCR,SPCR_SPIE);
#elif SPI_INT_STATE == SPI_INT_ENABLE
	SET_BIT(SPCR,SPCR_SPIE);
#endif

#if	SPI_SELECT_MODE	== SPI_MASTER
	SET_BIT(SPCR,SPCR_MSTR);

#if SPI_CLK_RATE == SPI_CLK_DIV_4
	CLR_BIT(SPSR,SPSR_SPI2X);
	CLR_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
#elif SPI_CLK_RATE == SPI_CLK_DIV_16
	CLR_BIT(SPSR,SPSR_SPI2X);
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
#elif SPI_CLK_RATE == SPI_CLK_DIV_64
	CLR_BIT(SPSR,SPSR_SPI2X);
	CLR_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPCR,SPCR_SPR1);
#elif SPI_CLK_RATE == SPI_CLK_DIV_128
	CLR_BIT(SPSR,SPSR_SPI2X);
	SET_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPCR,SPCR_SPR1);
#elif SPI_CLK_RATE == SPI_HCLK_DIV_2
	SET_BIT(SPSR,SPSR_SPI2X);
	CLR_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
#elif SPI_CLK_RATE == SPI_HCLK_DIV_8
	SET_BIT(SPSR,SPSR_SPI2X);
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
#elif SPI_CLK_RATE == SPI_HCLK_DIV_32
	SET_BIT(SPSR,SPSR_SPI2X);
	CLR_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPCR,SPCR_SPR1);
#elif SPI_CLK_RATE == SPI_hCLK_DIV_64
	SET_BIT(SPSR,SPSR_SPI2X);
	SET_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPCR,SPCR_SPR1);
#endif

#elif SPI_SELECT_MODE == SPI_SLAVE
	CLR_BIT(SPCR,SPCR_MSTR);
#endif

#if SPI_DATA_ORDER == SPI_MSB
	CLR_BIT(SPCR,SPCR_DORD);
#elif SPI_DATA_ORDER == SPI_LSB
	SET_BIT(SPCR,SPCR_DORD);
#endif

#if SPI_CLOCK_POLARITY == SPI_RISINGD_EDGE
	CLR_BIT(SPCR,SPCR_CPOL);
#elif SPI_CLOCK_POLARITY == SPI_FALLING_EDGE
	SET_BIT(SPCR,SPCR_CPOL);
#endif

#if SPI_CLOCK_PHASE == SPI_SETUP
	SET_BIT(SPCR,SPCR_CPHA);
#elif SPI_CLOCK_PHASE == SPI_SAMPLE
	CLR_BIT(SPCR,SPCR_CPHA);
#endif

	SET_BIT(SPCR,SPCR_SPE);

}

ErrorStatus SPI_u8SendByteSynch(u8 Data)
{
	ErrorStatus local_Error=ERROR_OK;
	u16 		local_Timout=0;
	u8 			Dummy_Data;


	SPDR=Data;

	if(GET_BIT(SPSR,SPSR_WCOL)==1)
	{
		local_Error=ERROR_NOK;
	}

	while(GET_BIT(SPSR,SPSR_SPIF)==0 && local_Timout<SPI_TIMEOUT)
	{
		local_Timout++;
	}

	if(local_Timout >= SPI_TIMEOUT)
	{
		local_Error=ERROR_NOK;
	}

	Dummy_Data=SPDR;

	return local_Error;
}

ErrorStatus SPI_u8ReceiveByteSynch(u8 *Data)
{
	ErrorStatus local_Error=ERROR_OK;
	u16 		local_Timout=0;



	if(Data==NULL)
	{
		local_Error=ERROR_NOK;
	}

	else
	{
		SPDR=0;		/*Dummy Data*/
		while(GET_BIT(SPSR,SPSR_SPIF)==0 && local_Timout<SPI_TIMEOUT)
		{
			local_Timout++;
		}

		if(local_Timout >= SPI_TIMEOUT)
		{
			local_Error=ERROR_NOK;
		}
		else
		{
			*Data=SPDR;
		}
	}

	return local_Error;
}

ErrorStatus SPI_u8_Send_Receive_ByteSynch(u8 Data_S,u8 *Data_R)
{
	ErrorStatus local_Error=ERROR_OK;
	u16 		local_Timout=0;



	if(Data_R==NULL)
	{
		local_Error=ERROR_NOK;
	}

	else
	{
		SPDR=Data_S;

		if(GET_BIT(SPSR,SPSR_WCOL)==1)
		{
			local_Error=ERROR_NOK;
		}

		while(GET_BIT(SPSR,SPSR_SPIF)==0 && local_Timout<SPI_TIMEOUT)
		{
			local_Timout++;
		}

		if(local_Timout >= SPI_TIMEOUT)
		{
			local_Error=ERROR_NOK;
		}
		else
		{
			*Data_R=SPDR;
		}
	}

	return local_Error;
}

ErrorStatus SPI_u8SendReceiveBufferASynch(u8 *Data_S,u8 *Data_R,u8 BufferSize,void(*NotificationFuction)(void))
{
	ErrorStatus local_Error=ERROR_OK;

	if(Data_S==NULL || Data_R==NULL || NotificationFuction==NULL || SPI_BusyFlag==1)
	{
		local_Error=ERROR_NOK;
	}
	else
	{
		SPI_BusyFlag=1;
		SPI_TxBuffer=Data_S;
		SPI_RxBuffer=Data_R;
		SPI_BufferSize=BufferSize;
		SPI_NotificationFn=NotificationFuction;

		SPDR=SPI_TxBuffer[SPI_BufferIdx];

		SET_BIT(SPCR,SPCR_SPIE);
	}

	return ERROR_OK;
}


void __vector_12 (void)
{
	SPI_RxBuffer[SPI_BufferIdx]=SPDR;
	SPI_BufferIdx++;

	if(SPI_BufferIdx==SPI_BufferSize)
	{
		CLR_BIT(SPCR,SPCR_SPIE);
		SPI_BufferIdx=0;
		SPI_BufferSize=0;
		SPI_NotificationFn();
		SPI_BusyFlag=0;
	}
	else
	{
		SPDR=SPI_TxBuffer[SPI_BufferIdx];
	}
}
