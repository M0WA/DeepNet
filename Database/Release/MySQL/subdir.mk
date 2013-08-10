################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../MySQL/MySQLConnection.cpp \
../MySQL/MySQLDatabaseConfig.cpp \
../MySQL/MySQLInsertOrUpdateStatement.cpp \
../MySQL/MySQLInsertStatement.cpp \
../MySQL/MySQLOperationTimeoutException.cpp \
../MySQL/MySQLQueryErrorException.cpp \
../MySQL/MySQLQueryResultStoreException.cpp \
../MySQL/MySQLSelectStatement.cpp \
../MySQL/MySQLTableBase.cpp \
../MySQL/MySQLUpdateStatement.cpp 

OBJS += \
./MySQL/MySQLConnection.o \
./MySQL/MySQLDatabaseConfig.o \
./MySQL/MySQLInsertOrUpdateStatement.o \
./MySQL/MySQLInsertStatement.o \
./MySQL/MySQLOperationTimeoutException.o \
./MySQL/MySQLQueryErrorException.o \
./MySQL/MySQLQueryResultStoreException.o \
./MySQL/MySQLSelectStatement.o \
./MySQL/MySQLTableBase.o \
./MySQL/MySQLUpdateStatement.o 

CPP_DEPS += \
./MySQL/MySQLConnection.d \
./MySQL/MySQLDatabaseConfig.d \
./MySQL/MySQLInsertOrUpdateStatement.d \
./MySQL/MySQLInsertStatement.d \
./MySQL/MySQLOperationTimeoutException.d \
./MySQL/MySQLQueryErrorException.d \
./MySQL/MySQLQueryResultStoreException.d \
./MySQL/MySQLSelectStatement.d \
./MySQL/MySQLTableBase.d \
./MySQL/MySQLUpdateStatement.d 


# Each subdirectory must supply rules for building sources it contributes
MySQL/%.o: ../MySQL/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -I/home/momo/deepnet/Database/src -I/home/momo/deepnet/Bot/src -I/home/momo/deepnet/Database/generated -I/home/momo/deepnet/Logging/src -I/home/momo/deepnet/Tools/src -I/home/momo/deepnet/Threading/src -I/usr/include/postgresql/ -O3 -g -Wall -c -fmessage-length=0 -pthread -rdynamic -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


