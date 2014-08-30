################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/generic/Token.cpp \
../src/generic/TreeConstructionBase.cpp 

OBJS += \
./src/generic/Token.o \
./src/generic/TreeConstructionBase.o 

CPP_DEPS += \
./src/generic/Token.d \
./src/generic/TreeConstructionBase.d 


# Each subdirectory must supply rules for building sources it contributes
src/generic/%.o: ../src/generic/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -DENABLE_PERFORMANCE_LOG -I../../Tools/src -I../../Database/src -I../../Database/generated -I../../Threading/src -I../../Networking/src -I../../HtmlParser/src -I../../Logging/src -O3 -fPIC -fomit-frame-pointer -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


