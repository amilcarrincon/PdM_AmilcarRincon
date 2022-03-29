/*
 * API_delay.c
 *
 *  Created on: Mar 19, 2022
 *      Author: gianfranco
 */


#include "API_delay.h"

/**
  * @brief  Initializes non-blocking delay.
  * @param  delay: Delay to be initialized.
  * @param  duration: Delay duration in ms.
  *
  */
void delayInit(delay_t *delay, tick_t duration)
{
	/* Checking received parameters */
	if (delay == NULL || duration == 0)
	{
		return;
	}

	/* Initializing delay */
	delay->duration = duration;
	delay->running = false;
}

/**
  * @brief  Checks if delay has elapsed
  * @param  delay: Delay to be checked.
  *
  * @retval True if the delay has elapsed, otherwise False.
  */
bool_t delayRead(delay_t * delay)
{
	bool_t result = false;

	/* Checking received parameters */
	if (delay == NULL)
	{
		return result;
	}

	if (delay->running)
	{
		/* Delay is running. Checking if the delay has elapsed. */
		if ((HAL_GetTick() - delay->startTime) >= delay->duration)
		{
			/* Delay has elapsed */
			delay->startTime = HAL_GetTick();
			result =  true;
		}
	}
	else
	{
		/* Delay is not running. Taking timestamp and switching to running. */
		delay->startTime = HAL_GetTick();
		delay->running = true;
	}

	return result;
}

/**
  * @brief  Changes delay duration.
  * @param  delay: Delay to be initialized.
  * @param  duration: Delay duration in ms.
  *
  */
void delayWrite(delay_t *delay, tick_t duration)
{
	/* Checking received parameters */
	if (delay == NULL || duration == 0)
	{
		return;
	}

	delay->duration = duration;

	/* Resetting the delay in case it is running. */
	delay->startTime = HAL_GetTick();
}
