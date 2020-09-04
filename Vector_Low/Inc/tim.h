/*
 * @Author: Wang YongChao
 * @Date: 2020-09-01 20:47:16
 * @LastEditTime: 2020-09-05 00:42:10
 * @LastEditors: Wang YongChao
 * @Description: 
 * @FilePath: \DesktopRobot\Vector_Low\Inc\tim.h
 * @开源机器人项目
 */
/**
  ******************************************************************************
  * File Name          : TIM.h
  * Description        : This file provides code for the configuration
  *                      of the TIM instances.
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __tim_H
#define __tim_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_TIM2_Init(void);
void MX_TIM3_Init(void);
void MX_TIM4_Init(void);

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* USER CODE BEGIN Prototypes */
void Board_PWM_Init(void);
void Board_ENCODER_Init(void);

void Left_Wheel_Set_Speed(uint32_t speed);
void Right_Wheel_Set_Speed(uint32_t speed);

Dire_t Letf_Encoder_Get_dire(void);
Dire_t Right_Encoder_Get_dire(void);
uint32_t Letf_Encoder_Get_number(void);
uint32_t Right_Encoder_Get_number(void);
void Letf_Encoder_Set_number(uint32_t number);
void Right_Encoder_Set_number(uint32_t number);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ tim_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
