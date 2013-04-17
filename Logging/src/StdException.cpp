/*
 * StdException.cpp
 *
 *  Created on: 17.08.2012
 *      Author: Moritz Wagner
 */

#include "StdException.h"
#include "DebuggingTools.h"

namespace errors {

StdException::StdException(
		const std::string& file,
		const int line,
		const std::string& function,
		const std::exception& ex,
		const std::string& backtrace,
		const bool logException)
: Exception(file,line,function,"unknown","std::exception",ex.what(),backtrace,logException) {
}

StdException::StdException(
		const std::string& file,
		const int line,
		const std::string& function,
		const std::exception& ex,
		const bool logException)
: Exception(file,line,function,"unknown","std::exception",ex.what(),tools::DebuggingTools::GetBacktrace(),logException) {
}

StdException::~StdException() {
}

}
