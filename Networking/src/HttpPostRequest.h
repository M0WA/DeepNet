/*
 * HttpPostRequest.h
 *
 *  Created on: Dec 21, 2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>

#include "HttpRequest.h"

namespace network {

class HttpUrl;
class HttpPostRequest: public network::HttpRequest {
public:
	HttpPostRequest(const HttpUrl& url);
	virtual ~HttpPostRequest();

public:
	virtual void ToString(std::string& out) const;
};

}
