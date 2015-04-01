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
 * @brief wrapper class for database table dockey
 */
class dockeyTableBase : public TableBase {

private:
    dockeyTableBase(const TableBase& base);

public:
    dockeyTableBase();
    virtual ~dockeyTableBase();

public:
    /**
     * factory function for dockey's table definition.
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
  /**
   * gets value of URLSTAGE_ID.
   * @param out value.
   */
  void Get_URLSTAGE_ID(long long& out) const;

  /**
   * gets const column for URLSTAGE_ID.
   * @return column for URLSTAGE_ID.
   */
  const TableColumn* GetConstColumn_URLSTAGE_ID() const;

  /**
   * gets column for URLSTAGE_ID.
   * @return column for URLSTAGE_ID.
   */
  TableColumn* GetColumn_URLSTAGE_ID();

	/**
	 * sets value of URLSTAGE_ID.
	 * @param in value.
	 */
  void Set_URLSTAGE_ID(const long long& in);
  /**
   * gets value of occurrence.
   * @param out value.
   */
  void Get_occurrence(long long& out) const;

  /**
   * gets const column for occurrence.
   * @return column for occurrence.
   */
  const TableColumn* GetConstColumn_occurrence() const;

  /**
   * gets column for occurrence.
   * @return column for occurrence.
   */
  TableColumn* GetColumn_occurrence();

	/**
	 * sets value of occurrence.
	 * @param in value.
	 */
  void Set_occurrence(const long long& in);


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
        SelectResultContainer<dockeyTableBase>& results);

	/**
	 * gets rows by multiple values of ID.
	 * @param db database connection.
	 * @param fieldValue values of ID.
	 * @param results contains results.
	 */
    static void GetBy_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dockeyTableBase>& results);
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
        SelectResultContainer<dockeyTableBase>& results);

	/**
	 * gets rows by multiple values of DICT_ID.
	 * @param db database connection.
	 * @param fieldValue values of DICT_ID.
	 * @param results contains results.
	 */
    static void GetBy_DICT_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dockeyTableBase>& results);
public:
	/**
	 * gets rows by a value of URLSTAGE_ID.
	 * @param db database connection.
	 * @param fieldValue value of URLSTAGE_ID.
	 * @param results contains results.
	 */
    static void GetBy_URLSTAGE_ID(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<dockeyTableBase>& results);

	/**
	 * gets rows by multiple values of URLSTAGE_ID.
	 * @param db database connection.
	 * @param fieldValue values of URLSTAGE_ID.
	 * @param results contains results.
	 */
    static void GetBy_URLSTAGE_ID(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dockeyTableBase>& results);
public:
	/**
	 * gets rows by a value of occurrence.
	 * @param db database connection.
	 * @param fieldValue value of occurrence.
	 * @param results contains results.
	 */
    static void GetBy_occurrence(
        DatabaseConnection* db,
        const long long& fieldValue, 
        SelectResultContainer<dockeyTableBase>& results);

	/**
	 * gets rows by multiple values of occurrence.
	 * @param db database connection.
	 * @param fieldValue values of occurrence.
	 * @param results contains results.
	 */
    static void GetBy_occurrence(
        DatabaseConnection* db, 
        const std::vector<long long>& fieldValue, 
        SelectResultContainer<dockeyTableBase>& results);


public:
//
// template: TableBase_InnerJoin.inc.h
//
    static void AddInnerJoinLeftSideOn_DICT_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_DICT_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_DICT_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_DICT_ID(Statement& stmt);
    static void AddInnerJoinLeftSideOn_URLSTAGE_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinLeftSideOn_URLSTAGE_ID(Statement& stmt);
    static void AddInnerJoinRightSideOn_URLSTAGE_ID(const std::string& joinTableAlias, const std::string& joinColumnAlias, const std::string& referencedTableAlias, const std::string& referencedColumnAlias, Statement& stmt);
    static void AddInnerJoinRightSideOn_URLSTAGE_ID(Statement& stmt);


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
    /**
     * creates where condition for a value of URLSTAGE_ID.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_URLSTAGE_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of URLSTAGE_ID.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_URLSTAGE_ID(
        const WhereConditionTableColumnCreateParam& createParam,
        const std::vector<long long>& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);
    /**
     * creates where condition for a value of occurrence.
     * @param createParam create parameter.
     * @param fieldValue field value.
     * @param container adds newly created where condition.
     */
	static void GetWhereColumnsFor_occurrence(
        const WhereConditionTableColumnCreateParam& createParam,
        const long long& fieldValue, 
        std::vector<WhereConditionTableColumn*>& container);

    /**
     * creates where condition for multiple values of occurrence.
     * @param createParam create parameter.
     * @param fieldValue field values.
     * @param container adds newly created where conditions.
     */
    static void GetWhereColumnsFor_occurrence(
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
     * create a column definition for column DICT_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_DICT_ID();
	/**
     * create a column definition for column URLSTAGE_ID.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_URLSTAGE_ID();
	/**
     * create a column definition for column occurrence.
     * @return column definition.
     */
	static TableColumnDefinition* GetDefinition_occurrence();

};

}
