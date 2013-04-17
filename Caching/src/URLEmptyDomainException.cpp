/*
 * URLEmptyDomainException.cpp
 *
 *  Created on: 19.11.2012
 *      Author: Moritz Wagner
 */

#include "URLEmptyDomainException.h"

#include <DatabaseUrl.h>

URLEmptyDomainException::URLEmptyDomainException(
		const std::string& file,
		const int line,
		const std::string& function,
		const htmlparser::DatabaseUrl& url)
: errors::Exception( file,line,function,"caching","URLEmptyDomainException","empty domain value in url: " + url.Dump() ) {

}

URLEmptyDomainException::~URLEmptyDomainException() {
}
