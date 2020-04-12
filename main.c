



#include "UserTasks.h"


void main(void)
{

	DIO_SetPinDirection(DIO_PIN12,OUTPUT);
	xTaskCreate(init_Task  , "Init_Task" , 150,
			NULL , (5 | portPRIVILEGE_BIT) , &InitTask_Flag);


	/* Start Scheduler */

	vTaskStartScheduler();





	while(1)
	{

	}
}

