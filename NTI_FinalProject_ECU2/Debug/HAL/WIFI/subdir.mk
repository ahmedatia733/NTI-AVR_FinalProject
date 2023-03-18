################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/WIFI/WIFI_prog.c 

OBJS += \
./HAL/WIFI/WIFI_prog.o 

C_DEPS += \
./HAL/WIFI/WIFI_prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/WIFI/%.o: ../HAL/WIFI/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"F:\embedded\NTIProjects\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\APP" -I"F:\embedded\NTIProjects\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\CONFIG\APPCfg" -I"F:\embedded\NTIProjects\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\APP\SmartHome" -I"F:\embedded\NTIProjects\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\APP\millis" -I"F:\embedded\NTIProjects\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\HAL\WIFI" -I"F:\embedded\NTIProjects\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\MCAL\UART" -I"F:\embedded\NTIProjects\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\CONFIG" -I"F:\embedded\NTIProjects\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\HAL" -I"F:\embedded\NTIProjects\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\HAL\DC_MOTOR" -I"F:\embedded\NTIProjects\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\HAL\LDR" -I"F:\embedded\NTIProjects\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\HAL\LM35" -I"F:\embedded\NTIProjects\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\LIB" -I"F:\embedded\NTIProjects\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\MCAL" -I"F:\embedded\NTIProjects\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\MCAL\ADC" -I"F:\embedded\NTIProjects\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\MCAL\DIO" -I"F:\embedded\NTIProjects\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\MCAL\EX_INT" -I"F:\embedded\NTIProjects\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\MCAL\GIE" -I"F:\embedded\NTIProjects\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\MCAL\PORT" -I"F:\embedded\NTIProjects\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\Services" -I"C:\WinAVR-20100110\avr\include" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


