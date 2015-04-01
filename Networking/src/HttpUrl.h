/**
 *
 * @file HttpUrl.h
 * @author Moritz Wagner
 * @date 22.12.2012
 *
 */

#pragma once

#include <string>

namespace network {

/**
 * @brief represents a http url
 * @see network::HttpUrlParser
 */
class HttpUrl {

	friend class HttpUrlParser;

public:
	HttpUrl();
	virtual ~HttpUrl();

	/**
	 * compares urls by their md5 values
	 * @param rhs url to compare to
	 * @return true if smaller, else false
	 */
	bool operator<(HttpUrl const& rhs) const;

	/**
	 * compares urls by their md5 values
	 * @param rhs url to compare to
	 * @return true if equal, else false
	 */
	bool operator==(HttpUrl const& rhs) const;

public:
	/**
	 * dumps url to a string
	 * @return url string
	 */
	std::string Dump() const;

	/**
	 * dumps url to a string
	 * @param dump string to dump url in
	 */
	virtual void Dump(std::string& dump) const;

public:
	/**
	 * sets all calculated values
	 * @param forceRecalculate set true to force recalculation
	 * @return true if successful, false if error
	 */
	bool CalculateFullUrl(const bool forceRecalculate = false);

	/**
	 * compares url memberwise
	 * @param rhs url to compare to
	 * @param compareAuth set true to also compare auth part
	 * @return true if match, false if not a match
	 */
	virtual bool DeepMatchUrl(const HttpUrl& rhs, const bool compareAuth = false) const;

public:
	/**
	 * gets scheme of url
	 * @return scheme
	 */
	const std::string& GetScheme() const;

	/**
	 * gets calculated md5 of url
	 * @return calculated md5
	 */
	const std::string& GetMD5() const;

	/**
	 * gets domain (sub- and secondlevel domain, without toplevel domain) of url
	 * @return domain
	 */
	const std::string& GetDomain() const;

	/**
	 * gets port of url
	 * @return port
	 */
	const std::string& GetPort() const;

	/**
	 * gets toplevel domain of url
	 * @return toplevel domain
	 */
	const std::string& GetTLD() const;

	/**
	 * gets secondlevel domain of url
	 * @return secondlevel domain
	 */
	const std::string& GetSecondLevelDomain() const;

	/**
	 * gets subdomain of url
	 * @return subdomain domain
	 */
	const std::string& GetSubdomain() const;

	/**
	 * gets path part of url
	 * @return path part
	 */
	const std::string& GetPathPart() const;

	/**
	 * gets document of url
	 * @return document
	 */
	const std::string& GetDocument() const;

	/**
	 * gets search part of url
	 * @return search part
	 */
	const std::string& GetSearchPart() const;

	/**
	 * gets fragment part of url
	 * @return fragment part
	 */
	const std::string& GetFragmentPart() const;

	/**
	 * gets auth user of url
	 * @return auth user
	 */
	const std::string& GetAuthUser() const;

	/**
	 * gets auth pass of url
	 * @return auth pass
	 */
	const std::string& GetAuthPass() const;

	/**
	 * gets normalized url
	 * @return normalized url
	 */
	const std::string& GetFullUrl() const;

	/**
	 * gets complete domain part (sub-, secondlevel and toplevel domain)
	 * @return complete domain part
	 */
	const std::string GetFullDomain() const;

	/**
	 * gets complete path and search part (without fragment part)
	 * @return complete path and search part
	 */
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
