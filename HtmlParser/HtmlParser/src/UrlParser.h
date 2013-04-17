/*
 * UrlParser.h
 *
 *  Created on: 14.01.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>
#include "URL.h"

namespace database {

	class DatabaseConnection;
}

namespace htmlparser {

class UrlParser
{
private:
	enum DOMAIN_TYPE
	{
		UNKNOWN,
		DOMAIN,
		DOCUMENT,
	};

private:
	UrlParser();
	virtual ~UrlParser();

public:
	//
	// parsing functions
	//
	static void ParseURL(const std::string& sBaseUrl, const std::string& sUrl, URL& url);
	static void ParseURL(const std::string& sUrl, URL& url);
	static void ParseURL(const URL& baseUrl, const std::string& sUrl, URL& url);

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
		const URL& baseUrl,
		const std::string& url,
		size_t& schemeEnd,
		std::string& scheme);

	static void ParseAuthentication(
		const URL& baseUrl,
		const std::string& url,
		size_t& schemeEndIn_AuthEndOut,
		std::string& user,
		std::string& pass);

	static void ParseDomain(
		const URL& baseUrl,
		const std::string& url,
		size_t& authEndIn_DomainEndOut,
		std::string& domain,
		std::string& tld,
		std::string& port);

	static void ParsePath(
		const URL& baseUrl,
		const std::string& url,
		size_t& domainEndIn_PathEndOut,
		std::string& path,
		std::string& document);

	static void ParseQuery(
		const URL& baseUrl,
		const std::string& url,
		size_t& pathEndIn_QueryEndOut,
		std::vector<std::string>& queryParam);

	static void ParseFragment(
		const URL& baseUrl,
		const std::string& url,
		size_t& queryEndIn,
		std::string& fragment);

	static void SplitPathDocument(
		const std::string& pathdocument,
		std::string& path,
		std::string& document);

	static bool IsValidDocumentExtension(const std::string& extension);

	static void TrimSlashes(std::string& in);
};

}
