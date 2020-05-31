################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/DGPIO.c \
../src/DMA.c \
../src/DMA_Cfg.c \
../src/DNVIC.c \
../src/DRCC.c \
../src/DSYSTICK.c \
../src/HLCD.c \
../src/HLCD_config.c \
../src/HLED.c \
../src/HSwitch.c \
../src/HSwitch_config.c \
../src/HUART.c \
../src/Sched.c \
../src/Sched_config.c \
../src/UART.c \
../src/app.c \
../src/main.c 

OBJS += \
./src/DGPIO.o \
./src/DMA.o \
./src/DMA_Cfg.o \
./src/DNVIC.o \
./src/DRCC.o \
./src/DSYSTICK.o \
./src/HLCD.o \
./src/HLCD_config.o \
./src/HLED.o \
./src/HSwitch.o \
./src/HSwitch_config.o \
./src/HUART.o \
./src/Sched.o \
./src/Sched_config.o \
./src/UART.o \
./src/app.o \
./src/main.o 

C_DEPS += \
./src/DGPIO.d \
./src/DMA.d \
./src/DMA_Cfg.d \
./src/DNVIC.d \
./src/DRCC.d \
./src/DSYSTICK.d \
./src/HLCD.d \
./src/HLCD_config.d \
./src/HLED.d \
./src/HSwitch.d \
./src/HSwitch_config.d \
./src/HUART.d \
./src/Sched.d \
./src/Sched_config.d \
./src/UART.d \
./src/app.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wpadded -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu11 -Wmissing-prototypes -Wstrict-prototypes -Wbad-function-cast -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


