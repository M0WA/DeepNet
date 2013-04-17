/*
 * DatabaseLoggingNotInitializedException.cpp
 *
 *  Created on: 22.09.2012
 *      Author: Moritz Wagner
 */

#include "DatabaseLoggingNotInitializedException.h"

namespace log {

DatabaseLoggingNotInitializedException::DatabaseLoggingNotInitializedException(
		const std::string& file,
		const int line,
		const std::string& function,
		const std::string& message)
: Exception(file,line,function,"Logging","DatabaseLoggingNotInitializedException",message){
}

DatabaseLoggingNotInitializedException::~DatabaseLoggingNotInitializedException() {
}

}
