#define SET_BIT(var,bit_no) (var|=(1<<bit_no))
#define CLR_BIT(var,bit_no) (var&=(~(1<<bit_no)))
#define TOGGLE_BIT(var,bit_no) (var^=(1<<bit_no))
#define GET_BIT(var,bit_no) ((var>>bit_no)&0x01)

//BADL SET W CLEAR ,, BSAFR EL MKAN W B3DEN ORING M3 EL VALUE 
#define ASSIGN_BIT(VAR,BIT_NO,VAL) (VAR=(VAR& ~(1<<BIT_NO) | (VAL<<BIT_NO)) 