/**
 * @file Exception.h
 * @author Moritz Wagner
 * @date 10.08.2012
 */

#include "Exception.h"

#include <sstream>
#include <stdexcept>

#include "Logging.h"

#include "EmptyException.h"
#include "StdException.h"
#include "DebuggingTools.h"

volatile bool errors::Exception::tryRethrow = true;

namespace errors {

Exception::Exception(
		const std::string& file,
		const int line,
		const std::string& function,
		const std::string& module,
		const std::string& exceptionName,
		const std::string& message,
		const bool logException)
: file(file)
, line(line)
, function(function)
, module(module)
, exceptionName(exceptionName)
, message(message)
, backtrace(tools::DebuggingTools::GetBacktrace())
, logException(logException){
}

Exception::Exception(
		const std::string& file,
		const int line,
		const std::string& function,
		const std::string& module,
		const std::string& exceptionName,
		const std::string& message,
		const std::string& backtrace,
		const bool logException)
: file(file)
, line(line)
, function(function)
, module(module)
, exceptionName(exceptionName)
, message(message)
, backtrace(backtrace)
, logException(logException){
	tryRethrow = true;
}

Exception::~Exception() {
	if(logException)
		Log();
}

void Exception::Log() const {

	log::Logging::LogUnlimited(log::Logging::LOGLEVEL_ERROR,Dump());
}

void Exception::DisableLogging() {
	logException = false;
}

std::string Exception::Dump() const {

	std::string now;
	log::Logging::GetTimeString(now);

	std::ostringstream ssExcection;
	ssExcection << "an exception has occurred"  << std::endl <<
		"time     : " << now           << std::endl <<
		"exception: " << exceptionName << std::endl <<
		"message  : " << message       << std::endl <<
		"module   : " << module        << std::endl <<
		"function : " << function      << std::endl <<
		"file     : " << file          << std::endl <<
		"line     : " << line          << std::endl <<
		"backtrace: " << std::endl << backtrace;

	return ssExcection.str();
}

void Exception::InitializeExceptionHandling() {

	std::set_terminate(Exception::TerminateHandler);
	//std::set_unexpected(Exception::TerminateHandler);
}

void Exception::TerminateHandler() {

	std::string backtrace = tools::DebuggingTools::GetBacktrace();
	if(tryRethrow) {
		try {
			tryRethrow = false;
			throw;
		}
		catch(std::exception& ex){
			THROW_EXCEPTION(errors::StdException,ex,backtrace);
		}
		catch(errors::Exception& ex) {
			throw ex;
		}
		/*
		catch(...) {
			THROW_EXCEPTION(errors::EmptyException);
		}
		*/
	}
	else {
		tryRethrow = true;
		THROW_EXCEPTION(errors::EmptyException);
	}
}

}
