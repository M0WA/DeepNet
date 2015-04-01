################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CharsetEncoder.cpp \
../src/CompressionTools.cpp \
../src/ContainerTools.cpp \
../src/DebuggingTools.cpp \
../src/EmptyException.cpp \
../src/Exception.cpp \
../src/FileTools.cpp \
../src/HashTools.cpp \
../src/InvalidOperationException.cpp \
../src/MemoryContainer.cpp \
../src/MimeType.cpp \
../src/NotImplementedException.cpp \
../src/OpenSSLThreadLock.cpp \
../src/PCRERegex.cpp \
../src/PCRERegexGroup.cpp \
../src/PCRERegexResult.cpp \
../src/PerformanceCounter.cpp \
../src/Pointer.cpp \
../src/PointerContainer.cpp \
../src/Regex.cpp \
../src/SpellChecking.cpp \
../src/Stack.cpp \
../src/StdException.cpp \
../src/StringTools.cpp \
../src/SynchronizedIDArray.cpp \
../src/TimeTools.cpp \
../src/TokenBucket.cpp 

OBJS += \
./src/CharsetEncoder.o \
./src/CompressionTools.o \
./src/ContainerTools.o \
./src/DebuggingTools.o \
./src/EmptyException.o \
./src/Exception.o \
./src/FileTools.o \
./src/HashTools.o \
./src/InvalidOperationException.o \
./src/MemoryContainer.o \
./src/MimeType.o \
./src/NotImplementedException.o \
./src/OpenSSLThreadLock.o \
./src/PCRERegex.o \
./src/PCRERegexGroup.o \
./src/PCRERegexResult.o \
./src/PerformanceCounter.o \
./src/Pointer.o \
./src/PointerContainer.o \
./src/Regex.o \
./src/SpellChecking.o \
./src/Stack.o \
./src/StdException.o \
./src/StringTools.o \
./src/SynchronizedIDArray.o \
./src/TimeTools.o \
./src/TokenBucket.o 

CPP_DEPS += \
./src/CharsetEncoder.d \
./src/CompressionTools.d \
./src/ContainerTools.d \
./src/DebuggingTools.d \
./src/EmptyException.d \
./src/Exception.d \
./src/FileTools.d \
./src/HashTools.d \
./src/InvalidOperationException.d \
./src/MemoryContainer.d \
./src/MimeType.d \
./src/NotImplementedException.d \
./src/OpenSSLThreadLock.d \
./src/PCRERegex.d \
./src/PCRERegexGroup.d \
./src/PCRERegexResult.d \
./src/PerformanceCounter.d \
./src/Pointer.d \
./src/PointerContainer.d \
./src/Regex.d \
./src/SpellChecking.d \
./src/Stack.d \
./src/StdException.d \
./src/StringTools.d \
./src/SynchronizedIDArray.d \
./src/TimeTools.d \
./src/TokenBucket.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D_REENTRANT -I/usr/include/libxml2 -I../../Logging/src -I../../Threading/src -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


