/*
 * UnitTestUrlParser.cpp
 *
 *  Created on: 24.08.2012
 *      Author: Moritz Wagner
 */

#include "UnitTestUrlParser.h"

#include <iostream>


#include <DatabaseUrl.h>
#include <HttpUrlParser.h>
#include <Exception.h>
#include <Logging.h>
#include <PerformanceCounter.h>
#include <Regex.h>
#include <TLD.h>

#include "UnitTestCacheUrl.h"

namespace toolbot {

UnitTestUrlParser::UnitTestUrlParser(database::DatabaseConnection* connection,
		const std::string& validUrlFileName,
		const std::string& invalidUrlFileName)
: connection(connection)
, validUrlFileName(validUrlFileName)
, invalidUrlFileName(invalidUrlFileName)
, testUrls(testUrls)
{
}

UnitTestUrlParser::~UnitTestUrlParser() {
}

bool UnitTestUrlParser::Run() {

	bool success = true;

	if(!invalidUrlFileName.empty())
		success &= TestInvalidUrls(connection, invalidUrlFileName);

	if(!validUrlFileName.empty())
		success &= TestValidUrls(validUrlFileName);

	return success;
}

bool UnitTestUrlParser::TestValidUrls(const std::string& urlFileName) {

	if(!UnitTestUrl::ReadValidURLFile(urlFileName, testUrls)){
		return false; }

	PERFORMANCE_LOG_START;

	bool success = true;
	std::vector<UnitTestUrl>::iterator iterTestUrl = testUrls.begin();
	for(;iterTestUrl != testUrls.end(); ++iterTestUrl) {

		UnitTestUrl& curTestUrl = *iterTestUrl;

		//enable to debug certain urls by line in file
		//just set line number and a break point here
		//if(curTestUrl.line == 60) {
		//	std::cout << std::endl;
		//}

		if(!curTestUrl.baseUrl.empty()) {
			try {
				network::HttpUrlParser::ParseURL(curTestUrl.baseUrl, curTestUrl.base);
				curTestUrl.base.CalculateFullUrl(connection);
			}
			catch(errors::Exception& e) {
				UnitTestUrlParser::OnError("error while parsing urlBase:\n" + e.Dump(),curTestUrl);
				success = false;
				continue;
			}
		}
		std::string baseUrlDump = curTestUrl.base.Dump();

		try {
			network::HttpUrlParser::ParseURL(curTestUrl.base,curTestUrl.theUrl, curTestUrl.url);
			curTestUrl.url.CalculateFullUrl(connection);
			network::HttpUrlParser::ParseURL(curTestUrl.base,curTestUrl.url.GetFullUrl(), curTestUrl.reverse);
			curTestUrl.reverse.CalculateFullUrl(connection);
		}
		catch(errors::Exception& e) {
			UnitTestUrlParser::OnError("error while parsing url:\n" + e.Dump(),curTestUrl);
			success = false;
			continue;
		}
		std::string curUrlDump = curTestUrl.url.Dump();
		std::string curReverseUrlDump = curTestUrl.reverse.Dump();

		try {
			network::HttpUrlParser::ParseURL(curTestUrl.resultUrl, curTestUrl.result);
			curTestUrl.result.CalculateFullUrl(connection);
		}
		catch(errors::Exception& e) {
			UnitTestUrlParser::OnError("error while parsing result url:\n" + e.Dump(),curTestUrl);
			success = false;
			continue;
		}
		std::string resultUrlDump = curTestUrl.result.Dump();

		std::string dumpAll =
			"\n\n dump theUrl:\n"   +curUrlDump+
			"\n\n dump resultUrl:\n"+resultUrlDump+
			"\n\n dump baseUrl:\n"  +baseUrlDump+
			"\n\n dump revUrl:\n"   +curReverseUrlDump;

		if(!curTestUrl.url.DeepMatchUrl(curTestUrl.result)) {
			UnitTestUrlParser::OnError("not matching theUrl + resultUrl" + dumpAll,curTestUrl);
			success = false;
			continue;
		}

		if(!curTestUrl.url.DeepMatchUrl(curTestUrl.reverse)) {
			UnitTestUrlParser::OnError("not matching theUrl + reverseUrl" + dumpAll,curTestUrl);
			success = false;
			continue;
		}

		if(!curTestUrl.result.DeepMatchUrl(curTestUrl.reverse)) {
			UnitTestUrlParser::OnError("not matching resultUrl + reverseUrl" + dumpAll,curTestUrl);
			success = false;
			continue;
		}

		if(log::Logging::IsLogLevelTrace())
			log::Logging::Log(log::Logging::LOGLEVEL_TRACE,"line %d: OK => %s", curTestUrl.line, curTestUrl.result.GetFullUrl().c_str());
	}


	if(!success){
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"\n\n !!! URL PARSER UNIT-TEST FAILED (VALID URL TEST) !!! \n");
	}
	else {
		std::stringstream msgPerf;
		msgPerf << "parsed " << testUrls.size() << " urls";
		PERFORMANCE_LOG_STOP(msgPerf.str().c_str());
		log::Logging::Log(log::Logging::LOGLEVEL_INFO,"url parser passed all tests (valid urls)");}

