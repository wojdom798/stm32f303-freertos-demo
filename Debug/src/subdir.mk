################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c 

S_UPPER_SRCS += \
../src/startup_stm32f303retx.S 

OBJS += \
./src/main.o \
./src/startup_stm32f303retx.o 

S_UPPER_DEPS += \
./src/startup_stm32f303retx.d 

C_DEPS += \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:\Users\Dominik\Documents\eclipse-workspace\stm32f303re-freertos-demo-1\headers" -I"C:\Users\Dominik\Documents\eclipse-workspace\stm32f303re-freertos-demo-1" -I"C:\Users\Dominik\Documents\eclipse-workspace\stm32f303re-freertos-demo-1\freertos\Source\include" -I"C:\Users\Dominik\Documents\eclipse-workspace\stm32f303re-freertos-demo-1\freertos\Source\portable\GCC\ARM_CM4F" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.S src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -x assembler-with-cpp -I"C:\Users\Dominik\Documents\eclipse-workspace\stm32f303re-freertos-demo-1\headers" -I"C:\Users\Dominik\Documents\eclipse-workspace\stm32f303re-freertos-demo-1" -I"C:\Users\Dominik\Documents\eclipse-workspace\stm32f303re-freertos-demo-1\freertos\Source\include" -I"C:\Users\Dominik\Documents\eclipse-workspace\stm32f303re-freertos-demo-1\freertos\Source\portable\GCC\ARM_CM4F" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


