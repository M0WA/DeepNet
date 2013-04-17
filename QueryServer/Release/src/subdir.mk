################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BackLinkEntry.cpp \
../src/KeywordEntry.cpp \
../src/PageInfo.cpp \
../src/QueryServer.cpp \
../src/Relevance.cpp \
../src/UrlStageEntry.cpp \
../src/XMLQueryRequest.cpp \
../src/XMLQueryResponse.cpp \
../src/XMLQueryServerThread.cpp \
../src/main.cpp 

OBJS += \
./src/BackLinkEntry.o \
./src/KeywordEntry.o \
./src/PageInfo.o \
./src/QueryServer.o \
./src/Relevance.o \
./src/UrlStageEntry.o \
./src/XMLQueryRequest.o \
./src/XMLQueryResponse.o \
./src/XMLQueryServerThread.o \
./src/main.o 

CPP_DEPS += \
./src/BackLinkEntry.d \
./src/KeywordEntry.d \
./src/PageInfo.d \
./src/QueryServer.d \
./src/Relevance.d \
./src/UrlStageEntry.d \
./src/XMLQueryRequest.d \
./src/XMLQueryResponse.d \
./src/XMLQueryServerThread.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -I/usr/include/libxml2 -I../../Networking/src -I../../HtmlParser/src -I../../FastCGIServer/src -I../../Caching/src -I../../Crawler/src -I../../Indexer/src -I../../Database/src -I../../Database/generated -I../../Bot/src -I../../Threading/src -I../../Logging/src -O3 -g -Wall -c -fmessage-length=0 -pthread -rdynamic -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


