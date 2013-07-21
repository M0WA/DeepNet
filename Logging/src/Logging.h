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
#include <ReadWriteLock.h>

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
		LOGLEVEL_MAX
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
	 * log an error.
	 * @param fmt format string.
	 */
	static void LogError(const char* fmt,...);

	/**
	 * log a warning.
	 * @param msg log message.
	 */
	static void LogWarn(const std::string& msg) { Log(LOGLEVEL_WARN,msg); }

	/**
	 * log a warning.
	 * @param fmt format string.
	 */
	static void LogWarn(const char* fmt,...);

	/**
	 * log an information.
	 * @param msg log message.
	 */
	static void LogInfo(const std::string& msg) { Log(LOGLEVEL_INFO,msg); }

	/**
	 * log a information.
	 * @param fmt format string.
	 */
	static void LogInfo(const char* fmt,...);

	/**
	 * log a debug information.
	 * @param msg log message.
	 */
	static void LogTrace(const std::string& msg) { Log(LOGLEVEL_TRACE,msg); }

	/**
	 * log a debug information.
	 * @param fmt format string.
	 */
	static void LogTrace(const char* fmt,...);

	/**
	 * log a debug information not respecting max log length.
	 * @param msg log message.
	 */
	static void LogTraceUnlimited(const std::string& msg) { LogUnlimited(LOGLEVEL_TRACE,msg); }

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
	static void SetMaxLogLength(size_t maxLogMsgLengthIn);

	/**
	 * get the maximum length of a log message.
	 * @return maximum length.
	 */
	static size_t GetMaxLogLength() { return (instance ? instance->maxLogMsgLength : 0); };

	/**
	 * set the log level.
	 * @param logLevelIn log level.
	 */
	static void SetLogLevel(LogLevel logLevelIn);

	/**
	 * log a message not respecting max log length.
	 * @param levelMsg log level.
	 * @param fmt format string.
	 */
	static void LogUnlimited(const LogLevel levelMsg,const char* fmt,...);

	/**
	 * log a message not respecting max log length.
	 * @param levelMsg log level.
	 * @param msg log message.
	 */
	static void LogUnlimited(const LogLevel levelMsg,const std::string& msg);

	/**
	 * logs at current log level
	 * @param msg log message.
	 */
	static void LogCurrentLevel(const std::string& msg) {
		Log(GetLogLevel(),msg);	}

	/**
	 * get the log level.
	 */
	static LogLevel GetLogLevel();

	/**
	 * checks if current log level is debug.
	 * @return false if not debug, true if debug (LOGLEVEL_TRACE).
	 */
	static bool IsLogLevelTrace();

	/**
	 * creates time string for log output.
	 * @param timeString time string.
	 */
	static void GetTimeString(std::string& timeString);

protected:
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

	/**
	 * gets a thread's name by it's thread id
	 * @param tid tid of thread
	 * @param threadName name of thread
	 * @return true if successful, false if unsuccessful
	 */
	static bool GetThreadNameByTID(const long int& tid, std::string& threadName);

protected:
	/**
	 * application name.
	 */
	std::string applicationName;

private:
	virtual void OnLog(const LogLevel levelMsg,const std::string& msg)=0;

	void SetMaxLogLength_Intern(size_t maxLogMsgLength);
	void SetLogLevel_Intern(LogLevel logLevel);
	void SetApplicationName_Intern(const std::string& applicationName);
	void Log_Intern(const LogLevel levelMsg, const size_t length,const std::string& msg);

private:
	volatile bool isLocking;
	volatile LogLevel logLevel;
	volatile size_t maxLogMsgLength;

	static threading::Mutex mutex;
	static Logging* instance;

	static threading::ReadWriteLock lockThreadNames;
	static std::map<long int,std::string> threadNames;
};

}
