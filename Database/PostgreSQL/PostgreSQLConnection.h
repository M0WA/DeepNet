/**
 *
 * @file PostgreSQLConnection.h
 * @author Moritz Wagner
 * @date 12.06.2013
 *
 */

#pragma once

#include "DatabaseConnection.h"

namespace database {

	class PostgreSQLDatabaseConfig;

/**
 * @brief connection to PostgreSQL database
 */
class PostgreSQLConnection: public database::DatabaseConnection {
public:
	PostgreSQLConnection(const bool logQuery = false);
	virtual ~PostgreSQLConnection();

public:
	virtual bool Connect   (DatabaseConfig* dbConfig);
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

	virtual void Initialize();
	virtual void Shutdown();

private:
	PostgreSQLDatabaseConfig* config;
	long long connectionID;
};

}
