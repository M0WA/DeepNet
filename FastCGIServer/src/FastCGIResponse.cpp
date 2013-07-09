/**
 * @file FastCGIResponse.cpp
 * @author Moritz Wagner
 * @date 16.03.2012
 */

#include "FastCGIResponse.h"

#include <Logging.h>

namespace fastcgiserver {

FastCGIResponse::FastCGIResponse(FastCGIRequest* fcgiRequest)
: fcgiRequest(fcgiRequest)
{
}

FastCGIResponse::~FastCGIResponse() {
}

bool FastCGIResponse::Process(FCGX_Request& request)
{
	std::string responseText = ToString();
	bool success =( FCGX_FPrintF(request.out, "%s", responseText.c_str()) != -1 );

	log::Logging::LogTrace("fastcgi query response completed %s",( success ? "successfully" : "with errors"));
	log::Logging::LogTrace("raw response:\n %s",responseText.c_str());

	return success;
}

}
