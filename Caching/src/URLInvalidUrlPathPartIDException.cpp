/**
 *
 * @file URLInvalidUrlPathPartIDException.cpp
 * @author Moritz Wagner
 * @date 06.08.2013
 *
 */

#include "URLInvalidUrlPathPartIDException.h"

namespace caching {

URLInvalidUrlPathPartIDException::URLInvalidUrlPathPartIDException(
	const std::string& file,
	const int line,
	const std::string& function,
	const std::string& message)
: errors::Exception(file,line,function,"caching","URLInvalidPathPartIDException",message){
}

URLInvalidUrlPathPartIDException::~URLInvalidUrlPathPartIDException() {
}

}
