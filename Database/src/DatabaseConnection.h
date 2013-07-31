/**
 * @file DatabaseConnection.h
 * @author Moritz Wagner
 * @date 29.04.2012
 */

#pragma once

#include <vector>
#include <algorithm>

#include "TableBase.h"
#include "DatabaseTypes.h"
#include "SelectResultContainer.h"

namespace database {

class Statement;
class SelectStatement;
class InsertStatement;
class InsertOrUpdateStatement;
class UpdateStatement;
class DeleteStatement;
class GenericStatement;
class DatabaseConfig;

/**
 * @brief generic database connection.
 * this class serves as a base class for a specialized,
 * database-manufacturer related connection class.
 * @see database::MySQLConnection
 * @see database::DB2Connection
 * @see database::PostgreSQLConnection
 */
class DatabaseConnection
{
protected:
	/**
	 * construct with a certain database::DatabaseType.
	 * @param databaseType database type.
	 */
	DatabaseConnection(const DatabaseType& databaseType);

public:
	virtual ~DatabaseConnection();

public:
	/**
	 * connects to a database.
	 * @param dbConfig database config.
	 * @return false on error, true on success.
	 */
	virtual bool Connect(const DatabaseConfig* dbConfig)=0;

	/**
	 * disconnect from database.
	 * @return false on error, true on success.
	 */
	virtual bool Disconnect(void)=0;

	/**
	 * checks if database connection is established.
	 * @return false if not established, true if established.
	 */
	virtual bool Connected(void)=0;

protected:
	/**
	 * execute an sql query.
	 * @param query sql statement.
	 * @param results gets filled with results.
	 */
	virtual void Query(const std::string& query, std::vector<TableBase*>& results)=0;

	/**
	 * executing an sql statement without fetching results.
	 * @param query sql statement.
	 */
	virtual void Execute(const std::string& query)=0;

public:
	/**
	 * execute an insert statement.
	 * @param stmt insert statement.
	 */
	virtual void Insert(const InsertStatement& stmt)=0;

	/**
	 * execute an insert or update statement.
	 * @param stmt insert or update statement.
	 */
	virtual void InsertOrUpdate(const InsertOrUpdateStatement& stmt)=0;

	/**
	 * execute an update statement.
	 * @param stmt update statement.
	 */
	virtual void Update(const UpdateStatement& stmt)=0;

	/**
	 * execute delete statement.
	 * @param stmt delete statement
	 */
	virtual void Delete(const DeleteStatement& stmt)=0;

	/**
	 * execute select statement.
	 * @param stmt select statement.
	 * @param results gets filled with results.
	 */
	virtual void Select(const SelectStatement& stmt, std::vector<TableBase*>& results)=0;

	/**
	 * start a transaction.
	 */
	virtual void TransactionStart(void)=0;

	/**
	 * commits a transaction.
	 */
	virtual void TransactionCommit(void)=0;

	/**
	 * does a transaction rollback.
	 */
	virtual void TransactionRollback(void)=0;

	/**
	 * gets last inserted id.
	 * @param lastInsertID gets filled with last inserted id.
	 * @return false on error, true on success.
	 */
	virtual bool LastInsertID(long long& lastInsertID)=0;

	/**
	 * gets the number of affected rows from last statement.
	 * @param affectedRows number of affected rows.
	 * @return false on error, true on success.
	 */
	virtual bool AffectedRows(long long& affectedRows)=0;

	/**
	 * escapes a sql string in place.
	 * @param inEscape string to be escaped.
	 * @return false on error, true on success.
	 */
	virtual bool EscapeString(std::string& inEscape)=0;

	/**
	 * called for global initialization, once per runtime.
	 */
	virtual void Initialize() {}

	/**
	 * called for global shutdown
	 */
	virtual void Shutdown() {}

public:
	/**
	 * gets the database type of this connection.
	 * @return database type.
	 */
	const DatabaseType& GetDatabaseType(void) const { return databaseType; }

public:
	/**
	 * execute select statements putting results into container.
	 * @param stmt select statement.
	 * @param results result container.
	 */
	void Select(const SelectStatement& stmt, SelectResultContainer<TableBase>& results)
	{
		std::vector<TableBase*> resultRows;
		Select(stmt, resultRows);

		std::vector<TableBase*>::iterator iterTableRows = resultRows.begin();
		for(;iterTableRows != resultRows.end();++iterTableRows) {
			results.Add(*iterTableRows);}
	}

	/**
	 * execute select statements putting results into container of type T.
	 * type T should be derived from database::TableBase.
	 * @param stmt select statement.
	 * @param results result container.
	 */
	template <class T>
	void Select(const SelectStatement& stmt, SelectResultContainer<T>& results)
	{
		std::vector<TableBase*> resultRows;
		Select(stmt, resultRows);

		std::vector<TableBase*>::iterator iterTableRows = resultRows.begin();
		for(;iterTableRows != resultRows.end();++iterTableRows) {
			TableBase* pResultBase = *iterTableRows;
			T* pResult = new T();
			pResult->CopyColumns(pResultBase);
			results.Add(pResult);
			delete (*iterTableRows);}
	}

private:
	const DatabaseType databaseType;
};

}
