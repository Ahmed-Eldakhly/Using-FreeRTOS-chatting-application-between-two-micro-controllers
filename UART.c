/*
 * UART_prog.c
 *
 *this file consist of function for UART Driver
 *
 *  Created on: Sep 3, 2019
 *  Modified on: Sep 4, 2019
 *      Author: Ahmed Eldakhly
 */

/*this file contain typedefs of Standard Data Types*/
/*this file contain enums,struct and function Prototypes for UART Driver*/
#include "UART.h"

/********************************************************************************************/
//
//ISR(USART_UDRE_vect)
//{
//	UART_Config.UART_Tx_CallBack_Function();
//}
//
//ISR(USART_RXC_vect)
//{
//	UART_Config.UART_Rx_CallBack_Function();
//}
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
Status_t UART_Init(void)
{
	Status_t ReturnValue=NOT_OK;
	/*select Baud rate mood*/
	if((UART_Config.Init_DoubleSpeed)==Dou_Speed)
	{
		SET_BIT(USART_UCSRA,Bit_U2X);
		USART_BaudRateLow=UART_Config.BuadRate;
		CLEAR_BIT(USART_BaudRateHigh,SelectRegister_URSEL);
		USART_BaudRateHigh=((UART_Config.BuadRate)>>8);
		ReturnValue=OK;
	}
	else if((UART_Config.Init_DoubleSpeed)==NormalSpeed)
	{
		CLEAR_BIT(USART_UCSRA,Bit_U2X);
		USART_BaudRateLow=UART_Config.BuadRate;
		ReturnValue=OK;
	}
	else
		ReturnValue=NOT_OK;
	/*select parity mood*/
	switch(UART_Config.Init_Parity)
	{
	case NoParity:
		USART_UCSRC=(USART_UCSRC|0x80)&(~(1<<Bit0_UPM0))&(~(1<<Bit1_UPM1));
		if(ReturnValue==OK)
			ReturnValue=OK;
		break;
	case EvenParity:
		USART_UCSRC=(USART_UCSRC|0xA0)&(~(1<<Bit0_UPM0));
		if(ReturnValue==OK)
			ReturnValue=OK;
		break;
	case OddParity:
		USART_UCSRC=(USART_UCSRC|0xB0);
		if(ReturnValue==OK)
			ReturnValue=OK;
		break;
	default:
		ReturnValue=NOT_OK;
	}
	/*select number of stop bits*/
	if(UART_Config.Init_Stop==OneStopBit)
	{
		USART_UCSRC=(USART_UCSRC|0x80)&(~(1<<StopBits_USBS));
		if(ReturnValue==OK)
			ReturnValue=OK;
	}
	else if(UART_Config.Init_Stop==TwoStopBit)
	{
		USART_UCSRC=(USART_UCSRC|0x88);
		if(ReturnValue==OK)
			ReturnValue=OK;
	}
	else
		ReturnValue=NOT_OK;
	/*select data size*/
	switch(UART_Config.Init_DataSize)
	{
	case _5_bit:
		USART_UCSRC=(USART_UCSRC|0x80)&(~(1<<Bit0_UCSZ0))&(~(1<<Bit1_UCSZ1));
		CLEAR_BIT(USART_UCSRB,Bit2_UCSZ2);
		if(ReturnValue==OK)
			ReturnValue=OK;
		break;
	case _6_bit:
		USART_UCSRC=(USART_UCSRC|0x82)&(~(1<<Bit1_UCSZ1));
		CLEAR_BIT(USART_UCSRB,Bit2_UCSZ2);
		if(ReturnValue==OK)
			ReturnValue=OK;
		break;
	case _7_bit:
		USART_UCSRC=(USART_UCSRC|0x84)&(~(1<<Bit0_UCSZ0));
		CLEAR_BIT(USART_UCSRB,Bit2_UCSZ2);
		if(ReturnValue==OK)
			ReturnValue=OK;
		break;
	case _8_bit:
		USART_UCSRC=(USART_UCSRC|0x86);
		CLEAR_BIT(USART_UCSRB,Bit2_UCSZ2);
		if(ReturnValue==OK)
			ReturnValue=OK;
		break;
	case _9_bit:
		USART_UCSRC=(USART_UCSRC|0x86);
		SET_BIT(USART_UCSRB,Bit2_UCSZ2);
		if(ReturnValue==OK)
			ReturnValue=OK;
		break;
	default:
		ReturnValue=NOT_OK;
	}
	/*enable or disable empty data register interrupt*/
	if(UART_Config.Init_Em)
	{
		CLEAR_BIT(USART_UCSRB,InterruptEnable_UDRIE);
		if(ReturnValue==OK)
			ReturnValue=OK;
	}
	else if((UART_Config.Init_Em)==EnableEM)
	{
		SET_BIT(USART_UCSRB,InterruptEnable_UDRIE);
		if(ReturnValue==OK)
			ReturnValue=OK;
	}
	else
		ReturnValue=NOT_OK;
	/*enable or disable transmitter interrupt*/
	if(UART_Config.Init_TX)
	{
		CLEAR_BIT(USART_UCSRB,InterruptEnable_TXCIE);
		if(ReturnValue==OK)
			ReturnValue=OK;
	}
	else if((UART_Config.Init_TX)==EnableTX)
	{
		SET_BIT(USART_UCSRB,InterruptEnable_TXCIE);
		if(ReturnValue==OK)
			ReturnValue=OK;
	}
	else
		ReturnValue=NOT_OK;
	/*enable or disable receiver interrupt*/
	if(UART_Config.Init_RX)
	{
		CLEAR_BIT(USART_UCSRB,InterruptEnable_RXCIE);
		if(ReturnValue==OK)
			ReturnValue=OK;
	}
	else if((UART_Config.Init_RX)==EnableRX)
	{
		SET_BIT(USART_UCSRB,InterruptEnable_RXCIE);
		if(ReturnValue==OK)
			ReturnValue=OK;
	}
	else
		ReturnValue=NOT_OK;
	SET_BIT(USART_UCSRB,Enable_RXEN);
	SET_BIT(USART_UCSRB,Enable_TXEN);
	return ReturnValue;
}
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
Status_t UART_ReceiveChar(uint8* a_data_ptr)
{
	uint16 dummy;
	Status_t ReturnValue;

	/*check if pulling is selected*/
	if(!(GET_BIT(USART_UCSRB,InterruptEnable_RXCIE)))
	{
		/*pull on receive flag*/
		while(!(GET_BIT(USART_UCSRA,Flag_RXC)));
	}
	/*get Data from data register of UART*/
	if(USART_UCSRA&((1<<Flag_PE)|(1<<Flag_DOR)|(1<<Flag_FE)))
	{
		dummy=USART_DataRegister;
		ReturnValue=NOT_OK;
	}
	else
	{
		*a_data_ptr=USART_DataRegister;
		ReturnValue=OK;
	}
	return ReturnValue;
}
/********************************************************************************************/
/****************************************************************************
 * 1-func_Name: UART_SendChar.												*
 *                                                             			    *
 * 2-arguments:																*
 * 		Input:																*
 * 			Data type:uint8													*
 * 			this data that send from user by UART Protocol					*
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
Status_t UART_SendChar(uint8 a_data)
{
	Status_t ReturnValue;
	/*check if pulling is selected*/
	if(!(GET_BIT(USART_UCSRB,InterruptEnable_UDRIE)))
		/*pull on empty Data register flag*/
		while(!(GET_BIT(USART_UCSRA,Flag_UDRE)));
	/*put Data on data register of UART*/
	if(GET_BIT(USART_UCSRB,Enable_TXEN))
	{
		USART_DataRegister=a_data;
		ReturnValue=OK;
	}
	else
		ReturnValue=NOT_OK;
	return ReturnValue;
}
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
Status_t UART_Receive( uint8* const a_data_ptr)
{
	Status_t ReturnValue;
	/*Loop to Receive string by UART*/
	for(uint8 Count=0;a_data_ptr[Count-1]!='\0';Count++)
	{
		ReturnValue=UART_ReceiveChar(&(a_data_ptr[Count]));
		if(!(ReturnValue))
			return ReturnValue;
	}
	return ReturnValue;
}
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
Status_t UART_Send(uint8* a_data_ptr)
{
	Status_t ReturnValue;
	/*Loop on string to send by UART*/
	for(uint8 Count=0;a_data_ptr[Count]!='\0';Count++)
	{
		ReturnValue=UART_SendChar((a_data_ptr[Count]));
		if(!(ReturnValue))
			return ReturnValue;
	}
	return ReturnValue;
}
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
Status_t UART_StartComm(void)
{
	Status_t ReturnValue;
	SET_BIT(USART_UCSRB,Enable_TXEN);
	SET_BIT(USART_UCSRB,Enable_RXEN);
	if((GET_BIT(USART_UCSRB,Enable_TXEN)))
	{
		if((GET_BIT(USART_UCSRB,Enable_RXEN)))
			ReturnValue=OK;
		else
			ReturnValue=NOT_OK;
	}
	else
		ReturnValue=NOT_OK;
	return ReturnValue;

}
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
Status_t UART_StopComm(void)
{
	Status_t ReturnValue;
	while((GET_BIT(USART_UCSRA,Flag_UDRE))==0);
	CLEAR_BIT(USART_UCSRB,Enable_TXEN);
	CLEAR_BIT(USART_UCSRB,Enable_RXEN);
	CLEAR_BIT(USART_UCSRB,InterruptEnable_UDRIE);
	CLEAR_BIT(USART_UCSRB,InterruptEnable_TXCIE);
	CLEAR_BIT(USART_UCSRB,InterruptEnable_RXCIE);
	if(!(GET_BIT(USART_UCSRB,Enable_TXEN)))
	{
		if(!(GET_BIT(USART_UCSRB,Enable_RXEN)))
			ReturnValue=OK;
		else
			ReturnValue=NOT_OK;
	}
	else
		ReturnValue=NOT_OK;
	return ReturnValue;
}

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
Status_t UART_EmptyRegisterInterrupt(void)
{
	Status_t ReturnValue=NOT_OK;
	/*enable or disable empty data register interrupt*/
	if(UART_Config.Init_Em)
	{
		CLEAR_BIT(USART_UCSRB,InterruptEnable_UDRIE);
		if(ReturnValue==OK)
			ReturnValue=OK;
	}
	else if((UART_Config.Init_Em)==EnableEM)
	{
		SET_BIT(USART_UCSRB,InterruptEnable_UDRIE);
		if(ReturnValue==OK)
			ReturnValue=OK;
	}
	else
		ReturnValue=NOT_OK;
	return ReturnValue;
}

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
Status_t UART_ReceiveInterrupt(void)
{
	Status_t ReturnValue=NOT_OK;
	/*enable or disable receiver interrupt*/
	if(UART_Config.Init_RX)
	{
		CLEAR_BIT(USART_UCSRB,InterruptEnable_RXCIE);
		if(ReturnValue==OK)
			ReturnValue=OK;
	}
	else if((UART_Config.Init_RX)==EnableRX)
	{
		SET_BIT(USART_UCSRB,InterruptEnable_RXCIE);
		if(ReturnValue==OK)
			ReturnValue=OK;
	}
	else
		ReturnValue=NOT_OK;
	return ReturnValue;
}

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
Status_t UART_transmitInterrupt(void)
{
	Status_t ReturnValue=NOT_OK;
	/*enable or disable transmitter interrupt*/
		if(UART_Config.Init_TX)
		{
			CLEAR_BIT(USART_UCSRB,InterruptEnable_TXCIE);
			if(ReturnValue==OK)
				ReturnValue=OK;
		}
		else if((UART_Config.Init_TX)==EnableTX)
		{
			SET_BIT(USART_UCSRB,InterruptEnable_TXCIE);
			if(ReturnValue==OK)
				ReturnValue=OK;
		}
		else
			ReturnValue=NOT_OK;
	return ReturnValue;
}
