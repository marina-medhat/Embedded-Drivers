#include "STD_TYPES.h"
#include "sched.h"
#include "DRCC.h"
#include "DGPIO.h"
#include "HLCD.h"
#include "HLCD_config.h"


#define FUNCTION_SET						0
#define DISPLAY_ON_OFF						1
#define DISPLAY_CLEAR						2
#define ENTRY_MODE_SET						3

#define IDLE_PROCESS						0
#define WRITE_PROCESS						1
#define CLEAR_PROCESS						2
#define POSITION_PROCESS					3

#define NOT_INITIALIZED 					0
#define INITIALIZED 						1

#define DDRAM_ADDRESS		 				0x80
#define LINE_TWO_ADDRESS_OFFSET				0x40

typedef uint_8t CurrentProcess_t;

extern LCDPins_t LCDPins;

task_t LCDTask;

CurrentProcess_t CurrentProcess=IDLE_PROCESS;
uint_8t InitComplete=NOT_INITIALIZED;
uint_8t Lcd_Data[DATA_BUFFER_SIZE];
uint_8t Lcd_Length;
uint_8t Lcd_Xpos;
uint_8t Lcd_Ypos;
LCDCbf_t Writecbf;

static void HLCD_SetDataPins (uint_8t data);
static void HLCD_LCDTask (void);
static void HLCD_InitProcess (void);
static void HLCD_WriteProcess (void);
static void HLCD_ClearProcess (void);
static void HLCD_SetPositionProcess(void);

