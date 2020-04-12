/*************************************************
 * Module 	  : Keypad
 *
 * File name  : keypad.c
 *
 * Created on : Apr 21, 2019
 *
 * Author     : Hesham Hafez & Ahmed El-Dakhly
 *************************************************/

/*************************************************
 * 				Included libraries
 *************************************************/
#include"keypad.h"

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

/*******************************************************************************
 *                           Check Configurations                              *
 *******************************************************************************/
#if(N_COL==3)
#if(N_ROW == 3)
static uint8 KeyPad_3x3_switch(uint8 row, uint8 col);
#elif(N_ROW == 4)
static uint8 KeyPad_4x3_switch(uint8 row, uint8 col);
#endif
#endif

#if(N_COL==4)
static uint8 KeyPad_4x4_switch(uint8 row, uint8 col);
#endif

/********************************************************************************
 * 				Functions Definition											*
 ********************************************************************************/
/********************************************************************************
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
void KeyPad_Init(void)
{
	/*set Pins Of KeyPad*/
	DIO_SetPinDirection(DIO_PIN18,INPUT);
	DIO_SetPinDirection(DIO_PIN19,INPUT);
	DIO_SetPinDirection(DIO_PIN20,INPUT);
	DIO_SetPinDirection(DIO_PIN21,OUTPUT);
	DIO_SetPinDirection(DIO_PIN22,OUTPUT);
	DIO_SetPinDirection(DIO_PIN23,OUTPUT);
	DIO_WritePin(DIO_PIN18,HIGH);
	DIO_WritePin(DIO_PIN19,HIGH);
	DIO_WritePin(DIO_PIN20,HIGH);
	DIO_WritePin(DIO_PIN21,LOW);
	DIO_WritePin(DIO_PIN22,LOW);
	DIO_WritePin(DIO_PIN23,LOW);
}

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
uint8 KeyPad_getPressedKey(void)
{
	/*return value*/
	uint8 ReturnVal=10;

	/*variables use to loop pn rows and column*/
	uint8 row,col;

	/*Loop to check if Key is pressed to return its value*/
	for(col=0;col<N_COL;col++)
	{
		KEYPAD_PORT_DIR = (0b00100000<<col);
		KEYPAD_PORT_OUT = (~(0b00100000<<col));

		for(row=START_ROW;row<END_ROW;row++)
		{
			if(GET_BIT(KEYPAD_PORT_IN,row) == 0)
			{
				/*check on Configurations Mode*/
#if(N_COL ==3)
#if(N_ROW == 3)

				/*return value of pressed Key*/
				return  KeyPad_3x3_switch(row-START_ROW,col);
#elif(N_ROW==4)
				return KeyPad_4x3_switch(row-START_ROW,col);
#endif
#elif(N_COL ==4)
				return KeyPad_4x4_switch(row-START_ROW,col);
#endif
			}
		}
	}
	return ReturnVal;
}

/*check on Configurations Mode*/
#if(N_COL==3)

/*check on Configurations Mode*/
#if(N_ROW == 4)

/********************************************************************************
 * Function Name:	KeyPad_4x3_switch
 *
 * Description: 	static function to return value of Pressed Key
 *
 * Inputs:			row of pressed Key (uint8)
 * 					column of pressed Key (uint8)
 *
 * Outputs:			NULL
 *
 * Return:			value of Pressed Key (uint8)
 *******************************************************************************/
static uint8 KeyPad_4x3_switch(uint8 row,uint8 col)
{
	/*variable of return value*/
	uint8 ReturnVal = 0;

	/*determine row of pressed key*/
	switch(row)
	{
	case 0:
		/*determine column of pressed key*/
		switch(col)
		{
			case 0: ReturnVal = R1C1;
				break;
			case 1: ReturnVal = R1C2;
				break;
			case 2: ReturnVal = R1C3;
				break;
			default: /*Do nothing*/
				break;
		}
		break;

	case 1:
		/*determine column of pressed key*/
		switch(col)
		{
		case 0: ReturnVal = R2C1;
			break;
		case 1: ReturnVal = R2C2;
			break;
		case 2: ReturnVal = R2C3;
			break;
		default: /*Do nothing*/
			break;
		}
		break;

	case 2:
		/*determine column of pressed key*/
		switch(col)
		{
		case 0: ReturnVal = R3C1;
			break;
		case 1: ReturnVal = R3C2;
			break;
		case 2: ReturnVal = R3C3;
			break;
		default: /*Do nothing*/
			break;
		}
		break;

	case 3:
		/*determine column of pressed key*/
		switch(col)
		{
		case 0: ReturnVal = R4C1;
			break;
		case 1: ReturnVal = R4C2;
			break;
		case 2: ReturnVal = R4C3;
			break;
		default: /*Do nothing*/
			break;
		}
		break;
	default:
		/*Do nothing*/
		break;
	}

	/*return value of pressed key*/
	return ReturnVal;
}

