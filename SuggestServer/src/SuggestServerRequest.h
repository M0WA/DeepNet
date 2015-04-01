/*
 * SuggestServerRequest.h
 *
 *  Created on: 12.06.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <FastCGIRequest.h>
#include <list>
#include <string>

namespace suggestserver {

class SuggestServerRequest : public fastcgiserver::FastCGIRequest {
public:
	SuggestServerRequest(fastcgiserver::FastCGIServerThread* serverThread);
	virtual ~SuggestServerRequest();

public:
	virtual void OnHandle(FCGX_Request& request);

	const std::list<std::string>& QueryParts() { queryParts.sort(); queryParts.unique(); return queryParts; };

private:
	std::list<std::string> queryParts;
};

}
