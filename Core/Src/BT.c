/*
 * BT.c
 *
 *  Created on: Jan 29, 2022
 *      Author: fdereli
 */

/* Includes ------------------------------------------------------------------*/

#include "BT.h"
/* Private variables ---------------------------------------------------------*/

extern UART_HandleTypeDef BT_UART;
uint8_t BT_TxDataBuffer[BT_UART_TX_BUF_SIZE];
uint8_t BT_RxDataBuffer[BT_UART_RX_BUF_SIZE];
uint16_t BT_RxCharCounter = 0;

/* Private functions ---------------------------------------------------------*/

void BT_RxData(void)
{
	uint8_t rxChar;
	uint32_t tmp_state = 0;

	tmp_state = BT_UART.gState;
	if((tmp_state == HAL_UART_STATE_BUSY_RX) || (tmp_state != HAL_UART_STATE_BUSY_TX_RX))
	{
		rxChar = (uint8_t)(BT_UART.Instance->DR & (uint8_t)0x00FF);
		BT_RxDataBuffer[BT_RxCharCounter] = rxChar;
		BT_RxCharCounter++;
	}

	if(BT_RxCharCounter >= BT_UART_RX_BUF_SIZE)
	{
		BT_RxCharCounter = 0;
	}

	if((BT_RxDataBuffer[BT_RxCharCounter-2] == 13) && (BT_RxDataBuffer[BT_RxCharCounter-1] == 10))
	{
		uint8_t receivedData[BT_RxCharCounter];
		for(uint16_t i=0; i<BT_RxCharCounter; i++)
		{
			receivedData[i] = BT_RxDataBuffer[i];
		}
		memset(BT_RxDataBuffer, 0x00, BT_UART_RX_BUF_SIZE*sizeof(uint8_t));
		HAL_UART_Transmit(&huart6, receivedData, BT_RxCharCounter, HAL_MAX_DELAY);
		BT_RxCharCounter = 0;

		if(strstr((const char*)receivedData, (const char*)"LEDON\r\n") != NULL)
		{
			HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
		}

		if(strstr((const char*)receivedData, (const char*)"LEDOFF\r\n") != NULL)
		{
			HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
		}

	}


}
