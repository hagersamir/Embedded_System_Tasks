################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Nvic/Nvic.c 

C_DEPS += \
./Nvic/Nvic.d 

OBJS += \
./Nvic/Nvic.o 


# Each subdirectory must supply rules for building sources it contributes
Nvic/%.o: ../Nvic/%.c Nvic/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra -g -DNDEBUG -DSTM32F401xE -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -I"C:\Study\Embedded System\Lab8_Project\Lib" -I"C:\Study\Embedded System\Lab8_Project\Rcc" -I"C:\Study\Embedded System\Lab8_Project\Gpio" -I"C:\Study\Embedded System\Lab8_Project\Nvic" -I"C:\Study\Embedded System\Lab8_Project\EXTI" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


