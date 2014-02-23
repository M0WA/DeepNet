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
#include "../PostgreSQL/PostgreSQLConnection.h"

#include "DatabaseNotConnectedException.h"

namespace database {

threading::Mutex DatabaseHelper::mutexLibraryInit;
volatile bool DatabaseHelper::isLibraryInitialized(false);
volatile size_t DatabaseHelper::libraryRefCount(0);

threading::ReadWriteLock DatabaseHelper::dbTypeMutex;
volatile DatabaseType DatabaseHelper::dbType(DB_INVALID_TYPE);

DatabaseHelper::DatabaseHelper()
: dbConnection(0)
, config(0)
{
}

DatabaseHelper::~DatabaseHelper()
{
	DestroyConnection();
}

DatabaseType DatabaseHelper::GetDatabaseType() {
	DatabaseType retType(DB_INVALID_TYPE);
	dbTypeMutex.WaitForReadLock();
	retType = dbType;
	dbTypeMutex.ReleaseLock();
	return retType;
}

DatabaseConnection* DatabaseHelper::CreateConnection(const DatabaseConfig* dbConfig)
{
	if(!dbConnection.IsNull()) {
		log::Logging::LogWarn("recreating active database connection.");
		DestroyConnection(); }

	if(dbType == DB_INVALID_TYPE) {
		dbTypeMutex.WaitForWriteLock();
		dbType = dbConfig->GetType();
		dbTypeMutex.ReleaseLock();
	}
	else {
		dbTypeMutex.WaitForReadLock();
		bool matchTypes = dbType == dbConfig->GetType();
		dbTypeMutex.ReleaseLock();

		if(!matchTypes) {
			log::Logging::LogError("only one type of database connection can be used per process");
			dbConnection.Release();
			return 0; }
	}

	switch(dbConfig->GetType())
	{
	case database::DB_MYSQL:
		dbConnection.Set(dynamic_cast<DatabaseConnection*>(new MySQLConnection()),true);
		break;

	case database::DB_IBM_DB2:
		dbConnection.Set(dynamic_cast<DatabaseConnection*>(new DB2Connection()),true);
		break;

	case database::DB_POSTGRESQL:
		dbConnection.Set(dynamic_cast<DatabaseConnection*>(new PostgreSQLConnection()),true);
		break;

	default:
		return 0;
	}

	mutexLibraryInit.Lock();
	if(!isLibraryInitialized) {
		dbConnection.Get()->Initialize();
		isLibraryInitialized = true;
	}
	libraryRefCount++;
	mutexLibraryInit.Unlock();

	if(!dbConnection.Get()->Connect(dbConfig)) {
		DestroyConnection();
		return 0;}

	config = dbConfig;
	return dbConnection;
}

void DatabaseHelper::DestroyConnection(void)
{
	if(!dbConnection.IsNull())
	{
		dbConnection.Get()->Disconnect();

		mutexLibraryInit.Lock();
		libraryRefCount--;
		if(libraryRefCount <= 0) {
			dbConnection.Get()->Shutdown();
			isLibraryInitialized = false;
		}
		mutexLibraryInit.Unlock();

		dbConnection.Release();
	}
	config = 0;
}

database::DatabaseConnection* DatabaseHelper::Connection(void)
{
	if(dbConnection.IsNull()) {
		THROW_EXCEPTION(database::DatabaseNotConnectedException);
	}
	return dbConnection.Get();
}

}
