################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ConsoleLogging.cpp \
../src/FileLogging.cpp \
../src/Logging.cpp 

OBJS += \
./src/ConsoleLogging.o \
./src/FileLogging.o \
./src/Logging.o 

CPP_DEPS += \
./src/ConsoleLogging.d \
./src/FileLogging.d \
./src/Logging.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -I/usr/include/libxml2 -I../../Threading/src -I../../Bot/src -I../../Database/src -I../../Database/generated -O3 -g -Wall -c -fmessage-length=0 -pthread -rdynamic -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


