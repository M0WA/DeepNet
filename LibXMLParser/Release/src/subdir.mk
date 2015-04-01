################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/HtmlSAX2Attribute.cpp \
../src/HtmlSAX2Document.cpp \
../src/HtmlSAX2Element.cpp \
../src/HtmlSAX2Namespace.cpp \
../src/HtmlSAX2Parser.cpp \
../src/LibXMLParserResult.cpp 

OBJS += \
./src/HtmlSAX2Attribute.o \
./src/HtmlSAX2Document.o \
./src/HtmlSAX2Element.o \
./src/HtmlSAX2Namespace.o \
./src/HtmlSAX2Parser.o \
./src/LibXMLParserResult.o 

CPP_DEPS += \
./src/HtmlSAX2Attribute.d \
./src/HtmlSAX2Document.d \
./src/HtmlSAX2Element.d \
./src/HtmlSAX2Namespace.d \
./src/HtmlSAX2Parser.d \
./src/LibXMLParserResult.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/libxml2 -I../../Tools/src -I../../Threading/src -I../../HtmlParser/src -I../../Logging/src -I../../Networking/src -O3 -fPIC -fomit-frame-pointer -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