static void HLCD_LCDTask (void)
{
	if(InitComplete)
	{
		switch(CurrentProcess)
		{
		case IDLE_PROCESS:
			break;
		case WRITE_PROCESS:
			LCD_WriteProcess();
			break;
		case CLEAR_PROCESS:
			LCD_ClearProcess();
			break;
		case POSITION_PROCESS :
			LCD_SetPositionProcess();
		}
	}
	else
	{
		LCD_InitProcess();
	}
}
static void HLCD_InitProcess (void)
{
	static uint_8t Current_state=FUNCTION_SET;
	static uint_8t counter;
	uint_8t Enable;

	counter++;

	if(counter>=15)
	{
		switch(Current_state)
		{
		case FUNCTION_SET:
			DGPIO_ReadPin(LCDPins.EN.Port,LCDPins.EN.Pin,&Enable);
			if(Enable)
			{
				DGPIO_Write(LCDPins.EN.Port,LCDPins.EN.Pin,CLEAR);
				Current_state=DISPLAY_ON_OFF;
			}
			else
			{
				DGPIO_Write(LCDPins.RS.Port,LCDPins.RS.Pin,CLEAR);
				DGPIO_Write(LCDPins.RW.Port,LCDPins.RW.Pin,CLEAR);
				DGPIO_Write(LCDPins.DataPins[0].Port,LCDPins.DataPins[0].Pin,CLEAR);
				DGPIO_Write(LCDPins.DataPins[1].Port,LCDPins.DataPins[1].Pin,CLEAR);
				DGPIO_Write(LCDPins.DataPins[2].Port,LCDPins.DataPins[2].Pin,FONT_SIZE);
				DGPIO_Write(LCDPins.DataPins[3].Port,LCDPins.DataPins[3].Pin,LINES_NUMBER);
				DGPIO_Write(LCDPins.DataPins[4].Port,LCDPins.DataPins[4].Pin,SET);
				DGPIO_Write(LCDPins.DataPins[5].Port,LCDPins.DataPins[5].Pin,SET);
				DGPIO_Write(LCDPins.DataPins[6].Port,LCDPins.DataPins[6].Pin,CLEAR);
				DGPIO_Write(LCDPins.DataPins[7].Port,LCDPins.DataPins[7].Pin,CLEAR);
				DGPIO_Write(LCDPins.EN.Port,LCDPins.EN.Pin,SET);

			}
			break;

		case DISPLAY_ON_OFF:
			DGPIO_ReadPin(LCDPins.EN.Port,LCDPins.EN.Pin,&Enable);
			if(Enable)
			{
				DGPIO_Write(LCDPins.EN.Port,LCDPins.EN.Pin,CLEAR);
				Current_state=DISPLAY_CLEAR;
			}
			else
			{
				DGPIO_Write(LCDPins.RS.Port,LCDPins.RS.Pin,CLEAR);
				DGPIO_Write(LCDPins.RW.Port,LCDPins.RW.Pin,CLEAR);
				DGPIO_Write(LCDPins.DataPins[0].Port,LCDPins.DataPins[0].Pin,BLINK_CURSOR);
				DGPIO_Write(LCDPins.DataPins[1].Port,LCDPins.DataPins[1].Pin,DISPLAY_CURSOR);
				DGPIO_Write(LCDPins.DataPins[2].Port,LCDPins.DataPins[2].Pin,DISPLAY_DATA);
				DGPIO_Write(LCDPins.DataPins[3].Port,LCDPins.DataPins[3].Pin,SET);
				DGPIO_Write(LCDPins.DataPins[4].Port,LCDPins.DataPins[4].Pin,CLEAR);
				DGPIO_Write(LCDPins.DataPins[5].Port,LCDPins.DataPins[5].Pin,CLEAR);
				DGPIO_Write(LCDPins.DataPins[6].Port,LCDPins.DataPins[6].Pin,CLEAR);
				DGPIO_Write(LCDPins.DataPins[7].Port,LCDPins.DataPins[7].Pin,CLEAR);
				DGPIO_Write(LCDPins.EN.Port,LCDPins.EN.Pin,SET);

			}
			break;

		case DISPLAY_CLEAR:
			DGPIO_ReadPin(LCDPins.EN.Port,LCDPins.EN.Pin,&Enable);
			if(Enable)
			{
				DGPIO_Write(LCDPins.EN.Port,LCDPins.EN.Pin,CLEAR);
				/*Current_state=ENTRY_MODE_SET;*/
				InitComplete=INITIALIZED;
			}
			else
			{
				DGPIO_Write(LCDPins.RS.Port,LCDPins.RS.Pin,CLEAR);
				DGPIO_Write(LCDPins.RW.Port,LCDPins.RW.Pin,CLEAR);
				DGPIO_Write(LCDPins.DataPins[0].Port,LCDPins.DataPins[0].Pin,SET);
				DGPIO_Write(LCDPins.DataPins[1].Port,LCDPins.DataPins[1].Pin,CLEAR);
				DGPIO_Write(LCDPins.DataPins[2].Port,LCDPins.DataPins[2].Pin,CLEAR);
				DGPIO_Write(LCDPins.DataPins[3].Port,LCDPins.DataPins[3].Pin,CLEAR);
				DGPIO_Write(LCDPins.DataPins[4].Port,LCDPins.DataPins[4].Pin,CLEAR);
				DGPIO_Write(LCDPins.DataPins[5].Port,LCDPins.DataPins[5].Pin,CLEAR);
				DGPIO_Write(LCDPins.DataPins[6].Port,LCDPins.DataPins[6].Pin,CLEAR);
				DGPIO_Write(LCDPins.DataPins[7].Port,LCDPins.DataPins[7].Pin,CLEAR);
				DGPIO_Write(LCDPins.EN.Port,LCDPins.EN.Pin,SET);

			}
			break;

		}
	}
	else
	{
		asm("NOP");
	}



}
static void HLCD_WriteProcess (void)
{
	uint_8t Enable;
	uint_8t local_counter;
	uint_8t temp;
	static uint_8t CurrChar;


	DGPIO_ReadPin(LCDPins.EN.Port,LCDPins.EN.Pin,&Enable);
	if(Enable)
	{
		DGPIO_Write(LCDPins.EN.Port,LCDPins.EN.Pin,CLEAR);
	}
	else
	{
		if (Lcd_Length==CurrChar)
		{
			CurrentProcess=IDLE_PROCESS;
			CurrChar=0;
			if (Writecbf)
			{
				Writecbf();
			}
		}
		else
		{
			DGPIO_Write(LCDPins.RS.Port,LCDPins.RS.Pin,SET);
			DGPIO_Write(LCDPins.RW.Port,LCDPins.RW.Pin,CLEAR);
			temp=Lcd_Data[CurrChar];
			LCD_SetDataPins(temp);
			DGPIO_Write(LCDPins.EN.Port,LCDPins.EN.Pin,SET);
			CurrChar++;
		}
	}

}
static void HLCD_ClearProcess (void)
{
	uint_8t Enable;
	DGPIO_ReadPin(LCDPins.EN.Port,LCDPins.EN.Pin,&Enable);
	if(Enable)
	{
		DGPIO_Write(LCDPins.EN.Port,LCDPins.EN.Pin,CLEAR);
		CurrentProcess=IDLE_PROCESS;
	}
	else
	{

		DGPIO_Write(LCDPins.RS.Port,LCDPins.RS.Pin,CLEAR);
		DGPIO_Write(LCDPins.RW.Port,LCDPins.RW.Pin,CLEAR);
		DGPIO_Write(LCDPins.DataPins[0].Port,LCDPins.DataPins[0].Pin,SET);
		DGPIO_Write(LCDPins.DataPins[1].Port,LCDPins.DataPins[1].Pin,CLEAR);
		DGPIO_Write(LCDPins.DataPins[2].Port,LCDPins.DataPins[2].Pin,CLEAR);
		DGPIO_Write(LCDPins.DataPins[3].Port,LCDPins.DataPins[3].Pin,CLEAR);
		DGPIO_Write(LCDPins.DataPins[4].Port,LCDPins.DataPins[4].Pin,CLEAR);
		DGPIO_Write(LCDPins.DataPins[5].Port,LCDPins.DataPins[5].Pin,CLEAR);
		DGPIO_Write(LCDPins.DataPins[6].Port,LCDPins.DataPins[6].Pin,CLEAR);
		DGPIO_Write(LCDPins.DataPins[7].Port,LCDPins.DataPins[7].Pin,CLEAR);
		DGPIO_Write(LCDPins.EN.Port,LCDPins.EN.Pin,SET);
	}
}
static void HLCD_SetPositionProcess(void)
{
	uint_8t Enable;
	DGPIO_ReadPin(LCDPins.EN.Port,LCDPins.EN.Pin,&Enable);
	if(Enable)
	{
		DGPIO_Write(LCDPins.EN.Port,LCDPins.EN.Pin,CLEAR);
		CurrentProcess=IDLE_PROCESS;
	}
	else
	{
		DGPIO_Write(LCDPins.RS.Port,LCDPins.RS.Pin,CLEAR);
		DGPIO_Write(LCDPins.RW.Port,LCDPins.RW.Pin,CLEAR);
		if (!Lcd_Ypos)
		{
			LCD_SetDataPins(DDRAM_ADDRESS+Lcd_Xpos);
		}
		else
		{
			LCD_SetDataPins(DDRAM_ADDRESS+LINE_TWO_ADDRESS_OFFSET+Lcd_Xpos);
		}
		DGPIO_Write(LCDPins.EN.Port,LCDPins.EN.Pin,SET);
	}

}

