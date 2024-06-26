/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
#include "led.h"


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


void vLEDAperiodicTask1(void *pvParam)
{
	//	led_toggle();
	while(1)
	{
		led_on(LED_GREEN);
		vTaskDelay(1000);
		led_off(LED_GREEN);
		vTaskDelay(1000);
	}
	vTaskDelete(NULL);
}

void vLEDAperiodicTask2(void *pvParam)
{
	//	led_toggle();
	while(1)
	{
		led_on(LED_ORANGE);
		vTaskDelay(2000);
		led_off(LED_ORANGE);
		vTaskDelay(2000);
	}
	  vTaskDelete(NULL);

}

void vLEDAperiodicTask3(void *pvParam)
{
	//	led_toggle();
	while(1)
	{
		led_on(LED_RED);
		vTaskDelay(3000);
		led_off(LED_RED);
		vTaskDelay(3000);
	}
    	vTaskDelete(NULL);

}

void vLEDAperiodicTask4(void *pvParam)
{
	//	led_toggle();
	while(1)
	{
		led_on(LED_BLUE);
		vTaskDelay(4000);
		led_off(LED_BLUE);
		vTaskDelay(4000);
	}
    	vTaskDelete(NULL);

}



int main(void)
{
	LedInit(LED_GREEN);
	LedInit(LED_ORANGE);
	LedInit(LED_RED);
	LedInit(LED_BLUE);



	xTaskCreate(vLEDAperiodicTask1, "LED GREEN", configMINIMAL_STACK_SIZE,NULL,2,NULL);
	xTaskCreate(vLEDAperiodicTask2, "LED ORANGE", configMINIMAL_STACK_SIZE,NULL,2,NULL);
	xTaskCreate(vLEDAperiodicTask3, "LED RED", configMINIMAL_STACK_SIZE,NULL,2,NULL);
	xTaskCreate(vLEDAperiodicTask4, "LED BLUE", configMINIMAL_STACK_SIZE,NULL,2,NULL);
	vTaskStartScheduler();
	while(1);
	return 0;


}


