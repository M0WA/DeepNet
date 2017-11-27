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

class SyncServerResponse: public fastcgiserver::FastCGIResponse {
public:
	SyncServerResponse(database::DatabaseHelper& dbHelper,SyncServerRequest* request);
	virtual ~SyncServerResponse();
};

}
