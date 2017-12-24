/**
 *
 * @file HttpResponse.cpp
 * @author Moritz Wagner
 * @date 15.05.2013
 *
 */

#include "HttpResponse.h"
#include <TimeTools.h>

namespace network {

HttpResponse::HttpResponse()
: httpResponseCode()
, contentLength(-1)
, downloadSpeed(0.0)
, uploadSpeed(0.0)
, totalTime(0.0)
, dnsLookupTime(0.0)
, connectTime(0.0)
, primaryPort(0)
{
	tools::TimeTools::InitTm(fileTimestamp);
}

HttpResponse::~HttpResponse() {
}

}
