#pragma once

namespace network
{

class HttpUrl;
class HttpResponse;
class HttpClientSettings;

class IHttpClient
{
public:
	virtual ~IHttpClient() {}

public:
	virtual bool Get(const HttpUrl& url, HttpResponse& response) = 0;
	virtual HttpClientSettings& Settings() = 0;
};

}
