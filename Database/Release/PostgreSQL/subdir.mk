################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../PostgreSQL/PostgreSQLConnection.cpp \
../PostgreSQL/PostgreSQLDatabaseConfig.cpp \
../PostgreSQL/PostgreSQLException.cpp \
../PostgreSQL/PostgreSQLInsertOrUpdateAffectedKeyStatement.cpp \
../PostgreSQL/PostgreSQLInsertOrUpdateStatement.cpp \
../PostgreSQL/PostgreSQLInsertStatement.cpp \
../PostgreSQL/PostgreSQLInvalidStatementException.cpp \
../PostgreSQL/PostgreSQLTableBase.cpp \
../PostgreSQL/PostgreSQLUniqueKeyIsSumColumnException.cpp \
../PostgreSQL/PostgreSQLUpdateStatement.cpp 

OBJS += \
./PostgreSQL/PostgreSQLConnection.o \
./PostgreSQL/PostgreSQLDatabaseConfig.o \
./PostgreSQL/PostgreSQLException.o \
./PostgreSQL/PostgreSQLInsertOrUpdateAffectedKeyStatement.o \
./PostgreSQL/PostgreSQLInsertOrUpdateStatement.o \
./PostgreSQL/PostgreSQLInsertStatement.o \
./PostgreSQL/PostgreSQLInvalidStatementException.o \
./PostgreSQL/PostgreSQLTableBase.o \
./PostgreSQL/PostgreSQLUniqueKeyIsSumColumnException.o \
./PostgreSQL/PostgreSQLUpdateStatement.o 

CPP_DEPS += \
./PostgreSQL/PostgreSQLConnection.d \
./PostgreSQL/PostgreSQLDatabaseConfig.d \
./PostgreSQL/PostgreSQLException.d \
./PostgreSQL/PostgreSQLInsertOrUpdateAffectedKeyStatement.d \
./PostgreSQL/PostgreSQLInsertOrUpdateStatement.d \
./PostgreSQL/PostgreSQLInsertStatement.d \
./PostgreSQL/PostgreSQLInvalidStatementException.d \
./PostgreSQL/PostgreSQLTableBase.d \
./PostgreSQL/PostgreSQLUniqueKeyIsSumColumnException.d \
./PostgreSQL/PostgreSQLUpdateStatement.d 


# Each subdirectory must supply rules for building sources it contributes
PostgreSQL/%.o: ../PostgreSQL/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -I../../Database/src -I../../Bot/src -I../../Database/generated -I../../Logging/src -I../../Tools/src -I../../Threading/src -I/usr/include/ -I/usr/include/mysql -I/usr/include/postgresql/ -I/usr/include/postgresql/9.4/server/ -O3 -fPIC -fomit-frame-pointer -g -Wall -c -fmessage-length=0 -pthread -rdynamic -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


