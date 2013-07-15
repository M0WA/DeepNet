/**
 *
 * @file PostgreSQLConnection.cpp
 * @author Moritz Wagner
 * @date 12.06.2013
 *
 */

#include "PostgreSQLConnection.h"

#include <TimeTools.h>
#include <StringTools.h>
#include <Logging.h>

#include "DatabaseTypes.h"
#include "DatabaseConfig.h"

#include "SelectStatement.h"
#include "InsertStatement.h"
#include "InsertOrUpdateStatement.h"
#include "UpdateStatement.h"
#include "DeleteStatement.h"
#include "TableColumn.h"

#include "PostgreSQLDatabaseConfig.h"
#include "PostgreSQLTableBase.h"
#include "PostgreSQLInsertStatement.h"
#include "PostgreSQLInsertOrUpdateStatement.h"
#include "PostgreSQLInsertOrUpdateAffectedKeyStatement.h"

#include "DatabaseNoColumnsException.h"
#include "DatabaseNotConnectedException.h"
#include "PostgreSQLInvalidStatementException.h"

namespace database {

PostgreSQLConnection::PostgreSQLConnection()
: database::DatabaseConnection(DB_POSTGRESQL)
, config(0)
, connection(0)
, affectedRows(-1)
, lastInsertID(-1){
}

PostgreSQLConnection::~PostgreSQLConnection() {
	if(Connected())
		Disconnect();
}

bool PostgreSQLConnection::Connect(const DatabaseConfig* dbConfig){

	if(PQisthreadsafe() == 0) {
		log::Logging::LogError("please use a thread-safe version of libpq");
		return false; }

	if(dbConfig->GetType() != GetDatabaseType()) {
		log::Logging::LogError("type of database config is wrong");
		return false;
	}
	else {
		config = reinterpret_cast<const PostgreSQLDatabaseConfig*>(dbConfig);
	}

	tools::StringTools::FormatString(
		connectionString,
		"host = '%s' "
		"port = '%d' "
		"dbname = '%s' "
		"user = '%s' "
		"password = '%s' ",
		dbConfig->GetHost().c_str(),
		dbConfig->GetPort(),
		dbConfig->GetDatabaseName().c_str(),
		dbConfig->GetUser().c_str(),
		dbConfig->GetPass().c_str()
	);

	connection = PQconnectdb(connectionString.c_str());
	if (PQstatus(connection) != CONNECTION_OK) {
		log::Logging::LogError("Connection to database failed: %s",	PQerrorMessage(connection));
		Disconnect(); }
	return connection;
}

bool PostgreSQLConnection::Disconnect(void){

	if(connection)
		PQfinish(connection);

	config = 0;
	connection = 0;
	connectionString.clear();
	affectedRows = lastInsertID = -1;
	return true;
}

bool PostgreSQLConnection::Connected(void){

	if(!connection)
		return false;

	if (PQstatus(connection) != CONNECTION_OK) {
		log::Logging::LogError("Connection to database failed: %s",	PQerrorMessage(connection));
		Disconnect(); }

	return connection;
}

void PostgreSQLConnection::Query(const std::string& query, std::vector<TableBase*>& results){

	if(!Connected()) {
		THROW_EXCEPTION(database::DatabaseNotConnectedException);}

	PGresult* res = Execute_Intern(query);
	if(!res)
		return;

	int noRows = PQntuples(res);
	if(noRows <= 0) {
		log::Logging::LogInfo("no rows in resultset for statement: %s",query.c_str());
		return; }

	int noCol = PQnfields(res);
	if(noCol <= 0) {
		log::Logging::LogWarn("no columns in resultset for statement: %s",query.c_str());
		THROW_EXCEPTION(database::DatabaseNoColumnsException);
		return; }

	for(int curRow = 0; curRow <  noRows;  ++curRow) {
		results.push_back(PostgreSQLTableBase::CreateInstance(res,curRow));	}

	PQclear(res);
}

void PostgreSQLConnection::Execute(const std::string& query) {
	if(!Connected()) {
		THROW_EXCEPTION(database::DatabaseNotConnectedException);}

	 PQclear(Execute_Intern(query));
}

PGresult* PostgreSQLConnection::Execute_Intern(const std::string& query){

	if(!Connected()) {
		THROW_EXCEPTION(database::DatabaseNotConnectedException);}

	if(config->GetLogQuery()){
		log::Logging::LogCurrentLevel("execute: " + query); }

	PGresult* res = PQexec(connection, query.c_str());
	if(!res) {
		affectedRows = -1;
		lastInsertID = -1;
		THROW_EXCEPTION(database::PostgreSQLInvalidStatementException, connection, query); }

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
		THROW_EXCEPTION(database::PostgreSQLInvalidStatementException,connection,query);
		break;
	}

