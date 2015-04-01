################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/SuggestServer.cpp \
../src/SuggestServerRequest.cpp \
../src/SuggestServerResponse.cpp \
../src/SuggestServerThread.cpp \
../src/main.cpp 

OBJS += \
./src/SuggestServer.o \
./src/SuggestServerRequest.o \
./src/SuggestServerResponse.o \
./src/SuggestServerThread.o \
./src/main.o 

CPP_DEPS += \
./src/SuggestServer.d \
./src/SuggestServerRequest.d \
./src/SuggestServerResponse.d \
./src/SuggestServerThread.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -I/usr/include/libxml2 -I../../Tools/src -I../../Networking/src -I../../FastCGIServer/src -I../../Bot/src -I../../Logging/src -I../../Threading/src -I../../Database/src -I../../Database/generated -O3 -fPIC -fomit-frame-pointer -g -Wall -c -fmessage-length=0 -rdynamic -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


