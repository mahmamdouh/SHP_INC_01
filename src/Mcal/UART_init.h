#ifndef _UART_INT_H
#define _UART_INT_H

#include "STD_TYPES.h"

void UART_voidInit(void);
void UART_voidSend(u8 Data);
u8 UART_voidReceive(void);

#endif
