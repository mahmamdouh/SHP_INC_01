/*
 * LCD_Int.h
 *
 *  Created on: May 17, 2019
 *      Author: salsa
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

void LCD_voidInitialize(void);
void LCD_voidWriteCommand(u8 command);
void LCD_voidWriteData(u8 data);
void LCD_voidSetCursor(u8 rows,u8 columns);
void LCD_voidPrint(u8 * string);
void LCD_voidClearDisplay(void);
void LCD_voidShiftToLeft(void);
void LCD_voidShiftToRight(void);

#endif /* LCD_INT_H_ */
