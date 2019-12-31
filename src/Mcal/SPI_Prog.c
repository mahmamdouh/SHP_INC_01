#include "avr/io.h"
#include "std_types.h"
#include "Bit_Math.h"
#include "util/delay.h"
#include "DIO_int.h"
#include "SPI_priv.h"
#include "SPI_Config.h"
#include "SPI_Init.h"



void SPI_Init(void)
{
    // SPI interrupt disable
	clear_bit(SPCR,7);
	// SPI enable
	set_bit(SPCR,6);
	// SPI data order
#if(DATA_ORDER == MSB)
	set_bit(SPCR,5);
#elif(DATA_ORDER == LSB)
	clear_bit(SPCR,5);
#else {#error "wrong data order selection"}
#endif

	// master slave selection
#if(SPI_MODE == MASTER )
	set_bit(SPCR,4);
#elif(SPI_MODE == SLAVE)
	clear_bit(SPCR,4);
#else {#error "wrong data order selection"}
#endif

	// clock polarity -- clock phase
#if(CLK_PHASE == MODE_0)
	clear_bit(SPCR,3);//CPOL
	clear_bit(SPCR,2);//CPHA
#elif(CLK_PHASE == MODE_1)
	clear_bit(SPCR,3);//CPOL
	set_bit(SPCR,2);//CPHA
#elif(CLK_PHASE == MODE_2)
	set_bit(SPCR,3);//CPOL
	clear_bit(SPCR,2);//CPHA
#elif(CLK_PHASE == MODE_3)
	set_bit(SPCR,3);//CPOL
	set_bit(SPCR,2);//CPHA
#else {#error "wrong data order selection"}
#endif


	// clock rate  CLK_RATE FEQ_DIV_4
#if(CLK_RATE == FEQ_DIV_4  )
	clear_bit(SPCR,1);
	clear_bit(SPCR,0);
	clear_bit(SPSR,0);
#elif(CLK_RATE == FEQ_DIV_16)
	set_bit(SPCR,0);
	clear_bit(SPCR,1);
	clear_bit(SPSR,0);
#elif(CLK_RATE == FEQ_DIV_64)
	set_bit(SPCR,1);
	clear_bit(SPCR,0);
	clear_bit(SPSR,0);
#elif(CLK_RATE == FEQ_DIV_128)
	set_bit(SPCR,1);
	set_bit(SPCR,0);
	clear_bit(SPSR,0);
#elif(CLK_RATE == FEQ_DIV_2)
	clear_bit(SPCR,1);
	clear_bit(SPCR,0);
	set_bit(SPSR,0);
#elif(CLK_RATE == FEQ_DIV_8)
	clear_bit(SPCR,1);
	set_bit(SPCR,0);
	set_bit(SPSR,0);
#elif(CLK_RATE == FEQ_DIV_32)
	clear_bit(SPCR,0);
	set_bit(SPCR,1);
	set_bit(SPSR,0);
#else {#error "wrong data order selection"}
#endif
/*	// douple speed mode
#if(SPEED_MODE == DOUBLE_SPEED  )
	set_bit(SPSR,0);
#elif(SPEED_MODE == NORMAL_SPEED)
	clear_bit(SPSR,0);
#else {#error "wrong data order selection"}
#endif
*/

}

u8 SPI_Receive(void)
{
	SPI_Transmit(0xff);
	// Wait for reception complete
	while(!(SPSR & (1<<SPIF)));
	// Return data register
	return SPDR;
}

u8 SPI_SLAVE_Receive(void)
{

	// Wait for reception complete
	while(!(SPSR & (1<<SPIF)));
	// Return data register
	return SPDR;
}
//#########################################################3
void SPI_Transmit(u8 data)
{
	// Start transmission
	SPDR = data;
	// Wait for transmission complete
	while(!(SPSR & (1<<SPIF)));
}


//######################################################3
void SPI_Select_Slave(u8 slave)
{
	switch(slave)
	{
	case 0:
	{
		DIO_voidWriteOnPin(PIN_SLAVE_0,HIGH);
		DIO_voidWriteOnPin(PIN_SLAVE_1,LOW);
		DIO_voidWriteOnPin(PIN_SLAVE_2,LOW);
		DIO_voidWriteOnPin(PIN_SLAVE_3,LOW);
		break;
	}
	case 1:
	{
		DIO_voidWriteOnPin(PIN_SLAVE_0,LOW);
		DIO_voidWriteOnPin(PIN_SLAVE_1,HIGH);
		DIO_voidWriteOnPin(PIN_SLAVE_2,LOW);
		DIO_voidWriteOnPin(PIN_SLAVE_3,LOW);
		break;
	}
	case 2:
	{
		DIO_voidWriteOnPin(PIN_SLAVE_0,LOW);
		DIO_voidWriteOnPin(PIN_SLAVE_1,LOW);
		DIO_voidWriteOnPin(PIN_SLAVE_2,HIGH);
		DIO_voidWriteOnPin(PIN_SLAVE_3,LOW);
		break;
	}
	case 3:
	{
		DIO_voidWriteOnPin(PIN_SLAVE_0,LOW);
		DIO_voidWriteOnPin(PIN_SLAVE_1,LOW);
		DIO_voidWriteOnPin(PIN_SLAVE_2,LOW);
		DIO_voidWriteOnPin(PIN_SLAVE_3,HIGH);
		break;
	}
	}
}
