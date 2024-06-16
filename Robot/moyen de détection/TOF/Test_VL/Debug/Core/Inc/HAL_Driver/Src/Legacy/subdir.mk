################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/HAL_Driver/Src/Legacy/stm32f4xx_hal_can.c 

OBJS += \
./Core/Inc/HAL_Driver/Src/Legacy/stm32f4xx_hal_can.o 

C_DEPS += \
./Core/Inc/HAL_Driver/Src/Legacy/stm32f4xx_hal_can.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/HAL_Driver/Src/Legacy/%.o Core/Inc/HAL_Driver/Src/Legacy/%.su Core/Inc/HAL_Driver/Src/Legacy/%.cyclo: ../Core/Inc/HAL_Driver/Src/Legacy/%.c Core/Inc/HAL_Driver/Src/Legacy/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Marie/STM32CubeIDE/workspace_1.15.1/Test_VL/Core/Inc/UltraLiteDriver" -I"C:/Users/Marie/STM32CubeIDE/workspace_1.15.1/Test_VL/Core/Inc/HAL_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-HAL_Driver-2f-Src-2f-Legacy

clean-Core-2f-Inc-2f-HAL_Driver-2f-Src-2f-Legacy:
	-$(RM) ./Core/Inc/HAL_Driver/Src/Legacy/stm32f4xx_hal_can.cyclo ./Core/Inc/HAL_Driver/Src/Legacy/stm32f4xx_hal_can.d ./Core/Inc/HAL_Driver/Src/Legacy/stm32f4xx_hal_can.o ./Core/Inc/HAL_Driver/Src/Legacy/stm32f4xx_hal_can.su

.PHONY: clean-Core-2f-Inc-2f-HAL_Driver-2f-Src-2f-Legacy

