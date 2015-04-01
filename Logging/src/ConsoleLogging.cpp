/**
 * @file ConsoleLogging.cpp
 * @author Moritz Wagner
 * @date 29.01.2012
 */

#include "ConsoleLogging.h"

#include <iostream>
#include <sstream>

namespace log {

ConsoleLogging::ConsoleLogging()
: Logging() {
	Logging::SetMaxLogLength(1024);
}

ConsoleLogging::~ConsoleLogging() {
}

void ConsoleLogging::OnLog(const LogLevel levelMsg,const std::string& msg)
{
	std::string timeString = "";
    GetTimeString(timeString);

	std::string pidTIDString = "";
    GetPIDTIDString(applicationName,pidTIDString);

    std::string logLevelString;
    GetLogLevelString(levelMsg,logLevelString);

    std::stringstream ssLog;
    ssLog << "[" << timeString << "]" << logLevelString << pidTIDString << ": " << msg;
    std::cout << ssLog.str() << std::endl << std::flush;
}

}
