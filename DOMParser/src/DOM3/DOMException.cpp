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
		const ExceptionCode& code)
: errors::Exception(file,line,function,"DOMParser", "DOMException", "", true)
, exceptionCode(code){
	std::ostringstream ssOut;
	ssOut << "DOMException Code: " << exceptionCode;
	message = ssOut.str();
}

DOMException::~DOMException() {
}

}

}
