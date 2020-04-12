/*****************************************************************************
 * Module 	  : DIO Driver
 *
 * File name  : DIO.h
 *
 * Created on : Sep 9, 2019
 *
 * Author     : Ahmed Eldakhly & Hesham Hafez
 ******************************************************************************/

#ifndef DIO_H_
#define DIO_H_
#include "DIO_Map.h"
#include "Macro.h"
#include "std_types.h"

void DIO_WritePin(uint8 PinNum,uint8 PinValue);
uint8 DIO_ReadPin(uint8 PinNum);
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);



#endif /* DIO_H_ */
