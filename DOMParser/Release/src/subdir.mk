################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Attr.cpp \
../src/CharacterData.cpp \
../src/Comment.cpp \
../src/DOMImplementation.cpp \
../src/DOMParser.cpp \
../src/DOMParserResult.cpp \
../src/DOMSettableTokenList.cpp \
../src/DOMTokenList.cpp \
../src/Document.cpp \
../src/DocumentFactory.cpp \
../src/DocumentFragment.cpp \
../src/DocumentType.cpp \
../src/Element.cpp \
../src/ElementFactory.cpp \
../src/Event.cpp \
../src/EventTarget.cpp \
../src/HTMLCollection.cpp \
../src/HTMLElement.cpp \
../src/ListImpl.cpp \
../src/MutationObserver.cpp \
../src/MutationRecord.cpp \
../src/NamedCharacterReferences.cpp \
../src/Node.cpp \
../src/NodeFactory.cpp \
../src/NodeFilter.cpp \
../src/NodeIterator.cpp \
../src/NodeList.cpp \
../src/ProcessingInstruction.cpp \
../src/Range.cpp \
../src/Text.cpp \
../src/Token.cpp \
../src/Tokeniser.cpp \
../src/Traverser.cpp \
../src/TreeWalker.cpp 

OBJS += \
./src/Attr.o \
./src/CharacterData.o \
./src/Comment.o \
./src/DOMImplementation.o \
./src/DOMParser.o \
./src/DOMParserResult.o \
./src/DOMSettableTokenList.o \
./src/DOMTokenList.o \
./src/Document.o \
./src/DocumentFactory.o \
./src/DocumentFragment.o \
./src/DocumentType.o \
./src/Element.o \
./src/ElementFactory.o \
./src/Event.o \
./src/EventTarget.o \
./src/HTMLCollection.o \
./src/HTMLElement.o \
./src/ListImpl.o \
./src/MutationObserver.o \
./src/MutationRecord.o \
./src/NamedCharacterReferences.o \
./src/Node.o \
./src/NodeFactory.o \
./src/NodeFilter.o \
./src/NodeIterator.o \
./src/NodeList.o \
./src/ProcessingInstruction.o \
./src/Range.o \
./src/Text.o \
./src/Token.o \
./src/Tokeniser.o \
./src/Traverser.o \
./src/TreeWalker.o 

CPP_DEPS += \
./src/Attr.d \
./src/CharacterData.d \
./src/Comment.d \
./src/DOMImplementation.d \
./src/DOMParser.d \
./src/DOMParserResult.d \
./src/DOMSettableTokenList.d \
./src/DOMTokenList.d \
./src/Document.d \
./src/DocumentFactory.d \
./src/DocumentFragment.d \
./src/DocumentType.d \
./src/Element.d \
./src/ElementFactory.d \
./src/Event.d \
./src/EventTarget.d \
./src/HTMLCollection.d \
./src/HTMLElement.d \
./src/ListImpl.d \
./src/MutationObserver.d \
./src/MutationRecord.d \
./src/NamedCharacterReferences.d \
./src/Node.d \
./src/NodeFactory.d \
./src/NodeFilter.d \
./src/NodeIterator.d \
./src/NodeList.d \
./src/ProcessingInstruction.d \
./src/Range.d \
./src/Text.d \
./src/Token.d \
./src/Tokeniser.d \
./src/Traverser.d \
./src/TreeWalker.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_REENTRANT -DENABLE_PERFORMANCE_LOG -I../../Tools/src -I../../Database/src -I../../Database/generated -I../../Threading/src -I../../Networking/src -I../../HtmlParser/src -I../../Logging/src -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


