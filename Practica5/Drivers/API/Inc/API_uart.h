/*
 * API_uart.h
 *
 *  Created on: Apr 1, 2022
 *      Author: Amilcar Rincon Charris
 */

#ifndef API_INC_API_UART_H_
#define API_INC_API_UART_H_

#include "API_debounce.h"
#include "stm32f4xx_hal_uart.h"

/**
 * @brief 	Inicializa UART3. Con los parametros: 9600, 8, N, 1
 * @retval 	True si inicializa correctamente sino false
 */
bool_t uartinit(void);

/**
 * @brief 	Envia string por el UART
 * @Parametro 	pstring: puntero al string a ser enviado
 */
void uartsendString(uint8_t *pstring);

/**
 * @brief 	Envia strip por el UART de un size limitado
 * @parametro pstring: puntero al string a ser enviado
 * @parametro size: Numero de bytes a ser enviados
 */
void uartSendStringSize(uint8_t *pstring, uint16_t size);

/**
 * @brief 	Recibe  UART.
 * @parametro pstring: puntero al buffer de data recibida
 * @parametro size: Numero de bytes a ser recibidos.
 */

#endif /* API_INC_API_UART_H_ */
