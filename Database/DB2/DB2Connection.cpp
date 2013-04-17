/*
 * DB2Connection.cpp
 *
 *  Created on: 30.04.2012
 *      Author: Moritz Wagner
 */

#include <NotImplementedException.h>

#include "DB2Connection.h"

namespace database {

DB2Connection::DB2Connection(const bool logQuery)
: DatabaseConnection(DB_IBM_DB2,logQuery)
, config(0)
{
}

DB2Connection::~DB2Connection()
{
}

bool DB2Connection::Connect(DatabaseConfig* dbConfig)
{
	//config = reinterpret_cast<DB2DatabaseConfig*>(dbConfig);
	THROW_EXCEPTION(errors::NotImplementedException,"database");
}

bool DB2Connection::Disconnect(void)
{
	THROW_EXCEPTION(errors::NotImplementedException,"database");
}

bool DB2Connection::Connected(void)
{
	THROW_EXCEPTION(errors::NotImplementedException,"database");
}

void DB2Connection::Query(const std::string& query, std::vector<TableBase*>& results)
{
	THROW_EXCEPTION(errors::NotImplementedException,"database");
}

void DB2Connection::Execute(const std::string& query)
{
	THROW_EXCEPTION(errors::NotImplementedException,"database");
}

void DB2Connection::Insert(const InsertStatement& stmt)
{
	THROW_EXCEPTION(errors::NotImplementedException,"database");
}

void DB2Connection::InsertOrUpdate(const InsertOrUpdateStatement& stmt)
{
	THROW_EXCEPTION(errors::NotImplementedException,"database");
}

void DB2Connection::Update(const UpdateStatement& stmt)
{
	THROW_EXCEPTION(errors::NotImplementedException,"database");
}

void DB2Connection::Select(const SelectStatement& stmt, std::vector<TableBase*>& results)
{
	THROW_EXCEPTION(errors::NotImplementedException,"database");
}

void DB2Connection::Delete(const DeleteStatement& stmt)
{
	THROW_EXCEPTION(errors::NotImplementedException,"database");
}

void DB2Connection::TransactionStart(void)
{
	THROW_EXCEPTION(errors::NotImplementedException,"database");
}

void DB2Connection::TransactionCommit(void)
{
	THROW_EXCEPTION(errors::NotImplementedException,"database");
}

void DB2Connection::TransactionRollback(void)
{
	THROW_EXCEPTION(errors::NotImplementedException,"database");
}

bool DB2Connection::LastInsertID(long long& lastInsertID)
{
	THROW_EXCEPTION(errors::NotImplementedException,"database");
}

bool DB2Connection::AffectedRows(long long& affectedRows)
{
	THROW_EXCEPTION(errors::NotImplementedException,"database");
}

bool DB2Connection::EscapeString(std::string& inEscape)
{
	THROW_EXCEPTION(errors::NotImplementedException,"database");
}

}
