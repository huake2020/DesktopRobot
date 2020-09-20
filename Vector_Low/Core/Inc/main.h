/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "board.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define VL6180X_SCL_Pin GPIO_PIN_13
#define VL6180X_SCL_GPIO_Port GPIOC
#define Power_Button_Pin GPIO_PIN_0
#define Power_Button_GPIO_Port GPIOA
#define PCA9685_SDA_Pin GPIO_PIN_4
#define PCA9685_SDA_GPIO_Port GPIOA
#define PCA9685_SCL_Pin GPIO_PIN_5
#define PCA9685_SCL_GPIO_Port GPIOA
#define VL53L0_SDA_Pin GPIO_PIN_6
#define VL53L0_SDA_GPIO_Port GPIOA
#define VL53L0_SCL_Pin GPIO_PIN_7
#define VL53L0_SCL_GPIO_Port GPIOA
#define LED_R_Pin GPIO_PIN_0
#define LED_R_GPIO_Port GPIOB
#define LED_G_Pin GPIO_PIN_1
#define LED_G_GPIO_Port GPIOB
#define LED_B_Pin GPIO_PIN_2
#define LED_B_GPIO_Port GPIOB
#define VL6180X_SDA_FL_Pin GPIO_PIN_10
#define VL6180X_SDA_FL_GPIO_Port GPIOB
#define VL6180X_SDA_FR_Pin GPIO_PIN_11
#define VL6180X_SDA_FR_GPIO_Port GPIOB
#define L_Dire1_Pin GPIO_PIN_12
#define L_Dire1_GPIO_Port GPIOB
#define L_Dire2_Pin GPIO_PIN_13
#define L_Dire2_GPIO_Port GPIOB
#define R_Dire1_Pin GPIO_PIN_14
#define R_Dire1_GPIO_Port GPIOB
#define R_Dire2_Pin GPIO_PIN_15
#define R_Dire2_GPIO_Port GPIOB
#define MPU6050_Input_Pin GPIO_PIN_8
#define MPU6050_Input_GPIO_Port GPIOA
#define VL6180X_SDA_BL_Pin GPIO_PIN_11
#define VL6180X_SDA_BL_GPIO_Port GPIOA
#define VL6180X_SDA_BR_Pin GPIO_PIN_12
#define VL6180X_SDA_BR_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
