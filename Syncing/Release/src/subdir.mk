################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/GetUrlsThread.cpp \
../src/ReleaseCrawlerThread.cpp 

OBJS += \
./src/GetUrlsThread.o \
./src/ReleaseCrawlerThread.o 

CPP_DEPS += \
./src/GetUrlsThread.d \
./src/ReleaseCrawlerThread.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../Threading/src -I../../Database/src -I../../Database/generated -I../../Logging/src -I../../Tools/src -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


