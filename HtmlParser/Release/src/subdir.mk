################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/DOMTree.cpp \
../src/DatabaseUrl.cpp \
../src/HtmlAttribute.cpp \
../src/HtmlDocument.cpp \
../src/HtmlElement.cpp \
../src/HtmlElementA.cpp \
../src/HtmlElementCreateParam.cpp \
../src/HtmlElementFORM.cpp \
../src/HtmlElementFactory.cpp \
../src/HtmlElementGeneric.cpp \
../src/HtmlElementH.cpp \
../src/HtmlElementIFRAME.cpp \
../src/HtmlElementIMG.cpp \
../src/HtmlElementLI.cpp \
../src/HtmlElementMETA.cpp \
../src/HtmlElementRules.cpp \
../src/HtmlElementTD.cpp \
../src/HtmlElementTH.cpp \
../src/HtmlElementTITLE.cpp \
../src/HtmlElementText.cpp \
../src/HtmlElementType.cpp \
../src/HtmlParser.cpp \
../src/HtmlParserException.cpp \
../src/HtmlParserInvalidStackException.cpp \
../src/HtmlTester.cpp \
../src/TLD.cpp \
../src/UrlInserter.cpp \
../src/UrlParserDecodeException.cpp \
../src/UrlParserEncodeException.cpp \
../src/UrlParserInvalidUrlException.cpp 

OBJS += \
./src/DOMTree.o \
./src/DatabaseUrl.o \
./src/HtmlAttribute.o \
./src/HtmlDocument.o \
./src/HtmlElement.o \
./src/HtmlElementA.o \
./src/HtmlElementCreateParam.o \
./src/HtmlElementFORM.o \
./src/HtmlElementFactory.o \
./src/HtmlElementGeneric.o \
./src/HtmlElementH.o \
./src/HtmlElementIFRAME.o \
./src/HtmlElementIMG.o \
./src/HtmlElementLI.o \
./src/HtmlElementMETA.o \
./src/HtmlElementRules.o \
./src/HtmlElementTD.o \
./src/HtmlElementTH.o \
./src/HtmlElementTITLE.o \
./src/HtmlElementText.o \
./src/HtmlElementType.o \
./src/HtmlParser.o \
./src/HtmlParserException.o \
./src/HtmlParserInvalidStackException.o \
./src/HtmlTester.o \
./src/TLD.o \
./src/UrlInserter.o \
./src/UrlParserDecodeException.o \
./src/UrlParserEncodeException.o \
./src/UrlParserInvalidUrlException.o 

CPP_DEPS += \
./src/DOMTree.d \
./src/DatabaseUrl.d \
./src/HtmlAttribute.d \
./src/HtmlDocument.d \
./src/HtmlElement.d \
./src/HtmlElementA.d \
./src/HtmlElementCreateParam.d \
./src/HtmlElementFORM.d \
./src/HtmlElementFactory.d \
./src/HtmlElementGeneric.d \
./src/HtmlElementH.d \
./src/HtmlElementIFRAME.d \
./src/HtmlElementIMG.d \
./src/HtmlElementLI.d \
./src/HtmlElementMETA.d \
./src/HtmlElementRules.d \
./src/HtmlElementTD.d \
./src/HtmlElementTH.d \
./src/HtmlElementTITLE.d \
./src/HtmlElementText.d \
./src/HtmlElementType.d \
./src/HtmlParser.d \
./src/HtmlParserException.d \
./src/HtmlParserInvalidStackException.d \
./src/HtmlTester.d \
./src/TLD.d \
./src/UrlInserter.d \
./src/UrlParserDecodeException.d \
./src/UrlParserEncodeException.d \
./src/UrlParserInvalidUrlException.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -I/usr/include/libxml2 -I../../Networking/src -I../../Caching/src -I../../Indexer/src -I../../Bot/src -I../../Threading/src -I../../Logging/src -I../../Database/src -I../../Database/generated -O3 -g -Wall -c -fmessage-length=0 -pthread -rdynamic -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


