################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Query.cpp \
../src/QueryKeyword.cpp \
../src/QueryProperties.cpp 

OBJS += \
./src/Query.o \
./src/QueryKeyword.o \
./src/QueryProperties.o 

CPP_DEPS += \
./src/Query.d \
./src/QueryKeyword.d \
./src/QueryProperties.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D_REENTRANT -I../../Tools/src -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


