/**
 * @file FastCGIServer.cpp
 * @author Moritz Wagner
 * @date 12.03.2012
 */

#include "FastCGIServer.h"

#include "FastCGIServerThread.h"

#include <fcgiapp.h>

#include <iostream>
#include <cstdlib>
#include <unistd.h>

#include <HttpUrlParser.h>
#include <CacheDatabaseUrl.h>
#include <CacheSecondLevelDomain.h>
#include <CacheSubdomain.h>
#include <CacheUrlPathPart.h>
#include <CacheUrlSearchPart.h>
#include <CachePathPart.h>
#include <CacheParsed.h>
#include <CacheHtml.h>
#include <CacheRobotsTxt.h>
#include <TLD.h>

#include <StringTools.h>
#include <FileTools.h>
#include <TLD.h>

#include <FileLogging.h>
#include <ConsoleLogging.h>
#include <DatabaseLogging.h>

#include <Exception.h>

//extern char ** environ;

namespace fastcgiserver {

FastCGIServer::FastCGIServer()
: logging(NULL)
, basePort(-1)
, threadCount(1)
{
	errors::Exception::InitializeExceptionHandling();
}

FastCGIServer::~FastCGIServer() {
}

bool FastCGIServer::StartServer(int argc, char** argv)
{
	if(threads.size())
		StopServer();

	RegisterDatabaseConfigParams();
	RegisterLoggingParams();
	RegisterSocketConfig();
	RegisterCacheConfigParams();

	config.RegisterParam("configfile", "filename of config file", false, 0);

	config.Init(argc,argv);

	//logging is "non-vital" so ignore non successful initiation...
	InitLoggingConfig();

	if(FCGX_Init() != 0){
		return false;}

	if (!InitConfig() || !InitDatabaseConfigs() || !InitSocketConfig() || !InitCacheConfigParams())
		return false;

	dbHelper.DestroyConnection();

	if(basePort <= 0)
		return false;

	int backlog = 0;
	for(int i = 0; i < threadCount; i++) {
		FastCGIServerThread* thread(0);
		if(basePort != -1) {
			thread = CreateThreadPort(databaseConfig,&acceptMutex,fcgiIP,basePort+i,backlog);
		}
		else {
			thread = CreateThreadSocket(databaseConfig,&acceptMutex,fcgiIP,backlog);
		}
		thread->SpellChecker().InitSpellChecking(dictionaryFile,affixFile);
		thread->StartThread(NULL);
		threads.push_back(thread);
	}

	return true;
}

bool FastCGIServer::StopServer()
{
	std::vector<FastCGIServerThread*>::iterator iterThreads(threads.begin());
	for(;iterThreads != threads.end(); ++iterThreads) {
		(*iterThreads)->SetShallEnd();
	}

	iterThreads = threads.begin();
	for(;iterThreads != threads.end(); ++iterThreads) {
		FCGX_ShutdownPending();
		(*iterThreads)->WaitForThread();
		delete (*iterThreads);
	}

	threads.clear();

	return true;
}

void FastCGIServer::RegisterLoggingParams()
{
	std::string defaultLogType = "none";
	config.RegisterParam("log", "logging, one of: none,console,file,database", false, &defaultLogType );

	std::string defaultLogLevel = "info";
	config.RegisterParam("loglevel", "log level, one of: error,warn,info,trace", false, &defaultLogType );

	std::string defaultLogFile = "server.log";
	config.RegisterParam("logfile", "log file, needed only for log type: file", false, &defaultLogFile );
}

void FastCGIServer::InitLoggingConfig()
{
	if(logging)
		delete logging;
	logging = NULL;

	std::string logType = "none";
	if ( !config.GetValue("log",logType) )
		logType = "none";

	if(logType == "console")
	{
		logging = dynamic_cast<log::Logging*>(new log::ConsoleLogging());
	}
	else if (logType == "file")
	{
		std::string logFile;
		if ( !config.GetValue("logfile",logFile) )
				return;

		log::FileLogging* loggingTmp = new log::FileLogging();
		loggingTmp->SetFileName(logFile);
		loggingTmp->SetAppend(false);
		loggingTmp->SetFlush(true);

		logging = dynamic_cast<log::Logging*>(loggingTmp);
	}
	else if (logType == "database")
	{
		logging = dynamic_cast<log::Logging*>(new log::DatabaseLogging(databaseConfig));
	}

	if(logging)
	{
		std::string logLevel = "info";
		if ( !config.GetValue("loglevel",logLevel) )
			return;

		if(!logLevel.compare("info"))
		{
			log::Logging::SetLogLevel(log::Logging::LOGLEVEL_INFO);
		}
		else if(!logLevel.compare("warn"))
		{
			log::Logging::SetLogLevel(log::Logging::LOGLEVEL_WARN);
		}
		else if(!logLevel.compare("error"))
		{
			log::Logging::SetLogLevel(log::Logging::LOGLEVEL_ERROR);
		}
		else if(!logLevel.compare("trace"))
		{
			log::Logging::SetLogLevel(log::Logging::LOGLEVEL_TRACE);
		}
	}
}

void FastCGIServer::RegisterSocketConfig()
{
	std::string defaultThreadCount = "1";
	config.RegisterParam("threads", "number of threads per server application", false, &defaultThreadCount );

	std::string defaultSocketType = "tcp";
	config.RegisterParam("socket_type", "one of: tcp, unix", false, &defaultSocketType );
	config.RegisterParam("fcgi_ip", "ip to listen on for fastcgi requests (needed only in socket_type tcp, 0.0.0.0 for all)", false, NULL);
	config.RegisterParam("fcgi_base_port", "base port to listen on for fastcgi requests (needed only in socket_type tcp)", false, NULL );
	config.RegisterParam("fcgi_unix_path", "unix socket file to listen on for fastcgi requests (needed only in socket_type unix)", false, NULL );
}

bool FastCGIServer::InitSocketConfig()
{
	if ( !config.GetValue("threads",threadCount) ) {
		log::Logging::LogWarn("no threads specified, fallback to 1");
		threadCount = 1;
	}

	std::string socketType = "tcp";
	if ( !config.GetValue("fcgi_socket_type",socketType) ) {
		socketType = "tcp";
		log::Logging::LogWarn("no fcgi_socket_type specified, fallback to tcp");
	}

	if(socketType.compare("tcp") == 0) {
		if ( !config.GetValue("fcgi_ip",fcgiIP) ) {
			log::Logging::LogError("no fcgi_ip specified");
			return false;
		}
		if ( !config.GetValue("fcgi_base_port",basePort) ) {
			log::Logging::LogError("no fcgi_base_port specified");
			return false;
		}
	}
	else if (socketType.compare("unix") == 0){
		if(threadCount != 1) {
			log::Logging::LogError("fcgi_socket_type unix does not support multi thread configuration, threads needs to be set to 1");
			return false;
		}
		if ( !config.GetValue("fcgi_unix_path",fcgiIP) ) {
			log::Logging::LogError("no fcgi_ip specified");
			return false;
		}
		basePort = -1;
	}
	else {
		log::Logging::LogError("unknown fcgi_socket_type specified: %s",socketType.c_str());
		return false;
	}

	return true;
}

void FastCGIServer::RegisterDatabaseConfigParams(void)
{
	std::string defaultDbType = "mysql";
	config.RegisterParam( "dbtype", "database type, one of: mysql | postgres ", true, &defaultDbType );
	config.RegisterParam( "dbhost", "database host"    , true, 0 );
	config.RegisterParam( "dbport", "database port"    , true, 0 );
	config.RegisterParam( "dbname", "database name"    , true, 0 );
	config.RegisterParam( "dbuser", "database username", true, 0 );
	config.RegisterParam( "dbpass", "database password", true, 0 );
	config.RegisterFlag ( "dblogquery", "logs all queries", false );
	config.RegisterParam( "request_xsd", "xsd file for request validation", false, &requestXSD );
	config.RegisterParam( "response_xsd", "xsd file for request validation", false, &responseXSD );

	config.RegisterParam( "dictionary_file", " hunspell dictionary (dictionary files normally found in /usr/share/hunspell)", true, 0 );
	config.RegisterParam( "affix_file", " hunspell affix file (see dictionary_file)", true, 0 );
}

bool FastCGIServer::InitDatabaseConfigs(void)
{
	int port;
	std::string tmp;
	bool bSuccess = true;

	if( ( bSuccess &= config.GetValue("dbtype", tmp) ) ) {
		if(tmp.compare("mysql") == 0) {
			databaseConfig = dynamic_cast<database::DatabaseConfig*>(new database::MySQLDatabaseConfig());
		}
		else if(tmp.compare("postgres") == 0) {
			databaseConfig = dynamic_cast<database::DatabaseConfig*>(new database::PostgreSQLDatabaseConfig());
		}
		else {
			log::Logging::LogError("invalid database type specified, defaulting to MySQL");
			databaseConfig = dynamic_cast<database::DatabaseConfig*>(new database::MySQLDatabaseConfig());
		}
	}

	if( ( bSuccess &= config.GetValue("dbhost", tmp) ) ) {
		databaseConfig->SetHost(tmp);}
	if( ( bSuccess &= config.GetValue("dbport", port) ) ) {
		databaseConfig->SetPort(port);}
	if( ( bSuccess &= config.GetValue("dbname", tmp) ) ) {
		databaseConfig->SetDatabaseName(tmp);}
	if( ( bSuccess &= config.GetValue("dbuser", tmp) ) ) {
		databaseConfig->SetUser(tmp);}
	if( ( bSuccess &= config.GetValue("dbpass", tmp) ) ) {
		databaseConfig->SetPass(tmp);}

	bool logQuery(true);
	if(!config.GetValue("dblogquery",logQuery)){
		logQuery = false;}
	databaseConfig->SetLogQuery(logQuery);

	if ( !config.GetValue("request_xsd",requestXSD) )
		requestXSD = "";
	if(!requestXSD.empty())
		tools::FileTools::ReadFile(requestXSD, xsdRequestContent);
	else{
		log::Logging::LogWarn("no valid xsd filename found, please check request_xsd config option to enable xsd validation");	}

	if ( !config.GetValue("response_xsd",responseXSD) )
		responseXSD = "";
	if(!responseXSD.empty())
		tools::FileTools::ReadFile(responseXSD, xsdResponseContent);
	else{
		log::Logging::LogWarn("no valid xsd filename found, please check response_xsd config option to enable xsd validation");	}

	if(!config.GetValue("dictionary_file", dictionaryFile) || dictionaryFile.empty() ){
		log::Logging::LogWarn("spellchecking will not be initialized, please check dictionary_file config option");	}

	if(!config.GetValue("affix_file", affixFile) || dictionaryFile.empty() ){
		log::Logging::LogWarn("spellchecking will not be initialized, please check affix_file config option");	}

	database::DatabaseConnection* conn = dbHelper.CreateConnection(databaseConfig);
	if(!conn) {
		log::Logging::LogError("could not establish database connection, exiting.");
		return false; }

	return bSuccess;
}

void FastCGIServer::RegisterCacheConfigParams()
{
	std::string defaultUrlCacheSize = "1000";
	config.RegisterParam("urlcache", "number of urls in cache", true, &defaultUrlCacheSize );

	std::string defaultUrlSubdomainCacheSize = "1000";
	config.RegisterParam("subdomaincache", "number of subdomains in cache", true, &defaultUrlSubdomainCacheSize );

	std::string defaultUrlSecondLevelCacheSize = "1000";
	config.RegisterParam("secondleveldomaincache", "number of second level domains in cache", true, &defaultUrlSecondLevelCacheSize );

	std::string defaultUrlPathPartCacheSize = "1000";
	config.RegisterParam("urlpathpartcache", "number of url path parts in cache", true, &defaultUrlPathPartCacheSize );

	std::string defaultUrlSearchPartCacheSize = "1000";
	config.RegisterParam("searchpartcache", "number of url search parts in cache", true, &defaultUrlSearchPartCacheSize );

	std::string defaultPathPartCacheSize = "1000";
	config.RegisterParam("pathpartcache", "number of path parts in cache", true, &defaultPathPartCacheSize );

	std::string defaultHtmlCacheSize = "100";
	config.RegisterParam("htmlcache", "number of html docs in cache", true, &defaultHtmlCacheSize );

	std::string defaultParsedCacheSize = "100";
	config.RegisterParam("parsercache", "number of parsed html in cache", true, &defaultParsedCacheSize );

	std::string defaultRobotsTxtCacheSize = "500";
	config.RegisterParam("robotscache", "number of robots.txt in cache", true, &defaultRobotsTxtCacheSize);
}

bool FastCGIServer::InitCacheConfigParams()
{
	if(!htmlparser::TLD::InitTLDCache(dbHelper.Connection())) {
		log::Logging::LogError("cannot initialize top level domain cache, exiting...");
		return false;}

	std::vector<std::string> tldStrings;
	htmlparser::TLD::GetTLDStrings(tldStrings);
	network::HttpUrlParser::SetTopLevelDomains(tldStrings);

	int sizeUrlCache(-1);
	if(!config.GetValue("urlcache", sizeUrlCache) || sizeUrlCache == -1) {
		log::Logging::LogWarn("missing urlcache parameter, using default value: 1000");
		sizeUrlCache = 1000; }
	caching::CacheDatabaseUrl::SetCapacity(sizeUrlCache);

	int sizeSubdomainCache(-1);
	if(!config.GetValue("subdomaincache", sizeSubdomainCache) || sizeSubdomainCache == -1) {
		log::Logging::LogWarn("missing subdomaincache parameter, using default value: 1000");
		sizeSubdomainCache = 1000; }
	caching::CacheSubdomain::SetCapacity(sizeSubdomainCache);

	int sizeSecondLevelCache(-1);
	if(!config.GetValue("secondleveldomaincache", sizeSecondLevelCache )) {
		log::Logging::LogWarn("missing secondleveldomaincache parameter, using default value: 1000");
		sizeSecondLevelCache = 1000; }
	caching::CacheSecondLevelDomain::SetCapacity(sizeSecondLevelCache);

	int sizeUrlPathPartCache(-1);
	if(!config.GetValue("urlpathpartcache", sizeUrlPathPartCache )) {
		log::Logging::LogWarn("missing urlpathpartcache parameter, using default value: 1000");
		sizeUrlPathPartCache = 1000; }
	caching::CacheUrlPathPart::SetCapacity(sizeUrlPathPartCache);
	caching::CacheUrlPathPart::Init(dbHelper.Connection());

	int sizeUrlSearchPartCache(-1);
	if(!config.GetValue("searchpartcache", sizeUrlSearchPartCache )) {
		log::Logging::LogWarn("missing searchpartcache parameter, using default value: 1000");
		sizeUrlSearchPartCache = 1000; }
	caching::CacheUrlSearchPart::SetCapacity(sizeUrlSearchPartCache);

	int sizePathPartCache(-1);
	if(!config.GetValue("pathpartcache", sizePathPartCache )) {
		log::Logging::LogWarn("missing pathpartcache parameter, using default value: 1000");
		sizePathPartCache = 1000; }
	caching::CachePathPart::SetCapacity(sizePathPartCache);

	int sizeHtmlCache = -1;
	if(!config.GetValue("htmlcache", sizeHtmlCache)) {
		log::Logging::LogWarn("missing htmlcache parameter, using default value: 100");
		sizeHtmlCache = 100; }
	caching::CacheHtml::SetCapacity(sizeHtmlCache);

	int sizeParsedCache = -1;
	if(!config.GetValue("parsercache", sizeParsedCache)) {
		log::Logging::LogWarn("missing parsercache parameter, using default value: 100");
		sizeParsedCache = 100; }
	caching::CacheParsed::SetCapacity(sizeParsedCache);

	int sizeRobotsCache = -1;
	if(!config.GetValue("robotscache",sizeRobotsCache)) {
		log::Logging::LogWarn("missing robotscache parameter, using default value: 500");
		sizeRobotsCache = 500; }
	caching::CacheRobotsTxt::SetCapacity(sizeRobotsCache);

	return true;
}

void FastCGIServer::OnException() {

	log::Logging::LogError("killing none gracefully due to unknown and uncaught exception");

}

void FastCGIServer::OnException(errors::Exception& ex) {

	log::Logging::LogError("killing none gracefully due to uncaught exception");
}

}
