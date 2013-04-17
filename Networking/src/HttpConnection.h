/*
 * HttpConnection.h
 *
 *  Created on: 14.01.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>
#include <curl/curl.h>

#include "HtmlData.h"

namespace htmlparser {
	class DatabaseUrl;
}

namespace network
{

class HttpConnection
{
public:
	struct HttpConnectionParam
	{
		HttpConnectionParam()
		: url()
		, userAgent()
		, secondsTimeoutConnect(-1)
		, secondsTimeoutConnection(-1)
		, allowIPv6(false)
		, uploadLimitKB(-1)
		, downloadLimitKB(-1)
		{ }

		std::string url;
		std::string userAgent;
		int secondsTimeoutConnect;
		int secondsTimeoutConnection;
		bool allowIPv6;
		int uploadLimitKB;
		int downloadLimitKB;
	};

	struct HttpConnectionResult
	{
		HttpConnectionResult()
		: fileTimestamp(-1)
		, redirectCount(-1)
		, downloadSpeed(-1)
		, uploadSpeed(-1)
		, totalTime(-1)
		, contentLength(-1)
		, contentType()
		, primaryIP()
		, primaryPort(80)
		, httpResponseCode(-1)
		, charsetHint()
		, validHint(false)
		, encodingName()
		, encodingConfidence(0)
		, htmlCode()
		{}

		//std::string lastEffectiveUrl;
		std::string redirectUrl;
		long fileTimestamp;
		long redirectCount;
		double downloadSpeed;
		double uploadSpeed;
		double totalTime;
		//double dnsLookupTime;
		//double connectTime;
		double contentLength;
		std::string contentType;
		std::string primaryIP;
		long primaryPort;
		long httpResponseCode;

		std::string charsetHint;
		bool validHint;
		std::string encodingName;
		int encodingConfidence;

		HtmlData htmlCode;
	};

public:
	HttpConnection();
	virtual ~HttpConnection();

public:
	bool FetchUrl(const HttpConnectionParam& in, HttpConnectionResult& out );
	void GetLastErrorString( std::string& errorBuffer ) const { errorBuffer = this->errorBuffer; }

public:
	static bool Get(const std::string& url, std::string& html);
	static bool Get(const htmlparser::DatabaseUrl& url, std::string& html);

private:
	static int WriterCallback(char *data, size_t size, size_t nmemb, HtmlData* writerData);

private:
	bool CheckContentType(const char* pszBuffer, const int bufLen, HttpConnectionResult& out);

private:
	CURL* curl;
	char errorBuffer[CURL_ERROR_SIZE];
};

}
