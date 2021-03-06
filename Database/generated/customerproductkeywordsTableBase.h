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
 * @brief wrapper class for database table customerproductkeywords
 */
class customerproductkeywordsTableBase : public TableBase {

private:
    customerproductkeywordsTableBase(const TableBase& base);

public:
    customerproductkeywordsTableBase();
    virtual ~customerproductkeywordsTableBase();

public:
    /**
     * factory function for customerproductkeywords's table definition.
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
   * gets value of PRODUCT_ID.
   * @param out value.
   */
  void Get_PRODUCT_ID(long long& out) const;

  /**
   * gets const column for PRODUCT_ID.
   * @return column for PRODUCT_ID.
   */
  const TableColumn* GetConstColumn_PRODUCT_ID() const;

  /**
   * gets column for PRODUCT_ID.
   * @return column for PRODUCT_ID.
   */
  TableColumn* GetColumn_PRODUCT_ID();

	/**
	 * sets value of PRODUCT_ID.
	 * @param in value.
	 */
  void Set_PRODUCT_ID(const long long& in);
  /**
   * gets value of DICT_ID.
   * @param out value.
   */
  void Get_DICT_ID(long long& out) const;

  /**
   * gets const column for DICT_ID.
   * @return column for DICT_ID.
   */
  const TableColumn* GetConstColumn_DICT_ID() const;

  /**
   * gets column for DICT_ID.
   * @return column for DICT_ID.
   */
  TableColumn* GetColumn_DICT_ID();

	/**
	 * sets value of DICT_ID.
	 * @param in value.
	 */
  void Set_DICT_ID(const long long& in);


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
        SelectResultContainer<customerproductkeywordsTableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerproductkeywordsTableBase>& results);
public:
	/**
	 * gets rows by a value of PRODUCT_ID.
	 * @param db database connection.
	 * @param fieldValue value of PRODUCT_ID.
	 * @param results contains results.
	 */
    static void GetBy_PRODUCT_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<customerproductkeywordsTableBase>& results);

	/**
	 * gets rows by multiple values of PRODUCT_ID.
	 * @param db database connection.
	 * @param fieldValue values of PRODUCT_ID.
	 * @param results contains results.
	 */
    static void GetBy_PRODUCT_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerproductkeywordsTableBase>& results);
public:
	/**
	 * gets rows by a value of DICT_ID.
	 * @param db database connection.
	 * @param fieldValue value of DICT_ID.
	 * @param results contains results.
	 */
    static void GetBy_DICT_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<customerproductkeywordsTableBase>& results);

	/**
	 * gets rows by multiple values of DICT_ID.
	 * @param db database connection.
	 * @param fieldValue values of DICT_ID.
	 * @param results contains results.
	 */
    static void GetBy_DICT_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<customerproductkeywordsTableBase>& results);


public:
//
// template: TableBase_InnerJoin.inc.h
//
    static void AddInnerJoinLeftSideOn_PRODUCT_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_PRODUCT_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_PRODUCT_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_PRODUCT_ID(Statement& stmt);
    static void AddInnerJoinLeftSideOn_DICT_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_DICT_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_DICT_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_DICT_ID(Statement& stmt);


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
     * creates where condition for a value of PRODUCT_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_PRODUCT_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of PRODUCT_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_PRODUCT_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of DICT_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_DICT_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of DICT_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_DICT_ID(
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
     * create a column definition for column PRODUCT_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_PRODUCT_ID();
	/**
     * create a column definition for column DICT_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_DICT_ID();

};

}
