#include "std_types.h"
#include "Bit_Math.h"
#include "avr/io.h"
#include "DIO_Int.h"
#include "LCD_Int.h"
#include "SPI_Init.h"
#include "LED_Init.h"


int main(void){

	DIO_voidInitialize();
	LCD_voidInitialize();
	LCD_voidSetCursor(1,1);
	LCD_voidPrint("Hello world!");
//DIO_voidSetPin(DIO_PIN_9);
	//UART_voidInit();
	SPI_Init();
u8  rece ;
	while(1)
	{
		//SPI_Select_Slave(SEL_SLAVE_0);
		rece = SPI_SLAVE_Receive();
		if (rece =='a' )
		{
			LED_OUT(LED_0,1);
		}
	}

	return 0;
}
