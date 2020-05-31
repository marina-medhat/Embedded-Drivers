/***************************************************
 ***************************************************
 ******HLED_map struct of Led Configuration:********
 * Led_Number  -> MACRO OF LED NUMBER              *
 *                 Led Number:LED_x(LED_1,LED_2,..)*
 *												   *
 * Led_Port    -> Pointer of Port_t struct         *
 *                PORT_x(PORT_A ... PORT_G)        *
 *                                                 *
 * Led_Pin     -> MACRO of LED PIN                 *
 *                PIN-x(PIN_0 ... PIN_15)          *
 *												   *                                     
 * Led_ON      -> Led Mode:                        *
 *                 ACTIVE_HIGH	                   *
 *                 ACTIVE_LOW	                   *
 *												   *
 ***************************************************
 ***************************************************/
typedef struct 
{
	uint_8t 	Led_Number;
	Port_t*  	Led_Port;
	uint_16t 	Led_Pin;
	uint_8t 	Led_ON;
}HLED_map;


