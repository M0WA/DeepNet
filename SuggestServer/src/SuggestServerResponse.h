/*
 * SuggestServerResponse.h
 *
 *  Created on: 12.06.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <DatabaseLayer.h>

#include <FastCGIResponse.h>
#include "SuggestServerRequest.h"

namespace suggestserver {

class SuggestServerResponse : public fastcgiserver::FastCGIResponse {
public:
	SuggestServerResponse(database::DatabaseHelper& dbHelper, SuggestServerRequest* request);
	virtual ~SuggestServerResponse();

public:
	virtual bool Process(FCGX_Request& request);

private:
	SuggestServerRequest* suggestRequest;
	database::DatabaseHelper& dbHelper;
};

}
