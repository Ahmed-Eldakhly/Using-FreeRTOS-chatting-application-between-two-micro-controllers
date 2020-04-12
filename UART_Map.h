/*
 * USART_MEMORY_MAPING.h
 *
 *this file consist of Register that belong to UART Peripheral
 *
 *  Created on: Sep 3, 2019
 *  Modified on: Sep 4, 2019
 *      Author: Ahmed Eldakhly
 */

#ifndef UART_MAP_H_
#define UART_MAP_H_

/*this file contain typedefs of Standard Data Types*/
#include "std_types.h"
#include "Macro.h"

#define USART_UCSRA (*(volatile uint8*)0x2B)
#define Bit_MPCM 0
#define Bit_U2X 1
#define Flag_PE 2
#define Flag_DOR 3
#define Flag_FE 4
#define Flag_UDRE 5
#define Flag_TXC 6
#define Flag_RXC 7


#define USART_UCSRB (*(volatile uint8*)0x2A)
#define Bit_TXB8 0
#define Bit_RXB8 1
#define Bit2_UCSZ2 2
#define Enable_TXEN 3
#define Enable_RXEN 4
#define InterruptEnable_UDRIE 5
#define InterruptEnable_TXCIE 6
#define InterruptEnable_RXCIE 7


#define USART_UCSRC (*(volatile uint8*)0x40)
#define Bit_UCPOL 0
#define Bit0_UCSZ0 1
#define Bit1_UCSZ1 2
#define StopBits_USBS 3
#define Bit0_UPM0 4
#define Bit1_UPM1 5
#define Bit_UMSEL 6
#define SelectRegister_URSEL 7



#define USART_DataRegister (*(volatile uint8*)0x2C)


#define USART_BaudRateLow (*(volatile uint8*)0x29)
#define USART_BaudRateHigh (*(volatile uint8*)0x40)
#define SelectRegister_URSEL 7




#endif /* UART_MAP_H_ */
