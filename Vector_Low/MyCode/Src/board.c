/*
 * @Author: Wang YongChao
 * @Date: 2020-08-30 15:54:45
 * @LastEditTime: 2020-09-02 23:20:03
 * @LastEditors: Wang YongChao
 * @Description: 
 * @FilePath: \Vector_Low\MyCode\Src\board.c
 * @开源机器人项目
 */
/* Private includes ----------------------------------------------------------*/
#include "board.h"

/* Private user code ---------------------------------------------------------*/

/**
 * @description: 板载初始化
 * @param {void} 
 * @return {void} 
 */
void Board_Init(void)
{
    Board.GPIO_Init();
    Board.PWM_Init();
    Board.USART_Init();
    Board.ENCODER_Init();
}

/**
 * @description: LED灯初始化
 * @param {void} 
 * @return {void} 
 */
void Led_Init(void)
{
    Led.Set_Power(OFF);
}

/**
 * @description: 轮子初始化
 * @param {void} 
 * @return {void} 
 */
void Wheel_Init(void)
{
    Left_Wheel.Set_Dire(FRONT);
    Left_Wheel.Set_Speed((uint32_t)0);
    Right_Wheel.Set_Dire(FRONT);
    Right_Wheel.Set_Speed((uint32_t)0);
}

void SerialPort_Init(void)
{
    PC_SerialPort.Receive_Data(PC_SerialPort.rx_data,PC_SerialPort.rx_len);
}
