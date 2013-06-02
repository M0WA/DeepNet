/**
 * @file HttpUrlParser.h
 * @author Moritz Wagner
 * @date 22.12.2012
 */

#pragma once

#include <vector>
#include <string>

namespace network {

class HttpUrl;

/**
 * @brief parser class for URLs
 */
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
	/**
	 * sets local top level domain cache
	 * @param tldsCache available top level domains
	 */
	static void SetTopLevelDomains(const std::vector<std::string>& tldVec) { tlds = tldVec; }

public:
	/**
	 * parses url from string and base url
	 * @param sBaseUrl base url of document (for relative links)
	 * @param sUrl url to parse
	 * @param url parsed url
	 */
	static void ParseURL(const std::string& sBaseUrl, const std::string& sUrl, HttpUrl& url);

	/**
	 * parses url from string
	 * @param sUrl url to parse
	 * @param url parsed url
	 */
	static void ParseURL(const std::string& sUrl, HttpUrl& url);

	/**
	 * parses url from string and base url
	 * @param baseUrl base url of document (for relative links)
	 * @param sUrl url to parse
	 * @param url parsed url
	 */
	static void ParseURL(const HttpUrl& baseUrl, const std::string& sUrl, HttpUrl& url);

	/**
	 * url decode string
	 * @param url url decoded string
	 */
	static void DecodeUrl(std::string& url);

	/**
	 * url encode string
	 * @param url url encoded string
	 */
	static void EncodeUrl(std::string& url);

	/**
	 * normalized path
	 * @param pathIn path to normalize
	 * @param pathNormalized normalized path
	 */
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
