// ADC channels

#define ADC_0 0
#define ADC_1 1
#define ADC_2 2
#define ADC_3 3
#define ADC_4 4
#define ADC_5 5
#define ADC_6 6
#define ADC_7 7

void ACD_void_init(void);

void ADC_interrupt_enable(void);
void ADC_interrupt_disable(void);


#if (ADC_CONVERSION_RESOLUTION == CONVERSION_8_BIT)

u8 ACD_Result(u8 channel);

#elif (ADC_CONVERSION_RESOLUTION == CONVERSION_16_BIT)

u16 ACD_Result(u8 channel);
#else {#error "wrong selection " }
#endif

//void ACD_setCallBack(void (*p) (void));


void ADC_enable(void);

void ADC_StartConversion(u8 channel);


