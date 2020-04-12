/*************************************************
 * Module     : PushButton
 *
 * File name  : PushButton.h
 *
 * Created on : Oct 6, 2019
 *
 * Author     : Hesham Hafez & Ahmed El-Dakhly
 *************************************************/

#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_

/*************************************************
 * 				Included libraries
 *************************************************/
#include "Macro.h"
#include "DIO.h"

/************************************************
 * 				Functions Deceleration
 ************************************************/

/*******************************************************************************
 * Function Name:	PushButton_Init
 *
 * Description: 	Initialize KeyPad with Configured mode
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void PushButton_Init(void);

/*******************************************************************************
 * Function Name:   Buttons_getPressedButton
 *
 * Description:     Return value of pressed Bush Button
 *
 * Inputs:          NULL
 *
 * Outputs:         NULL
 *
 * Return:          pressed Push Button (uint8_t)
 *******************************************************************************/
extern uint8 Buttons_getPressedButton(void);


#endif /* PUSHBUTTON_H_ */
