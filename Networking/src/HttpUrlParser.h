/*
 * HttpUrlParser.h
 *
 *  Created on: Dec 22, 2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <vector>
#include <string>

namespace network {

class HttpUrl;
class HttpUrlParser {

private:
	enum DOMAIN_TYPE
	{
		UNKNOWN,
		DOMAIN,
		DOCUMENT,
	};

private:
	HttpUrlParser();
public:
	virtual ~HttpUrlParser();

public:
	static void InitTLDCache(const std::vector<std::string>& tldsCache) { tlds = tldsCache; }

public:
	//
	// initialize toplevel domains
	//
	static void SetAllowedTopLevelDomains(const std::vector<std::string>& tldVec) { tlds = tldVec; }

public:
	//
	// parsing functions
	//
	static void ParseURL(const std::string& sBaseUrl, const std::string& sUrl, HttpUrl& url);
	static void ParseURL(const std::string& sUrl, HttpUrl& url);
	static void ParseURL(const HttpUrl& baseUrl, const std::string& sUrl, HttpUrl& url);

	//
	// encoding functions
	//
	static void DecodeUrl(std::string& url);
	static void EncodeUrl(std::string& url);

	static void NormalizePath(const std::string& pathIn, std::string& pathNormalized);

private:
	static bool ValidateDomain(
		const std::string& domainTLD,
		std::string& domain,
		std::string& tld,
		DOMAIN_TYPE& typeDomain);

	static void ParseScheme(
		const HttpUrl& baseUrl,
		const std::string& url,
		size_t& schemeEnd,
		std::string& scheme);

	static void ParseAuthentication(
		const HttpUrl& baseUrl,
		const std::string& url,
		size_t& schemeEndIn_AuthEndOut,
		std::string& user,
		std::string& pass);

	static void ParseDomain(
		const HttpUrl& baseUrl,
		const std::string& url,
		size_t& authEndIn_DomainEndOut,
		std::string& domain,
		std::string& tld,
		std::string& port);

	static void ParsePath(
		const HttpUrl& baseUrl,
		const std::string& url,
		size_t& domainEndIn_PathEndOut,
		std::string& path,
		std::string& document);

	static void ParseQuery(
		const HttpUrl& baseUrl,
		const std::string& url,
		size_t& pathEndIn_QueryEndOut,
		std::vector<std::string>& queryParam);

	static void ParseFragment(
		const HttpUrl& baseUrl,
		const std::string& url,
		size_t& queryEndIn,
		std::string& fragment);

	static void SplitPathDocument(
		const std::string& pathdocument,
		std::string& path,
		std::string& document);

	static bool IsValidDocumentExtension(const std::string& extension);

	static void TrimSlashes(std::string& in);

private:
	static std::vector<std::string> tlds;
};

}
