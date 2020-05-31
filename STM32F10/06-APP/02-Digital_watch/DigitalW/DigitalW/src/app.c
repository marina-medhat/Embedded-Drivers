/*
 * app.c
 *
 *  Created on: May 5, 2020
 *      Author: MOSTAFA
 */

#include "DRCC.h"
#include "DGPIO.h"
#include "DNVIC.h"
#include "DMA.h"
#include "HUART.h"
#include "DSYSTICK.h"
#include "HLED.h"
#include "Sched.h"
#include "HLCD.h"
#include "HSwitch.h"
#include "app.h"

#define CONFIG_MODE_ACTIVATED       1
#define CONFIG_MODE_DEACTIVATED     0

#define UP_BUTTON_PRESSED           0
#define DOWN_BUTTON_PRESSED         1
#define LEFT_BUTTON_PRESSED         2
#define RIGHT_BUTTON_PRESSED        3

#define HOURS_POSITION              0
#define MINUTES_POSITION            5
#define SECONDS_POSITION            10

#define STARTING_hours              17
#define STARTING_minutes            15

#define HEADER_KEY                  0XAA

#define CHECK(a,b)                  ~(a+b)

typedef struct
{
	uint_8t header;
	uint_8t config;
	uint_8t data;
	uint_8t checkSum;

}frame_t;

static uint_8t hours = STARTING_hours , minutes=STARTING_minutes , \
		seconds ,  receiveBuffer[4] , transmitBuffer[4];

static void appTask(void);
static void updateTime(void);
static void updateDisplay(void);
void writeDone(void);
void receiveDone(void);
void transmitDone(void);

static uint_8t configMode;
static uint_8t buttonPressed;
static uint_8t cursorPosition;


task_t mainTask={.Runnable=appTask , .periodicity=25};

void app_Init(void)
{
	Switch_Init();
	LCD_Init();
	HUART_Init();
	LCD_SetWriteCallBackFunction(writeDone);
	HUART_SetRxCbf(receiveDone);
	HUART_SetTxCbf(transmitDone);

}


static void appTask(void)
{
	uint_8t switchState;
	static uint_8t counter , configPressedCounter ;
	static frame_t *transmitFrame=(frame_t *)transmitBuffer ;

	/*Displaying Time*/
	counter++;
	if(counter == ((1000/mainTask.periodicity) -1))
	{
		LCD_ClearLCD();
	}
	else if(counter == (1000/mainTask.periodicity)) /*counter will reach 1 second */
	{
		updateTime();
		counter=0;
	}
	else
	{
		/*do nothing*/
	}



	/*Configuration Handling*/
	if(configMode == CONFIG_MODE_ACTIVATED)
	{
		switch(buttonPressed)
		{
		case UP_BUTTON_PRESSED:
			switch(cursorPosition)
			{
			case HOURS_POSITION:
				hours++;
				if(hours == 24)
				{
					hours=0;
				}
				break;

			case MINUTES_POSITION:
				minutes++;
				if(minutes == 60)
				{
					minutes=0;

				}
				break;

			case SECONDS_POSITION:
				seconds++;
				if(seconds == 60)
				{
					seconds=0;
				}

				break;
			default:

				break;

			}
			break;

			case DOWN_BUTTON_PRESSED:
				switch(buttonPressed)
				{
				case UP_BUTTON_PRESSED:
					switch(cursorPosition)
					{
					case HOURS_POSITION:
						if(hours == 0)
						{
							hours=23;
						}
						else
						{
							hours--;
						}
						break;

					case MINUTES_POSITION:
						if(minutes == 0)
						{
							minutes=59;
						}
						else
						{
							minutes--;
						}
						break;

					case SECONDS_POSITION:
						if(seconds == 0)
						{
							seconds=59;
						}
						else
						{
							seconds--;
						}
						break;

					default:
						break;
					}
					break;


					case LEFT_BUTTON_PRESSED:
						switch(cursorPosition)
						{
						case HOURS_POSITION:
							cursorPosition=SECONDS_POSITION;
							break;

						case MINUTES_POSITION:
							cursorPosition=HOURS_POSITION;
							break;

						case SECONDS_POSITION:
							cursorPosition=MINUTES_POSITION;
							break;

						default:
							break;
						}
						break;


						case RIGHT_BUTTON_PRESSED:
							switch(cursorPosition)
							{
							case HOURS_POSITION:
								cursorPosition=MINUTES_POSITION;
								break;

							case MINUTES_POSITION:
								cursorPosition=SECONDS_POSITION;
								break;

							case SECONDS_POSITION:
								cursorPosition=HOURS_POSITION;
								break;

							default:
								break;
							}
							break;

							default:
								break;

				}

		}
		updateDisplay();

	}
	else
	{
		/*do nothing*/
	}
	/*update transmitBuffer */
	transmitFrame->header = HEADER_KEY;
	Switch_GetSwitchState(CONFIG_SWITCH,& switchState);

	if(switchState == SWITCH_PRESSED)
	{
		configPressedCounter++;
		if(configPressedCounter == (2000/mainTask.periodicity) )
		{
			transmitFrame->config=CONFIG_MODE_ACTIVATED;
			configPressedCounter=0;
		}
		else
		{
			/*do nothing*/
		}

	}
	else
	{
		configPressedCounter=0;
	}

	Switch_GetSwitchState(OK_SWITCH,& switchState);
	if(switchState == SWITCH_PRESSED)
	{
		transmitFrame->config=CONFIG_MODE_DEACTIVATED;
	}
	else
	{
		/*do nothing*/
	}
	if(transmitFrame->config == CONFIG_MODE_ACTIVATED)
	{


		Switch_GetSwitchState(UP_SWITCH,& switchState);
		if(switchState == SWITCH_PRESSED)
		{
			transmitFrame->data=UP_BUTTON_PRESSED;
		}
		else
		{
			/*do nothing*/
		}

		Switch_GetSwitchState(DOWN_SWITCH,& switchState);
		if(switchState == SWITCH_PRESSED)
		{
			transmitFrame->data=DOWN_BUTTON_PRESSED;
		}
		else
		{
			/*do nothing*/
		}
		Switch_GetSwitchState(LEFT_SWITCH,& switchState);
		if(switchState == SWITCH_PRESSED)
		{
			transmitFrame->data=LEFT_BUTTON_PRESSED;
		}
		else
		{
			/*do nothing*/
		}
		Switch_GetSwitchState(RIGHT_SWITCH,& switchState);
		if(switchState == SWITCH_PRESSED)
		{
			transmitFrame->data=RIGHT_BUTTON_PRESSED;
		}
		else
		{
			/*do nothing*/
		}
	}
	else
	{
		/*do nothing*/
	}
}