	return res;
}

void PostgreSQLConnection::Insert(const InsertStatement& stmt){

	if(!Connected()) {
		THROW_EXCEPTION(database::DatabaseNotConnectedException);}

	PostgreSQLInsertStatement pqStmt(stmt);

	lastInsertID = -1;
	PGresult* res = Execute_Intern(pqStmt.ToSQL(this).c_str());
	SetLastInsertID(res);
	if(lastInsertID == -1) {

	}
	PQclear(res);
}

void PostgreSQLConnection::InsertOrUpdate(const InsertOrUpdateStatement& stmt){

	if(!Connected()) {
		THROW_EXCEPTION(database::DatabaseNotConnectedException);}

//	TransactionStart();

	try {
		//insert or update entries
		PostgreSQLInsertOrUpdateStatement pgStmt(stmt);
		lastInsertID = -1;
		PGresult* res = Execute_Intern(pgStmt.ToSQL(this).c_str());
		SetLastInsertID(res);
		PQclear(res);

		//check if we need to select the affected key by hand
		if(lastInsertID == -1) {

			long long tmpAffected = affectedRows;

			PostgreSQLInsertOrUpdateAffectedKeyStatement selectIDStmt(stmt);
			SelectResultContainer<TableBase> results;
			DatabaseConnection::Select(dynamic_cast<const SelectStatement&>(selectIDStmt),results);

			if(results.Size() != 1) {
				THROW_EXCEPTION(database::PostgreSQLInvalidStatementException,0,selectIDStmt.ToSQL(this));
			}
			results.ResetIter();
			const std::vector<TableColumn*>& cols = results.GetConstIter()->GetConstColumns();
			if(cols.size() != 1) {
				THROW_EXCEPTION(database::PostgreSQLInvalidStatementException,0,selectIDStmt.ToSQL(this));
			}

			TableColumn* priKeyCol = cols.at(0);
			priKeyCol->Get(lastInsertID);

			affectedRows = tmpAffected;
		}
	}
	catch(errors::Exception& e) {
		try {
//			TransactionRollback();
		}
		catch(...) {
			log::Logging::LogError("could not rollback after error");
		}
		throw;
	}

//	TransactionCommit();
}

void PostgreSQLConnection::Update(const UpdateStatement& stmt){

	if(!Connected()) {
		THROW_EXCEPTION(database::DatabaseNotConnectedException);}

	Execute( stmt.ToSQL(this).c_str() );
}

void PostgreSQLConnection::Delete(const DeleteStatement& stmt){

	if(!Connected()) {
		THROW_EXCEPTION(database::DatabaseNotConnectedException);}

	Execute( stmt.ToSQL(this).c_str() );
}

void PostgreSQLConnection::Select(const SelectStatement& stmt, std::vector<TableBase*>& results){

	if(!Connected()) {
		THROW_EXCEPTION(database::DatabaseNotConnectedException);}

	Query( stmt.ToSQL(this).c_str(), results);
}

void PostgreSQLConnection::TransactionStart(void){

	if(!Connected()) {
		THROW_EXCEPTION(database::DatabaseNotConnectedException);}

	Execute("BEGIN");
}

void PostgreSQLConnection::TransactionCommit(void){

	if(!Connected()) {
		THROW_EXCEPTION(database::DatabaseNotConnectedException);}

	Execute("COMMIT");
}

void PostgreSQLConnection::TransactionRollback(void){

	if(!Connected()) {
		THROW_EXCEPTION(database::DatabaseNotConnectedException);}

	Execute("ROLLBACK");
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

	if(inEscape.empty())
		return true;

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

	//remove leading and preceding '
	//which is added by PQescapeLiteral()
	if(inEscape.length() && inEscape.at(0) == '\'')
		inEscape.erase(0,1);
	if(inEscape.length() && inEscape.at(inEscape.length()-1) == '\'')
		inEscape.erase(inEscape.length()-1,1);
	return true;
}

void PostgreSQLConnection::SetLastInsertID(PGresult* res) {

	lastInsertID = -1;
	if(res == 0)
		return;

	lastInsertID = PQoidValue(res);
	if(lastInsertID == InvalidOid)
		lastInsertID = -1;
}

}
