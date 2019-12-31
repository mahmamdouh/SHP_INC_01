

//DATAT REGISTER
#define ADC_DATA (*(volatile u16*)0x24)

/*
 * ##### ADC MODES
 * FREE_RUNNING
 * ANALOG_COMPARATOR
 */
#define  ACD_MODE ANALOG_COMPARATOR

#define ADC_DATA  (*((volatile u16*)0x24))

/*
 * ##### ADC REFRENCE_SELECTION_BIT
 * ENTERNAL_REFRENCE_TURN_OFF
 * AVCC_WITH_EXTERNAL_CAPACITOR
 * INTERNAL_3_3_WITH_EXTERNAL_CAPACITOR
 */
#define REFRENCE_SELECTION_BIT INTERNAL_3_3_WITH_EXTERNAL_CAPACITOR


/*
 * ##### ADC PRESCALLER
 * PRES_2
 * PRES_4
 * PRES_8
 * PRES_16
 * PRES_32
 * PRES_64
 * PRES_128
 */
#define ADC_PRESCALLER PRES_2

/* ADC CONVERSION RESULT RESOLUTION
 *
 * CONVERSION_8_BIT
 * CONVERSION_16_BIT
 */
#define ADC_CONVERSION_RESOLUTION CONVERSION_8_BIT