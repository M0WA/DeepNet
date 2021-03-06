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
 * helper class for a database connection.
 * use this class for creation and destruction of a connection.
 * @see database::MySQLConnection
 * @see database::DB2Connection
 * @see database::PostgreSQLConnection
 */
class DatabaseHelper {
public:
	DatabaseHelper();
	virtual ~DatabaseHelper();

public:
	/**
	 * create a new database connection.
	 * @param dbConfig database configuration.
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
	DatabaseConnection* Connection(void);

public:
	/**
	 * gets current database type
	 * @return database type
	 */
    static DatabaseType GetDatabaseType();

private:
    tools::Pointer<DatabaseConnection> dbConnection;

private:
    static volatile DatabaseType dbType;
    static threading::ReadWriteLock dbTypeMutex;

  	static threading::Mutex mutexLibraryInit;
  	static volatile bool isLibraryInitialized;
  	static volatile size_t libraryRefCount;
};

}
