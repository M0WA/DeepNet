/**
 * @file FileLogging.h
 * @author Moritz Wagner
 * @date 03.02.2012
 */

#pragma once

#include "Logging.h"

#include <fstream>
#include <string>

namespace log {

/**
 * @brief class for logging to a file.
 */
class FileLogging: public log::Logging
{
public:
	FileLogging();
	virtual ~FileLogging();

	/**
	 * flushes file to filesystem.
	 */
	void Flush();

	/**
	 * sets autoflush.
	 * @param instantFlush true to flush after each message.
	 */
	void SetFlush(const bool instantFlush);

	/**
	 * sets append mode.
	 * @param appendFile true to append to file.
	 */
	void SetAppend(const bool appendFile);

	/**
	 * sets filename of log file.
	 * @param logFile filename.
	 */
	void SetFileName(const std::string& logFile);

private:
	virtual void OnLog(const LogLevel levelMsg,const std::string& msg);

private:
	std::string logFile;
	std::ofstream file;

	bool instantFlush;
	bool appendFile;
};

}
