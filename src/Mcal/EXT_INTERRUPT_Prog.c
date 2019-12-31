/* EXT_INTERRUPT_Prog.c */
#include "avr/io.h"
#include"avr/delay.h"
#include "Bit_Math.h"
#include "Std_Types.h"
#include"EXT_INTERRUPT_Config.h"
#include "EXT_INTERRUPT_Init.h"
#include"EXT_INTERRUPT_Priv.h"
#include "DIO_int.h"


static volatile void (*pf) (void) ;

void EXT_INTERRUPT0_INIT(void)
{
	EXT_INTERRUPT0_DES();
	EXT_I_SET_MODE();
}
/*#########################################################*/
void EXT_INTERRUPT0_EN(void)
{
	set_bit(GICR,6);
}
/*#########################################################*/
void EXT_INTERRUPT0_DES(void)
{
	clear_bit(GICR,6);
}

/*#########################################################*/
void EXT_INTERRUPT0_SetCallBack(void (*p) (void))
{
	pf=p;
}
/*##########################################################*/
void __vector_1(void) __attribute__ ((signal,used)) ;
void __vector_1(void)
{
	pf();

}
/*##########################################################*/
static void EXT_I_SET_MODE(void)
{
	#if (INTERRUPT0_SENCE_MODE == RISING_EDGE)
	{
		set_bit(MCUCR,1);
		set_bit(MCUCR,0);



	}
	#elif (INTERRUPT0_SENCE_MODE == FALLING_EDGE)
	{
	    set_bit(MCUCR,1);
        clear_bit(MCUCR,0);		
	}
    #elif (INTERRUPT0_SENCE_MODE == ON_CHANGE)
	{
	    set_bit(MCUCR,0);
        clear_bit(MCUCR,1);		
	}
	#elif (INTERRUPT0_SENCE_MODE == LOW_LEVEL)
	{
	    clear_bit(MCUCR,1);
        clear_bit(MCUCR,0);	
	}
	#else {#error "wrong mode" }
	#endif
}
