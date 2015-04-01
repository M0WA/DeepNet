/*
 * InspectorServerRequest.h
 *
 *  Created on: 06.05.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <FastCGIRequest.h>

#include <list>
#include <string>
#include <SpellChecking.h>

namespace inspectorserver {

class InspectorServerRequest : public fastcgiserver::FastCGIRequest {
public:
	InspectorServerRequest(fastcgiserver::FastCGIServerThread* serverThread);
	virtual ~InspectorServerRequest();

public:
	virtual void OnHandle(FCGX_Request& request);

	const std::list<std::string>& HtmlCodes(void) const {return htmlCodes;}

private:
	std::list<std::string> htmlCodes;
};

}
