/**
 *
 * @file HttpClientSettings.cpp
 * @author Moritz Wagner
 * @date 15.05.2013
 *
 */

#include "HttpClientSettings.h"

namespace network {

HttpClientSettings::HttpClientSettings()
: userAgent("DeepNet v1.0")
, secondsTimeoutConnect(5)
, secondsTimeoutConnection(15)
, allowIPv6(false)
, uploadLimitKB(300)
, downloadLimitKB(300)
, maxSize(0){
}

HttpClientSettings::~HttpClientSettings() {
}

}
