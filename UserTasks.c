/*****************************************************************************
 * Module 	  : FreeRTOS Final Project Tasks implementation
 *
 * File name  : UserTasks.c
 *
 * Created on : Oct 12, 2019
 *
 * Author     : Ahmed Eldakhly & Hesham Hafez
 ******************************************************************************/

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "UserTasks.h"
#include "queue.h"

/*******************************************************************************
 *                           static Global Variables                           *
 *******************************************************************************/
/*Queue between PushButtonTask & LCD Task*/
static xQueueHandle Queue_PushButton;

/*Queue between Send UART received data & LCD Task*/
static xQueueHandle Queue_ReceivedUART_Task;

/*Queue between Keypad & LCD Task*/
static xQueueHandle Queue_Keypad_Task;


/*******************************************************************************
 *                           Global Variables                    		       *
 *******************************************************************************/
TaskHandle_t  InitTask_Flag = NULL;

/*******************************************************************************
 *                      Functions Definitions                                  *
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
void init_Task(void * a_Task_ptr)
{
	/*initialize all HW and preipherals*/
	PushButton_Init();
	UART_Init();
	KeyPad_Init();
	LCD_init();
	DIO_SetPinDirection(DIO_PIN12,OUTPUT);
	DIO_SetPinDirection(DIO_PIN13,OUTPUT);

	/*Create Queues*/
	Queue_PushButton = xQueueCreate( 3 , sizeof(uint8) );
	Queue_Keypad_Task = xQueueCreate( 3 , sizeof(uint8) );
	Queue_ReceivedUART_Task = xQueueCreate( 3 , sizeof(uint8) );

	/*Create 5 Tasks*/
	/*create Push Button task to reset LCD*/
	xTaskCreate(PushButton_Task  , "PushButton_Task" , 100 ,
			NULL , (1 | portPRIVILEGE_BIT) , NULL);

	/*create UART Task to receive Data by UART*/
	xTaskCreate(UART_Task  , "UART_Task" , configMINIMAL_STACK_SIZE ,
			NULL , (3 | portPRIVILEGE_BIT) , NULL);

	/*create Keypad task to read temperature sensor*/
	xTaskCreate(KeyPad_Task  , "KeyPad_Task" , configMINIMAL_STACK_SIZE ,
			NULL , (2 | portPRIVILEGE_BIT) , NULL);

	/*create LCD task to display other tasks on LCD*/
	xTaskCreate(LCD_Task  , "LCD_Task" , configMINIMAL_STACK_SIZE,
			NULL , (4 | portPRIVILEGE_BIT) , NULL);

	/*create LED task to display other tasks on LCD*/
	xTaskCreate(LED_Task  , "SendLED_Task" , configMINIMAL_STACK_SIZE,
			NULL , (4 | portPRIVILEGE_BIT) , NULL);

	/*suspend this task*/
	vTaskSuspend(InitTask_Flag);
}

