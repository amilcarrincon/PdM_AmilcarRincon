################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c 

OBJS += \
./Src/main.o 

C_DEPS += \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DNUCLEO_F429ZI -c -I../Inc -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/practica_1/ej1/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/practica_1/ej1/Drivers/CMSIS/Include" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/practica_1/ej1/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/practica_1/ej1/Drivers/BSP/STM32F4xx_Nucleo_144" -I"D:/curso_sistemas_embebidos/programacionMicroprocesadores/practica_1/ej1/Drivers/Core/Inc" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/main.d ./Src/main.o

.PHONY: clean-Src

