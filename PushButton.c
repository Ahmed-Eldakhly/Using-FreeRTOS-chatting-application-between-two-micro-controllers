/*************************************************
 * Module     : PushButton
 *
 * File name  : PushButton.c
 *
 * Created on : Oct 6, 2019
 *
 * Author     : Hesham Hafez & Ahmed El-Dakhly
 *************************************************/

/*************************************************
 *              Included libraries
 *************************************************/
#include "PushButton.h"

/********************************************************************************
 *              Functions Definition                                            *
 ********************************************************************************/
/********************************************************************************
 * Function Name:   PushButton_Init
 *
 * Description:     Initialize Push Button
 *
 * Inputs:          NULL
 *
 * Outputs:         NULL
 *
 * Return:          NULL
 *******************************************************************************/
void PushButton_Init(void)
{
    /*set Pins Of Push Button*/
    DIO_SetPinDirection(DIO_PIN10 , INPUT);
    DIO_SetPinDirection(DIO_PIN20 , INPUT);


}

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
uint8 Buttons_getPressedButton(void)
{
    /*return value*/
    uint8 ReturnVal=10;


    /*Loop to check if button is pressed to return its value*/

    if(DIO_ReadPin(DIO_PIN10) == 1)
    {
        ReturnVal = 2;
    }
    else if(DIO_ReadPin(DIO_PIN20) == 1)
    {
        ReturnVal = 1;
    }
    else
    {
        /*Do Nothing*/
    }
    return ReturnVal;
}
