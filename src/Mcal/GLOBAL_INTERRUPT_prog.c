/* GLOBAL_INTERRUPT_prog.c */
#include "avr/io.h"
#include"avr/delay.h"
#include "Bit_Math.h"
#include "Std_Types.h"


void global_Interrupt_init(void)
{
	/* DO NOTHING */
}

void global_Interrupt_EN(void)
{
   	set_bit(SREG,7);
}

void global_Interrupt_DES(void)
{
	clear_bit(SREG,7);
}
	
