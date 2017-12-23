################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CommerceSearchCrawler.cpp \
../src/CommerceSearchFetcherThread.cpp \
../src/Crawler.cpp \
../src/CrawlerFactory.cpp \
../src/CrawlerParam.cpp \
../src/DataminingCrawler.cpp \
../src/DataminingUrlFetcherThread.cpp \
../src/FencedCrawler.cpp \
../src/FencedUrlFetcherThread.cpp \
../src/GenericWebCrawler.cpp \
../src/GenericWebUrlFetcherThread.cpp \
../src/GenericWebUrlFetcherThreadParam.cpp \
../src/UrlFetchParam.cpp \
../src/UrlFetcherThread.cpp \
../src/UrlFetcherThreadParam.cpp 

OBJS += \
./src/CommerceSearchCrawler.o \
./src/CommerceSearchFetcherThread.o \
./src/Crawler.o \
./src/CrawlerFactory.o \
./src/CrawlerParam.o \
./src/DataminingCrawler.o \
./src/DataminingUrlFetcherThread.o \
./src/FencedCrawler.o \
./src/FencedUrlFetcherThread.o \
./src/GenericWebCrawler.o \
./src/GenericWebUrlFetcherThread.o \
./src/GenericWebUrlFetcherThreadParam.o \
./src/UrlFetchParam.o \
./src/UrlFetcherThread.o \
./src/UrlFetcherThreadParam.o 

CPP_DEPS += \
./src/CommerceSearchCrawler.d \
./src/CommerceSearchFetcherThread.d \
./src/Crawler.d \
./src/CrawlerFactory.d \
./src/CrawlerParam.d \
./src/DataminingCrawler.d \
./src/DataminingUrlFetcherThread.d \
./src/FencedCrawler.d \
./src/FencedUrlFetcherThread.d \
./src/GenericWebCrawler.d \
./src/GenericWebUrlFetcherThread.d \
./src/GenericWebUrlFetcherThreadParam.d \
./src/UrlFetchParam.d \
./src/UrlFetcherThread.d \
./src/UrlFetcherThreadParam.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DENABLE_PERFORMANCE_LOG -DDEBUG_DEEPNET -D_REENTRANT -I/usr/include/libxml2 -I../../Syncing/src -I../../Tools/src -I../../Networking/src -I../../Logging/src -I../../Caching/src -I../../Bot/src -I../../Threading/src -I../../HtmlParser/src -I../../Database/src -I../../Database/generated -O0 -g3 -Wall -c -fmessage-length=0 -pthread -rdynamic -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


