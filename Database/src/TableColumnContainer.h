/**
 * @file TableColumnContainer.h
 * @author Moritz Wagner
 * @date 19.08.2012
 */

#pragma once

namespace database {
class TableColumn;

/**
 * @brief container for a single TableColumn pointer.
 * manages memory of a single TableColumnContainer.
 */
class TableColumnContainer {
private:
	TableColumnContainer(const TableColumnContainer& container);

public:
	/**
	 * construct by existing column.
	 * @param pCol existing column.
	 */
	TableColumnContainer(TableColumn* pCol);

	virtual ~TableColumnContainer();

public:
	/**
	 * gets const table column.
	 * @return table column;
	 */
	const TableColumn* GetConstColumn() const { return pCol; }

	/**
	 * gets table column.
	 * @return table column;
	 */
	TableColumn* GetColumn() { return pCol; }

private:
	void CleanUp();

private:
	TableColumn* pCol;
};

}

