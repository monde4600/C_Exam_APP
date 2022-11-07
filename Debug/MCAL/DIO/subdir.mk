################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/DIO/DIO_Prog.c 

OBJS += \
./MCAL/DIO/DIO_Prog.o 

C_DEPS += \
./MCAL/DIO/DIO_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/DIO/%.o: ../MCAL/DIO/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\embided_deblom\AMIT\interfacing\C_ExamTask\HAL" -I"E:\embided_deblom\AMIT\interfacing\C_ExamTask\LIB" -I"E:\embided_deblom\AMIT\interfacing\C_ExamTask\APP" -I"E:\embided_deblom\AMIT\interfacing\C_ExamTask\HAL" -I"E:\embided_deblom\AMIT\interfacing\C_ExamTask\MCAL" -I"E:\embided_deblom\AMIT\interfacing\C_ExamTask\LIB" -I"E:\embided_deblom\AMIT\interfacing\C_ExamTask\APP\Projects" -I"E:\embided_deblom\AMIT\interfacing\C_ExamTask\HAL\Buzzer" -I"E:\embided_deblom\AMIT\interfacing\C_ExamTask\HAL\Keypad" -I"E:\embided_deblom\AMIT\interfacing\C_ExamTask\HAL\LCD" -I"E:\embided_deblom\AMIT\interfacing\C_ExamTask\HAL\LDR" -I"E:\embided_deblom\AMIT\interfacing\C_ExamTask\HAL\LED" -I"E:\embided_deblom\AMIT\interfacing\C_ExamTask\HAL\PushButton" -I"E:\embided_deblom\AMIT\interfacing\C_ExamTask\HAL\Relay" -I"E:\embided_deblom\AMIT\interfacing\C_ExamTask\HAL\SSD" -I"E:\embided_deblom\AMIT\interfacing\C_ExamTask\MCAL\ADC" -I"E:\embided_deblom\AMIT\interfacing\C_ExamTask\MCAL\DIO" -I"E:\embided_deblom\AMIT\interfacing\C_ExamTask\MCAL\EXINT" -I"E:\embided_deblom\AMIT\interfacing\C_ExamTask\MCAL\GIE" -I"E:\embided_deblom\AMIT\interfacing\C_ExamTask\MCAL\I2C" -I"E:\embided_deblom\AMIT\interfacing\C_ExamTask\MCAL\Timer" -I"E:\embided_deblom\AMIT\interfacing\C_ExamTask\MCAL\UART" -I"E:\embided_deblom\AMIT\interfacing\C_ExamTask\MCAL\WDT" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


