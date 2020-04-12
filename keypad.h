/*************************************************
 * Module 	  : Keypad
 *
 * File name  : keypad.h
 *
 * Created on : Apr 21, 2019
 *
 * Author     : Hesham Hafez & Ahmed El-Dakhly
 *************************************************/

#ifndef KEYPAD_H_
#define KEYPAD_H_

/*************************************************
 * 				Included libraries
 *************************************************/
#include"keypad_cfg.h"


/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
//#define IDLE 		0
//#define PRESSED 	1
//#define RELEASED 	2
//#define PREPRESSED 	3
//#define PRERELEASED 4
/************************************************
 * 				Functions Deceleration
 ************************************************/

/*******************************************************************************
 * Function Name:	KeyPad_Init
 *
 * Description: 	Initialize KeyPad with Configured mode
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void KeyPad_Init(void);

/*******************************************************************************
 * Function Name:	KeyPad_getPressedKey
 *
 * Description: 	Return value of pressed key
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			pressed key (uint8)
 *******************************************************************************/
extern uint8 KeyPad_getPressedKey(void);

/*******************************************************************************
 * Function Name:	DeBounching_Task
 *
 * Description: 	DeBouncing Task that will run in OS
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void DeBounching_Task(void);

/*******************************************************************************
 * Function Name:	Key_PressedTask
 *
 * Description: 	Pressed Key Task that will run in OS
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Key_PressedTask(void);

#endif /* KEYPAD_H_ */
