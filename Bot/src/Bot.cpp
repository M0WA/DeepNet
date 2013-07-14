/**
 * @file Bot.cpp
 * @author Moritz Wagner
 * @date 18.01.2012
 */

#include "Bot.h"

#include <HttpUrlParser.h>

#include <ConsoleLogging.h>
#include <DatabaseLogging.h>
#include <FileLogging.h>

#include <CacheDatabaseUrl.h>
#include <CacheSecondLevelDomain.h>
#include <CacheSubdomain.h>
#include <CacheParsed.h>
#include <CacheHtml.h>
#include <CacheRobotsTxt.h>
#include <TLD.h>

#include <Exception.h>
#include <DebuggingTools.h>
#include <TimeTools.h>
#include <PerformanceCounter.h>

bot::Bot* bot::Bot::instance = 0;
threading::Mutex bot::Bot::signalMutex;

namespace bot
{

const int catchSignals[] =
{
		SIGINT,
		SIGTERM,
		SIGSEGV,
		SIGILL,
		SIGABRT,
		SIGHUP,
};
const int catchSignalCount = sizeof(catchSignals) / sizeof(catchSignals[0]);

Bot::Bot()
: shutdownReceived(false)
, dbConfig(0)
, logging(NULL)
, restartAfterShutdown(false)
, orig_uid(geteuid())
, orig_gid(getegid())
, cur_uid(geteuid())
, cur_gid(getegid())
, cacheLogInterval(0)
{
	Bot::instance = this;
}

Bot::~Bot()
{
	Shutdown();
}

void Bot::SignalHandler(int signum, siginfo_t* info, void* ucontext)
{
	signalMutex.Lock();

	tools::DebuggingTools::SignalInfos signalInfo(
		tools::DebuggingTools::GetSignalInfos(signum,info,ucontext)	);

	switch(signum)
	{
	//none graceful shutdown
	case SIGSEGV:
	case SIGABRT:
	case SIGILL:
		log::Logging::LogUnlimited(log::Logging::LOGLEVEL_ERROR,signalInfo.infoText);
		log::Logging::LogError("killing none gracefully");
		exit(1);
		break;

	//graceful shutdown
	case SIGINT:
	case SIGTERM:
		if(log::Logging::IsLogLevelTrace()) log::Logging::LogUnlimited(log::Logging::LOGLEVEL_TRACE,signalInfo.infoText);
		log::Logging::LogInfo("initiating shutting down");
		Bot::instance->shutdownReceived = true;
		Bot::instance->restartAfterShutdown = false;
		break;

	//graceful restart
	case SIGHUP:
		if(log::Logging::IsLogLevelTrace()) log::Logging::LogUnlimited(log::Logging::LOGLEVEL_TRACE,signalInfo.infoText);
		log::Logging::LogInfo("initiating soft restart");
		Bot::instance->restartAfterShutdown = true;
		Bot::instance->shutdownReceived = true;
		break;

		//other signals
	default:
		if(log::Logging::IsLogLevelTrace()) log::Logging::LogUnlimited(log::Logging::LOGLEVEL_TRACE,signalInfo.infoText);
		break;
	}

	signalMutex.Unlock();
}

bool Bot::RegisterSignalHandlers()
{
	for(int i = 0; i < catchSignalCount;i++)
	{
		struct sigaction old_action;

		struct sigaction sigact;
		sigemptyset (&sigact.sa_mask);
		sigaddset(&sigact.sa_mask,catchSignals[i]);
		sigact.sa_sigaction = &Bot::SignalHandler;
		sigact.sa_flags = SA_RESTART | SA_SIGINFO;

		sigaction (catchSignals[i], NULL, &old_action);
		if (old_action.sa_handler != SIG_IGN)
			sigaction(catchSignals[i], &sigact, &old_action);
	}
	return true;
}

void Bot::RegisterDefaultFlags(void)
{
	Config().RegisterFlag("h", "prints this message", false);
	Config().RegisterFlag("D", "daemonize", false);
}

void Bot::RegisterDefaultParams(void)
{
	RegisterDatabaseConfigParams();
	RegisterCacheConfigParams();
	RegisterPerformanceLoggingParams();

	Config().RegisterParam("user", "user id to drop privileges to", false, NULL );
	Config().RegisterParam("group", "group id to drop privileges to", false, NULL );

	std::string defaultLogType = "none";
	Config().RegisterParam("log", "logging, one of: none,console,file,database", false, &defaultLogType );

	std::string defaultLogLevel = "info";
	Config().RegisterParam("loglevel", "log level, one of: error,warn,info,trace", false, &defaultLogType );

	std::string defaultLogFile = "bot.log";
	Config().RegisterParam("logfile", "log file, needed only for log type: file", false, &defaultLogFile );

	Config().RegisterParam("configfile", "filename of config file", false, 0);
}

void Bot::RegisterCacheConfigParams()
{
	std::string defaultUrlCacheSize = "1000";
	Config().RegisterParam("urlcache", "number of urls in cache", true, &defaultUrlCacheSize );

	std::string defaultHtmlCacheSize = "100";
	Config().RegisterParam("htmlcache", "number of html docs in cache", true, &defaultHtmlCacheSize );

	std::string defaultParsedCacheSize = "100";
	Config().RegisterParam("parsercache", "number of parsed html in cache", true, &defaultParsedCacheSize );

	std::string defaultRobotsTxtCacheSize = "500";
	Config().RegisterParam("robotscache", "number of robots.txt in cache", true, &defaultRobotsTxtCacheSize);
}

bool Bot::InitCacheConfigParams()
{
	if(!htmlparser::TLD::InitTLDCache(DB().Connection())) {
		log::Logging::LogError("cannot initialize top level domain cache, exiting...");
		return false;}

	std::vector<std::string> tldStrings;
	htmlparser::TLD::GetTLDStrings(tldStrings);
	network::HttpUrlParser::SetTopLevelDomains(tldStrings);

	int sizeUrlCache = -1;
	if(!Config().GetValue("urlcache", sizeUrlCache)) {
		log::Logging::LogWarn("missing urlcache parameter, using default value: 1000");
		sizeUrlCache = 1000;
	}
	caching::CacheDatabaseUrl::SetCapacity(sizeUrlCache);

	//TODO: put sizes of secondlevel and subdomain caches in config file
	caching::CacheSecondLevelDomain::SetCapacity(sizeUrlCache);
	caching::CacheSubdomain::SetCapacity(sizeUrlCache);

	int sizeHtmlCache = -1;
	if(!Config().GetValue("htmlcache", sizeHtmlCache)) {
		log::Logging::LogWarn("missing htmlcache parameter, using default value: 100");
		sizeHtmlCache = 100;
	}
	caching::CacheHtml::SetCapacity(sizeHtmlCache);

	int sizeParsedCache = -1;
	if(!Config().GetValue("parsercache", sizeParsedCache)) {
		log::Logging::LogWarn("missing parsercache parameter, using default value: 100");
		sizeParsedCache = 100;
	}
	caching::CacheParsed::SetCapacity(sizeParsedCache);

	int sizeRobotsCache = -1;
	if(!Config().GetValue("robotscache",sizeRobotsCache)) {
		log::Logging::LogWarn("missing robotscache parameter, using default value: 500");
		sizeRobotsCache = 500;
	}
	caching::CacheRobotsTxt::SetCapacity(sizeRobotsCache);

	return true;
}

bool Bot::Run(int argc, char** argv)
{
	errors::Exception::InitializeExceptionHandling();

	do {
		restartAfterShutdown = false;

		if(!PreInit())
			return false;
		if(!Init(argc, argv))
			return false;
		if(!PostInit())
			return false;
		if(!Run())
			return false;
		if(!Shutdown())
			return false;

	} while(restartAfterShutdown);

	return true;
}

bool Bot::InitDefaultParameters()
{
	RegisterDefaultFlags();
	RegisterDefaultParams();
	RegisterSignalHandlers();
	return true;
}

bool Bot::Daemonize()
{
	pid_t pid = fork();

	//forking did not work
	//keep this process alive
	if (pid < 0) {
		log::Logging::LogError("could not daemonize, starting in default mode");
		return true; }

	//exit parent if child has valid PID
	if (pid > 0) {
		log::Logging::LogInfo("daemonized, exiting this process");
		return false;}

	return true;
}

bool Bot::SwitchUser(const uid_t setUid, const gid_t setGid)
{
	if(setUid != cur_uid) {
		cur_uid = setUid;
		setuid(setUid); }

	if(setGid != cur_gid){
		cur_uid = setGid;
		setgid(setGid);	}

	return true;
}

void Bot::InitLogging()
{
	if(logging)
		delete logging;
	logging = NULL;

	std::string logType = "none";
	if ( !Config().GetValue("log",logType) )
		logType = "none";

	if(logType == "console")
	{
		logging = dynamic_cast<log::Logging*>(new log::ConsoleLogging());
	}
	else if (logType == "file")
	{
		std::string logFile;
		if ( !Config().GetValue("logfile",logFile) )
				return;

		log::FileLogging* loggingTmp = new log::FileLogging();
		loggingTmp->SetFileName(logFile);
		loggingTmp->SetAppend(false);
		loggingTmp->SetFlush(true);

		logging = dynamic_cast<log::Logging*>(loggingTmp);
	}
	else if (logType == "database")
	{
		logging = dynamic_cast<log::Logging*>(new log::DatabaseLogging(dbConfig));
	}

	if(logging)
	{
		log::Logging::SetApplicationName(Config().GetApplicationName());

		std::string logLevel = "info";
		if ( !Config().GetValue("loglevel",logLevel) )
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

void Bot::RegisterDatabaseConfigParams(void)
{
	std::string defaultDbType = "mysql";
	Config().RegisterParam( "dbtype", "database type, one of: mysql | postgres ", true, &defaultDbType );
	Config().RegisterParam( "dbhost", "database host"    , true, 0 );
	Config().RegisterParam( "dbport", "database port"    , true, 0 );
	Config().RegisterParam( "dbname", "database name"    , true, 0 );
	Config().RegisterParam( "dbuser", "database username", true, 0 );
	Config().RegisterParam( "dbpass", "database password", true, 0 );
}

bool Bot::InitDatabaseConfigs(void)
{
	bool bSuccess = true;
	std::string tmp;
	if( ( bSuccess &= Config().GetValue("dbtype", tmp) ) ) {
		if(tmp.compare("mysql") == 0) {
			dbConfig = dynamic_cast<database::DatabaseConfig*>(new database::MySQLDatabaseConfig());
		}
		else if(tmp.compare("postgres") == 0) {
			dbConfig = dynamic_cast<database::DatabaseConfig*>(new database::PostgreSQLDatabaseConfig());
		}
		else {
			log::Logging::LogError("invalid database type specified, defaulting to MySQL");
			dbConfig = dynamic_cast<database::DatabaseConfig*>(new database::MySQLDatabaseConfig());
		}
	}

	int port;
	if( ( bSuccess &= Config().GetValue("dbhost", tmp) ) ) {
		dbConfig->SetHost(tmp);}
	if( ( bSuccess &= Config().GetValue("dbport", port) ) ) {
		dbConfig->SetPort(port);}
	if( ( bSuccess &= Config().GetValue("dbname", tmp) ) ) {
		dbConfig->SetDatabaseName(tmp);}
	if( ( bSuccess &= Config().GetValue("dbuser", tmp) ) ) {
		dbConfig->SetUser(tmp);}
	if( ( bSuccess &= Config().GetValue("dbpass", tmp) ) ) {
		dbConfig->SetPass(tmp);}

	if(!DB().CreateConnection(dbConfig)){
		log::Logging::LogError("could not create database connection");
		return false; }

	return bSuccess;
}

void Bot::RegisterPerformanceLoggingParams()
{
#ifdef ENABLE_PERFORMANCE_LOG
	std::string defaultEnablePerformance = "1";
	Config().RegisterParam("enablePerformanceLogging", "enables performance logging", false, &defaultEnablePerformance);
#endif

	std::string defaultDumpCaches = "0";
	Config().RegisterParam("dumpCaches", "log all cache stati (0: off, interval in mins) ", false, &defaultDumpCaches);
}

void Bot::InitPerformanceLoggingParams()
{
#ifdef ENABLE_PERFORMANCE_LOG
	bool enablePerformanceLog = true;
	if(!Config().GetValue("enablePerformanceLogging",enablePerformanceLog)) {
		enablePerformanceLog = true; }
	tools::PerformanceCounter::EnablePerformanceLog(enablePerformanceLog);
#endif

	if(!Config().GetValue("dumpCaches",cacheLogInterval)) {
		cacheLogInterval = 0; }
	cacheLogInterval *= 60; //convert to seconds
}

void Bot::OnException(errors::Exception& ex) {

	log::Logging::LogError("killing none gracefully due to uncaught exception");
}

void Bot::OnException() {

	log::Logging::LogError("killing none gracefully due to unknown and uncaught exception");
}

bool Bot::Run() {

	if(!OnRun())
		return false;

	//wait till shutdown
	size_t nSleep = 0;
	while(!shutdownReceived) {
		if(nSleep==0)
			WatchDog();

		sleep(1);
		++nSleep;
		if(cacheLogInterval > 0 && nSleep > cacheLogInterval)
			nSleep = 0;
	}

	return true;
}

bool Bot::Init(int argc, char** argv) {

	if(!InitDefaultParameters())
		return false;
	if(!Config().Init(argc, argv))
		return false;

	return OnInit();
}

bool Bot::PreInit(){
	return OnPreInit();
}

bool Bot::PostInit()
{
	//init logging at first
	InitLogging();
	if(log::Logging::IsLogLevelTrace()) {
		std::string dump;
		configManager.DumpConfig(dump);
		log::Logging::LogTrace("config:\n" + dump);	}

	//init database configs
	bool bSuccessDB = InitDatabaseConfigs();
	if(!bSuccessDB)
		return false;

	//init caches
	bool bSuccessCache = InitCacheConfigParams();
	if(!bSuccessCache)
		return false;

	//usage specified, print it and exit this process
	bool usageFlag = false;
	if(Config().GetValue("h",usageFlag) && usageFlag){
		Config().PrintUsage();
		return false; }

	//Daemonize return false, when in parent process
	//forked successfully => exit this process
	bool daemonize = false;
	if(Config().GetValue("D",daemonize)){
		if(daemonize) {
			if(!Daemonize())
				return false;
		}
	}

	//switch user and/or group
	bool bSwitch = false;
	std::string userID;
	uid_t newUid = 0;
	std::string groupID;
	gid_t newGid = 0;
	if ( Config().GetValue("user",userID) )
	{
		newUid = atoi(userID.c_str());
		bSwitch = true;
	}
	if ( Config().GetValue("group",groupID) )
	{
		newGid = atoi(groupID.c_str());
		bSwitch = true;
	}
	if(bSwitch)
		SwitchUser(newUid,newGid);

	InitPerformanceLoggingParams();
	return OnPostInit();
}

bool Bot::WatchDog(){
	if(cacheLogInterval > 0) {

		struct tm now;
		tools::TimeTools::NowUTC(now);
		database::DatabaseConnection* db = DB().Connection();

		database::cachehtmlTableBase cacheHtml;
		cacheHtml.Set_size(caching::CacheHtml::GetSize());
		cacheHtml.Set_matches(caching::CacheHtml::GetMatches());
		cacheHtml.Set_misses(caching::CacheHtml::GetMisses());
		cacheHtml.Set_action_time(now);
		cacheHtml.Insert(db);

		database::cachesubdomainTableBase cacheSubdomain;
		cacheSubdomain.Set_size(caching::CacheSubdomain::GetSize());
		cacheSubdomain.Set_matches(caching::CacheSubdomain::GetMatches());
		cacheSubdomain.Set_misses(caching::CacheSubdomain::GetMisses());
		cacheSubdomain.Set_action_time(now);
		cacheSubdomain.Insert(db);

		database::cachesecondleveldomainTableBase cacheSecondLevel;
		cacheSecondLevel.Set_size(caching::CacheSecondLevelDomain::GetSize());
		cacheSecondLevel.Set_matches(caching::CacheSecondLevelDomain::GetMatches());
		cacheSecondLevel.Set_misses(caching::CacheSecondLevelDomain::GetMisses());
		cacheSecondLevel.Set_action_time(now);
		cacheSecondLevel.Insert(db);

		database::cacheurlTableBase cacheUrl;
		cacheUrl.Set_size(caching::CacheDatabaseUrl::GetSize());
		cacheUrl.Set_matches(caching::CacheDatabaseUrl::GetMatches());
		cacheUrl.Set_misses(caching::CacheDatabaseUrl::GetMisses());
		cacheUrl.Set_action_time(now);
		cacheUrl.Insert(db);

		database::cacheparsedTableBase cacheParsed;
		cacheParsed.Set_size(caching::CacheParsed::GetSize());
		cacheParsed.Set_matches(caching::CacheParsed::GetMatches());
		cacheParsed.Set_misses(caching::CacheParsed::GetMisses());
		cacheParsed.Set_action_time(now);
		cacheParsed.Insert(db);

		database::cacherobotsTableBase cacheRobots;
		cacheRobots.Set_size(caching::CacheRobotsTxt::GetSize());
		cacheRobots.Set_matches(caching::CacheRobotsTxt::GetMatches());
		cacheRobots.Set_misses(caching::CacheRobotsTxt::GetMisses());
		cacheRobots.Set_action_time(now);
		cacheRobots.Insert(db);
	}
	return OnWatchDog();
}

bool Bot::Shutdown()
{
	bool shutdownSuccess = OnShutdown();

	DB().DestroyConnection();
	if(dbConfig)
		delete dbConfig;
	dbConfig = 0;

	if(logging)
		delete logging;
	logging = NULL;

	return shutdownSuccess;
}


}
