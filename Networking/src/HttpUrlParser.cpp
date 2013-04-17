/*
 * HttpUrlParser.cpp
 *
 *  Created on: Dec 22, 2012
 *      Author: Moritz Wagner
 */

#include "HttpUrlParser.h"

#include <sys/types.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#include <libxml/uri.h>
#include <curl/curl.h>

#include <Exception.h>
#include <StringTools.h>

#include "HttpUrl.h"

#include "HttpUrlParserInvalidUrlException.h"
#include "HttpUrlParserDecodeException.h"
#include "HttpUrlParserEncodeException.h"
#include "HttpUrlParserInvalidSchemeException.h"
#include "HttpUrlParserTLDCacheException.h"

namespace network {

std::vector<std::string> HttpUrlParser::tlds;

HttpUrlParser::HttpUrlParser() {
}

HttpUrlParser::~HttpUrlParser() {
}

void HttpUrlParser::ParseURL(const HttpUrl& baseUrl,const std::string& url, HttpUrl& urlParsed){

	if(url.empty()) {
		urlParsed = baseUrl;}

	size_t curPos = 0;

	std::string path, document;
	std::vector<std::string> queryParam;

	HttpUrlParser::ParseScheme(baseUrl, url, curPos, urlParsed.scheme);
	HttpUrlParser::ParseAuthentication(baseUrl, url, curPos, urlParsed.auth_user, urlParsed.auth_pass);
	HttpUrlParser::ParseDomain(baseUrl, url, curPos, urlParsed.domain, urlParsed.tld, urlParsed.port);
	HttpUrlParser::ParsePath(baseUrl, url, curPos, path, document);
	HttpUrlParser::ParseQuery(baseUrl, url, curPos, queryParam);
	HttpUrlParser::ParseFragment(baseUrl, url, curPos, urlParsed.fragment_part);

	//assemble port if missing
	if( urlParsed.port.empty() ) {
		if(urlParsed.scheme.compare("http") == 0) {
			urlParsed.port = "80"; }
		else if(urlParsed.scheme.compare("https") == 0) {
			urlParsed.port = "443"; }
		else {
			THROW_EXCEPTION(HttpUrlParserInvalidUrlException,url,baseUrl.fullUrl);
		}
	}

	//assemble path_part
	if(!document.empty() && !path.empty()) {
		urlParsed.path_part = path + "/" + document;
	}
	else if(document.empty() && !path.empty()) {
		urlParsed.path_part = path;
	}
	else if(!document.empty() && path.empty()) {
		urlParsed.path_part = document;
	}
	else {
		//both are empty
		urlParsed.path_part = "";
	}

	//assemble query_part
	if(queryParam.size()) {
		tools::StringTools::VectorToString(queryParam,"","",urlParsed.search_part);
	}
	else {
		urlParsed.search_part = "";
	}

	urlParsed.CalculateFullUrl(true);
}

void HttpUrlParser::ParseScheme(
	const HttpUrl& baseUrl,
	const std::string& url,
	size_t& schemeEnd,
	std::string& scheme) {

	scheme = baseUrl.scheme;
	std::string sUrl_LC = tools::StringTools::ToLowerNP(url);

	size_t schemeStart = sUrl_LC.find("http://");
	if(schemeStart == 0) {
		scheme = "http";
		schemeEnd += 7;
	}
	else if ( (schemeStart = sUrl_LC.find("https://")) == 0) {
		scheme = "https";
		schemeEnd += 8;
	}
	else if ( (schemeStart = sUrl_LC.find("//")) == 0) {
		if(scheme.empty()) {
			THROW_EXCEPTION(HttpUrlParserInvalidSchemeException,url);
		}
		// RFC 1808 Section 4, RFC 2396 Section 5.2, or RFC 3986 Section 5.2
		schemeEnd += 2;
	}

	if(scheme.empty() && url.find("://") != std::string::npos){
		//
		// TODO: find a better way to deal with this to allow urls like
		//       example.com/page.php?link=http://example.com
		//
		//       currently this prevent malformed/invalid schemes from
		//       being parsed as link
		// Solution: use regex "^[a-z]+:\\/\\/"
		//

		THROW_EXCEPTION(HttpUrlParserInvalidSchemeException,url);
	}

	if(scheme.empty()) {
		//default to http
		scheme = "http"; }
}

void HttpUrlParser::ParseAuthentication(
	const HttpUrl& baseUrl,
	const std::string& url,
	size_t& schemeEndIn_AuthEndOut,
	std::string& user,
	std::string& pass){

	std::string trimUrl = url;
	if(schemeEndIn_AuthEndOut>0) {
		trimUrl = trimUrl.substr(schemeEndIn_AuthEndOut,url.length() - schemeEndIn_AuthEndOut); }

	size_t posAt = trimUrl.find("@");
	if(posAt == std::string::npos)
		return;

	trimUrl = trimUrl.substr(0,posAt);
	schemeEndIn_AuthEndOut += posAt+1;

	size_t posColon = trimUrl.find(":");
	if(posColon != std::string::npos) {
		user = trimUrl.substr(0,posColon);
		pass = trimUrl.substr(posColon + 1,posAt - posColon - 1);
	}
	else {
		//no password, only username specified
		user = trimUrl.substr(0,posAt);
	}
}

void HttpUrlParser::ParseDomain(
	const HttpUrl& baseUrl,
	const std::string& url,
	size_t& authEndIn_DomainEndOut,
	std::string& domain,
	std::string& tld,
	std::string& port){

	std::string sUrl_LC = tools::StringTools::ToLowerNP(url);
	std::string trimUrl = sUrl_LC;
	if(authEndIn_DomainEndOut>0) {
		trimUrl = trimUrl.substr(authEndIn_DomainEndOut,trimUrl.length() - authEndIn_DomainEndOut); }

	//locate all possible end markers for domain
	size_t posSlash    = trimUrl.find("/");
	size_t posFragment = trimUrl.find("#");
	size_t posQuery    = trimUrl.find("?");
	size_t posQuery2   = trimUrl.find("&");
	std::vector<size_t> minPos;
	if( posSlash != std::string::npos ) {
		minPos.push_back(posSlash); }
	if(posFragment != std::string::npos)
		minPos.push_back(posFragment);
	if(posQuery != std::string::npos)
		minPos.push_back(posQuery);
	if(posQuery2 != std::string::npos)
		minPos.push_back(posQuery2);

	//trim until only domain part is left
	size_t posEnd = trimUrl.length();
	if(minPos.size() > 0) {
		posEnd = *std::min_element(minPos.begin(),minPos.end());
		trimUrl = trimUrl.substr(0,posEnd);	}

	size_t posDot = trimUrl.find(".");
	if( posDot == std::string::npos ) {
		//cannot be a domain, HAS NO dot in it...
		if(baseUrl.domain.empty() || baseUrl.tld.empty()){
			//relative url with empty base url is not possible
			THROW_EXCEPTION(HttpUrlParserInvalidUrlException,url,baseUrl.fullUrl);
		}

		domain = baseUrl.domain;
		tld    = baseUrl.tld;
		port   = baseUrl.port;
		return;
	}

	//this is the real length of the domain part
	if( trimUrl.length() == 0 ) {
		return; }
	int domainLen = trimUrl.length();

	//get port if available
	size_t posPort = trimUrl.find(":");
	if(posPort != std::string::npos) {
		port = trimUrl.substr(posPort+1,posEnd-posPort-1);

		if(!tools::StringTools::IsNumeric(port))
			THROW_EXCEPTION(HttpUrlParserInvalidUrlException,url,baseUrl.fullUrl);

		trimUrl = trimUrl.substr(0,posPort);
		posEnd  = trimUrl.length();
	}

	//check if the rest is a valid domain
	DOMAIN_TYPE typeDomain = UNKNOWN;
	if( !ValidateDomain(trimUrl, domain, tld, typeDomain) || typeDomain != DOMAIN) {

		//relative url with empty base is not possible
		if(baseUrl.domain.empty() || baseUrl.tld.empty()){
			THROW_EXCEPTION(HttpUrlParserInvalidUrlException,url,baseUrl.fullUrl);
		}

		//is not a domain, must be some document type...
		domain    = baseUrl.domain;
		tld       = baseUrl.tld;
		port      = baseUrl.port;
		return;
	}
	else {
		//only advance if it is a real domain
		authEndIn_DomainEndOut += domainLen;
	}
}

void HttpUrlParser::ParsePath(
	const HttpUrl& baseUrl,
	const std::string& url,
	size_t& domainEndIn_PathEndOut,
	std::string& path,
	std::string& document){

	if(domainEndIn_PathEndOut >= url.length()) {
		return; }

	std::string trimUrl = url;
	if(domainEndIn_PathEndOut>0) {
		trimUrl = trimUrl.substr(domainEndIn_PathEndOut,url.length() - domainEndIn_PathEndOut); }

	//locate all possible end markers for domain
	size_t posFragment = trimUrl.find("#");
	size_t posQuery    = trimUrl.find("?");
	size_t posQuery2   = trimUrl.find("&");
	std::vector<size_t> minPos;
	if(posFragment != std::string::npos)
		minPos.push_back(posFragment);
	if(posQuery != std::string::npos)
		minPos.push_back(posQuery);
	if(posQuery2 != std::string::npos)
		minPos.push_back(posQuery2);

	//trim until only path part is left
	size_t posEnd = trimUrl.length();
	if(minPos.size() > 0) {
		posEnd = *std::min_element(minPos.begin(),minPos.end());
		trimUrl = trimUrl.substr(0,posEnd);	}

	//this is the real length of the path part
	if( trimUrl.length() == 0 ) {
		return; }
	domainEndIn_PathEndOut += trimUrl.length();

	size_t posFirstSlash = trimUrl.find("/");
	std::string basePath = "";
	if(	posFirstSlash != std::string::npos &&
		posFirstSlash > 0 ) {

		//relative path in url need to assemble basePath
		std::string baseDoc;
		std::string trimmedBasePath = baseUrl.path_part;
		HttpUrlParser::TrimSlashes(trimmedBasePath);
		HttpUrlParser::SplitPathDocument(trimmedBasePath,basePath,baseDoc);

		//add preceding and remove trailing "/"-es to/from base path if neccessary
		HttpUrlParser::TrimSlashes(basePath);
	}

	//if path begins or ends with "/" remove it
	HttpUrlParser::TrimSlashes(trimUrl);

	std::string pathUrl;
	HttpUrlParser::SplitPathDocument(trimUrl,pathUrl,document);
	HttpUrlParser::TrimSlashes(pathUrl);
	HttpUrlParser::TrimSlashes(document);

	//assemble path and normalize it
	if(!basePath.empty())
		pathUrl = basePath + "/" + pathUrl;

	path = "";
	if(!pathUrl.empty()) {
		HttpUrlParser::NormalizePath("/"+pathUrl,path);
		HttpUrlParser::TrimSlashes(path);
	}
}

void HttpUrlParser::ParseQuery(
	const HttpUrl& baseUrl,
	const std::string& url,
	size_t& pathEndIn_QueryEndOut,
	std::vector<std::string>& queryParam){

	if(pathEndIn_QueryEndOut >= url.length()) {
		return; }

	std::string trimUrl = url;
	if(pathEndIn_QueryEndOut>0) {
		trimUrl = trimUrl.substr(pathEndIn_QueryEndOut,url.length() - pathEndIn_QueryEndOut); }

	//trim fragment part if neccessary
	size_t posFragment = trimUrl.find("#");
	if(posFragment != std::string::npos) {
		trimUrl = trimUrl.substr(0,posFragment);}

	if(trimUrl.length() == 0)
		return;
	pathEndIn_QueryEndOut += trimUrl.length();

	size_t posQuestion  = trimUrl.find("?");
	size_t posAmpersand = trimUrl.find("&");

	if( posQuestion  == std::string::npos &&
	    posAmpersand == std::string::npos) {
		return; }

	//detect illegal urls which use "&"
	//rather than "?" as marker
	//for their first get parameter
	//
	// this might be a bug producing some
	// strange urls, when people use "&"
	// to pass htmlencoded content
	// in their url at strange places...
	//
	if(posAmpersand < posQuestion) {
		posQuestion = posAmpersand; }

	//split into separate params
	std::vector<std::string> params;
	if(posAmpersand != std::string::npos) {
		tools::StringTools::SplitBy(trimUrl,"&",params); }
	else {
		params.push_back(trimUrl);}

	//remove leading "&" or "?"
	std::vector<std::string>::iterator iterParams = params.begin();
	for(;iterParams != params.end();++iterParams) {

		std::string& singleParam = *iterParams;
		if(singleParam.empty()) {
			THROW_EXCEPTION(HttpUrlParserInvalidUrlException,url,baseUrl.fullUrl);
		}

		if(singleParam.at(0) == '&' || singleParam.at(0) == '?')
			singleParam.erase(0,1);
	}

	// sort alphabetically
	std::sort(params.begin(),params.end());

	//add "?" and "&"
	iterParams = params.begin();
	for(int i = 0;iterParams != params.end();++iterParams,i++) {
		std::string& singleParam = *iterParams;
		if(i)
			singleParam = "&" + singleParam;
		else
			singleParam = "?" + singleParam;

		queryParam.push_back(singleParam);
	}
}

void HttpUrlParser::ParseFragment(
	const HttpUrl& baseUrl,
	const std::string& url,
	size_t& queryEndIn,
	std::string& fragment){

	if(url.length() <= queryEndIn)
		return;

	std::string trimUrl = url;
	if(queryEndIn>0) {
		trimUrl = trimUrl.substr(queryEndIn,url.length() - queryEndIn); }

	if(trimUrl.at(0) != '#') {
		THROW_EXCEPTION(HttpUrlParserInvalidUrlException,url,baseUrl.fullUrl);
	}

	fragment = trimUrl;
}

bool HttpUrlParser::IsValidDocumentExtension(const std::string& extension) {

	return extension.size() > 0;
}

void HttpUrlParser::SplitPathDocument(
	const std::string& pathdocument,
	std::string& path,
	std::string& document){

	size_t posFirstSlash = pathdocument.find("/");
	size_t posLastSlash  = (posFirstSlash != std::string::npos) ? pathdocument.rfind("/") : std::string::npos;

	size_t posLastDot = pathdocument.rfind(".");

	//ignore dots before the last slash
	if(	posLastDot != std::string::npos &&
		posLastSlash != std::string::npos &&
		posLastSlash > posLastDot) {
		posLastDot = std::string::npos;	}

	size_t posPathStop = pathdocument.length();
	if(posLastDot != std::string::npos) {

		//if extension is valid, pathdocument contains a document
		std::string extension = pathdocument.substr(posLastDot+1,pathdocument.length()-posLastDot-1);

		if(IsValidDocumentExtension(extension)) {

			//contains valid extension
			size_t posDoc = (posLastSlash != std::string::npos) ? posLastSlash + 1 : 0;
			std::string documentName = pathdocument.substr(posDoc, posLastDot - 1 - posLastSlash);
			posPathStop = posDoc;

			document = documentName + "." + extension;
		}
	}

	path = pathdocument.substr(0,posPathStop);
}

void HttpUrlParser::TrimSlashes(std::string& in) {

	//if path begins or ends with "/" remove it
	if(!in.empty()) {
		if(in.at(0) == '/') {
			in.erase(0,1); }

		if(!in.empty() && in.at(in.length()-1) == '/') {
			in.erase((in.length()-1),1);}
	}
}

void HttpUrlParser::DecodeUrl(std::string& url) {

	if(url.empty())
		return;

	char* pszDecodedUrl = xmlURIUnescapeString(url.c_str() , url.length(), NULL);
	if(!pszDecodedUrl) {
		THROW_EXCEPTION(HttpUrlParserDecodeException,url);
	}
	url = std::string(pszDecodedUrl);
	xmlFree(pszDecodedUrl);

	CURL* curl = curl_easy_init( );
	int decodedLen = -1;

	pszDecodedUrl = curl_easy_unescape( curl, url.c_str() , url.length() , &decodedLen );
	if(decodedLen <= 0)	{
		curl_free(pszDecodedUrl);
		curl_easy_cleanup(curl);
		THROW_EXCEPTION(HttpUrlParserDecodeException,url);
	}

	url = std::string(pszDecodedUrl);
	curl_free(pszDecodedUrl);
	curl_easy_cleanup(curl);
}

void HttpUrlParser::EncodeUrl(std::string& url) {

	if(url.empty())
		return;

	//decode first to prevent double escaping
	DecodeUrl(url);

	CURL* curl = curl_easy_init( );
	char* pszEncodedUrl = curl_easy_escape( curl, url.c_str(), url.length());
	if(!pszEncodedUrl)	{
		curl_easy_cleanup(curl);
		THROW_EXCEPTION(HttpUrlParserEncodeException,url);
	}
	if(strlen(pszEncodedUrl) <= 0)	{
		curl_free(pszEncodedUrl);
		curl_easy_cleanup(curl);
		THROW_EXCEPTION(HttpUrlParserEncodeException,url);
	}
	url = std::string(pszEncodedUrl);
	curl_free(pszEncodedUrl);
	curl_easy_cleanup(curl);
}

void HttpUrlParser::ParseURL(const std::string& sUrl, HttpUrl& url) {

	if(!sUrl.empty())
		ParseURL("", sUrl, url);
}

void HttpUrlParser::ParseURL(const std::string& sBaseUrl, const std::string& sUrl, HttpUrl& url) {

	HttpUrl urlBase;
	if(!sBaseUrl.empty()) {
		ParseURL(sBaseUrl, urlBase);}

	if(sUrl.empty())
		url = urlBase;
	else
		ParseURL(urlBase, sUrl, url);
}

bool HttpUrlParser::ValidateDomain(const std::string& domainTLD, std::string& domain, std::string& tld, DOMAIN_TYPE& typeDomain) {

	typeDomain = UNKNOWN;
	std::string domainTLD_CS = domainTLD;
	std::string domainTLD_LC = tools::StringTools::ToLowerNP(domainTLD_CS);

	size_t posLastDotInDomain = domainTLD_LC.find_last_of('.');
	size_t posColonInDomain   = domainTLD_LC.find_first_of(':',0);
	size_t sizeDomainTLD      = domainTLD_LC.size();

	// port in domain?
	if(posColonInDomain != std::string::npos) {
		sizeDomainTLD = domainTLD_LC.size() - posColonInDomain; }

	// domain/document/folder has extension
	if(posLastDotInDomain != std::string::npos) {

		// find tld/extension
		tld    = domainTLD_LC.substr(posLastDotInDomain+1, sizeDomainTLD - (posLastDotInDomain+1));
		domain = domainTLD_LC.substr(0, sizeDomainTLD  - tld.size() - 1);

		// detect domain or document
		if(tlds.size() == 0) {
			THROW_EXCEPTION(network::HttpUrlParserTLDCacheException);
		}
		bool extensionIsTLD = std::find(tlds.begin(),tlds.end(),tld) != tlds.end();
		if(extensionIsTLD && domain.length() > 0)
			typeDomain = DOMAIN;

		if(typeDomain != DOMAIN){
			typeDomain = DOCUMENT; }
	}
	// domain/document/folder has NO extension
	else {
		typeDomain = DOCUMENT;
	}

	if(typeDomain == DOCUMENT){
		// careful if it is document/path => respect case sensitivity
		if(posLastDotInDomain != std::string::npos) {
			tld    = domainTLD_CS.substr(posLastDotInDomain, sizeDomainTLD);
			domain = domainTLD_CS.substr(0, posLastDotInDomain); }
		else {
			domain = domainTLD_CS; }
	}

	return (typeDomain != UNKNOWN);
}

void HttpUrlParser::NormalizePath(const std::string& pathIn, std::string& pathNormalized) {

	pathNormalized = pathIn;

	//normalize path...
	char* pszPathNormalized = new char[pathNormalized.length() + 1];
	memset(pszPathNormalized,0,pathNormalized.length() + 1);
	strcpy(pszPathNormalized,pathNormalized.c_str());
	if(!xmlNormalizeURIPath(pszPathNormalized))
		pathNormalized = pszPathNormalized;
	delete [] pszPathNormalized;

	//canonize path...
	xmlChar* canonicPath = xmlCanonicPath((xmlChar*)pathNormalized.c_str());
	if(canonicPath){
		pathNormalized = (char*)canonicPath;
		xmlFree(canonicPath);}
}

}
