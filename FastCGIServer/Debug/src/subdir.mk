################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/FastCGIRequest.cpp \
../src/FastCGIResponse.cpp \
../src/FastCGIServer.cpp \
../src/FastCGIServerException.cpp \
../src/FastCGIServerInitException.cpp \
../src/FastCGIServerSocketException.cpp \
../src/FastCGIServerThread.cpp \
../src/FastCGISocket.cpp \
../src/HttpHeader.cpp 

OBJS += \
./src/FastCGIRequest.o \
./src/FastCGIResponse.o \
./src/FastCGIServer.o \
./src/FastCGIServerException.o \
./src/FastCGIServerInitException.o \
./src/FastCGIServerSocketException.o \
./src/FastCGIServerThread.o \
./src/FastCGISocket.o \
./src/HttpHeader.o 

CPP_DEPS += \
./src/FastCGIRequest.d \
./src/FastCGIResponse.d \
./src/FastCGIServer.d \
./src/FastCGIServerException.d \
./src/FastCGIServerInitException.d \
./src/FastCGIServerSocketException.d \
./src/FastCGIServerThread.d \
./src/FastCGISocket.d \
./src/HttpHeader.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -DDEBUG_DEEPNET -DENABLE_PERFORMANCE_LOG -I../../Logging/src -I../../Caching/src -I../../Tools/src -I../../Networking/src -I/usr/include/libxml2 -I../../HtmlParser/src -I../../Bot/src -I../../Database/src -I../../Database/generated -I../../Threading/src -O0 -g3 -Wall -c -fmessage-length=0  -rdynamic -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


