/**
 *
 * @file PostgreSQLConnection.cpp
 * @author Moritz Wagner
 * @date 12.06.2013
 *
 */

#include "PostgreSQLConnection.h"

#include <StringTools.h>
#include <Logging.h>

#include "DatabaseTypes.h"
#include "DatabaseConfig.h"

#include "InsertStatement.h"
#include "InsertOrUpdateStatement.h"
#include "UpdateStatement.h"
#include "DeleteStatement.h"

#include "DatabaseNotConnectedException.h"
#include "PostgreSQLInvalidStatementException.h"

namespace database {

PostgreSQLConnection::PostgreSQLConnection(const bool logQuery)
: database::DatabaseConnection(DB_POSTGRESQL,logQuery)
, connection(0)
, affectedRows(-1)
, lastInsertID(-1) {
}

PostgreSQLConnection::~PostgreSQLConnection() {
	if(Connected())
		Disconnect();
}

bool PostgreSQLConnection::Connect(DatabaseConfig* dbConfig){

	tools::StringTools::FormatString(
		connectionString,
		"host = '%s' "
		"port = '%d' "
		"dbname = '%s' "
		"user = '%s' "
		"password = '%s' ",
		dbConfig->GetHost().c_str(),
		dbConfig->GetPort(),
		dbConfig->GetUser().c_str(),
		dbConfig->GetPass().c_str(),
		dbConfig->GetDatabaseName().c_str()
	);

	connection = PQconnectdb(connectionString.c_str());
	return connection;
}

bool PostgreSQLConnection::Disconnect(void){

	if(connection)
		PQfinish(connection);
	connection = 0;
	connectionString.clear();
	return true;
}

bool PostgreSQLConnection::Connected(void){
	return connection;
}

void PostgreSQLConnection::Query(const std::string& query, std::vector<TableBase*>& results){

	if(!Connected()) {
		THROW_EXCEPTION(database::DatabaseNotConnectedException);}

	PGresult* res = Execute_Intern(query);

	//
	//TODO
	//

	PQclear(res);
}

void PostgreSQLConnection::Execute(const std::string& query) {
	 PQclear(Execute_Intern(query));
}

PGresult* PostgreSQLConnection::Execute_Intern(const std::string& query){

	if(!Connected()) {
		THROW_EXCEPTION(database::DatabaseNotConnectedException);}

	PGresult* res = PQexec(connection, query.c_str());
	if(!res) {
		THROW_EXCEPTION(database::PostgreSQLInvalidStatementException,query); }

	ExecStatusType type = PQresultStatus(res);
	switch(type) {

	// empty query string was executed
	case PGRES_EMPTY_QUERY:
		log::Logging::LogWarn("empty query in PostgreSQLConnection::Query(...)");
		lastInsertID = -1;
		affectedRows = -1;
		break;

	//a query command that doesn't return anything was executed properly
	case PGRES_COMMAND_OK:
		lastInsertID = -1;
		affectedRows = 0;
		//
		//TODO
		//
		break;

	//a query command that returns tuples was executed properly
	case PGRES_TUPLES_OK:
		//
		//TODO
		//
		break;

	//Copy Out data transfer in progress
	case PGRES_COPY_OUT:
	//Copy In data transfer in progress
	case PGRES_COPY_IN:
	//Copy In/Out data transfer in progress
	case PGRES_COPY_BOTH:
		//
		//TODO
		//
		break;

	//an unexpected response was recv'd from the backend
	case PGRES_BAD_RESPONSE:
	//notice or warning message
	case PGRES_NONFATAL_ERROR:
	//query failed
	case PGRES_FATAL_ERROR:
	default:
		lastInsertID = -1;
		affectedRows = -1;
		PQclear(res);
		res = 0;
		THROW_EXCEPTION(database::PostgreSQLInvalidStatementException,query);
		break;
	}

	return res;
}

void PostgreSQLConnection::Insert(const InsertStatement& stmt){

	if(!Connected()) {
		THROW_EXCEPTION(database::DatabaseNotConnectedException);}

	Execute( stmt.ToSQL(this).c_str() );
}

void PostgreSQLConnection::InsertOrUpdate(const InsertOrUpdateStatement& stmt){

	if(!Connected()) {
		THROW_EXCEPTION(database::DatabaseNotConnectedException);}

	Execute( stmt.ToSQL(this).c_str() );
}

void PostgreSQLConnection::Update(const UpdateStatement& stmt){

	if(!Connected()) {
		THROW_EXCEPTION(database::DatabaseNotConnectedException);}

	Execute( stmt.ToSQL(this).c_str() );
}

void PostgreSQLConnection::Select(const SelectStatement& stmt, std::vector<TableBase*>& results){

	if(!Connected()) {
		THROW_EXCEPTION(database::DatabaseNotConnectedException);}

	//
	//TODO
	//
}

void PostgreSQLConnection::Delete(const DeleteStatement& stmt){

	if(!Connected()) {
		THROW_EXCEPTION(database::DatabaseNotConnectedException);}

	Execute( stmt.ToSQL(this).c_str() );
}

void PostgreSQLConnection::TransactionStart(void){

	if(!Connected()) {
		THROW_EXCEPTION(database::DatabaseNotConnectedException);}

	//
	//TODO
	//
}

void PostgreSQLConnection::TransactionCommit(void){

	if(!Connected()) {
		THROW_EXCEPTION(database::DatabaseNotConnectedException);}

	//
	//TODO
	//
}

void PostgreSQLConnection::TransactionRollback(void){

	if(!Connected()) {
		THROW_EXCEPTION(database::DatabaseNotConnectedException);}

	//
	//TODO
	//
}

bool PostgreSQLConnection::LastInsertID(long long& lastInsertID){

	if(!Connected()) {
		THROW_EXCEPTION(database::DatabaseNotConnectedException);}

	//
	//TODO
	//

	return false;
}

bool PostgreSQLConnection::AffectedRows(long long& affectedRows){

	if(!Connected()) {
		THROW_EXCEPTION(database::DatabaseNotConnectedException);}

	//
	//TODO
	//

	return false;
}

bool PostgreSQLConnection::EscapeString(std::string& inEscape){

	if(!Connected()) {
		THROW_EXCEPTION(database::DatabaseNotConnectedException);}

	char* pszTmp = PQescapeLiteral(connection, inEscape.c_str(), inEscape.length());
	if(!pszTmp) {
		log::Logging::LogError("could not escape string: %s",inEscape.c_str());
		inEscape.clear();
		return false; }

	inEscape = pszTmp;
	PQfreemem(pszTmp);
	return true;
}

void PostgreSQLConnection::Initialize(){
}

void PostgreSQLConnection::Shutdown(){
}

}
