#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define PORT_A	0
#define PORT_B	1
#define PORT_C	2
#define PORT_D	3

#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7

ErrorStatus DIO_SetPinDirection(u8 Port,u8 Pin, u8 Direction);
ErrorStatus DIO_SetPinValue(u8 Port,u8 Pin, u8 Value);
ErrorStatus DIO_SetPortDirecton(u8 Port,u8 Value);
ErrorStatus DIO_SetPortValue(u8 Port,u8 Value);
ErrorStatus DIO_GetPinValue(u8 Port,u8 Pin,u8 *Value);
ErrorStatus DIO_GetPortValue(u8 Port,u8 *Value);


#endif
