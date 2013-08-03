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

	config.RegisterParam("configfile", "filename of config file", false, 0);

	config.Init(argc,argv);

	//logging is "non-vital" so ignore non successful initiation...
	InitLoggingConfig();

	if(FCGX_Init() != 0){
		return false;}

	if (!InitConfig() || !InitDatabaseConfigs() || !InitSocketConfig())
		return false;

	if(basePort <= 0)
		return false;

	int backlog = 0;
	for(int i = 0; i < threadCount; i++) {
		FastCGIServerThread* thread = CreateThreadPort(databaseConfig,&acceptMutex,basePort+i,backlog);
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

	std::string defaultSocketType = "port";
	config.RegisterParam("socket_type", "one of: port, filename(not supported)", false, &defaultSocketType );
	config.RegisterParam("base_port", "base port for fastcgi applications (needed only in socket_type port)", false, NULL );
}

bool FastCGIServer::InitSocketConfig()
{
	if ( !config.GetValue("threads",threadCount) )
		threadCount = 1;

	std::string socketType = "port";
	if ( !config.GetValue("socket_type",socketType) )
		socketType = "port";

	if(socketType.compare("port") == 0) {
		if ( !config.GetValue("base_port",basePort) )
			return false;
	}
	else {
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
	else {
		htmlparser::TLD::InitTLDCache(dbHelper.Connection());
		dbHelper.DestroyConnection();
	}
	return bSuccess;
}

void FastCGIServer::OnException() {

	log::Logging::LogError("killing none gracefully due to unknown and uncaught exception");

}

void FastCGIServer::OnException(errors::Exception& ex) {

	log::Logging::LogError("killing none gracefully due to uncaught exception");
}

}
