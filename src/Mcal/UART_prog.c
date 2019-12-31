#include "Std_Types.h"
#include "Bit_Math.h"
#include "UART_Reg.h"
#include "UART_priv.h"
#include "UART_config.h"
#include "UART_init.h"

void UART_voidInit(void)
{
	u8 Local_u8UCSRC = 0x80;
	UBRRL=BR;
	UCSRA=0;
	UCSRB=0;

	#if DOUBLE_UART_RATE==ENABLE
		SET_BIT(UCSRA,U2X);
	#endif

	/*choose UCSRC to write on it*/

		set_bit(Local_u8UCSRC,URSEL);
	UCSRC |= (PARITY_SELECT<<UPM1);

	#if NUM_OF_STOP_BITS==STOP_2
	set_bit(Local_u8UCSRC,USBS);
	#endif
	#if OP_MODE==Synch_OP
	set_bit(Local_u8UCSRC,UMSEL);
	#endif

	#if CHAR_SIZE==CHAR_SIZE_6
	set_bit(Local_u8UCSRC,UCSZ0);
	#elif CHAR_SIZE==CHAR_SIZE_7
	set_bit(Local_u8UCSRC,UCSZ1);
	#elif CHAR_SIZE==CHAR_SIZE_8
		set_bit(Local_u8UCSRC,UCSZ1);
		set_bit(Local_u8UCSRC,UCSZ0);
	#elif CHAR_SIZE==CHAR_SIZE_9
		set_bit(Local_u8UCSRC,UCSZ1);
		set_bit(Local_u8UCSRC,UCSZ0);
		set_bit(UCSRB,UCSZ2);
	#endif

	#if	TX_ENABLE==ENABLE
		set_bit(UCSRB,TXEN);
	#endif
	#if RX_ENABLE==ENABLE
		set_bit(UCSRB,RXEN);
	#endif

	UCSRC=Local_u8UCSRC;
}
 
void UART_voidSend(u8 Data)
{
	UDR=Data;
	/*wait until transmission complete*/
	while((red_bit(UCSRA,6))==0);
	/*clear flag as it isn't cleared by HW*/
	set_bit(UCSRA,6);
	return;
}

u8 UART_voidReceive(void)
{
	while((red_bit(UCSRA,7))==0);
	return UDR;
}
