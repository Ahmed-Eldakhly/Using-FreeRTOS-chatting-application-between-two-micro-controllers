/*
 * UART_interfacing.h
 *
 *this file consist of enums,struct and function Prototypes for UART Driver
 *
 *  Created on: Sep 3, 2019
 *  Modified on: Sep 4, 2019
 *      Author: Ahmed Eldakhly
 */

#ifndef UART_H_
#define UART_H_

/*this file contain typedefs of Standard Data Types*/
#include "UART_Map.h"

/*status flag for any function to make sure this function is done*/
typedef enum
{
	NOT_OK,
	OK
}Status_t;
/*flag to determine baud rate speed mood*/
typedef enum
{
	NormalSpeed,
	Dou_Speed
}DoubleSpeed_t;
/*flag to enable or disable receive interrupt*/
typedef enum
{
	EnableRX,
	DisableRX
}RXIntEN_t;
/*flag to enable or disable transmit interrupt*/
typedef enum
{
	EnableTX,
	DisableTX
}TXIntEN_t;
/*flag to enable or disable Empty Data register interrupt*/
typedef enum
{
	EnableEM,
	DisableEM
}EmptyIntEN_t;
/*flag to determine Data Size (5,6,7,8 or 9 bits)*/
typedef enum
{
	_5_bit,
	_6_bit,
	_7_bit,
	_8_bit,
	_9_bit
}DataSize_t;
/*flag to determine Parity Mood (No parity - even parity - odd parity)*/
typedef enum
{
	NoParity,
	OddParity,
	EvenParity
}Parity_t;
/*flag to determine Number of stop bits (one bit - two bits)*/
typedef enum
{
	OneStopBit,
	TwoStopBit
}StopBit_t;
/*struct that let user set configuration of UART Peripheral */
typedef struct
{
	 uint16 		BuadRate;
	 Parity_t 		Init_Parity;
	 StopBit_t 		Init_Stop;
	 DataSize_t 	Init_DataSize;
	 EmptyIntEN_t 	Init_Em;
	 TXIntEN_t 		Init_TX;
	 RXIntEN_t 		Init_RX;
	 DoubleSpeed_t 	Init_DoubleSpeed;
	 /*void (*ptr)(void);*/
	void (*UART_Tx_CallBack_Function)(void);
	void (*UART_Rx_CallBack_Function)(void);
}Str_UARTcfg_t;

extern Str_UARTcfg_t UART_Config;
/********************************************************************************************/
/****************************************************************************
 * 1-func_Name: UART_Init.													*
 *                                                             			    *
 * 2-arguments:																*
 * 		Input:																*
 * 			Data type: typedef of user struct called  UART_conf_s			*
 * 			this struct that contain the required parameters that needed to_*
 * 			configure the UART peripheral by user 							*
 * 		output: void                                 						*
 *																			*
 *3-Return:																	*
 *	  DataType: enum status   												*
 *	  description: the return value will be OK if function done 			*
 *	  			  correctly or NOT_OK if happen something wrong.			*
 *	                                                       				    *
 *4-this function's role is initialize UART communicationby determine Baud_	*
 *  rate,Baud rate mood,Data size,Number of stop bits,Parity Mood and_		*
 *  interrupts mood.															*
 *																			*
 *****************************************************************************/
Status_t UART_Init(void);

/********************************************************************************************/
/****************************************************************************
 * 1-func_Name: UART_ReceiveChar.											*
 *                                                             			    *
 * 2-arguments:																*
 * 		Input: void                                 						*
 * 		Output:																*
 * 			Data type: pointer to uint8										*
 * 			this pointer points to data that receive by UART				*
 *																			*
 *3-Return:																	*
 *	  DataType: enum status   												*
 *	  description: the return value will be OK if function done 			*
 *	  			  correctly or NOT_OK if happen something wrong.			*
 *	                                                       				    *
 *4-this function's role is return data that is received by UART				*
 *																			*
 *****************************************************************************/
Status_t UART_ReceiveChar(uint8* a_data_ptr);

/********************************************************************************************/
/****************************************************************************
 * 1-func_Name: UART_SendChar.												*
 *                                                             			    *
 * 2-arguments:																*
 * 		Input:																*
 * 			Data type:uint8													*
 * 			this data that send from user by UART	Protocol				*
 * 		Output: void                                 						*
 *																			*
 *3-Return:																	*
 *	  DataType: enum status   												*
 *	  description: the return value will be OK if function done 			*
 *	  			  correctly or NOT_OK if happen something wrong.			*
 *	                                                       				    *
 *4-this function's role is send data from user by UART						*
 *																			*
 *****************************************************************************/
