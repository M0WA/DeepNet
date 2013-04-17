/*
 * HttpRequest.h
 *
 *  Created on: Dec 21, 2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>
#include <map>

#include "HttpUrl.h"

namespace network {

class HttpRequest {

public:
	enum HttpRequestType {
		GET = 0,
		POST,
	};

protected:
	HttpRequest(const HttpRequestType& type, const HttpUrl& url);
public:
	virtual ~HttpRequest();

public:
	const std::string&     GetHost()         const { return url.GetDomain(); }
	const HttpRequestType& GetType()         const { return type; }

public:
	virtual void ToString(std::string& out) const;
	std::string ToString() const;

	void AddHeaderEntry(const std::string& key, const std::string& value);
	void RemoveHeaderEntry(const std::string& key);

public:
	HttpUrl url;

private:
	HttpRequestType type;
	std::map<std::string,std::string> headerEntries;

};

}
