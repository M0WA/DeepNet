################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/DatabaseColumnDatasizeExceededException.cpp \
../src/DatabaseConfig.cpp \
../src/DatabaseConnection.cpp \
../src/DatabaseEmptyDatabaseNameException.cpp \
../src/DatabaseEmptyTableNameException.cpp \
../src/DatabaseException.cpp \
../src/DatabaseHelper.cpp \
../src/DatabaseInvalidColumnNameException.cpp \
../src/DatabaseInvalidOperatorTypeException.cpp \
../src/DatabaseInvalidTypeConversionException.cpp \
../src/DatabaseInvalidTypeException.cpp \
../src/DatabaseLogging.cpp \
../src/DatabaseLoggingNotInitializedException.cpp \
../src/DatabaseNoColumnsException.cpp \
../src/DatabaseNoPrimaryKeyException.cpp \
../src/DatabaseNotConnectedException.cpp \
../src/DatabaseNotInitializedException.cpp \
../src/DatabaseNotNullableException.cpp \
../src/DatabaseValueNotSpecifiedException.cpp \
../src/DeleteStatement.cpp \
../src/GenericStatement.cpp \
../src/GroupByClause.cpp \
../src/InnerJoinCondition.cpp \
../src/InnerJoinEntry.cpp \
../src/InsertOrUpdateStatement.cpp \
../src/InsertStatement.cpp \
../src/OrderByClause.cpp \
../src/SelectResultContainer.cpp \
../src/SelectStatement.cpp \
../src/Statement.cpp \
../src/TableBase.cpp \
../src/TableColumn.cpp \
../src/TableColumnArrayContainer.cpp \
../src/TableColumnContainer.cpp \
../src/TableColumnDefinition.cpp \
../src/TableColumnDefinitionCreateParam.cpp \
../src/TableColumnValue.cpp \
../src/TableColumnValueTyped.cpp \
../src/TableDefinition.cpp \
../src/TableDefinitionCreateParam.cpp \
../src/UpdateStatement.cpp \
../src/WhereCondition.cpp \
../src/WhereConditionCompositeOperator.cpp \
../src/WhereConditionOperator.cpp \
../src/WhereConditionTableColumn.cpp \
../src/WhereConditionTableColumnContainer.cpp \
../src/WhereConditionTableColumnCreateParam.cpp 

OBJS += \
./src/DatabaseColumnDatasizeExceededException.o \
./src/DatabaseConfig.o \
./src/DatabaseConnection.o \
./src/DatabaseEmptyDatabaseNameException.o \
./src/DatabaseEmptyTableNameException.o \
./src/DatabaseException.o \
./src/DatabaseHelper.o \
./src/DatabaseInvalidColumnNameException.o \
./src/DatabaseInvalidOperatorTypeException.o \
./src/DatabaseInvalidTypeConversionException.o \
./src/DatabaseInvalidTypeException.o \
./src/DatabaseLogging.o \
./src/DatabaseLoggingNotInitializedException.o \
./src/DatabaseNoColumnsException.o \
./src/DatabaseNoPrimaryKeyException.o \
./src/DatabaseNotConnectedException.o \
./src/DatabaseNotInitializedException.o \
./src/DatabaseNotNullableException.o \
./src/DatabaseValueNotSpecifiedException.o \
./src/DeleteStatement.o \
./src/GenericStatement.o \
./src/GroupByClause.o \
./src/InnerJoinCondition.o \
./src/InnerJoinEntry.o \
./src/InsertOrUpdateStatement.o \
./src/InsertStatement.o \
./src/OrderByClause.o \
./src/SelectResultContainer.o \
./src/SelectStatement.o \
./src/Statement.o \
./src/TableBase.o \
./src/TableColumn.o \
./src/TableColumnArrayContainer.o \
./src/TableColumnContainer.o \
./src/TableColumnDefinition.o \
./src/TableColumnDefinitionCreateParam.o \
./src/TableColumnValue.o \
./src/TableColumnValueTyped.o \
./src/TableDefinition.o \
./src/TableDefinitionCreateParam.o \
./src/UpdateStatement.o \
./src/WhereCondition.o \
./src/WhereConditionCompositeOperator.o \
./src/WhereConditionOperator.o \
./src/WhereConditionTableColumn.o \
./src/WhereConditionTableColumnContainer.o \
./src/WhereConditionTableColumnCreateParam.o 

CPP_DEPS += \
./src/DatabaseColumnDatasizeExceededException.d \
./src/DatabaseConfig.d \
./src/DatabaseConnection.d \
./src/DatabaseEmptyDatabaseNameException.d \
./src/DatabaseEmptyTableNameException.d \
./src/DatabaseException.d \
./src/DatabaseHelper.d \
./src/DatabaseInvalidColumnNameException.d \
./src/DatabaseInvalidOperatorTypeException.d \
./src/DatabaseInvalidTypeConversionException.d \
./src/DatabaseInvalidTypeException.d \
./src/DatabaseLogging.d \
./src/DatabaseLoggingNotInitializedException.d \
./src/DatabaseNoColumnsException.d \
./src/DatabaseNoPrimaryKeyException.d \
./src/DatabaseNotConnectedException.d \
./src/DatabaseNotInitializedException.d \
./src/DatabaseNotNullableException.d \
./src/DatabaseValueNotSpecifiedException.d \
./src/DeleteStatement.d \
./src/GenericStatement.d \
./src/GroupByClause.d \
./src/InnerJoinCondition.d \
./src/InnerJoinEntry.d \
./src/InsertOrUpdateStatement.d \
./src/InsertStatement.d \
./src/OrderByClause.d \
./src/SelectResultContainer.d \
./src/SelectStatement.d \
./src/Statement.d \
./src/TableBase.d \
./src/TableColumn.d \
./src/TableColumnArrayContainer.d \
./src/TableColumnContainer.d \
./src/TableColumnDefinition.d \
./src/TableColumnDefinitionCreateParam.d \
./src/TableColumnValue.d \
./src/TableColumnValueTyped.d \
./src/TableDefinition.d \
./src/TableDefinitionCreateParam.d \
./src/UpdateStatement.d \
./src/WhereCondition.d \
./src/WhereConditionCompositeOperator.d \
./src/WhereConditionOperator.d \
./src/WhereConditionTableColumn.d \
./src/WhereConditionTableColumnContainer.d \
./src/WhereConditionTableColumnCreateParam.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -I/home/momo/deepnet/Database/src -I/home/momo/deepnet/Bot/src -I/home/momo/deepnet/Database/generated -I/home/momo/deepnet/Logging/src -I/home/momo/deepnet/Tools/src -I/home/momo/deepnet/Threading/src -I/usr/include/postgresql/ -O3 -g -Wall -c -fmessage-length=0 -pthread -rdynamic -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


