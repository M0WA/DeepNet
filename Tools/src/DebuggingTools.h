/**
 * @file DebuggingTools.h
 * @author Moritz Wagner
 * @date 08.11.2012
 */

#pragma once

#include <string>
#include <ucontext.h>

namespace tools {

/**
 * @brief wrapper class for debugging functionality.
 */
class DebuggingTools {

public:
	/**
	 * @struct SignalInfos
	 * @brief container for signal related information.
	 */
	struct SignalInfos {

		/**
		 * extensive information on signal.
		 */
		std::string infoText;

		/**
		 * signal originating call.
		 */
		void* caller;
	};

private:
	DebuggingTools();
public:
	virtual ~DebuggingTools();

private:
	struct sig_ucontext_t {
		unsigned long     uc_flags;
		struct ucontext   *uc_link;
		stack_t           uc_stack;
		struct sigcontext uc_mcontext;
		sigset_t          uc_sigmask;
	};

public:
	/**
	 * parses raw signal information.
	 * @param sig_num signal number.
	 * @param info signal infos.
	 * @param ucontext context
	 * @return parsed signal infos.
	 */
	static SignalInfos GetSignalInfos(int sig_num, siginfo_t* info, void* ucontext);

	/**
	 * creates a backtrace.
	 * @param caller originating address.
	 * @return backtrace
	 */
	static std::string GetBacktrace(void* caller = NULL);

	/**
	 * raises a debug trap.
	 * @param preferBuiltinTrapToSigTrap true to prefer gcc builtin trap.
	 */
	static void DebugBreak(bool preferBuiltinTrapToSigTrap = true);

	/**
	 * dumps current thread information to a string.
	 * @param out current thread information.
	 */
	static void DumpThreadContext(std::string& out);

	/**
	 * demangles a function name.
	 * @param pszMangledFunctionName mangled name.
	 * @param demangledFunctionName demangled name.
	 * @return false on error, true on success.
	 */
	static bool DemangleFunctionName(const char* pszMangledFunctionName, std::string& demangledFunctionName);

	/**
	 * resolves an address to a source file and line.
	 * @param pszModuleName module name.
	 * @param addr address of code.
	 * @param file gets filled with filename.
	 * @param line gets filled with lineno.
	 * @return false on error, true on success.
	 */
	static bool GetFileLineFromModuleAddress(const char* pszModuleName, const void* addr, std::string& file, size_t& line);
};

}

