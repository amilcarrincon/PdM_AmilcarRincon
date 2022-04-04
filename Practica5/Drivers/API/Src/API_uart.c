/*
 * API_uart.c
 *
 *  Created on: Apr 2, 2022
 *      Author: Amilcar Rincon Charris
 */

#include "API_uart.h"


static UART_HandleTypeDef UartHandle;


/**
  * @brief  Initializes UART3. Parameters: 9600,8,N,1
  * @retval  True if initialized correctly otherwise false.
  *
  */
bool_t uartinit(void)
{
	UartHandle.Instance = USART3;
	UartHandle.Init.BaudRate = 9600;
	UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
	UartHandle.Init.StopBits = UART_STOPBITS_1;
	UartHandle.Init.Parity = UART_PARITY_NONE;
	UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	UartHandle.Init.Mode = UART_MODE_TX_RX;
	UartHandle.Init.OverSampling = UART_OVERSAMPLING_16;

	HAL_StatusTypeDef status = HAL_UART_Init(&UartHandle);

	if (status != HAL_OK)
	{
		return false;
	}


	uint8_t msg[128];
	sprintf(msg, "UART initialization successfully. Parameters: %"PRIu32",%d,%s,%d\r\n",
			UartHandle.Init.BaudRate,
			UartHandle.Init.WordLength == UART_WORDLENGTH_8B ? 8 : 9,
			UartHandle.Init.Parity != UART_PARITY_NONE ? UartHandle.Init.Parity != UART_PARITY_EVEN ? "O" : "E" : "N",
			UartHandle.Init.StopBits == UART_STOPBITS_1 ? 1 : 2);

	HAL_UART_Transmit(&UartHandle, msg, strlen(msg), HAL_MAX_DELAY);

	return true;
}

/**
  * @brief  Sends string over UART
  * @param  pstring: Pointer to the string to be sent.
  *
  */
void uartsendString(uint8_t *pstring)
{
	if (pstring == NULL)
	{
		return;
	}

	HAL_UART_Transmit(&UartHandle, pstring, strlen(pstring), HAL_MAX_DELAY);
}

/**
  * @brief  Sends string over UART with size limit
  * @param  pstring: Pointer to the string to be sent.
  * @param  size: Number of bytes to be sent.
  *
  */
void uartSendStringSize(uint8_t *pstring, uint16_t size)
{
	if (pstring == NULL)
	{
		return;
	}

	HAL_UART_Transmit(&UartHandle, pstring, size, HAL_MAX_DELAY);
}

/**
  * @brief  Receives string over UART with size limit
  * @param  pstring: Pointer to the buffer to receive data.
  * @param  size: Number of bytes to be received.
  *
  */
void uartReceiveStringSize(uint8_t *pstring, uint16_t size)
{
	if (pstring == NULL)
	{
		return;
	}

	HAL_UART_Receive(&UartHandle, pstring, size, HAL_MAX_DELAY);
}
