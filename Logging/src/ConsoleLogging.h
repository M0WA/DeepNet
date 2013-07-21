/**
 * @file ConsoleLogging.h
 * @author Moritz Wagner
 * @date 29.01.2012
 */

#pragma once

#include "Logging.h"

#include <iostream>
#include <sstream>
#include <string>

namespace log {

/**
 * @brief class for logging to terminal console.
 * @see logging::Log
 */
class ConsoleLogging : public Logging
{
public:
	ConsoleLogging();
	virtual ~ConsoleLogging();

private:
	virtual void OnLog(const LogLevel levelMsg,const std::string& msg);
};

}
