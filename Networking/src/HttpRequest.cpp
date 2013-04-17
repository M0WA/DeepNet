/*
 * HttpRequest.cpp
 *
 *  Created on: Dec 21, 2012
 *      Author: Moritz Wagner
 */

#include "HttpRequest.h"

#include <sstream>

namespace network {

HttpRequest::HttpRequest(const HttpRequestType& type,const HttpUrl& url)
: url(url)
, type(type) {
	AddHeaderEntry("Host",url.GetFullDomain() );
	AddHeaderEntry("Accept","text/html"); //TODO: implement xhtml etc, only html supported,
}

HttpRequest::~HttpRequest() {
}

void HttpRequest::AddHeaderEntry(const std::string& key, const std::string& value) {
	headerEntries[key] = value;
}

void HttpRequest::RemoveHeaderEntry(const std::string& key) {
	headerEntries.erase(key);
}

void HttpRequest::ToString(std::string& out) const {

	std::ostringstream ssOut;
	std::map<std::string,std::string>::const_iterator iterMap = headerEntries.begin();
	for(; iterMap != headerEntries.end(); ++iterMap) {
		ssOut << iterMap->first << ": " << iterMap->second << "\r\n"; }
	out = ssOut.str();
}

std::string HttpRequest::ToString() const {

	std::string out;
	ToString(out);
	return out;
}

}
