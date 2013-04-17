/*
 * HttpRequestResult.cpp
 *
 *  Created on: Feb 4, 2013
 *      Author: Moritz Wagner
 */

#include "HttpRequestResult.h"

#include <sstream>

#include <TimeTools.h>

namespace network {

HttpRequestResult::HttpRequestResult( )
: success(false)
, redirectedCount(0)
, writtenBytes(0)
, httpStatusCode(-1){
	tools::TimeTools::InitTimeval(dnsTime);
	tools::TimeTools::InitTimeval(connectTime);
	tools::TimeTools::InitTimeval(readTime);
	tools::TimeTools::InitTimeval(writeTime);
	tools::TimeTools::InitTm(lastModified);
}

HttpRequestResult::~HttpRequestResult() {
}

void HttpRequestResult::ToString(std::string& in) const {

	in.clear();

	/*
	std::string htmlContent;
	htmlContent.append(htmlData.GetBuffer(),htmlData.GetBufferSize());
	*/
	std::string httpHeader;
	effectiveHeader.ToString(httpHeader);

	std::ostringstream oss;
	oss << "url:     " << effectiveUrl.GetFullUrl() << std::endl
		<< "connect: " << tools::TimeTools::TimevalToString(connectTime) << std::endl
		<< "read:    " << tools::TimeTools::TimevalToString(readTime)    << std::endl
		<< "htmlSize:" << htmlData.GetBufferSize() << std::endl
		<< "header:  " << std::endl
		<< httpHeader << std::endl
		/*
		<< "=================================================" << std::endl << std::endl
		<< "html:    " << std::endl
		<< "=================================================" << std::endl << std::endl
		<< htmlContent << std::endl
		<< "=================================================" << std::endl << std::endl
		*/
		;

	in = oss.str();
}

}
