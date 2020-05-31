/*set Mode to 1 for common Anode , 0 common Cathode */


/*Choose port from A , B , C , D */
#define KEYPAD_R0_PORT  'A'
#define KEYPAD_R0_PIN  0

/*Choose port from A , B , C , D */
#define KEYPAD_R1_PORT  'A'
#define KEYPAD_R1_PIN  1

/*Choose port from A , B , C , D */
#define KEYPAD_R2_PORT  'A'
#define KEYPAD_R2_PIN  2

/*Choose port from A , B , C , D */
#define KEYPAD_R3_PORT  'A'
#define KEYPAD_R3_PIN  3

/*Choose port from A , B , C , D */
#define KEYPAD_C0_PORT  'A'
#define KEYPAD_C0_PIN  4

/*Choose port from A , B , C , D */
#define KEYPAD_C1_PORT  'A'
#define KEYPAD_C1_PIN  5

/*Choose port from A , B , C , D */
#define KEYPAD_C2_PORT  'A'
#define KEYPAD_C2_PIN  6
 
/*Choose port from A , B , C , D */
#define KEYPAD_C3_PORT  'A'
#define KEYPAD_C3_PIN  7

/*Choose port from A , B , C , D */
#define KEYPAD_ROWS_NUM 4
/* Value Anode= 1 , Value Cathode= 0 */
#define KEYPAD_COLS_NUM 4

#define Keypad_ROWS_PORTS {KEYPAD_R0_PORT,KEYPAD_R1_PORT,KEYPAD_R2_PORT,KEYPAD_R3_PORT}
#define Keypad_ROWS_PINS  {KEYPAD_R0_PIN,KEYPAD_R1_PIN,KEYPAD_R2_PIN,KEYPAD_R3_PIN}


#define Keypad_COLS_PORTS {KEYPAD_C0_PORT,KEYPAD_C1_PORT,KEYPAD_C2_PORT,KEYPAD_C3_PORT}
#define Keypad_COLS_PINS  {KEYPAD_C0_PIN,KEYPAD_C1_PIN,KEYPAD_C2_PIN,KEYPAD_C3_PIN}

#define KeyPadKeys {{0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15}}

#define Keypad_default 0xff