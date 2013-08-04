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
 * @brief wrapper class for database table customerqueries
 */
class customerqueriesTableBase : public TableBase {

private:
    customerqueriesTableBase(const TableBase& base);

public:
    customerqueriesTableBase();
    virtual ~customerqueriesTableBase();

public:
    /**
     * factory function for customerqueries's table definition.
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
   * gets column for ID.
   * @return column for ID.
   */
  const TableColumn* GetColumn_ID() const;

	/**
	 * sets value of ID.
	 * @param in value.
	 */
  void Set_ID(const long long& in);
  /**
   * gets value of CUSTOMERDOMAIN_ID.
   * @param out value.
   */
  void Get_CUSTOMERDOMAIN_ID(long long& out) const;

  /**
   * gets column for CUSTOMERDOMAIN_ID.
   * @return column for CUSTOMERDOMAIN_ID.
   */
  const TableColumn* GetColumn_CUSTOMERDOMAIN_ID() const;

	/**
	 * sets value of CUSTOMERDOMAIN_ID.
	 * @param in value.
	 */
  void Set_CUSTOMERDOMAIN_ID(const long long& in);
  /**
   * gets value of query.
   * @param out value.
   */
  void Get_query(std::string& out) const;

  /**
   * gets column for query.
   * @return column for query.
   */
  const TableColumn* GetColumn_query() const;

	/**
	 * sets value of query.
	 * @param in value.
	 */
  void Set_query(const std::string& in);


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
        SelectResultContainer<customerqueriesTableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerqueriesTableBase>& results);
public:
	/**
	 * gets rows by a value of CUSTOMERDOMAIN_ID.
	 * @param db database connection.
	 * @param fieldValue value of CUSTOMERDOMAIN_ID.
	 * @param results contains results.
	 */
    static void GetBy_CUSTOMERDOMAIN_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<customerqueriesTableBase>& results);

	/**
	 * gets rows by multiple values of CUSTOMERDOMAIN_ID.
	 * @param db database connection.
	 * @param fieldValue values of CUSTOMERDOMAIN_ID.
	 * @param results contains results.
	 */
    static void GetBy_CUSTOMERDOMAIN_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerqueriesTableBase>& results);
public:
	/**
	 * gets rows by a value of query.
	 * @param db database connection.
	 * @param fieldValue value of query.
	 * @param results contains results.
	 */
    static void GetBy_query(
        DatabaseConnection* db,
        const std::string& fieldValue, 
        SelectResultContainer<customerqueriesTableBase>& results);

	/**
	 * gets rows by multiple values of query.
	 * @param db database connection.
	 * @param fieldValue values of query.
	 * @param results contains results.
	 */
    static void GetBy_query(
        DatabaseConnection* db, 
        const std::vector<std::string>& fieldValue, 
        SelectResultContainer<customerqueriesTableBase>& results);


public:
//
// template: TableBase_InnerJoin.inc.h
//
    static void AddInnerJoinLeftSideOn_CUSTOMERDOMAIN_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_CUSTOMERDOMAIN_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_CUSTOMERDOMAIN_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_CUSTOMERDOMAIN_ID(Statement& stmt);


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
     * creates where condition for a value of CUSTOMERDOMAIN_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_CUSTOMERDOMAIN_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of CUSTOMERDOMAIN_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_CUSTOMERDOMAIN_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of query.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_query(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::string& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of query.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_query(
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
     * create a column definition for column CUSTOMERDOMAIN_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_CUSTOMERDOMAIN_ID();
	/**
     * create a column definition for column query.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_query();

};

}
