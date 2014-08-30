################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CommerceSearchMatchCriteria.cpp \
../src/CommerceSearchMatchGroup.cpp \
../src/CommerceSearchParser.cpp \
../src/CommerceSearchParserThread.cpp \
../src/CommerceSearchProduct.cpp \
../src/GenericWebHtmlParser.cpp \
../src/GenericWebHtmlParserThread.cpp \
../src/HtmlParserBase.cpp \
../src/HtmlParserBaseFactory.cpp \
../src/HtmlParserEntry.cpp \
../src/HtmlParserParam.cpp \
../src/HtmlParserThread.cpp 

OBJS += \
./src/CommerceSearchMatchCriteria.o \
./src/CommerceSearchMatchGroup.o \
./src/CommerceSearchParser.o \
./src/CommerceSearchParserThread.o \
./src/CommerceSearchProduct.o \
./src/GenericWebHtmlParser.o \
./src/GenericWebHtmlParserThread.o \
./src/HtmlParserBase.o \
./src/HtmlParserBaseFactory.o \
./src/HtmlParserEntry.o \
./src/HtmlParserParam.o \
./src/HtmlParserThread.o 

CPP_DEPS += \
./src/CommerceSearchMatchCriteria.d \
./src/CommerceSearchMatchGroup.d \
./src/CommerceSearchParser.d \
./src/CommerceSearchParserThread.d \
./src/CommerceSearchProduct.d \
./src/GenericWebHtmlParser.d \
./src/GenericWebHtmlParserThread.d \
./src/HtmlParserBase.d \
./src/HtmlParserBaseFactory.d \
./src/HtmlParserEntry.d \
./src/HtmlParserParam.d \
./src/HtmlParserThread.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -I/usr/include/libxml2 -I../../Tools/src -I../../Networking/src -I../../Threading/src -I../../Caching/src -I../../Bot/src -I../../Logging/src -I../../HtmlParser/src -I../../Database/src -I../../Database/generated -O3 -fPIC -fomit-frame-pointer -g -Wall -c -fmessage-length=0 -pthread -rdynamic -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


