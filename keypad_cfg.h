/*
 * keypad_cfg.h
 *
 *  Created on: Sep 23, 2019
 *      Author: Hesham Hafez & Ahmed El-Dakhly
 */

#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

#include "DIO.h"

/*check the type of the keypad 4x3 or 4x4*/
#define N_COL 3
#define N_ROW 3
#define START_ROW 2
#define END_ROW 5
#define YES 1
#define NO 3

#define KEYPAD_PORT_OUT DIO_PORTC
#define KEYPAD_PORT_IN 	DIO_PINC
#define KEYPAD_PORT_DIR DIO_DDRC

#define R1C1 1
#define R1C2 2
#define R1C3 3
#if(N_COL==4)
#define R1C4 '/'
#endif

#define R2C1 4
#define R2C2 5
#define R2C3 6
#if(N_COL==4)
#define R2C4 '*'
#endif

#define R3C1 7
#define R3C2 8
#define R3C3 9
#if(N_COL==4)
#define R3C4 '-'
#endif

#if(N_ROW==4)
#define R4C1 13
#define R4C2 0
#define R4C3 '='
#if(N_COL==4)
#define R4C4 '+'
#endif
#endif

#endif /* KEYPAD_CFG_H_ */
