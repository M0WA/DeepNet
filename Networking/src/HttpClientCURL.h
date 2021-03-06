/**
 *
 * @file HttpClientCURL.h
 * @author Moritz Wagner
 * @date 15.05.2013
 *
 */

#pragma once

#include "IHttpClient.h"
#include "HttpClientSettings.h"

namespace network {

class HttpClientFactory;

/**
 * @brief implementation of network::IHttpClient for libCURL based http client
 * @see network::HttpClientFactory
 */
class HttpClientCURL: public network::IHttpClient {

	friend class network::HttpClientFactory;

private:
	typedef struct _CURLWriterParam{
	public:
		_CURLWriterParam(const HttpUrl& url, HttpResponse& response, const size_t& maxSize)
		: url(url), response(response), maxSize(maxSize), omitRest(false)
		{}

	public:
		const HttpUrl& url;
		HttpResponse& response;
		size_t maxSize;
		bool omitRest;
	} CURLWriterParam;

private:
	HttpClientCURL();
public:
	virtual ~HttpClientCURL();

public:
	virtual bool Get(const HttpUrl& url, HttpResponse& response);
	virtual bool Post(const HttpUrl& url, const std::string& content, const std::string& contentType, HttpResponse& response);
	virtual HttpClientSettings& Settings() { return settings; }

private:
	bool DoRequest(const HttpUrl& url, HttpResponse& response);

private:
	static int WriterCallback(char *data, size_t size, size_t nmemb, CURLWriterParam* param);

private:
	HttpClientSettings settings;
	void* curlPtr;
	char* errorBuffer;
};

}
