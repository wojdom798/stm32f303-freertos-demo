################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../freertos/Source/portable/Common/mpu_wrappers.c 

OBJS += \
./freertos/Source/portable/Common/mpu_wrappers.o 

C_DEPS += \
./freertos/Source/portable/Common/mpu_wrappers.d 


# Each subdirectory must supply rules for building sources it contributes
freertos/Source/portable/Common/%.o: ../freertos/Source/portable/Common/%.c freertos/Source/portable/Common/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:\Users\Dominik\Documents\eclipse-workspace\stm32f303re-freertos-demo-1\headers" -I"C:\Users\Dominik\Documents\eclipse-workspace\stm32f303re-freertos-demo-1" -I"C:\Users\Dominik\Documents\eclipse-workspace\stm32f303re-freertos-demo-1\freertos\Source\include" -I"C:\Users\Dominik\Documents\eclipse-workspace\stm32f303re-freertos-demo-1\freertos\Source\portable\GCC\ARM_CM4F" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


