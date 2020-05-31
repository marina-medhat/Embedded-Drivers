/*****************************/
/*Author: Marina Medhat */
/*Version: V01 */
/*Date 14 Jan 2020m */
/*****************************/


/*Description: This API shall initialize LCD*/
void CLCD_voidInitialize(void);

/*Description: This API shall display data on LCD*/
void CLCD_voidWriteData(u8 copy_u8Data);

/*Description: This API shall execute command on LCD*/
void CLCD_voidWriteCmd(u8 copy_u8Cmd);

/*Description: This API shall change position to write or read on LCD*/
void CLCD_voidGoToXYPos(u8 Copy_u8XPos,u8 Copy_u8YPos);

/*Description: This API shall write String on LCD*/
void CLCD_voidWriteString(const char* Copy_pchString);




#define CLCD_U8_LINE_ONE 1
#define CLCD_U8_LINE_TWO 2

#define HSI_SYS_CLK   0x00000000
#define HSE_SYS_CLK   0x00000001
#define PLL_SYS_CLK   0x00000002

a b c d e
0x00000000
0x00010000

#define PLL_INCLK_MUL4  00 1000 2
#define PLL_INCLK_MUL5  00 1100 3
#define PLL_INCLK_MUL6  01 0000 4
#define PLL_INCLK_MUL7  01 0100 5
#define PLL_INCLK_MUL8  01 1000 6
#define PLL_INCLK_MUL9  01 1100 7
#define PLL_INCLK_MUL6.5 11 0100 D
0x00080000
0x000C0000
0x00100000
0x00140000
0x00180000
0x001C0000
0x00340000

0100  4
0101  5
0110  6
0111  7
1000  8
1001  9
1010  a
1011  b