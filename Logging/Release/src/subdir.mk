################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CharsetEncoder.cpp \
../src/CompressionTools.cpp \
../src/ConsoleLogging.cpp \
../src/ContainerTools.cpp \
../src/DebuggingTools.cpp \
../src/EmptyException.cpp \
../src/Exception.cpp \
../src/FileLogging.cpp \
../src/FileTools.cpp \
../src/HashTools.cpp \
../src/Logging.cpp \
../src/MimeType.cpp \
../src/NotImplementedException.cpp \
../src/OpenSSLThreadLock.cpp \
../src/PCRERegex.cpp \
../src/PCRERegexGroup.cpp \
../src/PCRERegexResult.cpp \
../src/PerformanceCounter.cpp \
../src/Regex.cpp \
../src/SpellChecking.cpp \
../src/Stack.cpp \
../src/StdException.cpp \
../src/StringTools.cpp \
../src/TimeTools.cpp 

OBJS += \
./src/CharsetEncoder.o \
./src/CompressionTools.o \
./src/ConsoleLogging.o \
./src/ContainerTools.o \
./src/DebuggingTools.o \
./src/EmptyException.o \
./src/Exception.o \
./src/FileLogging.o \
./src/FileTools.o \
./src/HashTools.o \
./src/Logging.o \
./src/MimeType.o \
./src/NotImplementedException.o \
./src/OpenSSLThreadLock.o \
./src/PCRERegex.o \
./src/PCRERegexGroup.o \
./src/PCRERegexResult.o \
./src/PerformanceCounter.o \
./src/Regex.o \
./src/SpellChecking.o \
./src/Stack.o \
./src/StdException.o \
./src/StringTools.o \
./src/TimeTools.o 

CPP_DEPS += \
./src/CharsetEncoder.d \
./src/CompressionTools.d \
./src/ConsoleLogging.d \
./src/ContainerTools.d \
./src/DebuggingTools.d \
./src/EmptyException.d \
./src/Exception.d \
./src/FileLogging.d \
./src/FileTools.d \
./src/HashTools.d \
./src/Logging.d \
./src/MimeType.d \
./src/NotImplementedException.d \
./src/OpenSSLThreadLock.d \
./src/PCRERegex.d \
./src/PCRERegexGroup.d \
./src/PCRERegexResult.d \
./src/PerformanceCounter.d \
./src/Regex.d \
./src/SpellChecking.d \
./src/Stack.d \
./src/StdException.d \
./src/StringTools.d \
./src/TimeTools.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -I/usr/include/libxml2 -I../../Threading/src -I../../Bot/src -I../../Database/src -I../../Database/generated -O3 -g -Wall -c -fmessage-length=0 -pthread -rdynamic -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


