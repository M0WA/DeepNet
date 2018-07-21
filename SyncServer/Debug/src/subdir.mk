################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/SyncServer.cpp \
../src/SyncServerRequest.cpp \
../src/SyncServerResponse.cpp \
../src/SyncServerThread.cpp \
../src/main.cpp 

OBJS += \
./src/SyncServer.o \
./src/SyncServerRequest.o \
./src/SyncServerResponse.o \
./src/SyncServerThread.o \
./src/main.o 

CPP_DEPS += \
./src/SyncServer.d \
./src/SyncServerRequest.d \
./src/SyncServerResponse.d \
./src/SyncServerThread.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DENABLE_PERFORMANCE_LOG -DDEBUG_DEEPNET -D_REENTRANT -I/usr/include/libxml2 -I../../Networking/src/ -I../../Bot/src/ -I../../Database/src/ -I../../Database/generated/ -I../../Database/src/ -I../../FastCGIServer/src/ -I../../Tools/src/ -I../../Logging/src/ -I../../Threading/src/ -I../../Syncing/src/ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


