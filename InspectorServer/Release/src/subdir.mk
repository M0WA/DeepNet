################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/InspectorServer.cpp \
../src/InspectorServerRequest.cpp \
../src/InspectorServerResponse.cpp \
../src/InspectorServerThread.cpp \
../src/main.cpp 

OBJS += \
./src/InspectorServer.o \
./src/InspectorServerRequest.o \
./src/InspectorServerResponse.o \
./src/InspectorServerThread.o \
./src/main.o 

CPP_DEPS += \
./src/InspectorServer.d \
./src/InspectorServerRequest.d \
./src/InspectorServerResponse.d \
./src/InspectorServerThread.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -I/usr/include/libxml2 -I../../Tools/src -I../../Networking/src -I../../Bot/src -I../../Caching/src -I../../Crawler/src -I../../Database/src -I../../Database/generated -I../../FastCGIServer/src -I../../HtmlParser/src -I../../Indexer/src -I../../Logging/src -I../../Threading/src -O3 -g -Wall -c -fmessage-length=0 -rdynamic -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


