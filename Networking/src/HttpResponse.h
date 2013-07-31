/**
 *
 * @file HttpResponse.h
 * @author Moritz Wagner
 * @date 15.05.2013
 *
 */

#pragma once

#include <string>
#include <vector>

#include "HtmlData.h"
#include "HttpCookie.h"

namespace network {

/**
 * @brief response for a HTTP-Request
 * @see network::IHttpClient
 */
class HttpResponse {
public:
	HttpResponse();
	virtual ~HttpResponse();

public:
	/**
	 * container for html content
	 */
	HtmlData html;

	/**
	 * cookies
	 */
	std::vector<HttpCookie> cookies;

	/**
	 * redirected to urls
	 */
	std::vector<std::string> redirectUrls;

public:
	/**
	 * HTTP status code
	 */
	long httpResponseCode;

	/**
	 * content length
	 */
	double contentLength;

	/**
	 * timestamp
	 */
	long fileTimestamp;

	/**
	 * download speed
	 */
	double downloadSpeed;

	/**
	 * upload speed
	 */
	double uploadSpeed;

	/**
	 * total time used (in seconds)
	 */
	double totalTime;

	/**
	 * time used for DNS lookup (in seconds)
	 */
	double dnsLookupTime;

	/**
	 * time used for connect() (in seconds)
	 */
	double connectTime;

	/**
	 * ip of http server
	 */
	std::string primaryIP;

	/**
	 * port of http server
	 */
	long primaryPort;
};

}
