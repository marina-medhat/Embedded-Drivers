/**************************************************************************/
/*Author  :Marina Medhat                                                 */
/*Date    :9 March 2010                                                   */
/*Version :V01                                                            */
/**************************************************************************/

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

void UART_voidInit(void);
u8 UART_voidTransmitDataSynch(u8 Copy_u8Data);
void UART_voidTransmitDataASynch(u8 Copy_u8Data, void (*Copy_ptr)(void));
u8   UART_voidReceiveDataSynch(u8 * Copy_pu8Data);
/*lw feh data hab3atlo el datat fe u8 */
/*w lw mafesh data hastana interrupt w gwa el isr ha5leh y call el function de tany w yb3atli feha el data */
void UART_voidReceiveDataASynch(void (*Copy_ptr)(u8)); 

#endif

