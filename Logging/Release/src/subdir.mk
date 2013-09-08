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
	g++ -D_REENTRANT -I../../Threading/src -O3 -fPIC -fomit-frame-pointer -g -Wall -c -fmessage-length=0 -pthread -rdynamic -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


