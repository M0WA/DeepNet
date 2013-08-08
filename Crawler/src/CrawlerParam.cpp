/**
 *
 * @file CrawlerParam.cpp
 * @author Moritz Wagner
 * @date 30.06.2013
 *
 */

#include "CrawlerParam.h"

namespace crawler {

CrawlerParam::CrawlerParam()
: threadCount(8)
, waitOnIdle(25)
, minAge(30)
, maxPerSelect(20)
, userAgent("Mozilla/5.0 (Windows NT 6.2; rv:9.0.1) Gecko/20100101 Firefox/9.0.1")
, connectTimeout(8)
, connectionTimeout(15)
, maxDownloadSize(0)
, useIPv6(false)
, speedLimitKB(300)
, respectRobotsTxt(false)
, databaseConfig(0)
, clientType(network::HttpClientFactory::CURL)
{
}

CrawlerParam::~CrawlerParam() {
}

}
