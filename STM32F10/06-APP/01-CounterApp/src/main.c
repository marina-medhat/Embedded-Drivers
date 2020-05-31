#include "HUART.h"
#include "HSwitch.h"
#include "HLED.h"
#include "CounterApp.h"
int
main(/*int argc, char* argv[]*/void)
{
	uint_8t LocalError=OK;
	/*Initialize system*/
	LocalError=MyAPP_init();
	/*call application*/
	LocalError=MyApp();

	return LocalError;
}

