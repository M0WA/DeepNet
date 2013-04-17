/*
 * HttpPostRequest.cpp
 *
 *  Created on: Dec 21, 2012
 *      Author: Moritz Wagner
 */

#include "HttpPostRequest.h"

#include <StringTools.h>

namespace network {

HttpPostRequest::HttpPostRequest(const HttpUrl& url)
: HttpRequest(HttpRequest::POST, url){
}

HttpPostRequest::~HttpPostRequest() {
}

void HttpPostRequest::ToString(std::string& out) const {

	std::string defaultHeaderPart;
	HttpRequest::ToString(defaultHeaderPart);

	tools::StringTools::FormatString(out,
		"POST %s HTTP/1.1\r\n"
		"%s"
		"\r\n",
		url.GetFullPathSearch().c_str(),
		defaultHeaderPart.c_str()
	);
}

}
