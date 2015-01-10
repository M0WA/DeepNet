################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/QueryServer.cpp \
../src/main.cpp 

OBJS += \
./src/QueryServer.o \
./src/main.o 

CPP_DEPS += \
./src/QueryServer.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../FastCGIServer/src -I../../Tools/src -I../../Logging/src -I../../Database/generated -I../../Database/src -I../../Bot/src -I../../Threading/src -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


