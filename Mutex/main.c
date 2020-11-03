#include <FreeRTOS.h>
#include <task.h>
#include <semphr.h>
#include <stdint.h>
#include <stdio.h> 

uint32_t SystemCoreClock = 16000000; // Clock frequency is 16 MHz  

void First_Task(void *pvParameters); 
void Second_Task(void *pvParameters);

TaskHandle_t FirstHandle = NULL;
TaskHandle_t SecondHandle = NULL; 
SemaphoreHandle_t xMutex = NULL; 

char array[20]; 
int i; 

int main()
{ 
	xTaskCreate(First_Task, "First", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
	xTaskCreate(Second_Task, "Second", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
	xMutex = xSemaphoreCreateMutex(); // Create a mutex. 
	vTaskStartScheduler(); 
	while(1)
	{
		
	}
}

void First_Task(void *pvParameters)
{    
	char FirstMessage[14] = "Roses are red";  
  
	while(1)
	{
		if(xSemaphoreTake(xMutex, 0xFFFFFFFF) == pdTRUE) // If the mutex is acquired by the First_Task, print the 1st message. 
 		{
			for(i=0; i<13; i++)
			{
				array[i] = FirstMessage[i]; 
			}
			printf("First message is: %s\n", array);
			xSemaphoreGive(xMutex); // Release the mutex. 
		}		
	}
}

void Second_Task(void *pvParameters)
{  
	char SecondMessage[17] = "Violets are blue"; 
	
	while(1)
	{
		if(xSemaphoreTake(xMutex, 0xFFFFFFFF) == pdTRUE) // If the mutex is acquired by the Second_Task, print the 2nd message.  
		{
			for(i=0; i<16; i++)
			{
				array[i] = SecondMessage[i]; 
			}
			printf("Second message is: %s\n", array); 
			xSemaphoreGive(xMutex); // Release the mutex.   
		}
	}
}
