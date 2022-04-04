/*
 * API_delay.h
 *
 *  Created on: Mar 19, 2022
 *      Author: Amilcar Rincon Charris
 */

#ifndef API_API_DELAY_H_
#define API_API_DELAY_H_

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

#include "stm32f4xx_hal.h"

/* Exported types ------------------------------------------------------------*/
typedef uint32_t tick_t; /* from stdint.h */

typedef bool bool_t; /* from stdbool.h */

typedef struct{
   tick_t startTime;
   tick_t duration;
   bool_t running;
} delay_t;

/**
  * @brief  Initializes non-blocking delay.
  * @param  delay: Delay to be initialized.
  * @param  duration: Delay duration in ms.
  *
  */
void delayInit(delay_t *delay, tick_t duration);

/**
  * @brief  Checks if delay has elapsed
  * @param  delay: Delay to be checked.
  *
  * @retval True if the delay has elapsed, otherwise False.
  */
bool_t delayRead(delay_t *delay);

/**
  * @brief  Changes delay duration.
  * @param  delay: Delay to be initialized.
  * @param  duration: Delay duration in ms.
  *
  */
void delayWrite(delay_t *delay, tick_t duration);


#endif /* API_API_DELAY_H_ */
