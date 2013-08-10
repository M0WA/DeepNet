################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Mutex.cpp \
../src/ReadWriteLock.cpp \
../src/Semaphore.cpp \
../src/Thread.cpp 

OBJS += \
./src/Mutex.o \
./src/ReadWriteLock.o \
./src/Semaphore.o \
./src/Thread.o 

CPP_DEPS += \
./src/Mutex.d \
./src/ReadWriteLock.d \
./src/Semaphore.d \
./src/Thread.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -O3 -g -Wall -c -fmessage-length=0 -pthread  -rdynamic -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


