/*
 * HttpUrl.h
 *
 *  Created on: Dec 22, 2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>

namespace network {

class HttpUrl {

	friend class HttpUrlParser;

public:
	HttpUrl();
	virtual ~HttpUrl();
	bool operator<(HttpUrl const& rhs) const;
	bool operator==(HttpUrl const& rhs) const;

public:
	std::string Dump() const;
	virtual void Dump(std::string& dump) const;

public:
	bool CalculateFullUrl(const bool forceRecalculate = false);
	virtual bool DeepMatchUrl(const HttpUrl& rhs, const bool compareAuth = false) const;

public:
	const std::string& GetScheme() const;
	const std::string& GetMD5() const;
	const std::string& GetDomain() const;
	const std::string& GetPort() const;
	const std::string& GetTLD() const;
	const std::string& GetSecondLevelDomain() const;
	const std::string& GetSubdomain() const;
	const std::string& GetPathPart() const;
	const std::string& GetDocument() const;
	const std::string& GetSearchPart() const;
	const std::string& GetFragmentPart() const;
	const std::string& GetAuthUser() const;
	const std::string& GetAuthPass() const;

	const std::string& GetFullUrl() const;

	const std::string GetFullDomain() const;
	const std::string GetFullPathSearch() const;

private:
	void CalculatePortPart();
	void CalculateDomainPart();

protected:
	std::string fullUrl;

	std::string domain;
	std::string scheme;
	std::string subdomain;
	std::string secondleveldomain;
	std::string tld;
	std::string port;
	std::string path_part;
	std::string search_part;
	std::string fragment_part;

	std::string auth_user;
	std::string auth_pass;

	std::string md5;

	bool isCalculated;
};

}
