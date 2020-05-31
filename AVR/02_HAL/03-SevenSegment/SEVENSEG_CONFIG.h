/*set Mode to 1 for common Anode , 0 common Cathode */
#define SEVENSEG_Mode  1


/*Choose port from A , B , C , D */
#define SEVENSEG_PinA_PORT  'B'
#define SEVENSEG_PinA_Number  0

/*Choose port from A , B , C , D */
#define SEVENSEG_PinB_PORT  'B'
#define SEVENSEG_PinB_Number  1

/*Choose port from A , B , C , D */
#define SEVENSEG_PinC_PORT  'B'
#define SEVENSEG_PinC_Number  2

/*Choose port from A , B , C , D */
#define SEVENSEG_PinD_PORT  'B'
#define SEVENSEG_PinD_Number  3

/*Choose port from A , B , C , D */
#define SEVENSEG_PinE_PORT  'B'
#define SEVENSEG_PinE_Number  4

/*Choose port from A , B , C , D */
#define SEVENSEG_PinF_PORT  'B'
#define SEVENSEG_PinF_Number  5

/*Choose port from A , B , C , D */
#define SEVENSEG_PinG_PORT  'B'
#define SEVENSEG_PinG_Number  6
 
/*Choose port from A , B , C , D */
#define SEVENSEG_PinH_PORT  'B'
#define SEVENSEG_PinH_Number  7

/*Choose port from A , B , C , D */
#define SEVENSEG1_PinCOM_PORT  'D'
/* Value Anode= 1 , Value Cathode= 0 */
#define SEVENSEG1_PinCOM_Number 7

/*Choose port from A , B , C , D */
#define SEVENSEG2_PinCOM_PORT  'D'
/* Value Anode= 1 , Value Cathode= 0 */
#define SEVENSEG2_PinCOM_Number 1

#define SEVENSEGMENTS_NUMBER 2
#define SEVENSEGMENTS_PORTS {SEVENSEG1_PinCOM_PORT,SEVENSEG2_PinCOM_PORT}
#define SEVENSEGMENTS_PINS {SEVENSEG1_PinCOM_Number,SEVENSEG2_PinCOM_Number}



#define SEVENSEG_InitialVal 10000000
