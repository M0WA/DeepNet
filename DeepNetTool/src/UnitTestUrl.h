/**
 *
 * @file UnitTestUrl.h
 * @author Moritz Wagner
 * @date 25.08.2012
 *
 */

#pragma once

#include <string>
#include <vector>
#include <HttpUrl.h>

namespace toolbot {

/**
 * @brief implements wrapper for network::HttpUrl for unit tests for parsing URLs
 * @see network::HttpUrl
 * @see toolbot::UnitTestUrlParser
 */
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

