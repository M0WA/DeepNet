################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CommerceSearchTools.cpp \
../src/DataMiningTools.cpp \
../src/DatabaseRepair.cpp \
../src/DeepNetToolBot.cpp \
../src/UnitTestCacheUrl.cpp \
../src/UnitTestHtmlParser.cpp \
../src/UnitTestHttpClient.cpp \
../src/UnitTestIPv4TCPClient.cpp \
../src/UnitTestIPv4TCPServer.cpp \
../src/UnitTestPCRERegex.cpp \
../src/UnitTestRobotTxt.cpp \
../src/UnitTestUrl.cpp \
../src/UnitTestUrlParser.cpp \
../src/main.cpp 

OBJS += \
./src/CommerceSearchTools.o \
./src/DataMiningTools.o \
./src/DatabaseRepair.o \
./src/DeepNetToolBot.o \
./src/UnitTestCacheUrl.o \
./src/UnitTestHtmlParser.o \
./src/UnitTestHttpClient.o \
./src/UnitTestIPv4TCPClient.o \
./src/UnitTestIPv4TCPServer.o \
./src/UnitTestPCRERegex.o \
./src/UnitTestRobotTxt.o \
./src/UnitTestUrl.o \
./src/UnitTestUrlParser.o \
./src/main.o 

CPP_DEPS += \
./src/CommerceSearchTools.d \
./src/DataMiningTools.d \
./src/DatabaseRepair.d \
./src/DeepNetToolBot.d \
./src/UnitTestCacheUrl.d \
./src/UnitTestHtmlParser.d \
./src/UnitTestHttpClient.d \
./src/UnitTestIPv4TCPClient.d \
./src/UnitTestIPv4TCPServer.d \
./src/UnitTestPCRERegex.d \
./src/UnitTestRobotTxt.d \
./src/UnitTestUrl.d \
./src/UnitTestUrlParser.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -DENABLE_PERFORMANCE_LOG -I/usr/include/libxml2 -I../../Networking/src -I../../Database/src -I../../Caching/src -I../../Database/generated -I../../Indexer/src -I../../Logging/src -I../../Threading/src -I../../Bot/src -I../../HtmlParser/src -O0 -g -Wall -c -fmessage-length=0 -pthread -rdynamic -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


