/**
 * @file MySQLConnection.cpp
 * @author Moritz Wagner
 * @date 30.04.2012
 */

#include "MySQLConnection.h"

#include <cstring>
#include <mysql/mysqld_error.h>

#include <Logging.h>

#include "Statement.h"
#include "DeleteStatement.h"

#include "MySQLInsertStatement.h"
#include "MySQLInsertOrUpdateStatement.h"
#include "MySQLSelectStatement.h"
#include "MySQLUpdateStatement.h"

#include "MySQLTableBase.h"
#include "MySQLDatabaseConfig.h"

#include "DatabaseNotConnectedException.h"
#include "MySQLQueryResultStoreException.h"
#include "MySQLQueryErrorException.h"
#include "MySQLOperationTimeoutException.h"

#include <NotImplementedException.h>

namespace database {

MySQLConnection::MySQLConnection(const bool logQuery)
: DatabaseConnection(DB_MYSQL,logQuery)
, mysqlConnection(0)
, config(0)
{
	if (!mysql_thread_safe()) {
		THROW_EXCEPTION(errors::NotImplementedException,"current libmysqlclient is not compiled with thread support");
	}
}

MySQLConnection::~MySQLConnection()
{
	if(mysqlConnection)
		Disconnect();
	mysql_thread_end();
}

bool MySQLConnection::Connect(const DatabaseConfig* dbConfig)
{

	if(dbConfig->GetType() != GetDatabaseType()) {
		log::Logging::LogError("type of database config is wrong");
		return false;
	}

	config = reinterpret_cast<const MySQLDatabaseConfig*>(dbConfig);
	if(mysqlConnection)
	{
		Disconnect();
		log::Logging::LogWarn("closing established database connection due to a reconnect.");
	}

	mysqlConnection = mysql_init(mysqlConnection);

	my_bool one = 1;
	mysql_options(mysqlConnection,MYSQL_OPT_RECONNECT,(const char*)&one);
	mysql_options(mysqlConnection,MYSQL_OPT_COMPRESS, (const char*)&one);

	mysqlConnection = mysql_real_connect(
			mysqlConnection,
			config->GetHost().c_str(),
			config->GetUser().c_str(),
			config->GetPass().c_str(),
			config->GetDatabaseName().c_str(),
			config->GetPort(),
			NULL,
			CLIENT_MULTI_STATEMENTS|CLIENT_COMPRESS
			);

	if(!mysqlConnection)
	{
		const char* pszMySQLError = mysql_error(mysqlConnection);
		std::string msg = "mysql error: ";
		msg += std::string(pszMySQLError ? pszMySQLError : "N/A" );
		msg += "\n";
		log::Logging::LogError(msg);
	}
	else
	{
		mysql_autocommit(mysqlConnection,1);
	}

	log::Logging::LogInfo("connected to mysql-database");

	return true;
}

bool MySQLConnection::Disconnect()
{
	if(mysqlConnection) {
		mysql_close(mysqlConnection);
		log::Logging::LogInfo("disconnected from mysql-database");
	}
	mysqlConnection = NULL;
	return true;
}

bool MySQLConnection::Connected(void)
{
	if(mysqlConnection)
		return !mysql_ping(mysqlConnection);
	return false;
}

void MySQLConnection::Query(const std::string& query, std::vector<TableBase*>& results)
{
	Execute(query);

	MYSQL_RES* result = mysql_store_result(mysqlConnection);
	if(!result)
	{
		const char* pszMySQLError = mysql_error(mysqlConnection);
		std::string msg = "error while fetching query result: ";
		msg += std::string(pszMySQLError ? pszMySQLError : "N/A" ) + "\n";
		msg += "query: "+query+"\n";
		log::Logging::LogError(msg);
		THROW_EXCEPTION(MySQLQueryResultStoreException);
	}

	unsigned int  numFields  = mysql_num_fields  (result);
	MYSQL_FIELD * fieldNames = mysql_fetch_fields(result);
	MYSQL_ROW row;
	while( (row = mysql_fetch_row(result)) )
	{
		results.push_back(
			MySQLTableBase::CreateInstance(
				row,
				fieldNames,
				numFields));
	}
	mysql_free_result(result);
}

void MySQLConnection::Execute(const std::string& query, bool doRetry)
{
	if(logQuery){
		log::Logging::LogCurrentLevel("execute: " + query); }

	if(!mysqlConnection) {
		THROW_EXCEPTION(DatabaseNotConnectedException);
	}

	int nError = mysql_real_query(mysqlConnection,query.c_str(),query.size());
	if(nError) {

		unsigned int errNoMysql = mysql_errno(mysqlConnection);
		if(errNoMysql == ER_LOCK_DEADLOCK || errNoMysql == ER_LOCK_WAIT_TIMEOUT) {
			bool exceptionOccurred = true;
			if(doRetry) {
				log::Logging::LogWarn("timeout or deadlock in mysql database connection, retrying statement: %s",query.c_str());
				exceptionOccurred = true;
				for(int i = 0; exceptionOccurred && i < 3; i++) {
					try{
						Execute(query,false);
						exceptionOccurred = false;
					}
					catch(MySQLOperationTimeoutException& e) {
						exceptionOccurred = true;
					}
				}
			}
			if(exceptionOccurred){
				if(logQuery){
					log::Logging::LogCurrentLevel("execute: " + query); }
				THROW_EXCEPTION(MySQLOperationTimeoutException);
			}
		}
		else {
			std::string mySQLError = mysql_error(mysqlConnection);
			if(logQuery){
				log::Logging::LogCurrentLevel("execute: " + query); }
			THROW_EXCEPTION(MySQLQueryErrorException,mySQLError,query);
		}
	}
}

void MySQLConnection::Execute(const std::string& query)
{
	Execute(query,true);
}

void MySQLConnection::Insert(const InsertStatement& stmt) {

	MySQLInsertStatement mysqlStmt(&stmt);
	Execute(mysqlStmt.ToSQL(this));
}

void MySQLConnection::InsertOrUpdate(const InsertOrUpdateStatement& stmt) {

	MySQLInsertOrUpdateStatement mysqlStmt(&stmt);
	Execute(mysqlStmt.ToSQL(this));
}

void MySQLConnection::Update(const UpdateStatement& stmt)
{
	MySQLUpdateStatement mysqlStmt(&stmt);
	Execute(mysqlStmt.ToSQL(this));
}

void MySQLConnection::Select(const SelectStatement& stmt, std::vector<TableBase*>& results)
{
	MySQLSelectStatement mysqlStmt(&stmt);
	Query(mysqlStmt.ToSQL(this), results);
}

void MySQLConnection::Delete(const DeleteStatement& stmt)
{
	Execute(stmt.ToSQL(this));
}

void MySQLConnection::TransactionStart(void)
{
	mysql_autocommit(mysqlConnection,0);
	Execute("START TRANSACTION");
}

void MySQLConnection::TransactionCommit(void)
{
	try {
		Execute("COMMIT");
	}
	catch (...) {
		mysql_autocommit(mysqlConnection,1);
		throw;
	}
	mysql_autocommit(mysqlConnection,1);
}

void MySQLConnection::TransactionRollback(void)
{
	try {
		Execute("ROLLBACK");
	}
	catch (...) {
		mysql_autocommit(mysqlConnection,1);
		throw;
	}
	mysql_autocommit(mysqlConnection,1);
}

bool MySQLConnection::LastInsertID(long long& lastInsertID)
{
	lastInsertID = (long long)mysql_insert_id(mysqlConnection);
	return true;
}

bool MySQLConnection::AffectedRows(long long& affectedRows)
{
	affectedRows = (long long)mysql_affected_rows(mysqlConnection);
	return true;
}

bool MySQLConnection::EscapeString(std::string& inEscape)
{
	if(inEscape.empty())
		return true;

	int nMaxLenToString = (inEscape.length()*2)+1;
	char* pszConverted = new char[nMaxLenToString];
	unsigned long converted =(bool)mysql_real_escape_string(mysqlConnection,pszConverted,inEscape.c_str(),inEscape.length());
	if(converted && pszConverted)
		inEscape.assign(pszConverted,strlen(pszConverted));
	delete [] pszConverted;
	return (bool)converted;
}

void MySQLConnection::Initialize() {

	if(log::Logging::IsLogLevelTrace()) {
		log::Logging::LogTrace("initializing mysql library"); }

	mysql_library_init(0, NULL, NULL);
}

void MySQLConnection::Shutdown() {

	 mysql_library_end();
}

}
