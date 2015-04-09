################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/DictionaryInfoThread.cpp \
../src/QueryContentThread.cpp \
../src/QueryMetaThread.cpp \
../src/QueryProcessManager.cpp \
../src/QueryProcessManagerCleanupThread.cpp \
../src/QueryProcessThread.cpp \
../src/QueryResultCleanupThread.cpp \
../src/QueryResultServer.cpp \
../src/QueryResultServerThread.cpp \
../src/QueryResultXmlRequest.cpp \
../src/QueryResultXmlResponse.cpp \
../src/QuerySecondLevelDomainThread.cpp \
../src/QuerySubdomainThread.cpp \
../src/QueryThread.cpp \
../src/QueryThreadManager.cpp \
../src/QueryThreadParam.cpp \
../src/QueryThreadResultEntry.cpp \
../src/QueryUrlPathThread.cpp \
../src/QueryXmlResponseResultEntry.cpp \
../src/Relevance.cpp \
../src/main.cpp 

OBJS += \
./src/DictionaryInfoThread.o \
./src/QueryContentThread.o \
./src/QueryMetaThread.o \
./src/QueryProcessManager.o \
./src/QueryProcessManagerCleanupThread.o \
./src/QueryProcessThread.o \
./src/QueryResultCleanupThread.o \
./src/QueryResultServer.o \
./src/QueryResultServerThread.o \
./src/QueryResultXmlRequest.o \
./src/QueryResultXmlResponse.o \
./src/QuerySecondLevelDomainThread.o \
./src/QuerySubdomainThread.o \
./src/QueryThread.o \
./src/QueryThreadManager.o \
./src/QueryThreadParam.o \
./src/QueryThreadResultEntry.o \
./src/QueryUrlPathThread.o \
./src/QueryXmlResponseResultEntry.o \
./src/Relevance.o \
./src/main.o 

CPP_DEPS += \
./src/DictionaryInfoThread.d \
./src/QueryContentThread.d \
./src/QueryMetaThread.d \
./src/QueryProcessManager.d \
./src/QueryProcessManagerCleanupThread.d \
./src/QueryProcessThread.d \
./src/QueryResultCleanupThread.d \
./src/QueryResultServer.d \
./src/QueryResultServerThread.d \
./src/QueryResultXmlRequest.d \
./src/QueryResultXmlResponse.d \
./src/QuerySecondLevelDomainThread.d \
./src/QuerySubdomainThread.d \
./src/QueryThread.d \
./src/QueryThreadManager.d \
./src/QueryThreadParam.d \
./src/QueryThreadResultEntry.d \
./src/QueryUrlPathThread.d \
./src/QueryXmlResponseResultEntry.d \
./src/Relevance.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/include/libxml2 -I../../Threading/src -I../../Bot/src -I../../FastCGIServer/src -I../../Networking/src -I../../HtmlParser/src -I../../Caching/src -I../../Indexer/src -I../../Logging/src -I../../Tools/src -I../../Database/src -I../../Database/generated -I../../QueryLib/src -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


