################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO.c \
../KEYPAD.c \
../KEYPAD_cfg.c \
../LCD.c \
../LCD_cfg.c \
../main.c 

OBJS += \
./DIO.o \
./KEYPAD.o \
./KEYPAD_cfg.o \
./LCD.o \
./LCD_cfg.o \
./main.o 

C_DEPS += \
./DIO.d \
./KEYPAD.d \
./KEYPAD_cfg.d \
./LCD.d \
./LCD_cfg.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


