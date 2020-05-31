#include "std_types.h"
#include "bits.h"
#include "EXTI_CONFIG.h"
#include "EXTI_INTERFACE.h"
#include "EXTI_REGISTERS.h"
#include "EXTI_CONFIG.h"
#include "EXTI_PRIVATE.h"



//3 ISR ,, Global pointer to function to hold the call back address function
static void (*EXTI_pvCallVack[3]) (void) ={NULL , NULL,NULL};



void EXTI_voidInit(void)
{
	#if EXTI_u8_INT0_Control == ENABLED
	 SET_BIT(GICR,GICR_INT0);
	#elif EXTI_u8_INT0_Control == DISABLED 
	 CLR_BIT(GICR,GICR_INT0);
	#else
	#error "Wrong EXTI_u8_INT0_Control Configration"
    #endif
	
	
	#if EXTI_u8_INT1_Control == ENABLED
	 SET_BIT(GICR,GICR_INT1);
	#elif EXTI_u8_INT1_Control == DISABLED 
	 CLR_BIT(GICR,GICR_INT1);
	#else
	#error "Wrong EXTI_u8_INT1_Control Configration"
    #endif
	
	#if EXTI_u8_INT2_Control == ENABLED
	 SET_BIT(GICR,GICR_INT2);
	#elif EXTI_u8_INT2_Control == DISABLED 
	 CLR_BIT(GICR,GICR_INT2);
	#else
	#error "Wrong EXTI_u8_INT2_Control Configration"
    #endif
	
	#if EXTI_u8_INT0_SENSE == LOW_LEVEL
	  CLR_BIT(MCUCR,MCUCR_ISC00);
	  CLR_BIT(MCUCR,MCUCR_ISC01);
	  
	#elif EXTI_u8_INT0_SENSE == ON_CHANGE
	  SET_BIT(MCUCR,MCUCR_ISC00);
	  CLR_BIT(MCUCR,MCUCR_ISC01);

	#elif EXTI_u8_INT0_SENSE == FALLING_EDGE
	  CLR_BIT(MCUCR,MCUCR_ISC00);
	  SET_BIT(MCUCR,MCUCR_ISC01);

	#elif EXTI_u8_INT0_SENSE == RISING_EDGE
	  SET_BIT(MCUCR,MCUCR_ISC00);
	  SET_BIT(MCUCR,MCUCR_ISC01);	
    #else 
    #error "Wrong EXTI_u8_INT0_SENSE Configration"	
#endif

	#if EXTI_u8_INT1_SENSE == LOW_LEVEL
	  CLR_BIT(MCUCR,MCUCR_ISC10);
	  CLR_BIT(MCUCR,MCUCR_ISC11);
	  
	#elif EXTI_u8_INT1_SENSE == ON_CHANGE
	  SET_BIT(MCUCR,MCUCR_ISC10);
	  CLR_BIT(MCUCR,MCUCR_ISC11);

	#elif EXTI_u8_INT1_SENSE == FALLING_EDGE
	  CLR_BIT(MCUCR,MCUCR_ISC10);
	  SET_BIT(MCUCR,MCUCR_ISC11);

	#elif EXTI_u8_INT1_SENSE == RISING_EDGE
	  SET_BIT(MCUCR,MCUCR_ISC10);
	  SET_BIT(MCUCR,MCUCR_ISC11);	
    #else 
    #error "Wrong EXTI_u8_INT1_SENSE Configration"
#endif

	#if EXTI_u8_INT2_SENSE == FALLING_EDGE
	  CLR_BIT(MCUCSR,MCUCSR_ISC2);

	#elif EXTI_u8_INT2_SENSE == RISING_EDGE
	  SET_BIT(MCUCSR,MCUCR_ISC2);  	
    #else 
    #error "Wrong EXTI_u8_INT2_SENSE Configration"
#endif

}

ErrorStatus EXTI_errEnable(u8 Copy_u8IntIdx)
{
	ErrorStatus LocalError = OK;
	switch(Copy_u8IntIdx)
	{
		
		case EXTI_u8_INT0:
		      SET_BIT(GICR,GICR_INT0);
		      break;
			  
	    case EXTI_u8_INT1:
		      SET_BIT(GICR,GICR_INT1);
		      break;
			  
		case EXTI_u8_INT2:
		      SET_BIT(GICR,GICR_INT2);
		      break;
			  
		default: LocalError= NOK;
              break;		
	}
	return LocalError;
	
}
ErrorStatus EXTI_errDisable(u8 Copy_u8IntIdx)
{
	
	
	ErrorStatus LocalError = OK;
	switch(Copy_u8IntIdx)
	{
		
		case EXTI_u8_INT0:
		      CLR_BIT(GICR,GICR_INT0);
		      break;
			  
	    case EXTI_u8_INT1:
		      CLR_BIT(GICR,GICR_INT1);
		      break;
			  
		case EXTI_u8_INT2:
		      CLR_BIT(GICR,GICR_INT2);
		      break;
			  
		default: LocalError= NOK;
              break;		
	}
	return LocalError;
}

