/*
 * API_debounce.h
 *
 *  Created on: Mar 26, 2022
 *      Author: Amilcar Rincon Charris
 */

#ifndef API_INC_API_DEBOUNCE_H_
#define API_INC_API_DEBOUNCE_H_

#include "API_delay.h"
#include "API_uart.h"
#include "stm32f4xx_nucleo_144.h"

/**
 * @brief Inicializa la maquina de estado anti-rebote
 */
void debounceFSM_init(void);

/**
 * @brief Actualiza la maquina de estado anti-rebote
 */
void debounceFSM_update(void);

/**
 * brief Indica si el boton ha sido presionado
 * retval True si el boton ha sido presionado sino retorna false
 */

bool_t readKey(void);

#endif /* API_INC_API_DEBOUNCE_H_ */
