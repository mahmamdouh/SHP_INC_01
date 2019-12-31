#include "std_types.h"
#include "Bit_Math.h"
#include "avr/io.h"
#include "DIO_Int.h"
#include "LCD_Int.h"
#include "Uart_init.h"


int main(void){

	DIO_voidInitialize();
	LCD_voidInitialize();
	LCD_voidSetCursor(1,1);
	LCD_voidPrint("Hello world!");
//DIO_voidSetPin(DIO_PIN_9);
	UART_voidInit();

	while(1)
	{
		UART_voidSend(UART_voidReceive());
	}

	return 0;
}
