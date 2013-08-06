/**
 *
 * @file URLInvalidUrlSearchPartIDException.cpp
 * @author Moritz Wagner
 * @date 06.08.2013
 *
 */

#include "URLInvalidUrlSearchPartIDException.h"

namespace caching {

URLInvalidUrlSearchPartIDException::URLInvalidUrlSearchPartIDException(
	const std::string& file,
	const int line,
	const std::string& function,
	const std::string& message)
: errors::Exception(file,line,function,"caching","URLInvalidUrlSearchPartIDException",message) {
}

URLInvalidUrlSearchPartIDException::~URLInvalidUrlSearchPartIDException() {
}

}
