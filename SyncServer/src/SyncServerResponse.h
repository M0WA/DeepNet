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
 *       <response>
 *   	    <crawlerid>1</crawlerid>
 *   	    <token>mytoken</token>
 *       </response>
 *     </xml>
 *
 * example "get_url_ids" response
 *
 *     <xml>
 *       <response>
 *   	    <urlid>1</urlid>
 *   	    <urlid>2</urlid>
 *   	    <urlid>5</urlid>
 *       </response>
 *     </xml>
 *
 * example "release_crawler_id" response
 *
 *     <xml><response></response></xml>
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
