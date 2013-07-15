/**
 *
 * @file PostgreSQLConnection.h
 * @author Moritz Wagner
 * @date 12.06.2013
 *
 */

#pragma once

#include "DatabaseConnection.h"

#include <libpq-fe.h>

namespace database {

	class PostgreSQLDatabaseConfig;

/**
 * @brief implementation of database::DatabaseConnection for PostgreSQL servers
 */
class PostgreSQLConnection: public database::DatabaseConnection {
public:
	PostgreSQLConnection();
	virtual ~PostgreSQLConnection();

public:
	virtual bool Connect   (const DatabaseConfig* dbConfig);
	virtual bool Disconnect(void);
	virtual bool Connected (void);

protected:
	virtual void Query  (const std::string& query, std::vector<TableBase*>& results);
	virtual void Execute(const std::string& query);

public:
	virtual void Insert(const InsertStatement& stmt);
	virtual void InsertOrUpdate(const InsertOrUpdateStatement& stmt);
	virtual void Update(const UpdateStatement& stmt);
	virtual void Select(const SelectStatement& stmt, std::vector<TableBase*>& results);
	virtual void Delete(const DeleteStatement& stmt);

	virtual void TransactionStart   (void);
	virtual void TransactionCommit  (void);
	virtual void TransactionRollback(void);

	virtual bool LastInsertID       (long long& lastInsertID);
	virtual bool AffectedRows       (long long& affectedRows);

	virtual bool EscapeString(std::string& inEscape);

private:
	PGresult* Execute_Intern(const std::string& query);
	void SetLastInsertID(PGresult* res);

private:
	const PostgreSQLDatabaseConfig* config;
	PGconn* connection;
	std::string connectionString;

	long long affectedRows;
	long long lastInsertID;

};

}
