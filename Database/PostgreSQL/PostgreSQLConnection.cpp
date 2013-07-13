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

#include "TableDefinition.h"
#include "TableColumnDefinition.h"
#include "TableColumn.h"

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
	affectedRows = lastInsertID = -1;
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
		affectedRows = -1;
		lastInsertID = -1;
		THROW_EXCEPTION(database::PostgreSQLInvalidStatementException,query); }

	std::stringstream ssIn;
	ssIn <<	PQcmdTuples(res);
	ssIn >> affectedRows;

	ExecStatusType type = PQresultStatus(res);
	switch(type) {

	// empty query string was executed
	case PGRES_EMPTY_QUERY:
		log::Logging::LogWarn("empty query in PostgreSQLConnection::Query(...)");
		break;

	//a query command that doesn't return anything was executed properly
	case PGRES_COMMAND_OK:
	//a query command that returns tuples was executed properly
	case PGRES_TUPLES_OK:
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
		affectedRows = -1;
		lastInsertID = -1;
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

	lastInsertID = -1;
	std::string sqlStmt(stmt.ToSQL(this));

	const database::TableDefinition* def = stmt.GetConstTableBase()->GetConstTableDefinition();
	std::string primaryKey = "";
	const std::vector< database::TableColumnDefinition* >& cols = def->GetConstColumnDefinitions();
	std::vector<database::TableColumnDefinition*>::const_iterator iCol = cols.begin();
	for(; iCol != cols.end(); ++iCol) {
		if((*iCol)->IsPrimaryKey()) {
			primaryKey = " RETURNING " + (*iCol)->GetColumnName();
			break;
		}
	}

	if(!primaryKey.empty()) {
		log::Logging::LogWarn("could not find primary key for statement: " + sqlStmt); }
	sqlStmt += primaryKey;

	std::vector<database::TableBase*> results;
	Query(sqlStmt, results);

	if(results.size() != 1) {
		log::Logging::LogWarn("could not find last insert id for statement: " + sqlStmt); }
	if(results.size() < 1 ) {
		return; }

	database::TableBase* resultTable = results.at(0);
	const std::vector< database::TableColumn* >& resCols = resultTable->GetConstColumns();
	if(resCols.size() != 1) {
		log::Logging::LogWarn("could not find last insert id column for statement: " + sqlStmt); }
	if(resCols.size() < 1 ) {
		return; }

	database::TableColumn* resCol = resCols.at(0);
	resCol->Get(lastInsertID);

	std::vector<database::TableBase*>::iterator iDel = results.begin();
	for(;iDel != results.end();++iDel) {
		delete (*iDel);	}
}

void PostgreSQLConnection::InsertOrUpdate(const InsertOrUpdateStatement& stmt){

	if(!Connected()) {
		THROW_EXCEPTION(database::DatabaseNotConnectedException);}

	lastInsertID = -1;
	PGresult* res = Execute_Intern(stmt.ToSQL(this).c_str());

	//
	//TODO
	//

	PQclear(res);
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
	lastInsertID = this->lastInsertID;
	return lastInsertID > -1;
}

bool PostgreSQLConnection::AffectedRows(long long& affectedRows){
	affectedRows = this->affectedRows;
	return affectedRows > -1;
}

bool PostgreSQLConnection::EscapeString(std::string& inEscape){

	if(!Connected()) {
		THROW_EXCEPTION(database::DatabaseNotConnectedException);}

	char* pszTmp = PQescapeLiteral(connection, inEscape.c_str(), inEscape.length());
	if(!pszTmp) {
		log::Logging::LogError(
			"could not escape string: %s",
			inEscape.c_str());
		inEscape.clear();
		return false;
	}

	inEscape = pszTmp;
	PQfreemem(pszTmp);
	return true;
}

/*
void PostgreSQLConnection::Initialize(){
}

void PostgreSQLConnection::Shutdown(){
}
*/

}
