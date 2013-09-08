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
	g++ -D_REENTRANT -I/home/momo/deepnet/Database/src -I/home/momo/deepnet/Bot/src -I/home/momo/deepnet/Database/generated -I/home/momo/deepnet/Logging/src -I/home/momo/deepnet/Tools/src -I/home/momo/deepnet/Threading/src -I/usr/include/postgresql/ -O3 -fPIC -fomit-frame-pointer -g -Wall -c -fmessage-length=0 -pthread -rdynamic -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


