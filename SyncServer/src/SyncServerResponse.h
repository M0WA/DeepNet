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
 *     <?xml version="1.0"?>
 *       <response>
 *   	    <crawlerid>1</crawlerid>
 *   	    <token>mytoken</token>
 *       </response>
 *
 * example "get_url_ids" response
 *
 *     <?xml version="1.0"?>
 *       <response>
 *          <secondleveldomain>5</secondleveldomain>
 *          <urls>
 *   	      <urlid>1</urlid>
 *   	      <urlid>2</urlid>
 *   	      <urlid>5</urlid>
 *   	    </urls>
 *       </response>
 *
 * example "release_crawler_id" response
 *
 *     <?xml version="1.0"?>
 *       <response></response>
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
