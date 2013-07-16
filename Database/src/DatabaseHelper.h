/**
 * @file DatabaseHelper.h
 * @author Moritz Wagner
 * @date 02.05.2012
 */

#pragma once

#include <ctime>
#include <cstring>
#include <string>

#include <Mutex.h>
#include <ReadWriteLock.h>
#include <Pointer.h>

#include "DatabaseTypes.h"

namespace database {

class DatabaseConfig;
class DatabaseConnection;

/**
 * @brief helper class for a database connection.
 * @see database::MySQLDatabaseConnection
 * @see database::DB2DatabaseConnection
 * helper class for a database connection.
 * use this class for creation and destruction of a connection.
 */
class DatabaseHelper {
public:
	DatabaseHelper();
	virtual ~DatabaseHelper();

public:
	/**
	 * create a new database connection.
	 * @param dbConfig database configuration.
	 * @param logQuery true if all queries should be logged.
	 * @return NULL on error, database connection on success.
	 */
	DatabaseConnection* CreateConnection(const DatabaseConfig* dbConfig);

	/**
	 * destroys current database connection.
	 */
	void DestroyConnection(void);

	/**
	 * gets current database connection.
	 * @return current database connection.
	 */
	inline DatabaseConnection* Connection(void) { return dbConnection.Get(); }

    //mysql datetime conversion functions
  public:
	/**
	 * TODO: document
	 * move this function to TimeTools.
	 * @param in
	 * @param out
	 * @return
	 */
    inline static bool TmToDateTime(const struct tm& in, std::string& out)
    {
		const char* timeStringFormat = "%Y-%m-%d %H:%M:%S";
		const int timeStringLength = 40;
		char timeString[timeStringLength];
		strftime(timeString, timeStringLength, timeStringFormat, &in);
		out = std::string(timeString);
		return true;
    }

	/**
	 * TODO: document
	 * move this function to TimeTools.
	 * @param in
	 * @param out
	 * @return
	 */
    inline static bool DateTimeToTm(const std::string& in, struct tm& out )
    {
    	memset(&out,0,sizeof(struct tm));
		if(!in.empty() && in.compare("0000-00-00 00:00:00") != 0)
			return strptime(in.c_str(), "%Y-%m-%d %H:%M:%S", &out) != NULL;
		return true;
    }

    static DatabaseType GetDatabaseType();

  private:
    static volatile DatabaseType dbType;
    static threading::ReadWriteLock dbTypeMutex;

  private:
    tools::Pointer<DatabaseConnection> dbConnection;

  private:
  	static threading::Mutex mutexLibraryInit;
  	static volatile bool isLibraryInitialized;
  	static volatile size_t libraryRefCount;
};

}
