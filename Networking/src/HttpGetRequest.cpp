/*
 * HttpGetRequest.cpp
 *
 *  Created on: Dec 21, 2012
 *      Author: Moritz Wagner
 */

#include "HttpGetRequest.h"

#include <StringTools.h>

namespace network {

HttpGetRequest::HttpGetRequest(const HttpUrl& url)
: HttpRequest(HttpRequest::GET, url){
}

HttpGetRequest::~HttpGetRequest() {
}

void HttpGetRequest::ToString(std::string& out) const {

	std::string defaultHeaderPart;
	HttpRequest::ToString(defaultHeaderPart);

	tools::StringTools::FormatString(out,
		"GET %s HTTP/1.1\r\n"
		"%s"
		"\r\n",
		url.GetFullPathSearch().c_str(),
		defaultHeaderPart.c_str()
	);
}

}
