/**
 *
 * @file HttpClientSettings.h
 * @author Moritz Wagner
 * @date 15.05.2013
 *
 */

#pragma once

#include <string>

namespace network {

/**
 * @brief settings for all http clients
 * @see network::HttpClientFactory
 */
class HttpClientSettings {
public:
	HttpClientSettings();
	virtual ~HttpClientSettings();

public:
	/**
	 * user agent string
	 */
	std::string userAgent;

	/**
	 * timeout for connect()
	 */
	int secondsTimeoutConnect;

	/**
	 * timeout for complete connection
	 */
	int secondsTimeoutConnection;

	/**
	 * enables IPv6
	 */
	bool allowIPv6;

	/**
	 * upload limit in KB/sec
	 */
	int uploadLimitKB;

	/**
	 * download limit in KB/sec
	 */
	int downloadLimitKB;

	/**
	 * maximum download size (in bytes, 0 for unlimited)
	 */
	size_t maxSize;
};

}
