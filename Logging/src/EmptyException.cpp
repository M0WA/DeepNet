/**
 *
 * @file EmptyException.cpp
 * @author Moritz Wagner
 * @date 20.11.2012
 *
 */

#include "EmptyException.h"

namespace errors {

EmptyException::EmptyException(
		const std::string& file,
		const int line,
		const std::string& function)
: Exception(file,line,function,"Exception","EmptyException","an empty exception has been caught"){
}

EmptyException::~EmptyException() {
}

}
