################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Bot.cpp \
../src/CommandLine.cpp \
../src/ConfigFile.cpp \
../src/ConfigManager.cpp 

OBJS += \
./src/Bot.o \
./src/CommandLine.o \
./src/ConfigFile.o \
./src/ConfigManager.o 

CPP_DEPS += \
./src/Bot.d \
./src/CommandLine.d \
./src/ConfigFile.d \
./src/ConfigManager.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DENABLE_PERFORMANCE_LOG -D_REENTRANT -I/usr/include/libxml2 -I../../Networking/src -I../../Tools/src -I../../Logging/src -I../../HtmlParser/src -I../../Caching/src -I../../Database/src -I../../Database/generated -I../../Threading/src -O0 -g -Wall -c -fmessage-length=0 -pthread -rdynamic -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


