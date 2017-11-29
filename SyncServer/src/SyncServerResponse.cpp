/*
 * @file SyncServerResponse.cpp
 * @date Nov 27, 2017
 * @author Moritz Wagner
 */

#include "SyncServerResponse.h"

#include "SyncServerRequest.h"

#include <Logging.h>
#include <sstream>

namespace syncserver {

SyncServerResponse::SyncServerResponse(database::DatabaseHelper& dbHelper,SyncServerRequest* request)
: fastcgiserver::FastCGIResponse(request) {
}

SyncServerResponse::~SyncServerResponse() {
}

bool SyncServerResponse::Authenticate() {
	const SyncServerRequest* req(reinterpret_cast<const SyncServerRequest*>(fcgiRequest));
	std::ostringstream xmlResult;
	xmlResult <<
		"<?xml version=\"1.0\"?>\n"
		"  <response>\n"
		"    <token>" << req->GetToken() << "</token>\n"
		"  </response>\n"
		"</xml>";
	content = xmlResult.str();
	return true;
}

bool SyncServerResponse::GetUrls() {

	//TODO: get urls

	return false;
}

bool SyncServerResponse::ReleaseCrawler() {

	//TODO: really release crawler id

	std::ostringstream xmlResult;
	xmlResult <<
		"<?xml version=\"1.0\"?></xml>";
	content = xmlResult.str();
	return true;
}

bool SyncServerResponse::Process(FCGX_Request& request) {
	bool success(false);
	const SyncServerRequest* req(reinterpret_cast<const SyncServerRequest*>(fcgiRequest));
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
	return success;
}

}
