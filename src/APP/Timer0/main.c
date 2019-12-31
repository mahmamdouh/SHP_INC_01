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
#include "Timer0_Init.h"

// LED flag
u8 LED_FLAG=0 ;
// timer counter
/*i am using per 1024 sot Ttic  64 microsecone
 * when i need to ferform 64 ms so i need to count 1000 time
 */
u16 TIMER_COUNTER =0 ;
// external interrupt ISR
void ISR_INT0(void);

// TIMER0 interrupt ISR
void ISR_Timer0(void);
int main(void){
	// initialization
	global_Interrupt_DES();
	DIO_voidInitialize();
	EXT_INTERRUPT0_INIT();
	EXT_INTERRUPT0_EN();
	Timer0_Init();
	Timer0_Interrupt_Enable_OV();
	Timer0_set_CallBack(ISR_Timer0);
	EXT_INTERRUPT0_SetCallBack(ISR_INT0);
	global_Interrupt_EN();
	LCD_voidInitialize();
	LCD_voidSetCursor(1,1);

	// LCD INIT PRINT
	LCD_voidPrint("Hello world!");
	//Timer0_start();
	while(1)
	{
            // len off of timer
		LED_OUT(LED_2,LOW);
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
	LCD_voidClearDisplay();
	LCD_voidSetCursor(1,1);
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

void ISR_Timer0(void)
{

	LED_OUT(LED_2,HIGH);
	TIMER_COUNTER++;
	if(TIMER_COUNTER == 66)
	{
		//LCD_voidPrint("Hello in if pressed");
		LED_OUT(LED_2,HIGH);
		LED_FLAG= 1;

		LCD_voidPrint("1 second !");
		TIMER_COUNTER =0;
	}

}
