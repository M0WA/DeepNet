/*
 * UnitTestUrl.h
 *
 *  Created on: 25.08.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>
#include <vector>
#include <HttpUrl.h>

namespace toolbot {

class UnitTestUrl {

public:
	static bool ReadInvalidURLFile(const std::string& urlFileName, std::vector<UnitTestUrl>& testUrls);
	static bool ReadValidURLFile(const std::string& urlFileName, std::vector<UnitTestUrl>& testUrls);

public:
	std::string baseUrl;
	std::string theUrl;
	std::string resultUrl;

	network::HttpUrl base;
	network::HttpUrl url;
	network::HttpUrl result;
	network::HttpUrl reverse;

	int line;
};

}

