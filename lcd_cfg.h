/*
 * lcd_cfg.h
 *
 *  Created on: Sep 24, 2019
 *      Author: hesha
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#include "std_types.h"
#include "Macro.h"
#include "DIO.h"
#include <util/delay.h>

/* LCD Data bits mode configuration */
#define DATA_BITS_MODE 4

/* Use higher 4 bits in the data port */
#if (DATA_BITS_MODE == 4)
#define UPPER_PORT_PINS
#endif

/* LCD HW Pins */
#define RS DIO_PIN1
#define RW DIO_PIN2
#define E  DIO_PIN3

#define LCD_CTRL_PORT 	  	DIO_PORTA
#define LCD_CTRL_PORT_DIR 	DIO_DDRA

#define LCD_DATA_PORT 		DIO_PORTA
#define LCD_DATA_PORT_DIR 	DIO_DDRA

#endif /* LCD_CFG_H_ */