	return success;
}

bool UnitTestUrlParser::TestInvalidUrls(database::DatabaseConnection* connection, const std::string& urlFileName) {

	std::vector<UnitTestUrl> testUrls;
	if(!UnitTestUrl::ReadInvalidURLFile(urlFileName, testUrls)){
		return false; }

	PERFORMANCE_LOG_START;

	bool success = true;
	std::vector<UnitTestUrl>::const_iterator iterTestUrl = testUrls.begin();
	for(;iterTestUrl != testUrls.end(); ++iterTestUrl) {

		const UnitTestUrl& curTestUrl = *iterTestUrl;

		//enable to debug certain urls by line in file
		//just set line number and a break point here
		//if(curTestUrl.line == 60) {
		//	std::cout << std::endl;
		//}

		network::HttpUrl baseUrl, curUrl;
		if(!curTestUrl.baseUrl.empty()) {
			try {
				network::HttpUrlParser::ParseURL(curTestUrl.baseUrl, baseUrl);
				baseUrl.CalculateFullUrl(connection);
			}
			catch(errors::Exception& e) {
				UnitTestUrlParser::OnError("error while parsing urlBase:\n" + e.Dump(),curTestUrl);
				success = false;
				continue;
			}
		}
		std::string baseUrlDump = baseUrl.Dump();

		bool hasError = false;
		try {
			network::HttpUrlParser::ParseURL(baseUrl,curTestUrl.theUrl, curUrl);
		}
		catch(errors::Exception& e) {
			e.DisableLogging();
			hasError = true;
		}

		if(!hasError)
			OnError("invalid url validated\n" + curUrl.Dump(), curTestUrl);

		success &= hasError;
		std::string curUrlDump = curUrl.Dump();
	}

	if(!success){
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"\n\n !!! URL PARSER UNIT-TEST FAILED (INVALID URL TEST)!!! \n");
	}
	else {
		std::stringstream msgPerf;
		msgPerf << "parsed " << testUrls.size() << " urls";
		std::string sMsgPerf = msgPerf.str();
		PERFORMANCE_LOG_STOP(sMsgPerf.c_str());
		log::Logging::Log(log::Logging::LOGLEVEL_INFO,"url parser passed all tests (invalid urls)");}
	return success;
}

void UnitTestUrlParser::OnError(const std::string& message, const UnitTestUrl& errorUrl) {

	std::stringstream msg;
	msg << std::endl << std::endl << message << std::endl <<
		"baseUrl  : " << errorUrl.baseUrl << std::endl <<
		"theUrl   : " << errorUrl.theUrl << std::endl <<
		"resultUrl: " << errorUrl.resultUrl << std::endl <<
		"line     : " << errorUrl.line << std::endl;
	log::Logging::Log(log::Logging::LOGLEVEL_ERROR,msg.str());
}

}
