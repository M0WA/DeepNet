/*
 * @file SyncClient.cpp
 * @date Dec 2, 2017
 * @author Moritz Wagner
 */

#include "SyncClient.h"

#include <sstream>

#include <HttpUrl.h>
#include <HttpClientFactory.h>
#include <IHttpClient.h>
#include <HttpResponse.h>
#include <HttpUrlParser.h>
#include <HttpUrlParserInvalidUrlException.h>

#include <Pointer.h>
#include <Exception.h>
#include <Logging.h>
#include <XML.h>

namespace syncing {

SyncClient::SyncClient(const std::string& apiUrl,const long long& crawlerID, const std::string& pass)
: apiUrl(apiUrl)
, crawlerID(crawlerID)
, pass(pass)
, token() {
}

SyncClient::~SyncClient() {
	if(crawlerID != -1) {
		ReleaseCrawler();
		crawlerID = -1;
		token.clear();
	}
}

bool SyncClient::ReleaseCrawler() {

	if(crawlerID < 0) {
		return false;
	}

	if(token.empty()) {
		log::Logging::LogWarn("SyncClient::ReleaseCrawler: invalid token");
		return false;
	}

	std::ostringstream ss;
	ss <<
		"<?xml version=\"1.0\"?>\n"
		"  <request>\n"
		"    <mode>release_crawler_id</mode>\n"
		"    <crawlerid>"<< crawlerID <<"</crawlerid>\n"
	    "    <token>"<< token <<"</token>\n"
		"  </request>";

	std::string xmlResponse;
	bool success(DoRequest(ss.str(),xmlResponse));

	crawlerID = -1;
	token.clear();
	return success;
}

bool SyncClient::RegisterCrawler(const std::string& pass) {
	std::ostringstream ss;
	ss <<
		"<?xml version=\"1.0\"?>\n"
		"  <request>\n"
		"    <mode>auth</mode>\n"
		"    <pass>"<< pass <<"</pass>\n"
		"  </request>";

	std::string xmlResponse;
	if(!DoRequest(ss.str(),xmlResponse)) {
		crawlerID = -1;
		token.clear();
		return false;
	}

	tools::XML doc(xmlResponse);
	if(!doc.XPathFirst("/response/crawlerid/text()",crawlerID)) {
		log::Logging::LogWarn("could not find /response/crawlerID:\n%s",xmlResponse.c_str());
		crawlerID = -1;
		token.clear();
		return false;
	}
	if(!doc.XPathFirst("/response/token/text()",token)) {
		log::Logging::LogWarn("could not find /response/token:\n%s",xmlResponse.c_str());
		crawlerID = -1;
		token.clear();
		return false;
	}

	return true;
}

bool SyncClient::GetURLs(const long long& count,long long& secondLevelDomainID, std::vector<long long>& urls) {
	urls.clear();

	if(token.empty()) {
		log::Logging::LogWarn("SyncClient::GetURLs: invalid token");
		return false;
	}

	std::ostringstream ss;
	ss <<
		"<?xml version=\"1.0\"?>\n"
		"  <request>\n"
		"    <mode>get_url_ids</mode>\n"
		"    <crawlerid>"<< crawlerID <<"</crawlerid>\n"
	    "    <token>"<< token <<"</token>\n"
		"    <secondleveldomain>"<< secondLevelDomainID <<"</secondleveldomain>\n"
		"    <count>"<< count <<"</count>\n"
		"  </request>";

	std::string xmlResponse;
	if(!DoRequest(ss.str(),xmlResponse)) {
		return false;
	}

	tools::XML doc(xmlResponse);
	if(!doc.XPath("/response/urls/urlid/text()",urls)) {
		log::Logging::LogWarn("could not find /response/urls/urlid:\n%s",xmlResponse.c_str());
		return false;
	}
	if(!doc.XPathFirst("/response/secondleveldomain/text()",secondLevelDomainID)) {
		log::Logging::LogTrace("no found /response/secondleveldomain:\n%s",xmlResponse.c_str());
		secondLevelDomainID = -1;
	}

	return true;
}

bool SyncClient::DoRequest(const std::string& xmlIn,std::string& xmlOut) {

	if(crawlerID == -1 && !RegisterCrawler(pass)) {
		log::Logging::LogWarn("could not register crawler");
		return false;
	}

	xmlOut.clear();

	tools::Pointer<network::IHttpClient> client;
	if(!network::HttpClientFactory::CreateInstance( network::HttpClientFactory::CURL, client )) {
		log::Logging::LogWarn("could not create HttpClient for SyncClient");
		return false; }

	bool success(false);
	network::IHttpClient* hc(client.Get());
	network::HttpUrl url;
	network::HttpResponse response;
	std::string xml;
	try {
		network::HttpUrlParser::ParseURL(apiUrl,url);
	}
	CATCH_EXCEPTION(network::HttpUrlParserInvalidUrlException,e,1)
		goto END_SYNC_REQUEST;
	}

	log::Logging::LogTraceUnlimited("doing POST (%s):\n%s",url.GetFullUrl().c_str(),xmlIn.c_str());

	success = hc->Post(url, xmlIn, "application/xml", response);
	if(!success) {
		log::Logging::LogWarn("error while POST (%s):\n%s",url.GetFullUrl().c_str(),xmlIn.c_str());
		goto END_SYNC_REQUEST;
	}
	else {
		xmlOut.clear();
		xmlOut.append(response.html.GetBuffer(),0,response.html.GetBufferSize());
		log::Logging::LogTraceUnlimited("result POST (%s): \nin:\n%s\n\nout:\n%s",url.GetFullUrl().c_str(),xmlIn.c_str(),xmlOut.c_str());
	}

END_SYNC_REQUEST:
	client.Release();
	return success;
}

}
