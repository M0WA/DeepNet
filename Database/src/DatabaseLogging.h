/**
 * @file DatabaseLogging.h
 * @author Moritz Wagner
 * @date 22.09.2012
 */

#pragma once

#include <Logging.h>

namespace database {
	class DatabaseHelper;
	class DatabaseConfig;
}

namespace log {

/**
 * @brief class for logging to database.
 * @see log::Logging
 * this class is used to redirect logging to database.
 */
class DatabaseLogging : public Logging {
public:
	/**
	 * construct using database configuration.
	 * @param dbConfig database configuration
	 */
	DatabaseLogging(database::DatabaseConfig* dbConfig);
	virtual ~DatabaseLogging();

public:
	/**
	 * log message.
	 * @param levelMsg log level of message.
	 * @param msg the message.
	 */
	virtual void OnLog(const LogLevel levelMsg,const std::string& msg);

private:
	database::DatabaseHelper* dbHelper;
};

}

