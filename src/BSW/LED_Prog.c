


#include "avr/io.h"
#include"avr/delay.h"
#include "Bit_Math.h"
#include "Std_Types.h"
#include "DIO_int.h"
//#include"LED_Priv.h"
#include"LED_Config.h"
#include "LED_INIT.h"
#include "LCD_Int.h"  // for debugging



void LED_void_Init(void)
{
/*DO NOTHING */
	return ;
}

void LED_OUT(u8 LED_PIN , u8 value)
{
 	switch (LED_PIN)
	{
	case LED_0:
	{
	  #if(LED0_MODE == FORWARD)
	  {
		  if(value == HIGH)
        {DIO_voidWriteOnPin(LED0_PIN,HIGH);}
		  else if(value == LOW)
		  {  DIO_voidWriteOnPin(LED0_PIN,LOW);}
	  }
	  #elif (LED0_MODE == REVERSE))
	  {
		  if(value == HIGH)
        {DIO_voidWriteOnPin(LED0_PIN,LOW);}
		  else if(value == LOW)
		  {  DIO_voidWriteOnPin(LED0_PIN,HIGH);}
	  }

	  #else
	  {#error "wrong mode"}
      #endif
	 break ;
	}
     
     	case LED_1:
	{
	  #if(LED1_MODE == FORWARD)
	  {
		  if(value == HIGH)
        {DIO_voidWriteOnPin(LED1_PIN,HIGH);}
		  else if(value == LOW)
		  {  DIO_voidWriteOnPin(LED1_PIN,LOW);}
	  }
	  #elif (LED1_MODE == REVERSE))
	  {
		  if(value == HIGH)
        {DIO_voidWriteOnPin(LED1_PIN,LOW);}
		  else if(value == LOW)
		  {  DIO_voidWriteOnPin(LED1_PIN,HIGH);}
	  }

	  #else
	  {#error "wrong mode"}
      #endif
	 break ;
	}
	
		case LED_2:
	{
	  #if(LED2_MODE == FORWARD)
	  {
		  if(value == HIGH)
        {DIO_voidWriteOnPin(LED2_PIN,HIGH);}
		  else if(value == LOW)
		  {  DIO_voidWriteOnPin(LED2_PIN,LOW);}
	  }
	  #elif (LED2_MODE == REVERSE))
	  {
		  if(value == HIGH)
        {DIO_voidWriteOnPin(LED2_PIN,LOW);}
		  else if(value == LOW)
		  {  DIO_voidWriteOnPin(LED2_PIN,HIGH);}
	  }

	  #else
	  {#error "wrong mode"}
      #endif
	 break ;
	}
	 
	}
 	return;
}
