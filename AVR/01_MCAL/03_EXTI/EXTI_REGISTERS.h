

#define GICR   *((u8*)0x5B)
#define GICR_INT1  7
#define GICR_INT0  6
#define GICR_INT2  5


#define GIFR   *((u8*)0x5A)


#define MCUCR  *((u8*)0x55)

#define MCUCR_ISC00  0
#define MCUCR_ISC01  1
#define MCUCR_ISC10  2
#define MCUCR_ISC11  3

#define MCUCSR *((u8*)0x54)
#define MCUCSR_ISC2 6

#define SREG  *((u8*)0x5F)
#define SREG_I  7
