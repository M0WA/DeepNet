/**
 *
 * @file UnitTestHttpClientCURL.cpp
 * @author Moritz Wagner
 * @date May 31, 2013
 *
 * TODO: description for this file
 *
 */

#include "UnitTestHttpClientCURL.h"

#include <HttpClientCURL.h>
#include <HttpClientFactory.h>
#include <HttpResponse.h>
#include <FileTools.h>
#include <HttpUrlParser.h>
#include <Exception.h>
#include <Logging.h>

namespace toolbot {

UnitTestHttpClientCURL::UnitTestHttpClientCURL(const std::string& get,const std::string& post)
: get(get)
, post(post){
}

UnitTestHttpClientCURL::~UnitTestHttpClientCURL() {
}

bool UnitTestHttpClientCURL::Run() {

	tools::Pointer<network::IHttpClient> client;
	if(!network::HttpClientFactory::CreateInstance(network::HttpClientFactory::CURL,client)) {
		log::Logging::LogError("Could not create CURL HttpClient");
		return false; }

	network::IHttpClient* clientPtr(client.Get());
	if(	clientPtr == 0) {
		log::Logging::LogError("IHttpClient is empty, client could not be created");
		return false; }

	if(!get.empty()) {

		std::vector<network::HttpUrl> getUrls;
		if(!ReadURLFile(get, getUrls)) {
			log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"could not open/read get-file: " + get);
			return false; }

		std::vector<network::HttpUrl>::const_iterator i = getUrls.begin();
		for(;i != getUrls.end(); ++i) {
			network::HttpResponse response;
			if(!clientPtr->Get(*i,response)) {
				log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"could not get url: " + i->GetFullUrl());
				return false; }
		}
	}

	if(!post.empty()) {
		std::vector<network::HttpUrl> postUrls;
		if(!ReadURLFile(post,postUrls)) {
			log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"could not open/read post-file: " + post);
			return false; }
	}

	return true;
}

bool UnitTestHttpClientCURL::ReadURLFile(const std::string& urlFileName, std::vector<network::HttpUrl>& testUrls) {

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

}
