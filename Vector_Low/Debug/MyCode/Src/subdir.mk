################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MyCode/Src/board.c 

OBJS += \
./MyCode/Src/board.o 

C_DEPS += \
./MyCode/Src/board.d 


# Each subdirectory must supply rules for building sources it contributes
MyCode/Src/board.o: ../MyCode/Src/board.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -I"D:/Desktop/WorkSpace/WorkSpace/STM32IDE/Vector_Low/MyCode/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MyCode/Src/board.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

