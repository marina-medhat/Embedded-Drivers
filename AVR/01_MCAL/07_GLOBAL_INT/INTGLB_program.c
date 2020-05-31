#include "std_types.h"
#include "bits.h"
#include "INTGLB_register.h"
#include "INTGLB_private.h"
#include "INTGLB_interface.h"

void INT_voidEnableGlobal(void)
{
	SET_BIT(SREG,SREG_I);
}
void INT_voidDisableGlobal(void)
{
	CLR_BIT(SREG,SREG_I);
}
