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
 * @brief wrapper class for database table unittest3
 */
class unittest3TableBase : public TableBase {

private:
    unittest3TableBase(const TableBase& base);

public:
    unittest3TableBase();
    virtual ~unittest3TableBase();

public:
    /**
     * factory function for unittest3's table definition.
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
   * gets value of UNITTEST1_ID.
   * @param out value.
   */
  void Get_UNITTEST1_ID(long long& out) const;

  /**
   * gets column for UNITTEST1_ID.
   * @return column for UNITTEST1_ID.
   */
  const TableColumn* GetColumn_UNITTEST1_ID() const;

	/**
	 * sets value of UNITTEST1_ID.
	 * @param in value.
	 */
  void Set_UNITTEST1_ID(const long long& in);
  /**
   * gets value of UNITTEST2_ID.
   * @param out value.
   */
  void Get_UNITTEST2_ID(long long& out) const;

  /**
   * gets column for UNITTEST2_ID.
   * @return column for UNITTEST2_ID.
   */
  const TableColumn* GetColumn_UNITTEST2_ID() const;

	/**
	 * sets value of UNITTEST2_ID.
	 * @param in value.
	 */
  void Set_UNITTEST2_ID(const long long& in);


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
        SelectResultContainer<unittest3TableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<unittest3TableBase>& results);
public:
	/**
	 * gets rows by a value of UNITTEST1_ID.
	 * @param db database connection.
	 * @param fieldValue value of UNITTEST1_ID.
	 * @param results contains results.
	 */
    static void GetBy_UNITTEST1_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<unittest3TableBase>& results);

	/**
	 * gets rows by multiple values of UNITTEST1_ID.
	 * @param db database connection.
	 * @param fieldValue values of UNITTEST1_ID.
	 * @param results contains results.
	 */
    static void GetBy_UNITTEST1_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<unittest3TableBase>& results);
public:
	/**
	 * gets rows by a value of UNITTEST2_ID.
	 * @param db database connection.
	 * @param fieldValue value of UNITTEST2_ID.
	 * @param results contains results.
	 */
    static void GetBy_UNITTEST2_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<unittest3TableBase>& results);

	/**
	 * gets rows by multiple values of UNITTEST2_ID.
	 * @param db database connection.
	 * @param fieldValue values of UNITTEST2_ID.
	 * @param results contains results.
	 */
    static void GetBy_UNITTEST2_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<unittest3TableBase>& results);


public:
//
// template: TableBase_InnerJoin.inc.h
//
    static void AddInnerJoinLeftSideOn_UNITTEST1_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_UNITTEST1_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_UNITTEST1_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_UNITTEST1_ID(Statement& stmt);
    static void AddInnerJoinLeftSideOn_UNITTEST2_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_UNITTEST2_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_UNITTEST2_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_UNITTEST2_ID(Statement& stmt);


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
     * creates where condition for a value of UNITTEST1_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_UNITTEST1_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of UNITTEST1_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_UNITTEST1_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of UNITTEST2_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_UNITTEST2_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of UNITTEST2_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_UNITTEST2_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
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
     * create a column definition for column UNITTEST1_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_UNITTEST1_ID();
	/**
     * create a column definition for column UNITTEST2_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_UNITTEST2_ID();

};

}
