/*
 * @file SyncServerRequest.h
 * @date Nov 27, 2017
 * @author Moritz Wagner
 */

#pragma once

#include <FastCGIRequest.h>

namespace syncserver {

class SyncServerRequest: public fastcgiserver::FastCGIRequest {
public:
	SyncServerRequest(fastcgiserver::FastCGIServerThread* serverThread);
	virtual ~SyncServerRequest();

public:
	virtual void OnHandle(FCGX_Request& request);
};

}
