/**
 *
 * @file PostgreSQLConnection.cpp
 * @author Moritz Wagner
 * @date 12.06.2013
 *
 */

#include "PostgreSQLConnection.h"

#include <StringTools.h>

#include "PostgreSQLPGC.h"

#include "DatabaseTypes.h"
#include "DatabaseConfig.h"

namespace database {

PostgreSQLConnection::PostgreSQLConnection(const bool logQuery)
: database::DatabaseConnection(DB_POSTGRESQL,logQuery)
, connectionID(0){
}

PostgreSQLConnection::~PostgreSQLConnection() {
	if(Connected())
		Disconnect();
}

bool PostgreSQLConnection::Connect(DatabaseConfig* dbConfig){

	bool success = pg_db_connect(
		connectionID,
		dbConfig->GetHost().c_str(),
		dbConfig->GetPort(),
		dbConfig->GetUser().c_str(),
		dbConfig->GetPass().c_str(),
		dbConfig->GetDatabaseName().c_str()	);

	return success;
}

bool PostgreSQLConnection::Disconnect(void){
	bool success = pg_db_disconnect(connectionID);
	connectionID = -1;
	return success;
}

bool PostgreSQLConnection::Connected(void){
	return (connectionID != -1);
}

void PostgreSQLConnection::Query(const std::string& query, std::vector<TableBase*>& results){
}

void PostgreSQLConnection::Execute(const std::string& query){
}

void PostgreSQLConnection::Insert(const InsertStatement& stmt){
}

void PostgreSQLConnection::InsertOrUpdate(const InsertOrUpdateStatement& stmt){
}

void PostgreSQLConnection::Update(const UpdateStatement& stmt){
}

void PostgreSQLConnection::Select(const SelectStatement& stmt, std::vector<TableBase*>& results){
}

void PostgreSQLConnection::Delete(const DeleteStatement& stmt){
}

void PostgreSQLConnection::TransactionStart(void){
	pg_db_start_transaction(connectionID);
}

void PostgreSQLConnection::TransactionCommit(void){
	pg_db_commit_transaction(connectionID);
}

void PostgreSQLConnection::TransactionRollback(void){
	pg_db_rollback_transaction(connectionID);
}

bool PostgreSQLConnection::LastInsertID(long long& lastInsertID){
	return false;
}

bool PostgreSQLConnection::AffectedRows(long long& affectedRows){
	return false;
}

bool PostgreSQLConnection::EscapeString(std::string& inEscape){
	return false;
}

void PostgreSQLConnection::Initialize(){
}

void PostgreSQLConnection::Shutdown(){
}

}
