/*
 * HttpClientSettings.h
 *
 *  Created on: Feb 4, 2013
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>
#include <sys/time.h>

namespace network {

class HttpClientSettings {

public:
	HttpClientSettings();
	virtual ~HttpClientSettings();

public:
	void SetUserAgent(const std::string& userAgent) { this->userAgent = userAgent; }
	const std::string& GetUserAgent() const { return userAgent ;}

	void SetCompression(const bool& enableCompression) { this->enableCompression = enableCompression; }
	bool GetCompression() const { return enableCompression; }

	void  SetConnectTimeout(const struct timeval& connectTimeout) { this->connectTimeout = connectTimeout; }
	const struct timeval& GetConnectTimeout() const { return connectTimeout; }

	void SetReadTimeout(const struct timeval& readTimeout) { this->readTimeout = readTimeout; }
	const struct timeval& GetReadTimeout() const { return readTimeout; }

	void SetRedirectLimit(const size_t& followRedirects) { this->followRedirects = followRedirects; }
	const size_t& GetRedirectLimit() const { return followRedirects; }

	void SetKeepAlive(const bool& allowKeepAlive) { this->allowKeepAlive = allowKeepAlive; }
	bool GetKeepAlive() const { return allowKeepAlive; }

	void SetUploadLimit(const size_t& uploadLimit) { this->uploadLimit = uploadLimit; }
	size_t GetUploadLimit() const { return uploadLimit; }

	void SetDownloadLimit(const size_t& downloadLimit) { this->downloadLimit = downloadLimit; }
	size_t GetDownloadLimit() const { return downloadLimit; }

private:
	struct timeval connectTimeout;
	struct timeval readTimeout;

	bool allowKeepAlive;
	bool enableCompression;

	std::string userAgent;
	size_t followRedirects;

	size_t uploadLimit;
	size_t downloadLimit;
};

}
