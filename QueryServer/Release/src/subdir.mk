################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/QueryServer.cpp \
../src/QueryServerThread.cpp \
../src/QueryXmlRequest.cpp \
../src/QueryXmlResponse.cpp \
../src/main.cpp 

OBJS += \
./src/QueryServer.o \
./src/QueryServerThread.o \
./src/QueryXmlRequest.o \
./src/QueryXmlResponse.o \
./src/main.o 

CPP_DEPS += \
./src/QueryServer.d \
./src/QueryServerThread.d \
./src/QueryXmlRequest.d \
./src/QueryXmlResponse.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -DDEBUG_DEEPNET -DENABLE_PERFORMANCE_LOG -I/usr/include/libxml2 -I../../Networking/src -I../../Tools/src -I../../QueryLib/src -I../../HtmlParser/src -I../../FastCGIServer/src -I../../Caching/src -I../../Crawler/src -I../../Indexer/src -I../../Database/src -I../../Database/generated -I../../Bot/src -I../../Threading/src -I../../Logging/src -O0 -g3 -Wall -c -fmessage-length=0 -pthread -rdynamic -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


