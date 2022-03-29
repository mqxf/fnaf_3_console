################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/fnaf\ 3\ console.c 

C_DEPS += \
./src/fnaf\ 3\ console.d 

OBJS += \
./src/fnaf\ 3\ console.o 


# Each subdirectory must supply rules for building sources it contributes
src/fnaf\ 3\ console.o: ../src/fnaf\ 3\ console.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/fnaf 3 console.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/fnaf\ 3\ console.d ./src/fnaf\ 3\ console.o

.PHONY: clean-src

