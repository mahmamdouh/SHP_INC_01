#include "std_types.h"
#include"avr/delay.h"
#include "Bit_Math.h"
#include "avr/io.h"
#include "DIO_Int.h"
#include "LCD_Int.h"
#include "LED_INIT.h"
#include "SWITCH_INIT.h"

int main(void){
	// initialization
	DIO_voidInitialize();
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
