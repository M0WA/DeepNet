/**
 * @file TableColumnValue.cpp
 * @author Moritz Wagner
 * @date 10.08.2012
 */

#include "TableColumnValue.h"

#include <sstream>

#include "TableColumnValueTyped.h"

#include "DatabaseConnection.h"
#include "DatabaseHelper.h"

#include <NotImplementedException.h>
#include "DatabaseInvalidTypeException.h"

namespace database {

TableColumnValue::TableColumnValue(const TableColumnValue& copy){

	THROW_EXCEPTION(errors::NotImplementedException,"cannot copy TableColumnValue");
}

bool TableColumnValue::IsStringAllowed() const {
	switch(type)
	{
	case DB_TYPE_VARCHAR:
	case DB_TYPE_CHAR:
	case DB_TYPE_LARGE_TEXT:
		return true;

	default:
		return false;
	}
}

bool TableColumnValue::IsTimestampAllowed() const {

	switch(type)
	{
	case DB_TYPE_TIMESTAMP:
		return true;

	default:
		return false;
	}
}

bool TableColumnValue::IsDoubleAllowed() const {

	switch(type)
	{
	case DB_TYPE_DOUBLE:
		return true;

	default:
		return false;
	}
}

bool TableColumnValue::IsLongLongAllowed() const {

	switch(type)
	{
	case DB_TYPE_INTEGER:
		return true;

	default:
		return false;
	}
}

void TableColumnValue::Set(const std::string& in) {

	if(!IsStringAllowed())
		THROW_EXCEPTION(DatabaseInvalidTypeException);
	dynamic_cast< TableColumnValueTyped<std::string>* >(this)->Set(in);
}

void TableColumnValue::Get(std::string& out) const {

	if(!IsStringAllowed())
		THROW_EXCEPTION(DatabaseInvalidTypeException);
	dynamic_cast< const TableColumnValueTyped<std::string>* >(this)->Get(out);
}

void TableColumnValue::Set(const struct tm& in){

	if(!IsTimestampAllowed())
		THROW_EXCEPTION(DatabaseInvalidTypeException);
	dynamic_cast< TableColumnValueTyped<struct tm>* >(this)->Set(in);
}

void TableColumnValue::Get(struct tm& out) const {

	if(!IsTimestampAllowed())
		THROW_EXCEPTION(DatabaseInvalidTypeException);
	dynamic_cast< const TableColumnValueTyped<struct tm>* >(this)->Get(out);
}

void TableColumnValue::Set(const long long& in){

	if(!IsLongLongAllowed())
		THROW_EXCEPTION(DatabaseInvalidTypeException);
	dynamic_cast< TableColumnValueTyped<long long>* >(this)->Set(in);
}

void TableColumnValue::Get(long long& out) const {

	if(!IsLongLongAllowed())
		THROW_EXCEPTION(DatabaseInvalidTypeException);
	dynamic_cast< const TableColumnValueTyped<long long>* >(this)->Get(out);
}

void TableColumnValue::Set(const double& in){

	if(!IsDoubleAllowed())
		THROW_EXCEPTION(DatabaseInvalidTypeException);
	dynamic_cast< TableColumnValueTyped<double>* >(this)->Set(in);
}

void TableColumnValue::Get(double& out) const {

	if(!IsDoubleAllowed())
		THROW_EXCEPTION(DatabaseInvalidTypeException);
	dynamic_cast< const TableColumnValueTyped<double>* >(this)->Get(out);
}

std::string TableColumnValue::GetForSQL(DatabaseConnection* db) const {

	std::string stringQuotation, timestampPrefix;
	switch(db->GetDatabaseType()) {
	case DB_POSTGRESQL:
		stringQuotation = "'";
		timestampPrefix = " timestamp ";
		break;

	case DB_IBM_DB2:
	case DB_MYSQL:
	default:
		stringQuotation = "\"";
		break;
	}

	std::stringstream ssSQLValue;
	switch(type)
	{
	case DB_TYPE_VARCHAR:
	case DB_TYPE_CHAR:
	case DB_TYPE_LARGE_TEXT:
	{
		std::string value;
		Get(value);
		db->EscapeString(value);
		ssSQLValue << stringQuotation << value << stringQuotation;
	}
		break;

	case DB_TYPE_INTEGER:
	{
		long long rawValue;
		Get(rawValue);
		ssSQLValue << rawValue;
	}
		break;

	case DB_TYPE_DOUBLE:
	{
		double rawValue;
		Get(rawValue);
		ssSQLValue << rawValue;
	}
		break;

	case DB_TYPE_TIMESTAMP:
	{
		struct tm rawValue;
		Get(rawValue);
		std::string timeString;
		DatabaseHelper::TmToDateTime(rawValue,timeString);
		ssSQLValue << timestampPrefix << stringQuotation << timeString << stringQuotation;
	}
		break;

	default:
		THROW_EXCEPTION(DatabaseInvalidTypeException);
		break;
	}

	return ssSQLValue.str();
}

}
