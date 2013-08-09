/**
 *
 * @file UnitTestExceptions.cpp
 * @author Moritz Wagner
 * @date 09.08.2013
 *
 */

#include "UnitTestExceptions.h"

#include <vector>

#include <Logging.h>
#include <StdException.h>

namespace toolbot {

TestException::TestException(
	const std::string& file,
	const int line,
	const std::string& function,
	const char* tmp)
: errors::Exception(file,line,function,"UnitTest","UnitTestExceptions","test message",true){
	log::Logging::LogTrace("test: %s",tmp);
}

UnitTestExceptions::UnitTestExceptions() {
}

UnitTestExceptions::~UnitTestExceptions() {
}

bool UnitTestExceptions::Run() {

	const char* tmp = "";

	bool success(false);
	try {
		try {
			ThrowException(tmp);
		}
		catch(errors::Exception& e) {
			e.DisableLogging();
			throw;
		}
	}
	catch(errors::Exception& e) {
		e.DisableLogging();
		success = true;
	}
	log::Logging::LogTrace("rethrow of an exception: %s", success ? "true" : "false");
	if(!success)
		return false;

	success = false;
	std::vector<int> tmpVec;
	int i = 0;
	try {
		try {
			i = (tmpVec.at(20));
			throw i;
		}
		catch(errors::StdException& stdEx){
			stdEx.DisableLogging();
			log::Logging::LogTrace("throw of a std::exception: success");
			throw;
		}
	}
	catch(errors::StdException& stdEx1) {
		stdEx1.DisableLogging();
		success = true;
	}
	log::Logging::LogTrace("rethrow of a std::exception: %s", success ? "true" : "false");

	return success;
}

}
