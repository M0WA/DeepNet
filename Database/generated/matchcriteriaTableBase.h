#pragma once

#include "TableBase.h"
#include "SelectResultContainer.h"

namespace database {

class WhereConditionTableColumn;
class WhereConditionTableColumnCreateParam;
class TableDefinition;
class TableColumnDefinition;
class DatabaseConnection;

/**
 * @brief wrapper class for database table matchcriteria
 */
class matchcriteriaTableBase : public TableBase {

private:
    matchcriteriaTableBase(const TableBase& base);

public:
    matchcriteriaTableBase();
    virtual ~matchcriteriaTableBase();

public:
    /**
     * factory function for matchcriteria's table definition.
     * @return table definition.
     */
    static TableDefinition* CreateTableDefinition();

public:
//
// template: TableBase_GetSetFields.inc.h
//
  /**
   * gets value of ID.
   * @param out value.
   */
  void Get_ID(long long& out) const;

  /**
   * gets const column for ID.
   * @return column for ID.
   */
  const TableColumn* GetConstColumn_ID() const;

  /**
   * gets column for ID.
   * @return column for ID.
   */
  TableColumn* GetColumn_ID();

	/**
	 * sets value of ID.
	 * @param in value.
	 */
  void Set_ID(const long long& in);
  /**
   * gets value of regex.
   * @param out value.
   */
  void Get_regex(std::string& out) const;

  /**
   * gets const column for regex.
   * @return column for regex.
   */
  const TableColumn* GetConstColumn_regex() const;

  /**
   * gets column for regex.
   * @return column for regex.
   */
  TableColumn* GetColumn_regex();

	/**
	 * sets value of regex.
	 * @param in value.
	 */
  void Set_regex(const std::string& in);


public:
//
// template: TableBase_GetByFields.inc.h
//
public:
	/**
	 * gets rows by a value of ID.
	 * @param db database connection.
	 * @param fieldValue value of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<matchcriteriaTableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<matchcriteriaTableBase>& results);
public:
	/**
	 * gets rows by a value of regex.
	 * @param db database connection.
	 * @param fieldValue value of regex.
	 * @param results contains results.
	 */
    static void GetBy_regex(
        DatabaseConnection* db,
        const std::string& fieldValue, 
        SelectResultContainer<matchcriteriaTableBase>& results);

	/**
	 * gets rows by multiple values of regex.
	 * @param db database connection.
	 * @param fieldValue values of regex.
	 * @param results contains results.
	 */
    static void GetBy_regex(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<matchcriteriaTableBase>& results);


public:
//
// template: TableBase_InnerJoin.inc.h
//


public:
//
// template: TableBase_WhereColumns.inc.h
//
    /**
     * creates where condition for a value of ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of regex.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_regex(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::string& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of regex.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_regex(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<std::string>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);


public:
//
// template: TableDefinitionCreateParam_CreateColumn.inc.h
//
	/**
     * create a column definition for column ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_ID();
	/**
     * create a column definition for column regex.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_regex();

};

}
