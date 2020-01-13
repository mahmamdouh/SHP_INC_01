/*
 * SWITCH_Prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: 2013
 */
#include "avr/io.h"
#include"avr/delay.h"
#include "Bit_Math.h"

#include "Std_Types.h"
#include "DIO_int.h"
#include"SWITCH_Priv.h"
#include"SWITHCH_Config.h"
#include "SWITCH_INIT.h"
//#include "LCD_Int.h"  // for debugging


void Switch_void_Init(void)
{
/*DO NOTHING */
	return ;
}


u8 Switch_Is_Pressed(u8 SwitchNum)
{
	switch (SwitchNum)
	{
	case SWITCH_0:
	{
	  #if(SWITCH0_MODE == PULL_UP)
	  {
		  if(DIO_uint8PinState(SWITCH0_PIN)==HIGH)
		  {
			 return IS_PRESSED ;
		  }
		  else
		  {
			 return IS_NOT_PRESSED ;
		  }
	  }
	  #elif (SWITCH0_MODE == PULL_DOWN)
	  {
		  if(DIO_uint8PinState(SWITCH0_PIN)==HIGH)
		  {
			  return IS_NOT_PRESSED ;
		  }
		  else
		  {
			  return IS_PRESSED ;
		  }
	  }

	  #else
	  {#error "wrong mode"}
      #endif
	 break ;
	}


	case SWITCH_1:
	{
	  #if(SWITCH1_MODE == PULL_UP)
	  {
		  if(DIO_uint8PinState(SWITCH1_PIN)==HIGH)
		  {
			  return IS_PRESSED ;
		  }
		  else
		  {
			  return IS_NOT_PRESSED ;
		  }
	  }
	 #elif (SWITCH1_MODE == PULL_DOWN)
	  {
		  if(DIO_uint8PinState(SWITCH1_PIN)==HIGH)
		  {
			  return IS_NOT_PRESSED ;
		  }
		  else
		  {
			  return IS_PRESSED ;
		  }
	  }

	  #else
	  {#error "wrong mode"}
#endif
	 break ;
	}


	case SWITCH_2:
	{
	  #if(SWITCH2_MODE == PULL_UP)
	  {
		  if(DIO_uint8PinState(SWITCH2_PIN)==HIGH)
		  {
			  return IS_PRESSED ;
		  }
		  else
		  {
			  return IS_NOT_PRESSED ;
		  }
	  }
	 #elif (SWITCH2_MODE == PULL_DOWN)
	  {
		  if(DIO_uint8PinState(SWITCH2_PIN)==HIGH)
		  {
			  return IS_NOT_PRESSED ;
		  }
		  else
		  {
			  return IS_PRESSED ;
		  }
	  }

	  #else
	  {#error "wrong mode"}
#endif
	 break ;
	}
	}

}
