/*
 * InspectorServerResponse.h
 *
 *  Created on: 06.05.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <FastCGIResponse.h>

namespace database {
	class DatabaseHelper;
}

namespace inspectorserver {

class InspectorServerRequest;
class InspectorServerResponse : public fastcgiserver::FastCGIResponse {
public:
	InspectorServerResponse(database::DatabaseHelper& dbHelper, InspectorServerRequest* request);
	virtual ~InspectorServerResponse();

public:
	virtual bool Process(FCGX_Request& request);

private:
	database::DatabaseHelper& DB() { return dbHelper; }

private:
	InspectorServerRequest* inspectorRequest;
	database::DatabaseHelper& dbHelper;
};

}
