/*
 * API_debounce.h
 *
 *  Created on: Mar 26, 2022
 *      Author: gianfranco
 */

#ifndef API_INC_API_DEBOUNCE_H_
#define API_INC_API_DEBOUNCE_H_

#include "API_delay.h"
#include "stm32f4xx_nucleo_144.h"


void debounceFSM_init(void);

void debounceFSM_update(void);

bool_t readKey(void);

#endif /* API_INC_API_DEBOUNCE_H_ */
