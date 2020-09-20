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

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 64 * 4
};
/* Definitions for TaskLeftWheelSpeed */
osThreadId_t TaskLeftWheelSpeedHandle;
const osThreadAttr_t TaskLeftWheelSpeed_attributes = {
  .name = "TaskLeftWheelSpeed",
  .priority = (osPriority_t) osPriorityAboveNormal,
  .stack_size = 64 * 4
};
/* Definitions for TaskRightWheelSpeed */
osThreadId_t TaskRightWheelSpeedHandle;
const osThreadAttr_t TaskRightWheelSpeed_attributes = {
  .name = "TaskRightWheelSpeed",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 64 * 4
};
/* Definitions for TaskLeftEncoder */
osThreadId_t TaskLeftEncoderHandle;
const osThreadAttr_t TaskLeftEncoder_attributes = {
  .name = "TaskLeftEncoder",
  .priority = (osPriority_t) osPriorityBelowNormal,
  .stack_size = 64 * 4
};
/* Definitions for TaskRightEncoder */
osThreadId_t TaskRightEncoderHandle;
const osThreadAttr_t TaskRightEncoder_attributes = {
  .name = "TaskRightEncoder",
  .priority = (osPriority_t) osPriorityBelowNormal,
  .stack_size = 64 * 4
};
/* Definitions for TaskMPU6050 */
osThreadId_t TaskMPU6050Handle;
const osThreadAttr_t TaskMPU6050_attributes = {
  .name = "TaskMPU6050",
  .priority = (osPriority_t) osPriorityBelowNormal,
  .stack_size = 64 * 4
};
/* Definitions for TaskVL53L0 */
osThreadId_t TaskVL53L0Handle;
const osThreadAttr_t TaskVL53L0_attributes = {
  .name = "TaskVL53L0",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 64 * 4
};
/* Definitions for TaskVL6180X */
osThreadId_t TaskVL6180XHandle;
const osThreadAttr_t TaskVL6180X_attributes = {
  .name = "TaskVL6180X",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 64 * 4
};
/* Definitions for TaskTouch */
osThreadId_t TaskTouchHandle;
const osThreadAttr_t TaskTouch_attributes = {
  .name = "TaskTouch",
  .priority = (osPriority_t) osPriorityBelowNormal,
  .stack_size = 64 * 4
};
/* Definitions for TaskGoHome */
osThreadId_t TaskGoHomeHandle;
const osThreadAttr_t TaskGoHome_attributes = {
  .name = "TaskGoHome",
  .priority = (osPriority_t) osPriorityBelowNormal,
  .stack_size = 64 * 4
};
/* Definitions for TaskUpdate */
osThreadId_t TaskUpdateHandle;
const osThreadAttr_t TaskUpdate_attributes = {
  .name = "TaskUpdate",
  .priority = (osPriority_t) osPriorityHigh,
  .stack_size = 64 * 4
};
/* Definitions for TaskUsartDate */
osThreadId_t TaskUsartDateHandle;
const osThreadAttr_t TaskUsartDate_attributes = {
  .name = "TaskUsartDate",
  .priority = (osPriority_t) osPriorityAboveNormal,
  .stack_size = 64 * 4
};
/* Definitions for TaskLeftWheelDire */
osThreadId_t TaskLeftWheelDireHandle;
const osThreadAttr_t TaskLeftWheelDire_attributes = {
  .name = "TaskLeftWheelDire",
  .priority = (osPriority_t) osPriorityBelowNormal,
  .stack_size = 64 * 4
};
/* Definitions for TaskRightWheelDire */
osThreadId_t TaskRightWheelDireHandle;
const osThreadAttr_t TaskRightWheelDire_attributes = {
  .name = "TaskRightWheelDire",
  .priority = (osPriority_t) osPriorityBelowNormal,
  .stack_size = 64 * 4
};
/* Definitions for TaskPowerButton */
osThreadId_t TaskPowerButtonHandle;
const osThreadAttr_t TaskPowerButton_attributes = {
  .name = "TaskPowerButton",
  .priority = (osPriority_t) osPriorityBelowNormal,
  .stack_size = 64 * 4
};
/* Definitions for TaskRgbLed */
osThreadId_t TaskRgbLedHandle;
const osThreadAttr_t TaskRgbLed_attributes = {
  .name = "TaskRgbLed",
  .priority = (osPriority_t) osPriorityBelowNormal,
  .stack_size = 64 * 4
};
/* Definitions for QueueLeftWheelSpeed */
osMessageQueueId_t QueueLeftWheelSpeedHandle;
const osMessageQueueAttr_t QueueLeftWheelSpeed_attributes = {
  .name = "QueueLeftWheelSpeed"
};
/* Definitions for QueueRightWheelSpeed */
osMessageQueueId_t QueueRightWheelSpeedHandle;
const osMessageQueueAttr_t QueueRightWheelSpeed_attributes = {
  .name = "QueueRightWheelSpeed"
};
/* Definitions for QueueLeftEncoder */
osMessageQueueId_t QueueLeftEncoderHandle;
const osMessageQueueAttr_t QueueLeftEncoder_attributes = {
  .name = "QueueLeftEncoder"
};
/* Definitions for QueueRightEncoder */
osMessageQueueId_t QueueRightEncoderHandle;
const osMessageQueueAttr_t QueueRightEncoder_attributes = {
  .name = "QueueRightEncoder"
};
/* Definitions for QueueMPU6050 */
osMessageQueueId_t QueueMPU6050Handle;
const osMessageQueueAttr_t QueueMPU6050_attributes = {
  .name = "QueueMPU6050"
};
/* Definitions for QueueVL53L0 */
osMessageQueueId_t QueueVL53L0Handle;
const osMessageQueueAttr_t QueueVL53L0_attributes = {
  .name = "QueueVL53L0"
};
/* Definitions for QueueVL6180X */
osMessageQueueId_t QueueVL6180XHandle;
const osMessageQueueAttr_t QueueVL6180X_attributes = {
  .name = "QueueVL6180X"
};
/* Definitions for QueueTouch */
osMessageQueueId_t QueueTouchHandle;
const osMessageQueueAttr_t QueueTouch_attributes = {
  .name = "QueueTouch"
};
/* Definitions for QueueGoHome */
osMessageQueueId_t QueueGoHomeHandle;
const osMessageQueueAttr_t QueueGoHome_attributes = {
  .name = "QueueGoHome"
};
/* Definitions for QueueLeftWheelDire */
osMessageQueueId_t QueueLeftWheelDireHandle;
const osMessageQueueAttr_t QueueLeftWheelDire_attributes = {
  .name = "QueueLeftWheelDire"
};
/* Definitions for QueueRightWheelDire */
osMessageQueueId_t QueueRightWheelDireHandle;
const osMessageQueueAttr_t QueueRightWheelDire_attributes = {
  .name = "QueueRightWheelDire"
};
/* Definitions for QueuePowerButton */
osMessageQueueId_t QueuePowerButtonHandle;
const osMessageQueueAttr_t QueuePowerButton_attributes = {
  .name = "QueuePowerButton"
};
/* Definitions for QueueRgbLed */
osMessageQueueId_t QueueRgbLedHandle;
const osMessageQueueAttr_t QueueRgbLed_attributes = {
  .name = "QueueRgbLed"
};
/* Definitions for BinarySemUpdate */
osSemaphoreId_t BinarySemUpdateHandle;
const osSemaphoreAttr_t BinarySemUpdate_attributes = {
  .name = "BinarySemUpdate"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void StartTaskLeftWheelSpeed(void *argument);
void StartTaskRightWheelSpeed(void *argument);
void StartTaskLeftEncoder(void *argument);
void StartTaskRightEncoder(void *argument);
void StartTaskMPU6050(void *argument);
void StartTaskVL53L0(void *argument);
void StartTaskVL6180X(void *argument);
void StartTaskTouch(void *argument);
void StartTaskGoHome(void *argument);
void StartTaskUpdate(void *argument);
void StartTaskUsartDate(void *argument);
void StartTaskLeftWheelDire(void *argument);
void StartTaskRightWheelDire(void *argument);
void StartTaskPowerButton(void *argument);
void StartTaskRgbLed(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* Create the semaphores(s) */
  /* creation of BinarySemUpdate */
  BinarySemUpdateHandle = osSemaphoreNew(1, 1, &BinarySemUpdate_attributes);

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* creation of QueueLeftWheelSpeed */
  QueueLeftWheelSpeedHandle = osMessageQueueNew (3, sizeof(uint32_t), &QueueLeftWheelSpeed_attributes);

  /* creation of QueueRightWheelSpeed */
  QueueRightWheelSpeedHandle = osMessageQueueNew (3, sizeof(uint32_t), &QueueRightWheelSpeed_attributes);

  /* creation of QueueLeftEncoder */
  QueueLeftEncoderHandle = osMessageQueueNew (3, sizeof(uint32_t), &QueueLeftEncoder_attributes);

  /* creation of QueueRightEncoder */
  QueueRightEncoderHandle = osMessageQueueNew (3, sizeof(uint32_t), &QueueRightEncoder_attributes);

  /* creation of QueueMPU6050 */
  QueueMPU6050Handle = osMessageQueueNew (3, sizeof(uint32_t), &QueueMPU6050_attributes);

  /* creation of QueueVL53L0 */
  QueueVL53L0Handle = osMessageQueueNew (3, sizeof(uint32_t), &QueueVL53L0_attributes);

  /* creation of QueueVL6180X */
  QueueVL6180XHandle = osMessageQueueNew (3, sizeof(uint32_t), &QueueVL6180X_attributes);

  /* creation of QueueTouch */
  QueueTouchHandle = osMessageQueueNew (3, sizeof(uint32_t), &QueueTouch_attributes);

  /* creation of QueueGoHome */
  QueueGoHomeHandle = osMessageQueueNew (3, sizeof(uint32_t), &QueueGoHome_attributes);

  /* creation of QueueLeftWheelDire */
  QueueLeftWheelDireHandle = osMessageQueueNew (3, sizeof(uint32_t), &QueueLeftWheelDire_attributes);

  /* creation of QueueRightWheelDire */
  QueueRightWheelDireHandle = osMessageQueueNew (3, sizeof(uint32_t), &QueueRightWheelDire_attributes);

  /* creation of QueuePowerButton */
  QueuePowerButtonHandle = osMessageQueueNew (3, sizeof(uint32_t), &QueuePowerButton_attributes);

  /* creation of QueueRgbLed */
  QueueRgbLedHandle = osMessageQueueNew (3, sizeof(uint32_t), &QueueRgbLed_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of TaskLeftWheelSpeed */
  TaskLeftWheelSpeedHandle = osThreadNew(StartTaskLeftWheelSpeed, NULL, &TaskLeftWheelSpeed_attributes);

  /* creation of TaskRightWheelSpeed */
  TaskRightWheelSpeedHandle = osThreadNew(StartTaskRightWheelSpeed, NULL, &TaskRightWheelSpeed_attributes);

  /* creation of TaskLeftEncoder */
  TaskLeftEncoderHandle = osThreadNew(StartTaskLeftEncoder, NULL, &TaskLeftEncoder_attributes);

  /* creation of TaskRightEncoder */
  TaskRightEncoderHandle = osThreadNew(StartTaskRightEncoder, NULL, &TaskRightEncoder_attributes);

  /* creation of TaskMPU6050 */
  TaskMPU6050Handle = osThreadNew(StartTaskMPU6050, NULL, &TaskMPU6050_attributes);

  /* creation of TaskVL53L0 */
  TaskVL53L0Handle = osThreadNew(StartTaskVL53L0, NULL, &TaskVL53L0_attributes);

  /* creation of TaskVL6180X */
  TaskVL6180XHandle = osThreadNew(StartTaskVL6180X, NULL, &TaskVL6180X_attributes);

  /* creation of TaskTouch */
  TaskTouchHandle = osThreadNew(StartTaskTouch, NULL, &TaskTouch_attributes);

  /* creation of TaskGoHome */
  TaskGoHomeHandle = osThreadNew(StartTaskGoHome, NULL, &TaskGoHome_attributes);

  /* creation of TaskUpdate */
  TaskUpdateHandle = osThreadNew(StartTaskUpdate, NULL, &TaskUpdate_attributes);

  /* creation of TaskUsartDate */
  TaskUsartDateHandle = osThreadNew(StartTaskUsartDate, NULL, &TaskUsartDate_attributes);

  /* creation of TaskLeftWheelDire */
  TaskLeftWheelDireHandle = osThreadNew(StartTaskLeftWheelDire, NULL, &TaskLeftWheelDire_attributes);

  /* creation of TaskRightWheelDire */
  TaskRightWheelDireHandle = osThreadNew(StartTaskRightWheelDire, NULL, &TaskRightWheelDire_attributes);

  /* creation of TaskPowerButton */
  TaskPowerButtonHandle = osThreadNew(StartTaskPowerButton, NULL, &TaskPowerButton_attributes);

  /* creation of TaskRgbLed */
  TaskRgbLedHandle = osThreadNew(StartTaskRgbLed, NULL, &TaskRgbLed_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
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
  /* USER CODE BEGIN StartDefaultTask */
  osStatus_t status;
  Encoder_t *Encoder=NULL;
  Button_t *Button=NULL;
  /* Infinite loop */
  for(;;)
  {
#if 1
    Left_Wheel.speed=10;
    status=osMessageQueuePut(QueueLeftWheelSpeedHandle,&Left_Wheel,0,osWaitForever);
    if (status == osOK)
    {

    }

    Right_Wheel.speed=10;
    status=osMessageQueuePut(QueueRightWheelSpeedHandle,&Right_Wheel,0,osWaitForever);
    if (status == osOK)
    {

    }

    status=osMessageQueueGet(QueueLeftEncoderHandle,(void *)Encoder,NULL,0);
    if (status == osOK)
    {
      // ?=Encoder->number;
      // ?=Encoder->dire;
    }

    status=osMessageQueueGet(QueueRightEncoderHandle,(void *)Encoder,NULL,0);
    if (status == osOK)
    {
      // ?=Encoder->number;
      // ?=Encoder->dire;
    }

    Left_Wheel.dire=FRONT;
    status=osMessageQueuePut(QueueLeftWheelSpeedHandle,&Left_Wheel,0,osWaitForever);
    if (status == osOK)
    {

    }

    Right_Wheel.dire=FRONT;
    status=osMessageQueuePut(QueueLeftWheelSpeedHandle,&Right_Wheel,0,osWaitForever);
    if (status == osOK)
    {

    }

    Led_R.power=ON;
    status=osMessageQueuePut(QueueRgbLedHandle,&Led_R,0,osWaitForever);
    if (status == osOK)
    {

    }

    Led_G.power=ON;
    status=osMessageQueuePut(QueueRgbLedHandle,&Led_G,0,osWaitForever);
    if (status == osOK)
    {

    }

    Led_B.power=ON;
    status=osMessageQueuePut(QueueRgbLedHandle,&Led_B,0,osWaitForever);
    if (status == osOK)
    {

    }

    status=osMessageQueueGet(QueuePowerButtonHandle,(void *)Button,NULL,0);
    if (status == osOK)
    {
      // ?=Button->updown;
    }

    status=osMessageQueueGet(QueueTouchHandle,(void *)Button,NULL,0);
    if (status == osOK)
    {
      // ?=Button->updown;
    }

    status=osMessageQueueGet(QueueGoHomeHandle,(void *)Button,NULL,0);
    if (status == osOK)
    {
      // ?=Button->updown;
    }

    status=osSemaphoreRelease(BinarySemUpdateHandle);
    if (status == osOK)
    {

    }

#endif

    osDelay(1000);

  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_StartTaskLeftWheelSpeed */
/**
* @brief Function implementing the TaskLeftWheelSpeed thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskLeftWheelSpeed */
void StartTaskLeftWheelSpeed(void *argument)
{
  /* USER CODE BEGIN StartTaskLeftWheelSpeed */
  osStatus_t status;
  Wheel_t *Wheel=NULL;
  /* Infinite loop */
  for(;;)
  {
    status=osMessageQueueGet(QueueLeftWheelSpeedHandle,(void*)Wheel,NULL,osWaitForever);
    if(status == osOK)
    {
      Wheel->Set_Speed(Wheel->speed);
    }
    //osDelay(1);
  }
  /* USER CODE END StartTaskLeftWheelSpeed */
}

/* USER CODE BEGIN Header_StartTaskRightWheelSpeed */
/**
* @brief Function implementing the TaskRightWheelSpeed thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskRightWheelSpeed */
void StartTaskRightWheelSpeed(void *argument)
{
  /* USER CODE BEGIN StartTaskRightWheelSpeed */
  osStatus_t status;
  Wheel_t *Wheel=NULL;
  /* Infinite loop */
  for(;;)
  {
    status=osMessageQueueGet(QueueRightWheelSpeedHandle,(void*)Wheel,NULL,osWaitForever);
    if(status == osOK)
    {
      Wheel->Set_Speed(Wheel->speed);
    }
    // osDelay(1);
  }
  /* USER CODE END StartTaskRightWheelSpeed */
}

/* USER CODE BEGIN Header_StartTaskLeftEncoder */
/**
* @brief Function implementing the TaskLeftEncoder thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskLeftEncoder */
void StartTaskLeftEncoder(void *argument)
{
  /* USER CODE BEGIN StartTaskLeftEncoder */
  osStatus_t status;
  /* Infinite loop */
  for(;;)
  {
    osDelayUntil (100);
    Left_Encoder.number=Left_Encoder.Get_number();
    Left_Encoder.Set_number(0);
    status=osMessageQueuePut(QueueLeftEncoderHandle,&Left_Encoder,0,osWaitForever);
    if (status == osOK)
    {

    }
    // osDelay(1);
  }
  /* USER CODE END StartTaskLeftEncoder */
}

/* USER CODE BEGIN Header_StartTaskRightEncoder */
/**
* @brief Function implementing the TaskRightEncoder thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskRightEncoder */
void StartTaskRightEncoder(void *argument)
{
  /* USER CODE BEGIN StartTaskRightEncoder */
  osStatus_t status;
  /* Infinite loop */
  for(;;)
  {
    osDelayUntil (100);
    Right_Encoder.number=Right_Encoder.Get_number();
    Right_Encoder.Set_number(0);
    status=osMessageQueuePut(QueueRightEncoderHandle,&Right_Encoder,0,osWaitForever);
    if (status == osOK)
    {

    }
    // osDelay(1);
  }
  /* USER CODE END StartTaskRightEncoder */
}

/* USER CODE BEGIN Header_StartTaskMPU6050 */
/**
* @brief Function implementing the TaskMPU6050 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskMPU6050 */
void StartTaskMPU6050(void *argument)
{
  /* USER CODE BEGIN StartTaskMPU6050 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartTaskMPU6050 */
}

/* USER CODE BEGIN Header_StartTaskVL53L0 */
/**
* @brief Function implementing the TaskVL53L0 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskVL53L0 */
void StartTaskVL53L0(void *argument)
{
  /* USER CODE BEGIN StartTaskVL53L0 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartTaskVL53L0 */
}

/* USER CODE BEGIN Header_StartTaskVL6180X */
/**
* @brief Function implementing the TaskVL6180X thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskVL6180X */
void StartTaskVL6180X(void *argument)
{
  /* USER CODE BEGIN StartTaskVL6180X */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartTaskVL6180X */
}

/* USER CODE BEGIN Header_StartTaskTouch */
/**
* @brief Function implementing the TaskTouch thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskTouch */
void StartTaskTouch(void *argument)
{
  /* USER CODE BEGIN StartTaskTouch */
  osStatus_t status;
  /* Infinite loop */
  for(;;)
  {
    osDelayUntil (100);
    Touch_Button.updown=Touch_Button.Get_updown();
    status=osMessageQueuePut(QueueTouchHandle,&Touch_Button,0,osWaitForever);
    if (status == osOK)
    {

    }
    //osDelay(1);
  }
  /* USER CODE END StartTaskTouch */
}

/* USER CODE BEGIN Header_StartTaskGoHome */
/**
* @brief Function implementing the TaskGoHome thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskGoHome */
void StartTaskGoHome(void *argument)
{
  /* USER CODE BEGIN StartTaskGoHome */
  osStatus_t status;
  /* Infinite loop */
  for(;;)
  {
    osDelayUntil (100);
    GoHome_Button.updown=GoHome_Button.Get_updown();
    status=osMessageQueuePut(QueueGoHomeHandle,&GoHome_Button,0,osWaitForever);
    if (status == osOK)
    {

    }
    //osDelay(1);
  }
  /* USER CODE END StartTaskGoHome */
}

/* USER CODE BEGIN Header_StartTaskUpdate */
/**
* @brief Function implementing the TaskUpdate thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskUpdate */
void StartTaskUpdate(void *argument)
{
  /* USER CODE BEGIN StartTaskUpdate */
  osStatus_t status;
  /* Infinite loop */
  for(;;)
  {
    status=osSemaphoreAcquire(BinarySemUpdateHandle,osWaitForever);
    if (status == osOK)
    {

    }
    // osDelay(1);
  }
  /* USER CODE END StartTaskUpdate */
}

/* USER CODE BEGIN Header_StartTaskUsartDate */
/**
* @brief Function implementing the TaskUsartDate thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskUsartDate */
void StartTaskUsartDate(void *argument)
{
  /* USER CODE BEGIN StartTaskUsartDate */
  /* Infinite loop */
  for(;;)
  {
    osDelayUntil (100);

    // osDelay(1);
  }
  /* USER CODE END StartTaskUsartDate */
}

/* USER CODE BEGIN Header_StartTaskLeftWheelDire */
/**
* @brief Function implementing the TaskLeftWheelDire thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskLeftWheelDire */
void StartTaskLeftWheelDire(void *argument)
{
  /* USER CODE BEGIN StartTaskLeftWheelDire */
  osStatus_t status;
  Wheel_t *Wheel=NULL;
  /* Infinite loop */
  for(;;)
  {
    status=osMessageQueueGet(QueueLeftWheelDireHandle,(void*)Wheel,NULL,osWaitForever);
    if(status == osOK)
    {
      Wheel->Set_Dire(Wheel->dire);
    }
    //osDelay(1);
  }
  /* USER CODE END StartTaskLeftWheelDire */
}

/* USER CODE BEGIN Header_StartTaskRightWheelDire */
/**
* @brief Function implementing the TaskRightWheelDire thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskRightWheelDire */
void StartTaskRightWheelDire(void *argument)
{
  /* USER CODE BEGIN StartTaskRightWheelDire */
  osStatus_t status;
  Wheel_t *Wheel=NULL;
  /* Infinite loop */
  for(;;)
  {
    status=osMessageQueueGet(QueueRightWheelDireHandle,(void*)Wheel,NULL,osWaitForever);
    if(status == osOK)
    {
      Wheel->Set_Dire(Wheel->dire);
    }
    //osDelay(1);
  }
  /* USER CODE END StartTaskRightWheelDire */
}

/* USER CODE BEGIN Header_StartTaskPowerButton */
/**
* @brief Function implementing the TaskPowerButton thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskPowerButton */
void StartTaskPowerButton(void *argument)
{
  /* USER CODE BEGIN StartTaskPowerButton */
  osStatus_t status;
  /* Infinite loop */
  for(;;)
  {
    osDelayUntil (100);
    Power_Button.updown=Power_Button.Get_updown();
    status=osMessageQueuePut(QueuePowerButtonHandle,&Power_Button,0,osWaitForever);
    if (status == osOK)
    {

    }
    //osDelay(1);
  }
  /* USER CODE END StartTaskPowerButton */
}

/* USER CODE BEGIN Header_StartTaskRgbLed */
/**
* @brief Function implementing the TaskRgbLed thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskRgbLed */
void StartTaskRgbLed(void *argument)
{
  /* USER CODE BEGIN StartTaskRgbLed */
  osStatus_t status;
  Led_t *Led=NULL;
  /* Infinite loop */
  for(;;)
  {
    status=osMessageQueueGet(QueueRgbLedHandle,(void*)Led,NULL,osWaitForever);
    if(status == osOK)
    {
      Led->Set_Power(Led->power);
    }
    //osDelay(1);
  }
  /* USER CODE END StartTaskRgbLed */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
