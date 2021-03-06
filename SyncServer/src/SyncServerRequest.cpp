/*
 * @file SyncServerRequest.cpp
 * @date Nov 27, 2017
 * @author Moritz Wagner
 */

#include "SyncServerRequest.h"

#include "SyncServerThread.h"

#include <GetUrlsThread.h>
#include <ReleaseCrawlerThread.h>
#include <RegisterCrawlerThread.h>

#include <Logging.h>
#include <HashTools.h>
#include <XML.h>


namespace syncserver {

SyncServerRequest::SyncServerRequest(fastcgiserver::FastCGIServerThread* serverThread, const std::string& crawler_sync_pass)
: fastcgiserver::FastCGIRequest(serverThread)
, mode(SYNC_REQ_MODE_MAX)
, crawlerID(-1)
, authenticated(false)
, crawler_sync_pass(crawler_sync_pass)
, threadID(0) {
}

SyncServerRequest::~SyncServerRequest() {
}

void SyncServerRequest::OnHandle(FCGX_Request& request)
{
	if(rawPostData==0) {
		log::Logging::LogInfo("no post data received, ommitting request...");
		return;	}

	tools::XML xml(rawPostData.GetConstElements());

    std::string mode;
	if( !xml.XPathFirst("/request/mode/text()", mode)) {
		log::Logging::LogInfo("could not parse xml crawler request: missing mode");
		return; }

	if(mode.compare("auth") == 0) {
		Authenticate();
	}
	else if(mode.compare("get_url_ids") == 0) {
		GetUrls();
	}
	else if(mode.compare("release_crawler_id") == 0) {
		ReleaseCrawlerId();
	}
	else {
		log::Logging::LogInfo("could not parse xml crawler request: invalid mode %s",mode.c_str());
		return; }
}

bool SyncServerRequest::SetCrawlerID() {

    std::list<std::string> crawlerid;
	if( !Xpath(crawlerid, rawPostData, (xmlChar*)"/request/crawlerid/text()")) {
		log::Logging::LogInfo("could not parse xml crawler request: missing crawler id");
		return false; }

	if(!crawlerid.size()) {
		log::Logging::LogInfo("could not parse xml crawler request: invalid crawler id");
		return false; }

	if(!tools::StringTools::TransformString(crawlerid.front(),crawlerID)) {
		crawlerID = -1;
		authenticated = false;
		log::Logging::LogInfo("could not parse xml crawler request: malformed token");
		return false; }

	return true;
}

bool SyncServerRequest::CheckToken() {

	authenticated = false;

	tools::XML xml(rawPostData.GetConstElements());

    std::string token;
	if( !xml.XPathFirst("/request/token/text()", token) ) {
		log::Logging::LogInfo("could not parse xml crawler request: missing token");
		return false; }

	auth_token = tools::HashTools::GetSHA512(crawler_sync_pass);
	if(auth_token.compare(token) != 0) {
		auth_token = "";
		log::Logging::LogInfo("could not parse xml crawler request: invalid token");
		return false; }

	return true;
}

bool SyncServerRequest::Authenticate() {

	authenticated = false;

	tools::XML xml(rawPostData.GetConstElements());

    std::string pass;
	if( !xml.XPathFirst("/request/pass/text()", pass) ) {
		log::Logging::LogInfo("could not parse xml crawler request: missing pass");
		return false; }

	if(pass.compare(crawler_sync_pass) != 0) {
		log::Logging::LogInfo("could not parse xml crawler request: invalid pass");
		return false; }

	auth_token = tools::HashTools::GetSHA512(crawler_sync_pass);
	mode = SYNC_REQ_MODE_AUTH;

	syncing::RegisterCrawlerThread::RegisterCrawlerThreadParam* p(new syncing::RegisterCrawlerThread::RegisterCrawlerThreadParam());
	p->dbConf = reinterpret_cast<SyncServerThread*>(ServerThread())->databaseConfig;
	threadID = manager.AddThread(new syncing::RegisterCrawlerThread(),p);
	return true;
}

bool SyncServerRequest::GetUrls() {

	if(!SetCrawlerID()) {
		return false; }

	if(!CheckToken()) {
		return false; }

	tools::XML xml(rawPostData.GetConstElements());

	syncing::GetUrlsThread::GetUrlsThreadParam* p(new syncing::GetUrlsThread::GetUrlsThreadParam());
	p->crawlerID = crawlerID;

	p->urlCount = 1;
	if( !xml.XPathFirst("/request/count/text()", p->urlCount) ) {
		p->urlCount = 1;
	}

	p->secondlevelDomain = -1;
	if( !xml.XPathFirst("/request/secondleveldomain/text()", p->secondlevelDomain) ) {
		p->secondlevelDomain = -1;
	}

	mode = SYNC_REQ_MODE_GET_URLS;

	p->dbConf = reinterpret_cast<SyncServerThread*>(ServerThread())->databaseConfig;
	threadID = manager.AddThread(new syncing::GetUrlsThread(),p);
	return true;
}

bool SyncServerRequest::ReleaseCrawlerId() {

	if(!SetCrawlerID()) {
		return false; }

	if(!CheckToken()) {
		return false; }

	mode = SYNC_REQ_MODE_RELEASE;

	syncing::ReleaseCrawlerThread::ReleaseCrawlerThreadParam* p(new syncing::ReleaseCrawlerThread::ReleaseCrawlerThreadParam());
	p->crawlerID = crawlerID;
	p->dbConf = reinterpret_cast<SyncServerThread*>(ServerThread())->databaseConfig;

	threadID = manager.AddThread(new syncing::ReleaseCrawlerThread(),p);
	return true;
}

}
