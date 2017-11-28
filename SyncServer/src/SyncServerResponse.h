/*
 * @file SyncServerResponse.h
 * @date Nov 27, 2017
 * @author Moritz Wagner
 */

#pragma once

#include <FastCGIResponse.h>

#include "SyncServerRequest.h"

namespace database {
	class DatabaseHelper;
}

namespace syncserver {

/**
 * @brief response to a single request from a client for the SyncServer service
 * @details
 * example "auth" response
 *
 *     <xml>
 *       <request>
 *   	    <token>mytoken</token>
 *       </request>
 *     </xml>
 *
 * TBD: example "get_url_ids" response
 *
 * example "release_crawler_id" response
 *
 *     <xml></xml>
 */
class SyncServerResponse: public fastcgiserver::FastCGIResponse {
public:
	SyncServerResponse(database::DatabaseHelper& dbHelper,SyncServerRequest* request);
	virtual ~SyncServerResponse();

private:
	virtual bool Process(FCGX_Request& request);

private:
	bool Authenticate();
	bool GetUrls();
	bool ReleaseCrawler();
};

}
