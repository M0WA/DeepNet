/**
 * @file HttpCookie.h
 * @author Moritz Wagner
 * @date 29.06.2012
 */

#pragma once

#include <string>
#include <vector>
#include <map>

namespace network {

class HttpCookie {
public:
	HttpCookie();
	virtual ~HttpCookie();

	bool FromString(const std::string& rawCookieString);
	std::string ToString() const { return keyValuePair.first + "=" + keyValuePair.second; }

	const std::string& GetKey()   const { return keyValuePair.first;  }
	const std::string& GetValue() const { return keyValuePair.second; }

private:
	std::pair<std::string,std::string> keyValuePair;
};

class HttpCookieHelper
{
private:
	HttpCookieHelper() {}

public:
	static bool GetCookieByKey(const std::string& key, const std::vector<HttpCookie>& cookies, HttpCookie& cookie);

};

}
