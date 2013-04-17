/*
 * HttpUrl.cpp
 *
 *  Created on: Dec 22, 2012
 *      Author: Moritz Wagner
 */

#include "HttpUrl.h"

#include <sstream>
#include <vector>
#include <cstring>

#include <Exception.h>
#include <StringTools.h>
#include <HashTools.h>

#include "HttpUrlParserInvalidUrlException.h"

namespace network {

HttpUrl::HttpUrl()
: isCalculated(false){
}

HttpUrl::~HttpUrl() {
}

bool HttpUrl::operator<(HttpUrl const& rhs) const {

	if( this->md5.empty() || rhs.md5.empty() )
		throw;
	return this->md5 < rhs.md5;
}

bool HttpUrl::operator==(HttpUrl const& rhs) const {

	if( this->md5.empty() || rhs.md5.empty() )
		throw;
	return ( this->md5.compare(rhs.md5) == 0 );
}

std::string HttpUrl::Dump() const
{
	std::string dump;
	Dump(dump);
	return dump;
}

void HttpUrl::Dump(std::string& dump) const
{
	std::stringstream ssDump;
	ssDump << "full url:  " << fullUrl << std::endl <<
	"scheme:       " << scheme << std::endl <<
	"domain:       " << domain << std::endl <<
	"subdomain:    " << subdomain << std::endl <<
	"secondlvl:    " << secondleveldomain << std::endl <<
	"tld:          " << tld << std::endl <<
	"port:         " << port << std::endl <<
	"path_part:    " << path_part << std::endl <<
	"search:       " << search_part << std::endl <<
	"fragment:     " << fragment_part << std::endl <<
	"md5:          " << md5 << std::endl <<
	"auth_user:    " << auth_user << std::endl<<
	"auth_pass:    " << auth_pass << std::endl;
	dump = ssDump.str();
}

void HttpUrl::CalculateDomainPart() {

	if(domain.empty() && secondleveldomain.empty()) {
		THROW_EXCEPTION(HttpUrlParserInvalidUrlException,fullUrl,"");
	}

	if(!domain.empty() && secondleveldomain.empty()) {

		//calculate from domain, split in subdomain and secondleveldomain
		std::vector<std::string> domainParts;
		tools::StringTools::SplitBy(domain, ".", domainParts);
		if(domainParts.size()){
			secondleveldomain = domainParts.back();
			for(size_t i = 0; i < domainParts.size()-1; i++){
				if(i)
					subdomain.append(".");
				subdomain.append(domainParts.at(i));
			}
		} else {
			secondleveldomain = domain;
		}
	}
	else if(domain.empty() && !secondleveldomain.empty()) {
		if(!subdomain.empty())
			domain = subdomain + ".";
		domain += secondleveldomain;
	}

	if(domain.empty() && !subdomain.empty())
		domain = subdomain + "." + secondleveldomain;
	else if(domain.empty())
		domain = secondleveldomain;

	if(domain.empty()) {
		THROW_EXCEPTION(HttpUrlParserInvalidUrlException,fullUrl,"");
	}

	if(tld.empty()) {
		THROW_EXCEPTION(HttpUrlParserInvalidUrlException,fullUrl,"");
	}
}

void HttpUrl::CalculatePortPart() {

	if(port.empty()) {

		if(scheme.compare("https") == 0) {
			port = "443";
		}
		else if (scheme.compare("http") == 0) {
			port = "80";
		}
		else {
			//THROW_EXCEPTION(URLInvalidSchemeException,Dump());
		}
	}
}

bool HttpUrl::CalculateFullUrl(const bool forceRecalculate)
{
	if(isCalculated && !forceRecalculate)
		return true;

	CalculateDomainPart();
	CalculatePortPart();

	std::ostringstream ssUrl;
	ssUrl << scheme << "://" << domain << "." << tld << ":" << port;
	if(!path_part.empty() || !search_part.empty())
		ssUrl << "/";
	ssUrl << path_part;
	ssUrl << search_part;

	md5 = tools::HashTools::GetMD5(ssUrl.str().c_str());

	//fragment part gets ignored for hash calculation
	if(path_part.empty() && search_part.empty() && !fragment_part.empty())
		ssUrl << "/";
	ssUrl << fragment_part;
	fullUrl = ssUrl.str();

	isCalculated = true;
	return true;
}

const std::string& HttpUrl::GetScheme() const {

	return scheme;
}

const std::string& HttpUrl::GetFullUrl() const {

	return fullUrl;
}

const std::string& HttpUrl::GetMD5() const {

	return md5;
}

const std::string& HttpUrl::GetDomain() const {

	return domain;
}

const std::string& HttpUrl::GetPort() const {

	return port;
}

const std::string& HttpUrl::GetTLD() const {

	return tld;
}

const std::string& HttpUrl::GetSecondLevelDomain() const {

	return secondleveldomain;
}

const std::string& HttpUrl::GetSubdomain() const {

	return subdomain;
}

const std::string& HttpUrl::GetPathPart() const {

	return path_part;
}

const std::string& HttpUrl::GetSearchPart() const {

	return search_part;
}

const std::string& HttpUrl::GetFragmentPart() const {

	return fragment_part;
}

const std::string& HttpUrl::GetAuthUser() const {

	return auth_user;
}

const std::string& HttpUrl::GetAuthPass() const {

	return auth_pass;
}

bool HttpUrl::DeepMatchUrl(const HttpUrl& rhs, const bool compareAuth) const {

	bool match = true;

	match &= GetFullUrl().compare(rhs.GetFullUrl()) == 0;
	match &= GetDomain().compare(rhs.GetDomain()) == 0;
	match &= GetScheme().compare(rhs.GetScheme()) == 0;
	match &= GetSubdomain().compare(rhs.GetSubdomain()) == 0;
	match &= GetSecondLevelDomain().compare(rhs.GetSecondLevelDomain()) == 0;
	match &= GetTLD().compare(rhs.GetTLD()) == 0;
	match &= GetPort().compare(rhs.GetPort()) == 0;
	match &= GetPathPart().compare(rhs.GetPathPart()) == 0;
	match &= GetSearchPart().compare(rhs.GetSearchPart()) == 0;
	match &= GetMD5().compare(rhs.GetMD5()) == 0;
	match &= GetFragmentPart().compare(rhs.GetFragmentPart()) == 0;

	if(compareAuth) {
		match &= GetAuthUser().compare(rhs.GetAuthUser()) == 0;
		match &= GetAuthPass().compare(rhs.GetAuthPass()) == 0;
	}

	return match;
}

const std::string  HttpUrl::GetFullDomain() const {
	return GetDomain() + "." + GetTLD();
}

const std::string HttpUrl::GetFullPathSearch() const {

	std::stringstream ssFullPathSearch;
	if(!path_part.empty() || !search_part.empty())
		ssFullPathSearch << "/";
	ssFullPathSearch << path_part;
	ssFullPathSearch << search_part;

	std::string fullPath = ssFullPathSearch.str();
	if(fullPath.empty())
		return "/";

	return fullPath;
}

}
