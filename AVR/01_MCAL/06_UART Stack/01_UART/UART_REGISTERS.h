/**************************************************************************/
/*Author  :Marina Medhat                                                 */
/*Date    :9 March 2010                                                   */
/*Version :V01                                                            */
/**************************************************************************/


#ifndef UART_REGISTER_H
#define UART_REGISTER_H

#define UDR_T *((volatile u8*)0x2C)
#define UDR_R *((volatile u8*)0x2C)
#define UCSRA *((volatile u8*)0x2B)
#define UCSRB *((volatile u8*)0x2A)
#define UCSRC *((volatile u8*)0x40)
#define UBRRL *((volatile u8*)0x29)
#define UBRRH *((volatile u8*)0x40)

#endif
