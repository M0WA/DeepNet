/*
 * HttpHeader.h
 *
 *  Created on: 17.03.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <map>
#include <string>
#include <sstream>

namespace fastcgiserver {

class HttpHeader {
public:
	HttpHeader();
	virtual ~HttpHeader();

	void Add(const std::string& key, const std::string& value) { mapHeader[key] = value; }

	std::string ToString(const size_t contentLen);

	int StatusCode() const {return statusCode;}
	void SetStatusCode(const int statusCode) {this->statusCode = statusCode;}

private:
	int statusCode;
	std::map<std::string,std::string> mapHeader;
};

}
