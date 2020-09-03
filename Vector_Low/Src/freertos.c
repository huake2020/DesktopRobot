/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* Definitions for led_powerTask */
osThreadId_t led_powerTaskHandle;
const osThreadAttr_t led_powerTask_attributes = {
  .name = "led_powerTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};

osThreadId_t left_direTaskHandle;
const osThreadAttr_t left_direTask_attributes = {
  .name = "left_direTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};
osThreadId_t left_speedTaskHandle;
const osThreadAttr_t left_speedTask_attributes = {
  .name = "left_speedTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};
osThreadId_t right_direTaskHandle;
const osThreadAttr_t right_direTask_attributes = {
  .name = "right_direTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};
osThreadId_t right_speedTaskHandle;
const osThreadAttr_t right_speedTask_attributes = {
  .name = "right_speedTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};

osMutexId_t pc_tx_dataTaskHandle;
const osThreadAttr_t pc_tx_dataTask_attributes = {
  .name = "pc_tx_dataTask",
  .priority = (osPriority_t) osPriorityAboveNormal,
  .stack_size = 128 * 4
};

/* Definitions for led_powerQueue */
osMessageQueueId_t led_powerQueueHandle;
const osMessageQueueAttr_t led_powerQueue_attributes = {
  .name = "led_powerQueue"
};

osMessageQueueId_t left_direQueueHandle;
const osMessageQueueAttr_t left_direQueue_attributes = {
  .name = "left_direQueue"
};
osMessageQueueId_t left_speedQueueHandle;
const osMessageQueueAttr_t left_speedQueue_attributes = {
  .name = "left_speedQueue"
};

osMessageQueueId_t right_direQueueHandle;
const osMessageQueueAttr_t right_direQueue_attributes = {
  .name = "right_direQueue"
};
osMessageQueueId_t right_speedQueueHandle;
const osMessageQueueAttr_t right_speedQueue_attributes = {
  .name = "right_speedQueue"
};

osMessageQueueId_t pc_tx_dataQueueHandle;
const osMessageQueueAttr_t pc_tx_dataQueue_attributes = {
  .name = "pc_tx_dataQueue"
};

osMutexId_t pc_tx_dataMutexHandle;
const osMutexAttr_t pc_tx_dataMutex_attributes ={
  .name = "pc_tx_dataMutex"
};

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};
/* Definitions for defaultQueue */
osMessageQueueId_t defaultQueueHandle;
const osMessageQueueAttr_t defaultQueue_attributes = {
  .name = "defaultQueue"
};
/* Definitions for defaultMutex */
osMutexId_t defaultMutexHandle;
const osMutexAttr_t defaultMutex_attributes = {
  .name = "defaultMutex"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
void StartLedPowerTask(void *argument);

void StartLeftDireTask(void *argument);
void StartLeftSpeedTask(void *argument);

void StartRightDireTask(void *argument);
void StartRightSpeedTask(void *argument);

void StartPcTxDataTask(void *argument);

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);

extern void MX_USB_DEVICE_Init(void);
void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */
  /* Create the mutex(es) */
  /* creation of defaultMutex */
  defaultMutexHandle = osMutexNew(&defaultMutex_attributes);

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  pc_tx_dataMutexHandle = osMutexNew(&pc_tx_dataMutex_attributes);
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* creation of defaultQueue */
  defaultQueueHandle = osMessageQueueNew (16, sizeof(uint32_t), &defaultQueue_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */

  /* creation of defaultQueue */
  led_powerQueueHandle = osMessageQueueNew (16, sizeof(uint32_t), &led_powerQueue_attributes);

  left_direQueueHandle = osMessageQueueNew (16, sizeof(uint32_t), &left_direQueue_attributes);
  left_speedQueueHandle = osMessageQueueNew (16, sizeof(uint32_t), &left_speedQueue_attributes);

  right_direQueueHandle = osMessageQueueNew (16, sizeof(uint32_t), &right_direQueue_attributes);
  right_speedQueueHandle = osMessageQueueNew (16, sizeof(uint32_t), &right_speedQueue_attributes);

  pc_tx_dataQueueHandle = osMessageQueueNew (16, sizeof(uint32_t), &pc_tx_dataQueue_attributes);
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */

  /* creation of ledTask */
  led_powerTaskHandle = osThreadNew(StartLedPowerTask, NULL, &led_powerTask_attributes);

  left_direTaskHandle = osThreadNew(StartLedPowerTask, NULL, &left_direTask_attributes);
  left_speedTaskHandle = osThreadNew(StartLedPowerTask, NULL, &left_speedTask_attributes);

  right_direTaskHandle = osThreadNew(StartLedPowerTask, NULL, &right_direTask_attributes);
  right_speedTaskHandle = osThreadNew(StartLedPowerTask, NULL, &right_speedTask_attributes);

  pc_tx_dataTaskHandle = osThreadNew(StartPcTxDataTask, NULL, &pc_tx_dataTask_attributes); 
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* init code for USB_DEVICE */
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
#define LED_Test 1
#if LED_Test
  osStatus_t status;
  Power_t power = OFF;
  while (1)
  {
    status = osMessageQueuePut(led_powerQueueHandle,&power,0,osWaitForever);
    if (status == osOK)
    {
      if(Led.power == ON)
      {
        power = OFF;
      }else
      {
        power = ON;
      }
      osDelay(100);
    }
  }

#else

  while (1)
  {
    /* code */
  }
  
#endif

  /* USER CODE END StartDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
void StartLedPowerTask(void *argument)
{
  osStatus_t status;
  Power_t power = OFF;
  while (1)
  {
    status = osMessageQueueGet(led_powerQueueHandle,&power,NULL,osWaitForever);
    if(status == osOK)
    {
      switch (power)
      {
      case ON:
        Led.Set_Power(ON);
        Led.power=ON;
        break;
      case OFF:
        Led.Set_Power(OFF);
        Led.power=OFF;
        break;
      default:
        break;
      }
    }
  }
}

void StartLeftDireTask(void *argument)
{
  osStatus_t status;
  Dire_t dire = FRONT;
  while (1)
  {
    status = osMessageQueueGet(left_direQueueHandle,&dire,NULL,osWaitForever);
    if(status == osOK)
    {
      switch (dire)
      {
      case FRONT:
        Left_Wheel.Set_Dire(FRONT);
        Left_Wheel.dire=FRONT;
        break;
      case BACK:
        Left_Wheel.Set_Dire(BACK);
        Left_Wheel.dire=BACK;
        break;
      default:
        break;
      }
    }
  } 
}
void StartLeftSpeedTask(void *argument)
{
  osStatus_t status;
  uint32_t speed = 0;
  while (1)
  {
    status = osMessageQueueGet(left_direQueueHandle,&speed,NULL,osWaitForever);
    if(status == osOK)
    {
      Left_Wheel.Set_Speed(speed);
    }
  } 
}

void StartRightDireTask(void *argument)
{
  osStatus_t status;
  Dire_t dire = FRONT;
  while (1)
  {
    status = osMessageQueueGet(right_direQueueHandle,&dire,NULL,osWaitForever);
    if(status == osOK)
    {
      switch (dire)
      {
      case FRONT:
        Right_Wheel.Set_Dire(FRONT);
        Right_Wheel.dire=FRONT;
        break;
      case BACK:
        Right_Wheel.Set_Dire(BACK);
        Right_Wheel.dire=BACK;
        break;
      default:
        break;
      }
    }
  } 
}
void StartRightSpeedTask(void *argument)
{
  osStatus_t status;
  uint32_t speed = 0;
  while (1)
  {
    status = osMessageQueueGet(right_direQueueHandle,&speed,NULL,osWaitForever);
    if(status == osOK)
    {
      Right_Wheel.Set_Speed(speed);
    }
  } 
}

void StartPcTxDataTask(void *argument)
{
  osStatus_t status;
  uint8_t *tx_data=NULL;
  while(1)
  {
    status = osMutexWait(pc_tx_dataMutexHandle,osWaitForever);
    if(status == osOK)
    {
      status =osMessageQueueGet(pc_tx_dataQueueHandle,NULL,NULL,osWaitForever);
      if (status == osOK)
      {
          PC_SerialPort.Transmit_Data(PC_SerialPort.tx_data,PC_SerialPort.tx_len);
      }
      osMutexRelease(pc_tx_dataMutexHandle);
    }
  }
}
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
