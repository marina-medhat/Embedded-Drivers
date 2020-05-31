
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


#define EXTI_u8_INT0 0
#define EXTI_u8_INT1 1
#define EXTI_u8_INT2 2

#define EXTI_u8_LOW_LEVEL         0
#define EXTI_u8_ON_CHANGE         1 
#define EXTI_u8_FALLING_EDGE  2
#define EXTI_u8_RISING_EDGE   3


/*
Description : Function used to initialize the external interrupts INT0,INT1,INT2 according 
              to the precompiled configration
			  
	inputs : void 
    outputs: void	
			  

*/
void EXTI_voidInit(void);

/*
Description : Function used to enable the peripheral enable of external interrupts INT0,INT1,INT2 according 
              to the precompiled configration
			  
	inputs : interrupt index , Ranges are :
	         1-EXTI_u8_INT0
			 2-EXTI_u8_INT1
			 3-EXTI_u8_INT2
    outputs: Error Status	
*/
ErrorStatus EXTI_errEnable(u8 Copy_u8IntIdx);

/*
Description : Function used to disable the peripheral disable of external interrupts INT0,INT1,INT2 according 
              to the precompiled configration
			  
	inputs : interrupt index , Ranges are :
	         1-EXTI_u8_INT0
			 2-EXTI_u8_INT1
			 3-EXTI_u8_INT2
    outputs: Error Status	
*/
ErrorStatus EXTI_errDisable(u8 Copy_u8IntIdx);


/*
Description : Function used to set the required sense level of  external interrupts INT0,INT1,INT2 
			  
	inputs : 1)interrupt index , Ranges are :
	         1-EXTI_u8_INT0
			 2-EXTI_u8_INT1
			 3-EXTI_u8_INT2
			 
			 2)
			 1-EXTI_u8_LOW_LEVEL
			 2-EXTI_u8_ON_CHANGE
			 3-EXTI_u8_LOW_FALLING_EDGE
			 4-EXTI_u8_LOW_RISING_EDGE
    outputs: Error Status	
*/
ErrorStatus EXTI_errSetSense(u8 Copy_u8IntIdx,u8 Copy_u8SensLevel);

/*
Description : Function used to set the call back function of  INT0,INT1,INT2 
			  
	inputs : 1)interrupt index , Ranges are :
	         1-EXTI_u8_INT0
			 2-EXTI_u8_INT1
			 3-EXTI_u8_INT2
			 
			 2)call back function to the required address of application ISR function 
    outputs: Error Status	
*/
ErrorStatus EXTI_errSetCallBack(u8 Copy_u8IntIdx,void(*Copy_pvCallBack)(void));



void EXTI_VoidEnableGlobal(void);
void EXTI_VoidDisableGlobal(void);








/*void EXTI_VoidINT0Init(void);
void EXTI_VoidINT1Init(void);
void EXTI_VoidEnableGlobal(void);*/

#endif
