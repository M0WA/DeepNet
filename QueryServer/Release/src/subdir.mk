################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/DictionaryInfoThread.cpp \
../src/Query.cpp \
../src/QueryContentThread.cpp \
../src/QueryKeyword.cpp \
../src/QueryMetaThread.cpp \
../src/QueryProcessManager.cpp \
../src/QueryProcessManagerCleanupThread.cpp \
../src/QueryProcessThread.cpp \
../src/QueryProperties.cpp \
../src/QueryResultCleanupThread.cpp \
../src/QueryResultServer.cpp \
../src/QueryResultServerThread.cpp \
../src/QueryResultXmlRequest.cpp \
../src/QueryResultXmlResponse.cpp \
../src/QuerySecondLevelDomainThread.cpp \
../src/QueryServer.cpp \
../src/QueryServerThread.cpp \
../src/QuerySubdomainThread.cpp \
../src/QueryThread.cpp \
../src/QueryThreadManager.cpp \
../src/QueryThreadParam.cpp \
../src/QueryThreadResultEntry.cpp \
../src/QueryUrlPathThread.cpp \
../src/QueryXmlRequest.cpp \
../src/QueryXmlResponse.cpp \
../src/QueryXmlResponseResultEntry.cpp \
../src/Relevance.cpp \
../src/main.cpp 

OBJS += \
./src/DictionaryInfoThread.o \
./src/Query.o \
./src/QueryContentThread.o \
./src/QueryKeyword.o \
./src/QueryMetaThread.o \
./src/QueryProcessManager.o \
./src/QueryProcessManagerCleanupThread.o \
./src/QueryProcessThread.o \
./src/QueryProperties.o \
./src/QueryResultCleanupThread.o \
./src/QueryResultServer.o \
./src/QueryResultServerThread.o \
./src/QueryResultXmlRequest.o \
./src/QueryResultXmlResponse.o \
./src/QuerySecondLevelDomainThread.o \
./src/QueryServer.o \
./src/QueryServerThread.o \
./src/QuerySubdomainThread.o \
./src/QueryThread.o \
./src/QueryThreadManager.o \
./src/QueryThreadParam.o \
./src/QueryThreadResultEntry.o \
./src/QueryUrlPathThread.o \
./src/QueryXmlRequest.o \
./src/QueryXmlResponse.o \
./src/QueryXmlResponseResultEntry.o \
./src/Relevance.o \
./src/main.o 

CPP_DEPS += \
./src/DictionaryInfoThread.d \
./src/Query.d \
./src/QueryContentThread.d \
./src/QueryKeyword.d \
./src/QueryMetaThread.d \
./src/QueryProcessManager.d \
./src/QueryProcessManagerCleanupThread.d \
./src/QueryProcessThread.d \
./src/QueryProperties.d \
./src/QueryResultCleanupThread.d \
./src/QueryResultServer.d \
./src/QueryResultServerThread.d \
./src/QueryResultXmlRequest.d \
./src/QueryResultXmlResponse.d \
./src/QuerySecondLevelDomainThread.d \
./src/QueryServer.d \
./src/QueryServerThread.d \
./src/QuerySubdomainThread.d \
./src/QueryThread.d \
./src/QueryThreadManager.d \
./src/QueryThreadParam.d \
./src/QueryThreadResultEntry.d \
./src/QueryUrlPathThread.d \
./src/QueryXmlRequest.d \
./src/QueryXmlResponse.d \
./src/QueryXmlResponseResultEntry.d \
./src/Relevance.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -I/usr/include/libxml2 -I../../Networking/src -I../../Tools/src -I../../HtmlParser/src -I../../FastCGIServer/src -I../../Caching/src -I../../Crawler/src -I../../Indexer/src -I../../Database/src -I../../Database/generated -I../../Bot/src -I../../Threading/src -I../../Logging/src -O3 -fPIC -fomit-frame-pointer -g -Wall -c -fmessage-length=0 -pthread -rdynamic -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


