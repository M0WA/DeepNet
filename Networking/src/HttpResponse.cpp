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
{
	tools::TimeTools::InitTm(fileTimestamp);
}

HttpResponse::~HttpResponse() {
}

}
