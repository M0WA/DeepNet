/**
 *
 * @file DOMException.cpp
 * @author Moritz Wagner
 * @date 21.06.2013
 *
 */

#include "DOMException.h"

#include <sstream>

namespace domparser {

namespace dom3 {

DOMException::DOMException(
		const std::string& file,
		const int line,
		const std::string& function,
		const std::string& errorName)
: errors::Exception(file,line,function,"DOMParser", "DOMException", "", true)
, error(ErrorNamesTable::GetEntryByName(errorName)) {

	std::ostringstream ssOut;
	if(error.IsValidEntry()) {
		ssOut <<
			"Name: " << error.name <<
			" Description: "<< error.description <<
			" ErrorCode: " << error.code; }
	else {
		ssOut <<
			"Name: invalid error" <<
			" ErrorCode: " << error.code; }
	message = ssOut.str();
}

DOMException::~DOMException() {
}

void DOMException::ThrowNamedException(const std::string& errorName) {
	THROW_EXCEPTION(DOMException,errorName);
}

}

}