uint_8t HLCD_Init (void)
{
	uint_8t i,LocalError = OK;
	LCDTask.Runnable=LCD_LCDTask;
	LCDTask.periodicity=5;
	/*Enable RCC clock for GPIO Ports*/
	if (LCDPins.RS.Port == PORT_A)
	{
		LocalError |= DRCC_SetPriephralStatus(GPIO_A_ENABLE,ON);
	}
	else if (LCDPins.RS.Port == PORT_B)
	{

		LocalError |= DRCC_SetPriephralStatus(GPIO_B_ENABLE,ON);
	}
	else if (LCDPins.RS.Port == PORT_C)
	{
		LocalError |= DRCC_SetPriephralStatus(GPIO_C_ENABLE,ON);
	}
	else if (LCDPins.RS.Port == PORT_D)
	{
		LocalError |= DRCC_SetPriephralStatus(GPIO_D_ENABLE,ON);
	}
	else if (LCDPins.RS.Port == PORT_E)
	{
		LocalError |= DRCC_SetPriephralStatus(GPIO_E_ENABLE,ON);
	}
	else if (LCDPins.RS.Port == PORT_F)
	{
		LocalError |= DRCC_SetPriephralStatus(GPIO_F_ENABLE,ON);
	}
	else if (LCDPins.RS.Port == PORT_G)
	{
		LocalError |= DRCC_SetPriephralStatus(GPIO_G_ENABLE,ON);
	}

	if (LCDPins.RW.Port == PORT_A)
	{
		LocalError |= DRCC_SetPriephralStatus(GPIO_A_ENABLE,ON);
	}
	else if (LCDPins.RW.Port == PORT_B)
	{
		LocalError |= DRCC_SetPriephralStatus(GPIO_B_ENABLE,ON);
	}
	else if (LCDPins.RW.Port == PORT_C)
	{
		LocalError |= DRCC_SetPriephralStatus(GPIO_C_ENABLE,ON);
	}
	else if (LCDPins.RW.Port == PORT_D)
	{
		LocalError |= DRCC_SetPriephralStatus(GPIO_D_ENABLE,ON);
	}
	else if (LCDPins.RW.Port == PORT_E)
	{
		LocalError |= DRCC_SetPriephralStatus(GPIO_E_ENABLE,ON);
	}
	else if (LCDPins.RW.Port == PORT_F)
	{
		LocalError |= DRCC_SetPriephralStatus(GPIO_F_ENABLE,ON);
	}
	else if (LCDPins.RW.Port == PORT_G)
	{
		LocalError |= DRCC_SetPriephralStatus(GPIO_G_ENABLE,ON);
	}
	for (i=0;i<8;i++)
	{
		if (LCDPins.DataPins[i].Port == PORT_A)
		{
			LocalError |= DRCC_SetPriephralStatus(GPIO_A_ENABLE,ON);
		}
		else if (LCDPins.DataPins[i].Port == PORT_B)
		{
			LocalError |= DRCC_SetPriephralStatus(GPIO_B_ENABLE,ON);
		}
		else if (LCDPins.DataPins[i].Port == PORT_C)
		{
			LocalError |= DRCC_SetPriephralStatus(GPIO_C_ENABLE,ON);
		}
		else if (LCDPins.DataPins[i].Port == PORT_D)
		{
			LocalError |= DRCC_SetPriephralStatus(GPIO_D_ENABLE,ON);
		}
		else if (LCDPins.DataPins[i].Port == PORT_E)
		{
			LocalError |= DRCC_SetPriephralStatus(GPIO_E_ENABLE,ON);
		}
		else if (LCDPins.DataPins[i].Port == PORT_F)
		{
			LocalError |= DRCC_SetPriephralStatus(GPIO_F_ENABLE,ON);
		}
		else if (LCDPins.DataPins[i].Port == PORT_G)
		{
			LocalError |= DRCC_SetPriephralStatus(GPIO_G_ENABLE,ON);
		}
	}

	/*Configure LCD GPIO Pins*/

	LocalError=DGPIO_Config(&(LCDPins.RS));
	if (!LocalError)
		LocalError=DGPIO_Config(&(LCDPins.RW));
	if (!LocalError)
		LocalError=DGPIO_Config(&(LCDPins.EN));
	if (!LocalError)
	{
		for (i=0;i<8;i++)
		{
			if (!LocalError)
				DGPIO_Config(&(LCDPins.DataPins[i]));
		}
	}
	return LocalError;
}

