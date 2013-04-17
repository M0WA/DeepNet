################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/HtmlParserException.cpp \
../src/HtmlSAX2Attribute.cpp \
../src/HtmlSAX2Document.cpp \
../src/HtmlSAX2Element.cpp \
../src/HtmlSAX2Namespace.cpp \
../src/HtmlSAX2Parser.cpp \
../src/HtmlTester.cpp \
../src/TLD.cpp \
../src/URL.cpp \
../src/UrlInserter.cpp \
../src/UrlParser.cpp \
../src/UrlParserDecodeException.cpp \
../src/UrlParserEncodeException.cpp \
../src/UrlParserInvalidUrlException.cpp 

OBJS += \
./src/HtmlParserException.o \
./src/HtmlSAX2Attribute.o \
./src/HtmlSAX2Document.o \
./src/HtmlSAX2Element.o \
./src/HtmlSAX2Namespace.o \
./src/HtmlSAX2Parser.o \
./src/HtmlTester.o \
./src/TLD.o \
./src/URL.o \
./src/UrlInserter.o \
./src/UrlParser.o \
./src/UrlParserDecodeException.o \
./src/UrlParserEncodeException.o \
./src/UrlParserInvalidUrlException.o 

CPP_DEPS += \
./src/HtmlParserException.d \
./src/HtmlSAX2Attribute.d \
./src/HtmlSAX2Document.d \
./src/HtmlSAX2Element.d \
./src/HtmlSAX2Namespace.d \
./src/HtmlSAX2Parser.d \
./src/HtmlTester.d \
./src/TLD.d \
./src/URL.d \
./src/UrlInserter.d \
./src/UrlParser.d \
./src/UrlParserDecodeException.d \
./src/UrlParserEncodeException.d \
./src/UrlParserInvalidUrlException.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -I/usr/include/libxml2 -I../../Caching/src -I../../Indexer/src -I../../Bot/src -I../../Threading/src -I../../Logging/src -I../../Database/src -I../../Database/generated -O3 -g -Wall -c -fmessage-length=0 -fPIC -pthread -rdynamic -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


