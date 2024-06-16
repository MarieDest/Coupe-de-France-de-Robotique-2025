################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/HAL_Driver/Src/stm32f4xx_hal.c \
../Core/Inc/HAL_Driver/Src/stm32f4xx_hal_cortex.c \
../Core/Inc/HAL_Driver/Src/stm32f4xx_hal_dma.c \
../Core/Inc/HAL_Driver/Src/stm32f4xx_hal_dma2d.c \
../Core/Inc/HAL_Driver/Src/stm32f4xx_hal_dma_ex.c \
../Core/Inc/HAL_Driver/Src/stm32f4xx_hal_gpio.c \
../Core/Inc/HAL_Driver/Src/stm32f4xx_hal_i2c.c \
../Core/Inc/HAL_Driver/Src/stm32f4xx_hal_i2c_ex.c \
../Core/Inc/HAL_Driver/Src/stm32f4xx_hal_rcc.c \
../Core/Inc/HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c \
../Core/Inc/HAL_Driver/Src/stm32f4xx_hal_tim.c \
../Core/Inc/HAL_Driver/Src/stm32f4xx_hal_tim_ex.c \
../Core/Inc/HAL_Driver/Src/stm32f4xx_hal_uart.c \
../Core/Inc/HAL_Driver/Src/stm32f4xx_hal_usart.c 

OBJS += \
./Core/Inc/HAL_Driver/Src/stm32f4xx_hal.o \
./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_cortex.o \
./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_dma.o \
./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_dma2d.o \
./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_dma_ex.o \
./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_gpio.o \
./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_i2c.o \
./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_i2c_ex.o \
./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_rcc.o \
./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_rcc_ex.o \
./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_tim.o \
./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_tim_ex.o \
./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_uart.o \
./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_usart.o 

C_DEPS += \
./Core/Inc/HAL_Driver/Src/stm32f4xx_hal.d \
./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_cortex.d \
./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_dma.d \
./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_dma2d.d \
./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_dma_ex.d \
./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_gpio.d \
./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_i2c.d \
./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_i2c_ex.d \
./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_rcc.d \
./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_rcc_ex.d \
./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_tim.d \
./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_tim_ex.d \
./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_uart.d \
./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_usart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/HAL_Driver/Src/%.o Core/Inc/HAL_Driver/Src/%.su Core/Inc/HAL_Driver/Src/%.cyclo: ../Core/Inc/HAL_Driver/Src/%.c Core/Inc/HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Marie/STM32CubeIDE/workspace_1.15.1/Test_VL/Core/Inc/UltraLiteDriver" -I"C:/Users/Marie/STM32CubeIDE/workspace_1.15.1/Test_VL/Core/Inc/HAL_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-HAL_Driver-2f-Src

clean-Core-2f-Inc-2f-HAL_Driver-2f-Src:
	-$(RM) ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal.cyclo ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal.d ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal.o ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal.su ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_cortex.cyclo ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_cortex.d ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_cortex.o ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_cortex.su ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_dma.cyclo ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_dma.d ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_dma.o ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_dma.su ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_dma2d.cyclo ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_dma2d.d ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_dma2d.o ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_dma2d.su ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_dma_ex.cyclo ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_dma_ex.d ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_dma_ex.o ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_dma_ex.su ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_gpio.cyclo ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_gpio.d ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_gpio.o ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_gpio.su ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_i2c.cyclo ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_i2c.d ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_i2c.o ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_i2c.su ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_i2c_ex.cyclo ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_i2c_ex.d ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_i2c_ex.o ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_i2c_ex.su ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_rcc.cyclo ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_rcc.d ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_rcc.o ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_rcc.su ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_rcc_ex.cyclo ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_rcc_ex.d ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_rcc_ex.o ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_rcc_ex.su ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_tim.cyclo ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_tim.d ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_tim.o ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_tim.su ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_tim_ex.cyclo ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_tim_ex.d ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_tim_ex.o ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_tim_ex.su ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_uart.cyclo ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_uart.d ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_uart.o ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_uart.su ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_usart.cyclo ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_usart.d ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_usart.o ./Core/Inc/HAL_Driver/Src/stm32f4xx_hal_usart.su

.PHONY: clean-Core-2f-Inc-2f-HAL_Driver-2f-Src

