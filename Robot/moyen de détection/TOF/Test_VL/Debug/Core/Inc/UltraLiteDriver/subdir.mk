################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/UltraLiteDriver/VL53L1X_api.c \
../Core/Inc/UltraLiteDriver/VL53L1X_calibration.c \
../Core/Inc/UltraLiteDriver/platform.c 

OBJS += \
./Core/Inc/UltraLiteDriver/VL53L1X_api.o \
./Core/Inc/UltraLiteDriver/VL53L1X_calibration.o \
./Core/Inc/UltraLiteDriver/platform.o 

C_DEPS += \
./Core/Inc/UltraLiteDriver/VL53L1X_api.d \
./Core/Inc/UltraLiteDriver/VL53L1X_calibration.d \
./Core/Inc/UltraLiteDriver/platform.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/UltraLiteDriver/%.o Core/Inc/UltraLiteDriver/%.su Core/Inc/UltraLiteDriver/%.cyclo: ../Core/Inc/UltraLiteDriver/%.c Core/Inc/UltraLiteDriver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Marie/STM32CubeIDE/workspace_1.15.1/Test_VL/Core/Inc/UltraLiteDriver" -I"C:/Users/Marie/STM32CubeIDE/workspace_1.15.1/Test_VL/Core/Utilities" -I"C:/Users/Marie/STM32CubeIDE/workspace_1.15.1/Test_VL/Core/Utilities/STM32F4xx-Nucleo" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-UltraLiteDriver

clean-Core-2f-Inc-2f-UltraLiteDriver:
	-$(RM) ./Core/Inc/UltraLiteDriver/VL53L1X_api.cyclo ./Core/Inc/UltraLiteDriver/VL53L1X_api.d ./Core/Inc/UltraLiteDriver/VL53L1X_api.o ./Core/Inc/UltraLiteDriver/VL53L1X_api.su ./Core/Inc/UltraLiteDriver/VL53L1X_calibration.cyclo ./Core/Inc/UltraLiteDriver/VL53L1X_calibration.d ./Core/Inc/UltraLiteDriver/VL53L1X_calibration.o ./Core/Inc/UltraLiteDriver/VL53L1X_calibration.su ./Core/Inc/UltraLiteDriver/platform.cyclo ./Core/Inc/UltraLiteDriver/platform.d ./Core/Inc/UltraLiteDriver/platform.o ./Core/Inc/UltraLiteDriver/platform.su

.PHONY: clean-Core-2f-Inc-2f-UltraLiteDriver

