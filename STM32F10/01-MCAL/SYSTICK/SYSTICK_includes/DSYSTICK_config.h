/**************************************
 ******CONFIG_SYSTICK_CLK_SRC :******** 
 *    -> SYSTICK_CLK_AHB              *
 *    ->SYSTICK_CLK_AHB_DIV_8         *
 **************************************/
#define SYSTICK_CLK_SRC  SYSTICK_CLK_AHB_DIV_8

/**************************************
 ****CONFIG_SYSTICK_TICK_INTERRUPT***** 
 *    ->SYSTICK_TICK_INT_ENABLE       *
 *    ->SYSTICK_TICK_INT_DISABLE      *
 **************************************/
#define SYSTICK_TICK_INT SYSTICK_TICK_INT_ENABLE
