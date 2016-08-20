/*
 * LcdController.h
 *
 *  Created on: 13 A�u 2016
 *      Author: KaaN
 */

#ifndef LCDCONTROLLER_H_
#define LCDCONTROLLER_H_
#include "UartController.h"
#include "../Utilities/Vector.h"
#include "../Utilities/StringArray.h"

#define DISPLAY_MATRIX_ROW  2




u32 lcd_init(u32 deviceId);

/**
 * Clears the LCD display area. Sets cursor to the beginning.
 */
void lcd_clearDisplay();

/**
 * Displays the data stored in buffer. If amount of data exceeds
 * raises a flag.
 *
 * @return	- XST_SUCCESS if everything works correctly.
 * 			- XST_FAILURE if there is an error.
 * 			- XST_NO_DATA if buffer is empty.
 */
u32 lcd_display();

/**
 * Display the next available data fragment in the buffer.
 *
 * @return	- XST_SUCCESS if everything works correctly.
 * 			- XST_NO_DATA if no more data available.
 */
u32 lcd_displayNext();

/**
 * Display the last available data fragment in the buffer.
 *
 * @return	- XST_SUCCESS if everything works correctly.
 * 			- XST_NO_DATA if no more data available.
 */
u32 lcd_displayPrevious();



/**
 * Sets the display buffer. It represents the raw data to be displayed.
 *
 * @param 	byteVector is the raw input to be displayed. It can have u8 numbers.
 */
void lcd_setBuffer(StringArray* processedStrings);


/**
 * Displays the selected rows by sending the proper commands via
 * uart to the device.By default it moves the cursor to the beginning
 * and then puts the rows to display.Caller must call calculateDisplayMatrix()
 * method prior to this method.
 *
 *
 * @param 	rowIndex is a array of integers. Specifies which exact row
 * 			must be displayed.
 *
 * @return	- XST_SUCCESS
 * 			- XST_FAILURE
 */
u32 displayRow(u16 rowIndex);


#endif /* LCDCONTROLLER_H_ */