/*******************************************************************************
 * Function Name:	PushButtonA_Task
 *
 * Description: 	Push Button ATask
 *
 * Inputs:			pointer to void
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void PushButton_Task(void * a_Task_ptr)
{
	vTaskDelay(50);
	/* Data is sent to LCD by Queue*/
	uint8 SendData = 1;
	/*de_bouncing Flag to make sure key is pressed*/
	uint8 Debouncing = 0;

	/*comparing value to check if key is pressed*/
	uint8 OldPressedValue = 0;

	while(1)
	{
		/*Check if Button is pressed and enable de_bouncing*/
		if(Debouncing == 0 && Buttons_getPressedButton()==2)
		{
			OldPressedValue =  Buttons_getPressedButton();
			Debouncing++;
			/*de_bouncing Delay*/
			vTaskDelay(10);
		}
		else if(Debouncing == 1)
		{
			/*check if button is still pressed after de_bouncing time*/
			while(OldPressedValue == Buttons_getPressedButton())
			{
				SendData = 1;
				/*Send push Button was pressed to Lcd by queue*/
				xQueueSend(Queue_PushButton , &SendData , 5);
				xQueueSend(Queue_PushButton , &SendData , 5);
				xQueueSend(Queue_PushButton , &SendData , 5);

				vTaskDelay(50);
			}
			Debouncing = 2;
		}
		else if(Debouncing == 2)
		{
			SendData = 0;
			/*Send push Button was released to Lcd by queue*/
			Debouncing = 0;
			vTaskDelay(50);
		}
		else
		{
			/*Send push Button is in Idle state to Lcd by queue*/
			SendData = 3;
			xQueueSend(Queue_PushButton , &SendData , 5);
			xQueueSend(Queue_PushButton , &SendData , 5);
			xQueueSend(Queue_PushButton , &SendData , 5);
			vTaskDelay(50);
		}
	}
}

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
void KeyPad_Task(void * a_Task_ptr)
{
	/*de_bouncing Flag to make sure key is pressed*/
	uint8 Debouncing = 0;

	/*comparing value to check if key is pressed*/
	uint8 OldPressedValue = 0;

	while(1)
	{
		/*Start of pressing on button*/
		if(Debouncing == 0 && KeyPad_getPressedKey()!=10)
		{
			OldPressedValue =  KeyPad_getPressedKey();
			Debouncing++;
			vTaskDelay(10);
		}
		/*Check on de_bouncing*/
		else if(Debouncing == 1)
		{
			if(OldPressedValue == KeyPad_getPressedKey())
			{
				/*send pressed key to LCD & UART*/
				xQueueSend(Queue_Keypad_Task , &OldPressedValue , 5);
				xQueueSend(Queue_Keypad_Task , &OldPressedValue , 5);
				while(OldPressedValue == KeyPad_getPressedKey())
				{
					vTaskDelay(50);
				}
			}
			else
			{
				/*Do Nothing*/
			}
			Debouncing++;
			vTaskDelay(50);
		}
		else
		{
			Debouncing = 0;
			vTaskDelay(50);
		}
	}
}


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
void LCD_Task(void * a_Task_ptr)
{
	vTaskDelay(100);
	/*received data from Push Button Task to display button state on LCD*/
	uint8 PushButton_Task_Data = 0;

	/*received message from ADC Task to display button state on LCD*/
	uint8 Keypad_Task_Data = 0;

	/*received message from UART Task to display button state on LCD*/
	uint8 UART_Task_Data = 0;

	/*dummy & TenPowerDigit & DigitCounter buffers to convert integer number to string*/
	uint8 Keypad_ReadFlag = 0;
	uint8 ReceivedTimeCounter = 0;

	/*LCD strings*/
	uint8 Send_String[] = "Send Data= ";
	uint8 Received_String[] = "Received Data= ";
	uint8 Spaces_String[] = "                ";
	while(1)
	{
		/*receive messages from other tasks by queues*/
		xQueueReceive(Queue_PushButton , &PushButton_Task_Data , 10);
		xQueueReceive(Queue_ReceivedUART_Task, &UART_Task_Data , 10);


		/*Clear Send String row if Push button is pressed*/
		if(PushButton_Task_Data == 1)
		{
			LCD_displayStringRowColumn(0 , 0 , Spaces_String);
			Keypad_ReadFlag = 0;
			PushButton_Task_Data = 0;
		}
		/*display key value that will be sent*/
		if(Keypad_ReadFlag == 0)
		{
			xQueueReceive(Queue_Keypad_Task , &Keypad_Task_Data , 5);
			if((Keypad_Task_Data >= 1) && (Keypad_Task_Data <= 9))
			{
				LCD_displayStringRowColumn(0 , 0 , Send_String);
				LCD_displayCharacter(Keypad_Task_Data + 48);
				Keypad_Task_Data = 10;
				Keypad_ReadFlag = 1;
			}
		}

		/*display Value that will be received by UART*/
		if(UART_Task_Data != 0x00)
		{
			LCD_displayStringRowColumn(1 , 0 , Received_String);
			LCD_displayCharacter(UART_Task_Data + 48);
			UART_Task_Data = 0x00;
			ReceivedTimeCounter++;
		}
		if(ReceivedTimeCounter != 0)
		{
			if(ReceivedTimeCounter < 40)
			{
				ReceivedTimeCounter++;
			}
			else
			{
				/*Clear Received Data row */
				ReceivedTimeCounter = 0;
				LCD_displayStringRowColumn(1 , 0 , Spaces_String);
			}
		}
		vTaskDelay(50);
	}
}

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
void UART_Task(void * a_Task_ptr)
{
	/*Parameter that can get queues values*/
	vTaskDelay(100);
	uint8 UART_ReceivedData = 0;
	uint8 PushButton_PressedCheck = 0;
	uint8 UART_SendData = 0;
	while(1)
	{
		xQueueReceive(Queue_PushButton , &PushButton_PressedCheck , 10);
		/*receive data from UART*/
		UART_ReceivedData = USART_DataRegister;
		if(UART_ReceivedData != 0x00)
		{
			/* Data is sent to LCD by Queue*/
			xQueueSend(Queue_ReceivedUART_Task , &UART_ReceivedData , 5);
			xQueueSend(Queue_ReceivedUART_Task , &UART_ReceivedData , 5);
		}
		else
		{
			/*Do Nothing*/
		}

		/*check if UART can send data*/
		if(PushButton_PressedCheck == 1)
		{
			xQueueReceive(Queue_Keypad_Task , &UART_SendData , 5);
			/*send data by UART*/
			USART_DataRegister = UART_SendData;
			UART_SendData = 0;
			PushButton_PressedCheck = 0;
		}
		else
		{
			/*Do Nothing*/
		}
		vTaskDelay(50);
	}
}

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
void LED_Task(void * a_Task_ptr)
{
	/*Parameter that receive queues values*/
	uint8 PushButton_Check = 0;
	uint8 ReceivedMessage_Check = 0;
	uint8 SendLED_Counter = 0;
	uint8 ReceivedLED_Counter = 0;
	while(1)
	{
		if(SendLED_Counter == 0)
		{
			xQueueReceive(Queue_PushButton , &PushButton_Check , 10);
		}
		if(ReceivedLED_Counter == 0)
		{
			xQueueReceive(Queue_ReceivedUART_Task , &ReceivedMessage_Check , 10);
		}
		/* check if any message is sent*/
		if (PushButton_Check == 1)
		{
			/*LED ON*/
			DIO_WritePin(DIO_PIN13 , HIGH);
			SendLED_Counter++;
			PushButton_Check = 0;
		}

		/*to make LED off after specific time*/
		if(SendLED_Counter != 0)
		{
			if(SendLED_Counter < 3)
			{
				SendLED_Counter++;
			}
			else
			{
				/*LED OFF*/
				DIO_WritePin(DIO_PIN13 , LOW);
				SendLED_Counter = 0;
			}
		}

		/*check if Data is received*/
		if(ReceivedMessage_Check != 0x00)
		{
			/*LED ON*/
			DIO_WritePin(DIO_PIN12 , HIGH);
			ReceivedLED_Counter++;
			ReceivedMessage_Check = 0x00;
		}

		/*to make LED off after specific time*/
		if(ReceivedLED_Counter != 0)
		{
			if(ReceivedLED_Counter < 6)
			{
				ReceivedLED_Counter++;
			}
			else
			{
				/*LED OFF*/
				DIO_WritePin(DIO_PIN12 , LOW);
				ReceivedLED_Counter = 0;
			}
		}
		vTaskDelay(50);
	}
}

