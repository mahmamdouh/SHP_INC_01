#define HIGH 1
#define LOW 0

// clock phase
/*
 *CPOL = 0, CPHA = 0 Sample (Rising)   Setup (Falling)     MODE_0
 *CPOL = 0, CPHA = 1 Setup  (Rising)   Sample (Falling)    MODE_1
 *CPOL = 1, CPHA = 0 Sample (Falling)  Setup (Rising)      MODE_2
 *CPOL = 1, CPHA = 1 Setup  (Falling)  Sample (Rising)     MODE_3
 */
#define CLK_PHASE MODE_0
// clock polarity
#define CLK_POLARITY HIGH_IDEAL
//Master Slave mode
#define SPI_MODE MASTER
//normal - double speed mdoe
#define SPEED_MODE NORMAL_SPEED
// SPI data mode
#define SPI_DATA_MODE
// Data order LSB or MSB
#define DATA_ORDER MSB

// speed rate
/* OPTIONS
 * FEQ_DIV_4
 * FEQ_DIV_16
 * FEQ_DIV_24
 * FEQ_DIV_128
 * FEQ_DIV_2
 * FEQ_DIV_8
 * FEQ_DIV_32
 */
#define CLK_RATE FEQ_DIV_4
