################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CommerceSearchTools.cpp \
../src/DataMiningTools.cpp \
../src/DatabaseRepair.cpp \
../src/DeepNetToolBot.cpp \
../src/UnitTest.cpp \
../src/UnitTestCacheUrl.cpp \
../src/UnitTestHtmlDocumentFactory.cpp \
../src/UnitTestHtmlTokeniser.cpp \
../src/UnitTestHttpClientCURL.cpp \
../src/UnitTestManager.cpp \
../src/UnitTestPCRERegex.cpp \
../src/UnitTestRobotTxt.cpp \
../src/UnitTestSAX2HtmlParser.cpp \
../src/UnitTestUrl.cpp \
../src/UnitTestUrlParser.cpp \
../src/main.cpp 

OBJS += \
./src/CommerceSearchTools.o \
./src/DataMiningTools.o \
./src/DatabaseRepair.o \
./src/DeepNetToolBot.o \
./src/UnitTest.o \
./src/UnitTestCacheUrl.o \
./src/UnitTestHtmlDocumentFactory.o \
./src/UnitTestHtmlTokeniser.o \
./src/UnitTestHttpClientCURL.o \
./src/UnitTestManager.o \
./src/UnitTestPCRERegex.o \
./src/UnitTestRobotTxt.o \
./src/UnitTestSAX2HtmlParser.o \
./src/UnitTestUrl.o \
./src/UnitTestUrlParser.o \
./src/main.o 

CPP_DEPS += \
./src/CommerceSearchTools.d \
./src/DataMiningTools.d \
./src/DatabaseRepair.d \
./src/DeepNetToolBot.d \
./src/UnitTest.d \
./src/UnitTestCacheUrl.d \
./src/UnitTestHtmlDocumentFactory.d \
./src/UnitTestHtmlTokeniser.d \
./src/UnitTestHttpClientCURL.d \
./src/UnitTestManager.d \
./src/UnitTestPCRERegex.d \
./src/UnitTestRobotTxt.d \
./src/UnitTestSAX2HtmlParser.d \
./src/UnitTestUrl.d \
./src/UnitTestUrlParser.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -DENABLE_PERFORMANCE_LOG -I/usr/include/libxml2 -I../../DOMParser/src -I../../Tools/src -I../../Networking/src -I../../Database/src -I../../Caching/src -I../../Database/generated -I../../Indexer/src -I../../Logging/src -I../../Threading/src -I../../Bot/src -I../../HtmlParser/src -O0 -g -Wall -c -fmessage-length=0 -pthread -rdynamic -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


