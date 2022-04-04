/*
 * API_debounce.c
 *
 *  Created on: Mar 26, 2022
 *      Author: Amilcar Rincon Charris
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

/**
 * @brief Inicializa la maquina de estado anti-rebote
 */

void debounceFSM_init(void) {
	buttonState = BUTTON_UP;
}

/**
 * @brief Actualiza la maquina de estado anti-rebote
 */
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
				uartsendString("Rising edge detected\r\n");
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
				uartsendString("Falling edge detected\r\n");
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

/**
 * @brief Indica si el boton ha sido presionado
 * @retval True si el boton ha sido presionado sino retorna false
 */


bool_t readKey(void) {
	if (buttonPressed) {
		buttonPressed = false;
		return true;
	} else {
		return false;
	}
}
