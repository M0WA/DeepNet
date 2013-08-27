/**
 * @file MySQLConnection.h
 * @author Moritz Wagner
 * @date 30.04.2012
 */

#pragma once

#include <vector>
#include <string>

#include <mysql/mysql.h>

#include "DatabaseConnection.h"

namespace database {

class Statement;
class InsertStatement;
class InsertOrUpdateStatement;
class UpdateStatement;
class SelectStatement;
class DeleteStatement;

class TableBase;
class DatabaseConfig;
class MySQLDatabaseConfig;

/**
 * @brief implementation of database::DatabaseConnection for MySQL servers
 */
class MySQLConnection : public DatabaseConnection {
public:
	MySQLConnection();
	virtual ~MySQLConnection();

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

	virtual bool EscapeString(std::string& inEscape, const WildcardType& wildcard);

	virtual void Initialize();
	virtual void Shutdown();

private:
	void Execute(const std::string& query, bool doRetry);

private:
	MYSQL*               mysqlConnection;
	const MySQLDatabaseConfig* config;
};

}
