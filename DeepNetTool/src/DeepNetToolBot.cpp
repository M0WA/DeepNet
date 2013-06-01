/*
 * DeepNetToolBot.cpp
 *
 *  Created on: 20.03.2012
 *      Author: Moritz Wagner
 */

#include "DeepNetToolBot.h"

#include <iostream>

#include <TLD.h>
#include <UrlInserter.h>
#include <IndexerTester.h>
#include <FileTools.h>
#include <HttpUrl.h>
#include <HttpUrlParser.h>

#include "DatabaseRepair.h"
#include "CommerceSearchTools.h"
#include "DataMiningTools.h"

#include "UnitTestManager.h"
#include "UnitTestUrl.h"
#include "UnitTestUrlParser.h"
#include "UnitTestCacheUrl.h"
#include "UnitTestPCRERegex.h"
#include "UnitTestRobotTxt.h"
#include "UnitTestSAX2HtmlParser.h"
#include "UnitTestHttpClientCURL.h"
#include "UnitTestHtmlDocumentFactory.h"

namespace toolbot {

DeepNetToolBot::DeepNetToolBot()
: bot::Bot() {
}

DeepNetToolBot::~DeepNetToolBot() {
}

bool DeepNetToolBot::OnInit() {

	return true;
}

bool DeepNetToolBot::OnRun() {

	bool bSuccess = true;
	database::DatabaseConnection* conn = DB().CreateConnection(dbConfig);
	if(!conn || !htmlparser::TLD::InitTLDCache(DB().Connection())) {
		log::Logging::Log(log::Logging::LOGLEVEL_ERROR, "cannot initialize top level domain cache, exiting...");
		return false;
	}
	std::vector<std::string> tldStrings;
	htmlparser::TLD::GetTLDStrings(tldStrings);
	network::HttpUrlParser::InitTLDCache(tldStrings);

	//check for requested unit tests
	bSuccess = ProcessUnitTests();

	//repair database after unclean shutdown
	bool isRepair = false;
	if(Config().GetValue("databaseRepair", isRepair) && isRepair) {
		bSuccess = DatabaseRepair::FixUncleanShutdown(conn);
		if(!bSuccess) {
			log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"error while fixing database after unclean shutdown.");
			bSuccess = false;
		}
	}

	//insert a file of urls into database and schedules them for search engine
	std::string urlFile;
	if( Config().GetValue("urlFile", urlFile) )	{

		log::Logging::Log(log::Logging::LOGLEVEL_INFO,"inserting urls");
		std::multimap<std::string,std::string> urls;
		htmlparser::UrlInserter::ReadURLFile(urlFile,urls);
		htmlparser::UrlInserter::InsertURLFile(DB().Connection(),urls);
		log::Logging::Log(log::Logging::LOGLEVEL_INFO,"inserting urls done");
	}

	//insert an url into database and schedule it for search engine
	if( Config().GetValue("insertUrl", urlFile) ) {

		log::Logging::Log(log::Logging::LOGLEVEL_INFO,"inserting url");
		htmlparser::UrlInserter::InsertURL(DB().Connection(),urlFile,"");
		log::Logging::Log(log::Logging::LOGLEVEL_INFO,"inserting url done");
	}

