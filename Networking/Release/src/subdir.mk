################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/HtmlData.cpp \
../src/HttpClient.cpp \
../src/HttpConnection.cpp \
../src/HttpGetRequest.cpp \
../src/HttpPostRequest.cpp \
../src/HttpRequest.cpp \
../src/HttpResponse.cpp \
../src/HttpUrl.cpp \
../src/HttpUrlParser.cpp \
../src/HttpUrlParserDecodeException.cpp \
../src/HttpUrlParserEncodeException.cpp \
../src/HttpUrlParserException.cpp \
../src/HttpUrlParserInvalidSchemeException.cpp \
../src/HttpUrlParserInvalidUrlException.cpp \
../src/IPv4Tools.cpp \
../src/Socket.cpp \
../src/SocketIPv4.cpp \
../src/SocketIPv4TCP.cpp \
../src/SocketIPv4TCPClient.cpp \
../src/SocketIPv4TCPServer.cpp 

OBJS += \
./src/HtmlData.o \
./src/HttpClient.o \
./src/HttpConnection.o \
./src/HttpGetRequest.o \
./src/HttpPostRequest.o \
./src/HttpRequest.o \
./src/HttpResponse.o \
./src/HttpUrl.o \
./src/HttpUrlParser.o \
./src/HttpUrlParserDecodeException.o \
./src/HttpUrlParserEncodeException.o \
./src/HttpUrlParserException.o \
./src/HttpUrlParserInvalidSchemeException.o \
./src/HttpUrlParserInvalidUrlException.o \
./src/IPv4Tools.o \
./src/Socket.o \
./src/SocketIPv4.o \
./src/SocketIPv4TCP.o \
./src/SocketIPv4TCPClient.o \
./src/SocketIPv4TCPServer.o 

CPP_DEPS += \
./src/HtmlData.d \
./src/HttpClient.d \
./src/HttpConnection.d \
./src/HttpGetRequest.d \
./src/HttpPostRequest.d \
./src/HttpRequest.d \
./src/HttpResponse.d \
./src/HttpUrl.d \
./src/HttpUrlParser.d \
./src/HttpUrlParserDecodeException.d \
./src/HttpUrlParserEncodeException.d \
./src/HttpUrlParserException.d \
./src/HttpUrlParserInvalidSchemeException.d \
./src/HttpUrlParserInvalidUrlException.d \
./src/IPv4Tools.d \
./src/Socket.d \
./src/SocketIPv4.d \
./src/SocketIPv4TCP.d \
./src/SocketIPv4TCPClient.d \
./src/SocketIPv4TCPServer.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -I/usr/include/libxml2 -I../../Logging/src -I../../Threading/src -O0 -g -Wall -c -fmessage-length=0 -pthread -rdynamic -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


