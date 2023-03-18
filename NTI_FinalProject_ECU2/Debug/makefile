################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/UART/subdir.mk
-include MCAL/PORT/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EX_INT/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/WIFI/subdir.mk
-include HAL/LM35/subdir.mk
-include HAL/LDR/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/DC_MOTOR/subdir.mk
-include CONFIG/APPCfg/subdir.mk
-include CONFIG/subdir.mk
-include APP/millis/subdir.mk
-include APP/SmartHome/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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
LSS += \
NTI_FinalProject_ECU2.lss \

FLASH_IMAGE += \
NTI_FinalProject_ECU2.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: NTI_FinalProject_ECU2.elf secondary-outputs

# Tool invocations
NTI_FinalProject_ECU2.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,NTI_FinalProject_ECU2.map -mmcu=atmega32 -o "NTI_FinalProject_ECU2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

NTI_FinalProject_ECU2.lss: NTI_FinalProject_ECU2.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S NTI_FinalProject_ECU2.elf  >"NTI_FinalProject_ECU2.lss"
	@echo 'Finished building: $@'
	@echo ' '

NTI_FinalProject_ECU2.hex: NTI_FinalProject_ECU2.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex NTI_FinalProject_ECU2.elf  "NTI_FinalProject_ECU2.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: NTI_FinalProject_ECU2.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 NTI_FinalProject_ECU2.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) NTI_FinalProject_ECU2.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
