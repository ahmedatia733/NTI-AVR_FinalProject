################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CONFIG/ADC_Lconfig.c \
../CONFIG/DC_MOTOR_Lconfig.c \
../CONFIG/Dio_Lcfg.c \
../CONFIG/EX_INT_Lconfig.c \
../CONFIG/LCD_Lcfg.c \
../CONFIG/LDR_Lconfig.c \
../CONFIG/LM35_Lconfig.c \
../CONFIG/Led_Lcfg.c \
../CONFIG/Port_Lcfg.c \
../CONFIG/TIM_Lconfig.c \
../CONFIG/UART_Lcfg.c \
../CONFIG/WIFI_Lcfg.c 

OBJS += \
./CONFIG/ADC_Lconfig.o \
./CONFIG/DC_MOTOR_Lconfig.o \
./CONFIG/Dio_Lcfg.o \
./CONFIG/EX_INT_Lconfig.o \
./CONFIG/LCD_Lcfg.o \
./CONFIG/LDR_Lconfig.o \
./CONFIG/LM35_Lconfig.o \
./CONFIG/Led_Lcfg.o \
./CONFIG/Port_Lcfg.o \
./CONFIG/TIM_Lconfig.o \
./CONFIG/UART_Lcfg.o \
./CONFIG/WIFI_Lcfg.o 

C_DEPS += \
./CONFIG/ADC_Lconfig.d \
./CONFIG/DC_MOTOR_Lconfig.d \
./CONFIG/Dio_Lcfg.d \
./CONFIG/EX_INT_Lconfig.d \
./CONFIG/LCD_Lcfg.d \
./CONFIG/LDR_Lconfig.d \
./CONFIG/LM35_Lconfig.d \
./CONFIG/Led_Lcfg.d \
./CONFIG/Port_Lcfg.d \
./CONFIG/TIM_Lconfig.d \
./CONFIG/UART_Lcfg.d \
./CONFIG/WIFI_Lcfg.d 


# Each subdirectory must supply rules for building sources it contributes
CONFIG/%.o: ../CONFIG/%.c CONFIG/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\APP" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\HAL\LED" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\CONFIG\APPCfg" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\APP\SmartHome" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\APP\millis" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\HAL\WIFI" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\MCAL\UART" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\CONFIG" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\HAL" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\HAL\DC_MOTOR" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\HAL\LDR" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\HAL\LM35" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\LIB" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\MCAL" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\MCAL\ADC" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\MCAL\DIO" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\MCAL\EX_INT" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\MCAL\GIE" -I"C:\Users\alish\Desktop\NTI R2\Embedded\NTI - PROJECTS\Final1-Project\Project\NTI_FinalProject_ECU_GitVersions\v4\NTI-AVR_FinalProject\NTI_FinalProject_ECU2\MCAL\PORT" -I"C:\WinAVR-20100110\avr\include" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


