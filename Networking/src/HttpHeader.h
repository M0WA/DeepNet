/*
 * HttpHeader.h
 *
 *  Created on: Jan 20, 2013
 *      Author: Moritz Wagner
 */

#pragma once

#include <map>
#include <string>

#include <MemoryContainer.h>

namespace network {

class HtmlData;
class SocketIPv4TCPClient;
class HttpHeader {
public:
	HttpHeader();
	virtual ~HttpHeader();

public:
	bool Init(const tools::MemoryContainer<char>& headerData, const size_t& rawDataSize);

public:
	int                    GetStatusCode()    const { return statusCode;    }
	const std::string&     GetStatusMessage() const { return statusMessage; }

	std::string            GetLocation() const { return (HasProperty("location") ? entries.at("location") : ""); }
	void				   SetLocation(const std::string& location) { AddProperty("location", location); }
	size_t				   GetLength() const { return rawData.GetCount(); }

	void SetStatusCode(int newStatusCode);

	bool HasProperty(const std::string& property) const;
	bool GetProperty(const std::string& property, std::string& value) const;
	void AddProperty(const std::string& property, const std::string& value);

	bool ToString(std::string& out) const;

public:
	static size_t FindEndOfLine(const char* search, const size_t maxPos);
	static size_t FindEndOfHeader(const char* search, const size_t maxPos);
	static bool GetStatusStringByCode(const int newStatusCode, std::string& statusMessage);

private:
	bool ParseStatusLine(size_t& endStatus);
	bool ParseHeader(const size_t beginHeader);

private:
	tools::MemoryContainer<char> rawData;
	std::map<std::string, std::string> entries;
	int statusCode;
	std::string statusMessage;
};

}
