/* EXT_INTERRUPT_Init.h */


/* EXT_INTERRUPT_Init.h */
/* intrrupt driver for Interrupt 0 */

void EXT_INTERRUPT0_INIT(void);

void EXT_INTERRUPT0_EN(void);

void EXT_INTERRUPT0_DES(void);

void EXT_INTERRUPT0_SetCallBack(void (*p) (void));

//void __vector_1(void) __attribute__((signal, used));

