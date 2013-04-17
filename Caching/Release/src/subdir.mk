################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Cache.cpp \
../src/CacheDatabaseUrl.cpp \
../src/CacheHtml.cpp \
../src/CacheHtmlEntry.cpp \
../src/CacheParsed.cpp \
../src/CacheRobotsEntry.cpp \
../src/CacheRobotsTxt.cpp \
../src/CacheSecondLevelDomain.cpp \
../src/CacheSubdomain.cpp \
../src/RobotTxt.cpp \
../src/URLEmptyDomainException.cpp \
../src/URLInvalidMD5ValueException.cpp \
../src/URLInvalidSchemeException.cpp \
../src/URLInvalidSchemeIDException.cpp \
../src/URLInvalidSecondLevelDomainIDException.cpp \
../src/URLInvalidSubdomainIDException.cpp \
../src/URLInvalidTopLevelDomainIDException.cpp \
../src/URLInvalidUrlIDException.cpp \
../src/URLStoreException.cpp 

OBJS += \
./src/Cache.o \
./src/CacheDatabaseUrl.o \
./src/CacheHtml.o \
./src/CacheHtmlEntry.o \
./src/CacheParsed.o \
./src/CacheRobotsEntry.o \
./src/CacheRobotsTxt.o \
./src/CacheSecondLevelDomain.o \
./src/CacheSubdomain.o \
./src/RobotTxt.o \
./src/URLEmptyDomainException.o \
./src/URLInvalidMD5ValueException.o \
./src/URLInvalidSchemeException.o \
./src/URLInvalidSchemeIDException.o \
./src/URLInvalidSecondLevelDomainIDException.o \
./src/URLInvalidSubdomainIDException.o \
./src/URLInvalidTopLevelDomainIDException.o \
./src/URLInvalidUrlIDException.o \
./src/URLStoreException.o 

CPP_DEPS += \
./src/Cache.d \
./src/CacheDatabaseUrl.d \
./src/CacheHtml.d \
./src/CacheHtmlEntry.d \
./src/CacheParsed.d \
./src/CacheRobotsEntry.d \
./src/CacheRobotsTxt.d \
./src/CacheSecondLevelDomain.d \
./src/CacheSubdomain.d \
./src/RobotTxt.d \
./src/URLEmptyDomainException.d \
./src/URLInvalidMD5ValueException.d \
./src/URLInvalidSchemeException.d \
./src/URLInvalidSchemeIDException.d \
./src/URLInvalidSecondLevelDomainIDException.d \
./src/URLInvalidSubdomainIDException.d \
./src/URLInvalidTopLevelDomainIDException.d \
./src/URLInvalidUrlIDException.d \
./src/URLStoreException.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -I/usr/include/libxml2 -I../../Networking/src -I../../Logging/src -I../../Database/src -I../../Database/generated -I../../Bot/src -I../../Threading/src -I../../HtmlParser/src -O0 -g -Wall -c -fmessage-length=0 -pthread -rdynamic -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


