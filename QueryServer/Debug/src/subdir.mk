################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/QueryServer.cpp \
../src/QueryServerThread.cpp \
../src/QueryServerThreadConfig.cpp \
../src/main.cpp 

OBJS += \
./src/QueryServer.o \
./src/QueryServerThread.o \
./src/QueryServerThreadConfig.o \
./src/main.o 

CPP_DEPS += \
./src/QueryServer.d \
./src/QueryServerThread.d \
./src/QueryServerThreadConfig.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -DDEBUG_DEEPNET -DENABLE_PERFORMANCE_LOG -I/usr/include/libxml2 -I../../Networking/src -I../../FastCGIServer/src -I../../Tools/src -I../../Logging/src -I../../Database/generated -I../../Database/src -I../../Bot/src -I../../Threading/src -O0 -g3 -Wall -c -fmessage-length=0 -pthread -rdynamic -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


