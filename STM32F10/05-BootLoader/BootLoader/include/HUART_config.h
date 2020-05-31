/*
 * HUART_config.h
 *
 *  Created on: Mar 28, 2020
 *      Author: MOSTAFA
 */

#ifndef HUART_CONFIG_H_
#define HUART_CONFIG_H_

/*************************************
 ********OPTIONS_UART_SENDING*********
 *************************************/
#define SEND_MODE_INTERRUPT			0
#define SEND_MODE_DMA				1

/*************************************
 *******OPTIONS_UART_RECEIVING********
 *************************************/
#define RECEIVE_MODE_INTERRUPT		0
#define RECEIVE_MODE_DMA			1


/*************************************
 ************OPTIONS_MODE*************
 *************************************/
#define INTERRUPT_MODE		        0
#define DMA_MODE			        1

/*************************************
 ********OPTIONS_OF_PARITY_BIT********
 *************************************/
#define PARITY_DISABLED		    0x00000000
#define PARITY_EVEN			    0x00000400
#define PARITY_ODD			    0x00000600
	
/*************************************
 *********OPTIONS_OF_STOP_BIT*********
 *************************************/	
#define ONE_STOP_BIT		    0x00000000
#define TWO_STOP_BIT		    0x00002000

/*************************************
 *********OPTIONS_OF_DATA_BIT*********
 *************************************/								    
#define DATA_8_BITS			    0x00000000
#define DATA_9_BITS			    0x00001000

/*************************************
 ********CONFIGS_OF_PARITY_BIT:*******
 *        ->PARITY_DISABLED	         *
 *        ->PARITY_EVEN		         *
 *        ->PARITY_ODD		         *
 *************************************/							    
#define PARITY_BIT			    PARITY_DISABLED

/*************************************
 ********CONFIGS_OF_STOP_BIT: ********
 *        ->ONE_STOP_BIT             *
 *        ->TWO_STOP_BIT             *
 *************************************/	
#define STOP_BITS			    ONE_STOP_BIT

/*************************************
 ********CONFIGS_OF_DATA_BIT: ********
 *        ->DATA_8_BITS              *
 *        ->DATA_9_BITS              *
 *************************************/
#define DATA_BITS			    DATA_8_BITS
	
/*************************************
 **********BAUD_RATE_VALUE************
 *************************************/	
#define BAUD_RATE_9600		    9600

/*************************************
 ********CONFIGS_SEND_MODE : *********
 *        ->SEND_MODE_INTERRUPT	     *
 *        ->SEND_MODE_DMA		     *
 *************************************/
#define SEND_MODE				SEND_MODE_DMA

/*************************************
 ********CONFIGS_RECEIVE_MODE:********
 *        ->RECEIVE_MODE_INTERRUPT	  *
 *        ->RECEIVE_MODE_DMA		  *
 *************************************/
#define RECEIVE_MODE			RECEIVE_MODE_DMA

/*************************************
 ***********CONFIGS_MODE: ************
 *           ->INTERRUPT_MODE	     *
 *           ->DMA_MODE		         *
 *************************************/
#define MODE					DMA_MODE


/*************************************
 **********CONFIG_BAUD_RATE***********
 *************************************/
#define BAUD_RATE			    BAUD_RATE_9600






#endif /* HUART_CONFIG_H_ */
