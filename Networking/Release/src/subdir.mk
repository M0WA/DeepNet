################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/HtmlData.cpp \
../src/HttpClientEx.cpp \
../src/HttpClientSettings.cpp \
../src/HttpConnection.cpp \
../src/HttpCookie.cpp \
../src/HttpGetRequest.cpp \
../src/HttpHeader.cpp \
../src/HttpPostRequest.cpp \
../src/HttpRequest.cpp \
../src/HttpRequestResult.cpp \
../src/HttpUrl.cpp \
../src/HttpUrlParser.cpp \
../src/HttpUrlParserDecodeException.cpp \
../src/HttpUrlParserEncodeException.cpp \
../src/HttpUrlParserException.cpp \
../src/HttpUrlParserInvalidSchemeException.cpp \
../src/HttpUrlParserInvalidUrlException.cpp \
../src/HttpUrlParserTLDCacheException.cpp \
../src/IPv4Tools.cpp \
../src/Socket.cpp \
../src/SocketIPv4.cpp \
../src/SocketIPv4TCP.cpp \
../src/SocketIPv4TCPClient.cpp \
../src/SocketIPv4TCPSSLClient.cpp \
../src/SocketIPv4TCPServer.cpp \
../src/SocketOptions.cpp 

OBJS += \
./src/HtmlData.o \
./src/HttpClientEx.o \
./src/HttpClientSettings.o \
./src/HttpConnection.o \
./src/HttpCookie.o \
./src/HttpGetRequest.o \
./src/HttpHeader.o \
./src/HttpPostRequest.o \
./src/HttpRequest.o \
./src/HttpRequestResult.o \
./src/HttpUrl.o \
./src/HttpUrlParser.o \
./src/HttpUrlParserDecodeException.o \
./src/HttpUrlParserEncodeException.o \
./src/HttpUrlParserException.o \
./src/HttpUrlParserInvalidSchemeException.o \
./src/HttpUrlParserInvalidUrlException.o \
./src/HttpUrlParserTLDCacheException.o \
./src/IPv4Tools.o \
./src/Socket.o \
./src/SocketIPv4.o \
./src/SocketIPv4TCP.o \
./src/SocketIPv4TCPClient.o \
./src/SocketIPv4TCPSSLClient.o \
./src/SocketIPv4TCPServer.o \
./src/SocketOptions.o 

CPP_DEPS += \
./src/HtmlData.d \
./src/HttpClientEx.d \
./src/HttpClientSettings.d \
./src/HttpConnection.d \
./src/HttpCookie.d \
./src/HttpGetRequest.d \
./src/HttpHeader.d \
./src/HttpPostRequest.d \
./src/HttpRequest.d \
./src/HttpRequestResult.d \
./src/HttpUrl.d \
./src/HttpUrlParser.d \
./src/HttpUrlParserDecodeException.d \
./src/HttpUrlParserEncodeException.d \
./src/HttpUrlParserException.d \
./src/HttpUrlParserInvalidSchemeException.d \
./src/HttpUrlParserInvalidUrlException.d \
./src/HttpUrlParserTLDCacheException.d \
./src/IPv4Tools.d \
./src/Socket.d \
./src/SocketIPv4.d \
./src/SocketIPv4TCP.d \
./src/SocketIPv4TCPClient.d \
./src/SocketIPv4TCPSSLClient.d \
./src/SocketIPv4TCPServer.d \
./src/SocketOptions.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -I/usr/include/libxml2 -I../../Logging/src -I../../Threading/src -O0 -g -Wall -c -fmessage-length=0 -pthread -rdynamic -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


