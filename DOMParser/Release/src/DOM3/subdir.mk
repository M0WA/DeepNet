################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/DOM3/DOMException.cpp \
../src/DOM3/DOMImplementation.cpp \
../src/DOM3/DOMImplementationImpl.cpp \
../src/DOM3/DOMImplementationList.cpp \
../src/DOM3/DOMImplementationSource.cpp \
../src/DOM3/DOMObject.cpp \
../src/DOM3/DOMString.cpp \
../src/DOM3/DOMStringList.cpp \
../src/DOM3/Document.cpp \
../src/DOM3/DocumentFragment.cpp \
../src/DOM3/DocumentType.cpp \
../src/DOM3/NameList.cpp \
../src/DOM3/Node.cpp 

OBJS += \
./src/DOM3/DOMException.o \
./src/DOM3/DOMImplementation.o \
./src/DOM3/DOMImplementationImpl.o \
./src/DOM3/DOMImplementationList.o \
./src/DOM3/DOMImplementationSource.o \
./src/DOM3/DOMObject.o \
./src/DOM3/DOMString.o \
./src/DOM3/DOMStringList.o \
./src/DOM3/Document.o \
./src/DOM3/DocumentFragment.o \
./src/DOM3/DocumentType.o \
./src/DOM3/NameList.o \
./src/DOM3/Node.o 

CPP_DEPS += \
./src/DOM3/DOMException.d \
./src/DOM3/DOMImplementation.d \
./src/DOM3/DOMImplementationImpl.d \
./src/DOM3/DOMImplementationList.d \
./src/DOM3/DOMImplementationSource.d \
./src/DOM3/DOMObject.d \
./src/DOM3/DOMString.d \
./src/DOM3/DOMStringList.d \
./src/DOM3/Document.d \
./src/DOM3/DocumentFragment.d \
./src/DOM3/DocumentType.d \
./src/DOM3/NameList.d \
./src/DOM3/Node.d 


# Each subdirectory must supply rules for building sources it contributes
src/DOM3/%.o: ../src/DOM3/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -DENABLE_PERFORMANCE_LOG -I../../Tools/src -I../../Caching/src -I../../Database/src -I../../Database/generated -I../../Threading/src -I../../Networking/src -I../../HtmlParser/src -I../../Logging/src -O3 -fPIC -fomit-frame-pointer -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


