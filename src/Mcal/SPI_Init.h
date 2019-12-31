
// slave selection
/*OPTIONS
 * SLAVE_1
 * SLAVE_2
 * SLAVE_3
 */
#define SEL_SLAVE_0 0
#define SEL_SLAVE_1 1
#define SEL_SLAVE_2 2
#define SEL_SLAVE_3 3



void SPI_Init(void);

u8 SPI_Receive(void);

u8 SPI_SLAVE_Receive(void);

void SPI_Transmit(u8 data);

void SPI_Select_Slave(u8 slave);

