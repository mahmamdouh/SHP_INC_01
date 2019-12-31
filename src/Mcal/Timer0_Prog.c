/* "Timer0_Prog.c"
* Timer Driver 
* developed By : Mahmoud Elmohtady
*/
#include "avr/io.h"
#include "std_types.h"
#include "Bit_Math.h"
#include "util/delay.h"
#include "DIO_Int.h"
#include "Timer0_Privt.h"
#include "Timer0_Confg.h"
#include "Timer0_Init.h"


static volatile void (*pf) (void);


void Timer0_Init(void)
{
	TCCR0=0b00000000;
	Timer0_Interrupt_Desable_OCR();
	Timer0_Interrupt_Desable_OV();
	set_mode();
	set_prescaller();

}

void Timer0_start(void);

//####################################################################
void Timer0_set_CallBack(void (*p) (void))
{
	pf=p;
}

//###########################################################################
#if(TIMER0_MODE== OUTPUT_COMPARE)
void Timer0_Interrupt_Enable_OCR(void)
{
	set_bit(TIMSK,1);  // enable bit OCIE0
	clear_bit(TIMSK,0);// disable bit TOIE0
}

void Timer0_Interrupt_Desable_OCR(void)
{
	clear_bit(TIMSK,1); // disable bit OCIE0
}
#endif
//###########################################################################

#if(TIMER0_MODE== NORMAL_MODE)
void Timer0_Interrupt_Enable_OV(void)
{
	set_bit(TIMSK,0);   // disable bit TOIE0
	clear_bit(TIMSK,1); // enable bit OCIE0
}

void Timer0_Interrupt_Desable_OV(void)
{
	clear_bit(TIMSK,0);// disable bit TOIE0
}
#endif
void Set_counter_Timer0(u8 time)
{
#if(TIMER0_MODE== OUTPUT_COMPARE)
	{OCR0=time ;}

#elif(TIMER0_MODE== NORMAL_MODE)
	{TCNT0=time ;}

#elif(TIMER0_MODE== PWN_PHASE_CORRECT)
	{OCR0=time;}

#elif(TIMER0_MODE== PWM_FAST)
	{OCR0=time;}

#endif
}

//##############################################################################
static void set_prescaller(void)
{
 #if(PRESCALLER == PRE_1024)
	{
		set_bit(TCCR0,0);
		set_bit(TCCR0,2);
		clear_bit(TCCR0,1);
	}
#elif(PRESCALLER == PRE_256)
	{
		set_bit(TCCR0,2);
		clear_bit(TCCR0,0);
		clear_bit(TCCR0,1);
	}
#elif(PRESCALLER == PRE_64)
	{
		set_bit(TCCR0,0);
		set_bit(TCCR0,1);
		clear_bit(TCCR0,2);
	}
#elif(PRESCALLER == PRE_8)
	{
		set_bit(TCCR0,1);
		clear_bit(TCCR0,0);
		clear_bit(TCCR0,2);
	}
#elif(PRESCALLER == NO_PRES)
	{
		set_bit(TCCR0,0);
		clear_bit(TCCR0,2);
		clear_bit(TCCR0,1);
	}
#else {#error "wrong!"}

#endif

}


//##########################################################
#if(TIMER0_MODE== NORMAL_MODE)
// timer 0 overflow
void __vector_11 (void) __attribute__ ((signal,used)) ;
void __vector_11 (void)
{
	pf();
}
#endif

#if(TIMER0_MODE== OUTPUT_COMPARE)
// timer 0 compared
void __vector_10 (void) __attribute__ ((signal,used)) ;
void __vector_10 (void){
	pf();
}

#endif


//##################################################3
static void set_mode(void)
{
#if(TIMER0_MODE== NORMAL_MODE)
	clear_bit(TCCR0,3);
	clear_bit(TCCR0,6);
#elif(TIMER0_MODE== OUTPUT_COMPARE)
	set_bit(TCCR0,3);
	clear_bit(TCCR0,6);

#elif(TIMER0_MODE== PWM_FAST)
	set_bit(TCCR0,3);
	set_bit(TCCR0,6);

#elif(TIMER0_MODE== PWN_PHASE_CORRECT)
	clear_bit(TCCR0,3);
	set_bit(TCCR0,6);
#endif
}


