################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../generated/content_lexer.yy.cpp \
../generated/content_parser.tab.cpp \
../generated/meta_lexer.yy.cpp \
../generated/meta_parser.tab.cpp 

OBJS += \
./generated/content_lexer.yy.o \
./generated/content_parser.tab.o \
./generated/meta_lexer.yy.o \
./generated/meta_parser.tab.o 

CPP_DEPS += \
./generated/content_lexer.yy.d \
./generated/content_parser.tab.d \
./generated/meta_lexer.yy.d \
./generated/meta_parser.tab.d 


# Each subdirectory must supply rules for building sources it contributes
generated/%.o: ../generated/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -I/usr/include/libxml2 -I../../Tools/src -I../../Networking/src -I../../Bot/src -I../../Caching/src -I../../HtmlParser/src -I../../Threading/src -I../../Logging/src -I../../Database/src -I../../Database/generated -O3 -fPIC -fomit-frame-pointer -g -Wall -c -fmessage-length=0 -pthread -rdynamic -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


