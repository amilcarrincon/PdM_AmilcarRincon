# Preguntas

1. ¿Se pueden cambiar los tiempos de encendido de cada led fácilmente en un solo lugar 
del código o estos están _hardcodeados_?

Se pueden cambiar facilmente y en un solo lugar. Se encuentran definidos como macro.

2. ¿Qué bibliotecas estándar se debieron agregar a API_delay.h para que el código compile? Si las funcionalidades de una API propia crecieran, habría que pensar cuál sería el mejor lugar para incluir esas bibliotecas y algunos typedefs que se usan en el ejercicio.

Se debieron agregar _stdint_ y _stdbool_.

3. ¿Es adecuado el control de los parámetros pasados por el usuario que se hace en las funciones implementadas? ¿Se controla que sean valores válidos? ¿Se controla que estén dentro de los rangos correctos?

En las funciones se verifica que el puntero a la _struct_ delay_t no sea un puntero _NULL_. Tambien
se verifica que la duracion no sea 0 ya que carece de sentido. 
