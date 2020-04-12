################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO.c \
../PushButton.c \
../UART.c \
../UART_cfg.c \
../UserTasks.c \
../croutine.c \
../event_groups.c \
../heap_1.c \
../keypad.c \
../lcd.c \
../list.c \
../main.c \
../port.c \
../queue.c \
../stream_buffer.c \
../tasks.c \
../timers.c 

OBJS += \
./DIO.o \
./PushButton.o \
./UART.o \
./UART_cfg.o \
./UserTasks.o \
./croutine.o \
./event_groups.o \
./heap_1.o \
./keypad.o \
./lcd.o \
./list.o \
./main.o \
./port.o \
./queue.o \
./stream_buffer.o \
./tasks.o \
./timers.o 

C_DEPS += \
./DIO.d \
./PushButton.d \
./UART.d \
./UART_cfg.d \
./UserTasks.d \
./croutine.d \
./event_groups.d \
./heap_1.d \
./keypad.d \
./lcd.d \
./list.d \
./main.d \
./port.d \
./queue.d \
./stream_buffer.d \
./tasks.d \
./timers.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


