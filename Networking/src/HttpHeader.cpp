/*
 * HttpHeader.cpp
 *
 *  Created on: Jan 20, 2013
 *      Author: Moritz Wagner
 */

#include "HttpHeader.h"

#include <vector>

#include <MemoryContainer.h>
#include <Logging.h>
#include <PCRERegex.h>
#include <StringTools.h>

#include "HtmlData.h"
#include "SocketIPv4TCPClient.h"

namespace network {

HttpHeader::HttpHeader() {
}

HttpHeader::~HttpHeader() {
}

bool HttpHeader::Init(const tools::MemoryContainer<char>& headerData, const size_t& rawDataSize) {

	rawData.Release();
	rawData.Append(0, headerData, 0, rawDataSize);

	size_t endStatusLine = 0;
	if(!ParseStatusLine(endStatusLine)) {
		return false; }

	if(!ParseHeader(endStatusLine) ) {
		return false; }

	return true;
}

size_t HttpHeader::FindEndOfLine(const char* search, const size_t maxPos) {

	if(maxPos < 2)
		return 0;

	size_t endPos = maxPos - 1;
	for(size_t i = 0; i < endPos; i++) {
		if( search[i  ] == '\r' &&
			search[i+1] == '\n'
		) {
			return i + 2;
		}
	}

	return 0;
}

size_t HttpHeader::FindEndOfHeader(const char* search, const size_t maxPos) {

	if(maxPos < 4)
		return 0;

	size_t endPos = maxPos - 3;
	for(size_t i = 0; i < endPos; i++) {
		if( search[i  ] == '\r' &&
			search[i+1] == '\n' &&
			search[i+2] == '\r' &&
			search[i+3] == '\n' ) {
			return i + 4;
		}
	}

	return 0;
}

bool HttpHeader::ParseStatusLine(size_t& endStatus) {

	endStatus = FindEndOfLine(rawData.GetConstElementAt(0),rawData.GetCount());
	if(endStatus == 0) {
		log::Logging::Log(log::Logging::LOGLEVEL_INFO,"error while reading status line from http header");
		return false;}

	std::string lineStatus;
	lineStatus.append(rawData.GetConstElementAt(0),endStatus - 2);

	std::vector<std::string> groupsStatus;
	tools::PCRERegex regexStatusLine("HTTP\\/1\\.(0|1)\\s+(\\d+)\\s+(.*)",true);
	if(!regexStatusLine.Match(lineStatus,groupsStatus) || groupsStatus.size() != 4) {
		log::Logging::Log(log::Logging::LOGLEVEL_INFO,"error while parsing status line from http header");
		return false;
	}

	if(!tools::StringTools::TransformString(groupsStatus.at(2), statusCode)) {
		log::Logging::Log(log::Logging::LOGLEVEL_INFO,"error while reading status code from http header");
		return false;
	}

	statusMessage = groupsStatus.at(3);
	return true;
}

bool HttpHeader::ParseHeader(const size_t beginHeader) {

	tools::PCRERegex regexHeaderLine("\\s*(.*?)\\s*:\\s*(.*)",true);
	size_t startLine = beginHeader;
	for(size_t i = startLine; i < rawData.GetCount(); i++) {

		if( *(rawData.GetConstElementAt(i)) == '\r' &&
			*(rawData.GetConstElementAt(i+1)) == '\n' ) {

			const char* pLineStart = rawData.GetConstElementAt(startLine);
			const char* pLineStop  = rawData.GetConstElementAt(i);

			size_t lineSize = pLineStop - pLineStart;
			std::string line;
			line.append(pLineStart,lineSize);

			std::vector<std::string> groups;
			if(!regexHeaderLine.Match(line,groups) || groups.size() != 3) {
				break;}

			std::string& key = groups.at(1);
			tools::StringTools::ToLowerIP(key);
			entries[key] = groups.at(2);

			i += 2;
			startLine = i;
		}
	}
	return true;
}

bool HttpHeader::GetProperty(const std::string& property, std::string& value) const {

	if(!HasProperty(property))
		return false;

	value = entries.at(property);
	return true;
}

bool HttpHeader::HasProperty(const std::string& property) const {
	return entries.count(tools::StringTools::ToLowerNP(property)) > 0;
}

void HttpHeader::AddProperty(const std::string& property, const std::string& value) {
	entries[tools::StringTools::ToLowerNP(property)] = value;
}

void HttpHeader::SetStatusCode(int newStatusCode) {

	std::string newStatusMessage;
	if(!GetStatusStringByCode(newStatusCode, newStatusMessage))
		return;
	statusCode = newStatusCode;
	statusMessage = newStatusMessage;
}

bool HttpHeader::GetStatusStringByCode(const int newStatusCode, std::string& statusMessage) {

	switch(newStatusCode)
	{
	case 200:
		statusMessage = "OK";
		break;

	case 301:
		statusMessage = "moved permanently";
		break;

	case 302:
		statusMessage = "found";
		break;

	case 304:
		statusMessage = "not modified";
		break;

	case 401:
		statusMessage = "unauthorized";
		break;

	case 403:
		statusMessage = "forbidden";
		break;

	case 404:
		statusMessage = "page not found";
		break;

	case 429:
		statusMessage = "too many requests";
		break;

	case 500:
		statusMessage = "internal server error";
		break;

	case 503:
		statusMessage = "service unavailable";
		break;

	default:
		return false;
	}

	return true;
}

bool HttpHeader::ToString(std::string& out) const {

	if( rawData.GetCount() == 0 )
		return false;

	out.append(rawData,rawData.GetCount());
	return true;
}

}
