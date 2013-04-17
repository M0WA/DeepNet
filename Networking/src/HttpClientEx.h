/*
 * HttpClientEx.h
 *
 *  Created on: Feb 2, 2013
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>
#include <netinet/in.h>
#include <sys/time.h>

#include <MemoryContainer.h>

#include "HtmlData.h"
#include "HttpClientSettings.h"
#include "HttpRequestResult.h"
#include "SocketOptions.h"
#include "SocketIPv4TCPClient.h"

namespace network {

class HttpUrl;
class HttpHeader;
class HttpRequest;
class HttpResponse;
class HttpClientEx {

public:
	HttpClientEx();
	virtual ~HttpClientEx();

	void Get(const HttpUrl& url, HttpRequestResult& result);
	void Post(const HttpUrl& url, HttpRequestResult& result);
	HttpClientSettings& GetSettings() { return clientSettings; }

private:
	bool Connect(const HttpUrl& url);
	void Disconnect();

	bool SendRequest(const HttpRequest& request, HttpRequestResult& result);
	bool ReadHeader (const struct timeval* const timeout, tools::MemoryContainer<char>& containerHeader, size_t& headerEnd, HtmlData& containerContent);
	bool ReadContent(const HttpHeader& header, const HttpRequest& request, const struct timeval* const timeout, HttpRequestResult& result);
	bool HandleRedirect(const HttpHeader& header, const HttpRequest& request, HttpRequestResult& result);

private:
	void InitRequestFromSettings(HttpRequest& request);

	bool ProcessAfterRequest(const HttpHeader& header, const HttpRequest& request, HttpRequestResult& result);
	bool ProcessTransferEncoding(const HttpHeader& header, HtmlData& container);
	bool ProcessContentEncoding(const HttpHeader& header, HtmlData& containerContent);
	bool ProcessContentType(const HttpHeader& header, HtmlData& containerContent);

	bool LoadChunkedContent(HtmlData& contentBuf);
	bool LoadChunkSize(HtmlData& chunkedContent, const size_t curChunkedPos, size_t& chunkSize, size_t& endChunkSize);
	bool LoadContentLength(HtmlData& chunkedContent, const std::string& contentLengthString);

private:
	void SetSettings(const HttpClientSettings& clientSettings) { this->clientSettings = clientSettings; }

private:
	std::string hostname;
	struct sockaddr_in host;
	HttpClientSettings clientSettings;

	SocketIPv4TCPClient* pClient;
};

}
