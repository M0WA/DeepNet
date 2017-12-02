/*
 * @file SyncServerRequest.cpp
 * @date Nov 27, 2017
 * @author Moritz Wagner
 */

#include "SyncServerRequest.h"

#include "SyncServerThread.h"

#include <GetUrlsThread.h>
#include <ReleaseCrawlerThread.h>

#include <Logging.h>
#include <HashTools.h>

namespace syncserver {

SyncServerRequest::SyncServerRequest(fastcgiserver::FastCGIServerThread* serverThread)
: fastcgiserver::FastCGIRequest(serverThread)
, mode(SYNC_REQ_MODE_MAX)
, crawlerID(-1)
, authenticated(false)
, threadID(0) {
}

SyncServerRequest::~SyncServerRequest() {
}

void SyncServerRequest::OnHandle(FCGX_Request& request)
{
	if(rawPostData==0) {
		log::Logging::LogWarn("no post data received, ommitting...");
		return;	}

    std::list<std::string> mode;
	if( !Xpath(mode, rawPostData, (xmlChar*)"/request/mode/text()")) {
		log::Logging::LogError("could not parse xml crawler request: missing mode");
		return; }

	if(!mode.size()) {
		log::Logging::LogError("could not parse xml crawler request: wrong mode");
		return; }

	if(mode.front().compare("auth") == 0) {
		Authenticate();
	}
	else if(mode.front().compare("get_url_ids") == 0) {
		GetUrls();
	}
	else if(mode.front().compare("release_crawler_id") == 0) {
		ReleaseCrawlerId();
	}
	else {
		log::Logging::LogError("could not parse xml crawler request: invalid mode %s",mode.front().c_str());
		return; }
}

bool SyncServerRequest::SetCrawlerID() {

    std::list<std::string> crawlerid;
	if( !Xpath(crawlerid, rawPostData, (xmlChar*)"/request/crawlerid/text()")) {
		log::Logging::LogError("could not parse xml crawler request: missing crawler id");
		return false; }

	if(!crawlerid.size()) {
		log::Logging::LogError("could not parse xml crawler request: wrong crawler id");
		return false; }

	if(!tools::StringTools::TransformString(crawlerid.front(),crawlerID)) {
		crawlerID = -1;
		authenticated = false;
		return false; }

	return true;
}

bool SyncServerRequest::CheckToken() {

	authenticated = false;

    std::list<std::string> token;
	if( !Xpath(token, rawPostData, (xmlChar*)"/request/token/text()")) {
		log::Logging::LogError("could not parse xml crawler request: missing token");
		return false; }

	if(!token.size()) {
		log::Logging::LogError("could not parse xml crawler request: wrong token");
		return false; }

	std::string input(tools::StringTools::TransformString(crawlerID));
	auth_token = tools::HashTools::GetSHA512(input);

	if(auth_token.compare(token.front()) != 0) {
		auth_token = "";
		return false; }

	return true;
}

bool SyncServerRequest::Authenticate() {

	authenticated = false;

	if(!SetCrawlerID()) {
		return false; }

    std::list<std::string> pass;
	if( !Xpath(pass, rawPostData, (xmlChar*)"/request/pass/text()")) {
		log::Logging::LogError("could not parse xml crawler request: missing pass");
		return false; }

	if(!pass.size()) {
		log::Logging::LogError("could not parse xml crawler request: wrong pass");
		return false; }

	//TODO: do not hardcode password
	const char* password = "syncclient";
	if(pass.front().compare(password) != 0) {
		return false; }

	std::string input(tools::StringTools::TransformString(crawlerID));
	auth_token = tools::HashTools::GetSHA512(input);

	//TODO: set crawlerID correctly
	crawlerID = -1;

	return true;
}

bool SyncServerRequest::GetUrls() {

	if(!SetCrawlerID()) {
		return false; }

	if(!CheckToken()) {
		return false; }


	syncing::GetUrlsThread::GetUrlsThreadParam* p(new syncing::GetUrlsThread::GetUrlsThreadParam());
	p->crawlerID = crawlerID;

	p->urlCount = 1;
    std::list<std::string> cnt;
	if( Xpath(cnt, rawPostData, (xmlChar*)"/request/count/text()") && cnt.size() ) {
		if( !tools::StringTools::TransformString(cnt.front(),p->urlCount) ) {
			p->urlCount = 1;
		}
	}

	p->secondlevelDomain = -1;
    std::list<std::string> sld;
	if( Xpath(sld, rawPostData, (xmlChar*)"/request/secondleveldomain/text()") && sld.size() ) {
		if( !tools::StringTools::TransformString(sld.front(),p->secondlevelDomain) ) {
			p->secondlevelDomain = -1;
		}
	}

	p->dbConn = ServerThread()->DB().CreateConnection(dynamic_cast<SyncServerThread*>(ServerThread())->databaseConfig);
	threadID = manager.AddThread(new syncing::GetUrlsThread(),p);
	return true;
}

bool SyncServerRequest::ReleaseCrawlerId() {

	if(!SetCrawlerID()) {
		return false; }

	if(!CheckToken()) {
		return false; }

	database::DatabaseConnection* dbCon(ServerThread()->DB().CreateConnection(dynamic_cast<SyncServerThread*>(ServerThread())->databaseConfig));
	threadID = manager.AddThread(new syncing::ReleaseCrawlerThread(dbCon),this);
	return true;
}

}
