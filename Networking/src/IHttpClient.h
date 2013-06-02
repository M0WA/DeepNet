/**
 *
 * @file IHttpClient.h
 * @author Moritz Wagner
 * @date Jun 2, 2013
 *
 */

#pragma once

namespace network
{

class HttpUrl;
class HttpResponse;
class HttpClientSettings;

/**
 * @brief interface class for all http clients
 * To instantiate use network::HttpClientFactory only
 */
class IHttpClient
{
protected:
	IHttpClient() {}

public:
	virtual ~IHttpClient() {}

public:
	/**
	 * performs http get request
	 * @param url url to "GET"
	 * @param response response of http GET
	 * @return true if successful, false if unsuccessful
	 */
	virtual bool Get(const HttpUrl& url, HttpResponse& response) = 0;

	/**
	 * returns settings of this http client
	 * @return settings of this http client
	 */
	virtual HttpClientSettings& Settings() = 0;
};

}
