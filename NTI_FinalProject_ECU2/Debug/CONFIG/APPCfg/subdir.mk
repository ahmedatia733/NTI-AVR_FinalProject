################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CONFIG/APPCfg/SmartHome_Lcfg.c 

OBJS += \
./CONFIG/APPCfg/SmartHome_Lcfg.o 

C_DEPS += \
./CONFIG/APPCfg/SmartHome_Lcfg.d 


# Each subdirectory must supply rules for building sources it contributes
CONFIG/APPCfg/%.o: ../CONFIG/APPCfg/%.c CONFIG/APPCfg/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\APP" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\HAL\LED" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\CONFIG\APPCfg" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\APP\SmartHome" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\APP\millis" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\HAL\WIFI" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\MCAL\UART" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\CONFIG" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\HAL" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\HAL\DC_MOTOR" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\HAL\LDR" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\HAL\LM35" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\LIB" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\MCAL" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\MCAL\ADC" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\MCAL\DIO" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\MCAL\EX_INT" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\MCAL\GIE" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\MCAL\PORT" -I"C:\WinAVR-20100110\avr\include" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


