/*
 * LCD_Config.h
 *
 *  Created on: May 17, 2019
 *      Author: Salah Mahmoud
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

//The following parameters specify if we will use LCD in 4 bits mode or 8 bits mode
//Remove the following comment for operation modes first option to use only 4 wires for communication and second for 8 wires communication
/* 4_BITS_OPERATING_MODE
 * 8_BITS_OPERATING_MODE
 */
#define OPERATING_MODE FOUR_BITS_OPERATING_MODE

//pins that will be connected to the LCD
#define LCD_PIN_D4 DIO_PIN_4
#define LCD_PIN_D5 DIO_PIN_5
#define LCD_PIN_D6 DIO_PIN_6
#define LCD_PIN_D7 DIO_PIN_7

//Remove commented section if you use 8 bits mode
/*
#define LCD_PIN_D0 DIO_PIN_0
#define LCD_PIN_D1 DIO_PIN_1
#define LCD_PIN_D2 DIO_PIN_2
#define LCD_PIN_D3 DIO_PIN_3
#define LCD_PIN_D4 DIO_PIN_4
#define LCD_PIN_D5 DIO_PIN_5
#define LCD_PIN_D6 DIO_PIN_6
#define LCD_PIN_D7 DIO_PIN_7
*/


#define LCD_PIN_RS DIO_PIN_9
#define LCD_PIN_RW DIO_PIN_10
#define LCD_PIN_E DIO_PIN_11

#endif /* LCD_CONFIG_H_ */
