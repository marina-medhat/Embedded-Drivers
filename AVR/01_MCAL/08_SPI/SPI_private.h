
#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

/*SPCR Bits*/
#define		SPCR_SPIE	7
#define		SPCR_SPE	6
#define		SPCR_DORD	5
#define		SPCR_MSTR	4
#define		SPCR_CPOL	3
#define		SPCR_CPHA	2
#define		SPCR_SPR1	1
#define		SPCR_SPR0	0

/*SPSR Bits*/
#define 	SPSR_SPIF	7
#define 	SPSR_WCOL	6
#define 	SPSR_SPI2X	0

/*Configuration*/

#define		SPI_MASTER			0
#define		SPI_SLAVE			1

#define		SPI_INT_ENABLE		0
#define		SPI_INT_DISABLE		1

#define		SPI_MSB				0
#define		SPI_LSB				1

#define		SPI_RISINGD_EDGE	0
#define		SPI_FALLING_EDGE	1

#define		SPI_SAMPLE			0
#define		SPI_SETUP			1


#define 	SPI_CLK_DIV_4		0
#define 	SPI_CLK_DIV_16		1
#define 	SPI_CLK_DIV_64		2
#define 	SPI_CLK_DIV_128		3
#define 	SPI_HCLK_DIV_2		4
#define 	SPI_HCLK_DIV_8		5
#define 	SPI_HCLK_DIV_32		6
#define 	SPI_HCLK_DIV_64		7


void __vector_12 (void) __attribute__((signal));



#endif


