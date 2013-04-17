/**
 * @file TableColumnValue.h
 * @author Moritz Wagner
 * @date 10.08.2012
 */

#pragma once

#include <string>
#include "TableColumnType.h"

namespace database {

class DatabaseConnection;

/**
 * @brief container for a generic column value.
 */
class TableColumnValue {
private:
	TableColumnValue(const TableColumnValue& copy);

public:
	/**
	 * create using column type.
	 * @param type column type.
	 */
	TableColumnValue(const TableColumnType& type)
	: type(type) {}

	virtual ~TableColumnValue(){}

	/**
	 * sets column value.
	 * @param in column value.
	 */
	void Set(const std::string& in);

	/**
	 * gets column value.
	 * @param out column value.
	 */
	void Get(std::string& out) const;

	/**
	 * sets column value.
	 * @param in column value.
	 */
	void Set(const struct tm& in);

	/**
	 * gets column value.
	 * @param out column value.
	 */
	void Get(struct tm& out) const;

	/**
	 * sets column value.
	 * @param in column value.
	 */
	void Set(const long long& in);

	/**
	 * gets column value.
	 * @param out column value.
	 */
	void Get(long long& out) const;

	/**
	 * sets column value.
	 * @param in column value.
	 */
	void Set(const double& in);

	/**
	 * gets column value.
	 * @param out column value.
	 */
	void Get(double& out) const;

	/**
	 * gets escaped column value as string.
	 * @param db database connection.
	 * @return escaped column value.
	 */
	std::string GetForSQL(DatabaseConnection* db) const;

	/**
	 * check if string is valid for column type.
	 * @return false if invalid, true if valid.
	 */
	bool IsStringAllowed() const;

	/**
	 * check if timestamp is valid for column type.
	 * @return false if invalid, true if valid.
	 */
	bool IsTimestampAllowed() const;

	/**
	 * check if double is valid for column type.
	 * @return false if invalid, true if valid.
	 */
	bool IsDoubleAllowed() const;

	/**
	 * check if integer is valid for column type.
	 * @return false if invalid, true if valid.
	 */
	bool IsLongLongAllowed() const;

protected:
	/**
	 * column type.
	 */
	TableColumnType type;
};

}

