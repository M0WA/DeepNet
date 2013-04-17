/**
 * @file TableColumnValueTyped.h
 * @author Moritz Wagner
 * @date 10.08.2012
 */

#pragma once

#include <string>

#include "TableColumnType.h"
#include "TableColumnValue.h"

#include <NotImplementedException.h>

namespace database {

/**
 * @brief implements typed column value.
 */
template <class T>
class TableColumnValueTyped : public TableColumnValue {
private:
	TableColumnValueTyped(const TableColumnValueTyped& type) {
		THROW_EXCEPTION(errors::NotImplementedException,"cannot copy TableColumnValueTyped");
	}

public:
	/**
	 * construct by column type.
	 * @param type column type.
	 */
	TableColumnValueTyped(const TableColumnType& type)
	: TableColumnValue(type){}

	virtual ~TableColumnValueTyped() {}

public:
	/**
	 * sets column value.
	 * @param in column value.
	 */
	void Set(const T& in) { value = in; }

	/**
	 * gets column value.
	 * @return column value.
	 */
	const T& Get() const { return value; }

	/**
	 * gets column value.
	 * @param out column value.
	 */
	void Get(T& out) const { out = value; }

private:
	T value;
};

}

