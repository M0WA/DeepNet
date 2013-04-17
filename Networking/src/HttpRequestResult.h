/*
 * HttpRequestResult.h
 *
 *  Created on: Feb 4, 2013
 *      Author: Moritz Wagner
 */

#pragma once

#include <ctime>
#include <string>
#include <netinet/in.h>

#include "HttpUrl.h"
#include "HttpHeader.h"
#include "HtmlData.h"

namespace network {
class HttpRequestResult {
public:
	HttpRequestResult();
	virtual ~HttpRequestResult();

	void ToString(std::string& in) const;

	timeval dnsTime;
	timeval connectTime;
	timeval readTime;
	timeval writeTime;

	bool success;

	HtmlData htmlData;

	HttpHeader effectiveHeader;
	HttpUrl    effectiveUrl;

	struct sockaddr_in effectiveHost;
	size_t redirectedCount;
	size_t writtenBytes;

	int httpStatusCode;
	struct tm lastModified;
};

}
