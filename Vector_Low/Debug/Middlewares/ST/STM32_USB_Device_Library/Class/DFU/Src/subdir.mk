################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/ST/STM32_USB_Device_Library/Class/DFU/Src/usbd_dfu.c 

OBJS += \
./Middlewares/ST/STM32_USB_Device_Library/Class/DFU/Src/usbd_dfu.o 

C_DEPS += \
./Middlewares/ST/STM32_USB_Device_Library/Class/DFU/Src/usbd_dfu.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/STM32_USB_Device_Library/Class/DFU/Src/usbd_dfu.o: ../Middlewares/ST/STM32_USB_Device_Library/Class/DFU/Src/usbd_dfu.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../MyCode/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/DFU/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/ST/STM32_USB_Device_Library/Class/DFU/Src/usbd_dfu.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

