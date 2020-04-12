/*****************************************************************************
 * Module 	  : FreeRTOS Final Project Tasks implementation
 *
 * File name  : UserTasks.h
 *
 * Created on : Oct 12, 2019
 *
 * Author     : Ahmed Eldakhly & Hesham Hafez
 ******************************************************************************/

#ifndef USERTASKS_H_
#define USERTASKS_H_

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "FreeRTOS.h"
#include "task.h"
#include "DIO.h"
#include "PushButton.h"
#include "lcd.h"
#include "keypad.h"
#include "UART.h"

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/
extern TaskHandle_t  InitTask_Flag;


/*******************************************************************************
 *                      Functions Prototypes        	                       *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:	init_Task
 *
 * Description: 	Create all tasks in the system
 *
 * Inputs:			pointer to void
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void init_Task(void * a_Task_ptr);

/*******************************************************************************
 * Function Name:	PushButton_Task
 *
 * Description: 	Push Button Task
 *
 * Inputs:			pointer to void
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void PushButton_Task(void * a_Task_ptr);

/*******************************************************************************
 * Function Name:	KeyPad_Task
 *
 * Description: 	KeyPad Task
 *
 * Inputs:			pointer to void
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void KeyPad_Task(void * a_Task_ptr);

/*******************************************************************************
 * Function Name:	LCD_Task
 *
 * Description: 	LCD Task
 *
 * Inputs:			pointer to void
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void LCD_Task(void * a_Task_ptr);
/*******************************************************************************
 * Function Name:	UART_Task
 *
 * Description: 	UART receive data
 *
 * Inputs:			pointer to void
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void UART_Task(void * a_Task_ptr);

/*******************************************************************************
 * Function Name:	LED_Task
 *
 * Description: 	LED on if push button is pressed
 *
 * Inputs:			pointer to void
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void LED_Task(void * a_Task_ptr);

#endif /* USERTASKS_H_ */
