/* "Timer0_Init.h"
* Timer Driver 
* developed By : Mahmoud Elmohtady
*/

void Timer0_Init(void);
void Timer0_start(void);
void Timer0_set_CallBack(void (*p) (void));

void Timer0_Interrupt_Enable_OCR(void);
void Timer0_Interrupt_Enable_OV(void);

void Timer0_Interrupt_Desable_OCR(void);
void Timer0_Interrupt_Desable_OV(void);

void Set_counter_Timer0(u8 time);


