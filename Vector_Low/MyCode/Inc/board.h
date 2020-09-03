/*
 * @Author: Wang YongChao
 * @Date: 2020-08-30 15:54:56
 * @LastEditTime: 2020-09-02 23:27:27
 * @LastEditors: Wang YongChao
 * @Description: 
 * @FilePath: \Vector_Low\MyCode\Inc\board.h
 * @开源机器人项目
 */
/*
 *                        _oo0oo_
 *                       o8888888o
 *                       88" . "88
 *                       (| -_- |)
 *                       0\  =  /0
 *                     ___/`---'\___
 *                   .' \\|     |// '.
 *                  / \\|||  :  |||// \
 *                 / _||||| -:- |||||- \
 *                |   | \\\  - /// |   |
 *                | \_|  ''\---/''  |_/ |
 *                \  .-\__  '-'  ___/-. /
 *              ___'. .'  /--.--\  `. .'___
 *           ."" '<  `.___\_<|>_/___.' >' "".
 *          | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *          \  \ `_.   \_ __\ /__ _/   .-` /  /
 *      =====`-.____`.___ \_____/___.-`___.-'=====
 *                        `=---='
 * 
 * 
 *      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 
 *            佛祖保佑       永不宕机     永无BUG
 */

/*
 * @Author: Wang YongChao
 * @Date: 2020-08-30 15:54:56
 * @LastEditTime: 2020-08-30 17:39:18
 * @LastEditors: Wang YongChao
 * @Description: 
 * @FilePath: \Vector_Low\MyCode\Inc\board.h
 * @开源机器人项目
 */

#ifndef _BOARD_H_
#define _BOARD_H_
#ifdef __cplusplus
 extern "C" {
#endif
/* Private includes ----------------------------------------------------------*/
#include "stdio.h"
/* Private macro -------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
typedef enum
{
    ON=0,
    OFF
}Power_t;

typedef enum 
{
    FRONT=0,
    BACK
}Dire_t;

typedef struct
{
	void (*GPIO_Init)(void);
	void (*PWM_Init)(void);
    void (*USART_Init)(void);
    void (*ENCODER_Init)(void);
}Board_t;

typedef struct
{
    Power_t power;                      //保存LED电源状态，用来获取LED电源状态
    void (*Set_Power)(Power_t power);   //设置LED灯电源开关
}Led_t;

typedef struct
{
    uint32_t speed;                     //保存轮子速度，用来获取轮子速度
    Dire_t dire;                        //保存轮子方向，用来获取轮子方向
    void (*Set_Speed)(uint32_t speed);
    void (*Set_Dire)(Dire_t dire);
}Wheel_t;

typedef struct 
{
    uint8_t *tx_data;
    uint8_t *rx_data;
    uint32_t tx_len;
    uint32_t rx_len;
    void (*Transmit_Data)(uint8_t *tx_data, uint32_t tx_len);
    void (*Receive_Data)(uint8_t *rx_data, uint32_t rx_len);
}SerialPort_t;

typedef struct 
{
    Dire_t dire;
    uint32_t number;
    Dire_t (*Get_dire)(void);
    uint32_t (*Get_number)(void);
}Encoder_t;


/* Private variables ---------------------------------------------------------*/

Board_t Board;
Led_t Led;
Wheel_t Left_Wheel;
Wheel_t Right_Wheel;
SerialPort_t PC_SerialPort;
Encoder_t Letf_Encoder;
Encoder_t Right_Encoder;
/* Private function prototypes -----------------------------------------------*/

void Board_Init(void);

void Led_Init(void);
void Wheel_Init(void);
void SerialPort_Init(void);

#ifdef __cplusplus
}
#endif
#endif