Status_t UART_SendChar(uint8 a_data);

/********************************************************************************************/
/****************************************************************************
 * 1-func_Name: UART_Receive.												*
 *                                                             			    *
 * 2-arguments:																*
 * 		Input: void                                 						*
 * 		Output:																*
 * 			Data type: pointer to uint8										*
 * 			this pointer points to string that receive by UART				*
 *																			*
 *3-Return:																	*
 *	  DataType: enum status   												*
 *	  description: the return value will be OK if function done 			*
 *	  			  correctly or NOT_OK if happen something wrong.			*
 *	                                                       				    *
 *4-this function's role is return string that is received by UART			*
 *																			*
 *****************************************************************************/
Status_t UART_Receive( uint8* const a_data_ptr);

/********************************************************************************************/
/****************************************************************************
 * 1-func_Name: UART_Send.													*
 *                                                             			    *
 * 2-arguments:																*
 * 		Input:																*
 * 			Data type:Pointer to uint8										*
 * 			this string that send from user by UART Protocol				*
 * 		Output: void                                 						*
 *																			*
 *3-Return:																	*
 *	  DataType: enum status   												*
 *	  description: the return value will be OK if function done 			*
 *	  			  correctly or NOT_OK if happen something wrong.			*
 *	                                                       				    *
 *4-this function's role is send string from user by UART					*
 *																			*
 *****************************************************************************/
Status_t UART_Send(uint8* a_data_ptr);

/********************************************************************************************/
/****************************************************************
 * 1-func_Name:UART_StartComm.									*
 *                                                              *
 * 2-arguments:													*
 * 		Input: void												*
 * 		output: void                                 			*
 *																*
 *3-Return:														*
 *	  DataType: enum status   									*
 *	  description: the return value will be OK if function done *
 *	  			  correctly or NOT_OK if happen something wrong.*
 *	                                                            *
 *4-this function's role is starting UART communication_		*
 *  by Set Enable Bits for receive and transmit.				*
 *																*
 * **************************************************************/
Status_t UART_StartComm(void);

/********************************************************************************************/
/****************************************************************
 * 1-func_Name:UART_StopComm.									*
 *                                                              *
 * 2-arguments:													*
 * 		Input: void												*
 * 		output: void                                 			*
 *																*
 *3-Return:														*
 *	  DataType: enum status   									*
 *	  description: the return value will be OK if function done *
 *	  			  correctly or NOT_OK if happen something wrong.*
 *	                                                            *
 *4-this function's role is stopping UART communication_		*
 *  by Clear Enable Bits for receive and transmit.				*
 *																*
 * **************************************************************/
Status_t UART_StopComm(void);

/********************************************************************************************/
/****************************************************************
 * 1-UART_EmptyRegisterInterrupt.								*
 *                                                              *
 * 2-arguments:													*
 * 		Input: void												*
 * 		output: void                                 			*
 *																*
 *3-Return:														*
 *	  DataType: enum status   									*
 *	  description: the return value will be OK if function done *
 *	  			  correctly or NOT_OK if happen something wrong.*
 *	                                                            *
 *4-this function's role enable or disable empty register		*
 *interrupt.													*
 *																*
 * **************************************************************/
Status_t UART_EmptyRegisterInterrupt(void);

/********************************************************************************************/
/****************************************************************
 * 1-UART_ReceiveInterrupt.										*
 *                                                              *
 * 2-arguments:													*
 * 		Input: void												*
 * 		output: void                                 			*
 *																*
 *3-Return:														*
 *	  DataType: enum status   									*
 *	  description: the return value will be OK if function done *
 *	  			  correctly or NOT_OK if happen something wrong.*
 *	                                                            *
 *4-this function's role enable or disable receive interrupt.	*													*
 *																*
 * **************************************************************/
Status_t UART_ReceiveInterrupt(void);

/********************************************************************************************/
/****************************************************************
 * 1-UART_transmitInterrupt.									*
 *                                                              *
 * 2-arguments:													*
 * 		Input: void												*
 * 		output: void                                 			*
 *																*
 *3-Return:														*
 *	  DataType: enum status   									*
 *	  description: the return value will be OK if function done *
 *	  			  correctly or NOT_OK if happen something wrong.*
 *	                                                            *
 *4-this function's role enable or disable transmit interrupt.	*													*
 *																*
 * **************************************************************/
Status_t UART_transmitInterrupt(void);

#endif /* UART_H_ */
