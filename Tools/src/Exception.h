/**
 * @file Exception.h
 * @author Moritz Wagner
 * @date 10.08.2012
 */

#pragma once

#include <string>

#define THROW_EXCEPTION(className,args...) \
	throw className(__FILE__,__LINE__,__PRETTY_FUNCTION__, ##args);

#define CATCH_EXCEPTION(className,exceptionName,enableLogging) \
	catch(className& exceptionName) { \
		if( enableLogging ) { \
		  exceptionName.Log(); }

namespace errors {

/**
 * @brief generic wrapper class for exceptions.
 */
class Exception {
public:
	/**
	 * creates an exception. use THROW_EXCEPTION macro to throw an exception.
	 * @param file originating filename.
	 * @param line originating sourceline.
	 * @param function originating function.
	 * @param module originating module.
	 * @param exceptionName exception name
	 * @param message exception message
	 * @param logException true if exception shall be logged.
	 */
	Exception(
			const std::string& file,
			const int line,
			const std::string& function,
			const std::string& module,
			const std::string& exceptionName,
			const std::string& message,
			const bool logException = true);

	/**
	 * creates an exception. use THROW_EXCEPTION macro to throw an exception.
	 * @param file originating filename.
	 * @param line originating sourceline.
	 * @param function originating function.
	 * @param module originating module.
	 * @param exceptionName exception name
	 * @param message exception message
	 * @param backtrace backstrace.
	 * @param logException true if exception shall be logged.
	 */
	Exception(
			const std::string& file,
			const int line,
			const std::string& function,
			const std::string& module,
			const std::string& exceptionName,
			const std::string& message,
			const std::string& backtrace,
			const bool logException = true);

	virtual ~Exception();

public:
	/**
	 * initializes exception handling for current process.
	 */
	static void InitializeExceptionHandling();

public:
	/**
	 * log this exception.
	 */
	void Log() const;

	/**
	 * dumps exception as string.
	 * @return exception as string.
	 */
	std::string Dump() const;

protected:
	/**
	 * originating filename
	 */
	std::string file;

	/**
	 * originating source line.
	 */
	int line;

	/**
	 * originating function.
	 */
	std::string function;

	/**
	 * originating module.
	 */
	std::string module;

	/**
	 * name of the exception.
	 */
	std::string exceptionName;

	/**
	 * exception message.
	 */
	std::string message;

	/**
	 * backtrace.
	 */
	std::string backtrace;

	/**
	 * log this exception.
	 */
	bool logException;

private:
	volatile static bool tryRethrow;
	static void TerminateHandler();
};

}