ErrorStatus EXTI_errSetSense(u8 Copy_u8IntIdx,u8 Copy_u8SensLevel)
{
	ErrorStatus LocalError = OK;
	switch(Copy_u8IntIdx)
	{
		case EXTI_u8_INT0:
		   if(Copy_u8SensLevel == EXTI_u8_LOW_LEVEL)
		   {
			   CLR_BIT(MCUCR,MCUCR_ISC00);
			   CLR_BIT(MCUCR,MCUCR_ISC01);
		   }
		   else if(Copy_u8SensLevel == EXTI_u8_ON_CHANGE)
		   {
			   SET_BIT(MCUCR,MCUCR_ISC00);
			   CLR_BIT(MCUCR,MCUCR_ISC01);   
		   }
		   else if(Copy_u8SensLevel == EXTI_u8_FALLING_EDGE)
		   {
			   CLR_BIT(MCUCR,MCUCR_ISC00);
			   SET_BIT(MCUCR,MCUCR_ISC01); 
		   }
		   else if(Copy_u8SensLevel == EXTI_u8_RISING_EDGE)
		   {
			   SET_BIT(MCUCR,MCUCR_ISC00);
			   SET_BIT(MCUCR,MCUCR_ISC01);
		   }
		   else
		   {
			  LocalError=NOK; 
		   }
	   
		   break;
		   
		case EXTI_u8_INT1:
		if(Copy_u8SensLevel == EXTI_u8_LOW_LEVEL)
		   {
			   CLR_BIT(MCUCR,MCUCR_ISC10);
			   CLR_BIT(MCUCR,MCUCR_ISC11);
		   }
		   else if(Copy_u8SensLevel == EXTI_u8_ON_CHANGE)
		   {
			   SET_BIT(MCUCR,MCUCR_ISC10);
			   CLR_BIT(MCUCR,MCUCR_ISC11);   
		   }
		   else if(Copy_u8SensLevel == EXTI_u8_FALLING_EDGE)
		   {
			   CLR_BIT(MCUCR,MCUCR_ISC10);
			   SET_BIT(MCUCR,MCUCR_ISC11); 
		   }
		   else if(Copy_u8SensLevel == EXTI_u8_RISING_EDGE)
		   {
			   SET_BIT(MCUCR,MCUCR_ISC10);
			   SET_BIT(MCUCR,MCUCR_ISC11);
		   }
		   else
		   {
			  LocalError=NOK; 
		   }
		   break;
		   
		case EXTI_u8_INT2:
		if(Copy_u8SensLevel == EXTI_u8_FALLING_EDGE)
		   {
			   CLR_BIT(MCUCSR,MCUCSR_ISC2);
		   }
		   else if(Copy_u8SensLevel == EXTI_u8_RISING_EDGE)
		   {
			   SET_BIT(MCUCSR,MCUCSR_ISC2);   
		   }
		   else
		   {
			  LocalError=NOK; 
		   }
		   break;
		
		
	}
	
	return LocalError;
	
}



/*a7na 3malna keda 3lshan ana 3aiza akteb el isr fel mcal bs hya bt3ml app 
fa ana hakteb da fel mcal w andah 3aleha fel app*/

ErrorStatus EXTI_errSetCallBack(u8 Copy_u8IntIdx,void(*Copy_pvCallBack)(void))
{
	ErrorStatus LocalError = OK;
	
	if(Copy_pvCallBack != NULL)
	{
		if(Copy_u8IntIdx<3)
		{
			EXTI_pvCallVack[Copy_u8IntIdx]=Copy_pvCallBack;
		}
		else
		{
			LocalError= NOK;
		}
	}
	else
	{
		LocalError= NULLPOINTER;
	}
	
	return LocalError;
	
}


/*ISR OF INT0*/
void __vector_1(void)
{
	if(EXTI_pvCallVack[0] !=NULL)
	{
		EXTI_pvCallVack[0]();
	}
}


/*ISR OF INT1*/
void __vector_2(void)
{
	if(EXTI_pvCallVack[1] !=NULL)
	{
		EXTI_pvCallVack[1]();
	}
}


/*ISR OF INT2*/
void __vector_3(void)
{
	if(EXTI_pvCallVack[2] !=NULL)
	{
		EXTI_pvCallVack[2]();
	}
}

void EXTI_VoidEnableGlobal(void)
{
	SET_BIT(SREG,SREG_I);

}

void EXTI_VoidDisableGlobal(void)
{
	CLR_BIT(SREG,SREG_I);

}

/*
void EXTI_VoidINT0Init(void)
{
	SET_BIT(MCUCR,1);
	CLR_BIT(MCUCR,0);
	SET_BIT(GICR,6);

}*/

/*
void EXTI_VoidINT1Init(void)
{
	SET_BIT(MCUCR,3);
	CLR_BIT(MCUCR,2);
	SET_BIT(GICR,7);

}*/

/*
void EXTI_VoidEnableGlobal(void)
{
	SET_BIT(SREG,7);

}*/
