/*
 * @file SyncServerResponse.cpp
 * @date Nov 27, 2017
 * @author Moritz Wagner
 */

#include "SyncServerResponse.h"

#include "SyncServerRequest.h"

#include <GetUrlsThread.h>
#include <RegisterCrawlerThread.h>
#include <ReleaseCrawlerThread.h>

#include <Logging.h>
#include <ThreadManager.h>

#include <sstream>

namespace syncserver {

SyncServerResponse::SyncServerResponse(database::DatabaseHelper& dbHelper,SyncServerRequest* request)
: fastcgiserver::FastCGIResponse(request) {
}

SyncServerResponse::~SyncServerResponse() {
}

bool SyncServerResponse::Authenticate() {
	SyncServerRequest* req(dynamic_cast<SyncServerRequest*>(fcgiRequest));

	threading::ThreadManager<threading::Thread>& tm(req->GetThreadManager());
	tm.WaitForAll();

	threading::ThreadManager<threading::Thread>::ThreadInfos ti(tm.GetThreadInfosByID(req->GetThreadID()));
	syncing::RegisterCrawlerThread* t(dynamic_cast<syncing::RegisterCrawlerThread*>(ti.first));

	std::ostringstream xmlResult;
	xmlResult <<
		"<?xml version=\"1.0\"?>\n"
		"  <response>\n"
		"    <crawlerid>" << t->GetCrawlerID() << "</crawlerid>\n"
		"    <token>"     << req->GetToken()   << "</token>\n"
		"  </response>\n"
		"</xml>";
	content = xmlResult.str();
	return true;
}

bool SyncServerResponse::GetUrls() {

	SyncServerRequest* req(dynamic_cast<SyncServerRequest*>(fcgiRequest));

	threading::ThreadManager<threading::Thread>& tm(req->GetThreadManager());
	tm.WaitForAll();

	threading::ThreadManager<threading::Thread>::ThreadInfos ti(tm.GetThreadInfosByID(req->GetThreadID()));
	syncing::GetUrlsThread* t(dynamic_cast<syncing::GetUrlsThread*>(ti.first));
	const std::vector<long long>& urlIDs(t->GetUrlIDs());

	std::vector<long long>::const_iterator i(urlIDs.begin());

	std::ostringstream xmlResult;
	xmlResult <<
		"<?xml version=\"1.0\"?>\n"
		"  <response>\n";
	    "    <urls>\n";
	for(;i != urlIDs.end();++i) {
		xmlResult <<
		"      <urlid>" << *i << "</urlid>\n";
	}
	xmlResult <<
		"    </urls>\n";
		"  </response>\n"
		"</xml>";

	tm.ReleaseAll();
	content = xmlResult.str();
	return true;
}

bool SyncServerResponse::ReleaseCrawler() {

	SyncServerRequest* req(dynamic_cast<SyncServerRequest*>(fcgiRequest));

	threading::ThreadManager<threading::Thread>& tm(req->GetThreadManager());
	tm.WaitForAll();
	tm.ReleaseAll();

	std::ostringstream xmlResult;
	xmlResult <<
		"<?xml version=\"1.0\"?><response></response></xml>";
	content = xmlResult.str();
	return true;
}

bool SyncServerResponse::Process(FCGX_Request& request) {
	bool success(false);
	const SyncServerRequest* req(dynamic_cast<const SyncServerRequest*>(fcgiRequest));
	switch(req->GetMode()) {
	case SyncServerRequest::SYNC_REQ_MODE_AUTH:
		success = Authenticate();
		break;
	case SyncServerRequest::SYNC_REQ_MODE_GET_URLS:
		success = GetUrls();
		break;
	case SyncServerRequest::SYNC_REQ_MODE_RELEASE:
		success = ReleaseCrawler();
		break;
	default:
		log::Logging::LogError("could not parse xml crawler response: invalid mode");
		break;

	}

	success &= fastcgiserver::FastCGIResponse::Process(request);
	return success;
}

}
