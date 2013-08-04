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
 * @brief wrapper class for database table fencedsearch
 */
class fencedsearchTableBase : public TableBase {

private:
    fencedsearchTableBase(const TableBase& base);

public:
    fencedsearchTableBase();
    virtual ~fencedsearchTableBase();

public:
    /**
     * factory function for fencedsearch's table definition.
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
   * gets value of CUSTOMER_ID.
   * @param out value.
   */
  void Get_CUSTOMER_ID(long long& out) const;

  /**
   * gets column for CUSTOMER_ID.
   * @return column for CUSTOMER_ID.
   */
  const TableColumn* GetColumn_CUSTOMER_ID() const;

	/**
	 * sets value of CUSTOMER_ID.
	 * @param in value.
	 */
  void Set_CUSTOMER_ID(const long long& in);
  /**
   * gets value of SECONDLEVELDOMAIN_ID.
   * @param out value.
   */
  void Get_SECONDLEVELDOMAIN_ID(long long& out) const;

  /**
   * gets column for SECONDLEVELDOMAIN_ID.
   * @return column for SECONDLEVELDOMAIN_ID.
   */
  const TableColumn* GetColumn_SECONDLEVELDOMAIN_ID() const;

	/**
	 * sets value of SECONDLEVELDOMAIN_ID.
	 * @param in value.
	 */
  void Set_SECONDLEVELDOMAIN_ID(const long long& in);


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
        SelectResultContainer<fencedsearchTableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<fencedsearchTableBase>& results);
public:
	/**
	 * gets rows by a value of CUSTOMER_ID.
	 * @param db database connection.
	 * @param fieldValue value of CUSTOMER_ID.
	 * @param results contains results.
	 */
    static void GetBy_CUSTOMER_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<fencedsearchTableBase>& results);

	/**
	 * gets rows by multiple values of CUSTOMER_ID.
	 * @param db database connection.
	 * @param fieldValue values of CUSTOMER_ID.
	 * @param results contains results.
	 */
    static void GetBy_CUSTOMER_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<fencedsearchTableBase>& results);
public:
	/**
	 * gets rows by a value of SECONDLEVELDOMAIN_ID.
	 * @param db database connection.
	 * @param fieldValue value of SECONDLEVELDOMAIN_ID.
	 * @param results contains results.
	 */
    static void GetBy_SECONDLEVELDOMAIN_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<fencedsearchTableBase>& results);

	/**
	 * gets rows by multiple values of SECONDLEVELDOMAIN_ID.
	 * @param db database connection.
	 * @param fieldValue values of SECONDLEVELDOMAIN_ID.
	 * @param results contains results.
	 */
    static void GetBy_SECONDLEVELDOMAIN_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<fencedsearchTableBase>& results);


public:
//
// template: TableBase_InnerJoin.inc.h
//
    static void AddInnerJoinLeftSideOn_CUSTOMER_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_CUSTOMER_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_CUSTOMER_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_CUSTOMER_ID(Statement& stmt);
    static void AddInnerJoinLeftSideOn_SECONDLEVELDOMAIN_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_SECONDLEVELDOMAIN_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_SECONDLEVELDOMAIN_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_SECONDLEVELDOMAIN_ID(Statement& stmt);


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
     * creates where condition for a value of CUSTOMER_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_CUSTOMER_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of CUSTOMER_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_CUSTOMER_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of SECONDLEVELDOMAIN_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of SECONDLEVELDOMAIN_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_SECONDLEVELDOMAIN_ID(
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
     * create a column definition for column CUSTOMER_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_CUSTOMER_ID();
	/**
     * create a column definition for column SECONDLEVELDOMAIN_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_SECONDLEVELDOMAIN_ID();

};

}
