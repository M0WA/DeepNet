/**
 * @file FileLogging.cpp
 * @author Moritz Wagner
 * @date 03.02.2012
 */

#include "FileLogging.h"

#include <sstream>

namespace log {

FileLogging::FileLogging()
: Logging()
, instantFlush(false)
, appendFile(false)	{
	Logging::SetMaxLogLength(1024);
}

FileLogging::~FileLogging() {
	if( file.is_open() )
		file.close();
}

void FileLogging::SetFlush(const bool instantFlush) {
	this->instantFlush = instantFlush;
	if( instantFlush && file.is_open() )
		Flush();
}

void FileLogging::SetAppend(const bool appendFile) {
	this->appendFile = appendFile;
}

void FileLogging::SetFileName(const std::string& logFile) {
	if( file.is_open() && ( logFile.compare(this->logFile) != 0 ) )
		file.close();

	this->logFile = logFile;

	std::ios_base::openmode mode = std::ios_base::out | (appendFile ? std::ios_base::app : std::ios_base::trunc );
	file.open(logFile.c_str(),mode);

	Log(Logging::LOGLEVEL_TRACE,"initialized file logging successfully");
}

void FileLogging::Flush() {
	file << std::flush;
}

void FileLogging::OnLog(const LogLevel levelMsg,const std::string& msg) {
	if(!file.is_open())
		return;

	std::string timeString = "";
    GetTimeString(timeString);

	std::string pidTIDString = "";
    GetPIDTIDString(applicationName,pidTIDString);

    std::string logLevelString;
    GetLogLevelString(levelMsg,logLevelString);

    std::stringstream ssLog;
    ssLog << "[" << timeString << "]" << logLevelString << pidTIDString << ": " << msg << std::endl;

    file << ssLog.str();

    if(instantFlush)
    	Flush();
}

}
