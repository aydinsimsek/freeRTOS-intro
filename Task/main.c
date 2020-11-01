#include <FreeRTOS.h>
#include <task.h>
#include <stdint.h>
#include <stdio.h> 

uint32_t SystemCoreClock = 16000000; // Clock frequency is 16 MHz  

void Task(void *pvParameters); 

TaskHandle_t TaskHandle = NULL; 
 
int main()
{ 
	xTaskCreate(Task, "Task", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
	vTaskStartScheduler(); 
	while(1)
	{
		
	}		
}

void Task(void *pvParameters)
{
	const TickType_t xDelay = 16000 / configCPU_CLOCK_HZ;  // 1 ms delay 
	while(1)
	{
		  printf("Hey, what's up?");    
			vTaskDelay(xDelay); 
	}
}