	//add commerce search user
	std::string csUserAdd, csUser = "", csPass = "", csDomain = "";
	long long csRevisitInterval = -1;
	if( Config().GetValue("csUserAdd",csUserAdd) ) {
		if( Config().GetValue("csUser", csUser)      &&
			Config().GetValue("csPass", csPass)      &&
			Config().GetValue("csDomain", csDomain)  &&
			Config().GetValue("csRevisitInterval", csRevisitInterval)
	    ) {
			log::Logging::Log(log::Logging::LOGLEVEL_INFO,"adding user to commerce search database");

			if(!CommerceSearchTools::AddCustomer(DB().Connection(),csUser,csPass,csDomain,csRevisitInterval)) {
				log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"an error occured while inserting new customer for commerce search, customer was not inserted.");}
			else {
				log::Logging::Log(log::Logging::LOGLEVEL_INFO,"new customer for commerce search was inserted successfully");}
		}
		else {
			log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"either csUser, csPass, csDomain or csRevisitInterval parameter is/are missing, exiting...");
		}
	}

	//add datamining request
	std::string dmAddDataminingAlert;
	if( Config().GetValue("dmAddDataminingAlert",dmAddDataminingAlert) ) {

		std::string dmDataminingCriteria = "",
			dmDataminingAlertParam   = "",
			dmDataminingAlertType    = "",
			dmDataminingUsername     = "";

		if( Config().GetValue("dmDataminingCriteria"  , dmDataminingCriteria) &&
			Config().GetValue("dmDataminingUsername"  , dmDataminingUsername) &&
			Config().GetValue("dmDataminingAlertType" , dmDataminingAlertType) ) {

			Config().GetValue("dmDataminingAlertParam", dmDataminingAlertParam);
			DataMiningTools::RegisterDataminingAlert(DB().Connection(),dmDataminingUsername,dmDataminingCriteria,dmDataminingAlertType,dmDataminingAlertParam);
		}
	}

	//add datamining user
	std::string dmAddDataminingUser;
	if( Config().GetValue("dmAddDataminingUser",dmAddDataminingUser) ) {

		std::string dmDataminingUsername = "",
					dmDataminingPassword = "";

		if( Config().GetValue("dmDataminingUsername"  , dmDataminingUsername) &&
			Config().GetValue("dmDataminingPassword"  , dmDataminingPassword) ) {

			DataMiningTools::InsertDataminingUser(DB().Connection(),dmDataminingUsername,dmDataminingPassword);
		}
	}

	shutdownReceived = true;
	return bSuccess;
}

bool DeepNetToolBot::OnShutdown() {

	return true;
}

void DeepNetToolBot::RegisterDefaultParams(void) {

	RegisterDatabaseRepairParams();
	RegisterCommerceSearchParams();
	RegisterDataminingParams();
	RegisterUrlInserterParams();

	//unit tests
	RegisterHtmlTestParams();
	RegisterPCRERegexTestParams();
	RegisterRobotTxtParams();
	RegisterHtmlClientCURLParams();
	RegisterHtmlDocumentFactoryParams();

	Bot::RegisterDefaultParams();
}

void DeepNetToolBot::RegisterDatabaseRepairParams() {

	std::string defaultOff = "0";
	Config().RegisterParam("databaseRepair", "repairs database after unclean shutdown", false, true, &defaultOff);
}

void DeepNetToolBot::RegisterHtmlTestParams() {

	Config().RegisterParam("htmlFile", "filename of html file to parse/check", false, false, 0);
	Config().RegisterParam("htmlUnitTestPath", "path to unit test html files", false, false, 0);
}

void DeepNetToolBot::RegisterUrlInserterParams() {

	Config().RegisterParam("urlFile", "insert urls from file into database", false, false, 0 );
	Config().RegisterParam("insertUrl", "domain to insert ie. dummy.siridia.de", false, false, 0 );

	Config().RegisterParam("urlValidateFile", "validates urls from file", false, false, 0 );
	Config().RegisterParam("urlInvalidateFile", "validates invalid urls from file", false, false, 0 );
}

void DeepNetToolBot::RegisterCommerceSearchParams() {

	Config().RegisterParam("csUserAdd", "add commerce search user to database", false, false, 0);
	Config().RegisterParam("csUser", "username of commerce search user", false, false, 0);
	Config().RegisterParam("csPass", "password of commerce search user", false, false, 0);
	Config().RegisterParam("csDomain", "domain of commerce search user", false, false, 0);
	Config().RegisterParam("csRevisitInterval", "crawler revisit interval of commerce search user (in minutes)", false, false, 0);
}

