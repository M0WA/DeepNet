################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/DatabaseUrl.cpp \
../src/HtmlParserException.cpp \
../src/HtmlSAX2Attribute.cpp \
../src/HtmlSAX2Document.cpp \
../src/HtmlSAX2Element.cpp \
../src/HtmlSAX2Namespace.cpp \
../src/HtmlSAX2Parser.cpp \
../src/TLD.cpp \
../src/UrlInserter.cpp \
../src/UrlParserDecodeException.cpp \
../src/UrlParserEncodeException.cpp \
../src/UrlParserInvalidUrlException.cpp 

OBJS += \
./src/DatabaseUrl.o \
./src/HtmlParserException.o \
./src/HtmlSAX2Attribute.o \
./src/HtmlSAX2Document.o \
./src/HtmlSAX2Element.o \
./src/HtmlSAX2Namespace.o \
./src/HtmlSAX2Parser.o \
./src/TLD.o \
./src/UrlInserter.o \
./src/UrlParserDecodeException.o \
./src/UrlParserEncodeException.o \
./src/UrlParserInvalidUrlException.o 

CPP_DEPS += \
./src/DatabaseUrl.d \
./src/HtmlParserException.d \
./src/HtmlSAX2Attribute.d \
./src/HtmlSAX2Document.d \
./src/HtmlSAX2Element.d \
./src/HtmlSAX2Namespace.d \
./src/HtmlSAX2Parser.d \
./src/TLD.d \
./src/UrlInserter.d \
./src/UrlParserDecodeException.d \
./src/UrlParserEncodeException.d \
./src/UrlParserInvalidUrlException.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -I/usr/include/libxml2 -I../../Tools/src -I../../Networking/src -I../../Caching/src -I../../Indexer/src -I../../Bot/src -I../../Threading/src -I../../Logging/src -I../../Database/src -I../../Database/generated -O3 -g -Wall -c -fmessage-length=0 -pthread -rdynamic -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


