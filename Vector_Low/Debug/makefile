################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include MyCode/Src/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/subdir.mk
-include Middlewares/ST/STM32_USB_Device_Library/Core/Src/subdir.mk
-include Middlewares/ST/STM32_USB_Device_Library/Class/DFU/Src/subdir.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Vector_Low.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Vector_Low.list \

OBJCOPY_BIN += \
Vector_Low.bin \


# All Target
all: Vector_Low.elf secondary-outputs

# Tool invocations
Vector_Low.elf: $(OBJS) $(USER_OBJS) D:\Desktop\WorkSpace\STM32\Vector_Low\Vector_Low\STM32F103C8TX_FLASH.ld
	arm-none-eabi-gcc -o "Vector_Low.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\Desktop\WorkSpace\STM32\Vector_Low\Vector_Low\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Vector_Low.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Vector_Low.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Vector_Low.list"
	@echo 'Finished building: $@'
	@echo ' '

Vector_Low.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Vector_Low.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
