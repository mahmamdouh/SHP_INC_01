#include "avr/io.h"
#include"avr/delay.h"
#include "Bit_Math.h"
#include "Std_Types.h"
#include "Keypad_Init.h"
#include "DIO_int.h"
#include "Keypad_Priv.h"
#include "Keypad_Config.h"

const u8 keypad[4][4] = {	{'1','2','3','A'},  // [input sequence]  * [output sequence]
		             		{'4','5','6','B'},
				            {'7','8','9','C'},
				            {'*','0','#','D'}};

u8 index = 1;

void Keypad_Init(void)
{
	// set here input pins if you want
}

u8 Keypad_char (void)
{
	u8 data;
	for(int i=1 ; i<5 ; i++)
	  {
		Out_seqencer(i);
		switch(i)
		{
		case 1:
		{
			if(DIO_uint8PinState(Keypad_IN_0)== 1)
			{
				return keypad[0][3];
			}
			else if(DIO_uint8PinState(Keypad_IN_1)== 1)
			{
				return keypad[1][3];
			}
			else if(DIO_uint8PinState(Keypad_IN_2)== 1)
			{
				return keypad[2][3];
			}
			else if(DIO_uint8PinState(Keypad_IN_3)== 1)
			{
				return keypad[3][3];
			}
			break;
		}
		case 2:
		{
			if(DIO_uint8PinState(Keypad_IN_0)== 1)
			{
				return keypad[0][2];
			}
			else if(DIO_uint8PinState(Keypad_IN_1)== 1)
			{
				return keypad[1][2];
			}
			else if(DIO_uint8PinState(Keypad_IN_2)== 1)
			{
				return keypad[2][2];
			}
			else if(DIO_uint8PinState(Keypad_IN_3)== 1)
			{
				return keypad[3][2];
			}
			break;
		}
		case 3:
		{
			if(DIO_uint8PinState(Keypad_IN_0)== 1)
			{
				return keypad[0][1];
			}
			else if(DIO_uint8PinState(Keypad_IN_1)== 1)
			{
				return keypad[1][1];
			}
			else if(DIO_uint8PinState(Keypad_IN_2)== 1)
			{
				return keypad[2][1];
			}
			else if(DIO_uint8PinState(Keypad_IN_3)== 1)
			{
				return keypad[3][1];
			}
			break;
		}
		case 4:
		{
			if(DIO_uint8PinState(Keypad_IN_0)== 1)
			{
				return keypad[0][0];
			}
			else if(DIO_uint8PinState(Keypad_IN_1)== 1)
			{
				return keypad[1][0];
			}
			else if(DIO_uint8PinState(Keypad_IN_2)== 1)
			{
				return keypad[2][0];
			}
			else if(DIO_uint8PinState(Keypad_IN_3)== 1)
			{
				return keypad[3][0];
			}
			break;
		}
		default:
		{

			break;
		}
		}

	  }
	return ;
}

static void Out_seqencer(u8 index)
{
	switch(index)
	{
	case 1:
	{
		/// change to zero ones
	DIO_voidWriteOnPin(Keypad_OUT_0,1);
	DIO_voidWriteOnPin(Keypad_OUT_1,0);
	DIO_voidWriteOnPin(Keypad_OUT_2,0);
	DIO_voidWriteOnPin(Keypad_OUT_3,0);
	break;
	}
	case 2:
	{
	DIO_voidWriteOnPin(Keypad_OUT_0,0);
	DIO_voidWriteOnPin(Keypad_OUT_1,1);
	DIO_voidWriteOnPin(Keypad_OUT_2,0);
	DIO_voidWriteOnPin(Keypad_OUT_3,0);
	break;
	}
	case 3:
	{
	DIO_voidWriteOnPin(Keypad_OUT_0,0);
	DIO_voidWriteOnPin(Keypad_OUT_1,0);
	DIO_voidWriteOnPin(Keypad_OUT_2,1);
	DIO_voidWriteOnPin(Keypad_OUT_3,0);
	break;
	}
	case 4:
	{
	DIO_voidWriteOnPin(Keypad_OUT_0,0);
	DIO_voidWriteOnPin(Keypad_OUT_1,0);
	DIO_voidWriteOnPin(Keypad_OUT_2,0);
	DIO_voidWriteOnPin(Keypad_OUT_3,1);
	break;
	}
	default: break;
	}
}
