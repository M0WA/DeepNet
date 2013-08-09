/**
 *
 * @file UnitTestExceptions.h
 * @author Moritz Wagner
 * @date 09.08.2013
 *
 */

#pragma once

#include "UnitTest.h"

#include <Exception.h>

namespace toolbot {

class TestException : public errors::Exception {
public:
	TestException(
		const std::string& file,
		const int line,
		const std::string& function,
		const char* tmp);
};

class UnitTestExceptions: public toolbot::UnitTest {
public:
	UnitTestExceptions();
	virtual ~UnitTestExceptions();

public:
	virtual bool Run();
	virtual std::string GetName() const { return "UnitTestExceptions"; }

private:
	void ThrowException(const char* s) {
		THROW_EXCEPTION(TestException,s);
	}
};

}
