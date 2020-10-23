#include <FreeRTOS.h>
#include <task.h>
#include <stdint.h>
#include <stdio.h> 

uint32_t SystemCoreClock = 16000000; // Clock frequency is 16 MHz  

void vDemoTask(void *pvParameters); 
 
int main()
{ 
	xTaskCreate(vDemoTask, "Task", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
	vTaskStartScheduler(); 
	for(;;);  
}

void vDemoTask(void *pvParameters)
{
	const TickType_t xDelay = 16000 / configCPU_CLOCK_HZ;  // 1 ms delay 
	for(;;)
	{
		  printf("Hey, what's up?");    
			vTaskDelay(xDelay); 
	}
}