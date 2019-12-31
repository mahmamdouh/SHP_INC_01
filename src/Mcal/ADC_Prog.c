
#include "avr/io.h"
#include"avr/delay.h"
#include "Bit_Math.h"
#include "Std_Types.h"
#include "ADC_Init.h"
#include "ADC_Priv.h"
#include "ADC_Config.h"


// global variable for ADC results [ array of 8 ]
u8 ADC_index ;
#if (ADC_CONVERSION_RESOLUTION == CONVERSION_8_BIT)

    	u8 ADC_array [8] = {0};

#elif (ADC_CONVERSION_RESOLUTION == CONVERSION_16_BIT)

    	u16 ADC_array [8] = {0};


#else {#error "wrong selection " }
#endif




// Global variable for call back

//static volatile void (*pf) (void) ;

void ACD_void_init()
{
	//adjustment
	set_bit(ADMUX,5);  // left shift

    //set reference
	ADC_refrence_source();

	//reserved bit
	clear_bit(SFIOR,4);

	//ADC_AUTO_TRIGGER_ENABLE
	set_bit(ADCSRA,5);

	// set trigger mode
	ADC_Trigger_mode();

	// set prescaller
	ADC_prescaller();

}

//########################################
static void ADC_Channel(u8 channel)
{
	switch(channel)
	{
	case 0:
	{ // ADC0
		clear_bit(ADMUX,0);
		clear_bit(ADMUX,1);
		clear_bit(ADMUX,2);
		clear_bit(ADMUX,3);
		break ;
	}

	case 1:
	{
		set_bit(ADMUX,0);
		clear_bit(ADMUX,1);
		clear_bit(ADMUX,2);
		clear_bit(ADMUX,3);
		break ;
	}

	case 2:
	{
		set_bit(ADMUX,1);
		clear_bit(ADMUX,0);
		clear_bit(ADMUX,2);
		clear_bit(ADMUX,3);
		break ;
	}

	case 3:
	{
		set_bit(ADMUX,0);
		set_bit(ADMUX,1);
		clear_bit(ADMUX,2);
		clear_bit(ADMUX,3);
		break ;
	}

	case 4:
	{
		set_bit(ADMUX,2);
		clear_bit(ADMUX,0);
		clear_bit(ADMUX,1);
		clear_bit(ADMUX,3);
		break ;
	}

	case 5:
	{
		set_bit(ADMUX,0);
		set_bit(ADMUX,2);
		clear_bit(ADMUX,1);
		clear_bit(ADMUX,3);
		break ;
	}

	case 6:
	{
		set_bit(ADMUX,2);
		set_bit(ADMUX,1);
		clear_bit(ADMUX,0);
		clear_bit(ADMUX,3);
		break ;
	}

	case 7:
	{
		set_bit(ADMUX,2);
		set_bit(ADMUX,1);
		set_bit(ADMUX,0);
		clear_bit(ADMUX,3);
		break ;
	}
	default : break;{}
	}

}

//#######################################3
void ADC_interrupt_enable()
{
	set_bit(ADCSRA,3);
}

void ADC_interrupt_disable()
{
	clear_bit(ADCSRA,3);
}

//########################################


#if (ADC_CONVERSION_RESOLUTION == CONVERSION_8_BIT)

		u8 ACD_Result(u8 channel)
		{
    return ADC_array[channel];
		}

#elif (ADC_CONVERSION_RESOLUTION == CONVERSION_16_BIT)

    	u16 ACD_Result(u8 channel)
    			{
    return ADC_DATA;
    			}

#else {#error "wrong selection " }
#endif




//################################
void ADC_enable(void)
{
	set_bit(ADCSRA,7);
}

//#######################################
void ADC_StartConversion(u8 channel)
{
	ADC_index  = channel;
	ADC_Channel(channel);
	set_bit(ADCSRA,6);
}


//###########################################
/*void ACD_setCallBack(void (*p) (void))
{
	pf=p ;
}
*/
//##############################################
void __vector_17(void) __attribute__ ((signal,used)) ;
void __vector_17(void)
{

	LCD_voidPrint("ADC ISR"); // debugging
#if (ADC_CONVERSION_RESOLUTION == CONVERSION_8_BIT)


		ADC_array[ADC_index]= ADCH ;

#elif (ADC_CONVERSION_RESOLUTION == CONVERSION_16_BIT)


    	ADC_array[ADC_index]= ADC_DATA;

#else {#error "wrong selection " }
#endif
    	clear_bit(ADCSRA,6);
}

//########################################
static void ADC_refrence_source(void)
{
#if ( REFRENCE_SELECTION_BIT == ENTERNAL_REFRENCE_TURN_OFF )

		clear_bit(ADMUX,6);
		clear_bit(ADMUX,7);

#elif (REFRENCE_SELECTION_BIT == AVCC_WITH_EXTERNAL_CAPACITOR)

		set_bit(ADMUX,6);
		clear_bit(ADMUX,7);

#elif(REFRENCE_SELECTION_BIT == INTERNAL_3_3_WITH_EXTERNAL_CAPACITOR)

	set_bit(ADMUX,6);
		set_bit(ADMUX,7);

#else (#error "wrong refrence_selection")

#endif
}


static void ADC_prescaller(void)
{
#if ( ADC_PRESCALLER == PRES_2 )

		set_bit(ADCSRA,0);
		clear_bit(ADCSRA,1);
		clear_bit(ADCSRA,2);

#elif ( ADC_PRESCALLER == PRES_4 )

		set_bit(ADCSRA,1);
		clear_bit(ADCSRA,0);
		clear_bit(ADCSRA,2);

#elif ( ADC_PRESCALLER == PRES_8 )

		set_bit(ADCSRA,1);
		clear_bit(ADCSRA,2);
		set_bit(ADCSRA,0);

#elif ( ADC_PRESCALLER == PRES_16 )

		set_bit(ADCSRA,2);
		clear_bit(ADCSRA,0);
		clear_bit(ADCSRA,1);

#elif ( ADC_PRESCALLER == PRES_32 )

		clear_bit(ADCSRA,1);
		set_bit(ADCSRA,2);
		set_bit(ADCSRA,0);

#elif ( ADC_PRESCALLER == PRES_64 )

		clear_bit(ADCSRA,0);
		set_bit(ADCSRA,2);
		set_bit(ADCSRA,1);

#elif ( ADC_PRESCALLER == PRES_128 )

		set_bit(ADCSRA,0);
		set_bit(ADCSRA,1);
		set_bit(ADCSRA,2);

#else #error "wrong prescaller selection"
#endif
}


//###################################################3
static void ADC_Trigger_mode(void)
{
#if ( ACD_MODE == ANALOG_COMPARATOR )

		set_bit(SFIOR,5);
		clear_bit(SFIOR,6);
		clear_bit(SFIOR,7);

#elif (ACD_MODE == FREE_RUNNING )

		clear_bit(SFIOR,5);
		clear_bit(SFIOR,6);
		clear_bit(SFIOR,7);

#else {#error "wrong trigger mode selection"}
#endif
}
