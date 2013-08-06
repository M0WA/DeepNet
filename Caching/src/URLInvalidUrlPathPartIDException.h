/**
 *
 * @file URLInvalidUrlPathPartIDException.h
 * @author Moritz Wagner
 * @date 06.08.2013
 *
 */

#pragma once

#include <Exception.h>

namespace caching {

class URLInvalidUrlPathPartIDException: public errors::Exception {
public:
	URLInvalidUrlPathPartIDException(
		const std::string& file,
		const int line,
		const std::string& function,
		const std::string& message);
	virtual ~URLInvalidUrlPathPartIDException();
};

}
