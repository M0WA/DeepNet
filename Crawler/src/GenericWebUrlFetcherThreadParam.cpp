/**
 *
 * @file GenericWebUrlFetcherThreadParam.cpp
 * @author Moritz Wagner
 * @date 30.06.2013
 *
 */

#include "GenericWebUrlFetcherThreadParam.h"

namespace crawler {

GenericWebUrlFetcherThreadParam::GenericWebUrlFetcherThreadParam(const CrawlerParam& crawlerParam)
: UrlFetcherThreadParam(crawlerParam){
}

GenericWebUrlFetcherThreadParam::~GenericWebUrlFetcherThreadParam() {
}

}
