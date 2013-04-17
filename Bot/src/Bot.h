/**
 * @file Bot.h
 * @author Moritz Wagner
 * @date 18.01.2012
 */

#pragma once

#include <string>
#include <vector>
#include <map>
#include <csignal>

#include "ConfigManager.h"
#include <DatabaseLayer.h>
#include <Mutex.h>

namespace errors {
	class Exception;
}

namespace log {
	class Logging;
}

namespace bot
{

/**
 * @brief base class for all (commandline-) applications.
 * All applications derive from this class.
 * It helps processing signals, exceptions,
 * commandline argument handling, logging etc.
 */
class Bot
{
protected:
	Bot();

public:
	virtual ~Bot();

public:
	/**
	 * this function starts the application.
	 * it returns when the application exits.
	 * @param argc number of commandline arguments.
	 * @param argv array of commandline arguments.
	 * @return false on error, true on success.
	 */
	bool Run(int argc, char** argv);

public:
	/**
	 * this function is called when an uncaught exception
	 * derived from errors::Exception occurs.
	 * @param ex exception caught by application
	 */
	virtual void OnException(errors::Exception& ex);

	/**
	 * this function is called when an uncaught exception
	 * occurs. exceptions derived from errors::Exception
	 * are caught separately.
	 * @see bot::Bot::OnException(errors::Exception&)
	 */
	virtual void OnException();

protected:
	/**
	 * gets the configuration of this bot::Bot.
	 * @see bot::ConfigManager
	 * @return associated bot::ConfigManager.
	 */
	ConfigManager& Config() { return configManager; }

	/**
	 * gets the database of this bot::Bot.
	 * @see database::DatabaseHelper
	 * @return associated database::DatabaseHelper.
	 */
	database::DatabaseHelper& DB() {return databaseHelper; }

protected:
	/**
	 * registers default commandline flags available for this bot.
	 * usually used to register application specific commandline flags.
	 */
	virtual void RegisterDefaultFlags(void);

	/**
	 * registers default commandline parameters available for this bot.
	 * usually used to register application specific commandline parameters.
	 */
	virtual void RegisterDefaultParams(void);

	/**
	 * initialization when configuration is initialized and validated.
	 * @return false on error, true on success.
	 */
	virtual bool OnPostInit();

	/**
	 * periodically called watchdog function.
	 * call interval is hardcoded in WATCHDOG_TIMER_INTERVAL.
	 * @return false on error, true on success.
	 */
	virtual bool OnWatchDog();

	/**
	 * called when configuration and initialization is comleted.
	 * usually used to initialize application specific commandline parameters.
	 * @return false on error, true on success.
	 */
	virtual bool OnInit()=0;

	/**
	 * called when all initialization is comleted and the applications starts running.
	 * when this function returns, the applications exits.
	 * @return false on error, true on success.
	 */
	virtual bool OnRun()=0;

	/**
	 * called before the application is shutting down.
	 * @return false on error, true on success.
	 */
	virtual bool OnShutdown()=0;

private:
	static void SignalHandler(int signum, siginfo_t* info, void* ucontext);

	bool RegisterSignalHandlers();

	void RegisterDatabaseConfigParams(void);
	bool InitDatabaseConfigs(void);

	void RegisterCacheConfigParams();
	bool InitCacheConfigParams();

	void RegisterPerformanceLoggingParams();
	void InitPerformanceLoggingParams();

	bool SwitchUser(const uid_t setUid, const gid_t setGid);
	void InitLogging();

private:
	bool Init();
	bool Shutdown();
	bool Daemonize();

private:
	static Bot* instance;
	static threading::Mutex signalMutex;

protected:
	/**
	 * true if application shall end.
	 */
	volatile bool shutdownReceived;

	/**
	 * database configuration.
	 */
	database::DatabaseConfig* dbConfig;

private:
	ConfigManager configManager;
	database::DatabaseHelper databaseHelper;

	log::Logging* logging;
	volatile bool restartAfterShutdown;

	uid_t orig_uid;
	gid_t orig_gid;

	uid_t cur_uid;
	gid_t cur_gid;

	bool enablePerformanceLog;
};

}
