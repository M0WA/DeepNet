/**
 *
 * @file HttpUrlParserTLDCacheException.cpp
 * @author Moritz Wagner
 * @date Apr 17, 2013
 *
 * TODO: description for this file
 *
 */

#include "HttpUrlParserTLDCacheException.h"

namespace network {

HttpUrlParserTLDCacheException::HttpUrlParserTLDCacheException(
		const std::string& file,
		const int line,
		const std::string& function)
: HttpUrlParserException(file,line,function,"HttpUrlParserTLDCacheException","TLD cache has not been initialized for url parser"){
}

HttpUrlParserTLDCacheException::~HttpUrlParserTLDCacheException() {
}

}
