/*
 * HttpGetRequest.h
 *
 *  Created on: Dec 21, 2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>

#include "HttpRequest.h"

namespace network {

class HttpGetRequest: public HttpRequest {
public:
	HttpGetRequest(const HttpUrl& url);
	virtual ~HttpGetRequest();

public:
	virtual void ToString(std::string& out) const;
};

}
