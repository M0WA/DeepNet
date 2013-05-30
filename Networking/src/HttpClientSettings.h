/**
 *
 * @file HttpClientSettings.h
 * @author Moritz Wagner
 * @date May 15, 2013
 *
 */

#pragma once

#include <string>

namespace network {

class HttpClientSettings {
public:
	HttpClientSettings();
	virtual ~HttpClientSettings();

public:
	std::string userAgent;
	int secondsTimeoutConnect;
	int secondsTimeoutConnection;
	bool allowIPv6;
	int uploadLimitKB;
	int downloadLimitKB;
};

}
