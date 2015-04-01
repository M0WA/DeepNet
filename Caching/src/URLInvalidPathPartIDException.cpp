/**
 *
 * @file URLInvalidPathPartIDException.cpp
 * @author Moritz Wagner
 * @date 06.08.2013
 *
 */

#include "URLInvalidPathPartIDException.h"

namespace caching {

URLInvalidPathPartIDException::URLInvalidPathPartIDException(
	const std::string& file,
	const int line,
	const std::string& function,
	const std::string& message)
: errors::Exception(file,line,function,"caching","URLInvalidPathPartIDException",message) {
}

URLInvalidPathPartIDException::~URLInvalidPathPartIDException() {
}

}
