/**************************************************************************/
/*Author  :Marmora Medhat                                                 */
/*Date    :9 March 2010                                                   */
/*Version :V01                                                            */
/**************************************************************************/

#ifndef UART_CONFIG_H
#define UART_CONFIG_H

/*options : UART_PARITY_DISABLED
            UART_PARITY_EVEN
			UART_PARITY_ODD
*/
#define UART_u8_PARITY                      UART_PARITY_DISABLED


/*options : UART_u8_BAUD_4800
            UART_u8_BAUD_9600
			UART_u8_BAUD_115200             
*/
#define UART_u8_BAUD_RATE                   UART_u8_BAUD_4800 



/*options : UART_u8_STOP_1_BIT
            UART_u8_STOP_2_BIT			
*/
#define UART_u8_STOP_BITS                   UART_u8_STOP_1_BIT



/*options : UART_u8_SYS_FREQ_8M
            UART_u8_SYS_FREQ_12M	
            UART_u8_SYS_FREQ_16M			
*/
#define UART_u8_SYS_FREQ                   UART_u8_SYS_FREQ_8M

#define UART_u32_TIME_OUT_TH               10000UL



#endif