/**
 *
 * @file HttpUrlParserTLDCacheException.h
 * @author Moritz Wagner
 * @date Apr 17, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include "HttpUrlParserException.h"

namespace network {

class HttpUrlParserTLDCacheException : public network::HttpUrlParserException {
public:
	HttpUrlParserTLDCacheException(
			const std::string& file,
			const int line,
			const std::string& function);
	virtual ~HttpUrlParserTLDCacheException();
};

}
