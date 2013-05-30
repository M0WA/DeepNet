/**
 *
 * @file HttpResponse.h
 * @author Moritz Wagner
 * @date May 15, 2013
 *
 */

#pragma once

#include <string>
#include <vector>

#include "HtmlData.h"
#include "HttpCookie.h"

namespace network {

class HttpResponse {
public:
	HttpResponse();
	virtual ~HttpResponse();

public:
	HtmlData html;
	std::vector<HttpCookie> cookies;
	std::vector<std::string> redirectUrls;

public:
	long httpResponseCode;
	double contentLength;

	long fileTimestamp;
	double downloadSpeed;
	double uploadSpeed;
	double totalTime;
	double dnsLookupTime;
	double connectTime;

	std::string primaryIP;
	long primaryPort;
};

}
