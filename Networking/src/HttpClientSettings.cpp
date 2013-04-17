/*
 * HttpClientSettings.cpp
 *
 *  Created on: Feb 4, 2013
 *      Author: Moritz Wagner
 */

#include "HttpClientSettings.h"

namespace network {

HttpClientSettings::HttpClientSettings()
: allowKeepAlive(true)
, enableCompression(true)
, followRedirects(5)
, uploadLimit(0)
, downloadLimit(0){
	connectTimeout.tv_sec  = readTimeout.tv_sec  = 10;
	connectTimeout.tv_usec = readTimeout.tv_usec = 0;
}

HttpClientSettings::~HttpClientSettings() {
}

}
