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
#include "ADC_Init.h"

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

// ADC0 conversion prototype
u8 ADC0_5volt_conversion(u8 data);
u8 ADC_result0=0 ;
int main(void){
	// initialization
	global_Interrupt_DES();
	// DIO init
	DIO_voidInitialize();
	// EXT interrrupt init
	EXT_INTERRUPT0_INIT();
	EXT_INTERRUPT0_EN();
	// timer0 init
	/*
	Timer0_Init();
	Timer0_Interrupt_Enable_OV();
	Timer0_set_CallBack(ISR_Timer0);                  // callback of timer
	EXT_INTERRUPT0_SetCallBack(ISR_INT0);             // call back of EXT interrupt
	*/
	// LCD init
	LCD_voidInitialize();
	LCD_voidSetCursor(1,1);
    //ADC int
	ACD_void_init();
	ADC_interrupt_enable();
	ADC_enable();
	global_Interrupt_EN();
	// LCD INIT PRINT
	//LCD_voidPrint("Hello Mahmoud!");
	//Timer0_start();

	while(1)
	{
		LCD_voidPrint("Hello in main !");
		ADC_StartConversion(ADC_0);
		ADC_result0 = ADC0_5volt_conversion(ACD_Result(ADC_0));
		if(ADC_result0 == 5)
		LCD_voidPrint("Volt equal 5:");
		else if(ADC_result0 < 5 && ADC_result0 > 3)
			LCD_voidPrint("Volt between 5 and 3:");
		else if(ADC_result0 < 3 && ADC_result0 > 1)
			LCD_voidPrint("Volt between 3 and 1:");
		else if(ADC_result0 < 1)
			LCD_voidPrint("Volt less than 1:");

		_delay_ms(100);
		LCD_voidSetCursor(1,1);
		LCD_voidClearDisplay();
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


u8 ADC0_5volt_conversion(u8 data)
{
	return ((data*5)/255) ;
}
