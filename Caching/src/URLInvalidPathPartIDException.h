/**
 *
 * @file URLInvalidPathPartIDException.h
 * @author Moritz Wagner
 * @date 06.08.2013
 *
 */

#pragma once

#include <string>

#include <Exception.h>

namespace caching {

class URLInvalidPathPartIDException : public errors::Exception {
public:
	URLInvalidPathPartIDException(
		const std::string& file,
		const int line,
		const std::string& function,
		const std::string& message);
	virtual ~URLInvalidPathPartIDException();
};

}
