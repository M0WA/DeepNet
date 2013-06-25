/**
 *
 * @file DOMException.h
 * @author Moritz Wagner
 * @date 21.06.2013
 *
 */

#pragma once

#include <Exception.h>

#include "ErrorNamesTable.h"

namespace domparser {

namespace dom3 {

class DOMException : public errors::Exception {
public:
	DOMException(
			const std::string& file,
			const int line,
			const std::string& function,
			const ErrorNamesTable::DOMErrorCode& code);
	virtual ~DOMException();

public:
	static void ThrowNamedException(const std::string& errorName);

public:
	const ErrorNamesTable::DOMErrorCode& code() const { return errorCode; }

private:
	ErrorNamesTable::DOMErrorCode errorCode;
};

}

}
