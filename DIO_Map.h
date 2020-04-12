/*****************************************************************************
 * Module 	  : DIO Driver
 *
 * File name  : DIO_Map.h
 *
 * Created on : Sep 9, 2019
 *
 * Author     : Ahmed Eldakhly & Hesham Hafez
 ******************************************************************************/
#ifndef DIO_MAP_H_
#define DIO_MAP_H_

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "std_types.h"


#define DIO_PORTA (*(volatile uint8*)0x3B)
#define DIO_PORTB (*(volatile uint8*)0x38)
#define DIO_PORTC (*(volatile uint8*)0x35)
#define DIO_PORTD (*(volatile uint8*)0x32)

#define DIO_DDRA (*(volatile uint8*)0x3A)
#define DIO_DDRB (*(volatile uint8*)0x37)
#define DIO_DDRC (*(volatile uint8*)0x34)
#define DIO_DDRD (*(volatile uint8*)0x31)

#define DIO_PINA (*(volatile uint8*)0x39)
#define DIO_PINB (*(volatile uint8*)0x36)
#define DIO_PINC (*(volatile uint8*)0x33)
#define DIO_PIND (*(volatile uint8*)0x30)



#define DIO_PIN0 	0u
#define DIO_PIN1 	1u
#define DIO_PIN2 	2u
#define DIO_PIN3 	3u
#define DIO_PIN4 	4u
#define DIO_PIN5 	5u
#define DIO_PIN6 	6u
#define DIO_PIN7 	7u
#define DIO_PIN8 	8u
#define DIO_PIN9 	9u
#define DIO_PIN10 	10u
#define DIO_PIN11 	11u
#define DIO_PIN12 	12u
#define DIO_PIN13 	13u
#define DIO_PIN14 	14u
#define DIO_PIN15 	15u
#define DIO_PIN16 	16u
#define DIO_PIN17 	17u
#define DIO_PIN18 	18u
#define DIO_PIN19 	19u
#define DIO_PIN20 	20u
#define DIO_PIN21 	21u
#define DIO_PIN22 	22u
#define DIO_PIN23 	23u
#define DIO_PIN24 	24u
#define DIO_PIN25 	25u
#define DIO_PIN26 	26u
#define DIO_PIN27 	27u
#define DIO_PIN28 	28u
#define DIO_PIN29 	29u
#define DIO_PIN30 	30u
#define DIO_PIN31 	31u





#endif /* DIO_MAP_H_ */
