################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DB2/DB2Connection.cpp \
../DB2/DB2DatabaseConfig.cpp 

OBJS += \
./DB2/DB2Connection.o \
./DB2/DB2DatabaseConfig.o 

CPP_DEPS += \
./DB2/DB2Connection.d \
./DB2/DB2DatabaseConfig.d 


# Each subdirectory must supply rules for building sources it contributes
DB2/%.o: ../DB2/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -I../src -I../../Bot/src -I../generated -I../../Logging/src -I../../Threading/src -O3 -g -Wall -c -fmessage-length=0 -pthread -rdynamic -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


