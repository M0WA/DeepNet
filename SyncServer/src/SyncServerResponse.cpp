/*
 * @file SyncServerResponse.cpp
 * @date Nov 27, 2017
 * @author Moritz Wagner
 */

#include "SyncServerResponse.h"

namespace syncserver {

SyncServerResponse::SyncServerResponse(database::DatabaseHelper& dbHelper,SyncServerRequest* request)
: fastcgiserver::FastCGIResponse(request) {
}

SyncServerResponse::~SyncServerResponse() {
}

}
