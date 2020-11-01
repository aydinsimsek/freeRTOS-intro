#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include <stdint.h>
#include <stdio.h> 

uint32_t SystemCoreClock = 16000000; // Clock frequency is 16 MHz  

void Transmit_Task(void *pvParameters); 
void Receive_Task(void *pvParameters);

TaskHandle_t TXHandle = NULL;
TaskHandle_t RXHandle = NULL; 
QueueHandle_t QueueHandle = NULL; 

int i = 1;

int main()
{ 
	QueueHandle = xQueueCreate(10, sizeof(int)); // Create a queue that is capable of containing 10 integer values
	xTaskCreate(Transmit_Task, "Transmitter", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
	xTaskCreate(Receive_Task, "Receiver", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
	vTaskStartScheduler(); 
	while(1)
	{
		
	}
}

void Transmit_Task(void *pvParameters)
{      
	while(1)
	{
		xQueueSend(QueueHandle, &i, 0);
		printf("%d is sent\n", i);    
	}
}

void Receive_Task(void *pvParameters)
{  
	while(1)
	{
		xQueueReceive(QueueHandle, &i, 100);
		printf("%d is received\n", i);
	}
}
