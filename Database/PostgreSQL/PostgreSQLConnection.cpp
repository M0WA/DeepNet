/**
 *
 * @file PostgreSQLConnection.cpp
 * @author Moritz Wagner
 * @date 12.06.2013
 *
 */

#include "PostgreSQLConnection.h"

#include "PostgreSQLPGC.h"

#include "DatabaseTypes.h"
#include "DatabaseConfig.h"

namespace database {

PostgreSQLConnection::PostgreSQLConnection(const bool logQuery)
: database::DatabaseConnection(DB_POSTGRESQL,logQuery) {
}

PostgreSQLConnection::~PostgreSQLConnection() {
}

bool PostgreSQLConnection::Connect(DatabaseConfig* dbConfig){
	pg_db_connect(
		dbConfig->GetHost().c_str(),
		dbConfig->GetPort(),
		dbConfig->GetUser().c_str(),
		dbConfig->GetPass().c_str(),
		dbConfig->GetDatabaseName().c_str()
	);
	return false;
}

bool PostgreSQLConnection::Disconnect(void){
	return false;
}

bool PostgreSQLConnection::Connected(void){
	return false;
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
}

void PostgreSQLConnection::TransactionCommit(void){
}

void PostgreSQLConnection::TransactionRollback(void){
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
