/*
 * BT.h
 *
 *  Created on: Jan 29, 2022
 *      Author: fdereli
 */

#ifndef INC_BT_H_
#define INC_BT_H_

/* Includes ------------------------------------------------------------------*/

#include "stm32f4xx_hal.h"
#include "stdio.h"
#include "string.h"
#include "main.h"

/* Private defines ------------------------------------------------------------*/

#define BT_UART 					huart6
#define BT_UART_TX_BUF_SIZE			256
#define BT_UART_RX_BUF_SIZE			512

/* Function Prototypes ------------------------------------------------------------*/

void BT_RxData(void);

#endif /* INC_BT_H_ */
