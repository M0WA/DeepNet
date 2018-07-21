################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/HtmlParserException.cpp \
../src/HtmlParserFactory.cpp \
../src/IHtmlParser.cpp \
../src/UrlInserter.cpp \
../src/UrlParserDecodeException.cpp \
../src/UrlParserEncodeException.cpp \
../src/UrlParserInvalidUrlException.cpp 

OBJS += \
./src/HtmlParserException.o \
./src/HtmlParserFactory.o \
./src/IHtmlParser.o \
./src/UrlInserter.o \
./src/UrlParserDecodeException.o \
./src/UrlParserEncodeException.o \
./src/UrlParserInvalidUrlException.o 

CPP_DEPS += \
./src/HtmlParserException.d \
./src/HtmlParserFactory.d \
./src/IHtmlParser.d \
./src/UrlInserter.d \
./src/UrlParserDecodeException.d \
./src/UrlParserEncodeException.d \
./src/UrlParserInvalidUrlException.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -I/usr/include/libxml2 -I../../HtmlParser/src -I../../LibXMLParser/src -I../../Tools/src -I../../Networking/src -I../../Caching/src -I../../Indexer/src -I../../Bot/src -I../../Threading/src -I../../Logging/src -I../../Database/src -I../../Database/generated -O3 -fPIC -fomit-frame-pointer -g -Wall -c -fmessage-length=0 -pthread -rdynamic -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


