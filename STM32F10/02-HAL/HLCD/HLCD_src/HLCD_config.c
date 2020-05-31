#include "DGPIO.h"
#include "HLCD_config.h"


 const LCDPins_t LCDPins= {
.RS.Port= PORT_B,.RS.Pin=PIN_6,.RS.Mode=MODE_PIN6_OP_PP,.RS.Speed=SPEED_PIN6_2MHZ,
.RW.Port= PORT_B,.RW.Pin=PIN_7,.RW.Mode=MODE_PIN7_OP_PP,.RW.Speed=SPEED_PIN7_2MHZ,
.EN.Port= PORT_B,.EN.Pin=PIN_8,.EN.Mode=MODE_PIN8_OP_PP,.EN.Speed=SPEED_PIN8_2MHZ,
.DataPins[0].Port= PORT_A,.DataPins[0].Pin=PIN_0,.DataPins[0].Mode=MODE_PIN0_OP_PP,.DataPins[0].Speed=SPEED_PIN0_2MHZ,
.DataPins[1].Port= PORT_A,.DataPins[1].Pin=PIN_1,.DataPins[1].Mode=MODE_PIN1_OP_PP,.DataPins[1].Speed=SPEED_PIN1_2MHZ,
.DataPins[2].Port= PORT_A,.DataPins[2].Pin=PIN_2,.DataPins[2].Mode=MODE_PIN2_OP_PP,.DataPins[2].Speed=SPEED_PIN2_2MHZ,
.DataPins[3].Port= PORT_A,.DataPins[3].Pin=PIN_3,.DataPins[3].Mode=MODE_PIN3_OP_PP,.DataPins[3].Speed=SPEED_PIN3_2MHZ,
.DataPins[4].Port= PORT_A,.DataPins[4].Pin=PIN_4,.DataPins[4].Mode=MODE_PIN4_OP_PP,.DataPins[4].Speed=SPEED_PIN4_2MHZ,
.DataPins[5].Port= PORT_A,.DataPins[5].Pin=PIN_5,.DataPins[5].Mode=MODE_PIN5_OP_PP,.DataPins[5].Speed=SPEED_PIN5_2MHZ,
.DataPins[6].Port= PORT_A,.DataPins[6].Pin=PIN_6,.DataPins[6].Mode=MODE_PIN6_OP_PP,.DataPins[6].Speed=SPEED_PIN6_2MHZ,
.DataPins[7].Port= PORT_A,.DataPins[7].Pin=PIN_7,.DataPins[7].Mode=MODE_PIN7_OP_PP,.DataPins[7].Speed=SPEED_PIN7_2MHZ
};
