#include "std_types.h"
#include "avr/delay.h"
#include "Bit_Math.h"
#include "avr/io.h"
#include "DIO_Int.h"
#include "LCD_Int.h"
#include "LED_INIT.h"
#include "SWITCH_INIT.h"
#include "GLOBAL_INTERRUPT_Init.h"
#include "EXT_INTERRUPT_Init.h"

// LED flag
u8 LED_FLAG=0 ;

void ISR_INT0(void);

int main(void){
	// initialization
	global_Interrupt_DES();
	DIO_voidInitialize();
	EXT_INTERRUPT0_INIT();
	EXT_INTERRUPT0_EN();
	EXT_INTERRUPT0_SetCallBack(ISR_INT0);
	global_Interrupt_EN();
	LCD_voidInitialize();
	LCD_voidSetCursor(1,1);

	// LCD INIT PRINT
	LCD_voidPrint("Hello world!");

	while(1)
	{

		if(Switch_Is_Pressed(SWITCH_0) == IS_PRESSED)
		{
			//LCD_voidPrint("Hello in if pressed");
			LED_OUT(LED_0,HIGH);
		}
		else if (Switch_Is_Pressed(SWITCH_0) == IS_NOT_PRESSED)
		{
			//LCD_voidPrint("Hello in else ");
			LED_OUT(LED_0,LOW);

		}

	}


	return 0;
}


void ISR_INT0(void)
{
	LCD_voidPrint("Hello IN ISR!");
	if(LED_FLAG == 0)
	{
		//LCD_voidPrint("Hello in if pressed");
		LED_OUT(LED_2,HIGH);
		LED_FLAG= 1;
	}
	else if (LED_FLAG == 1)
	{
		//LCD_voidPrint("Hello in else ");
		LED_OUT(LED_2,LOW);
		LED_FLAG= 0;

	}
}
