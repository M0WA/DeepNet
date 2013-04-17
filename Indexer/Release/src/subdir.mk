################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ContentIndexer.cpp \
../src/DataminingContentIndexer.cpp \
../src/DataminingCriteria.cpp \
../src/DataminingDictionary.cpp \
../src/DataminingIndexer.cpp \
../src/DataminingIndexerThread.cpp \
../src/DataminingNotifier.cpp \
../src/DataminingNotifierEmail.cpp \
../src/Dictionary.cpp \
../src/GenericWebContentIndexer.cpp \
../src/GenericWebDictionary.cpp \
../src/GenericWebIndexer.cpp \
../src/GenericWebIndexerThread.cpp \
../src/Indexer.cpp \
../src/IndexerBase.cpp \
../src/IndexerTester.cpp \
../src/IndexerThread.cpp \
../src/MetaIndexer.cpp \
../src/Word.cpp 

OBJS += \
./src/ContentIndexer.o \
./src/DataminingContentIndexer.o \
./src/DataminingCriteria.o \
./src/DataminingDictionary.o \
./src/DataminingIndexer.o \
./src/DataminingIndexerThread.o \
./src/DataminingNotifier.o \
./src/DataminingNotifierEmail.o \
./src/Dictionary.o \
./src/GenericWebContentIndexer.o \
./src/GenericWebDictionary.o \
./src/GenericWebIndexer.o \
./src/GenericWebIndexerThread.o \
./src/Indexer.o \
./src/IndexerBase.o \
./src/IndexerTester.o \
./src/IndexerThread.o \
./src/MetaIndexer.o \
./src/Word.o 

CPP_DEPS += \
./src/ContentIndexer.d \
./src/DataminingContentIndexer.d \
./src/DataminingCriteria.d \
./src/DataminingDictionary.d \
./src/DataminingIndexer.d \
./src/DataminingIndexerThread.d \
./src/DataminingNotifier.d \
./src/DataminingNotifierEmail.d \
./src/Dictionary.d \
./src/GenericWebContentIndexer.d \
./src/GenericWebDictionary.d \
./src/GenericWebIndexer.d \
./src/GenericWebIndexerThread.d \
./src/Indexer.d \
./src/IndexerBase.d \
./src/IndexerTester.d \
./src/IndexerThread.d \
./src/MetaIndexer.d \
./src/Word.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -I/usr/include/libxml2 -I../../Networking/src -I../../Bot/src -I../../Caching/src -I../../HtmlParser/src -I../../Threading/src -I../../Logging/src -I../../Database/src -I../../Database/generated -O3 -g -Wall -c -fmessage-length=0 -pthread -rdynamic -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


