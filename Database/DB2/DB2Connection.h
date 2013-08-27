/*
 * DB2Connection.h
 *
 *  Created on: 30.04.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>
#include "DatabaseConnection.h"

namespace database {

class Statement;
class SelectStatement;
class InsertStatement;
class InsertOrUpdateStatement;
class UpdateStatement;

class DatabaseConfig;
class DB2DatabaseConfig;

class DB2Connection : public DatabaseConnection {
public:
	DB2Connection();
	virtual ~DB2Connection();

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

private:
	DB2DatabaseConfig* config;
};

}