static void updateTime(void)
{

	seconds++;
	if(seconds == 60)
	{
		seconds=0;
		minutes++;
	}
	else
	{
		/*do nothing*/
	}
	if(minutes == 60)
	{
		minutes=0;
		hours++;
	}
	else
	{
		/*do nothing*/
	}
	if(hours == 24)
	{
		hours=0;
	}
	else
	{
		/*do nothing*/
	}

	/*setting display array */
	updateDisplay();

}

static void updateDisplay(void)
{
	static uint_8t displayArray[12];
	if(hours<10)
	{
		displayArray[0]='0';
		displayArray[1]=(uint_8t)(hours+'0');
	}
	else
	{
		displayArray[0]=(uint_8t)((hours/10)+'0');
		displayArray[1]=(uint_8t)((hours%10)+'0');

	}

	displayArray[2]=' ';
	displayArray[3]=':';
	displayArray[4]=' ';

	if(minutes<10)
	{
		displayArray[5]='0';
		displayArray[6]=(uint_8t)(minutes+'0');
	}
	else
	{
		displayArray[5]=(uint_8t)((minutes/10)+'0');
		displayArray[6]=(uint_8t)((minutes%10)+'0');

	}

	displayArray[7]=' ';
	displayArray[8]=':';
	displayArray[9]=' ';

	if(seconds<10)
	{
		displayArray[10]='0';
		displayArray[11]=(uint_8t)(seconds+'0');
	}
	else
	{
		displayArray[10]=(uint_8t)((seconds/10)+'0');
		displayArray[11]=(uint_8t)((seconds%10)+'0');

	}
	/*Call LCD Write*/
	LCD_WriteData(displayArray,12);
}

void writeDone(void)
{
	LCD_SetPosition(FIRST_ROW,cursorPosition);
}


void receiveDone(void)
{
	frame_t *receivedFrame=(frame_t *)receiveBuffer;
	if(receivedFrame->header ==  HEADER_KEY)
	{
		if((CHECK(receivedFrame->config,receivedFrame->data)) == receivedFrame->checkSum)
		{
			configMode=receivedFrame->config;
			buttonPressed=receivedFrame->data;
		}
		else
		{
			/*do nothing*/
		}
	}
	else
	{
		/*do nothing*/
	}

	HUART_Receive(receiveBuffer,4);

}


void transmitDone(void)
{
	HUART_Send(transmitBuffer,4);

}
