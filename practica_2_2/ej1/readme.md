# TP2 PDM 

En este ejercicio, se realizan las funciones delayInit, delayRead, y delayWrite. Estas funciones realizan retardos no bloqueantes en la 
placa NUCLEO-F429ZI. La forma de invocarla, es utilizar el tipo de datos delay_t, definida en main.c. Las definiciones de estas son: 
```
#include <stdbool.h>
#include <stdint.h>
... 
typedef uint32_t tick_t;
typedef bool bool_t;
typedef struct{
   tick_t startTime;
   tick_t duration;
   bool_t running;
} delay_t;
// prototipos para manejar retardos no bloqueantes  
	void delayInit( delay_t * delay, tick_t duration );
	bool_t delayRead( delay_t * delay );
	void delayWrite( delay_t * delay, tick_t duration );
```
Donde el registro startTime, obtiene el inicio del sytem ticks, duration: la duración de cada una de ellas, y running el estado (encendido = true, apagado = false) 

La funcion delayInit, modifica el valor de duracion 

La funcion delayRead, verifica si no esta encendido, y si ha pasado el tiempo correspondiente.  En caso de que no este 
encendido, modifica el campo running, asignando el valor de true. En el caso de que al ser llamada posea un campo true en running, 
verifica si el tiempo ha transcurrido o no(este campo esta en duration). 

delayWrite modifica el registro de duración, en caso de querer cambiarse la duración del evento. 


Luego de la construcción de estas funciones, se prueban con la funcion BSP_LED_Toggle(LED1),BSP_LED_Toggle(LED2),BSP_LED_Toggle(LED3)

Adicionalmente se intento que los valores de entrada de duración de delayInit se correspondan con valores positivos. La unica forma que se encontro 
fue utilizando directivas de compilación "error", pero si cambian en tiempo de ejecución, esto es un problema, que debe resolverse y manejarse 
de alguna forma.  



# Respuestas a preguntas del TP2 

## 1 - Se pueden cambiar los tiempos de encendido de cada led fácilmente en un solo lugar del código o estos están hardcodeados?
Si, se puede. En el archivo "main.c", tiene tres macros definidas de la siguiente forma: 

```c
	#define TIME_TOOGLE_LED1 
	#define TIME_TOOGLE_LED2 
	#define TIME_TOOGLE_LED3 
```
	

## 2 - ¿Qué bibliotecas estándar se debieron agregar a API_delay.h para que el código compile? Si las funcionalidades de una API propia crecieran, habría que pensar cuál sería el mejor lugar para incluir esas bibliotecas y algunos typedefs que se usan en el ejercicio.

Las bibliotecas añadidas son "stdbool" y "stdint", que contienen las definiciones  
## 3 - ¿Es adecuado el control de los parámetros pasados por el usuario que se hace en las funciones implementadas? ¿Se controla que sean valores válidos? ¿Se controla que estén dentro de los rangos correctos?
No, ya que se pueden pasar valores negativos, y pueden provocar errores, o tiempos de retardo excesivos, esto depende de si 
usa CA2 o CA1. 
De hecho, para ver este efecto, se puede usar el debug. Aparentemente C, no tiene soporte para verificar los tipos de datos, 
intente con typename, pero no paso nada. En mi caso, para evitar esto, se utilizo la siguiente directiva de compilación 

```c
#if TIME_TOOGLE_LED_1<0 || TIME_TOOGLE_LED_2<0  || TIME_TOOGLE_LED_3<0
	#error "los valores de retardo son negativos "
#else
  delayInit(&toogle_led[LED1], TIME_TOOGLE_LED_1) ;
  delayInit(&toogle_led[LED2], TIME_TOOGLE_LED_1) ;
  delayInit(&toogle_led[LED3], TIME_TOOGLE_LED_3) ;
#endif 
```


