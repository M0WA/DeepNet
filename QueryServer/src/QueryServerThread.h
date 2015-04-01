/*
 * @file QueryServerThread.h
 * @date Jan 11, 2015
 * @uthor Moritz Wagner
 */

#pragma once

#include <string>

#include <FastCGIServerThread.h>

#include "QueryServerThreadConfig.h"


namespace queryserver {

/**
 * @brief encapsulates fastcgiserver::FastCGIServerThread for queryserver::QueryServer
 */
class QueryServerThread : public fastcgiserver::FastCGIServerThread {
public:
	QueryServerThread(const queryserver::QueryServerThreadConfig& config);
	virtual ~QueryServerThread();

private:
	virtual fastcgiserver::FastCGIRequest*  CreateRequest();
	virtual fastcgiserver::FastCGIResponse* CreateResponse(database::DatabaseHelper& dbHelper, fastcgiserver::FastCGIRequest* request);
	virtual const char* GetThreadName() const { return "QueryServerThread"; }

private:
	const queryserver::QueryServerThreadConfig& config;
};

}
