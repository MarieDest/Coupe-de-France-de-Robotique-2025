################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Utilities/STM32F4xx-Nucleo/stm32f4xx_nucleo.c 

OBJS += \
./Core/Utilities/STM32F4xx-Nucleo/stm32f4xx_nucleo.o 

C_DEPS += \
./Core/Utilities/STM32F4xx-Nucleo/stm32f4xx_nucleo.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Utilities/STM32F4xx-Nucleo/%.o Core/Utilities/STM32F4xx-Nucleo/%.su Core/Utilities/STM32F4xx-Nucleo/%.cyclo: ../Core/Utilities/STM32F4xx-Nucleo/%.c Core/Utilities/STM32F4xx-Nucleo/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Marie/STM32CubeIDE/workspace_1.15.1/Test_VL/Core/Inc/UltraLiteDriver" -I"C:/Users/Marie/STM32CubeIDE/workspace_1.15.1/Test_VL/Core/Utilities" -I"C:/Users/Marie/STM32CubeIDE/workspace_1.15.1/Test_VL/Core/Utilities/STM32F4xx-Nucleo" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Utilities-2f-STM32F4xx-2d-Nucleo

clean-Core-2f-Utilities-2f-STM32F4xx-2d-Nucleo:
	-$(RM) ./Core/Utilities/STM32F4xx-Nucleo/stm32f4xx_nucleo.cyclo ./Core/Utilities/STM32F4xx-Nucleo/stm32f4xx_nucleo.d ./Core/Utilities/STM32F4xx-Nucleo/stm32f4xx_nucleo.o ./Core/Utilities/STM32F4xx-Nucleo/stm32f4xx_nucleo.su

.PHONY: clean-Core-2f-Utilities-2f-STM32F4xx-2d-Nucleo

