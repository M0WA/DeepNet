################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/WorkerBot.cpp \
../src/main.cpp 

OBJS += \
./src/WorkerBot.o \
./src/main.o 

CPP_DEPS += \
./src/WorkerBot.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -I/usr/include/libxml2 -I../../Networking/src -I../../Caching/src -I../../Indexer/src -I../../Parser/src -I../../Crawler/src -I../../Database/src -I../../Database/generated -I../../HtmlParser/src -I../../Bot/src -I../../Threading/src -I../../Logging/src -O3 -g -Wall -c -fmessage-length=0 -pthread  -rdynamic -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


