/*
 * UnitTestHttpClient.cpp
 *
 *  Created on: Dec 22, 2012
 *      Author: Moritz Wagner
 */

#include "UnitTestHttpClient.h"

#include <Logging.h>
#include <Exception.h>
#include <FileTools.h>

#include <HttpUrlParser.h>
#include <HttpUrl.h>

namespace toolbot {

UnitTestHttpClient::UnitTestHttpClient() {
}

UnitTestHttpClient::~UnitTestHttpClient() {
}

bool UnitTestHttpClient::Test(const std::string& urlGet,const std::string& urlPost) {

	std::vector<network::HttpUrl> get,post;

	if(!urlGet.empty())
		ReadURLFile(urlGet, get);

	if(!urlPost.empty())
		ReadURLFile(urlPost, post);

	bool success = true;

	std::vector<network::HttpUrl>::const_iterator iterGet = get.begin();
	for(;iterGet != get.end();++iterGet) {
		success &= TestGet(*iterGet); }

	std::vector<network::HttpUrl>::const_iterator iterPost = post.begin();
	for(;iterPost != post.end();++iterPost) {
		success &= TestPost(*iterPost); }

	return success;
}

bool UnitTestHttpClient::TestPost(const network::HttpUrl& url) {

	/*
	network::HttpClientEx client;
	network::HttpRequestResult result = client.Post(url);
	if(!ProcessResponse(result))
		return false;

	client.GetSettings().SetCompression(true);
	result = client.Get(url);
	if(!ProcessResponse(result))
		return false;
	*/

	return true;
}

bool UnitTestHttpClient::TestGet(const network::HttpUrl& url) {

	network::HttpClientEx client;
	client.GetSettings().SetUserAgent("Mozilla/5.0 (Windows NT 6.1; WOW64; rv:18.0) Gecko/20100101 Firefox/18.0");
	client.GetSettings().SetCompression(false);
	network::HttpRequestResult result;
	client.Get(url,result);
	if(!ProcessResponse(result))
		return false;

	client.GetSettings().SetUserAgent("Mozilla/5.0 (Windows NT 6.1; WOW64; rv:18.0) Gecko/20100101 Firefox/18.0");
	client.GetSettings().SetCompression(true);
	client.Get(url,result);
	if(!ProcessResponse(result))
		return false;

	return true;
}

bool UnitTestHttpClient::ReadURLFile(const std::string& urlFileName, std::vector<network::HttpUrl>& testUrls) {

	std::vector<std::string> lines;
	bool bSuccessReadFile = tools::FileTools::ReadFile(urlFileName,lines);
	if(!bSuccessReadFile)
		return false;

	std::vector<std::string>::iterator iterLines = lines.begin();
	for(int line=1;iterLines != lines.end();++iterLines,line++) {
		network::HttpUrl insertUrl;
		try {
			network::HttpUrlParser::ParseURL(*iterLines,insertUrl);
			testUrls.push_back(insertUrl);
		}
		catch(errors::Exception& e) {
			e.DisableLogging();
		}
		catch(...) {

		}
	}

	return testUrls.size() > 0;
}

bool UnitTestHttpClient::ProcessResponse(const network::HttpRequestResult& response) {

	if(!response.success || log::Logging::IsLogLevelTrace()) {
		std::string responseComplete;
		response.ToString(responseComplete);

		int oldLen = log::Logging::GetMaxLogLength();
		log::Logging::SetMaxLogLength(responseComplete.length());
		log::Logging::Log(log::Logging::LOGLEVEL_TRACE,"\r\n%s",responseComplete.c_str());
		log::Logging::SetMaxLogLength(oldLen);
	}

	if(!response.success) {
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"invalid response received, request was not successful: %s",
			response.effectiveUrl.GetFullUrl().c_str());
	}

	return response.success;
}

}
