/*
 * Prog.c
 *
 *  Created on: May 18, 2019
 *      Author: salsa
 */
#include "std_types.h"
#include "Bit_Math.h"
#include "util/delay.h"
#include "DIO_Int.h"
#include "LCD_priv.h"
#include "LCD_Config.h"
#include "LCD_Int.h"

void LCD_voidWriteCommand(u8 command){
#if (OPERATING_MODE == FOUR_BITS_OPERATING_MODE)
DIO_voidWriteOnPin(LCD_PIN_D7,CHECK_BIT(command,7));
DIO_voidWriteOnPin(LCD_PIN_D6,CHECK_BIT(command,6));
DIO_voidWriteOnPin(LCD_PIN_D5,CHECK_BIT(command,5));
DIO_voidWriteOnPin(LCD_PIN_D4,CHECK_BIT(command,4));


DIO_voidWriteOnPin(LCD_PIN_RW,DIO_LOW);
DIO_voidWriteOnPin(LCD_PIN_E,DIO_HIGH);
_delay_ms(2);
DIO_voidWriteOnPin(LCD_PIN_E,DIO_LOW);
_delay_ms(2);
DIO_voidWriteOnPin(LCD_PIN_D7,CHECK_BIT(command,3));
DIO_voidWriteOnPin(LCD_PIN_D6,CHECK_BIT(command,2));
DIO_voidWriteOnPin(LCD_PIN_D5,CHECK_BIT(command,1));
DIO_voidWriteOnPin(LCD_PIN_D4,CHECK_BIT(command,0));

DIO_voidWriteOnPin(LCD_PIN_E,DIO_HIGH);
_delay_ms(1);
DIO_voidWriteOnPin(LCD_PIN_E,DIO_LOW);
_delay_ms(2);

#elif (OPERATING_MODE == EIGHT_BITS_OPERATING_MODE)
DIO_voidWriteOnPin(LCD_PIN_D7,CHECK_BIT(command,7));
DIO_voidWriteOnPin(LCD_PIN_D6,CHECK_BIT(command,6));
DIO_voidWriteOnPin(LCD_PIN_D5,CHECK_BIT(command,5));
DIO_voidWriteOnPin(LCD_PIN_D4,CHECK_BIT(command,4));
DIO_voidWriteOnPin(LCD_PIN_D3,CHECK_BIT(command,3));
DIO_voidWriteOnPin(LCD_PIN_D2,CHECK_BIT(command,2));
DIO_voidWriteOnPin(LCD_PIN_D1,CHECK_BIT(command,1));
DIO_voidWriteOnPin(LCD_PIN_D0,CHECK_BIT(command,0));

DIO_voidWriteOnBit(LCD_PIN_RS,DIO_LOW);
DIO_voidWriteOnBit(LCD_PIN_RW,DIO_LOW);
DIO_voidWriteOnPin(LCD_PIN_E,DIO_HIGH);
_delay_us(1);
DIO_voidWriteOnPin(LCD_PIN_E,DIO_LOW);
_delay_ms(2);
#endif
}
void LCD_voidWriteData(u8 data){
#if (OPERATING_MODE == FOUR_BITS_OPERATING_MODE)
DIO_voidWriteOnPin(LCD_PIN_RS, DIO_HIGH);

DIO_voidWriteOnPin(LCD_PIN_D7,CHECK_BIT(data,7));
DIO_voidWriteOnPin(LCD_PIN_D6,CHECK_BIT(data,6));
DIO_voidWriteOnPin(LCD_PIN_D5,CHECK_BIT(data,5));
DIO_voidWriteOnPin(LCD_PIN_D4,CHECK_BIT(data,4));

DIO_voidWriteOnPin(LCD_PIN_RS,DIO_HIGH);
DIO_voidWriteOnPin(LCD_PIN_RW,DIO_LOW);
DIO_voidWriteOnPin(LCD_PIN_E,DIO_HIGH);
_delay_ms(2);
DIO_voidWriteOnPin(LCD_PIN_E,DIO_LOW);
_delay_ms(2);
DIO_voidWriteOnPin(LCD_PIN_D7,CHECK_BIT(data,3));
DIO_voidWriteOnPin(LCD_PIN_D6,CHECK_BIT(data,2));
DIO_voidWriteOnPin(LCD_PIN_D5,CHECK_BIT(data,1));
DIO_voidWriteOnPin(LCD_PIN_D4,CHECK_BIT(data,0));

DIO_voidWriteOnPin(LCD_PIN_E,DIO_HIGH);
_delay_ms(2);
DIO_voidWriteOnPin(LCD_PIN_E,DIO_LOW);
_delay_ms(2);

#elif (OPERATING_MODE == EIGHT_BITS_OPERATING_MODE)
DIO_voidWriteOnPin(LCD_PIN_D7,CHECK_BIT(data,7));
DIO_voidWriteOnPin(LCD_PIN_D6,CHECK_BIT(data,6));
DIO_voidWriteOnPin(LCD_PIN_D5,CHECK_BIT(data,5));
DIO_voidWriteOnPin(LCD_PIN_D4,CHECK_BIT(data,4));
DIO_voidWriteOnPin(LCD_PIN_D3,CHECK_BIT(data,3));
DIO_voidWriteOnPin(LCD_PIN_D2,CHECK_BIT(data,2));
DIO_voidWriteOnPin(LCD_PIN_D1,CHECK_BIT(data,1));
DIO_voidWriteOnPin(LCD_PIN_D0,CHECK_BIT(data,0));

DIO_voidWriteOnPin(LCD_PIN_RS,DIO_HIGH);
DIO_voidWriteOnPin(LCD_PIN_RW,DIO_LOW);
DIO_voidWriteOnPin(LCD_PIN_RS,DIO_HIGH);
_delay_us(1);
DIO_voidWriteOnPin(LCD_PIN_E,DIO_LOW);
_delay_us(100);
#endif
}
void LCD_voidInitialize(void){
#if (OPERATING_MODE == FOUR_BITS_OPERATING_MODE)
/*
	DIO_voidWriteOnPin(LCD_PIN_E,DIO_HIGH);
	_delay_ms(1);
	LCD_voidWriteCommand(0x28);
	LCD_voidWriteCommand(0x0E);
	LCD_voidWriteCommand(0x01);
	_delay_ms(2);
	LCD_voidWriteCommand(0x06);
	_delay_us(100);
*/
	LCD_voidWriteCommand(0x03);
		_delay_ms(2);
		LCD_voidWriteCommand(0x03);
		_delay_ms(11);
		LCD_voidWriteCommand(0x03);
		LCD_voidWriteCommand(0x02);
		LCD_voidWriteCommand(0x08);
		LCD_voidWriteCommand(0x00);
		LCD_voidWriteCommand(0x0C); //cursor blinking put it D
		LCD_voidWriteCommand(0x01);
		_delay_ms(2);
		LCD_voidWriteCommand(0x00);
		LCD_voidWriteCommand(0x06);
#elif (OPERATING_MODE== EIGHT_BITS_OPERATING_MODE)
	DIO_voidWriteOnPin(LCD_PIN_E,DIO_HIGH);
		_delay_ms(1);
		LCD_voidWriteCommand(0x38);
		LCD_voidWriteCommand(0x0E);
		LCD_voidWriteCommand(0x01);
		_delay_ms(2);
		LCD_voidWriteCommand(0x06);
		_delay_us(100);
	#endif
}

void LCD_voidSetCursor(u8 rows,u8 columns){
	u8 Starting_line_position[] ={0x80,0xC0,0x94 ,0xD4};
	   LCD_voidWriteCommand(Starting_line_position[columns-1]+rows-1);
	   _delay_us(100);
}
void LCD_voidPrint(u8 * string){
		/*if (sizeof(*string) == sizeof(u8)||sizeof(*string) == sizeof(u16))
		{
			while(*string !=0)
			{

				LCD_voidWriteData()
			}
		}*/
	   for (u8 i=0;string[i] !='\0';i++){
	      LCD_voidWriteData(string[i]);
	   }
}
void LCD_voidClearDisplay(void){
	LCD_voidWriteCommand(0x01);
}
void LCD_voidShiftToLeft(void);
void LCD_voidShiftToRight(void);
