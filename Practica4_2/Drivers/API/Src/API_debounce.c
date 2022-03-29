/*
 * API_debounce.c
 *
 *  Created on: Mar 26, 2022
 *      Author: gianfranco
 */


#include "API_debounce.h"

typedef enum{
	BUTTON_UP,
	BUTTON_FALLING,
	BUTTON_DOWN,
	BUTTON_RAISING,
} debounceState_t;

static delay_t delay_button;
static debounceState_t buttonState;
static bool_t buttonPressed = false;


void debounceFSM_init(void) {
	buttonState = BUTTON_UP;
}

void debounceFSM_update(void) {
	switch (buttonState)
	{
	case BUTTON_UP:
		delayInit(&delay_button, 40);
		if (BSP_PB_GetState(BUTTON_USER))
		{
			buttonState = BUTTON_FALLING;
		}
		break;
	case BUTTON_FALLING:
		if (delayRead(&delay_button))
		{
			if (BSP_PB_GetState(BUTTON_USER))
			{
				buttonState = BUTTON_DOWN;
			}
			else
			{
				buttonState = BUTTON_UP;
			}
		}
		break;
	case BUTTON_DOWN:
		delayInit(&delay_button, 40);
		if (!BSP_PB_GetState(BUTTON_USER))
		{
			buttonState = BUTTON_RAISING;
		}
		break;
	case BUTTON_RAISING:
		if (delayRead(&delay_button))
		{
			if (!BSP_PB_GetState(BUTTON_USER))
			{
				buttonPressed = true;
				buttonState = BUTTON_UP;
			}
			else
			{
				buttonState = BUTTON_DOWN;
			}
		}
		break;
	default:
		debounceFSM_init();
		break;
	}
}

bool_t readKey(void) {
	if (buttonPressed) {
		buttonPressed = false;
		return true;
	} else {
		return false;
	}
}