uint_8t HLCD_WriteData (const uint_8t *data,uint_8t DataLength)
{
	uint_8t local_counter;
	if(CurrentProcess==IDLE_PROCESS && InitComplete == INITIALIZED )
	{
		CurrentProcess=WRITE_PROCESS;
		Lcd_Length=DataLength;
		for(local_counter=0;local_counter<Lcd_Length;local_counter++)
		{
			Lcd_Data[local_counter]=data[local_counter];
		}
		return OK;
	}
	else
		return NOT_OK;
}


uint_8t HLCD_ClearLCD (void)
{
	if(CurrentProcess==IDLE_PROCESS && InitComplete == INITIALIZED )
	{
		CurrentProcess=CLEAR_PROCESS;
		return OK;
	}
	else
		return NOT_OK;
}
static void HLCD_SetDataPins (uint_8t data)
{
	uint_8t local_counter;
	for(local_counter=0;local_counter<8;local_counter++)
	{
		DGPIO_Write(LCDPins.DataPins[local_counter].Port,LCDPins.DataPins[local_counter].Pin,((data>>local_counter)&(1)));
	}
}
uint_8t HLCD_SetPosition (uint_8t YPos,uint_8t XPos)
{
	Lcd_Xpos=XPos;
	Lcd_Ypos=YPos;
	if(CurrentProcess==IDLE_PROCESS && InitComplete == INITIALIZED)
	{
		CurrentProcess=POSITION_PROCESS;
		return OK;
	}
	else
		return NOT_OK;
}

uint_8t HLCD_SetWriteCallBackFunction (LCDCbf_t cbf)
{
	uint_8t LocalError=OK;
	if (cbf)
	{
		Writecbf=cbf;
	}
	else
	{
		LocalError= NOT_OK;
	}
	return LocalError;
}
