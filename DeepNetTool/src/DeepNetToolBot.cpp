/*
 * DeepNetToolBot.cpp
 *
 *  Created on: 20.03.2012
 *      Author: Moritz Wagner
 */

#include "DeepNetToolBot.h"

#include <iostream>

#include <UrlInserter.h>
#include <HttpUrl.h>
#include <HttpUrlParser.h>
#include <IndexerTester.h>

#include <FileTools.h>
#include <Exception.h>
#include <Logging.h>

#include <DatabaseRepair.h>

#include <DatabaseLayer.h>

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
#include "UnitTestIndexerEx.h"
#include "UnitTestDatabase.h"
#include "UnitTestCacheUrlPathPart.h"
#include "UnitTestExceptions.h"
#include "UnitTestSyncing.h"

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

	bool bSuccess(true);

	//check for requested unit tests
	bSuccess = ProcessUnitTests();

	//repair database after unclean shutdown
	bool isRepair(false);
	if(Config().GetValue("databaseRepair", isRepair) && isRepair) {
		bSuccess = bot::DatabaseRepair::FixUncleanShutdown(DB().Connection());
		if(!bSuccess) {
			log::Logging::LogError("error while fixing database after unclean shutdown.");
			bSuccess = false;
		}
	}

	//insert a file of urls into database and schedules them for search engine
	std::string urlFile;
	if( Config().GetValue("urlFile", urlFile) )	{

		log::Logging::LogInfo("inserting urls");
		std::multimap<std::string,std::string> urls;
		htmlparser::UrlInserter::ReadURLFile(urlFile,urls);
		htmlparser::UrlInserter::InsertURLFile(DB().Connection(),urls);
		log::Logging::LogInfo("inserting urls done");
	}

	//insert an url into database and schedule it for search engine
	if( Config().GetValue("insertUrl", urlFile) ) {

		log::Logging::LogInfo("inserting url");
		htmlparser::UrlInserter::InsertURL(DB().Connection(),urlFile,"");
		log::Logging::LogInfo("inserting url done");
	}

	//add commerce search user
	std::string csUserAdd, csUser = "", csPass = "", csDomain = "";
	long long csRevisitInterval(-1);
	if( Config().GetValue("csUserAdd",csUserAdd) ) {
		if( Config().GetValue("csUser", csUser)      &&
			Config().GetValue("csPass", csPass)      &&
			Config().GetValue("csDomain", csDomain)  &&
			Config().GetValue("csRevisitInterval", csRevisitInterval)
	    ) {
			log::Logging::LogInfo("adding user to commerce search database");

			if(!CommerceSearchTools::AddCustomer(DB().Connection(),csUser,csPass,csDomain,csRevisitInterval)) {
				log::Logging::LogError("an error occured while inserting new customer for commerce search, customer was not inserted.");}
			else {
				log::Logging::LogInfo("new customer for commerce search was inserted successfully");}
		}
		else {
			log::Logging::LogError("either csUser, csPass, csDomain or csRevisitInterval parameter is/are missing, exiting...");
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
	DB().DestroyConnection();
	return true;
}

bool DeepNetToolBot::OnPreInit() {

	RegisterDatabaseRepairParams();
	RegisterCommerceSearchParams();
	RegisterDataminingParams();
	RegisterUrlInserterParams();

	//unit tests
	RegisterHtmlTestParams();
	RegisterPCRERegexTestParams();
	RegisterExceptionTestParams();
	RegisterRobotTxtParams();
	RegisterHtmlClientCURLParams();
	RegisterHtmlDocumentFactoryParams();
	RegisterIndexerExParams();
	RegisterDatabaseUnitTestParams();
	RegisterSyncingTestParams();

	return true;
}

void DeepNetToolBot::RegisterDatabaseRepairParams() {
	Config().RegisterFlag("databaseRepair", "repairs database after unclean shutdown", false);
}

void DeepNetToolBot::RegisterHtmlTestParams() {
	Config().RegisterParam("htmlFile", "filename of html file to parse/check", false, 0);
	Config().RegisterParam("htmlUnitTestPath", "path to unit test html files", false, 0);
}

void DeepNetToolBot::RegisterUrlInserterParams() {
	Config().RegisterParam("urlFile", "insert urls from file into database", false, 0 );
	Config().RegisterParam("insertUrl", "domain to insert ie. dummy.mo-sys.de", false, 0 );

	Config().RegisterParam("urlValidateFile", "validates urls from file", false, 0 );
	Config().RegisterParam("urlInvalidateFile", "validates invalid urls from file", false, 0 );

	Config().RegisterParam("urlPathPartValidateFile", "validates path part of an url from a file", false, 0 );
}

void DeepNetToolBot::RegisterCommerceSearchParams() {
	Config().RegisterParam("csUserAdd", "add commerce search user to database", false, 0);
	Config().RegisterParam("csUser", "username of commerce search user", false, 0);
	Config().RegisterParam("csPass", "password of commerce search user", false, 0);
	Config().RegisterParam("csDomain", "domain of commerce search user", false, 0);
	Config().RegisterParam("csRevisitInterval", "crawler revisit interval of commerce search user (in minutes)", false, 0);
}

void DeepNetToolBot::RegisterDataminingParams() {
	Config().RegisterParam("dmAddDataminingUser", "add datamining user to database", false, 0);
	Config().RegisterParam("dmAddDataminingAlert", "add datamining alert to database", false, 0);
	Config().RegisterParam("dmDataminingUsername", "datamining username", false, 0);
	Config().RegisterParam("dmDataminingPassword", "datamining password", false, 0);
	Config().RegisterParam("dmDataminingCriteria", "regex for datamining criteria", false, 0);
	Config().RegisterParam("dmDataminingAlertType", "type of alert, one of: email", false, 0);
	Config().RegisterParam("dmDataminingAlertParam", "parameters for alert types", false, 0);
}

void DeepNetToolBot::RegisterPCRERegexTestParams() {
	Config().RegisterParam("pcreRegexFile", "validates pcre regexes from file", false, 0 );
}

void DeepNetToolBot::RegisterExceptionTestParams() {
	Config().RegisterParam("exceptionTest", "set to 1 to enable UnitTests for exceptions", false, 0 );
}

void DeepNetToolBot::RegisterRobotTxtParams() {
	Config().RegisterParam("robotsTxtFile", "validates robots.txt from file", false, 0 );
}

void DeepNetToolBot::RegisterHtmlClientCURLParams() {
	Config().RegisterParam("curlGetFile", "filename of urls to \"GET\" via cURL-based client", false, 0 );
	Config().RegisterParam("curlPostFile", "filename of urls to \"POST\" via cURL-based client", false, 0 );
}

void DeepNetToolBot::RegisterHtmlDocumentFactoryParams() {
	Config().RegisterParam("domParserUnitTestPath", "path to unit test html files for DOM parser", false, 0);
}

void DeepNetToolBot::RegisterIndexerExParams() {
	Config().RegisterParam("indexerExUnitTestPath", "path to unit test text and dictionary xml files for indexer", false, 0);
}

void DeepNetToolBot::RegisterDatabaseUnitTestParams() {
	Config().RegisterFlag("databaseUnitTest", "enables unit tests for database",false);
}

void DeepNetToolBot::RegisterSyncingTestParams() {
	Config().RegisterParam("syncingUnitTest", "set to 1 to enable UnitTests for syncing library", false, 0 );
}

bool DeepNetToolBot::ProcessUnitTests() {

	bool bSuccess(true);
	UnitTestManager unitTests;

	//initiate url based unit tests
	std::string urlFile;
	if( Config().GetValue("urlValidateFile", urlFile) ) {
		std::string invalidUrlFileName;
		Config().GetValue("urlInvalidateFile", invalidUrlFileName);
		unitTests.AddUnitTest(new UnitTestUrlParser(DB().Connection(),urlFile,invalidUrlFileName));
		unitTests.AddUnitTest(new UnitTestCacheUrl(DB().Connection(),urlFile)); }

	std::string urlPathPartValidateFile;
	if( Config().GetValue("urlPathPartValidateFile", urlPathPartValidateFile) ) {
		unitTests.AddUnitTest(new UnitTestCacheUrlPathPart(DB().Connection(),urlPathPartValidateFile));}

	//initiate pcre regex unit test
	std::string pcreRegexFile;
	if( Config().GetValue("pcreRegexFile",pcreRegexFile) ){
		unitTests.AddUnitTest(new UnitTestPCRERegex(pcreRegexFile)); }

	//initiate exceptions
	long long test(-1);
	if( Config().GetValue("exceptionTest",test) && test > 0) {
		unitTests.AddUnitTest(new UnitTestExceptions()); }

	//initiate robots.txt unit test
	std::string robotsTxtFile;
	if( Config().GetValue("robotsTxtFile",robotsTxtFile) ){
		unitTests.AddUnitTest(new UnitTestRobotTxt(robotsTxtFile)); }

	//initiate html parser based unit tests
	std::string htmlUnitTestPath;
	if(Config().GetValue("htmlUnitTestPath",htmlUnitTestPath)) {
		unitTests.AddUnitTest(new toolbot::UnitTestSAX2HtmlParser(DB().Connection(),htmlUnitTestPath)); }

	//initiate http client CURL based unit tests
	std::string curlGetFile,curlPostFile;
	bool isHttpCurlTest = Config().GetValue("curlGetFile",curlGetFile);
	isHttpCurlTest |= Config().GetValue("curlPostFile",curlPostFile);
	if(isHttpCurlTest){
		unitTests.AddUnitTest(new toolbot::UnitTestHttpClientCURL(curlGetFile,curlPostFile)); }

	//initiate html parser based unit tests
	std::string domParserUnitTestPath,domParserUnitTestFile;
	if( Config().GetValue("domParserUnitTestPath",domParserUnitTestPath) && !domParserUnitTestPath.empty()) {
		//used for html parsed as base url
		network::HttpUrl httpUrl;
		bool successParse(true);
		try {
			network::HttpUrlParser::ParseURL("siridia.de",httpUrl); }
		CATCH_EXCEPTION(errors::Exception,e,1)
			successParse = false; }

		if(successParse)
			unitTests.AddUnitTest(new toolbot::UnitTestHtmlDocumentFactory(httpUrl,domParserUnitTestPath));
		else
			return false;
	}

	//initiate indexer based unit tests
	std::string indexerExUnitTestPath;
	if( Config().GetValue("indexerExUnitTestPath",indexerExUnitTestPath) && !indexerExUnitTestPath.empty() ) {
		unitTests.AddUnitTest(new toolbot::UnitTestIndexerEx(DB().Connection(),indexerExUnitTestPath));	}

	//initiate database based unit tests
	bool enableDatabaseUnitTest(false);
	if( Config().GetValue("databaseUnitTest",enableDatabaseUnitTest) ) {
		if(enableDatabaseUnitTest) {
			unitTests.AddUnitTest(new toolbot::UnitTestDatabase(dbConfig));
		}
	}

	//initiate syncing based unit tests
	bool enableSyncingUnitTest(false);
	if( Config().GetValue("syncingUnitTest",enableSyncingUnitTest) ) {
		if(enableSyncingUnitTest) {
			unitTests.AddUnitTest(new toolbot::UnitTestSyncing(dbConfig));
		}
	}

	//finally run all previously registered unit tests
	bSuccess &= unitTests.Run();
	return bSuccess;
}

}
