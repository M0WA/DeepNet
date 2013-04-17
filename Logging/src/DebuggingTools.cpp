/**
 * @file DebuggingTools.cpp
 * @author Moritz Wagner
 * @date 08.11.2012
 */

#include "DebuggingTools.h"

 #ifndef _GNU_SOURCE
	#define _GNU_SOURCE
#endif

#ifndef __USE_GNU
	#define __USE_GNU
#endif

#include <execinfo.h>
#include <cxxabi.h>
#include <csignal>
#include <sys/syscall.h>
#include <ucontext.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sstream>
#include <iomanip>

#include "StringTools.h"

namespace tools {

DebuggingTools::DebuggingTools() {
}

DebuggingTools::~DebuggingTools() {
}

DebuggingTools::SignalInfos DebuggingTools::GetSignalInfos(int sig_num, siginfo_t * info, void * ucontext)
{
	sig_ucontext_t* uc = (sig_ucontext_t *)ucontext;
	SignalInfos sigInfo;

	if(uc) {
#if __WORDSIZE == 32
	sigInfo.caller = (void *)uc->uc_mcontext.eip;
#elif __WORDSIZE == 64
	sigInfo.caller = (void *)uc->uc_mcontext.rip;
#else
	sigInfo.caller = 0;
#endif
	}

	std::ostringstream ssInfoText;
	ssInfoText << "caught signal " << sig_num  << ": " << strsignal(sig_num) << std::endl;
	ssInfoText << "backtrace:" << std::endl;
	ssInfoText << GetBacktrace(sigInfo.caller);

	sigInfo.infoText = ssInfoText.str();
	return sigInfo;
}

std::string DebuggingTools::GetBacktrace(void* caller)
{
	std::ostringstream ssBacktrace;

	unsigned int max_frames = 63;
	void* addrlist[max_frames+1];
	int addrlen = backtrace(addrlist, sizeof(addrlist) / sizeof(void*));
	if (!addrlen) {
		return "could not generate backtrace: no stack-frames found\n\n";}

	//search for calling function in backtrace
	//if not found, start at beginning
	int nStartOffset = 0;
	if(caller){
		for(int i = 0;i < addrlen; i++){
			if(addrlist[i] == caller){
				nStartOffset = i;
				break;}
		}
	}

	char** symbollist = backtrace_symbols(addrlist, addrlen);
	for(int i = nStartOffset;i < (addrlen-1); i++)
	{
		// find parentheses and +address offset surrounding the mangled name:
		// ./module(function+0x15c) [0x8048a6d]
		std::string cur_symbol(symbollist[i]);
		size_t posBegin = cur_symbol.find('(');
		size_t posEnd   = cur_symbol.find(')',posBegin);

		if( posBegin       == std::string::npos ||
			(posBegin + 1) > cur_symbol.size()  ||
			posEnd         == std::string::npos ||
			(posEnd-1)     <= (posBegin + 1)
		){
			//error while parsing symbol...
			ssBacktrace << cur_symbol << std::endl;
			continue;}

		size_t posPlus = cur_symbol.find('+',posBegin);
		if(posPlus != std::string::npos){
			posEnd = posPlus;}

		std::string sMangledFunctionName = cur_symbol.substr(posBegin+1, posEnd-1-posBegin);
		std::string sModuleName = cur_symbol.substr(0,posBegin);

		std::string demangledFunctionName;
		DemangleFunctionName(sMangledFunctionName.c_str(),demangledFunctionName);
		if(!demangledFunctionName.empty()) {
			ssBacktrace << " in function " << demangledFunctionName;
		}
		else {
			ssBacktrace << " at address " << addrlist[i];
		}

		std::string file; size_t line = 0;
		bool isFileResolved = GetFileLineFromModuleAddress(sModuleName.c_str(), addrlist[i], file, line);
		if(isFileResolved && file.compare("??") != 0) {
			ssBacktrace << " at " << file << ":" << line;
		}
		ssBacktrace << " [" << sModuleName << "]";

		ssBacktrace << std::endl;
	}

	free(symbollist);
	return ssBacktrace.str();
}

bool DebuggingTools::DemangleFunctionName(const char* pszMangledFunctionName, std::string& demangledFunctionName) {

	int status;
	char* pszDemangledFunctionName = NULL;
	pszDemangledFunctionName = abi::__cxa_demangle(pszMangledFunctionName, pszDemangledFunctionName, NULL, &status);

	bool success = false;
	if(status == 0 && pszDemangledFunctionName) {
		demangledFunctionName = pszDemangledFunctionName;
		success = true;
	}
	else {
		demangledFunctionName = pszMangledFunctionName;
	}

	if(pszDemangledFunctionName!=NULL)
		free(pszDemangledFunctionName);

	return success;
}

bool DebuggingTools::GetFileLineFromModuleAddress(const char* pszModuleName, const void* addr, std::string& file, size_t& line) {

	std::ostringstream addr2LineCmd;
	addr2LineCmd << "/usr/bin/addr2line -C " << " -e \"" << pszModuleName << "\" \"" << addr << "\"";
	std::string addr2LineOutput;
	if(!StringTools::ExecuteCommand(addr2LineCmd.str(), addr2LineOutput, 0)) {
		return false; }

	StringTools::Trim(addr2LineOutput);
	std::vector<std::string> fileLine;
	StringTools::SplitBy(addr2LineOutput,":",fileLine);
	if(fileLine.size() != 2) {
		return false; }

	file = fileLine.at(0);
	StringTools::TransformString(fileLine.at(1), line);
	return true;
}

void DebuggingTools::DebugBreak(bool preferBuiltinTrapToSigTrap) {

#if defined(__i386__) || defined(__x86_64__)

	__asm__ volatile("int $0x03");
/* untested, thumb mode can change at runtime?
#elif defined(__thumb__)

	__asm__ volatile(".inst\t0xdeff");

#elif defined(__arm__) && !defined(__thumb__)

	__asm__ volatile(".inst\t0xe7ffffff");
*/
#else

	if (preferBuiltinTrapToSigTrap) {
		// to continue in gdb: (gdb) handle SIGILL stop nopass
		__builtin_trap();
	} else {
		raise(SIGTRAP);
	}

#endif
}

void DebuggingTools::DumpThreadContext(std::string& out) {

	ucontext_t ucp;
	if(getcontext(&ucp) != 0)
		return;

	std::stringstream ssThreadContext;
	ucontext_t* currentFrame = &ucp;
	int nFrameNo = 0;
	while(currentFrame) {

#if __WORDSIZE == 32
		size_t hexSize = 4;
		greg_t sp = currentFrame->uc_mcontext.gregs[REG_ESP];
		greg_t bp = currentFrame->uc_mcontext.gregs[REG_EBP];
		greg_t ip = currentFrame->uc_mcontext.gregs[REG_EIP];
#elif __WORDSIZE == 64
		size_t hexSize = 8;
		greg_t sp = currentFrame->uc_mcontext.gregs[REG_RSP];
		greg_t bp = currentFrame->uc_mcontext.gregs[REG_RBP];
		greg_t ip = currentFrame->uc_mcontext.gregs[REG_RIP];
#endif

		ssThreadContext << "[" << nFrameNo << "] IP: 0x" << std::setw(hexSize) << std::hex << ip << " BP: 0x" << std::setw(hexSize) << std::hex << bp << " SP: 0x" << std::setw(hexSize) << std::hex << sp << std::endl;

		currentFrame = currentFrame->uc_link;
		nFrameNo++;
	}

	out = ssThreadContext.str();
}

}
