/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : There are 2 tasks, StartDefaultTask and StartTask02.StartDefaultTask is default task.
  * StartTask02 is to detect whether the button has been pressed,once the button is pressed, the LED will blink 3 times.
  ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"


/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}

/**
  * @brief When the blue button is pressed, the LED LD2 will blink 3 times.
  * @param None
  * @retval None
  */
void read_a_button(void)
{
	/*
	 *The function returns the current state of the GPIO pin as either GPIO_PIN_RESET or GPIO_PIN_SET.
	 *GPIO_PIN_RESET means the pin is in a low state (0V) and GPIO_PIN_SET means the pin is in a high state (3.3V).
	 *When the button is pressed, the PIN is low, when PIN is low, the LED will blink 3 times.
	 */
	if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET)
	    {
          HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
	      osDelay(100);
	      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
	      osDelay(100);
	      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
	      osDelay(100);
	      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
	      osDelay(100);
	      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
	      osDelay(100);
	      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
	      osDelay(100);
	    }
}

/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */

void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END 5 */
}


/**
* @brief Function implementing the read_a_button thread.
* @param argument: Not used
* @retval None
*/

void StartTask02(void const * argument)
{
  /* Infinite loop */
  for(;;)
  {
    read_a_button();
  }
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
