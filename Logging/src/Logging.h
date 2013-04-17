/**
 * @file Logging.h
 * @author Moritz Wagner
 * @date 29.01.2012
 */

#pragma once

#include <string>
#include <sstream>
#include <map>

#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/syscall.h>

#include <Mutex.h>

namespace log {

/**
 * @brief implements generic logging functionality.
 */
class Logging
{
public:
	/**
	 * @enum LogLevel
	 * @brief log level
	 */
    enum LogLevel
    {
    	/**
    	 * errors
    	 */
    	LOGLEVEL_ERROR = 0,

		/**
		* warnings
		*/
		LOGLEVEL_WARN  = 1,

		/**
		* information
		*/
		LOGLEVEL_INFO  = 2,

		/**
		* debug
		*/
		LOGLEVEL_TRACE = 3,

		/**
		* do not use this
		*/
		LOGLEVEL_MAX   = 10000
    };

protected:
	Logging();

public:
	virtual ~Logging();

	/**
	 * log an error.
	 * @param msg log message.
	 */
	static void LogError(const std::string& msg) { Log(LOGLEVEL_ERROR,msg); }

	/**
	 * log a warning.
	 * @param msg log message.
	 */
	static void LogWarn(const std::string& msg) { Log(LOGLEVEL_WARN,msg); }

	/**
	 * log an information.
	 * @param msg log message.
	 */
	static void LogInfo(const std::string& msg) { Log(LOGLEVEL_INFO,msg); }

	/**
	 * log a debug information.
	 * @param msg log message.
	 */
	static void LogTrace(const std::string& msg) { Log(LOGLEVEL_TRACE,msg); }

	/**
	 * register a current thread assigning it a name.
	 * @param threadName thread name.
	 */
	static void RegisterThreadID(const std::string& threadName);

	/**
	 * set the name of the application.
	 * @param applicationNameIn application name.
	 */
	static void SetApplicationName(const std::string& applicationNameIn);

	/**
	 * set the maximum length of a log message.
	 * @param maxLogMsgLengthIn maximum length.
	 */
	static void SetMaxLogLength(int maxLogMsgLengthIn);

	/**
	 * set the log level.
	 * @param logLevelIn log level.
	 */
	static void SetLogLevel(LogLevel logLevelIn);

	/**
	 * log a message.
	 * @param levelMsg log level.
	 * @param msg log message.
	 */
	static void Log(const LogLevel levelMsg,const std::string& msg);

	/**
	 * log a message.
	 * @param levelMsg log level.
	 * @param fmt format string.
	 */
	static void Log(const LogLevel levelMsg,const char* fmt,...);

	/**
	 * get the log level.
	 */
	static LogLevel GetLogLevel();

	/**
	 * get the maximum length of a log message.
	 * @return maximum length.
	 */
	static int GetMaxLogLength();

	/**
	 * checks if current log level is debug.
	 * @return false if not debug, true if debug (LOGLEVEL_TRACE).
	 */
	static bool IsLogLevelTrace();

	/**
	 * creates time string from log output.
	 * @param timeString time string.
	 */
	static void GetTimeString(std::string& timeString);

protected:
	/**
	 * gets the log level as a string.
	 * @param logLevel log level.
	 * @param logLevelString log level as a string.
	 */
	static void GetLogLevelString(const LogLevel logLevel, std::string& logLevelString);

	/**
	 * gets process info as a string.
	 * @param applicationName application name.
	 * @param pidTIDString gets filled with process information.
	 */
	static void GetPIDTIDString(const std::string& applicationName,std::string& pidTIDString);

protected:
	/**
	 * application name.
	 */
	std::string applicationName;

	/**
	 * map of thread names.
	 */
	std::map<long int,std::string> threadNames;

private:
	virtual void OnLog(const LogLevel levelMsg,const std::string& msg)=0;

	void SetMaxLogLength_Intern(int maxLogMsgLength);
	void SetLogLevel_Intern(LogLevel logLevel);
	void SetApplicationName_Intern(const std::string& applicationName);
	void Log_Intern(const LogLevel levelMsg,const std::string& msg);

private:
	volatile bool isLocking;
	volatile LogLevel logLevel;
	volatile int maxLogMsgLength;

	static threading::Mutex mutex;
	static Logging* instance;
};

}
