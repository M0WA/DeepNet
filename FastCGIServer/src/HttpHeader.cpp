/*
 * HttpHeader.cpp
 *
 *  Created on: 17.03.2012
 *      Author: Moritz Wagner
 */

#include "HttpHeader.h"

#define SERVER_NAME "httpd"

#include <Logging.h>

namespace fastcgiserver {

HttpHeader::HttpHeader()
: statusCode(200) {
}

HttpHeader::~HttpHeader() {
}

std::string HttpHeader::ToString(const size_t contentLen)
{
	std::string statusMsg;
	switch(statusCode)
	{
	case 200:
		statusMsg = "OK";
		break;

	case 301:
		statusMsg = "moved permanently";
		break;

	case 302:
		statusMsg = "found";
		break;

	case 304:
		statusMsg = "not modified";
		break;

	case 401:
		statusMsg = "unauthorized";
		break;

	case 403:
		statusMsg = "forbidden";
		break;

	case 404:
		statusMsg = "page not found";
		break;

	case 429:
		statusMsg = "too many requests";
		break;

	case 500:
		statusMsg = "internal server error";
		break;

	case 503:
		statusMsg = "service unavailable";
		break;

	default:
		//unknown defaulting to 404
		statusMsg = "page not found";
		statusCode = 404;
		break;
	}

	std::stringstream ssHeader;
	ssHeader <<
		"HTTP/1.1 " << statusCode << " " << statusMsg << "\r\n" <<
		"Server: " << SERVER_NAME << "\r\n";

	std::map<std::string,std::string>::const_iterator iterMapHeader(mapHeader.begin());
	for(;iterMapHeader != mapHeader.end(); ++iterMapHeader) {
		ssHeader << iterMapHeader->first << ": " << iterMapHeader->second << "\r\n"; }

	ssHeader <<
		"Content-Length: " << contentLen << "\r\n" <<
		"Content-Type: application/xml; charset=utf-8\r\n\r\n";

	const std::string& tmpHeader(ssHeader.str());
	log::Logging::LogTrace("header:\n%s", tmpHeader.c_str());

	return tmpHeader;
}

}
