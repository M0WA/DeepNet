################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/HtmlData.cpp \
../src/HttpClientCURL.cpp \
../src/HttpClientFactory.cpp \
../src/HttpClientSettings.cpp \
../src/HttpCookie.cpp \
../src/HttpResponse.cpp \
../src/HttpUrl.cpp \
../src/HttpUrlParser.cpp \
../src/HttpUrlParserDecodeException.cpp \
../src/HttpUrlParserEncodeException.cpp \
../src/HttpUrlParserException.cpp \
../src/HttpUrlParserInvalidSchemeException.cpp \
../src/HttpUrlParserInvalidUrlException.cpp \
../src/HttpUrlParserTLDCacheException.cpp \
../src/IPv4Tools.cpp 

OBJS += \
./src/HtmlData.o \
./src/HttpClientCURL.o \
./src/HttpClientFactory.o \
./src/HttpClientSettings.o \
./src/HttpCookie.o \
./src/HttpResponse.o \
./src/HttpUrl.o \
./src/HttpUrlParser.o \
./src/HttpUrlParserDecodeException.o \
./src/HttpUrlParserEncodeException.o \
./src/HttpUrlParserException.o \
./src/HttpUrlParserInvalidSchemeException.o \
./src/HttpUrlParserInvalidUrlException.o \
./src/HttpUrlParserTLDCacheException.o \
./src/IPv4Tools.o 

CPP_DEPS += \
./src/HtmlData.d \
./src/HttpClientCURL.d \
./src/HttpClientFactory.d \
./src/HttpClientSettings.d \
./src/HttpCookie.d \
./src/HttpResponse.d \
./src/HttpUrl.d \
./src/HttpUrlParser.d \
./src/HttpUrlParserDecodeException.d \
./src/HttpUrlParserEncodeException.d \
./src/HttpUrlParserException.d \
./src/HttpUrlParserInvalidSchemeException.d \
./src/HttpUrlParserInvalidUrlException.d \
./src/HttpUrlParserTLDCacheException.d \
./src/IPv4Tools.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -I/usr/include/libxml2 -I../../Tools/src -I../../Logging/src -I../../Threading/src -O0 -g -Wall -c -fmessage-length=0 -pthread -rdynamic -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


