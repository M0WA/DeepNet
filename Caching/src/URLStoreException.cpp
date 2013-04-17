/*
 * URLStoreException.cpp
 *
 *  Created on: 23.08.2012
 *      Author: Moritz Wagner
 */

#include "URLStoreException.h"

URLStoreException::URLStoreException(
	const std::string& file,
	const int line,
	const std::string& function,
	const std::string& url)
: errors::Exception( file,line,function,"caching","URLStoreException", "can not store url: " + url){
}

URLStoreException::~URLStoreException() {
}
