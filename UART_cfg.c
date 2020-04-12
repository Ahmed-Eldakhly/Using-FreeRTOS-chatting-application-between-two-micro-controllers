/*
 * UART_cfg.c
 *
 *this file consist of function for UART Driver
 *
 *  Created on: Sep 3, 2019
 *  Modified on: Sep 4, 2019
 *      Author: Ahmed Eldakhly
 */


/*this file contain configuration struct for UART Driver*/

#include "UART_cfg.h"

Str_UARTcfg_t UART_Config={51,NoParity,OneStopBit,_8_bit,DisableEM,DisableTX,DisableRX,NormalSpeed,NULL_PTR,NULL_PTR};