/*check on Configurations Mode*/
#elif (N_ROW == 3)

/********************************************************************************
 * Function Name:	KeyPad_3x3_switch
 *
 * Description: 	static function to return value of Pressed Key
 *
 * Inputs:			row of pressed Key (uint8)
 * 					column of pressed Key (uint8)
 *
 * Outputs:			NULL
 *
 * Return:			value of Pressed Key (uint8)
 *******************************************************************************/
static uint8 KeyPad_3x3_switch(uint8 row, uint8 col)
{
	/*variable of return value*/
	uint8 ReturnVal = 0;

	/*determine row of pressed key*/
	switch(row)
	{
	case 0:
		/*determine column of pressed key*/
		switch(col)
		{
		case 0: ReturnVal = R1C1;
			break;
		case 1: ReturnVal = R1C2;
			break;
		case 2: ReturnVal = R1C3;
			break;
		default:/*Do nothing*/
			break;
		}
		break;

	case 1:
		/*determine column of pressed key*/
		switch(col)
		{
		case 0: ReturnVal = R2C1;
			break;
		case 1: ReturnVal = R2C2;
			break;
		case 2: ReturnVal = R2C3;
			break;
		}
			break;
	case 2:
		/*determine column of pressed key*/
		switch(col)
		{
		case 0: ReturnVal = R3C1;
			break;
		case 1: ReturnVal = R3C2;
			break;
		case 2: ReturnVal = R3C3;
			break;
		}
		break;
	}

	/*return value of pressed key*/
	return ReturnVal;
}

#endif

/*check on Configurations Mode*/
#elif(N_COL==4)

/********************************************************************************
 * Function Name:	KeyPad_4x4_switch
 *
 * Description: 	static function to return value of Pressed Key
 *
 * Inputs:			row of pressed Key (uint8)
 * 					column of pressed Key (uint8)
 *
 * Outputs:			NULL
 *
 * Return:			value of Pressed Key (uint8)
 *******************************************************************************/
static uint8 KeyPad_4x4_switch(uint8 row,uint8 col)
{
	/*variable of return value*/
	uint8 ReturnVal = 0;

	/*determine row of pressed key*/
	switch(row)
	{
	case 0:
		/*determine column of pressed key*/
		switch(col)
		{
		case 0: ReturnVal = R1C1;
		break;
		case 1: ReturnVal = R1C2;
		break;
		case 2: ReturnVal = R1C3;
		break;
		case 3: ReturnVal = R1C4;
		break;
		}
		break;

	case 1:
		/*determine column of pressed key*/
		switch(col)
		{
		case 0: ReturnVal = R2C1;
			break;
		case 1: ReturnVal = R2C2;
			break;
		case 2: ReturnVal = R2C3;
			break;
		case 3: ReturnVal = R2C4;
			break;
		}
		break;

	case 2:
		/*determine column of pressed key*/
		switch(col)
		{
		case 0: ReturnVal = R3C1;
			break;
		case 1: ReturnVal = R3C2;
			break;
		case 2: ReturnVal = R3C3;
			break;
		case 3: ReturnVal = R3C4;
			break;
		}
		break;

	case 3:
		/*determine column of pressed key*/
		switch(col)
		{
		case 0: ReturnVal = R4C1;
			break;
		case 1: ReturnVal = R4C2;
			break;
		case 2: ReturnVal = R4C3;
			break;
		case 3: ReturnVal = R4C4;
			break;
		}
		break;
	}

	/*return value of pressed key*/
	return ReturnVal;
}
#endif
