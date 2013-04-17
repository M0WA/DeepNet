/*
 * UnitTestHttpClient.h
 *
 *  Created on: Dec 22, 2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>
#include <vector>

#include <HttpRequestResult.h>
#include <HttpClientEx.h>

namespace network {
	class HttpUrl;
}

namespace toolbot {

class UnitTestHttpClient {
private:
	UnitTestHttpClient();
public:
	virtual ~UnitTestHttpClient();

public:
	static bool Test(const std::string& urlGet,const std::string& urlPost);

private:
	static bool TestGet(const network::HttpUrl& url);
	static bool TestPost(const network::HttpUrl& url);

	static bool ProcessResponse(const network::HttpRequestResult& response);
	static bool ReadURLFile(const std::string& urlFileName, std::vector<network::HttpUrl>& testUrls);
};

}