void DeepNetToolBot::RegisterDataminingParams() {

	Config().RegisterParam("dmAddDataminingUser", "add datamining user to database", false, false, 0);
	Config().RegisterParam("dmAddDataminingAlert", "add datamining alert to database", false, false, 0);
	Config().RegisterParam("dmDataminingUsername", "datamining username", false, false, 0);
	Config().RegisterParam("dmDataminingPassword", "datamining password", false, false, 0);
	Config().RegisterParam("dmDataminingCriteria", "regex for datamining criteria", false, false, 0);
	Config().RegisterParam("dmDataminingAlertType", "type of alert, one of: email", false, false, 0);
	Config().RegisterParam("dmDataminingAlertParam", "parameters for alert types", false, false, 0);
}

void DeepNetToolBot::RegisterPCRERegexTestParams() {

	Config().RegisterParam("pcreRegexFile", "validates pcre regexes from file", false, false, 0 );
}

void DeepNetToolBot::RegisterRobotTxtParams() {

	Config().RegisterParam("robotsTxtFile", "validates robots.txt from file", false, false, 0 );
}

void DeepNetToolBot::RegisterHtmlClientCURLParams() {

	Config().RegisterParam("curlGetFile", "filename of urls to \"GET\" via cURL-based client", false, false, 0 );
	Config().RegisterParam("curlPostFile", "filename of urls to \"POST\" via cURL-based client", false, false, 0 );
}

void DeepNetToolBot::RegisterHtmlDocumentFactoryParams() {

	//initiate html parser based unit tests
	/*
	std::string htmlUnitTestPath;
	if(Config().GetValue("htmlUnitTestPath",htmlUnitTestPath)) {
		std::vector<std::string> files;
		tools::FileTools::ListDirectory(files, htmlUnitTestPath, ".*?\\.html$", true);
		std::vector<std::string>::const_iterator iterFiles = files.begin();
		for(;iterFiles != files.end(); ++iterFiles) {
			if( !UnitTestHtmlDocumentFactory::Test(DB().Connection(),"siridia.de",htmlUnitTestPath +"/" + *iterFiles) ){
				bSuccess = false;
			}

			if(bSuccess) {
				log::Logging::Log(log::Logging::LOGLEVEL_INFO,"all html parser based unit tests finished SUCCESSFULLY"); }
		}
	}
	*/
}

bool DeepNetToolBot::ProcessUnitTests() {

	bool bSuccess = true;
	UnitTestManager unitTests;

	//initiate url based unit tests
	std::string urlFile;
	if( Config().GetValue("urlValidateFile", urlFile) ) {
		std::string invalidUrlFileName;
		Config().GetValue("urlInvalidateFile", invalidUrlFileName);
		unitTests.AddUnitTest(new UnitTestUrlParser(DB().Connection(),urlFile,invalidUrlFileName));
		unitTests.AddUnitTest(new UnitTestCacheUrl(DB().Connection(),urlFile)); }

	//initiate pcre regex unit test
	std::string pcreRegexFile;
	if( Config().GetValue("pcreRegexFile",pcreRegexFile) ){
		unitTests.AddUnitTest(new UnitTestPCRERegex(pcreRegexFile)); }

	//initiate robots.txt unit test
	std::string robotsTxtFile;
	if( Config().GetValue("robotsTxtFile",robotsTxtFile) ){
		unitTests.AddUnitTest(new UnitTestRobotTxt(robotsTxtFile)); }

	//initiate html parser based unit tests
	std::string htmlUnitTestPath;
	if(Config().GetValue("htmlUnitTestPath",htmlUnitTestPath)) {
		std::vector<std::string> files;
		tools::FileTools::ListDirectory(files, htmlUnitTestPath, ".*?\\.html$", true);
		unitTests.AddUnitTest(new toolbot::UnitTestSAX2HtmlParser(DB().Connection(),htmlUnitTestPath,files)); }

	//initiate http client CURL based unit tests
	std::string curlGetFile,curlPostFile;
	bool isHttpCurlTest = Config().GetValue("curlGetFile",curlGetFile);
	isHttpCurlTest |= Config().GetValue("curlPostFile",curlPostFile);
	if(isHttpCurlTest){
		unitTests.AddUnitTest(new toolbot::UnitTestHttpClientCURL(curlGetFile,curlPostFile)); }

	//finally run all previously registered unit tests
	bSuccess &= unitTests.Run();
	return bSuccess;
}

}
