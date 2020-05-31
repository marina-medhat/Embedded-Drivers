#ifndef HLCD_CONFIG_H_
#define HLCD_CONFIG_H_

/*************************************
 ************MAX_DATA_SIZE************
 *************************************/
#define DATA_BUFFER_SIZE	255

/*************************************
 ******LCD_NUMBER_OF_LINE_MODES*******
 *************************************/
#define ONE_LINE  CLEAR
#define TWO_LINES SET

/*************************************
 ***********LCD_FONT_MODES************
 *************************************/
#define SMALL_FONT CLEAR
#define BIG_FONT   SET

/*************************************
 **********LCD_DISPLAY_MODES**********
 *************************************/
#define DATA_DISPLAY_OFF CLEAR
#define DATA_DISPLAY_ON  SET

/*************************************
 *********LCD_CURSOR_MODES************
 *************************************/
#define CURSOR_DISPLAY_OFF CLEAR
#define CURSOR_DISPLAY_ON  SET

/*************************************
 *******LCD_BLINK_CURSOR_MODES********
 *************************************/
#define CURSOR_BLINK_OFF CLEAR
#define CURSOR_BLINK_ON  SET

/*************************************
 *********LCD_CONFIGURATIONS**********
 *************************************/
#define LINES_NUMBER   TWO_LINES
#define FONT_SIZE      SMALL_FONT
#define DISPLAY_DATA   DATA_DISPLAY_ON
#define DISPLAY_CURSOR CURSOR_DISPLAY_ON
#define BLINK_CURSOR   CURSOR_BLINK_OFF

/***************************************
 ***********LCD_PINS_STRUCT*************
 *********** RS		 : Command/Data Pin*
 *********** RW		 : Read/Write pin  *
 *********** EN		 : Enable Pin      *
 *********** DataPins: Data Pins       *
 ***************************************/
typedef struct {
	GPIO_t RS;
	GPIO_t RW;
	GPIO_t EN;
	GPIO_t DataPins [8];
}LCDPins_t;

#endif
