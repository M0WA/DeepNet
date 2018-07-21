################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/GetUrlsThread.cpp \
../src/RegisterCrawlerThread.cpp \
../src/ReleaseCrawlerThread.cpp \
../src/Sync.cpp \
../src/SyncClient.cpp 

OBJS += \
./src/GetUrlsThread.o \
./src/RegisterCrawlerThread.o \
./src/ReleaseCrawlerThread.o \
./src/Sync.o \
./src/SyncClient.o 

CPP_DEPS += \
./src/GetUrlsThread.d \
./src/RegisterCrawlerThread.d \
./src/ReleaseCrawlerThread.d \
./src/Sync.d \
./src/SyncClient.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -I/usr/include/libxml2 -I../../Threading/src -I../../Networking/src -I../../Database/src -I../../Database/generated -I../../Logging/src -I../../Tools/src -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


