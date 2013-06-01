################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CommerceSearchCrawler.cpp \
../src/CommerceSearchFetcherThread.cpp \
../src/Crawler.cpp \
../src/DataminingCrawler.cpp \
../src/DataminingUrlFetcherThread.cpp \
../src/GenericWebCrawler.cpp \
../src/GenericWebUrlFetcherThread.cpp \
../src/UrlFetchParam.cpp \
../src/UrlFetcherThread.cpp 

OBJS += \
./src/CommerceSearchCrawler.o \
./src/CommerceSearchFetcherThread.o \
./src/Crawler.o \
./src/DataminingCrawler.o \
./src/DataminingUrlFetcherThread.o \
./src/GenericWebCrawler.o \
./src/GenericWebUrlFetcherThread.o \
./src/UrlFetchParam.o \
./src/UrlFetcherThread.o 

CPP_DEPS += \
./src/CommerceSearchCrawler.d \
./src/CommerceSearchFetcherThread.d \
./src/Crawler.d \
./src/DataminingCrawler.d \
./src/DataminingUrlFetcherThread.d \
./src/GenericWebCrawler.d \
./src/GenericWebUrlFetcherThread.d \
./src/UrlFetchParam.d \
./src/UrlFetcherThread.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -I/usr/include/libxml2 -I../../Tools/src -I../../Networking/src -I../../Logging/src -I../../Caching/src -I../../Bot/src -I../../Threading/src -I../../HtmlParser/src -I../../Database/src -I../../Database/generated -O3 -g -Wall -c -fmessage-length=0 -pthread -rdynamic -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


