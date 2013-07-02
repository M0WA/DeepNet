/**
 * @file DatabaseHelper.cpp
 * @author Moritz Wagner
 * @date 02.05.2012
 */

#include <Logging.h>

#include "DatabaseHelper.h"
#include "DatabaseConfig.h"

#include "../MySQL/MySQLConnection.h"
#include "../DB2/DB2Connection.h"

namespace database {

threading::Mutex DatabaseHelper::mutexLibraryInit;
volatile bool DatabaseHelper::isLibraryInitialized = false;
volatile size_t DatabaseHelper::libraryRefCount = 0;

DatabaseHelper::DatabaseHelper()
: dbConnection(0)
{
}

DatabaseHelper::~DatabaseHelper()
{
	DestroyConnection();
}

DatabaseConnection* DatabaseHelper::CreateConnection(DatabaseConfig* dbConfig, const bool logQuery)
{
	if(dbConnection) {
		log::Logging::LogWarn("recreating active database connection.");
		DestroyConnection(); }

	switch(dbConfig->GetType())
	{
	case database::DB_MYSQL:
		dbConnection = (DatabaseConnection*) new MySQLConnection(logQuery);
		break;

	case database::DB_IBM_DB2:
		dbConnection = (DatabaseConnection*) new DB2Connection(logQuery);
		break;

	default:
		return 0;
	}

	mutexLibraryInit.Lock();
	if(!isLibraryInitialized) {
		dbConnection->Initialize();
		isLibraryInitialized = true;
	}
	libraryRefCount++;
	mutexLibraryInit.Unlock();

	if(!dbConnection->Connect(dbConfig)) {
		DestroyConnection();
		return 0;}

	return dbConnection;
}

void DatabaseHelper::DestroyConnection(void)
{
	if(dbConnection)
	{
		dbConnection->Disconnect();

		mutexLibraryInit.Lock();
		libraryRefCount--;
		if(libraryRefCount <= 0) {
			dbConnection->Shutdown();
			isLibraryInitialized = false;
		}
		mutexLibraryInit.Unlock();

		delete dbConnection;
		dbConnection = 0;
	}
}

}
