################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/html5/OpenElementStack.cpp \
../src/html5/Tokeniser.cpp \
../src/html5/TreeConstruction.cpp \
../src/html5/TreeConstructionContext.cpp 

OBJS += \
./src/html5/OpenElementStack.o \
./src/html5/Tokeniser.o \
./src/html5/TreeConstruction.o \
./src/html5/TreeConstructionContext.o 

CPP_DEPS += \
./src/html5/OpenElementStack.d \
./src/html5/Tokeniser.d \
./src/html5/TreeConstruction.d \
./src/html5/TreeConstructionContext.d 


# Each subdirectory must supply rules for building sources it contributes
src/html5/%.o: ../src/html5/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -DENABLE_PERFORMANCE_LOG -I../../Tools/src -I../../Database/src -I../../Database/generated -I../../Threading/src -I../../Networking/src -I../../HtmlParser/src -I../../Logging/src -O3 -fPIC -fomit-frame-pointer -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


