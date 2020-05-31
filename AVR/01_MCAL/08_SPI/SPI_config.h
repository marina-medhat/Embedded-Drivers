/*
 * SPI_private.h
 *
 *  Created on: Apr 20, 2020
 *      Author: Marina
 */
#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_


/*
 Choose option from:
 	 SPI_MASTE
	 SPI_SLAVE
*/
#define SPI_SELECT_MODE		SPI_SLAVE

/*
 Choose option from:
 	 SPI_INT_ENABLE
	 SPI_INT_DISABLE
*/
#define SPI_INT_STATE	SPI_INT_DISABLE

/*
 Choose option from:
 	 SPI_LSB
	 SPI_MSB
*/
#define SPI_DATA_ORDER	SPI_MSB

/*
 Choose option from:
 	 SPI_RISINGD_EDGE
	 SPI_FALLING_EDGE
*/
#define SPI_CLOCK_POLARITY	SPI_RISINGD_EDGE

/*
 Choose option from:
 	 SPI_SAMPLE
	 SPI_SETUP
*/
#define SPI_CLOCK_PHASE		SPI_SAMPLE

/*
  Choose option from:
  	  SPI_CLK_DIV_4
	  SPI_CLK_DIV_16
	  SPI_CLK_DIV_64
	  SPI_CLK_DIV_128
	  SPI_HCLK_DIV_2
	  SPI_HCLK_DIV_8
	  SPI_HCLK_DIV_32
	  SPI_HCLK_DIV_64
 */
#define SPI_CLK_RATE		SPI_CLK_DIV_16


#define SPI_TIMEOUT			50000


#endif
